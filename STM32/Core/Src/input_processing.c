/*
 * input_processing.c
 *
 *  Created on: Oct 29, 2022
 *      Author: tuanb
 */
#include "input_processing.h"

void increase(void){
	counter += 1;
	if (counter > 9) counter = 0;
}
void decrease(void){
	counter -= 1;
	if (counter < 0) counter = 9;
}

void fsm_simple_buttons_run(void){
	switch(status){
	case 0:
		if (isButtonPressed(0)){
			counter = 0;
		}
		if (isButtonPressed(1)){
			increase();
		}
		if (isButtonPressed(2)){
			decrease();
		}
		if (isButtonHolded(1)){
			status = 1;
			setTimer2(1000);
		}
		if (isButtonHolded(2)){
			status = 2;
			setTimer2(1000);
		}
		break;
	case 1 :
		if (timer2_flag == 1){
			increase();
			setTimer2(1000);
		}
		if (button_flag[1] == -1) {
			status = 0;
			clearTimer2();
		}
		break;
	case 2:
		if (timer2_flag == 1){
			decrease();
			setTimer2(1000);
		}
		if (button_flag[2] == -1) {
			status = 0;
			clearTimer2();
		}
		break;
	case 3:
		if (isButtonPressed(0) || isButtonPressed(1) || isButtonPressed(2) || counter == 0 ){
				status = 0;
				flag = 0;
			}
		if (timer3_flag == 1){
			if (counter > 0) counter--;
			setTimer3(1000);
		}
	break;
	}
}
