/**
  ******************************************************************************
  * @file DEBUG_TEST.h
  *
  ******************************************************************************
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GCE_DEBUG_H
#define __GCE_DEBUG_H

// ѡ���Ƿ�򿪵���ģʽ
//#define GCE_DEBUG GCE_ENABLE
#define GCE_DEBUG GCE_DISABLE

//ѡ���Ƿ�򿪵��Զ˿�
//1 ָ���˿ڲ�ȷ���������ȷ��ƽ
#define _TEST_PORT          DEBUG_IO_XOR

// 2ѡ����Ե�
//���²��Ե����Ʋ��ɸ���
#define _TEST_1MS           //_TEST_PORT;
#define _TEST_1S            //_TEST_PORT;
#define _TEST_MAINLOOP      //_TEST_PORT;
#define _TEST_POWERUP_DELAY   //_TEST_PORT;
#define _TEST_INIT_TIME      //_TEST_PORT;
#define _TEST_ENTER_SLEEP         //_TEST_PORT;
#define _TEST_EXIT_SLEEP          //_TEST_PORT;

#define _TEST_TIMER0_IT          _TEST_PORT;
#define _TEST_TIMER1_IT          //_TEST_PORT;
#define _TEST_TIMER2_IT          //_TEST_PORT;
#define _TEST_TIMER3_IT          //_TEST_PORT;

#define _TEST_UART0_RX0_IT          //_TEST_PORT;
#define _TEST_UART0_TX0_IT          //_TEST_PORT;
#define _TEST_UART1_RX1_IT          //_TEST_PORT;
#define _TEST_UART1_TX1_IT          //_TEST_PORT;
#define _TEST_UART2_RX1_IT          //_TEST_PORT;
#define _TEST_UART2_TX1_IT          //_TEST_PORT;
#define _TEST_UART3_RX1_IT          //_TEST_PORT;
#define _TEST_UART3_TX1_IT          //_TEST_PORT;

#define _TEST_INT0_IT          //_TEST_PORT;
#define _TEST_INT1_IT          //_TEST_PORT;

#define _TEST_PWM0_IT          //_TEST_PORT;
#define _TEST_PWM1_IT          //_TEST_PORT;
//���²��Ե����ƿ�




#endif /* __GCE_DEBUG_H */

