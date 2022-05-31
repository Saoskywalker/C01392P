/********************************************************************************
//文件名称:    	__GENERAL_H
//文件描述:    	系统 通用调用文件
//构	建:    	GCE 周智伟		2021/06/3
//修	改:     GCE XXX       	2021/06/3
 ****************************************************************************** */
#ifndef __GCE_GENERAL_H
#define __GCE_GENERAL_H

//********************************************
//	单片机 相关头文件
//********************************************
//------------------在下面添加各个模块的应用子函数头文件----------//
#include "GCE_Data_Type.h" // 系统数据结构

#include "F03.h"    // 使用的MCU SFR文件
#include "common.h" // 使用的MCU通用文件

#include "GCE_MCU_Config.h" // MCU配置宏定义
#include "GCE_Debug.h"      // 测试宏定义

#include "GCE_System_Time.h" //系统时钟集头文件
#include "GCE_MCU_RDF.h"     // SFR重定义文件
#include "GCE_MCU_Init.h"    // MCU初始化外设接口头文件

// #include "GCE_UART_Driver.h"  //UART外设接口头文件
#include "GCE_Timer_Driver.h" //定时器中断外设接口头文件

#include "GCE_EXT_Driver.h" //外中断外设接口头文件
#include "GCE_ADC_Driver.h" //ADC外设接口头文件

#include "ADC_API.h"

#include "IO_API.h"

#include "Motor_API.h"

#include "EXV_driver.h"
#include "EXV_API.h"

#include "Communication_API.h"
#include "Communication_Driver.h"

#include "General_Func.h"

// #include "SHT30_I2C.h"

#define Version 0

#endif ///__GCE_GENERAL_H
//////////////////////////////////////////////////////////
//
//      eeeeeeeeee       n           nn      ddddddddd
//     ee               nnn         nn      dd       dd
//    ee               nn   n      nn      dd        dd
//   eeeeeeeeee       nn     n    nn      dd         dd
//  ee               nn       n  nn      dd         dd
// ee               nn         nnn      dd         dd
// eeeeeeeeee       nn          nn      ddddddddddd
// Designed by Yuanze.Zhang 2010.10.28
///////////////////////////////////////////////////////
