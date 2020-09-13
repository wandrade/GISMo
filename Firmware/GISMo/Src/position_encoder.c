#include "position_encoder.h"

extern POSITION_STRUCT position;

void initialize_position(){

}

void update_position_raw(TIM_HandleTypeDef* htim){
	// Reset timer counter for next interrupt pair
	__HAL_TIM_SET_COUNTER(htim, 0);
	position.CCR3 = htim->Instance->CCR3; 	// Rising edge time (channel 3 interrupt time)
	position.CCR4 = htim->Instance->CCR4; 	// Falling edge time (channel 4 interrupt time)

	// Falling this might happen when position is close to 360 degrees and there is not enough time to process interrupt
	if(position.CCR4 >= position.CCR3){
		position.raw_prev = position.raw;
		// Calculate PWM duty cycle
		position.raw = position.CCR4 - position.CCR3;

		// Increase multiturn counter when completed a turn
		if(position.raw_prev > 50000 && position.raw < 10000){
			position.multiturn_counter++;
		}
		else if (position.raw_prev < 10000 && position.raw > 50000){
			position.multiturn_counter--;
		}
		// Convert Duty cycle into useful stuff
		update_position_rad();
	}

}


// AS5048 splits 100% duty cycle into 4119 where max duty cycle is 4111 clock cycles (https://ams.com/documents/20143/36005/AS5048_DS000298_4-00.pdf page 27)
// Defined on position_encoder.h as CLOCK_TICKS_PER_PWM_CYCLE
// On each cycle:
//   12 clocks - init (high for 12 clock cycles)
//    4 clocks - Not error (low when there is an error)
// 4095 clocks - Position
//    8 Clocks - Exit (Low for 8 clock cycles)

// The max value position.raw can be is the max time it takes between two rising edges (refresh period of the sensor) minus the minimal dead time of the line (the 8 exit clocks of the signal)
// This value is directly measured by CCR4 since we are reseting the timer at each falling edge
void update_position_rad(){
	// From MAX_POSITION_TICK_COUNT to 4119 as stated in datasheet
	uint32_t scaled_raw = CLOCK_TICKS_PER_PWM_CYCLE*position.raw/position.CCR4;
	if (scaled_raw > 12){
		position.valid = 1;
		position.rad_prev = position.rad;
		position.rad = (float)(scaled_raw - 15)*PWM_TO_RADIANS_SCALE;
		position.rad_multiturn = position.multiturn_counter*2*PI + position.rad;
	} else {
		position.valid = 0;
	}

}











