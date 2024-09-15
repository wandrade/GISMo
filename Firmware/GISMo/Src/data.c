//data.c

#include "data.h"
#include "led.h"
data_register_t data_register;
structured_data_t *d = &data_register.s;

void init_data(){
	data_register.s.device_ID = 0x5541;
	data_register.s.version_major = 0;
	data_register.s.version_minor = 1;
	data_register.s.led_mode = LED_MODE_OFF;
}

