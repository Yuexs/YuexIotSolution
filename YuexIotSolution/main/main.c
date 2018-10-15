#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "custom_led.h"
#include "nvs_flash.h"
#include "custom_wifi_conn.h"
#include "custom_button.h"

void iot_start()
{
	custom_led_init();
	custom_wifi_conn_init();
	custom_button_init();
}

void app_main()
{
	ESP_ERROR_CHECK(nvs_flash_init());
	iot_start();
}
