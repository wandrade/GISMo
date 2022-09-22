
// helper_functions.h
#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "stm32f3xx_hal.h"
#include "main.h"

#define PI 3.14159265359

#define DEBUG_PIN // comment out to disable output debug pin

//######################################################## Clock counter ########################################################//

#define  ARM_CM_DEMCR      (*(uint32_t *)0xE000EDFC)
#define  ARM_CM_DWT_CTRL   (*(uint32_t *)0xE0001000)
#define  ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)

extern uint32_t clock_counter_start_time;

void enable_CPU_count();
void start_cpu_count();
extern uint32_t stop_cpu_count();


#endif
//###############################################################################################################################//
