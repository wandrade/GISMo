// led.h
#ifndef LED_H
#define LED_H

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "data.h"

void init_led();
void ledPWMTask(void*);
void ledManagerTask(void*);
#endif
