/*
 * led_display.c
 *
 *  Created on: Oct 29, 2022
 *      Author: tuanb
 */

#include "led_display.h"

void display7SEG(int num){
	HAL_GPIO_WritePin (GPIOB,a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin, GPIO_PIN_SET) ;
	switch(num){
	case 0:
		HAL_GPIO_TogglePin (GPIOB,a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin) ;
		break;
	case 1:
		HAL_GPIO_TogglePin (GPIOB ,b_Pin|c_Pin) ;
		break;
	case 2:
		HAL_GPIO_TogglePin (GPIOB,a_Pin|b_Pin|g_Pin|d_Pin|e_Pin) ;
		break;
	case 3:
		HAL_GPIO_TogglePin (GPIOB,a_Pin|b_Pin|g_Pin|c_Pin|d_Pin) ;
		break;
	case 4:
		HAL_GPIO_TogglePin (GPIOB,f_Pin|g_Pin|b_Pin|c_Pin) ;
		break;
	case 5:
		HAL_GPIO_TogglePin (GPIOB,a_Pin|f_Pin|g_Pin|c_Pin|d_Pin) ;
		break;
	case 6 :
		HAL_GPIO_TogglePin (GPIOB,a_Pin|f_Pin|g_Pin|e_Pin|c_Pin|d_Pin) ;
		break;
	case 7 :
		HAL_GPIO_TogglePin (GPIOB ,a_Pin|b_Pin|c_Pin ) ;
		break;
	case 8:
		HAL_GPIO_TogglePin (GPIOB,a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin) ;
		break;
	case 9:
		HAL_GPIO_TogglePin (GPIOB,a_Pin|b_Pin|c_Pin|d_Pin|f_Pin|g_Pin) ;
		break;
	}
}



