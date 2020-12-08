/**
 * @file    lds_hal_adc.h
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
#ifndef __adc_H
#define __adc_H
#ifdef __cplusplus
 extern "C" {
#endif
/*---------------------------------------------------------------------------*/
#include "lds_config.h"


#ifdef LDS_HAL_ADC_ENABLED


extern ADC_HandleTypeDef hadc;


void hal_adc0_init(void);
void MX_ADC_Init(void);
uint16_t hal_adc0_getVal(uint8_t ch);
void channel_switch(uint8_t ch);
void Error_Handler(void);
#endif
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}


#endif
#endif /*__ adc_H */
