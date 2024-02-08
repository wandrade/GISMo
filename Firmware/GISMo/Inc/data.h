// data.h

#ifndef DATA_H
#define DATA_H

#include <stdint.h>

#define DATA_REGISTER_SIZE 256

typedef struct __attribute__((__packed__)){
	int8_t cmd;							// RW
	uint8_t device_ID;					// RO
	uint8_t device_addr;        		//

} structured_data_t;

typedef union {
	uint8_t r[DATA_REGISTER_SIZE];		// Raw
	structured_data_t s;				// Structured
} data_register_t;


extern data_register_t data_register;

void init_data();

#endif
