//data.c

#include "data.h"

data_register_t data_register;

void init_data(){
	data_register.s.device_ID = 0x5541;
	data_register.s.version_major = 0;
	data_register.s.version_minor = 1;
	data_register.s.led_mode = 0;
}

