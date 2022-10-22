//led.c

#include "led.h"


//#define LED_UPDATE_PERIOD_MS 50
//#define LED_PWM_RESOLUTION 256



//	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, 1);
//	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
//	HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
//	osDelay(200);
//	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, 0);
//	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
//	HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);

uint32_t led_pwm = 0xFF8;

void StartLedUpdateTask(void const * argument){
	// Initialise the xLastWakeTime variable with the current time.
	TickType_t xLastWakeTime = xTaskGetTickCount();
	uint8_t i;

	for( ;; )
	{

		// Perform action here.
		for (i = 0; i < LED_PWM_RESOLUTION; i++){
			// Wait for the next cycle.
			vTaskDelayUntil( &xLastWakeTime, LED_UPDATE_PERIOD_MS);//LED_UPDATE_PERIOD_MS/portTICK_RATE_MS);
			// Blue LED
			if (i >= (led_pwm & 0x00F)){
				HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
			}
			else {
				HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
			}
			// Green LED
			if (i >= (led_pwm & 0x0F0) >> 2){
				HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
			}
			else {
				HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
			}
			// Red LED
			if (i >= (led_pwm & 0xF00) >> 4){
				HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, 0);
			}
			else {
				HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, 1);
			}
		}
	}
}
