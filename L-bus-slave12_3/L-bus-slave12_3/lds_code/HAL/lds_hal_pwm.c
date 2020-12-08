/**
 * @file    lds_hal_pwm.c
 * @brief   **瀹氭椂鍣�3鐨勫洓涓�氶亾杈撳嚭PWM
 * @author  huanghelou, huanghelou@leedarson.com
 * @version v1.0.0
 * @date    2020-11-18 12:00:00
 * @par     Copyright
 * Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 *
 * @par     History
 * 1.Date        :2020-11-18 12:00:00
 *   Author      :huanghelou
 *   Version     :v1.0.0
 *   Modification:Create file
 */
#include "lds_hal_pwm.h"
#ifdef LDS_HAL_PWM_ENABLED

TIM_HandleTypeDef htim3;

/**
  * @brief  鍒濆鍖栧畾鏃跺櫒3
  * @param  鏃�
  * @retval 鏃�
  */
void hal_pwm0_init(void)
{
	MX_TIM3_Init();

}


/**
  * @brief  鍚姩PWM杈撳嚭
  * @param  cCh:瀹氭椂鍣ㄧ殑鍥涗釜閫氶亾涔嬩竴锛屽彲閫塗IM_CHANNEL_1,TIM_CHANNEL_2,TIM_CHANNEL_3,TIM_CHANNEL_4
  * @param  cNum:鍗犵┖姣� = 锛坈Num/ARR(閲嶈杞藉�兼垨璁℃暟鍊硷紝榛樿1000) 锛�*100%
  *
  * *鍥涗釜閫氶亾鍒濆鍖栧崰绌烘瘮濡備笅:
  * *閫氶亾			cNum	鍗犵┖姣�
  *  TIM_CHANNEL_1  800		80%
  *  TIM_CHANNEL_2	250		25%
  *  TIM_CHANNEL_3	200		20%
  *  TIM_CHANNEL_4	100		10%
  *
  **TIM3 GPIO Configuration
    PB0     ------> TIM3_CH3
    PB1     ------> TIM3_CH4
    PB4     ------> TIM3_CH1
    PB5     ------> TIM3_CH2
  * @retval 鏃�
  */
eState_t hal_pwm0_start(uint8_t cCh, uint16_t cNum)
{
	if(cCh !=TIM_CHANNEL_1 && cCh !=TIM_CHANNEL_2 && cCh !=TIM_CHANNEL_3 && cCh !=TIM_CHANNEL_4 )
	{
		return E_HAL_ERROR;
	}
	if(cNum>1000 || cNum<0)
	{
		return E_HAL_ERROR;
	}
	__HAL_TIM_SET_COMPARE(&htim3,cCh,cNum);
	HAL_TIM_PWM_Start(&htim3,cCh);


	return E_HAL_OK;

}


/**
  * @brief  鍏抽棴PWM杈撳嚭
  * @param  鏃�
  * @retval 鏃�
  */
eState_t hal_pwm0_stop(uint8_t cCh)
{
	if(cCh !=TIM_CHANNEL_1 && cCh !=TIM_CHANNEL_2 && cCh !=TIM_CHANNEL_3 && cCh !=TIM_CHANNEL_4 )
	{
		return E_HAL_ERROR;
	}
	HAL_TIM_PWM_Stop(&htim3,cCh);
	return E_HAL_OK;
}




/**
  * @brief  瀹氭椂鍣�3鍒濆鍖�
  * @param  鏃�
  * @retval 鏃�
  *
  * * 瀹氭椂鍣ㄨ鏃舵椂闂磋绠�: Tout=((ARR+1)*(PSC+1))/Tclk---->>>ARR(閲嶈杞藉�兼垨璁℃暟鍊硷紝榛樿1000)   PSC(棰勫垎棰戝�奸粯璁�4799)     Tclk(鏃堕挓榛樿48Mhz)
  * * 鏈枃妗out=((999+1)*(4799+1))/48M = 0.1s = 100ms
  *
  */
void MX_TIM3_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 4799;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }


  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 800;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.Pulse = 500;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.Pulse = 250;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.Pulse = 100;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim3);

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM3)
  {
    /* TIM3 clock enable */
    __HAL_RCC_TIM3_CLK_ENABLE();

  }
}
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* timHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(timHandle->Instance==TIM3)
  {
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**TIM3 GPIO Configuration
    PB0     ------> TIM3_CH3
    PB1     ------> TIM3_CH4
    PB4     ------> TIM3_CH1
    PB5     ------> TIM3_CH2
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM3;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{
  if(tim_baseHandle->Instance==TIM3)
  {

    __HAL_RCC_TIM3_CLK_DISABLE();

  }
}

#endif
