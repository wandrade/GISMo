//led.c
#include "led.h"

uint16_t led_pwm = 0x0000;

void StartLedUpdateTask(void const * argument){
	// Initialise the xLastWakeTime variable with the current time.
	TickType_t xLastWakeTime = xTaskGetTickCount();
	uint8_t i;

	for( ;; )
	{
		// Perform action here.
		for (i = 0; i < LED_PWM_RESOLUTION; i++){
			// Wait for the next cycle.
			vTaskDelayUntil(&xLastWakeTime, LED_UPDATE_PERIOD_MS);
			// Blue LED
			if (i >= (led_pwm & 0x000F)){
				HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
			}
			else {
				HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
			}
			// Green LED
			if (i >= (led_pwm & 0x00F0) >> 2){
				HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
			}
			else {
				HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
			}
			// Red LED
			if (i >= (led_pwm & 0x0F00) >> 4){
				HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, 0);
			}
			else {
				HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, 1);
			}
		}
	}
}
