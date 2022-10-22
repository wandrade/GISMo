
// driver.h
#ifndef DRIVER_H
#define DRIVER_H

#include "stm32f3xx_hal.h"
//#include "cmsis_os.h"


// If change the buffer size, make sure to fix the divison in HAL_ADC_ConvCpltCallback
// at 32kz, a buffer of 8 gives us a current reading at 4KHZ for the torque loop
#define CURRENT_BUFF_SIZE 8

// Vref (max current) is set to 3.2V (1.5k and 50k voltage divider)
// Ripropi
// Aipropi = 1000
// According to DRV8876 datasheet then, Itrip (or max output current or current in which the driver cuts the power)
// Itrip = Aipropi * vref/Ripropi
// Itrip = 1000 * 3.3/Ripropi = Max Current
// If the current exceeds that value, Driver will enter current chopping mode

// Current on Ripropi will be proportional to current on the motor scaled by Aipropi
// Voltage drop is what we are measuring
// Ipropi = Iload/Aipropi
// Vadc = Ipropi*Ripropi
// Vadr = Iload*Ripropi/Aipropi
// Iload = Vadr*Aipropi/Ripropi
// Vadr = ADC_raw * 3.3/4096
// Iload = ADC_Raw*scalar
// scalar = 3.3*1000/(Ripropi*4096)
//#define CURRENT_SCALAR 0.00040283203125		// Ripropi = 2.0K (1.65A current limit)
#define CURRENT_SCALAR 0.000537109375		// Ripropi = 1.5K (2.2A current limit)
//#define CURRENT_SCALAR 0.0008056640625		// Ripropi = 1.0K (3.3A current limit)

typedef struct {
	uint16_t adc_buffer[CURRENT_BUFF_SIZE];
	uint32_t raw;
	float value;

} CURRENT_SENSING_STRUCT;


extern CURRENT_SENSING_STRUCT current;
extern TIM_OC_InitTypeDef pwm_config;

void init_driver();
void enable_driver();
void disable_driver();
//duty cycle 0 to 1000
void pwm_set_ouput(uint16_t dutyCycle, uint8_t direction);

#endif
