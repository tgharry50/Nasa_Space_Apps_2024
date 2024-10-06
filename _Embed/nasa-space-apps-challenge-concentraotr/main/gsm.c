/*
 * gsm.c
 *
 *  Created on: 6 paź 2024
 *      Author: majorbien
 */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "esp_log.h"
#include "string.h"
#include "gsm.h"

static const char *TAG = "SIM800L";



void send_at_command(const char *command) {
    uart_write_bytes(MODEM_UART_NUM, command, strlen(command));
    uart_write_bytes(MODEM_UART_NUM, "\r\n", 2);  
}

void receive_modem_response() {
    uint8_t data[BUF_SIZE];
    int length = uart_read_bytes(MODEM_UART_NUM, data, BUF_SIZE, 100 / portTICK_PERIOD_MS);
    if (length > 0) {
        data[length] = '\0';
        ESP_LOGI(TAG, "Received: %s", data);
    } else {
        ESP_LOGW(TAG, "No data received.");
    }
}

void send_sms(const char *phone_number, const char *message) {
    send_at_command("AT+CMGF=1"); 
    vTaskDelay(pdMS_TO_TICKS(2000)); 
    receive_modem_response();  

    char command[50];
    sprintf(command, "AT+CMGS=\"%s\"", phone_number);
    send_at_command(command);
    vTaskDelay(pdMS_TO_TICKS(2000)); 
    receive_modem_response();  

    uart_write_bytes(MODEM_UART_NUM, message, strlen(message));
    uart_write_bytes(MODEM_UART_NUM, "\x1A", 1);  
    vTaskDelay(pdMS_TO_TICKS(5000));  
    receive_modem_response();  
}

void init_sim800l() {
    send_at_command("AT");
    vTaskDelay(pdMS_TO_TICKS(1000));
    receive_modem_response();
    send_at_command("AT+CPIN?");
    vTaskDelay(pdMS_TO_TICKS(1000));
    receive_modem_response();

}

void init_uart() {
    const uart_config_t uart_config = {
        .baud_rate = MODEM_UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };

    uart_param_config(MODEM_UART_NUM, &uart_config);
    uart_set_pin(MODEM_UART_NUM, MODEM_TX_PIN, MODEM_RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(MODEM_UART_NUM, BUF_SIZE * 2, 0, 0, NULL, 0);
}