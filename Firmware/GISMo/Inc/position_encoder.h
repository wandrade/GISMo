
// position_encoder.h
#ifndef POSITION_ENCODER_H
#define POSITION_ENCODER_H

#define CLOCK_TICKS_PER_PWM_CYCLE 	4111
#define PWM_TO_RADIANS_SCALE		0.00153399	// Convert from 12bit raw to and angle in radians

#include "stm32f3xx_hal.h"
#include "helper_functions.h"

typedef struct {
	uint32_t raw;
	uint32_t raw_prev;
	int32_t multiturn_counter;
	uint32_t CCR3, CCR4;
	uint8_t valid;
	float rad, rad_prev;
	float rad_multiturn;
} POSITION_STRUCT;

POSITION_STRUCT position;

void initialize_position();
void update_position_raw(TIM_HandleTypeDef* htim);
void update_position_rad();

#endif
