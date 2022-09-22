//driver.c

#include "driver.h"
#include "main.h"

extern TIM_HandleTypeDef htim2;
extern ADC_HandleTypeDef hadc1;

CURRENT_SENSING_STRUCT current;
TIM_OC_InitTypeDef pwm_config;

void init_driver(){
	// Set configuration struct
    pwm_config.OCMode = TIM_OCMODE_PWM1; // 1 for side aligned 2 for middle aligned PWM
    pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config.OCFastMode = TIM_OCFAST_DISABLE;
    // Set duty cycle to 0 and start PWM output encoder
    pwm_config.Pulse = 0;
    HAL_TIM_PWM_ConfigChannel(&htim2, &pwm_config, TIM_CHANNEL_4);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);

    // Set Analogue PWM trigger and DMA
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&current.adc_buffer, CURRENT_BUFF_SIZE);
    HAL_TIM_Base_Start_IT(&htim2);
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
	HAL_GPIO_WritePin(DEBUG_3_GPIO_Port, DEBUG_3_Pin,0);
#endif
	uint32_t filtre = 0;
	for(uint8_t i = 0; i < CURRENT_BUFF_SIZE; i++){
		filtre += current.adc_buffer[i];
	}
	// If buffer size is 2^n, then division can be done more efficiently with bit shift
	// filter/2^n = filtre >> n
		current.raw = filtre >> 3;
		current.value = current.raw*CURRENT_SCALAR;
	//	current.raw = filtre/CURRENT_BUFF_SIZE;
#ifdef DEBUG_PIN
	HAL_GPIO_WritePin(DEBUG_3_GPIO_Port, DEBUG_3_Pin,0);
#endif
}
