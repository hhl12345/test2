/**
 * @file    lds_hal_iwdog.c
 * @brief   **独立看门狗封装
 * @author  huanghelou, huanghelou@leedarson.com
 * @version v1.0.0
 * @date    2020-11-05 12:00:00
 * @par     Copyright
 * Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 *
 * @par     History
 * 1.Date        :2020-11-05 12:00:00
 *   Author      :huanghelou
 *   Version     :v1.0.0
 *   Modification:Create file
 */
#include "lds_hal_iwdg.h"
#ifdef LDS_HAL_IWDG_ENABLED


IWDG_HandleTypeDef hiwdg;

/**
  * @brief  **独立看门狗初始化
  * @param  counter_reload_value: 计数值
  * @retval 成功E_HAL_OK，失败E_HAL_ERROR
  *
  ** 独立看门狗超时时间计算(这边看门狗定时器的时钟频率默认为40khz, **定时器为12位递减定时器重装载值最大为2^12-1=4095):
  *  Tout = prv/40k * rlv (ms)--->prv(分频系数)         rlv(counter_reload_value)
  *
  **分频系数(prv)对应的最短和最长可监视时间:
  **分频系数（prv）		min(ms)	max(ms)
  *  4/				0.1		409.6
  *  8/				0.2		819.2
  *  16/			0.4		1638.4
  *  32/			0.8		3276.8
  *  64/			1.6		6553.6
  *  128/			3.2		13107.2
  *  256/			6.4		26214.4
  *
  *
  */
eState_t hal_watchDog_init(uint16_t counter_reload_value)
{
	if(counter_reload_value>4095 || counter_reload_value<0 )
	{
		return E_HAL_ERROR;
	}
	hiwdg.Instance = IWDG;
	hiwdg.Init.Prescaler = IWDG_PRESCALER_64;
	hiwdg.Init.Window = counter_reload_value;
	hiwdg.Init.Reload = counter_reload_value;
	if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
	{
		return E_HAL_ERROR;

	}
	return E_HAL_OK;
}
/**
  * @brief  独立看门狗喂狗
  * @param  无
  * @retval 无
  */
void hal_watchDog_feed(void)
{
	HAL_IWDG_Refresh(&hiwdg);

}

#endif

