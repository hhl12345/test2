/*
 * lds_hal_gpio.h
 *
 *  Created on: 2020年11月18日
 *      Author: zhangtao2
 */
#ifndef __LDS_HAL_GPIO_H__
#define __LDS_HAL_GPIO_H__  

#include <lds_config.h>
#include "stm32f072xb.h"
/***********************************************DT1*******************************************************/
#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)



typedef GPIO_TypeDef ldsGpioPort_t;

#define GPIO_PIR_PORT GPIOA
#define GPIO_PIR_PIN GPIO_PIN_1

#define GPIO_RST_BUTTON_PORT GPIOA
#define GPIO_RST_BUTTON_PIN GPIO_PIN_2

#define GPIO_GREEN_LED_PORT GPIOB
#define GPIO_GREEN_LED_PIN GPIO_PIN_5

#define GPIO_RED_LED_PORT GPIOB
#define GPIO_RED_LED_PIN GPIO_PIN_4

typedef enum{
  E_GPIO_PIN_RESET = 0U,
  E_GPIO_PIN_SET
}ePinState_t;


void hal_gpio_init(void);

void hal_gpio_deInit(ldsGpioPort_t* pPort, uint16_t usPin);
void hal_gpio_setPinLevel(ldsGpioPort_t* pPort, uint16_t usPin, ePinState_t eLevel);
ePinState_t hal_gpio_getPinLevel(ldsGpioPort_t* pPort, uint16_t usPin);
void hal_gpio_togPinLevel(ldsGpioPort_t* pPort, uint16_t usPin);

void hal_gpio_redLedOn(void);
void hal_gpio_redLedOff(void);
uint8_t hal_gpio_getRedLedStat(void);
void hal_gpio_greenLedOn(void);
void hal_gpio_greenLedOff(void);
uint8_t hal_gpio_getGreenLedStat(void);

uint8_t hal_gpio_getRstButtonStat(void);
#endif
/***********************************************DT1*******************************************************/

/***********************************************DT4_pannel_6keys*********************************************/
#if (LBUS_DEVICE_TYPE == LBUS_DT4_TYPE)

typedef GPIO_TypeDef ldsGpioPort_t;

#define GPIO_GREEN_LED_PORT_1 GPIOA
#define GPIO_GREEN_LED_PIN_1 GPIO_PIN_15

#define GPIO_GREEN_LED_PORT_2 GPIOB
#define GPIO_GREEN_LED_PIN_2 GPIO_PIN_13

#define GPIO_GREEN_LED_PORT_3 GPIOA
#define GPIO_GREEN_LED_PIN_3 GPIO_PIN_7

#define GPIO_GREEN_LED_PORT_4 GPIOB
#define GPIO_GREEN_LED_PIN_4 GPIO_PIN_4

#define GPIO_GREEN_LED_PORT_5 GPIOA
#define GPIO_GREEN_LED_PIN_5 GPIO_PIN_0

#define GPIO_GREEN_LED_PORT_6 GPIOA
#define GPIO_GREEN_LED_PIN_6 GPIO_PIN_5


#define GPIO_RED_LED_PORT_1 GPIOB
#define GPIO_RED_LED_PIN_1 GPIO_PIN_3

#define GPIO_RED_LED_PORT_2 GPIOB
#define GPIO_RED_LED_PIN_2 GPIO_PIN_14

#define GPIO_RED_LED_PORT_3 GPIOB
#define GPIO_RED_LED_PIN_3 GPIO_PIN_0

#define GPIO_RED_LED_PORT_4 GPIOB
#define GPIO_RED_LED_PIN_4 GPIO_PIN_5

#define GPIO_RED_LED_PORT_5 GPIOA
#define GPIO_RED_LED_PIN_5 GPIO_PIN_1

#define GPIO_RED_LED_PORT_6 GPIOA
#define GPIO_RED_LED_PIN_6 GPIO_PIN_4


