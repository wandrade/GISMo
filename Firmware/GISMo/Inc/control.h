// control.h
#ifndef CONTROL_H
#define CONTROL_H

#include "pid.h"
#include "FreeRTOS.h"
#include "task.h"
#include "data.h"
#include "driver.h"

void PositionLoopTask(void *pvParameters);
void positionLoopStart(TaskHandle_t *taskHandle);
void positionLoopStop(TaskHandle_t *taskHandle);

#endif //CONTROL_H
