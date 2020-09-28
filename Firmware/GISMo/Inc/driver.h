
// driver.h
#ifndef DRIVER_H
#define DRIVER_H

#include "stm32f3xx_hal.h"
//#include "cmsis_os.h"


// If change the buffer size, make sure to fix the divison in HAL_ADC_ConvCpltCallback
// at 32kz, a buffer of 8 gives us a current reading at 4KHZ for the torque loop
#define CURRENT_BUFF_SIZE 8

typedef struct {
	uint16_t adc_buffer[CURRENT_BUFF_SIZE];
	uint32_t raw;

} CURRENT_SENSING_STRUCT;


CURRENT_SENSING_STRUCT current;
TIM_OC_InitTypeDef pwm_config;

void init_driver();
void enable_driver();
void disable_driver();
void pwm_set_ouput(uint16_t dutyCycle, uint8_t direction);

#endif
