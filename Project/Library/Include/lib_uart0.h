/*********************************************************
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ע:    
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
