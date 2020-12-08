/*
 * lds_LBus_func.h
 *
 *  Created on: Nov 17, 2020
 *      Author: ganxiaosheng
 *  Version     :v1.0.0
 *  Modification:Create file
 *  @par     Copyright
 *  Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 */
#ifndef __LDS_LBUS_FUNC_H
#define __LDS_LBUS_FUNC_H

#ifdef __cplusplus
 extern "C" {
#endif
//------------
#include "lds_config.h"

#define FIREWMARE_UPDATA_TIMEOUT 60000

#if LBUS_DT1_ENABLE == 1

#elif LBUS_DT2_ENABLE ==1

#elif LBUS_DT3_ENABLE ==1

#elif LBus_DT4_ENABLE ==1

#elif LBUS_DT5_ENABLE ==1

#elif LBUS_DT6_ENABLE ==1

#else

#endif

 eState_t LBus_basic_SN_func(uint32_t uiExtID, uint8_t *pcDataBuf, uint8_t ucLen);
 eState_t LBus_basic_firewmareUpdata(uint32_t uiExtID, uint8_t *pcDataBuf, uint8_t ucLen);
 eState_t LBus_basic_CAN_ID_func(uint32_t uiExtID, uint8_t *pcDataBuf, uint8_t ucLen);

//------------
#ifdef __cplusplus
}
#endif

#endif /* __LDS_LBUS_FUNC_H */

