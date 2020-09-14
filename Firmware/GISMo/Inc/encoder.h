
// encoder.h
#ifndef ENCODER_H
#define ENCODER_H

#define TIMER_FREQUENCY				64000000	// in Hz (timer 1 is on APB2 according to datasheet)
#define ENCODER_CLOCKS_PER_CYCLE	4119		// see datasheet  (https://ams.com/documents/20143/36005/AS5048_DS000298_4-00.pdf page 27)
#define ENCODER_MAX_VALID_CLOCK_NUM	4111		// The last 8 clocks are always 0 if the sensor is connected and there is a magnet close to it
#define ENCODER_MIN_VALID_CLOCK_NUM	16			// When there is no error, the sensor outputs 16 clocks high at the beggining (12 for init and 4 bit for error code)







#define ENCODER_REFRESH_RATE		1000		// in Hz
#define CLOCK_TICKS_PER_PWM_CYCLE 	4111
#define PWM_TO_RADIANS_SCALE		0.00153399	// Convert from 12bit raw to and angle in radians

#include "stm32f3xx_hal.h"
#include "main.h"
#include "helper_functions.h"
#include <math.h>

typedef struct {
	float period;
	uint32_t t_rising_edge, t_falling_edge;
	uint16_t pwm_clocks;
	uint32_t error;
	uint16_t single, single_prev;
	int32_t multiturn_counter;
	int32_t raw;

} ENCODER_STRUCT;
ENCODER_STRUCT encoder;

typedef struct {
	uint32_t raw;
	uint32_t raw_prev;
	int32_t multiturn_counter;
	uint32_t CCR3, CCR4;
	uint8_t valid;
	float rad, rad_prev;
	float rad_multiturn, rad_multiturn_prev;
	float spike_limit;
	uint8_t spike_counter;

	// Position filter
	uint8_t filter_size, buffer_head;
	float rad_filtered, rad_filtered_prev;
	float buffer[50];

} POSITION_STRUCT;
POSITION_STRUCT position;

typedef struct{
	float rad_sec_raw;
	float rad_sec, rad_sec_prev;
} SPEED_STRUCT;
SPEED_STRUCT speed;

void initialize_encoder();
void update_position_raw(TIM_HandleTypeDef* htim);
void update_position_speed();
void update_encoder(TIM_HandleTypeDef* htim);
#endif
