/**
  ******************************************************************************
  * @file GCE_adc.h
  * @brief This file contains all HW registers definitions and memory mapping.
  * @author STMicroelectronics - MCD Application Team
  * @version V1.1.1
  * @date 2021-6-1
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GCE_ADC_driver_H
#define __GCE_ADC_driver_H

#include "GCE_General.h"

#if(GCE_ADC_EN)

extern UI08 ADC_Channel[ADC_USE_CHANNEL_TOTAL];
extern GCE_XDATA UI16 AD_value_lit[2];
extern GCE_XDATA UI08 ADC_channel_ptr;//Õ®µ¿÷∏’Î

extern void ADC_Sample(void);


#endif////GCE_ADC_EN

#endif /* __GCE_ADC_driver_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
