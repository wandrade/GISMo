
// encoder.h
#ifndef ENCODER_H
#define ENCODER_H

#define ENCODER_REFRESH_RATE		1000		// in Hz
#define CLOCK_TICKS_PER_PWM_CYCLE 	4111
#define PWM_TO_RADIANS_SCALE		0.00153399	// Convert from 12bit raw to and angle in radians

#include "stm32f3xx_hal.h"
#include "main.h"
#include "helper_functions.h"
#include <stdlib.h>

typedef struct {
	uint32_t raw;
	uint32_t raw_prev;
	int32_t multiturn_counter;
	uint32_t CCR3, CCR4;
	uint8_t valid;
	float rad, rad_prev;
	float rad_multiturn, rad_multiturn_prev;
	float spike_limit;
	float max, min;
	uint8_t spike_counter;
} POSITION_STRUCT;

typedef struct{
	uint8_t filter_size, buffer_head;
	float buffer[50];
	float rad_sec_raw;
	float rad_sec, rad_sec_prev;
	float max, min;
} SPEED_STRUCT;

POSITION_STRUCT position;
SPEED_STRUCT speed;

void initialize_encoder();
void update_position_raw(TIM_HandleTypeDef* htim);
void update_position_speed();

#endif
