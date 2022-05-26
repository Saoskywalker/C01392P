/**
  ******************************************************************************
  * @file timer_API.h
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
#ifndef __Dust_Sensor_UART_H
#define __Dust_Sensor_UART_H

#define RXD_TOTAL  10
#define TXD_TOTAL  10

#define Dust_Uart_rxd_ok  Uart0_Rxd_Ok

//灰尘传感器电源与风机15V电源共用
//#define SENSOR_POWER_OFF
//#define SENSOR_POWER_ON


extern GCE_XDATA UI32  Dust_Sensor_Value_sum;//灰尘传感器值sum
extern GCE_XDATA UI08  Dust_rxd_delay;
extern GCE_XDATA UI08  Dust_rxd_bytes;
extern GCE_XDATA UI08  Dust_rxd_buf[];
extern GCE_XDATA UI08  Dust_txd_buf[];
extern GCE_XDATA UI08  Dust_txd_length;
extern GCE_XDATA UI08  Dust_txd_bytes;
extern GCE_XDATA UI16  Dust_Sensor_Value;
extern GCE_XDATA UI08  Dust_Sensor_sample_Cont;


extern void Dust_Sensor_Data_Init(void);
extern void Dust_sensor_Uart(void);
extern  void Dust_Uart_Txd_test(void);

#endif /* __timer_API_H*/
