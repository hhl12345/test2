#ifndef __LDS_BUTTONAPP_H__
#define __LDS_BUTTONAPP_H__  

#include <stdint.h>
#include <stdbool.h>

#define NUM_OF_BUTTONS       6 //按键总数

#define BUTTON_1	   0
#define BUTTON_2       1
#define BUTTON_3       2
#define BUTTON_4       3
#define BUTTON_5       4
#define BUTTON_6       5


#define PRESS_TIME  10//单位为10ms

typedef enum{
  E_BUTTON_RELEASE = 0U,
  E_BUTTON_PRESS
}eButtonState_t;
typedef enum{
	E_BUTTON_BROADCAST = 0U,//广播模式
	E_BUTTON_LINKED,//联动反馈按键编号给主控器
	E_BUTTON_FORBIDDEN,//禁用模式
	E_BUTTON_RESET//待复位模式
}eButtonMode_t;

typedef struct{
  uint32_t uiCounter[NUM_OF_BUTTONS];     //按下计数值，单位为10ms
  uint32_t uiKeyMode[NUM_OF_BUTTONS];    //0广播模式 1联动模式 2禁用模式 3复位模式
  void (*pCb)(uint8_t cButtonNum, eButtonState_t eButtonState,eButtonMode_t mode);
}tButtonPara_t;


/***********************************************/
/*                                             */ 
/*                API                          */
/*                                             */
/***********************************************/
void buttonApp_register(void(*pCb)(uint8_t cButtonNum, uint8_t cPress));
void buttonApp_ticks(void);
uint32_t buttonApp_getCntVal(uint8_t cButtonNum);
//void CirculationFlashing_led2(void);
void app_rstButton(uint8_t cButtonNum, eButtonState_t eButtonState,eButtonMode_t mode);
#endif

