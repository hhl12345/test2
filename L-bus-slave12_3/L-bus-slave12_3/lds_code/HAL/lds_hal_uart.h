/*
 * lds_hal_uart.h
 *
 *  Created on: 2020Äê11ÔÂ18ÈÕ
 *      Author: zhangtao2
 */
#ifndef __LDS_HAL_UART_H__
#define __LDS_HAL_UART_H__  

#include <stdint.h>

void hal_uart_init(void);
void hal_uart_send(uint8_t *pcData, uint16_t usSize);
void hal_uart_rec(uint8_t *pcData, uint16_t usSize);

#endif

