
// data.h
#ifndef DATA_H
#define DATA_H

#include "driver.h"
#include "encoder.h"


#define DATA_REGISTER_SIZE 256

typedef struct{
	void *mem_addr;
	uint8_t len;
} DATA_REGISTER;

extern DATA_REGISTER data_register[DATA_REGISTER_SIZE];

void init_data();

#endif
