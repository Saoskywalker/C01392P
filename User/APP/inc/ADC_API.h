/**
 ******************************************************************************
 * @file GCE_adc.h
 * @brief This file contains all HW registers definitions and memory mapping.
 * @author STMicroelectronics - MCD Application Team
 * @version V1.1.1
 * @date 2010-8-19
 ******************************************************************************
 *
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADC_API_H
#define __ADC_API_H

#include "GCE_General.h" //系统 通用调用文件

#define Tcoil_AD_value AD_value_lit[0]
#define Comp_AD_value AD_value_lit[1]
#define Troom_AD_value AD_value_lit[2]
#define Hum_AD_value AD_value_lit[3]

extern ADC_PARA Hum_para, Temp_room_para, Temp_comp_para, Temp_coil_para;
extern UI16 Temp_C_room_digit_value;

extern void ADC_deal(void);
void room_temp_deal(void);
void hum_deal(void);

#endif /* __ADC_API_H */

/**
 * @}
 */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
