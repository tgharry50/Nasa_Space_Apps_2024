/*
 * http_server.c
 *
 *  Created on: 14 wrz 2024
 *      Author: majorbien
 */
 
#include "http_server.h"
 
 
#include "esp_http_server.h"
#include "esp_log.h"
 
#include "tasks_settings.h"
#include "wifi.h"
 
#include <string.h> 
#include <cJSON.h> 
#include "lora.h"
#include "gsm.h"
 
char json_buffer[256]; 
 
static SemaphoreHandle_t json_mutex;
 
static const char TAG[] = "http_server";
 
 
static httpd_handle_t http_server_handle = NULL;
 
static TaskHandle_t task_http_server_monitor = NULL;
 
static QueueHandle_t http_server_monitor_queue_handle;
 
static esp_err_t http_server_json_handler1(httpd_req_t *req);
static esp_err_t http_server_json_handler2(httpd_req_t *req);

static void http_server_monitor(void *parameter)
{
    http_server_queue_message_t msg;
 
    for (;;)
    {
        if (xQueueReceive(http_server_monitor_queue_handle, &msg, portMAX_DELAY))
        {
            switch (msg.msgID)
            {
                case HTTP_MSG_WIFI_CONNECT_INIT:
                    ESP_LOGI(TAG, "HTTP_MSG_WIFI_CONNECT_INIT");
 
                    break;
 
                case HTTP_MSG_WIFI_CONNECT_SUCCESS:
                    ESP_LOGI(TAG, "HTTP_MSG_WIFI_CONNECT_SUCCESS");
 
                    break;
 
                case HTTP_MSG_WIFI_CONNECT_FAIL:
                    ESP_LOGI(TAG, "HTTP_MSG_WIFI_CONNECT_FAIL");
 
                    break;
 
                case HTTP_MSG_FIRMWARE_UPDATE_SUCCESSFUL:
                    ESP_LOGI(TAG, "HTTP_MSG_OTA_UPDATE_SUCCESSFUL");
 
                    break;
 
                case HTTP_MSG_FIRMWARE_UPDATE_FAILED:
                    ESP_LOGI(TAG, "HTTP_MSG_OTA_UPDATE_FAILED");
 
                    break;
 
                case HTTP_MSG_FIRMWARE_UPATE_INITIALIZED:
                    ESP_LOGI(TAG, "HTTP_MSG_OTA_UPATE_INITIALIZED");
 
                    break;

                default:
                    break;
            }
        }
    }
}
 
 
static httpd_handle_t http_server_configure(void)
{
 
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
 
    xTaskCreatePinnedToCore(&http_server_monitor, "http_server_monitor", HTTP_STACK_SIZE, NULL, HTTP_PRIORITY, &task_http_server_monitor, HTTP_CORE_ID);
 
    http_server_monitor_queue_handle = xQueueCreate(3, sizeof(http_server_queue_message_t));
 
    config.core_id = HTTP_CORE_ID;
 
    config.task_priority = HTTP_PRIORITY;
 
    config.stack_size = HTTP_STACK_SIZE;
 
    config.max_uri_handlers = 20;
 
    config.recv_wait_timeout = 10;
    config.send_wait_timeout = 10;
 
    ESP_LOGI(TAG,
            "http_server_configure: Starting server on port: '%d' with task priority: '%d'",
            config.server_port,
            config.task_priority);
 
    if (httpd_start(&http_server_handle, &config) == ESP_OK)
    {
        ESP_LOGI(TAG, "http_server_configure: Registering URI handlers");
 
 
        httpd_uri_t json_post1 = {
                .uri = "/sensors",
                 .method = HTTP_POST,
                 .handler = http_server_json_handler1,
                 .user_ctx = NULL
        };
        
        
        
        httpd_register_uri_handler(http_server_handle, &json_post1);
        
        httpd_uri_t json_post2 = {
    			 .uri = "/alert",
   				 .method = HTTP_POST,
   				 .handler = http_server_json_handler2,
   				 .user_ctx = NULL
		};
		httpd_register_uri_handler(http_server_handle, &json_post2);

        return http_server_handle;
    }
 
    return NULL;
}
 
 
void http_server_start(void)
{
    json_mutex = xSemaphoreCreateMutex();
    if (http_server_handle == NULL)
    {
        http_server_handle = http_server_configure();
    }
}
 
