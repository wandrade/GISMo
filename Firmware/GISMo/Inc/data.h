// data.h

#ifndef DATA_H
#define DATA_H

#include <stdint.h>

#define DATA_REGISTER_SIZE 256

typedef struct{
	uint16_t 		device_ID;					// 0x00
	uint8_t 		version_major;				// 0x02
	uint8_t 		version_minor;				// 0x03
	int32_t			encoder_raw;				// 0x04
	int32_t			encoder_multiturn;			// 0x08

	int16_t 		cmd;						// 0x0C
	uint8_t 		led_mode;					// 0x0E
	uint8_t 		enable_motor;				// 0x0F
	uint8_t			controller_mode;			// 0x10
	int16_t			duty_cycle;					// 0x11
} structured_data_t;

typedef union {
	uint8_t r[DATA_REGISTER_SIZE];		// Raw
	structured_data_t s;				// Structured
} data_register_t;


extern data_register_t data_register;

void init_data();

#endif
