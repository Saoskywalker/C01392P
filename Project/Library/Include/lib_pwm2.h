/*********************************************************
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ע:    
**********************************************************/

#ifndef __PWM2_H__
#define __PWM2_H__

#include "user.h"

void   PWM2_R0_WR(uint  pwm_r0);  //����PWM20���ռ�ձȼĴ���
void   PWM2_R1_WR(uint  pwm_r1);  //����PWM21���ռ�ձȼĴ���

uint   PWM2_R0_RD(void);  //��ȡPWM_R0ֵ
uint   PWM2_R1_RD(void);  //��ȡPWM_R1ֵ

void   PWM2_DT_WR(uchar  pwm_dt);  //����PWM����ʱ��
uchar  PWM2_DT_RD(void);  //��ȡPWM2_DTֵ��16λ

#endif
