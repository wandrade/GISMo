
// helper_functions.h
#ifndef HELPER_FUNCTIONS_C
#define HELPER_FUNCTIONS_C

#include "helper_functions.h"



//######################################################## Clock counter ########################################################//

extern uint32_t clock_counter_start_time;

void enable_CPU_count(){
	if (ARM_CM_DWT_CTRL != 0) {        // See if DWT is available
	    ARM_CM_DEMCR      |= 1 << 24;  // Set bit 24
	    ARM_CM_DWT_CYCCNT  = 0;
	    ARM_CM_DWT_CTRL   |= 1 << 0;   // Set bit 0

	}
}

void start_cpu_count(){
	clock_counter_start_time = ARM_CM_DWT_CYCCNT;
}

uint32_t stop_cpu_count(){
	return ARM_CM_DWT_CYCCNT - clock_counter_start_time - 34;
}
//###############################################################################################################################//

#endif
