/**
 * @file    lds_ledApp.c
 * @brief   provide LED registration mechanism for other module
 * @author  ZhangTao, zhangtao2@leedarson.com
 * @version v1.0.0
 * @date    2020-11-03 12:00:00
 * @par     Copyright
 * Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 *
 * @par     History
 * 1.Date        :2020-11-03 12:00:00
 *   Author      :ZhangTao
 *   Version     :v1.0.0
 *   Modification:Create file
 */

#include <lds_hal_debugPrintf.h>
#include "lds_ledApp.h"
#include "lds_timerApp.h"

#include "lds_hal_gpio.h"//该c文件中定义LED的硬件接口函数
eLedRegStat_t eLedRegStat;

static tLedPara_t satLedPara[NUM_OF_LEDS];
static tLedPara_t satLedParaBuf[NUM_OF_LEDS];  //低优先级LED缓存

/**
  * @brief  Initialize LED number and callback function
  *
  * @param  None
  *
  * @retval None
  */
#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)
void ledApp_init(void){
  satLedPara[LED_GREEN].pLedOn = hal_gpio_greenLedOn;
  satLedPara[LED_GREEN].pLedOff = hal_gpio_greenLedOff;
  satLedPara[LED_GREEN].pGetLedStat = hal_gpio_getGreenLedStat;
  
  satLedPara[LED_RED].pLedOn = hal_gpio_redLedOn;
  satLedPara[LED_RED].pLedOff = hal_gpio_redLedOff;
  satLedPara[LED_RED].pGetLedStat = hal_gpio_getRedLedStat;

  ledApp_register(LED_GREEN,
                  RED_LED_PRIORITY_UNADDR,
                  500,
                  500,
                  10,
                  ledApp_null);

  satLedPara[LED_GREEN].bEnable = true;
  satLedPara[LED_RED].bEnable = true;
  //hal_flash_readMultiWords(LEDAPP_FLASH_BASE, 4, suiLedEnable);
}
#endif

