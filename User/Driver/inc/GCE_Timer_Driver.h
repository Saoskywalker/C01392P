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
#ifndef __GCE_TIMER_DRIVER_H
#define __GCE_TIMER_DRIVER_H

#if (GCE_TIMER0_IT_EN)

extern void GCE_Timer0_IT(void);
void GCE_Timer0_Enable(void);
void GCE_Timer0_Disable(void);

#endif // GCE_TIMER0_IT_EN
#endif /* __GCE_TIMER0_DRIVER_H */

/******************* (C) COPYRIGHT 2021 GCE *****END OF FILE****/
