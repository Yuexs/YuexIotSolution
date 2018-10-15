#include "iot_smartconfig.h"
#include "custom_smart_config.h"
#include "esp_log.h"
#include "custom_led.h"

static const char* TAG = "custom_smart_config";

void sc_check_status(void* arg)
{
	while (1) {
		//ESP_EARLY_LOGI(TAG, "sc status: %d\n", iot_sc_get_status());
		vTaskDelay(300 / portTICK_PERIOD_MS);
		if (iot_sc_get_status() == SC_STATUS_LINK_OVER) {
			custom_led_on();
			break;
		}
	}
	vTaskDelete(NULL);
}

void custom_smart_config_setup()
{
	esp_err_t res;
	iot_sc_setup(SC_TYPE_ESPTOUCH_AIRKISS, WIFI_MODE_STA, 0);
	xTaskCreate(sc_check_status, "sc_check_status", 1024 * 2, NULL, 5, NULL);
	while (1) {
		res = iot_sc_start(20000 / portTICK_PERIOD_MS);
		if (res == ESP_OK) {
			ESP_EARLY_LOGI(TAG, "connected\n");
			break;
		}
		else if (res == ESP_ERR_TIMEOUT) {
			ESP_EARLY_LOGI(TAG, "smart config timeout\n");
		}
		else if (res == ESP_FAIL) {
			ESP_EARLY_LOGI(TAG, "smart config stopped\n");
		}
	}
}