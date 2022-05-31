/**
  ******************************************************************************
  * @file MCU_init.h
  *
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GCE_RDF_H
#define __GCE_RDF_H

#define GCE_GIE(x)				 GIE = x // ���жϺ궨��
//WDT-------------------------------------
//WDT_OP WDT �����Ĵ���
//д��д��5AH ��WDT ��������0�������WDT �����־
//���� WDT δ�������Ϊ00H��WDT �������Ϊ01H��WDT ������Ѷ���Ϊ03H
#define GCE_CLRWDT()   WDT_OP=0x5A        //�궨���幷ָ��

#define GCE_SOFT_RST            SOFT_RST = 0xA5 // �����λ

#define GCE_SLEEP               PCON = 0x50; PCON = 0x01; PCON = 0xA0 // ����sleepģʽ
#define GCE_IDLE                PCON = 0x50; PCON = 0x02; PCON = 0xA0 // ����idleģʽ
//==========================================================================================
//ADC���岿��END
//==========================================================================================
#define GCE_ADC_TRG                   ADC_C0 |= bit6///��ʼת��
#define GCE_ADC_SET_CH(ch)            ADC_C0 = bit7|ch  ///����ADC����ͨ��//����ͨ��
#define GCE_GET_ADC_VALUE            ((UI16)(ADC_DH << 8) | ADC_DL)// ��ȡADCֵ
//ADC---------------------------------
#define ADC_USE_CHANNEL_TOTAL  4 //ʹ�õ�������ADCͨ������

//#define TOIL_ADC_channel ADC_NUM_AN0        //ͨ��0   δʹ��
//#define ADCNUM_NOTUSE ADC_NUM_AN1        //ͨ��1   δʹ��
//#define TOIL_ADC_channel ADC_NUM_AN2        //ͨ��2   δʹ��
//#define COMP_ADC_channel ADC_NUM_AN3        //ͨ��3   δʹ��
#define Troom_ADC_channel ADC_NUM_AN4       //ͨ��4  ����
#define HUM_ADC_channel ADC_NUM_AN5       //ͨ��5   ����
#define COMP_ADC_channel ADC_NUM_AN6        //ͨ��6   δʹ��
//#define ADCNUM_NOTUSE ADC_NUM_AN7        //ͨ��7   δʹ��
//#define COMP_ADC_channel ADC_NUM_AN8        //1/4VDD  δʹ��
//#define ADCNUM_ROOM_T ADC_NUM_AN9        //ͨ��9   δʹ��
#define TOIL_ADC_channel ADC_NUM_AN10       //ͨ��10  δʹ��
//#define ADCNUM_NOTUSE ADC_NUM_AN11       ////�̶�ѡ���ڲ�1/4VDD ͨ��//δʹ��

#define ADC_USE_CHANNEL_TAB     TOIL_ADC_channel,COMP_ADC_channel,Troom_ADC_channel,HUM_ADC_channel   //�˴������õ���ͨ������ճ������
#define ADC_USE_CHANNEL_FIRST   TOIL_ADC_channel //�״�����ADC����ͨ��
//==========================================================================================
//ADC���岿��START
//�ܹ�12ͨ��12λSAR ADC������1·ͨ����ءVDD ��⣬
//==========================================================================================
//ʹ�õĵ���ADCͨ������
//==========================================================================================
//ʹ�õ�ȫ��ADCͨ��
//==========================================================================================

//==========================================================================================
//ADC���岿��END
//==========================================================================================
//==========================================================================================
//UART���岿��START
//�ܹ�2ͨ��UART
//==========================================================================================
//UART---------------------------------
#define GCE_UART0_TXD  UART0_TXB
#define GCE_UART0_RXD  UART0_RXB


#define GCE_UART1_TXD  UART1_TXB
#define GCE_UART1_RXD  UART1_RXB
//==========================================================================================
//UART���岿��END
//==========================================================================================
//--<< PWMռ�ձ� �궨�� >>------------------------------------------------------
#define USER_PWM00_DUTY(duty)    PWM0_R0H = (UI08)(duty >> 8); PWM0_R0L = (UI08)(duty) // PWM00ͨ��ռ�ձ�
#define USER_PWM01_DUTY(duty)    PWM0_R1H = (UI08)(duty >> 8); PWM0_R1L = (UI08)(duty) // PWM01ͨ��ռ�ձ�

#define USER_PWM10_DUTY(duty)    PWM1_R0H = (UI08)(duty >> 8); PWM1_R0L = (UI08)(duty) // PWM10ͨ��ռ�ձ�
#define USER_PWM11_DUTY(duty)    PWM1_R1H = (UI08)(duty >> 8); PWM1_R1L = (UI08)(duty) // PWM11ͨ��ռ�ձ�

#define USER_PWM20_DUTY(duty)    PWM2_R0H = (UI08)(duty >> 8); PWM2_R0L = (UI08)(duty) // PWM20ͨ��ռ�ձ�
#define USER_PWM21_DUTY(duty)    PWM2_R1H = (UI08)(duty >> 8); PWM2_R1L = (UI08)(duty) // PWM21ͨ��ռ�ձ�



//==========================================================================================
//IO���岿��START
//�ܹ�30��IO
//==========================================================================================
//ʹ�õĵ���IOͨ������
//IO---------------------------------
//����IO����Ϊ���---------------------------------
//#define DEBUG_IO_PORT  P2_3
#define DEBUG_IO_PORT  P2_4
#define DEBUG_IO_XOR  (DEBUG_IO_PORT^=1)
#define DEBUG_IO_H  (DEBUG_IO_PORT=1)
#define DEBUG_IO_L  (DEBUG_IO_PORT=0)


#define  Txd_H             P1_3=1
#define  Txd_L             P1_3=0
#define  Rxd_IO            (P1_4)
//#define  Comm_input_init     P27_OUT_DIS,P27_IN_EN //����ͨ�ſ�Ϊ����
//#define  Comm_output_init    P27_IN_DIS,P27_OUT_EN //����ͨ�ſ�Ϊ���
#define  Comm_input_init      //����ͨ�ſ�Ϊ����
#define  Comm_output_init     //����ͨ�ſ�Ϊ���

////
#define  SCL_output_init     P32_IN_DIS,P32_OUT_EN //����ͨ�ſ�Ϊ����
#define  SDA_output_init     P31_IN_DIS,P31_OUT_EN //����ͨ�ſ�Ϊ���
#define  SDA_input_init      P31_OUT_DIS,P31_IN_EN //����ͨ�ſ�Ϊ���

#define SDA_high    P3_1=1
#define SDA_low     P3_1=0

#define SCL_high    P3_2=1
#define SCL_low     P3_2=0

#define Sda         (P3_1)  //HUM1
#define Scl         (P3_2)  //HUM2 ���� HUM_AD
////

#define HUM1_L P3_1 = 0
#define HUM1_H P3_1 = 1
#define HUM2_L P3_2 = 0
#define HUM2_H P3_2 = 1

#define  WATER_IO      (P0_2)  //ˮ������IO

#define  Filt_IO       (P2_4)      //�������뿪��IO

//#define  AC_110V_IO        (P3_2)
//Motor
#define  Motor_POWER_OFF      P3_7=0
#define  Motor_POWER_ON       P3_7=1

#define  Motor_CW_EN          P2_2=0 //�������ת����
#define  Motor_CCW_EN         P2_2=1
#define  PWM_DUTY_Set(duty)   USER_PWM01_DUTY(duty)
//

#define  COMP_OFF          P0_1=0
#define  COMP_ON           P0_1=1

#define  UVC_OFF           P0_5=0
#define  UVC_ON            P0_5=1


//���°ڶ������������
#define  EXV_UD_A_H      P1_5=1
#define  EXV_UD_A_L      P1_5=0

#define  EXV_UD_B_H      P1_6=1
#define  EXV_UD_B_L      P1_6=0

#define  EXV_UD_C_H      P1_7=1
#define  EXV_UD_C_L      P1_7=0

#define  EXV_UD_D_H      P0_0=1
#define  EXV_UD_D_L      P0_0=0

//���Ұڶ������������
//#define  EXV_LR_A_H      P3_0=1
//#define  EXV_LR_A_L      P3_0=0

//#define  EXV_LR_B_H      P3_1=1
//#define  EXV_LR_B_L      P3_1=0

//#define  EXV_LR_C_H      P1_6=1
//#define  EXV_LR_C_L      P1_6=0

//#define  EXV_LR_D_H      P1_5=1
//#define  EXV_LR_D_L      P1_5=0


#endif /* __GCE_RDF_H */