#if (LBUS_DEVICE_TYPE == LBUS_DT4_TYPE)
void ledApp_init(void){
  satLedPara[LED_GREEN_1].pLedOn = hal_gpio_greenLedOn_1;
  satLedPara[LED_GREEN_1].pLedOff = hal_gpio_greenLedOff_1;
  satLedPara[LED_GREEN_1].pGetLedStat = hal_gpio_getGreenLedStat_1;

  satLedPara[LED_GREEN_2].pLedOn = hal_gpio_greenLedOn_2;
  satLedPara[LED_GREEN_2].pLedOff = hal_gpio_greenLedOff_2;
  satLedPara[LED_GREEN_2].pGetLedStat = hal_gpio_getGreenLedStat_2;

  satLedPara[LED_GREEN_3].pLedOn = hal_gpio_greenLedOn_3;
  satLedPara[LED_GREEN_3].pLedOff = hal_gpio_greenLedOff_3;
  satLedPara[LED_GREEN_3].pGetLedStat = hal_gpio_getGreenLedStat_3;

  satLedPara[LED_GREEN_4].pLedOn = hal_gpio_greenLedOn_4;
  satLedPara[LED_GREEN_4].pLedOff = hal_gpio_greenLedOff_4;
  satLedPara[LED_GREEN_4].pGetLedStat = hal_gpio_getGreenLedStat_4;

  satLedPara[LED_GREEN_5].pLedOn = hal_gpio_greenLedOn_5;
  satLedPara[LED_GREEN_5].pLedOff = hal_gpio_greenLedOff_5;
  satLedPara[LED_GREEN_5].pGetLedStat = hal_gpio_getGreenLedStat_5;

  satLedPara[LED_GREEN_6].pLedOn = hal_gpio_greenLedOn_6;
  satLedPara[LED_GREEN_6].pLedOff = hal_gpio_greenLedOff_6;
  satLedPara[LED_GREEN_6].pGetLedStat = hal_gpio_getGreenLedStat_6;

///////////////////////////////
  satLedPara[LED_RED_1].pLedOn = hal_gpio_redLedOn_1;
  satLedPara[LED_RED_1].pLedOff = hal_gpio_redLedOff_1;
  satLedPara[LED_RED_1].pGetLedStat = hal_gpio_getRedLedStat_1;

  satLedPara[LED_RED_2].pLedOn = hal_gpio_redLedOn_2;
  satLedPara[LED_RED_2].pLedOff = hal_gpio_redLedOff_2;
  satLedPara[LED_RED_2].pGetLedStat = hal_gpio_getRedLedStat_2;

  satLedPara[LED_RED_3].pLedOn = hal_gpio_redLedOn_3;
  satLedPara[LED_RED_3].pLedOff = hal_gpio_redLedOff_3;
  satLedPara[LED_RED_3].pGetLedStat = hal_gpio_getRedLedStat_3;

  satLedPara[LED_RED_4].pLedOn = hal_gpio_redLedOn_4;
  satLedPara[LED_RED_4].pLedOff = hal_gpio_redLedOff_4;
  satLedPara[LED_RED_4].pGetLedStat = hal_gpio_getRedLedStat_4;

  satLedPara[LED_RED_5].pLedOn = hal_gpio_redLedOn_5;
  satLedPara[LED_RED_5].pLedOff = hal_gpio_redLedOff_5;
  satLedPara[LED_RED_5].pGetLedStat = hal_gpio_getRedLedStat_5;

  satLedPara[LED_RED_6].pLedOn = hal_gpio_redLedOn_6;
  satLedPara[LED_RED_6].pLedOff = hal_gpio_redLedOff_6;
  satLedPara[LED_RED_6].pGetLedStat = hal_gpio_getRedLedStat_6;
//若设备处于未入网状态，面板LED白色处于慢闪状态
#if 0
  for(uint8_t i=0;i<6;i++)
  {
	  ledApp_register(i,
	                  RED_LED_PRIORITY_UNADDR,
	                  700,
	                  700,
					  0xFFFFFFFF,
	                  ledApp_null);

  }
#endif
#if 0//常亮绿色三秒后熄灭
  for(uint8_t i=0;i<6;i++)
  {
	  ledApp_register(i,
	                  RED_LED_PRIORITY_UNADDR,
	                  3000,
	                  0,
					  1,
	                  ledApp_null);

  }
#endif
#if 0//慢闪绿色10秒后熄灭
  for(uint8_t i=0;i<6;i++)
  {
	  ledApp_register(i,
	                  RED_LED_PRIORITY_UNADDR,
	                  700,
	                  700,
					  7,
	                  ledApp_null);

  }
#endif









//代码冗余
//  ledApp_register(LED_RED_1,
//                  RED_LED_PRIORITY_UNADDR,
//                  500,
//                  500,
//                  10,
//                  ledApp_null);
//总线主控器搜索过程面板白色指示灯快闪，直至搜索到设备成功后，面板LED灯长亮，呈现白色，入网成功。搜索失败时，面板指示灯恢复到慢闪状态。
#if 0
  for(uint8_t i=0;i<12;i++)
  {
	  ledApp_register(i,
	                  RED_LED_PRIORITY_UNADDR,
	                  300,
	                  300,
					  0xFFFFFFFF,
	                  ledApp_null);

  }
#endif
#if 0
//关闭所有12个灯
  for(uint8_t i=0;i<12;i++)
  {

	  ledApp_unregister(i);
  }
#endif
//设备升级过程：面板白色LED指示灯开始慢闪，在整个OTA过程中保持慢闪。设备升级成功：面板白色LED指示灯长亮3s后熄灭。
  //设备升级失败：面板白色LED指示灯慢闪10s后熄灭
 // 过程结束之后恢复到正常状态。
for(uint8_t i=0;i<12;i++)
{
	satLedPara[i].bEnable = true;

}
//  satLedPara[LED_GREEN_1].bEnable = true;
//  satLedPara[LED_RED_1].bEnable = true;
//
//  satLedPara[LED_GREEN_2].bEnable = true;
//  satLedPara[LED_RED_2].bEnable = true;
  //hal_flash_readMultiWords(LEDAPP_FLASH_BASE, 4, suiLedEnable);
}
#endif


void ledApp_writeFalsh(uint32_t addrBase){
  //hal_flash_writeMultiWords(addrBase, 4, suiLedEnable);
}

/**
  * @brief  Flash LED action registration
  *
  * @param[in]  cLedNum       : The LED ID number.
  * @param[in]  cPriority     : The higher the value, the higher the priority.
  * @param[in]  uiOnTime      : The time the LED is on.
  * @param[in]  uiOffTime     : The time the LED is off.  
  * @param[in]  uiLoopTimes   : loop times,equal to the maximum for an infinite loop，shall not be 0!!!
  * @param[in]  pOverCb       : After the flashing is finished, this callback function executes.
  *
  * @retval None
  */
