
// driver.h
#ifndef DRIVER_H
#define DRIVER_H

#include "stm32f3xx_hal.h"
//#include "cmsis_os.h"

TIM_OC_InitTypeDef pwm_config;

void init_driver();
void enable_driver();
void disable_driver();
void pwm_set_ouput(uint16_t dutyCycle, uint8_t direction);

#endif
