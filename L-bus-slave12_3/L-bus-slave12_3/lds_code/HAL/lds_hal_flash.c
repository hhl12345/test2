/*
 * lds_hal_flash.c
 *  Created on: Nov 13, 2020
 *      Author: ganxiaosheng
 *  Version     :v1.0.0
 *  Modification:Create file
 *  @par     Copyright
 *  Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 */
#include "lds_hal_flash.h"
#ifdef LDS_HAL_FLASH_ENABLED

eState_t hal_flash_open(void)
{
	if(HAL_FLASH_Unlock() == HAL_OK)
	{
		return E_HAL_OK;
	}else{
		return E_HAL_ERROR;
	}
}

eState_t hal_flash_close(void)
{
	if(HAL_FLASH_Lock() == HAL_OK)
	{
		return E_HAL_OK;
	}else{
		return E_HAL_ERROR;
	}
}
/*
 * 函数功能：内部flash的读
 * 输入参数：
 *      uiAddr：读的地址
 *      pcDataBuf：为存读的数据缓存地址
 *      clen：读的数据长度
 * */
eState_t hal_flash_read(uint32_t uiAddr, uint8_t *pcDataBuf, uint32_t cLen)
{
	if(uiAddr > FLASH_END_LBUS || uiAddr < FLASH_BASE_LBUS) return E_HAL_ERROR;
    uint32_t i=0;

    while(cLen)
    {
       cLen--;
    	if(pcDataBuf != NULL)
    	{
    		*(pcDataBuf+i) = *(__IO uint8_t*)(uiAddr+i);
    		i = i+1;
    	}else{
    		return E_HAL_ERROR;
    	}
    }

	return E_HAL_OK;
}
/*
 * 函数功能：内部flash的写
 * 输入参数：
 *      uiAddr：写入内部flash的地址
 *      pcDataBuf：写缓存数据的地址
 *      clen：写的数据长度
 * */
eState_t hal_flash_write(uint32_t uiAddr, uint8_t *pcDataBuf, uint32_t cLen)
{
	if(uiAddr > FLASH_END_LBUS || uiAddr < FLASH_BASE_LBUS) return E_HAL_ERROR;
	uint8_t  *p_data = pcDataBuf,i;
	uint32_t uidatabuf=0;
	if(E_HAL_OK == hal_flash_open() )
	{
		while (cLen)
		{
			uidatabuf=0;
			if(cLen >=4){
				uidatabuf = *(pcDataBuf+3);
				uidatabuf = uidatabuf << 8 | *(pcDataBuf+2);
				uidatabuf = uidatabuf << 8 | *(pcDataBuf+1);
				uidatabuf = uidatabuf << 8 | *(pcDataBuf+0);

				if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, uiAddr, uidatabuf) == HAL_OK)
				{
					uiAddr = uiAddr + 4;
					pcDataBuf = pcDataBuf + 4;
					cLen = cLen - 4;
				}
				else
				{
					return E_HAL_ERROR;
				}
			}else{
                while(cLen)
                {
                	uidatabuf = uidatabuf<<8 | (*(pcDataBuf+(cLen-1)));
                	cLen = cLen - 1;
                }

				if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, uiAddr, uidatabuf) != HAL_OK)
				{
					return E_HAL_ERROR;
				}

			}
		}
	}


	if(E_HAL_OK == hal_flash_close() ) return E_HAL_OK;

	return E_HAL_ERROR;

}
/*
 * 函数功能：内部flash的写
 * 输入参数：
 *      uiAddr：擦除flash的地址
 *      cPageNumf：擦除的页数，每页2k

 * */
eState_t hal_flash_erasePage(uint32_t uiAddr, uint8_t cPageNum)
{
	uint32_t NbrOfPage = 0;
	uint32_t SECTORError = 0;

	static FLASH_EraseInitTypeDef EraseInitStruct;
	NbrOfPage = cPageNum;//cLen/FLASH_PAGE_SIZE +1;
	EraseInitStruct.TypeErase     = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.NbPages       = NbrOfPage;
	EraseInitStruct.PageAddress   = uiAddr;

	if( E_HAL_OK == hal_flash_open() )
	{
		if(HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
		{
			return E_HAL_ERROR;
		}
	}
	if(E_HAL_OK == hal_flash_close() ) return E_HAL_OK;

	return E_HAL_ERROR;
}



#ifdef FLASH_TEST
//extern UART_HandleTypeDef huart1;
eState_t flash_test(uint32_t uiAddr)
{
	static uint8_t data[FLASH_APP_PAGE_SIZE];
	uint32_t i=0;
	uint32_t uiFlahAddr;
	uint32_t e_time_s,e_time_e,w_time_s,w_time_e,r_time_s,r_time_e;
	for(i=0;i<FLASH_APP_PAGE_SIZE;i++)
	{
		data[i]=i;
	}

	uiFlahAddr = uiAddr;
	e_time_s = HAL_GetTick();
	if( hal_flash_erasePage(uiFlahAddr,1) != E_HAL_OK){
		lds_debug_printf("hal_flash_erasePage err\n");
	}
	e_time_e = HAL_GetTick();
	uiFlahAddr = uiAddr;
	w_time_s = HAL_GetTick();
	if(hal_flash_write(uiFlahAddr,data,FLASH_APP_PAGE_SIZE) != E_HAL_OK){
		lds_debug_printf("hal_flash_write err\n");

	}
	w_time_e = HAL_GetTick();

	memset(data,0,FLASH_APP_PAGE_SIZE);
	uiFlahAddr = uiAddr;
	r_time_s = HAL_GetTick();
	if(hal_flash_read(uiFlahAddr,data,FLASH_APP_PAGE_SIZE) != E_HAL_OK)
	{
		lds_debug_printf("hal_flash_read err\n");
	}
	r_time_e = HAL_GetTick();
	lds_debug_printf("erasePage=%d ms,flash_write=%d ms,flash_read=%d ms\n",(e_time_e-e_time_s),(w_time_e-w_time_s),(r_time_e-r_time_s));
//	HAL_UART_Transmit(&huart1,data,FLASH_APP_PAGE_SIZE,HAL_MAX_DELAY);
	return E_HAL_OK;
}

#endif

#endif
