/*
 * lds_hal_uart.c
 *
 *  Created on: 2020Äê11ÔÂ18ÈÕ
 *      Author: zhangtao2
 */

#include "lds_hal_uart.h"
#include "usart.h"

void hal_uart_init(void){
  MX_USART1_UART_Init();
  MX_USART4_UART_Init();
}

void hal_uart_send(uint8_t *pcData, uint16_t usSize){
  HAL_UART_Transmit(&huart4, pcData, usSize, 100);
}

void hal_uart_rec(uint8_t *pcData, uint16_t usSize){
  HAL_UART_Receive(&huart4, pcData, usSize, 100);
}