void ledApp_register(uint8_t cLedNum,
                      uint8_t cPriority,
                      uint32_t uiOnTime,
                      uint32_t uiOffTime,
                      uint32_t uiLoopTimes,
                      void(*pOverCb)()){
  if(E_LED_REGISTER == satLedPara[cLedNum].eRegState){
    if(cPriority > satLedPara[cLedNum].cPriority){
      satLedParaBuf[cLedNum].cPriority = satLedPara[cLedNum].cPriority;
      satLedParaBuf[cLedNum].uiOnTime = satLedPara[cLedNum].uiOnTime;
      satLedParaBuf[cLedNum].uiOffTime = satLedPara[cLedNum].uiOffTime;
      satLedParaBuf[cLedNum].uiLoopTimes = satLedPara[cLedNum].uiLoopTimes;
      satLedParaBuf[cLedNum].pOverCb = satLedPara[cLedNum].pOverCb;
      satLedParaBuf[cLedNum].eRegState = E_LED_REGISTER;
      satLedParaBuf[cLedNum].uiCounter = 0;
      satLedParaBuf[cLedNum].cLedInitStat = satLedPara[cLedNum].cLedInitStat;

      satLedPara[cLedNum].cPriority = cPriority;
      satLedPara[cLedNum].uiOnTime = uiOnTime;
      satLedPara[cLedNum].uiOffTime = uiOffTime;
      satLedPara[cLedNum].uiLoopTimes = uiLoopTimes;
      satLedPara[cLedNum].pOverCb = pOverCb;
      satLedPara[cLedNum].eRegState = E_LED_REGISTER;
      satLedPara[cLedNum].uiCounter = 0;
    }
    else if(cPriority == satLedPara[cLedNum].cPriority){
      satLedPara[cLedNum].cPriority = cPriority;
      satLedPara[cLedNum].uiOnTime = uiOnTime;
      satLedPara[cLedNum].uiOffTime = uiOffTime;
      satLedPara[cLedNum].uiLoopTimes = uiLoopTimes;
      satLedPara[cLedNum].pOverCb = pOverCb;
      satLedPara[cLedNum].eRegState = E_LED_REGISTER;
      satLedPara[cLedNum].uiCounter = 0;
      satLedPara[cLedNum].cLedInitStat = satLedPara[cLedNum].pGetLedStat();
    }
  }
  else{
    satLedPara[cLedNum].cPriority = cPriority;
    satLedPara[cLedNum].uiOnTime = uiOnTime;
    satLedPara[cLedNum].uiOffTime = uiOffTime;
    satLedPara[cLedNum].uiLoopTimes = uiLoopTimes;
    satLedPara[cLedNum].pOverCb = pOverCb;
    satLedPara[cLedNum].eRegState = E_LED_REGISTER;
    satLedPara[cLedNum].uiCounter = 0;
    satLedPara[cLedNum].cLedInitStat = satLedPara[cLedNum].pGetLedStat();
  }
}
					  ///h文件申明
					  void CirculationFlashing_led1(void)
					  {

					  ledApp_register(0,
									  RED_LED_PRIORITY_UNADDR,
									  100,
									  500,
									  0xFFFFFFFF,
									  ledApp_null);
					  }
					  					void CirculationFlashing_led2(void)
					  					{

					  					ledApp_register(1,
					  									RED_LED_PRIORITY_UNADDR,
														100,
														500,
					  									0xFFFFFFFF,
					  									ledApp_null);
					  					}

					  void CirculationFlashing_led3(void)
					  {

					  ledApp_register(2,
									  RED_LED_PRIORITY_UNADDR,
									  100,
									  500,
									  0xFFFFFFFF,
									  ledApp_null);
					  }
					  void CirculationFlashing_led4(void)
					  {

					  ledApp_register(3,
									  RED_LED_PRIORITY_UNADDR,
									  100,
									  500,
									  0xFFFFFFFF,
									  ledApp_null);
					  }
					  void CirculationFlashing_led5(void)
					  {

					  ledApp_register(4,
									  RED_LED_PRIORITY_UNADDR,
									  100,
									  500,
									  0xFFFFFFFF,
									  ledApp_null);
					  }
					  void CirculationFlashing_led6(void)
					  {

					  ledApp_register(5,
									  RED_LED_PRIORITY_UNADDR,
									  100,
									  500,
									  0xFFFFFFFF,
									  ledApp_null);
					  }
					  void fastfalsh_led4_green()
					  {
					  	  ledApp_register(3,
	                  		RED_LED_PRIORITY_UNADDR,
	                  		300,
	                  		300,
					  		0xFFFFFFFF,
	                  		ledApp_null);
						 // ledApp_unregister(3);


					  }
					  void fastfalsh_led4_green_off()
					  	{
							hal_gpio_greenLedOff_4();

					  }
					  
