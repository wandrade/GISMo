// led.h
#ifndef LED_H
#define LED_H

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "data.h"

#define LED_MODE_OFF 			0
#define LED_MODE_HEARTBEAT_G	1
#define LED_MODE_ON_R			2
#define LED_MODE_ON_G			3
#define LED_MODE_ON_B			4
#define LED_MODE_HEARTBEAT_R	5

void init_led();
void ledPWMTask(void*);
void ledManagerTask(void*);
#endif
