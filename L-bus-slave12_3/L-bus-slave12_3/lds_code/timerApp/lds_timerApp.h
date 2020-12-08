#ifndef __LDS_TIMERAPP_H__
#define __LDS_TIMERAPP_H__  

#include <stdint.h>

#define NUM_OF_TIMERS       9 //�������涨ʱ����������

/*�������õ��Ķ�ʱ�����ڴ˴�ע�����*/
#define RESET_BUTTON_5S_TIMER         	    0
#define RESET_BUTTON_WAIT_RELEASE_TIMER     1
#define READ_LIGHT_SENSOR_TMR               2
#define CIRCULATION_FLASHING_TIMER_1    		3
#define CIRCULATION_FLASHING_TIMER_2    		4
#define CIRCULATION_FLASHING_TIMER_3    		5
#define CIRCULATION_FLASHING_TIMER_4    		6
#define CIRCULATION_FLASHING_TIMER_5    		7
#define CIRCULATION_FLASHING_TIMER_6    		8



#define TIMEOUT_500MS     500
#define TIMEOUT_1S        1000



#define TIMERAPP_INFINITE_LOOP 0xFFFFFFFF




typedef enum{
  E_TIMER_UNREGISTER,
  E_TIMER_REGISTER
}eTimerRegStat_t;

typedef struct{
  void (*pCb)();  	               //�ص�����
  eTimerRegStat_t  eRegState;      //1Ϊע�ᣬ0Ϊδע��
  uint32_t uiLoopTimes;            //ѭ�����������ֵ��ʾ����ѭ��
  uint32_t uiCounter;              //�ۼ���
  uint32_t uiTimeout;              //��ʱʱ��
}tTimerPara_t;


/***********************************************/
/*                                             */
/*                API                          */
/*                                             */
/***********************************************/
void timerApp_register(void(*pFunc)(), uint8_t cTimerNum, uint32_t uiTimeout, uint32_t uiLoopTimes);
void timerApp_unregister(uint8_t cTimerNum);
void timerApp_task(void);
void timerApp_ticks(void);
uint32_t timerApp_getCounterVal(uint8_t cTimerNum);
eTimerRegStat_t timerApp_getStat(uint8_t cTimerNum);
void timerApp_null(void);

#endif

