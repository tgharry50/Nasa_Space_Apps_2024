
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "ra01s.h"
#include "lora.h"
#include "nvs_flash.h"
#include "wifi.h"
#include "gsm.h"

static const char *TAG = "MAIN";



void app_main()
{
	ESP_LOGI(TAG, "APP START");
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);
	

	loraInit();
	loraTaskStart();
	wifi_app_start();
	init_uart();
    init_sim800l();
	//send_sms("692336423", "xyz");	

	

}