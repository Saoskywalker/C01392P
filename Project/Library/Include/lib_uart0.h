/*********************************************************
*作  者:	sinomicon
*版  本:	V1.00
*备  注:    
**********************************************************/
#ifndef __UART0_H__
#define __UART0_H__

#include "user.h"

void  UART0_BRR_WR(uint brr);
void  UART0_TX_DAT(uchar tx_data);
uint  UART0_BRR_RD(void);
uchar UART0_RX8_DAT(void);
uchar UART0_RX9_DAT(void);

#endif
