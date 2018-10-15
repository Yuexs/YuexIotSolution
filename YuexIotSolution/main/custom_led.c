#include "custom_led.h"

#define LED_IO_NUM_0    2
//#define LED_IO_NUM_1    17

#define TAG "led"

void custom_led_init()
{
	led_0 = iot_led_create(LED_IO_NUM_0, LED_DARK_LOW);
	custom_led_slow();
}

void custom_led_on()
{
	iot_led_state_write(led_0, LED_ON);
}

void custom_led_off()
{
	iot_led_state_write(led_0, LED_OFF);
}

void custom_led_quick()
{
	iot_led_state_write(led_0, LED_QUICK_BLINK);
}

void custom_led_slow()
{
	iot_led_state_write(led_0, LED_SLOW_BLINK);
}