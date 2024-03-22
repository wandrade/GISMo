//led.c
#include "led.h"

#define MGR_UPDATE_PERIOD_MS 100
#define LED_UPDATE_PERIOD_MS 1
#define LED_PWM_RESOLUTION 0xF

extern data_register_t data_register;

uint8_t led_mode;
uint8_t led_dutycycle_r; // RGB pwm's from 0 to LED_PWM_RESOLUTION
uint8_t led_dutycycle_g; // RGB pwm's from 0 to LED_PWM_RESOLUTION
uint8_t led_dutycycle_b; // RGB pwm's from 0 to LED_PWM_RESOLUTION
uint8_t periodCounter;

void init_led(){
    TaskHandle_t taskHandle = NULL;
    xTaskCreate(ledPWMTask, 	"ledPWMTask", 	  24, NULL, tskIDLE_PRIORITY, &taskHandle);
    xTaskCreate(ledManagerTask, "ledManagerTask", 64, NULL, tskIDLE_PRIORITY, &taskHandle);
}

int8_t led_dir = 0;
static uint8_t heartbeat(uint8_t current_dc){
	if(current_dc == LED_PWM_RESOLUTION){
		led_dir = -1;
	}
	else if(current_dc == 0){
		led_dir = 1;
	}
	return (current_dc += led_dir);
}

void ledManagerTask(void* pvParameters){
    while(1){
        // Update LED duty cycle every LED_UPDATE_PERIOD_MS
        vTaskDelay(pdMS_TO_TICKS(MGR_UPDATE_PERIOD_MS));
        led_mode = data_register.s.led_mode;

        switch(led_mode){
        case 0:
			led_dutycycle_r = 0;
			led_dutycycle_g = 0;
			led_dutycycle_b = 0;
            break;
        case 1:
			led_dutycycle_r = 0;
			led_dutycycle_g = heartbeat(led_dutycycle_g);
			led_dutycycle_b = 0;
            break;
        case 2:
			led_dutycycle_r = 1;
			led_dutycycle_g = 0;
			led_dutycycle_b = 0;
            break;
        case 3:
			led_dutycycle_r = 0;
			led_dutycycle_g = 1;
			led_dutycycle_b = 0;
            break;
        case 4:
			led_dutycycle_r = 0;
			led_dutycycle_g = 0;
			led_dutycycle_b = 1;
            break;
        case 5:
			led_dutycycle_r = heartbeat(led_dutycycle_g);
			led_dutycycle_g = 0;
			led_dutycycle_b = 0;
            break;
        default:
			led_dutycycle_r = 1;
			led_dutycycle_g = 1;
			led_dutycycle_b = 1;
        };
    }
}

void ledPWMTask(void *pvParameters){
    while(1){
        // Update LED duty cycle every LED_UPDATE_PERIOD_MS
        vTaskDelay(pdMS_TO_TICKS(LED_UPDATE_PERIOD_MS));
        // Increment period counter and reset if it reaches LED_PWM_RESOLUTION
        periodCounter = (periodCounter + 1) % LED_PWM_RESOLUTION;

        // Determine LED state based on duty cycle and period counter
        if (periodCounter < led_dutycycle_r) {
            HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
        }
        if (periodCounter < led_dutycycle_g) {
            HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
        }
        if (periodCounter < led_dutycycle_b) {
            HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET);
        }
    }
}
