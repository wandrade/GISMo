//driver.c

#include "driver.h"

extern TIM_OC_InitTypeDef pwm_config;
extern TIM_HandleTypeDef htim2;

void init_driver(){
	// Set configuration struct
    pwm_config.OCMode = TIM_OCMODE_PWM1; // 1 for side aligned 2 for middle aligned PWM
    pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config.OCFastMode = TIM_OCFAST_DISABLE;
    // Set duty cycle to 0
    pwm_config.Pulse = 0;
    HAL_TIM_PWM_ConfigChannel(&htim2, &pwm_config, TIM_CHANNEL_4);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
}

void pwm_setvalue(uint16_t value)
{
	TIM2->CCR4 = value;
}
