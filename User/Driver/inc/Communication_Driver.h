#ifndef _COMMUNICATION_DRIVER_H
#define _COMMUNICATION_DRIVER_H

#define     COM_HEAD   20//30
#define     COM_ONE    15//18
#define     COM_ZERO   10//8

#define     rece_data_lenth  5
#define     txd_length      11


extern GCE_XDATA   UI08 communication_width_count;
extern GCE_XDATA   UI08 txd_buf[txd_length];
extern GCE_XDATA   UI08 rxd_buf[rece_data_lenth];
extern GCE_XDATA   UI08 pulse_cnt;

extern GCE_XDATA   UUI08  communication_bit1;
#define  _txd_en        communication_bit1.bit_.b0  //ʹ�ܷ�������
#define  _txd_start     communication_bit1.bit_.b1  //����ͷ��
#define  _txd_end       communication_bit1.bit_.b2  //���ͽ���
#define  _txd_data      communication_bit1.bit_.b3  //��������
#define  _Rxd_start     communication_bit1.bit_.b4  //��ʼ��������
#define  _Rxd_OK        communication_bit1.bit_.b5  //�������
#define  _Rxd_IO_       communication_bit1.bit_.b6  //����IO��״̬����

extern void Communication_Txd_IRQ(void);
extern void Communication_Rxd_IRQ_deal(void);

#endif

//////////////////////////////////////////////////////////
//
//      eeeeeeeeee       n           nn      ddddddddd
//     ee               nnn         nn      dd       dd
//    ee               nn   n      nn      dd        dd
//   eeeeeeeeee       nn     n    nn      dd         dd
//  ee               nn       n  nn      dd         dd
// ee               nn         nnn      dd         dd
//eeeeeeeeee       nn          nn      ddddddddddd
//
//Designed by Benkye.Zhang 2010.10.28
///////////////////////////////////////////////////////







