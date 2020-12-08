/**
 * @file    lds_hal_pwm.h
 * @brief   **定时器3的四个通道输出PWM
 * @author  huanghelou, huanghelou@leedarson.com
 * @version v1.0.0
 * @date    2020-11-018 12:00:00
 * @par     Copyright
 * Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 *
 * @par     History
 * 1.Date        :2020-11-18 12:00:00
 *   Author      :huanghelou
 *   Version     :v1.0.0
 *   Modification:Create file
 */
#ifndef __LDS_HAL_PWM_H
#define __LDS_HAL_PWM_H
#ifdef __cplusplus
 extern "C" {
#endif


/* lds------------------------------------------------------------------*/

#include "lds_config.h"
#ifdef LDS_HAL_IWDG_ENABLED

extern TIM_HandleTypeDef htim3;


void MX_TIM3_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
void hal_pwm0_init(void);
eState_t hal_pwm0_start(uint8_t cCh, uint16_t cNum);
eState_t hal_pwm0_stop(uint8_t cCh);
void Error_Handler(void);
#endif

/* lds------------------------------------------------------------------*/


#ifdef __cplusplus
}
#endif
#endif /*__ lds_hal_pwm_H */


