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

extern void ADC_deal(void);

#endif /* __ADC_API_H */

/**
 * @}
 */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
