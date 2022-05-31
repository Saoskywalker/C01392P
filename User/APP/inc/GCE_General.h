/********************************************************************************
//�ļ�����:    	__GENERAL_H
//�ļ�����:    	ϵͳ ͨ�õ����ļ�
//��	��:    	GCE ����ΰ		2021/06/3
//��	��:     GCE XXX       	2021/06/3
 ****************************************************************************** */
#ifndef __GCE_GENERAL_H
#define __GCE_GENERAL_H

//********************************************
//	��Ƭ�� ���ͷ�ļ�
//********************************************
//------------------��������Ӹ���ģ���Ӧ���Ӻ���ͷ�ļ�----------//
#include "GCE_Data_Type.h" // ϵͳ���ݽṹ

#include "F03.h"    // ʹ�õ�MCU SFR�ļ�
#include "common.h" // ʹ�õ�MCUͨ���ļ�

#include "GCE_MCU_Config.h" // MCU���ú궨��
#include "GCE_Debug.h"      // ���Ժ궨��

#include "GCE_System_Time.h" //ϵͳʱ�Ӽ�ͷ�ļ�
#include "GCE_MCU_RDF.h"     // SFR�ض����ļ�
#include "GCE_MCU_Init.h"    // MCU��ʼ������ӿ�ͷ�ļ�

// #include "GCE_UART_Driver.h"  //UART����ӿ�ͷ�ļ�
#include "GCE_Timer_Driver.h" //��ʱ���ж�����ӿ�ͷ�ļ�

#include "GCE_EXT_Driver.h" //���ж�����ӿ�ͷ�ļ�
#include "GCE_ADC_Driver.h" //ADC����ӿ�ͷ�ļ�

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
