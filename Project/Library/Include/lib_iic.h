/*********************************************************
*作  者:	sinomicon
*版  本:	V1.00
*备  注:    
**********************************************************/
#ifndef __IIC_H__
#define __IIC_H__

#include "user.h"

void  IIC_BRR_WR(uchar brr);
void  IIC_S_ADDR_WR(uchar addr);
void  IIC_DATA_WR(uchar wr_data);
void   IIC_M_ADDR_WR(uchar addr,uchar w_r);
uchar IIC_STA_RD(void);
uchar IIC_DATA_RD(void);
void  IIC_START_TG(void);
void  IIC_STOP_TG(void);

#endif
