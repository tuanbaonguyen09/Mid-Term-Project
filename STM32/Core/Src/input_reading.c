/*
 * input_reading.c
 *
 *  Created on: Oct 29, 2022
 *      Author: tuanb
 */

#include "input_reading.h"

int button_flag[N0_OF_BUTTONS] = {0,0,0};

int KeyReg0[N0_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[N0_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[N0_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[N0_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimerForKeyPress[N0_OF_BUTTONS];

int isButtonPressed(int index){
	if (button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}
int isButtonHolded(int index){
	if (button_flag[index] == 2){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}
void getKeyInput(){
	for (int i = 0; i < N0_OF_BUTTONS; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		if(i == 0)
			KeyReg2[i] = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
		if(i == 1)
			KeyReg2[i] = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
		if(i == 2)
			KeyReg2[i] = HAL_GPIO_ReadPin(DEC_GPIO_Port,DEC_Pin);
		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg3[i] == PRESSED_STATE){
					button_flag[i] = 1;
					TimerForKeyPress[i] = 300;
					flag = 1;
					setTimer3(10000);
				}
			}
			else{
				TimerForKeyPress[i]--;
				if (KeyReg3[i] == NORMAL_STATE){
					button_flag[i] = -1;
				}
				if (TimerForKeyPress[i] == 0){
					if (KeyReg3[i] == PRESSED_STATE){
						button_flag[i] = 2;
						TimerForKeyPress[i] = 300;
						flag = 1;
						setTimer3(10000);
					}
				}
			}
		}
	}
}


