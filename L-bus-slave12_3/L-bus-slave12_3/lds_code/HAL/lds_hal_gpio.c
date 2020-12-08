/*
 * lds_hal_gpio.c
 *
 *  Created on: 2020Äê11ÔÂ18ÈÕ
 *      Author: zhangtao2
 */
#include "lds_hal_gpio.h"
#include "gpio.h"
#include "stm32f0xx_hal_gpio.h"

void hal_gpio_init(void){
  MX_GPIO_Init();
}

void hal_gpio_deInit(ldsGpioPort_t* pPort, uint16_t usPin){
  HAL_GPIO_DeInit(pPort, usPin);
}

void hal_gpio_setPinLevel(ldsGpioPort_t* pPort, uint16_t usPin, ePinState_t eLevel){
  HAL_GPIO_WritePin(pPort, usPin, eLevel);
}

ePinState_t hal_gpio_getPinLevel(ldsGpioPort_t* pPort, uint16_t usPin){
  if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(pPort, usPin)){
    return E_GPIO_PIN_RESET;
  }
  else{
    return E_GPIO_PIN_SET;
  }
}

void hal_gpio_togPinLevel(ldsGpioPort_t* pPort, uint16_t usPin){
  HAL_GPIO_TogglePin(pPort, usPin);
}
/***********************************************DT1*********************************************/
#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)
/**************  LED  **************/
void hal_gpio_redLedOn(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT, GPIO_RED_LED_PIN, GPIO_PIN_RESET);
}

void hal_gpio_redLedOff(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT, GPIO_RED_LED_PIN, GPIO_PIN_SET);
}

uint8_t hal_gpio_getRedLedStat(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_RED_LED_PORT, GPIO_RED_LED_PIN)){
    return 0;
  }
  else{
    return 1;
  }
}

void hal_gpio_greenLedOn(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT, GPIO_GREEN_LED_PIN, GPIO_PIN_RESET);
}

void hal_gpio_greenLedOff(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT, GPIO_GREEN_LED_PIN, GPIO_PIN_SET);
}

uint8_t hal_gpio_getGreenLedStat(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_GREEN_LED_PORT, GPIO_GREEN_LED_PIN)){
    return 0;
  }
  else{
    return 1;
  }
}

/**************  button  **************/
uint8_t hal_gpio_getRstButtonStat(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_RST_BUTTON_PORT, GPIO_RST_BUTTON_PIN)){
    return 0;
  }
  else{
    return 1;
  }
}
#endif
/***********************************************DT1*********************************************/

/***********************************************pannel_6keys*********************************************/
#if (LBUS_DEVICE_TYPE == LBUS_DT4_TYPE)
void hal_gpio_greenLedOn_1(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_1, GPIO_GREEN_LED_PIN_1, GPIO_PIN_RESET);
}
void hal_gpio_greenLedOn_2(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_2, GPIO_GREEN_LED_PIN_2, GPIO_PIN_RESET);
}
void hal_gpio_greenLedOn_3(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_3, GPIO_GREEN_LED_PIN_3, GPIO_PIN_RESET);
}
void hal_gpio_greenLedOn_4(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_4, GPIO_GREEN_LED_PIN_4, GPIO_PIN_RESET);
}
void hal_gpio_greenLedOn_5(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_5, GPIO_GREEN_LED_PIN_5, GPIO_PIN_RESET);
}
void hal_gpio_greenLedOn_6(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_6, GPIO_GREEN_LED_PIN_6, GPIO_PIN_RESET);
}


void hal_gpio_greenLedOff_1(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_1, GPIO_GREEN_LED_PIN_1, GPIO_PIN_SET);
}
void hal_gpio_greenLedOff_2(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_2, GPIO_GREEN_LED_PIN_2, GPIO_PIN_SET);
}
void hal_gpio_greenLedOff_3(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_3, GPIO_GREEN_LED_PIN_3, GPIO_PIN_SET);
}
void hal_gpio_greenLedOff_4(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_4, GPIO_GREEN_LED_PIN_4, GPIO_PIN_SET);
}
void hal_gpio_greenLedOff_5(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_5, GPIO_GREEN_LED_PIN_5, GPIO_PIN_SET);
}
void hal_gpio_greenLedOff_6(void){
  HAL_GPIO_WritePin(GPIO_GREEN_LED_PORT_6, GPIO_GREEN_LED_PIN_6, GPIO_PIN_SET);
}

