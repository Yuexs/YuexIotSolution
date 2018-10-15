#include "esp_system.h"
#include "esp_log.h"
#include "iot_led.h"

static led_handle_t led_0;

void custom_led_init();

void custom_led_on();

void custom_led_off();

void custom_led_quick();

void custom_led_slow();