/********************************************************************************

//构	建:    	GCE
//修	改:     GCE
 ****************************************************************************** */
#ifndef __GCE_UART_DRIVER_H
#define __GCE_UART_DRIVER_H
//********************************************
#include "GCE_General.h"

typedef struct
{
    UI08 Len;     // 发送长度
    UI08 *pTxBuf; // 发送指针
} TS_UART_TYPE;

/*************************************************
全局宏
************************************************/
/*************************************************
全局变量
************************************************/
extern GCE_XDATA UUI08 Uart0_Flag; /*串口0标志*/
#define uart0_RX_Err Uart0_Flag.bit_.b0
#define Uart0_Rxd_Ok Uart0_Flag.bit_.b1

extern GCE_XDATA UUI08 Uart1_Flag; /*串口1标志*/
#define uart1_RX_Err Uart1_Flag.bit_.b0
#define Uart1_Rxd_Ok Uart1_Flag.bit_.b1

extern GCE_XDATA TS_UART_TYPE GCE_Uart0;
extern GCE_XDATA TS_UART_TYPE GCE_Uart1;
/*************************************************
函数
************************************************/
void Uart0_rxd_delay(UI08 _uart0rxdata);

extern void Uart0Send_IT(UI08 *_pbuf, UI08 _len);
extern void UART0_RX_IT(UI08 _uart0rxdata);
extern void Deal_Uart0(void);

extern void Uart1Send_IT(UI08 *_pbuf, UI08 _len);
extern void UART1_RX_IT(UI08 uart1rxdata);
extern void Deal_Uart1(void);

#endif ///__GCE_UART_DRIVER_H
//////////////////////////////////////////////////////////
//
//      eeeeeeeeee       n           nn      ddddddddd
//     ee               nnn         nn      dd       dd
//    ee               nn   n      nn      dd        dd
//   eeeeeeeeee       nn     n    nn      dd         dd
//  ee               nn       n  nn      dd         dd
// ee               nn         nnn      dd         dd
// eeeeeeeeee       nn          nn      ddddddddddd
// Designed by ZHOUZHIWEI 2021.6.2
///////////////////////////////////////////////////////
