// led.h
#ifndef LED_H
#define LED_H

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

#define LED_UPDATE_PERIOD_MS 1
#define LED_PWM_RESOLUTION 0x0F

extern uint32_t led_pwm;

void StartLedUpdateTask(void const * argument);

#endif
