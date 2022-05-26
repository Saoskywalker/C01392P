#ifndef __SHT30_I2C_H
#define __SHT30_I2C_H

#include "GCE_General.h"

#define  Ack   1
#define  Noack 0



#define  sht30_CONTROL_size   (sizeof(sht30_CONTROL))






void IIC_Delay(UI32 K);

#define delayH    IIC_Delay(6)// 最少放 35  SHT30_IIC 读写必须放长延时
#define delayL    IIC_Delay(3)



typedef struct
{
	UI08 sht30_data_buffer[6];
	UI16 SHT30_temperature;
	UI08 SHT30_humidity;

}sht30_CONTROL;//发送定义
extern GCE_XDATA  sht30_CONTROL  data_process;

extern GCE_XDATA UI08  SHT30_err_Status;


extern void I2C_Dat_Init(void);
extern void SHT30_Init(void);
extern void Sht30_Deal(void);
extern void SHT30_Sleep_Deal(void);
extern void Data_Send_Use_Uart(void);
#endif /* __SHT30_I2C_H */


