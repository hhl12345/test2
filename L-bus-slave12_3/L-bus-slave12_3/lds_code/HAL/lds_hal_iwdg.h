/**
 * @file    lds_hal_iwdog.h
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
#ifndef __LDS_HAL_IWDG_H
#define __LDS_HAL_IWDG_H

#ifdef __cplusplus
 extern "C" {
#endif
//--------
#include "lds_config.h"

#ifdef LDS_HAL_IWDG_ENABLED

extern IWDG_HandleTypeDef hiwdg;

eState_t hal_watchDog_init(uint16_t counter_reload_value);
void hal_watchDog_feed(void);


#endif


//---------
#ifdef __cplusplus
}
#endif

#endif /* __LDS_HAL_IWDG_H */

