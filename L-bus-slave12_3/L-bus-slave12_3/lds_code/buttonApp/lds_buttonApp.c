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

#include "lds_buttonApp.h"
#include "lds_hal_gpio.h"//��c�ļ��ж���button��Ӳ���ӿں���
#include "lds_timerApp.h"
#include "lds_ledApp.h"

static tButtonPara_t sstButtonPara;


static uint8_t (*paReadPin[NUM_OF_BUTTONS])(void)={
		hal_gpio_getButtonStat_1,
		hal_gpio_getButtonStat_2,
		hal_gpio_getButtonStat_3,
		hal_gpio_getButtonStat_4,
		hal_gpio_getButtonStat_5,
		hal_gpio_getButtonStat_6
};

/**
  * @brief  Register the callback
  *
  * @param[in]  pCb: the callback function.
  *
  * @retval None
  */
void buttonApp_register(void(*pCb)(uint8_t, eButtonState_t)){
  sstButtonPara.pCb = pCb;
  for(uint8_t i=0; i<NUM_OF_BUTTONS ;i++)
  {
	  sstButtonPara.uiKeyMode[i] = E_BUTTON_BROADCAST;//��ʼ��ģʽ
	  	  //sstButtonPara.uiKeyMode[i] = E_BUTTON_LINKED;//��ʼ��ģʽ
	  	  	  //sstButtonPara.uiKeyMode[i] = E_BUTTON_FORBIDDEN;//��ʼ��ģʽ
	  	  	  	  //sstButtonPara.uiKeyMode[i] = E_BUTTON_RESET;//��ʼ��ģʽ
  }
}


/**
  * @brief  background ticks, repeat invoking interval 1ms
  *
  * @param  None
  *
  * @retval None
  */
void buttonApp_ticks(void){
  static uint8_t c10msCnt = 0;
  
  if(10 <= c10msCnt){
    c10msCnt = 0;
    for(uint8_t i=0; i<NUM_OF_BUTTONS; i++){
      if(1 == paReadPin[i]()){
        sstButtonPara.uiCounter[i]++;
        if(PRESS_TIME == sstButtonPara.uiCounter[i]){
          sstButtonPara.pCb(i,E_BUTTON_PRESS,sstButtonPara.uiKeyMode[i]);
        }
      }
      else{
        if(PRESS_TIME <= sstButtonPara.uiCounter[i]){
          sstButtonPara.uiCounter[i] = 0;
          sstButtonPara.pCb(i,E_BUTTON_RELEASE,sstButtonPara.uiKeyMode[i]);
        }
        else if(0 != sstButtonPara.uiCounter[i]){
          sstButtonPara.uiCounter[i] = 0;
        }
      }
    }
  }
  else{
    c10msCnt++;
  }
}

