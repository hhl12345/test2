/*
 * lds_hal_i2c.h
 *
 *  Created on: 2020年11月18日
 *      Author: zhangtao2
 */
#ifndef __LDS_HAL_GPIO_H__
#define __LDS_HAL_GPIO_H__  

#include <lds_config.h>
#include "stm32f0xx_hal.h"

#define LDS_HAL_I2C_TIMEOUT 100//好像是ms单位，需后期确认

void hal_i2c_init(void);
eState_t hal_i2c0_masterWrite(uint8_t cDevAddress, uint8_t cMemAddress, uint8_t *pcData, uint8_t cSize);
eState_t hal_i2c0_masterRead(uint8_t cDevAddress, uint8_t cMemAddress, uint8_t *pcData, uint8_t cSize);

#endif

