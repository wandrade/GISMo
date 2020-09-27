//driver.c

#include "driver.h"
#include "main.h"

extern TIM_OC_InitTypeDef pwm_config;
extern TIM_HandleTypeDef htim2;
extern ADC_HandleTypeDef hadc1;

uint16_t current_adc_buffer[32] = {0};
uint32_t flag, current;
void init_driver(){
	// Set configuration struct
    pwm_config.OCMode = TIM_OCMODE_PWM1; // 1 for side aligned 2 for middle aligned PWM
    pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config.OCFastMode = TIM_OCFAST_DISABLE;
    // Set duty cycle to 0 and start PWM output encoder
    pwm_config.Pulse = 0;
    HAL_TIM_PWM_ConfigChannel(&htim2, &pwm_config, TIM_CHANNEL_4);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
    current = 0;
    flag = 0;

    // Set Analogue PWM trigger
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&current_adc_buffer, 5);
    HAL_TIM_Base_Start_IT(&htim2);

    //    TIM2->CCR2 = 500; // Delay before reading current (in clock cycles of a 32MHZ clock)
//    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&current_adc_buffer, 1);
//    HAL_ADC_Start(&hadc1);
//    HAL_TIM_Base_Start_IT(&htim2);
}

void enable_driver(){
	// Set DC to zero
	TIM2->CCR4 = 0;
	// Wake up
	HAL_GPIO_WritePin(nSleep_GPIO_Port, nSleep_Pin, 1);
}

void disable_driver(){
	// Set DC to zero
	TIM2->CCR4 = 0;
	// Wake up
	HAL_GPIO_WritePin(nSleep_GPIO_Port, nSleep_Pin, 0);
}

void pwm_set_ouput(uint16_t dutyCycle, uint8_t direction){
	TIM2->CCR4 = dutyCycle;
	HAL_GPIO_WritePin(Direction_GPIO_Port, Direction_Pin, direction);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
#ifdef DEBUG_PIN
	HAL_GPIO_TogglePin(DEBUG_3_GPIO_Port, DEBUG_3_Pin);
#endif
	flag++;
	current = current_adc_buffer[0];
//	if(flag == 0) flag = 1000;
//	else flag = 0;

}
