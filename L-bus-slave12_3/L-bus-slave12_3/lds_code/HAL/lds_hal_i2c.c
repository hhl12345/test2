/*
 * lds_hal_i2c.c
 *
 *  Created on: 2020Äê11ÔÂ18ÈÕ
 *      Author: zhangtao2
 */
#include "lds_hal_i2c.h"
#include "stm32f0xx_hal.h"
#include "i2c.h"


void hal_i2c_init(void){
  MX_I2C2_Init();
}

eState_t hal_i2c0_masterWrite(uint8_t cDevAddress, uint8_t cMemAddress, uint8_t *pcData, uint8_t cSize){

  return HAL_I2C_Mem_Write_IT(&hi2c2, cDevAddress, cMemAddress, I2C_MEMADD_SIZE_8BIT, pcData, cSize);
}

eState_t hal_i2c0_masterRead(uint8_t cDevAddress, uint8_t cMemAddress, uint8_t *pcData, uint8_t cSize){

	return HAL_I2C_Mem_Read_IT(&hi2c2, cDevAddress, cMemAddress, I2C_MEMADD_SIZE_8BIT, pcData, cSize);
}


