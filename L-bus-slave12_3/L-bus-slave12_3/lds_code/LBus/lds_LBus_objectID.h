/*
 * lds_LBus_objectID.h
 *
 *  Created on: Nov 17, 2020
 *      Author: ganxiaosheng
 *  Version     :v1.0.0
 *  Modification:Create file
 *  @par     Copyright
 *  Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 */
typedef enum{
	E_OBJECT_ID_RESET               =    1,
	E_OBJECT_ID_FIRMWARE_VER        =    2,
	E_OBJECT_ID_HARDWARE_VER        =    3,
	E_OBJECT_ID_HAND_AUTO_MODE      =    4,
	E_OBJECT_ID_ON_OFF_MATCH_STATE  =    5,
	E_OBJECT_ID_SEARCH_INTERNET     =    6,
	E_OBJECT_ID_PREINSTALL_CMD      =    7,
	E_OBJECT_ID_DEVICE_MODE         =    8,
	E_OBJECT_ID_MODEID              =    9,
	E_OBJECT_ID_FACTORY_TEST        =   10,

  E_OBJECT_ID_ON_OFF_INPUT            =  101,
	E_OBJECT_ID_ON_OFF_OUTPUT           =  102,
	E_OBJECT_ID_ADC_INPUT               =  103,
	E_OBJECT_ID_DAC_OUTPUT              =  104,
	E_OBJECT_ID_CURTAIN                 =  105,
	E_OBJECT_ID_DIMMER                  =  106,
	E_OBJECT_ID_PRESENCE_SENSOR         =  107,
	E_OBJECT_ID_ILLUMINANCE_SENSOR      =  108,
	E_OBJECT_ID_TEMPERATURE_SENSOR      =  109,
	E_OBJECT_ID_HUMIDITY_SENSOR         =  110,
	E_OBJECT_ID_PM25_SENSOR             =  111,
	E_OBJECT_ID_C2O_SENSOR              =  112,
	E_OBJECT_ID_VOC_SENSOR              =  113,
	E_OBJECT_ID_ELECTRICITY_METER       =  114

}eObject_t;
