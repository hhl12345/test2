/**
 * @file    lds_hal_adc.c
 * @brief   ADC通道0和通道1封装
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
#include "lds_hal_adc.h"

#ifdef LDS_HAL_ADC_ENABLED


ADC_HandleTypeDef hadc;

/**
  * @brief  ADC初始化
  * @param  无
  * @retval 无
  */
void hal_adc0_init(void)
{
	MX_ADC_Init();
}

/**
  * @brief  获取对应通道的ADC值
  * @param  ch：通道（可选ADC_CHANNEL_0或ADC_CHANNEL_1）
  * @retval ADC通道返回值
  */
uint16_t hal_adc0_getVal(uint8_t ch)
{
	if(  (ch>1) || (ch<0) )
	{
		 Error_Handler();
	}
	channel_switch(ch);
	HAL_ADC_Start(&hadc);
	HAL_ADC_PollForConversion(&hadc, 50);
	return (uint16_t)HAL_ADC_GetValue(&hadc);
}


/**
  * @brief  打开对应通道
  * @param  ch：通道（可选ADC_CHANNEL_0或ADC_CHANNEL_1）
  * @retval 无
  */
void channel_switch(uint8_t ch)
{
	ADC_ChannelConfTypeDef sConfig = {0};

	sConfig.Channel = ch;
	sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
	sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;
	if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}
}

/*--------------------------------------------st_init------------------------------------*/
void MX_ADC_Init(void)
{

  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = DISABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }

}


void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspInit 0 */

  /* USER CODE END ADC1_MspInit 0 */
    /* ADC1 clock enable */
    __HAL_RCC_ADC1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**ADC GPIO Configuration
    PA1     ------> ADC_IN1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  }
}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspDeInit 0 */

  /* USER CODE END ADC1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC1_CLK_DISABLE();

    /**ADC GPIO Configuration
    PA1     ------> ADC_IN1
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1);

  }
}
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}
#endif


