/*
 * lds_hal_flash.h
 *  Created on: Nov 13, 2020
 *      Author: ganxiaosheng
 *  Version     :v1.0.0
 *  Modification:Create file
 *  @par     Copyright
 *  Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 */
#ifndef __LDS_HAL_FLASH_H
#define __LDS_HAL_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif
//------------
#include "lds_config.h"
#ifdef LDS_HAL_FLASH_ENABLED


//#define FLASH_TEST

eState_t hal_flash_read(uint32_t uiAddr, uint8_t *pcDataBuf, uint32_t cLen);
eState_t hal_flash_write(uint32_t uiAddr, uint8_t *pcDataBuf, uint32_t cLen);
eState_t hal_flash_erasePage(uint32_t uiAddr, uint8_t cPageNum);


#ifdef FLASH_TEST
extern UART_HandleTypeDef huart1;
eState_t flash_test(uint32_t uiAddr);
#endif





 #endif

//------------
#ifdef __cplusplus
}
#endif

#endif /* __LDS_HAL_FLASH_H */