uint8_t hal_gpio_getGreenLedStat_1(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_GREEN_LED_PORT_1, GPIO_GREEN_LED_PIN_1)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getGreenLedStat_2(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_GREEN_LED_PORT_2, GPIO_GREEN_LED_PIN_2)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getGreenLedStat_3(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_GREEN_LED_PORT_3, GPIO_GREEN_LED_PIN_3)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getGreenLedStat_4(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_GREEN_LED_PORT_4, GPIO_GREEN_LED_PIN_4)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getGreenLedStat_5(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_GREEN_LED_PORT_5, GPIO_GREEN_LED_PIN_5)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getGreenLedStat_6(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_GREEN_LED_PORT_6, GPIO_GREEN_LED_PIN_6)){
    return 0;
  }
  else{
    return 1;
  }
}




void hal_gpio_redLedOn_1(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_1, GPIO_RED_LED_PIN_1, GPIO_PIN_RESET);
}
void hal_gpio_redLedOn_2(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_2, GPIO_RED_LED_PIN_2, GPIO_PIN_RESET);
}
void hal_gpio_redLedOn_3(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_3, GPIO_RED_LED_PIN_3, GPIO_PIN_RESET);
}
void hal_gpio_redLedOn_4(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_4, GPIO_RED_LED_PIN_4, GPIO_PIN_RESET);
}
void hal_gpio_redLedOn_5(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_5, GPIO_RED_LED_PIN_5, GPIO_PIN_RESET);
}
void hal_gpio_redLedOn_6(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_6, GPIO_RED_LED_PIN_6, GPIO_PIN_RESET);
}



void hal_gpio_redLedOff_1(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_1, GPIO_RED_LED_PIN_1, GPIO_PIN_SET);
}
void hal_gpio_redLedOff_2(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_2, GPIO_RED_LED_PIN_2, GPIO_PIN_SET);
}
void hal_gpio_redLedOff_3(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_3, GPIO_RED_LED_PIN_3, GPIO_PIN_SET);
}
void hal_gpio_redLedOff_4(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_4, GPIO_RED_LED_PIN_4, GPIO_PIN_SET);
}
void hal_gpio_redLedOff_5(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_5, GPIO_RED_LED_PIN_5, GPIO_PIN_SET);
}
void hal_gpio_redLedOff_6(void){
  HAL_GPIO_WritePin(GPIO_RED_LED_PORT_6, GPIO_RED_LED_PIN_6, GPIO_PIN_SET);
}


uint8_t hal_gpio_getRedLedStat_1(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_RED_LED_PORT_1, GPIO_RED_LED_PIN_1)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getRedLedStat_2(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_RED_LED_PORT_2, GPIO_RED_LED_PIN_2)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getRedLedStat_3(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_RED_LED_PORT_3, GPIO_RED_LED_PIN_3)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getRedLedStat_4(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_RED_LED_PORT_4, GPIO_RED_LED_PIN_4)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getRedLedStat_5(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_RED_LED_PORT_5, GPIO_RED_LED_PIN_5)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getRedLedStat_6(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_RED_LED_PORT_6, GPIO_RED_LED_PIN_6)){
    return 0;
  }
  else{
    return 1;
  }
}


uint8_t hal_gpio_getButtonStat_1(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_BUTTON_PORT_1, GPIO_BUTTON_PIN_1)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getButtonStat_2(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_BUTTON_PORT_2, GPIO_BUTTON_PIN_2)){
    return 0;
  }
  else{
    return 1;
  }
}uint8_t hal_gpio_getButtonStat_3(void){
	  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_BUTTON_PORT_3, GPIO_BUTTON_PIN_3)){
	    return 0;
	  }
	  else{
	    return 1;
	  }
	}
uint8_t hal_gpio_getButtonStat_4(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_BUTTON_PORT_4, GPIO_BUTTON_PIN_4)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getButtonStat_5(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_BUTTON_PORT_5, GPIO_BUTTON_PIN_5)){
    return 0;
  }
  else{
    return 1;
  }
}
uint8_t hal_gpio_getButtonStat_6(void){
  if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIO_BUTTON_PORT_6, GPIO_BUTTON_PIN_6)){
    return 0;
  }
  else{
    return 1;
  }
}
#endif
/***********************************************pannel_6keys*********************************************/