///////////按键
#define GPIO_BUTTON_PORT_1 GPIOA
#define GPIO_BUTTON_PIN_1 GPIO_PIN_12

#define GPIO_BUTTON_PORT_2 GPIOB
#define GPIO_BUTTON_PIN_2 GPIO_PIN_12

#define GPIO_BUTTON_PORT_3 GPIOA
#define GPIO_BUTTON_PIN_3 GPIO_PIN_6

#define GPIO_BUTTON_PORT_4 GPIOB
#define GPIO_BUTTON_PIN_4 GPIO_PIN_6

#define GPIO_BUTTON_PORT_5 GPIOA
#define GPIO_BUTTON_PIN_5 GPIO_PIN_2

#define GPIO_BUTTON_PORT_5 GPIOA
#define GPIO_BUTTON_PIN_5 GPIO_PIN_2

#define GPIO_BUTTON_PORT_6 GPIOA
#define GPIO_BUTTON_PIN_6 GPIO_PIN_3


typedef enum{
  E_GPIO_PIN_RESET = 0U,
  E_GPIO_PIN_SET
}ePinState_t;


void hal_gpio_init(void);

void hal_gpio_deInit(ldsGpioPort_t* pPort, uint16_t usPin);
void hal_gpio_setPinLevel(ldsGpioPort_t* pPort, uint16_t usPin, ePinState_t eLevel);
ePinState_t hal_gpio_getPinLevel(ldsGpioPort_t* pPort, uint16_t usPin);
void hal_gpio_togPinLevel(ldsGpioPort_t* pPort, uint16_t usPin);

void hal_gpio_greenLedOn_1();
void hal_gpio_greenLedOn_2();
void hal_gpio_greenLedOn_3();
void hal_gpio_greenLedOn_4();
void hal_gpio_greenLedOn_5();
void hal_gpio_greenLedOn_6();

void hal_gpio_greenLedOff_1();
void hal_gpio_greenLedOff_2();
void hal_gpio_greenLedOff_3();
void hal_gpio_greenLedOff_4();
void hal_gpio_greenLedOff_5();
void hal_gpio_greenLedOff_6();


uint8_t hal_gpio_getGreenLedStat_1(void);
uint8_t hal_gpio_getGreenLedStat_2(void);
uint8_t hal_gpio_getGreenLedStat_3(void);
uint8_t hal_gpio_getGreenLedStat_4(void);
uint8_t hal_gpio_getGreenLedStat_5(void);
uint8_t hal_gpio_getGreenLedStat_6(void);

void hal_gpio_redLedOn_1();
void hal_gpio_redLedOn_2();
void hal_gpio_redLedOn_3();
void hal_gpio_redLedOn_4();
void hal_gpio_redLedOn_5();
void hal_gpio_redLedOn_6();

void hal_gpio_redLedOff_1();
void hal_gpio_redLedOff_2();
void hal_gpio_redLedOff_3();
void hal_gpio_redLedOff_4();
void hal_gpio_redLedOff_5();
void hal_gpio_redLedOff_6();
uint8_t hal_gpio_getRedLedStat_1(void);
uint8_t hal_gpio_getRedLedStat_2(void);
uint8_t hal_gpio_getRedLedStat_3(void);
uint8_t hal_gpio_getRedLedStat_4(void);
uint8_t hal_gpio_getRedLedStat_5(void);
uint8_t hal_gpio_getRedLedStat_6(void);

uint8_t hal_gpio_getButtonStat_1(void);
uint8_t hal_gpio_getButtonStat_2(void);
uint8_t hal_gpio_getButtonStat_3(void);
uint8_t hal_gpio_getButtonStat_4(void);
uint8_t hal_gpio_getButtonStat_5(void);
uint8_t hal_gpio_getButtonStat_6(void);

#endif
/***********************************************DT4_pannel_6keys*********************************************/



#endif

