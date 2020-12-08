/*
 * lds_LBus_attributeID.h
 *
 *  Created on: Nov 17, 2020
 *      Author: ganxiaosheng
 *  Version     :v1.0.0
 *  Modification:Create file
 *  @par     Copyright
 *  Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 */
typedef enum{
	E_ATTRIBUTE_ID_ENABLE                     =    1,  //通道使能
	E_ATTRIBUTE_ID_VALUE                      =    2,  //当前�?
	E_ATTRIBUTE_ID_VALUE_TIME                 =    3,  //当前�?值得持续时间
	E_ATTRIBUTE_ID_COEFFICIENT                =    4,  //值得变化系数
	E_ATTRIBUTE_ID_CURRENT                    =    5,  //当前电流
	E_ATTRIBUTE_ID_CURRENT_COEFFICIENT        =    6,  //当前电流变化系数
	E_ATTRIBUTE_ID_VOLTAGE                    =    7,  //当前电压
	E_ATTRIBUTE_ID_VOLTAGE_COEFFICIENT        =    8,  //当前电压变化系数
	E_ATTRIBUTE_ID_POWER                      =    9,  //当前功率
	E_ATTRIBUTE_ID_POWER_COEFFICIENT          =   10,  //当前功率变化系数
	E_ATTRIBUTE_ID_TOTAL_ENERGY               =   11,  //总电�?
	E_ATTRIBUTE_ID_TOTAL_ENERGY_COEFFICIEN    =   12,  //总电量变化系�?
	E_ATTRIBUTE_ID_SCENE                      =   13,  //场景
	E_ATTRIBUTE_ID_GROUP                      =   14,  //�?
	E_ATTRIBUTE_ID_TRIGGER_MIN                =   15,  //最小触发条�?
	E_ATTRIBUTE_ID_TRIGGER_MAX                =   16,  //最小触发条�?
	E_ATTRIBUTE_ID_SENSOR_SENSITIVITY         =   17,  //传感器灵敏度
	E_ATTRIBUTE_ID_DELAY_TIME                 =   18,  //占空延时时间
	E_ATTRIBUTE_ID_VALUE_CHANGE_TIME          =   19,  //值的渐变时间
	E_ATTRIBUTE_ID_SAMPLING_CYCLE             =   20,  //采样周期
	E_ATTRIBUTE_ID_TIMING_REPORTED            =   21,  //定时上报周期
	E_ATTRIBUTE_ID_OBJECT_MODE                =   22,  //对象模式
}eAttribute_t;

