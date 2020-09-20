
// helper_functions.h
#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "stm32f3xx_hal.h"
#include "main.h"

#define PI 3.14159265359

#define DEBUG_PIN

// T enable clock counting of CPU
#define  ARM_CM_DEMCR      (*(uint32_t *)0xE000EDFC)
#define  ARM_CM_DWT_CTRL   (*(uint32_t *)0xE0001000)
#define  ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)

void enable_CPU_count();


// How to measure CPU clock
//uint32_t  start;
//uint32_t  stop;
//uint32_t  delta;
//
//start = ARM_CM_DWT_CYCCNT;
//// Code to measure
//stop  = ARM_CM_DWT_CYCCNT;
//delta = stop – start;


#endif