void http_server_stop(void)
{
    if (http_server_handle)
    {
        httpd_stop(http_server_handle);
        ESP_LOGI(TAG, "http_server_stop: stopping HTTP server");
        http_server_handle = NULL;
    }
    if (task_http_server_monitor)
    {
        vTaskDelete(task_http_server_monitor);
        ESP_LOGI(TAG, "http_server_stop: stopping HTTP server monitor");
        task_http_server_monitor = NULL;
    }
}
 
BaseType_t http_server_monitor_send_message(http_server_message_e msgID)
{
    http_server_queue_message_t msg;
    msg.msgID = msgID;
    return xQueueSend(http_server_monitor_queue_handle, &msg, portMAX_DELAY);
}
extern char json_buffer[];  
 
static esp_err_t http_server_json_handler1(httpd_req_t *req) {
    ESP_LOGI(TAG, "JSON data requested");
 
    httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
    httpd_resp_set_hdr(req, "Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    httpd_resp_set_hdr(req, "Access-Control-Allow-Headers", "Content-Type");
 
    xSemaphoreTake(json_mutex, portMAX_DELAY);
 
    if (strlen(json_buffer) > 0) {
        esp_err_t result = httpd_resp_send(req, json_buffer, strlen(json_buffer));
        if (result != ESP_OK) {
            ESP_LOGE(TAG, "Failed to send JSON response. Error: %d", result);
            xSemaphoreGive(json_mutex);
            return result;  
        }
        ESP_LOGI(TAG, "Sent JSON: %s", json_buffer);
    } else {
        const char *empty_response = "{}";
        httpd_resp_send(req, empty_response, strlen(empty_response));
        ESP_LOGI(TAG, "Sent empty JSON response");
    }
 
    xSemaphoreGive(json_mutex);
    return ESP_OK; 
}
 
 
 static esp_err_t http_server_json_handler2(httpd_req_t *req)
{
    ESP_LOGI(TAG, "JSON data requested");

    // Set appropriate CORS headers
    httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
    httpd_resp_set_hdr(req, "Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    httpd_resp_set_hdr(req, "Access-Control-Allow-Headers", "Content-Type");

    char buf[256] = { 0 };  // Buffer to store received data
    int ret, total_length = 0;

    // Receive data in chunks
    do {
        ret = httpd_req_recv(req, buf + total_length, sizeof(buf) - total_length - 1);
        if (ret == HTTPD_SOCK_ERR_TIMEOUT) {
            ESP_LOGI(TAG, "timeout, continue receiving");
            continue;
        }
        if (ret < 0) {
            ESP_LOGE(TAG, "Error receiving data! (status = %d)", ret);
            return ESP_FAIL;
        }
        total_length += ret;
        buf[total_length] = '\0';  // Null-terminate the buffer
    } while (ret > 0 && total_length < sizeof(buf) - 1);

    ESP_LOGI(TAG, "Received JSON: %s", buf);

    // Parse JSON data
    cJSON *json = cJSON_Parse(buf);
    if (json == NULL) {
        ESP_LOGE(TAG, "Failed to parse JSON");
        return ESP_FAIL;
    }

    // Extract "number" field
    cJSON *json_number = cJSON_GetObjectItemCaseSensitive(json, "number");
    if (!cJSON_IsString(json_number) || (json_number->valuestring == NULL)) {
        ESP_LOGE(TAG, "Invalid or missing 'number' field");
        cJSON_Delete(json);
        return ESP_FAIL;
    }

    // Extract "message" field
    cJSON *json_message = cJSON_GetObjectItemCaseSensitive(json, "message");
    if (!cJSON_IsString(json_message) || (json_message->valuestring == NULL)) {
        ESP_LOGE(TAG, "Invalid or missing 'message' field");
        cJSON_Delete(json);
        return ESP_FAIL;
    }

    // Use the extracted values
    const char *number = json_number->valuestring;
    const char *message = json_message->valuestring;

    ESP_LOGI(TAG, "Sending SMS to number: %s, with message: %s", number, message);


    send_sms(number, message);

    cJSON_Delete(json);

    const char *resp_str = "Data received successfully!";
    httpd_resp_send(req, resp_str, strlen(resp_str));

    return ESP_OK;
}




 