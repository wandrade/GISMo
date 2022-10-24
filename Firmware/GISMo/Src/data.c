//data.c

#include "data.h"
#include "encoder.h"
#include "driver.h"
#include "led.h"

DATA_REGISTER data_register[DATA_REGISTER_SIZE];

#define ADD_TO_REGISTER(VAR, TYPE) data_register[i].mem_addr = (void*)&VAR; data_register[i].len = sizeof(TYPE); i--;


void init_data(){
	uint8_t i = 0xFF;
	ADD_TO_REGISTER(encoder.raw, int32_t)
	ADD_TO_REGISTER(encoder.single, uint16_t)
	ADD_TO_REGISTER(encoder.multiturn_counter, int32_t)
	ADD_TO_REGISTER(encoder.error, uint32_t)
	ADD_TO_REGISTER(led_pwm, uint16_t)
}
