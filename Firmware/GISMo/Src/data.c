//data.c

#include "data.h"
#include "encoder.h"
#include "driver.h"


DATA_REGISTER data_register[DATA_REGISTER_SIZE];

void init_data(){
	uint8_t i = 254;
	data_register[3].mem_addr = (void*)&encoder.raw;
	data_register[3].len = sizeof(int32_t);
}