#if 1//循环6个绿色


void CirculationFlashing()
{
timerApp_register(CirculationFlashing_led1, CIRCULATION_FLASHING_TIMER_1, 0, 1);
timerApp_register(CirculationFlashing_led2, CIRCULATION_FLASHING_TIMER_2, 100, 1);
timerApp_register(CirculationFlashing_led3, CIRCULATION_FLASHING_TIMER_3, 200, 1);
timerApp_register(CirculationFlashing_led4, CIRCULATION_FLASHING_TIMER_4, 500, 1);
timerApp_register(CirculationFlashing_led5, CIRCULATION_FLASHING_TIMER_5, 400, 1);
timerApp_register(CirculationFlashing_led6, CIRCULATION_FLASHING_TIMER_6, 300, 1);
	
}


#endif

void ledApp_unregister(uint8_t cLedNum){
  satLedPara[cLedNum].eRegState = E_LED_UNREGISTER;//hal_gpio_greenLedOff_4
  if(satLedPara[cLedNum].cLedInitStat == 0)//注册前为灭
  {
  	satLedPara[cLedNum].pLedOff();
  }else{
  	
  satLedPara[cLedNum].pLedOn();

  }
  
}

/**
  * @brief  Execute the callback function in the main loop
  *
  * @param  None
  *
  * @retval None
  */
void ledApp_task(void){
  for(uint8_t i=0; i<NUM_OF_LEDS; i++){
    if(true == satLedPara[i].bEnable){
      if(E_LED_REGISTER == satLedPara[i].eRegState){
        if((satLedPara[i].uiCounter==0) && (0 < satLedPara[i].uiOnTime)){
          satLedPara[i].pLedOn();
        }
        else if((satLedPara[i].uiCounter == satLedPara[i].uiOnTime) && (0 < satLedPara[i].uiOffTime)){
          satLedPara[i].pLedOff();
        }
        else if(satLedPara[i].uiCounter == (satLedPara[i].uiOnTime + satLedPara[i].uiOffTime)){
          if(LEDAPP_INFINITE_LOOP != satLedPara[i].uiLoopTimes){
            satLedPara[i].uiLoopTimes--;
          }
          satLedPara[i].uiCounter = 0;
          if(0 == satLedPara[i].uiLoopTimes){
            satLedPara[i].eRegState = E_LED_UNREGISTER;
            if(E_LED_REGISTER == satLedParaBuf[i].eRegState){
              satLedPara[i].cPriority = satLedParaBuf[i].cPriority;
              satLedPara[i].uiOnTime = satLedParaBuf[i].uiOnTime;
              satLedPara[i].uiOffTime = satLedParaBuf[i].uiOffTime;
              satLedPara[i].uiLoopTimes = satLedParaBuf[i].uiLoopTimes;
              satLedPara[i].pOverCb = satLedParaBuf[i].pOverCb;
              satLedPara[i].eRegState = E_LED_REGISTER;
              satLedPara[i].uiCounter = 0;
              satLedPara[i].cLedInitStat = satLedParaBuf[i].cLedInitStat;
            }
            else{
              if(0 == satLedPara[i].cLedInitStat){
                satLedPara[i].pLedOff();
              }
              else{
                satLedPara[i].pLedOn();
              }
            }
          }
        }
      }
    }
    else{
      if(1 == satLedPara[i].pGetLedStat){
        satLedPara[i].pLedOff();
      }
      if(E_LED_REGISTER == satLedPara[i].eRegState){
        satLedPara[i].eRegState = E_LED_UNREGISTER;
      }
    }
  }
}

/**
  * @brief  background ticks,repeat invoking interval 1ms
  *
  * @param  None
  *
  * @retval None
  */
void ledApp_ticks(void){
  for(uint8_t i=0; i<NUM_OF_LEDS; i++){
    if(E_LED_REGISTER == satLedPara[i].eRegState){
      satLedPara[i].uiCounter++;
    }
  }
}

void ledApp_enable(uint8_t cLedNum, bool bEnable){
  satLedPara[cLedNum].bEnable = bEnable;
}

void ledApp_null(void){
  return;
}


