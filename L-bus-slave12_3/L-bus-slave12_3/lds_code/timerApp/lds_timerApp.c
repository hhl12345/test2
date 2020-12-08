/**
 * @file    lds_softTimer.c
 * @brief   provide soft timer for other module
 * @author  ZhangTao, zhangtao2@leedarson.com
 * @version v1.0.0
 * @date    2020-08-21 12:00:00
 * @par     Copyright
 * Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 *
 * @par     History
 * 1.Date        :2020-08-21 12:00:00
 *   Author      :ZhangTao
 *   Version     :v1.0.0
 *   Modification:Create file
 */

#include "lds_timerApp.h"

eTimerRegStat_t eTimerRegStat;

static tTimerPara_t stTimerPara[NUM_OF_TIMERS];


/**
  * @brief  Register the timer
  *
  * @param[in]  (*pFunc)(): the callback function.
  * @param[in]  cTimerNum   : the number of the timer.
  * @param[in]  timeout   : stop time.
  * @param[in]  loop      : Circular execution.  
  *
  * @retval None
  */
void timerApp_register(void(*pFunc)(), uint8_t cTimerNum, uint32_t uiTimeout, uint32_t uiLoopTimes){
  stTimerPara[cTimerNum].pCb = pFunc;
  stTimerPara[cTimerNum].eRegState = E_TIMER_REGISTER;
  stTimerPara[cTimerNum].uiTimeout = uiTimeout;
  stTimerPara[cTimerNum].uiCounter = 0;
  stTimerPara[cTimerNum].uiLoopTimes = uiLoopTimes;
}

void timerApp_unregister(uint8_t cTimerNum){
  stTimerPara[cTimerNum].eRegState = E_TIMER_UNREGISTER;
  stTimerPara[cTimerNum].uiCounter = 0;
}

/**
  * @brief  Execute the callback function in the main loop
  *
  * @param  None
  *
  * @retval None
  */
void timerApp_task(void){
  for(uint8_t i=0; i<NUM_OF_TIMERS; i++){
    if(E_TIMER_REGISTER == stTimerPara[i].eRegState){
      if(stTimerPara[i].uiCounter >= stTimerPara[i].uiTimeout){
        stTimerPara[i].uiCounter = 0;
        if(stTimerPara[i].uiLoopTimes == 0xFFFFFFFF){
          stTimerPara[i].pCb();
        }
        else{
          stTimerPara[i].uiLoopTimes--;
          stTimerPara[i].pCb();
          if(stTimerPara[i].uiLoopTimes == 0){
            timerApp_unregister(i);
          }
        }
      }
    }
  }
}

/**
  * @brief  background ticks, tTimerPara_t repeat invoking interval 1ms
  *
  * @param  None
  *
  * @retval None
  */
void timerApp_ticks(void){
  for(uint8_t i=0; i<NUM_OF_TIMERS; i++){
    if(E_TIMER_REGISTER == stTimerPara[i].eRegState){
      stTimerPara[i].uiCounter++;
    }
  }
}

uint32_t timerApp_getCounterVal(uint8_t cTimerNum){
  return stTimerPara[cTimerNum].uiCounter;
}

eTimerRegStat_t timerApp_getStat(uint8_t cTimerNum){
  return stTimerPara[cTimerNum].eRegState;
}

void timerApp_null(void){
  return;
}

