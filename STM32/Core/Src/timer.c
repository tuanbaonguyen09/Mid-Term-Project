/*
 * timer.c
 *
 *  Created on: Oct 29, 2022
 *      Author: tuanb
 */
#include "timer.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim){
	if(htim->Instance == TIM2){
		getKeyInput();
		fsm_simple_buttons_run();
		timerRun();
	}
}
