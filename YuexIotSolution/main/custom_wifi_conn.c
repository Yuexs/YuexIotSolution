#include "custom_wifi_conn.h"
#include "esp_log.h"
#include "custom_led.h"

static const char* TAG = "custom_wifi_conn";

void wifi_connect_start(void* arg)
{
	ESP_EARLY_LOGI(TAG, "wifi_connect_start");
	//	wifi_sta_status_t status = iot_wifi_get_status();
	//	if (status == WIFI_STATUS_STA_DISCONNECTED)
	//	{
	////		iot_wifi_disconnect();
	////		wifi_config_t wifi_config;
	////		esp_wifi_get_config(ESP_IF_WIFI_STA, &wifi_config);
	////		esp_err_t res=iot_wifi_connect((const char *)wifi_config.sta.ssid, (const char *)wifi_config.sta.password, portMAX_DELAY);
	//		vTaskDelay(5000 / portTICK_PERIOD_MS);
	//		ESP_EARLY_LOGI(TAG, "wifi_connect_start");
	//	}
	//	if (status == WIFI_STATUS_STA_CONNECTED)
	//	{
	//		h_led_on();
	//		vTaskDelete(NULL);
	//	}
		vTaskDelay(5000 / portTICK_PERIOD_MS);
	vTaskDelete(NULL);
	
}

void custom_wifi_conn_init()
{
	iot_wifi_setup(WIFI_MODE_STA);
	//	iot_wifi_setup(WIFI_MODE_STA);
		wifi_config_t wifi_config;
	esp_wifi_get_config(ESP_IF_WIFI_STA, &wifi_config);
	iot_wifi_connect((const char *)wifi_config.sta.ssid, (const char *)wifi_config.sta.password, portMAX_DELAY);
	custom_led_on();
	//xTaskCreate(wifi_connect_start, "wifi_connect_start", 1024 * 2, NULL, 5, NULL);
}