/*
 * lds_hal_timer.c
 *
 *  Created on: 2020Äê11ÔÂ18ÈÕ
 *      Author: zhangtao2
 */
#include "lds_hal_timer.h"
#include "tim.h"
#include "stm32f0xx_hal_tim.h"


void hal_timer_init(void){
  MX_TIM1_Init();
  hal_timer0_open();
}

void hal_timer0_open(void){
  HAL_TIM_Base_Start(&htim1);
  HAL_TIM_Base_Start_IT(&htim1);
}

void hal_timer0_close(void){
  HAL_TIM_Base_Stop(&htim1);
  HAL_TIM_Base_Stop_IT(&htim1);
}


