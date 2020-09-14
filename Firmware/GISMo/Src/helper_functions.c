#include "helper_functions.h"


void enable_CPU_count(){
	if (ARM_CM_DWT_CTRL != 0) {        // See if DWT is available
	    ARM_CM_DEMCR      |= 1 << 24;  // Set bit 24
	    ARM_CM_DWT_CYCCNT  = 0;
	    ARM_CM_DWT_CTRL   |= 1 << 0;   // Set bit 0

	}
}
