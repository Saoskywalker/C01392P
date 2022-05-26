/*********************************************************
*作  者:	sinomicon
*版  本:	V1.00
*备  注:    
**********************************************************/
#ifndef __UART1_H__
#define __UART1_H__

#include "user.h"

void UART1_BRR_WR(uint brr);
void UART1_TX_DAT(uchar tx_data);
uint UART1_BRR_RD(void);
uchar UART1_RX8_DAT(void);
uchar UART1_RX9_DAT(void);

#endif