//uint32_t buttonApp_getCntVal(uint8_t cButtonNum){
//  return sstButtonPara.uiCounter[cButtonNum];
//}
//static void app_redLedFlashFastest(void){
//  ledApp_register(LED_RED_1, RED_LED_PRIORITY_RESET, 100, 100, 0xFFFFFFFF, ledApp_null);
//}
#if 1
void app_rstButton(uint8_t cButtonNum, eButtonState_t eButtonState,eButtonMode_t mode){
  uint32_t uiValue = 0;
  
  if(BUTTON_1 == cButtonNum){
	 if(mode == E_BUTTON_BROADCAST)
	 {
		    if(E_BUTTON_PRESS == eButtonState){
		 	  //timerApp_register(app_redLedFlashFastest, RESET_BUTTON_5S_TIMER, 5000, 1);
		      timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
		    }
		    else{
		      uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		      timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
		    	if(800 > uiValue)//�̰�
		    	{
		    		printf("�㲥ģʽ�¶̰�BUTTON_1");
		    	}
		    	if(5000 < uiValue){
		//        timerApp_unregister(RESET_BUTTON_5S_TIMER);
		    		printf("�㲥ģʽ�³���BUTTON_1");
		      }
		    }


	 }else if(mode == E_BUTTON_LINKED)
	 {
		    if(E_BUTTON_PRESS == eButtonState){
		//      timerApp_register(app_redLedFlashFastest, RESET_BUTTON_5S_TIMER, 5000, 1);
		      timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
		    }
		    else{
		      uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		      timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
		    	if(800 > uiValue)//�̰�
		    	{
		    		printf("����ģʽ�¶̰�BUTTON_1");//���ذ�����ź����ߵ�ַ
		    	}
		    	if(5000 < uiValue){
		//        timerApp_unregister(RESET_BUTTON_5S_TIMER);
		    		printf("����ģʽ�³���BUTTON_1"); //������
		      }
		    }



	 }else if(mode == E_BUTTON_FORBIDDEN)
	 {
				if(E_BUTTON_PRESS == eButtonState){ 					  
				}
				else{					  
				printf("����ģʽBUTTON_2");
				}


	 }else//��λģʽ��
	 {
		    if(E_BUTTON_PRESS == eButtonState){

		    }
		    else{
		    	//���븴λ����ʼ��λ
		    	
				ledApp_unregister(LED_GREEN_4);
		    	printf("ȡ������λ״̬�����а����ص��㲥����ģʽ");
				for(uint8_t i=0;i<6;i++)
		  	  	  	  sstButtonPara.uiKeyMode[i] = E_BUTTON_BROADCAST;
				
				

		      }
	 }//else

	 }

	
	if(BUTTON_2 == cButtonNum){
	   if(mode == E_BUTTON_BROADCAST)
	   {
			  if(E_BUTTON_PRESS == eButtonState){
				//timerApp_register(app_redLedFlashFastest, RESET_BUTTON_5S_TIMER, 5000, 1);
				timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
			  }
			  else{
				uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		  	  timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
				  if(800 > uiValue)//�̰�
				  {
					  printf("�㲥ģʽ�¶̰�BUTTON_2");
				  }
				  if(5000 < uiValue){
		  //		timerApp_unregister(RESET_BUTTON_5S_TIMER);
					  printf("�㲥ģʽ�³���BUTTON_2");
				}
			  }
  
  
	   }else if(mode == E_BUTTON_LINKED)
	   {
			  if(E_BUTTON_PRESS == eButtonState){
		  //	  timerApp_register(app_redLedFlashFastest, RESET_BUTTON_5S_TIMER, 5000, 1);
				timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
			  }
			  else{
				uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		  	  timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
				  if(800 > uiValue)//�̰�
				  {
					  printf("����ģʽ�¶̰�BUTTON_2");//���ذ�����ź����ߵ�ַ
				  }
				  if(5000 < uiValue){
		  //		timerApp_unregister(RESET_BUTTON_5S_TIMER);
					  printf("����ģʽ�³���BUTTON_2"); //������
				}
			  }
  
  
  
	   }else if(mode == E_BUTTON_FORBIDDEN)
	   {
					  if(E_BUTTON_PRESS == eButtonState){					  	
					  }
					  else{						
					  printf("����ģʽBUTTON_2");
					  }

  
	   }else//��λģʽ��
	   {
			  if(E_BUTTON_PRESS == eButtonState){
  
			  }
			  else{
				  ledApp_unregister(LED_GREEN_4);
				  printf("ȡ������λ״̬�����а����ص��㲥����ģʽ");
				  for(uint8_t i=0;i<6;i++)
						sstButtonPara.uiKeyMode[i] = E_BUTTON_BROADCAST;

  
				}
	   }//else
  
	   }
  
  
  
  
   
  
  
  
  if(BUTTON_3 == cButtonNum){
	 if(mode == E_BUTTON_BROADCAST)
	 {
		    if(E_BUTTON_PRESS == eButtonState){
		 	  //timerApp_register(app_redLedFlashFastest, RESET_BUTTON_5S_TIMER, 5000, 1);
		      timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
		    }
		    else{
		      uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		      timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
		    	if(800 > uiValue)//�̰�
		    	{
		    		printf("�㲥ģʽ�¶̰�BUTTON_3");
		    	}
		    	if(5000 < uiValue){
		//        timerApp_unregister(RESET_BUTTON_5S_TIMER);
		    		printf("�㲥ģʽ�³���BUTTON_3");
		      }
		    }


	 }else if(mode == E_BUTTON_LINKED)
	 {
		    if(E_BUTTON_PRESS == eButtonState){
		//      timerApp_register(app_redLedFlashFastest, RESET_BUTTON_5S_TIMER, 5000, 1);
		      timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
		    }
		    else{
		      uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		      timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
		    	if(800 > uiValue)//�̰�
		    	{
		    		printf("����ģʽ�¶̰�BUTTON_3");//���ذ�����ź����ߵ�ַ
		    	}
		    	if(5000 < uiValue){
		//        timerApp_unregister(RESET_BUTTON_5S_TIMER);
		    		printf("����ģʽ�³���BUTTON_3"); //������
		      }
		    }



	 }else if(mode == E_BUTTON_FORBIDDEN)
	 {
				if(E_BUTTON_PRESS == eButtonState){ 					  
				}
				else{					  
				printf("����ģʽBUTTON_2");
				}


	 }else//��λģʽ��
	 {
		    if(E_BUTTON_PRESS == eButtonState){

		    }
		    else{
				
			ledApp_unregister(LED_GREEN_4);
			HAL_Delay(10);
			CirculationFlashing();
		    	printf("��ʼ��λ�������ָ��������ã�");

		      }
	 }//else

	 }



	
	if(BUTTON_4 == cButtonNum){
	   if(mode == E_BUTTON_BROADCAST)
	   {
			  if(E_BUTTON_PRESS == eButtonState){
			  //��ʱ��5���4�ż�����          ִ��һ�κ��Զ�ȡ��ע�� ��4���������ȴ������������¾�ֹͣ			  
				timerApp_register(fastfalsh_led4_green, RESET_BUTTON_5S_TIMER, 5000, 1);
				timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
			  }
			  else{
				uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		  	  	timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
				  if(800 > uiValue)//�̰�
				  {
				  	  timerApp_unregister(RESET_BUTTON_5S_TIMER);
					  printf("�㲥ģʽ�¶̰�BUTTON_4");
				  }
				  if(5000 < uiValue){
		  //		timerApp_unregister(RESET_BUTTON_5S_TIMER);
					printf("�㲥ģʽ�³���BUTTON_4");
	
		  
		  //���6�������л�������λģʽ
		  for(uint8_t i=0;i<6;i++)
		  	  	  	  sstButtonPara.uiKeyMode[i] = E_BUTTON_RESET;
		  //������ѭ����˸����������

		  //��ʱ�������ص��㲥ģʽ �ǵ�ȡ��
		  				
				}
			  }
  
  
	   }else if(mode == E_BUTTON_LINKED)
	   {
			  if(E_BUTTON_PRESS == eButtonState){
		  	  timerApp_register(fastfalsh_led4_green, RESET_BUTTON_5S_TIMER, 5000, 1);
				timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
			  }
			  else{
				uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		  	  timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
				  if(800 > uiValue)//�̰�
				  {
					  printf("����ģʽ�¶̰�BUTTON_4");//���ذ�����ź����ߵ�ַ
				  }
				  if(5000 < uiValue){
		  //		timerApp_unregister(RESET_BUTTON_5S_TIMER);
					  printf("����ģʽ�³���BUTTON_4"); //������
				}
			  }
  
  
  
	   }else if(mode == E_BUTTON_FORBIDDEN)
	   {
				  if(E_BUTTON_PRESS == eButtonState){						
				  }
				  else{ 					
				  printf("����ģʽBUTTON_2");
				  }

  
	   }else//��λģʽ��
	   {
			  if(E_BUTTON_PRESS == eButtonState){
  
			  }
			  else{
			  	
			  ledApp_unregister(LED_GREEN_4);
				  printf("ȡ������λ״̬�����а����ص��㲥����ģʽ");
				  for(uint8_t i=0;i<6;i++)
						sstButtonPara.uiKeyMode[i] = E_BUTTON_BROADCAST;

  
				}
	   }//else
  
	   }
  
  
  
  
   
  
  
  


	
	if(BUTTON_5 == cButtonNum){
	   if(mode == E_BUTTON_BROADCAST)
	   {
			  if(E_BUTTON_PRESS == eButtonState){
				//timerApp_register(app_redLedFlashFastest, RESET_BUTTON_5S_TIMER, 5000, 1);
				timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
			  }
			  else{
				uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		  	  timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
				  if(800 > uiValue)//�̰�
				  {
					  printf("�㲥ģʽ�¶̰�BUTTON_5");
				  }
				  if(5000 < uiValue){
		  //		timerApp_unregister(RESET_BUTTON_5S_TIMER);
					  printf("�㲥ģʽ�³���BUTTON_5");
				}
			  }
  
  
	   }else if(mode == E_BUTTON_LINKED)
	   {
			  if(E_BUTTON_PRESS == eButtonState){
		  //	  timerApp_register(app_redLedFlashFastest, RESET_BUTTON_5S_TIMER, 5000, 1);
				timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
			  }
			  else{
				uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		  	  timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
				  if(800 > uiValue)//�̰�
				  {
					  printf("����ģʽ�¶̰�BUTTON_5");//���ذ�����ź����ߵ�ַ
				  }
				  if(5000 < uiValue){
		  //		timerApp_unregister(RESET_BUTTON_5S_TIMER);
					  printf("����ģʽ�³���BUTTON_5"); //������
				}
			  }
  
  
  
	   }else if(mode == E_BUTTON_FORBIDDEN)
	   {
				  if(E_BUTTON_PRESS == eButtonState){						
				  }
				  else{ 					
				  printf("����ģʽBUTTON_2");
				  }

  
	   }else//��λģʽ��
	   {
			  if(E_BUTTON_PRESS == eButtonState){
  
			  }
			  else{
			  	
			  ledApp_unregister(LED_GREEN_4);
				  printf("ȡ������λ״̬�����а����ص��㲥����ģʽ");
				  for(uint8_t i=0;i<6;i++)
						sstButtonPara.uiKeyMode[i] = E_BUTTON_BROADCAST;

  
				}
	   }//else
  
	   }
  
  
  
  
   
  
  
  


	
	if(BUTTON_6 == cButtonNum){
	   if(mode == E_BUTTON_BROADCAST)
	   {
			  if(E_BUTTON_PRESS == eButtonState){
				//timerApp_register(app_redLedFlashFastest, RESET_BUTTON_5S_TIMER, 5000, 1);
				timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
			  }
			  else{
				uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		  	  timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
				  if(800 > uiValue)//�̰�
				  {
					  printf("�㲥ģʽ�¶̰�BUTTON_6");
				  }
				  if(5000 < uiValue){
		  //		timerApp_unregister(RESET_BUTTON_5S_TIMER);
					  printf("�㲥ģʽ�³���BUTTON_6");
				}
			  }
  
  
	   }else if(mode == E_BUTTON_LINKED)
	   {
			  if(E_BUTTON_PRESS == eButtonState){
		  //	  timerApp_register(app_redLedFlashFastest, RESET_BUTTON_5S_TIMER, 5000, 1);
				timerApp_register(timerApp_null, RESET_BUTTON_WAIT_RELEASE_TIMER, TIMERAPP_INFINITE_LOOP, 1);
			  }
			  else{
				uiValue = timerApp_getCounterVal(RESET_BUTTON_WAIT_RELEASE_TIMER);
		  	  timerApp_unregister(RESET_BUTTON_WAIT_RELEASE_TIMER);
				  if(800 > uiValue)//�̰�
				  {
					  printf("����ģʽ�¶̰�BUTTON_6");//���ذ�����ź����ߵ�ַ
				  }
				  if(5000 < uiValue){
		  //		timerApp_unregister(RESET_BUTTON_5S_TIMER);
					  printf("����ģʽ�³���BUTTON_6"); //������
				}
			  }
  
  
  
	   }else if(mode == E_BUTTON_FORBIDDEN)
	   {
				  if(E_BUTTON_PRESS == eButtonState){						
				  }
				  else{ 					
				  printf("����ģʽBUTTON_2");
				  }

  
	   }else//��λģʽ��
	   {
			  if(E_BUTTON_PRESS == eButtonState){
  
			  }
			  else{
			  	
			  ledApp_unregister(LED_GREEN_4);
				  printf("ȡ������λ״̬�����а����ص��㲥����ģʽ");
				  for(uint8_t i=0;i<6;i++)
						sstButtonPara.uiKeyMode[i] = E_BUTTON_BROADCAST;

  
				}
	   }//else
  
	   }
  
  
  
  
   
  
  
  






 


}
#endif

