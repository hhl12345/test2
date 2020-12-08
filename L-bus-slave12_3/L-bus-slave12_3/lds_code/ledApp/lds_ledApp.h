#ifndef __LDS_LEDAPP_H__
#define __LDS_LEDAPP_H__  

#include <stdint.h>
#include <stdbool.h>
#include "lds_config.h"

#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)

#define NUM_OF_LEDS       2 	//LED的全部个数

#define LEDAPP_FLASH_BASE  0x1F150

#define LEDAPP_INFINITE_LOOP 0xFFFFFFFF

/*将所有用到的LED，在此处注册序号*/
#define LED_GREEN        0
#define LED_RED          1

/*LED行为优先级*/
#define RED_LED_PRIORITY_UNADDR      0 
#define RED_LED_PRIORITY_SET_PARA    1 
#define RED_LED_PRIORITY_RESET       2 

#define GREEN_LED_PRIORITY_LOWEST    0 

#endif
/*******************************************DT4_6keys_pannel***********************************/
#if (LBUS_DEVICE_TYPE == LBUS_DT4_TYPE)

#define NUM_OF_LEDS       12 	//LED的全部个数

#define LEDAPP_INFINITE_LOOP 0xFFFFFFFF
#define LEDAPP_FLASH_BASE  0x1F150

#define RED_LED_PRIORITY_UNADDR      0
#define RED_LED_PRIORITY_SET_PARA    1
#define RED_LED_PRIORITY_RESET       2

#define GREEN_LED_PRIORITY_LOWEST    0
/*将所有用到的LED，在此处注册序号*/
#define LED_GREEN_1        0
#define LED_GREEN_2        1
#define LED_GREEN_3        2
#define LED_GREEN_4        3
#define LED_GREEN_5        4
#define LED_GREEN_6        5

#define LED_RED_1          6
#define LED_RED_2          7
#define LED_RED_3          8
#define LED_RED_4          9
#define LED_RED_5          10
#define LED_RED_6          11




#endif
/*******************************************DT4_6keys_pannel***********************************/

typedef enum{
  E_LED_UNREGISTER,
  E_LED_REGISTER
}eLedRegStat_t;

typedef struct{
  void (*pLedOn)();  		    //点亮LED
  void (*pLedOff)();  		  //熄灭LED
  uint8_t(*pGetLedStat)();  //LED初始状态：0-灭，1-亮, 其他值-未知
  void (*pOverCb)();  	    //完成闪灯后调用
  uint32_t uiCounter;      	//累加器
  uint32_t uiOnTime;      	//LED点亮时间
  uint32_t uiOffTime;    		//LED熄灭时间
  eLedRegStat_t  eRegState; //注册状态
  uint32_t uiLoopTimes; 	  //闪灯循环次数，最大值表示无限循环.不能为该值赋值0！！！
  uint8_t cPriority;		    //优先级，值越大，优先级越高
  uint8_t cLedInitStat;		  //LED注册前的初始状态:0-1-亮
  bool bEnable;             //开启或禁用LED
}tLedPara_t;

extern eLedRegStat_t eLedRegStat;


/***********************************************/
/*                                             */
/*                API                          */
/*                                             */
/***********************************************/
void ledApp_init(void);
void ledApp_writeFalsh(uint32_t addrBase);
void ledApp_register(uint8_t cLedNum,
                      uint8_t cPriority,
                      uint32_t uiOnTime,
                      uint32_t uiOffTime,
                      uint32_t uiLoopTimes,
                      void(*pOverCb)());
void ledApp_unregister(uint8_t cLedNum);
void ledApp_task(void);
void ledApp_ticks(void);
void ledApp_enable(uint8_t cLedNum, bool bEnable);
void ledApp_null(void);
void CirculationFlashing_led1(void);
void CirculationFlashing_led2(void);
void CirculationFlashing_led3(void);
void CirculationFlashing_led4(void);
void CirculationFlashing_led5(void);
void CirculationFlashing_led6(void);
void fastfalsh_led4_green();
void CirculationFlashing();
void fastfalsh_led4_green_off();








#endif

