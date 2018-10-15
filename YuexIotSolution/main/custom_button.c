#include "esp_log.h"
#include "custom_button.h"
#include "custom_smart_config.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "custom_led.h"

static const char* TAG = "custom_button";

void smart_config_start(void* arg)
{
	ESP_EARLY_LOGI(TAG, "smart_config_start");
	custom_smart_config_setup();
	vTaskDelete(NULL);
}

void button_smart_config_cb(void* arg)
{
	custom_led_quick();
	xTaskCreate(smart_config_start, "smart_config_start", 1024 * 2, NULL, 5, NULL);
}

void custom_button_init()
{
	button_handle_t btn_handle = iot_button_create(BUTTON_IO_NUM, BUTTON_ACTIVE_LEVEL);
	iot_button_add_custom_cb(btn_handle, 5, button_smart_config_cb, NULL);
}