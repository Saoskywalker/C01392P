/*********************************************************
*�ļ���:	common.h
*��  ��:	SINOMICON
*��  ��:	V1.00
*��  ��:	2019/10/20
*��  ��:	����ͷ�ļ�
*��  ע:	ͨ���������ͺͺ궨��
**********************************************************/
#ifndef   __COMMON_H__
#define   __COMMON_H__

/* ������������ */
typedef unsigned char  uchar;	//�޷���8λ���ͱ���
typedef unsigned int   uint;	//�޷���16λ���ͱ��� 
typedef unsigned long  ulong;   //�޷���32λ���ͱ���

typedef unsigned char  INT8U;   //�޷���8λ���ͱ���
typedef signed   char  INT8S;   //�з���8λ���ͱ���
typedef unsigned int   INT16U;  //�޷���16λ���ͱ��� 
typedef signed   int   INT16S;  //�з���16λ���ͱ���
typedef unsigned long  INT32U;  //�޷���32λ���ͱ���
typedef signed   long  INT32S;	//�з���32λ���ͱ���
typedef float          FP32;    //�����ȸ����ͱ��� 
typedef double         FP64;    //˫���ȸ����ͱ���

//system
#define  SystemReset    SYS_RST_FLAG = 0x08

//CLK
#define  HRC_EN         CLK_PR=0xA5;  CLK_C1 |= 0x01; CLK_PR=0x5a //ʹ���ڲ���������HRC        
#define  HRC_DIS        CLK_PR=0xA5;  CLK_C1 &= 0xfe; CLK_PR=0x5a //��ֹ�ڲ���������HRC
#define  XOSC_EN        CLK_PR=0xA5;  CLK_C1 |= 0x02; CLK_PR=0x5a //ʹ���ⲿ����XOSC
#define  XOSC_DIS       CLK_PR=0xA5;  CLK_C1 |= 0xfd; CLK_PR=0x5a //��ֹ�ⲿ����XOSC
    
#define  SYSCK_DIV1     CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x00; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//ϵͳʱ��ΪHRC/1  = 16M/1  = 16M
#define  SYSCK_DIV2     CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x01; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//ϵͳʱ��ΪHRC/2  = 16M/2  = 8M
#define  SYSCK_DIV4     CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x02; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//ϵͳʱ��ΪHRC/4  = 16M/4  = 4M
#define  SYSCK_DIV8     CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x03; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//ϵͳʱ��ΪHRC/8  = 16M/8  = 2M
#define  SYSCK_DIV16    CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x04; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//ϵͳʱ��ΪHRC/16 = 16M/16 = 1M
#define  SYSCK_DIV32    CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x05; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//ϵͳʱ��ΪHRC/32 = 16M/32 = 0.5M
#define  SYSCK_DIV64    CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x06; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//ϵͳʱ��ΪHRC/64 = 16M/64 = 0.25M
#define  SYSCK_DIV128   CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x07; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//ϵͳʱ��ΪHRC/128= 16M/128= 0.125M
    
#define  WKUP_T_4US     CLK_PR=0xA5;  WKUP_T = 0x08;  CLK_PR=0x5a //SLEEP ���ѵȴ�ʱ�� 4uS
#define  WKUP_T_8US     CLK_PR=0xA5;  WKUP_T = 0x18;  CLK_PR=0x5a //SLEEP ���ѵȴ�ʱ�� 8uS
#define  WKUP_T_DEF     CLK_PR=0xA5;  WKUP_T = 0xff;  CLK_PR=0x5a //SLEEP ���ѵȴ�ʱ��
 
//iap
#define  EEPROMADDR     0x8200                                  //EEPROM��ʼ��ַ
//wdt
#define  CLR_WDT        WDT_OP = 0x5A                           //������Ź�
#define  WDT_EN         WDT_C  &= 0xdf                          //�������Ź�
#define  WDT_DIS        WDT_C  |= 0x20                          //�رտ��Ź�
//��Ƶ��ΪWDTʱ��
#define  WDT_LRC_2560MS WDT_C  = 0x10                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ2560MS
#define  WDT_LRC_2000MS WDT_C  = 0x11                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ2000MS
#define  WDT_LRC_1500MS WDT_C  = 0x12                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ1500MS
#define  WDT_LRC_1000MS WDT_C  = 0x13                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ1000MS
#define  WDT_LRC_900MS  WDT_C  = 0x14                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ900MS
#define  WDT_LRC_800MS  WDT_C  = 0x15                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ800MS
#define  WDT_LRC_700MS  WDT_C  = 0x16                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ700MS
#define  WDT_LRC_600MS  WDT_C  = 0x17                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ600MS
#define  WDT_LRC_500MS  WDT_C  = 0x18                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ500MS
#define  WDT_LRC_400MS  WDT_C  = 0x19                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ400MS
#define  WDT_LRC_300MS  WDT_C  = 0x1a                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ300MS
#define  WDT_LRC_200MS  WDT_C  = 0x1b                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ200MS
#define  WDT_LRC_100MS  WDT_C  = 0x1c                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ100MS
#define  WDT_LRC_50MS   WDT_C  = 0x1d                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ50MS
#define  WDT_LRC_20MS   WDT_C  = 0x1e                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ20MS
#define  WDT_LRC_10MS   WDT_C  = 0x1f                           //���ÿ��Ź�ʱ��Ϊ��Ƶ16K��WDTʱ��Ϊ10MS

#define  WDT_SYSCLK_8MS    WDT_C  = 0x00
#define  WDT_SYSCLK_4MS    WDT_C  = 0x01
#define  WDT_SYSCLK_2MS    WDT_C  = 0x02
#define  WDT_SYSCLK_1MS    WDT_C  = 0x03
#define  WDT_SYSCLK_512US  WDT_C  = 0x04
//low power
#define  SLEEP_MD     PCON = 0x50;  PCON = 0x01; PCON = 0xA0    //MCU����SLEEPģʽ
#define  IDLE_MD      PCON = 0x50;  PCON = 0x02; PCON = 0xA0    //MCU����IDLEģʽ

//P0_FUN����
#define  P05_FUN_IO        P0_FUN2 &= 0x0F                      //P05�˿���ΪIO����       
#define  P05_FUN_PWM01     P0_FUN2 &= 0x0F; P0_FUN2 |= 0x10     //P05�˿���ΪPWM10����
#define  P05_FUN_PWM11     P0_FUN2 &= 0x0F; P0_FUN2 |= 0x20     //P05�˿���ΪPWM11����
#define  P05_FUN_PWM21     P0_FUN2 &= 0x0F; P0_FUN2 |= 0x30     //P05�˿���ΪPWM21����
#define  P05_FUN_TX0       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x40     //P05�˿���ΪTX0����
#define  P05_FUN_RX0       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x50     //P05�˿���ΪRX0����
#define  P05_FUN_SCL       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x60     //P05�˿���ΪSCL����
#define  P05_FUN_SDA       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x70     //P05�˿���ΪSDA����
#define  P05_FUN_T2G       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x80     //P05�˿���ΪT2G����
#define  P05_FUN_TIN1      P0_FUN2 &= 0x0F; P0_FUN2 |= 0x90     //P05�˿���ΪTIN1����
#define  P05_FUN_TO1       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x90     //P05�˿���ΪTO1����
#define  P05_FUN_CAP2      P0_FUN2 &= 0x0F; P0_FUN2 |= 0xA0     //P05�˿���ΪCAP2����

#define  P04_FUN_IO        P0_FUN2 &= 0xF0                      //P04�˿���ΪIO����          
#define  P04_FUN_PWM00     P0_FUN2 &= 0xF0; P0_FUN2 |= 0x01     //P04�˿���ΪPWM00����
#define  P04_FUN_PWM10     P0_FUN2 &= 0xF0; P0_FUN2 |= 0x02     //P04�˿���ΪPWM10����
#define  P04_FUN_PWM20     P0_FUN2 &= 0xF0; P0_FUN2 |= 0x03     //P04�˿���ΪPWM20����
#define  P04_FUN_TX0       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x04     //P04�˿���ΪTX0����
#define  P04_FUN_RX0       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x05     //P04�˿���ΪRX0����
#define  P04_FUN_SCL       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x06     //P04�˿���ΪSCL����
#define  P04_FUN_SDA       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x07     //P04�˿���ΪSDA����
#define  P04_FUN_T3G       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x08     //P04�˿���ΪT3G����
#define  P04_FUN_TIN0      P0_FUN2 &= 0xF0; P0_FUN2 |= 0x09     //P04�˿���ΪTIN0����
#define  P04_FUN_TO0       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x09     //P04�˿���ΪTO0����
#define  P04_FUN_CAP1A     P0_FUN2 &= 0xF0; P0_FUN2 |= 0x0A     //P04�˿���ΪCAP1A����

#define  P03_FUN_IO        P0_FUN1 &= 0x0F                      //P03�˿���ΪIO����                          
#define  P03_FUN_PWM01     P0_FUN1 &= 0x0F; P0_FUN1 |= 0x10     //P03�˿���ΪPWM10����
#define  P03_FUN_PWM11     P0_FUN1 &= 0x0F; P0_FUN1 |= 0x20     //P03�˿���ΪPWM11����
#define  P03_FUN_PWM21     P0_FUN1 &= 0x0F; P0_FUN1 |= 0x30     //P03�˿���ΪPWM21����
#define  P03_FUN_TX1       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x40     //P03�˿���ΪTX1����
#define  P03_FUN_RX1       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x50     //P03�˿���ΪRX1����
#define  P03_FUN_SCL       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x60     //P03�˿���ΪSCL����
#define  P03_FUN_SDA       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x70     //P03�˿���ΪSDA����
#define  P03_FUN_T0G       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x80     //P03�˿���ΪT0G����
#define  P03_FUN_TIN3      P0_FUN1 &= 0x0F; P0_FUN1 |= 0x90     //P03�˿���ΪTIN3����
#define  P03_FUN_TO3       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x90     //P03�˿���ΪTO3����
#define  P03_FUN_CAP0      P0_FUN1 &= 0x0F; P0_FUN1 |= 0xA0     //P03�˿���ΪCAP0����
#define  P03_FUN_MOSI      P0_FUN1 &= 0x0F; P0_FUN1 |= 0xB0     //P03�˿���ΪMOSI����
#define  P03_FUN_SEG11     P0_FUN1 &= 0x0F; P0_FUN1 |= 0xF0     //P03�˿���ΪSEG11����

#define  P02_FUN_IO        P0_FUN1 &= 0xF0                      //P02�˿���ΪIO����            
#define  P02_FUN_PWM00     P0_FUN1 &= 0xF0; P0_FUN1 |= 0x01     //P02�˿���ΪPWM00����
#define  P02_FUN_PWM10     P0_FUN1 &= 0xF0; P0_FUN1 |= 0x02     //P02�˿���ΪPWM10����
#define  P02_FUN_PWM20     P0_FUN1 &= 0xF0; P0_FUN1 |= 0x03     //P02�˿���ΪPWM20����
#define  P02_FUN_TX1       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x04     //P02�˿���ΪTX1����
#define  P02_FUN_RX1       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x05     //P02�˿���ΪRX1����
#define  P02_FUN_SCL       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x06     //P02�˿���ΪSCL����
#define  P02_FUN_SDA       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x07     //P02�˿���ΪSDA����
#define  P02_FUN_T1G       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x08     //P02�˿���ΪT1G����
#define  P02_FUN_TIN2      P0_FUN1 &= 0xF0; P0_FUN1 |= 0x09     //P02�˿���ΪTIN2����
#define  P02_FUN_TO2       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x09     //P02�˿���ΪTO2����
#define  P02_FUN_CAP2      P0_FUN1 &= 0xF0; P0_FUN1 |= 0x0A     //P02�˿���ΪCAP2����
#define  P02_FUN_MISO      P0_FUN1 &= 0xF0; P0_FUN1 |= 0x0B     //P02�˿���ΪMISO����
#define  P02_FUN_SEG10     P0_FUN1 &= 0xF0; P0_FUN1 |= 0x0F     //P02�˿���ΪSEG10����

#define  P01_FUN_IO        P0_FUN0 &= 0x0F                      //P01�˿���ΪIO����                          
#define  P01_FUN_PWM01     P0_FUN0 &= 0x0F; P0_FUN0 |= 0x10     //P01�˿���ΪPWM10����
#define  P01_FUN_PWM11     P0_FUN0 &= 0x0F; P0_FUN0 |= 0x20     //P01�˿���ΪPWM11����
#define  P01_FUN_PWM21     P0_FUN0 &= 0x0F; P0_FUN0 |= 0x30     //P01�˿���ΪPWM21����
#define  P01_FUN_TX0       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x40     //P01�˿���ΪTX0����
#define  P01_FUN_RX0       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x50     //P01�˿���ΪRX0����
#define  P01_FUN_SCL       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x60     //P01�˿���ΪSCL����
#define  P01_FUN_SDA       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x70     //P01�˿���ΪSDA����
#define  P01_FUN_T2G       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x80     //P01�˿���ΪT2G����
#define  P01_FUN_TIN1      P0_FUN0 &= 0x0F; P0_FUN0 |= 0x90     //P01�˿���ΪTIN1����
#define  P01_FUN_TO1       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x90     //P01�˿���ΪTO1����
#define  P01_FUN_CAP1      P0_FUN0 &= 0x0F; P0_FUN0 |= 0xA0     //P01�˿���ΪCAP1����
#define  P01_FUN_SCK       P0_FUN0 &= 0x0F; P0_FUN0 |= 0xB0     //P01�˿���ΪSCK����
#define  P01_FUN_SEG09     P0_FUN0 &= 0x0F; P0_FUN0 |= 0xF0     //P01�˿���ΪSEG9����

#define  P00_FUN_IO        P0_FUN0 &= 0xF0                      //P00�˿���ΪIO����           
#define  P00_FUN_PWM00     P0_FUN0 &= 0xF0; P0_FUN0 |= 0x01     //P00�˿���ΪPWM00����
#define  P00_FUN_PWM10     P0_FUN0 &= 0xF0; P0_FUN0 |= 0x02     //P00�˿���ΪPWM10����
#define  P00_FUN_PWM20     P0_FUN0 &= 0xF0; P0_FUN0 |= 0x03     //P00�˿���ΪPWM20����
#define  P00_FUN_TX0       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x04     //P00�˿���ΪTX0����
#define  P00_FUN_RX0       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x05     //P00�˿���ΪRX0����
#define  P00_FUN_SCL       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x06     //P00�˿���ΪSCL����
#define  P00_FUN_SDA       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x07     //P00�˿���ΪSDA����
#define  P00_FUN_T3G       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x08     //P00�˿���ΪT3G����
#define  P00_FUN_TIN0      P0_FUN0 &= 0xF0; P0_FUN0 |= 0x09     //P00�˿���ΪTIN0����
#define  P00_FUN_TO0       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x09     //P00�˿���ΪTO0����
#define  P00_FUN_CAP0      P0_FUN0 &= 0xF0; P0_FUN0 |= 0x0A     //P00�˿���ΪCAP0����
#define  P00_FUN_SS        P0_FUN0 &= 0xF0; P0_FUN0 |= 0x0B     //P00�˿���ΪSS����
#define  P00_FUN_SEG8      P0_FUN0 &= 0xF0; P0_FUN0 |= 0x0F     //P00�˿���ΪSEG8����

//P1_FUN����
#define  P10_FUN_IO        P1_FUN0 &= 0xF0                      //P10�˿���ΪIO����           
#define  P10_FUN_PWM00     P1_FUN0 &= 0xF0; P1_FUN0 |= 0x01     //P10�˿���ΪPWM00����
#define  P10_FUN_PWM10     P1_FUN0 &= 0xF0; P1_FUN0 |= 0x02     //P10�˿���ΪPWM10����
#define  P10_FUN_PWM20     P1_FUN0 &= 0xF0; P1_FUN0 |= 0x03     //P10�˿���ΪPWM20����
#define  P10_FUN_TX0       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x04     //P10�˿���ΪTX0����
#define  P10_FUN_RX0       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x05     //P10�˿���ΪRX0����
#define  P10_FUN_SCL       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x06     //P10�˿���ΪSCL����
#define  P10_FUN_SDA       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x07     //P10�˿���ΪSDA����
#define  P10_FUN_T3G       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x08     //P10�˿���ΪT3G����
#define  P10_FUN_TIN2      P1_FUN0 &= 0xF0; P1_FUN0 |= 0x09     //P10�˿���ΪTIN2����
#define  P10_FUN_TO2       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x09     //P10�˿���ΪTO2����
#define  P10_FUN_CAP2      P1_FUN0 &= 0xF0; P1_FUN0 |= 0x0A     //P10�˿���ΪCAP2����
#define  P10_FUN_SS        P1_FUN0 &= 0xF0; P1_FUN0 |= 0x0B     //P10�˿���ΪSS����
#define  P10_FUN_SEG0      P1_FUN0 &= 0xF0; P1_FUN0 |= 0x0F     //P10�˿���ΪSEG0����

#define  P11_FUN_IO        P1_FUN0 &= 0x0F                      //P11�˿���ΪIO����                             
#define  P11_FUN_PWM01     P1_FUN0 &= 0x0F; P1_FUN0 |= 0x10     //P11�˿���ΪPWM10����
#define  P11_FUN_PWM11     P1_FUN0 &= 0x0F; P1_FUN0 |= 0x20     //P11�˿���ΪPWM11����
#define  P11_FUN_PWM21     P1_FUN0 &= 0x0F; P1_FUN0 |= 0x30     //P11�˿���ΪPWM21����
#define  P11_FUN_TX0       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x40     //P11�˿���ΪTX0����
#define  P11_FUN_RX0       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x50     //P11�˿���ΪRX0����
#define  P11_FUN_SCL       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x60     //P11�˿���ΪSCL����
#define  P11_FUN_SDA       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x70     //P11�˿���ΪSDA����
#define  P11_FUN_T2G       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x80     //P11�˿���ΪT2G����
#define  P11_FUN_TIN3      P1_FUN0 &= 0x0F; P1_FUN0 |= 0x90     //P11�˿���ΪTIN3����
#define  P11_FUN_TO3       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x90     //P11�˿���ΪTO3����
#define  P11_FUN_CAP0      P1_FUN0 &= 0x0F; P1_FUN0 |= 0xA0     //P11�˿���ΪCAP0����
#define  P11_FUN_SCK       P1_FUN0 &= 0x0F; P1_FUN0 |= 0xB0     //P11�˿���ΪSCK����
#define  P11_FUN_SEG1      P1_FUN0 &= 0x0F; P1_FUN0 |= 0xF0     //P11�˿���ΪSEG1����

#define  P12_FUN_IO        P1_FUN1 &= 0xF0                      //P12�˿���ΪIO����           
#define  P12_FUN_PWM00     P1_FUN1 &= 0xF0; P1_FUN1 |= 0x01     //P12�˿���ΪPWM00����
#define  P12_FUN_PWM10     P1_FUN1 &= 0xF0; P1_FUN1 |= 0x02     //P12�˿���ΪPWM10����
#define  P12_FUN_PWM20     P1_FUN1 &= 0xF0; P1_FUN1 |= 0x03     //P12�˿���ΪPWM20����
#define  P12_FUN_TX1       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x04     //P12�˿���ΪTX1����
#define  P12_FUN_RX1       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x05     //P12�˿���ΪRX1����
#define  P12_FUN_SCL       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x06     //P12�˿���ΪSCL����
#define  P12_FUN_SDA       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x07     //P12�˿���ΪSDA����
#define  P12_FUN_T1G       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x08     //P12�˿���ΪT1G����
#define  P12_FUN_TIN0      P1_FUN1 &= 0xF0; P1_FUN1 |= 0x09     //P12�˿���ΪTIN0����
#define  P12_FUN_TO0       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x09     //P12�˿���ΪTO0����
#define  P12_FUN_CAP1      P1_FUN1 &= 0xF0; P1_FUN1 |= 0x0A     //P12�˿���ΪCAP1����
#define  P12_FUN_MISO      P1_FUN1 &= 0xF0; P1_FUN1 |= 0x0B     //P12�˿���ΪMISO����
#define  P12_FUN_SEG2      P1_FUN1 &= 0xF0; P1_FUN1 |= 0x0F     //P12�˿���ΪSEG2����

#define  P13_FUN_IO        P1_FUN1 &= 0x0F                      //P13�˿���ΪIO����                     
#define  P13_FUN_PWM01     P1_FUN1 &= 0x0F; P1_FUN1 |= 0x10     //P13�˿���ΪPWM10����
#define  P13_FUN_PWM11     P1_FUN1 &= 0x0F; P1_FUN1 |= 0x20     //P13�˿���ΪPWM11����
#define  P13_FUN_PWM21     P1_FUN1 &= 0x0F; P1_FUN1 |= 0x30     //P13�˿���ΪPWM21����
#define  P13_FUN_TX1       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x40     //P13�˿���ΪTX1����
#define  P13_FUN_RX1       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x50     //P13�˿���ΪRX1����
#define  P13_FUN_SCL       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x60     //P13�˿���ΪSCL����
#define  P13_FUN_SDA       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x70     //P13�˿���ΪSDA����
#define  P13_FUN_T0G       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x80     //P13�˿���ΪT0G����
#define  P13_FUN_TIN1      P1_FUN1 &= 0x0F; P1_FUN1 |= 0x90     //P13�˿���ΪTIN1����
#define  P13_FUN_TO1       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x90     //P13�˿���ΪTO1����
#define  P13_FUN_CAP2      P1_FUN1 &= 0x0F; P1_FUN1 |= 0xA0     //P13�˿���ΪCAP2����
#define  P13_FUN_MOSI      P1_FUN1 &= 0x0F; P1_FUN1 |= 0xB0     //P13�˿���ΪMOSI����
#define  P13_FUN_SEG3      P1_FUN1 &= 0x0F; P1_FUN1 |= 0xF0     //P13�˿���ΪSEG3����

#define  P14_FUN_IO        P1_FUN2 &= 0xF0                      //P14�˿���ΪIO����   
#define  P14_FUN_PWM00     P1_FUN2 &= 0xF0; P1_FUN2 |= 0x01     //P14�˿���ΪPWM00����
#define  P14_FUN_PWM10     P1_FUN2 &= 0xF0; P1_FUN2 |= 0x02     //P14�˿���ΪPWM10����
#define  P14_FUN_PWM20     P1_FUN2 &= 0xF0; P1_FUN2 |= 0x03     //P14�˿���ΪPWM20����
#define  P14_FUN_TX0       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x04     //P14�˿���ΪTX0����
#define  P14_FUN_RX0       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x05     //P14�˿���ΪRX0����
#define  P14_FUN_SCL       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x06     //P14�˿���ΪSCL����
#define  P14_FUN_SDA       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x07     //P14�˿���ΪSDA����
#define  P14_FUN_T3G       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x08     //P14�˿���ΪT3G����
#define  P14_FUN_TIN2      P1_FUN2 &= 0xF0; P1_FUN2 |= 0x09     //P14�˿���ΪTIN2����
#define  P14_FUN_TO2       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x09     //P14�˿���ΪTO2����
#define  P14_FUN_CAP0      P1_FUN2 &= 0xF0; P1_FUN2 |= 0x0A     //P14�˿���ΪCAP0����
#define  P14_FUN_SEG4      P1_FUN2 &= 0xF0; P1_FUN2 |= 0x0F     //P14�˿���ΪSEG4����

#define  P15_FUN_IO        P1_FUN2 &= 0x0F                      //P15�˿���ΪIO����                    
#define  P15_FUN_PWM01     P1_FUN2 &= 0x0F; P1_FUN2 |= 0x10     //P15�˿���ΪPWM10����
#define  P15_FUN_PWM11     P1_FUN2 &= 0x0F; P1_FUN2 |= 0x20     //P15�˿���ΪPWM11����
#define  P15_FUN_PWM21     P1_FUN2 &= 0x0F; P1_FUN2 |= 0x30     //P15�˿���ΪPWM21����
#define  P15_FUN_TX0       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x40     //P15�˿���ΪTX0����
#define  P15_FUN_RX0       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x50     //P15�˿���ΪRX0����
#define  P15_FUN_SCL       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x60     //P15�˿���ΪSCL����
#define  P15_FUN_SDA       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x70     //P15�˿���ΪSDA����
#define  P15_FUN_T2G       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x80     //P15�˿���ΪT2G����
#define  P15_FUN_TIN3      P1_FUN2 &= 0x0F; P1_FUN2 |= 0x90     //P15�˿���ΪTIN3����
#define  P15_FUN_TO3       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x90     //P15�˿���ΪTO3����
#define  P15_FUN_CAP1      P1_FUN2 &= 0x0F; P1_FUN2 |= 0xA0     //P15�˿���ΪCAP1����
#define  P15_FUN_SEG5      P1_FUN2 &= 0x0F; P1_FUN2 |= 0xF0     //P15�˿���ΪSEG5����

#define  P16_FUN_IO        P1_FUN3 &= 0xF0                      //P16�˿���ΪIO����                   
#define  P16_FUN_PWM00     P1_FUN3 &= 0xF0; P1_FUN3 |= 0x01     //P16�˿���ΪPWM00����
#define  P16_FUN_PWM10     P1_FUN3 &= 0xF0; P1_FUN3 |= 0x02     //P16�˿���ΪPWM10����
#define  P16_FUN_PWM20     P1_FUN3 &= 0xF0; P1_FUN3 |= 0x03     //P16�˿���ΪPWM20����
#define  P16_FUN_TX1       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x04     //P16�˿���ΪTX1����
#define  P16_FUN_RX1       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x05     //P16�˿���ΪRX1����
#define  P16_FUN_SCL       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x06     //P16�˿���ΪSCL����
#define  P16_FUN_SDA       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x07     //P16�˿���ΪSDA����
#define  P16_FUN_T1G       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x08     //P16�˿���ΪT1G����
#define  P16_FUN_TIN3      P1_FUN3 &= 0xF0; P1_FUN3 |= 0x09     //P16�˿���ΪTIN3����
#define  P16_FUN_TO3       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x09     //P16�˿���ΪTO3����
#define  P16_FUN_CAP2      P1_FUN3 &= 0xF0; P1_FUN3 |= 0x0A     //P16�˿���ΪCAP2����
#define  P16_FUN_SEG6      P1_FUN3 &= 0xF0; P1_FUN3 |= 0x0F     //P16�˿���ΪSEG6����

#define  P17_FUN_IO        P1_FUN3 &= 0x0F                      //P17�˿���ΪIO����   
#define  P17_FUN_PWM01     P1_FUN3 &= 0x0F; P1_FUN3 |= 0x10     //P17�˿���ΪPWM10����
#define  P17_FUN_PWM11     P1_FUN3 &= 0x0F; P1_FUN3 |= 0x20     //P17�˿���ΪPWM11����
#define  P17_FUN_PWM21     P1_FUN3 &= 0x0F; P1_FUN3 |= 0x30     //P17�˿���ΪPWM21����
#define  P17_FUN_TX1       P1_FUN3 &= 0x0F; P1_FUN3 |= 0x40     //P17�˿���ΪTX1����
#define  P17_FUN_RX1  	   P1_FUN3 &= 0x0F; P1_FUN3 |= 0x50     //P17�˿���ΪRX1����
#define  P17_FUN_SCL       P1_FUN3 &= 0x0F; P1_FUN3 |= 0x60     //P17�˿���ΪSCL����
#define  P17_FUN_SDA       P1_FUN3 &= 0x0F; P1_FUN3 |= 0x70     //P17�˿���ΪSDA����
#define  P17_FUN_T0G       P1_FUN3 &= 0x0F; P1_FUN3 |= 0x80     //P17�˿���ΪT0G����
#define  P17_FUN_TIN2      P1_FUN3 &= 0x0F; P1_FUN3 |= 0x90     //P17�˿���ΪTIN2����
#define  P17_FUN_TO2       P1_FUN3 &= 0x0F; P1_FUN3 |= 0x90     //P17�˿���ΪTO2����
#define  P17_FUN_CAP2      P1_FUN3 &= 0x0F; P1_FUN3 |= 0xA0     //P17�˿���ΪCAP2����
#define  P17_FUN_SEG7      P1_FUN3 &= 0x0F; P1_FUN3 |= 0xF0     //P17�˿���ΪSEG7����

//P2_FUN����
#define  P20_FUN_IO        P2_FUN0 &= 0xF0                      //P23�˿���ΪIO����                            
#define  P20_FUN_PWM00     P2_FUN0 &= 0xF0; P2_FUN0 |= 0x01     //P23�˿���ΪPWM00����
#define  P20_FUN_PWM10     P2_FUN0 &= 0xF0; P2_FUN0 |= 0x02     //P23�˿���ΪPWM10����
#define  P20_FUN_PWM20     P2_FUN0 &= 0xF0; P2_FUN0 |= 0x03     //P23�˿���ΪPWM20����
#define  P20_FUN_TX0       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x04     //P23�˿���ΪTX0����
#define  P20_FUN_RX0       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x05     //P23�˿���ΪRX0����
#define  P20_FUN_SCL       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x06     //P23�˿���ΪSCL����
#define  P20_FUN_SDA       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x07     //P23�˿���ΪSDA����
#define  P20_FUN_T3G       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x08     //P23�˿���ΪT3G����
#define  P20_FUN_TIN0      P2_FUN0 &= 0xF0; P2_FUN0 |= 0x09     //P23�˿���ΪTIN0����
#define  P20_FUN_TO0       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x09     //P23�˿���ΪTO0����
#define  P20_FUN_CAP1      P2_FUN0 &= 0xF0; P2_FUN0 |= 0x0A     //P23�˿���ΪCAP1����
#define  P20_FUN_SS        P2_FUN0 &= 0xF0; P2_FUN0 |= 0x0B     //P23�˿���ΪSS����

#define  P21_FUN_IO        P2_FUN0 &= 0x0F                      //P21�˿���ΪIO����                           
#define  P21_FUN_PWM01     P2_FUN0 &= 0x0F; P2_FUN0 |= 0x10     //P21�˿���ΪPWM10����
#define  P21_FUN_PWM11     P2_FUN0 &= 0x0F; P2_FUN0 |= 0x20     //P21�˿���ΪPWM11����
#define  P21_FUN_PWM21     P2_FUN0 &= 0x0F; P2_FUN0 |= 0x30     //P21�˿���ΪPWM21����
#define  P21_FUN_TX0       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x40     //P21�˿���ΪTX0����
#define  P21_FUN_RX0       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x50     //P21�˿���ΪRX0����
#define  P21_FUN_SCL       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x60     //P21�˿���ΪSCL����
#define  P21_FUN_SDA       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x70     //P21�˿���ΪSDA����
#define  P21_FUN_T2G       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x80     //P21�˿���ΪT2G����
#define  P21_FUN_TIN1      P2_FUN0 &= 0x0F; P2_FUN0 |= 0x90     //P21�˿���ΪTIN1����
#define  P21_FUN_TO1       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x90     //P21�˿���ΪTO1����
#define  P21_FUN_CAP2      P2_FUN0 &= 0x0F; P2_FUN0 |= 0xA0     //P21�˿���ΪCAP2����
#define  P21_FUN_SCK       P2_FUN0 &= 0x0F; P2_FUN0 |= 0xB0     //P21�˿���ΪSCK����

#define  P22_FUN_IO        P2_FUN1 &= 0xF0                      //P22�˿���ΪIO����                            
#define  P22_FUN_PWM00     P2_FUN1 &= 0xF0; P2_FUN1 |= 0x01     //P22�˿���ΪPWM10����
#define  P22_FUN_PWM10     P2_FUN1 &= 0xF0; P2_FUN1 |= 0x02     //P22�˿���ΪPWM11����
#define  P22_FUN_PWM20     P2_FUN1 &= 0xF0; P2_FUN1 |= 0x03     //P22�˿���ΪPWM21����
#define  P22_FUN_TX1       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x04     //P22�˿���ΪTX1����
#define  P22_FUN_RX1       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x05     //P22�˿���ΪRX1����
#define  P22_FUN_SCL       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x06     //P22�˿���ΪSCL����
#define  P22_FUN_SDA       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x07     //P22�˿���ΪSDA����
#define  P22_FUN_T1G       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x08     //P22�˿���ΪT1G����
#define  P22_FUN_TIN2      P2_FUN1 &= 0xF0; P2_FUN1 |= 0x09     //P22�˿���ΪTIN2����
#define  P22_FUN_TO2       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x09     //P22�˿���ΪTO2����
#define  P22_FUN_CAP0      P2_FUN1 &= 0xF0; P2_FUN1 |= 0x0A     //P22�˿���ΪCAP0����
#define  P22_FUN_MISO      P2_FUN1 &= 0xF0; P2_FUN1 |= 0x0B     //P22�˿���ΪMISO����

#define  P23_FUN_IO        P2_FUN1 &= 0x0F                      //P23�˿���ΪIO����           
#define  P23_FUN_PWM01     P2_FUN1 &= 0x0F; P2_FUN1 |= 0x10     //P23�˿���ΪPWM10����
#define  P23_FUN_PWM11     P2_FUN1 &= 0x0F; P2_FUN1 |= 0x20     //P23�˿���ΪPWM11����
#define  P23_FUN_PWM21     P2_FUN1 &= 0x0F; P2_FUN1 |= 0x30     //P23�˿���ΪPWM21����
#define  P23_FUN_TX1       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x40     //P23�˿���ΪTX1����
#define  P23_FUN_RX1       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x50     //P23�˿���ΪRX1����
#define  P23_FUN_SCL       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x60     //P23�˿���ΪSCL����
#define  P23_FUN_SDA       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x70     //P23�˿���ΪSDA����
#define  P23_FUN_T0G       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x80     //P23�˿���ΪT0G����
#define  P23_FUN_TIN3      P2_FUN1 &= 0x0F; P2_FUN1 |= 0x90     //P23�˿���ΪTIN3����
#define  P23_FUN_TO3       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x90     //P23�˿���ΪTO3����
#define  P23_FUN_CAP1      P2_FUN1 &= 0x0F; P2_FUN1 |= 0xA0     //P23�˿���ΪCAP1����
#define  P23_FUN_MOSI      P2_FUN1 &= 0x0F; P2_FUN1 |= 0xB0     //P23�˿���ΪMOSI����

#define  P24_FUN_IO        P2_FUN2 &= 0xF0                      //P24�˿���ΪIO����                            
#define  P24_FUN_PWM00     P2_FUN2 &= 0xF0; P2_FUN2 |= 0x01     //P24�˿���ΪPWM00����
#define  P24_FUN_PWM10     P2_FUN2 &= 0xF0; P2_FUN2 |= 0x02     //P24�˿���ΪPWM10����
#define  P24_FUN_PWM20     P2_FUN2 &= 0xF0; P2_FUN2 |= 0x03     //P24�˿���ΪPWM20����
#define  P24_FUN_TX0       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x04     //P24�˿���ΪTX0����
#define  P24_FUN_RX0       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x05     //P24�˿���ΪRX0����
#define  P24_FUN_SCL       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x06     //P24�˿���ΪSCL����
#define  P24_FUN_SDA       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x07     //P24�˿���ΪSDA����
#define  P24_FUN_T3G       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x08     //P24�˿���ΪT3G����
#define  P24_FUN_TIN0      P2_FUN2 &= 0xF0; P2_FUN2 |= 0x09     //P24�˿���ΪTIN0����
#define  P24_FUN_TO0       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x09     //P24�˿���ΪTO0����
#define  P24_FUN_CAP2      P2_FUN2 &= 0xF0; P2_FUN2 |= 0x0A     //P24�˿���ΪCAP2����

#define  P25_FUN_IO        P2_FUN2 &= 0x0F                      //P25�˿���ΪIO����           
#define  P25_FUN_PWM01     P2_FUN2 &= 0x0F; P2_FUN2 |= 0x10     //P25�˿���ΪPWM10����
#define  P25_FUN_PWM11     P2_FUN2 &= 0x0F; P2_FUN2 |= 0x20     //P25�˿���ΪPWM11����
#define  P25_FUN_PWM21     P2_FUN2 &= 0x0F; P2_FUN2 |= 0x30     //P25�˿���ΪPWM21����
#define  P25_FUN_TX0       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x40     //P25�˿���ΪTX0����
#define  P25_FUN_RX0       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x50     //P25�˿���ΪRX0����
#define  P25_FUN_SCL       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x60     //P25�˿���ΪSCL����
#define  P25_FUN_SDA       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x70     //P25�˿���ΪSDA����
#define  P25_FUN_T2G       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x80     //P25�˿���ΪT2G����
#define  P25_FUN_TIN1      P2_FUN2 &= 0x0F; P2_FUN2 |= 0x90     //P25�˿���ΪTIN1����
#define  P25_FUN_TO1       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x90     //P25�˿���ΪTO1����
#define  P25_FUN_CAP0      P2_FUN2 &= 0x0F; P2_FUN2 |= 0xA0     //P25�˿���ΪCAP0����

#define  P26_FUN_IO        P2_FUN3 &= 0xF0                      //P26�˿���ΪIO����                             
#define  P26_FUN_PWM00     P2_FUN3 &= 0xF0; P2_FUN3 |= 0x01     //P26�˿���ΪPWM00����
#define  P26_FUN_PWM10     P2_FUN3 &= 0xF0; P2_FUN3 |= 0x02     //P26�˿���ΪPWM10����
#define  P26_FUN_PWM20     P2_FUN3 &= 0xF0; P2_FUN3 |= 0x03     //P26�˿���ΪPWM20����
#define  P26_FUN_TX1       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x04     //P26�˿���ΪTX1����
#define  P26_FUN_RX1       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x05     //P26�˿���ΪRX1����
#define  P26_FUN_SCL       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x06     //P26�˿���ΪSCL����
#define  P26_FUN_SDA       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x07     //P26�˿���ΪSDA����
#define  P26_FUN_T1G       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x08     //P26�˿���ΪT1G����
#define  P26_FUN_TIN2      P2_FUN3 &= 0xF0; P2_FUN3 |= 0x09     //P26�˿���ΪTIN2����
#define  P26_FUN_TO2       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x09     //P26�˿���ΪTO2����
#define  P26_FUN_CAP1      P2_FUN3 &= 0xF0; P2_FUN3 |= 0x0A     //P26�˿���ΪCAP1����

#define  P27_FUN_IO        P2_FUN3 &= 0x0F                      //P27�˿���ΪIO����           
#define  P27_FUN_PWM01     P2_FUN3 &= 0x0F; P2_FUN3 |= 0x10     //P27�˿���ΪPWM10����
#define  P27_FUN_PWM11     P2_FUN3 &= 0x0F; P2_FUN3 |= 0x20     //P27�˿���ΪPWM11����
#define  P27_FUN_PWM21     P2_FUN3 &= 0x0F; P2_FUN3 |= 0x30     //P27�˿���ΪPWM21����
#define  P27_FUN_TX1       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x40     //P27�˿���ΪTX1����
#define  P27_FUN_RX1       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x50     //P27�˿���ΪRX1����
#define  P27_FUN_SCL       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x60     //P27�˿���ΪSCL����
#define  P27_FUN_SDA       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x70     //P27�˿���ΪSDA����
#define  P27_FUN_T0G       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x80     //P27�˿���ΪT0G����
#define  P27_FUN_TIN3      P2_FUN3 &= 0x0F; P2_FUN3 |= 0x90     //P27�˿���ΪTIN3����
#define  P27_FUN_TO3       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x90     //P27�˿���ΪTO3����
#define  P27_FUN_CAP2A     P2_FUN3 &= 0x0F; P2_FUN3 |= 0xA0     //P27�˿���ΪCAP2A����

//P3_FUN����
#define  P30_FUN_IO        P3_FUN0 &= 0xF0                      //P33�˿���ΪIO����                            
#define  P30_FUN_PWM00     P3_FUN0 &= 0xF0; P3_FUN0 |= 0x01     //P33�˿���ΪPWM10����
#define  P30_FUN_PWM10     P3_FUN0 &= 0xF0; P3_FUN0 |= 0x02     //P33�˿���ΪPWM11����
#define  P30_FUN_PWM20     P3_FUN0 &= 0xF0; P3_FUN0 |= 0x03     //P33�˿���ΪPWM21����
#define  P30_FUN_TX0       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x04     //P33�˿���ΪTX0����
#define  P30_FUN_RX0       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x05     //P33�˿���ΪRX0����
#define  P30_FUN_SCL       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x06     //P33�˿���ΪSCL����
#define  P30_FUN_SDA       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x07     //P33�˿���ΪSDA����
#define  P30_FUN_T3G       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x08     //P33�˿���ΪT3G����
#define  P30_FUN_TIN0      P3_FUN0 &= 0xF0; P3_FUN0 |= 0x09     //P33�˿���ΪTIN0����
#define  P30_FUN_TO0       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x09     //P33�˿���ΪTO0����
#define  P30_FUN_CAP0      P3_FUN0 &= 0xF0; P3_FUN0 |= 0x0A     //P33�˿���ΪCAP0����
#define  P30_FUN_SS        P3_FUN0 &= 0xF0; P3_FUN0 |= 0x0B     //P33�˿���ΪSS����
#define  P30_FUN_COM0      P3_FUN0 &= 0xF0; P3_FUN0 |= 0x0F     //P33�˿���ΪCOM0����

#define  P31_FUN_IO        P3_FUN0 &= 0x0F                      //P31�˿���ΪIO����                
#define  P31_FUN_PWM01     P3_FUN0 &= 0x0F; P3_FUN0 |= 0x10     //P31�˿���ΪPWM10����
#define  P31_FUN_PWM11     P3_FUN0 &= 0x0F; P3_FUN0 |= 0x20     //P31�˿���ΪPWM11����
#define  P31_FUN_PWM21     P3_FUN0 &= 0x0F; P3_FUN0 |= 0x30     //P31�˿���ΪPWM21����
#define  P31_FUN_TX0       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x40     //P31�˿���ΪTX0����
#define  P31_FUN_RX0       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x50     //P31�˿���ΪRX0����
#define  P31_FUN_SCL       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x60     //P31�˿���ΪSCL����
#define  P31_FUN_SDA       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x70     //P31�˿���ΪSDA����
#define  P31_FUN_T2G       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x80     //P31�˿���ΪT2G����
#define  P31_FUN_TIN1      P3_FUN0 &= 0x0F; P3_FUN0 |= 0x90     //P31�˿���ΪTIN1����
#define  P31_FUN_TO1       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x90     //P31�˿���ΪTO1����
#define  P31_FUN_CAP1      P3_FUN0 &= 0x0F; P3_FUN0 |= 0xA0     //P31�˿���ΪCAP1����
#define  P31_FUN_SCK       P3_FUN0 &= 0x0F; P3_FUN0 |= 0xB0     //P31�˿���ΪSCK����
#define  P31_FUN_COM1      P3_FUN0 &= 0x0F; P3_FUN0 |= 0xF0     //P31�˿���ΪCOM1����

#define  P32_FUN_IO        P3_FUN1 &= 0xF0                      //P32�˿���ΪIO����                             
#define  P32_FUN_PWM00     P3_FUN1 &= 0xF0; P3_FUN1 |= 0x01     //P32�˿���ΪPWM00����
#define  P32_FUN_PWM10     P3_FUN1 &= 0xF0; P3_FUN1 |= 0x02     //P32�˿���ΪPWM10����
#define  P32_FUN_PWM20     P3_FUN1 &= 0xF0; P3_FUN1 |= 0x03     //P32�˿���ΪPWM20����
#define  P32_FUN_TX1       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x04     //P32�˿���ΪTX1����
#define  P32_FUN_RX1       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x05     //P32�˿���ΪRX1����
#define  P32_FUN_SCL       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x06     //P32�˿���ΪSCL����
#define  P32_FUN_SDA       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x07     //P32�˿���ΪSDA����
#define  P32_FUN_T1G       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x08     //P32�˿���ΪT1G����
#define  P32_FUN_TIN2      P3_FUN1 &= 0xF0; P3_FUN1 |= 0x09     //P32�˿���ΪTIN2����
#define  P32_FUN_TO2       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x09     //P32�˿���ΪTO2����
#define  P32_FUN_CAP2      P3_FUN1 &= 0xF0; P3_FUN1 |= 0x0A     //P32�˿���ΪCAP2����
#define  P32_FUN_MISO      P3_FUN1 &= 0xF0; P3_FUN1 |= 0x0B     //P32�˿���ΪMISO����
#define  P32_FUN_COM2      P3_FUN1 &= 0xF0; P3_FUN1 |= 0x0F     //P32�˿���ΪCOM2����

#define  P33_FUN_IO        P3_FUN1 &= 0x0F                      //P33�˿���ΪIO����                                   
#define  P33_FUN_PWM01     P3_FUN1 &= 0x0F; P3_FUN1 |= 0x10     //P33�˿���ΪPWM10����
#define  P33_FUN_PWM11     P3_FUN1 &= 0x0F; P3_FUN1 |= 0x20     //P33�˿���ΪPWM11����
#define  P33_FUN_PWM21     P3_FUN1 &= 0x0F; P3_FUN1 |= 0x30     //P33�˿���ΪPWM21����
#define  P33_FUN_TX1       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x40     //P33�˿���ΪTX1����
#define  P33_FUN_RX1       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x50     //P33�˿���ΪRX1����
#define  P33_FUN_SCL       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x60     //P33�˿���ΪSCL����
#define  P33_FUN_SDA       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x70     //P33�˿���ΪSDA����
#define  P33_FUN_T0G       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x80     //P33�˿���ΪT0G����
#define  P33_FUN_TIN3      P3_FUN1 &= 0x0F; P3_FUN1 |= 0x90     //P33�˿���ΪTIN3����
#define  P33_FUN_TO3       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x90     //P33�˿���ΪTO3����
#define  P33_FUN_CAP0      P3_FUN1 &= 0x0F; P3_FUN1 |= 0xA0     //P33�˿���ΪCAP0����
#define  P33_FUN_MOSI      P3_FUN1 &= 0x0F; P3_FUN1 |= 0xB0     //P33�˿���ΪMOSI����
#define  P33_FUN_COM3      P3_FUN1 &= 0x0F; P3_FUN1 |= 0xF0     //P33�˿���ΪCOM3����

#define  P34_FUN_IO        P3_FUN2 &= 0xF0                      //P34�˿���ΪIO����                                          
#define  P34_FUN_PWM00     P3_FUN2 &= 0xF0; P3_FUN2 |= 0x01     //P34�˿���ΪPWM00����
#define  P34_FUN_PWM10     P3_FUN2 &= 0xF0; P3_FUN2 |= 0x02     //P34�˿���ΪPWM10����
#define  P34_FUN_PWM20     P3_FUN2 &= 0xF0; P3_FUN2 |= 0x03     //P34�˿���ΪPWM20����
#define  P34_FUN_TX0       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x04     //P34�˿���ΪTX0����
#define  P34_FUN_RX0       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x05     //P34�˿���ΪRX0����
#define  P34_FUN_SCL       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x06     //P34�˿���ΪSCL����
#define  P34_FUN_SDA       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x07     //P34�˿���ΪSDA����
#define  P34_FUN_T3G       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x08     //P34�˿���ΪT3G����
#define  P34_FUN_TIN0      P3_FUN2 &= 0xF0; P3_FUN2 |= 0x09     //P34�˿���ΪTIN0����
#define  P34_FUN_TO0       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x09     //P34�˿���ΪTO0����
#define  P34_FUN_CAP1      P3_FUN2 &= 0xF0; P3_FUN2 |= 0x0A     //P34�˿���ΪCAP1����
#define  P34_FUN_COM4      P3_FUN2 &= 0xF0; P3_FUN2 |= 0x0F     //P34�˿���ΪCOM4����

#define  P35_FUN_IO        P3_FUN2 &= 0x0F                      //P35�˿���ΪIO����                 
#define  P35_FUN_PWM01     P3_FUN2 &= 0x0F; P3_FUN2 |= 0x10     //P35�˿���ΪPWM10����
#define  P35_FUN_PWM11     P3_FUN2 &= 0x0F; P3_FUN2 |= 0x20     //P35�˿���ΪPWM11����
#define  P35_FUN_PWM21     P3_FUN2 &= 0x0F; P3_FUN2 |= 0x30     //P35�˿���ΪPWM21����
#define  P35_FUN_TX0       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x40     //P35�˿���ΪTX0����
#define  P35_FUN_RX0       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x50     //P35�˿���ΪRX0����
#define  P35_FUN_SCL       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x60     //P35�˿���ΪSCL����
#define  P35_FUN_SDA       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x70     //P35�˿���ΪSDA����
#define  P35_FUN_T2G       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x80     //P35�˿���ΪT2G����
#define  P35_FUN_TIN1      P3_FUN2 &= 0x0F; P3_FUN2 |= 0x90     //P35�˿���ΪTIN1����
#define  P35_FUN_TO1       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x90     //P35�˿���ΪTO1����
#define  P35_FUN_CAP2      P3_FUN2 &= 0x0F; P3_FUN2 |= 0xA0     //P35�˿���ΪCAP2����
#define  P35_FUN_COM5      P3_FUN2 &= 0x0F; P3_FUN2 |= 0xF0     //P35�˿���ΪCOM5����

#define  P36_FUN_IO        P3_FUN3 &= 0xF0                      //P36�˿���ΪIO����                 
#define  P36_FUN_PWM00     P3_FUN3 &= 0xF0; P3_FUN3 |= 0x01     //P36�˿���ΪPWM00����
#define  P36_FUN_PWM10     P3_FUN3 &= 0xF0; P3_FUN3 |= 0x02     //P36�˿���ΪPWM10����
#define  P36_FUN_PWM20     P3_FUN3 &= 0xF0; P3_FUN3 |= 0x03     //P36�˿���ΪPWM20����
#define  P36_FUN_TX1       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x04     //P36�˿���ΪTX1����
#define  P36_FUN_RX1       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x05     //P36�˿���ΪRX1����
#define  P36_FUN_SCL       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x06     //P36�˿���ΪSCL����
#define  P36_FUN_SDA       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x07     //P36�˿���ΪSDA����
#define  P36_FUN_T1G       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x08     //P36�˿���ΪT1G����
#define  P36_FUN_TIN0      P3_FUN3 &= 0xF0; P3_FUN3 |= 0x09     //P36�˿���ΪTIN0����
#define  P36_FUN_TO0       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x09     //P36�˿���ΪTO0����
#define  P36_FUN_CAP0      P3_FUN3 &= 0xF0; P3_FUN3 |= 0x0A     //P36�˿���ΪCAP0����
#define  P36_FUN_COM6      P3_FUN3 &= 0xF0; P3_FUN3 |= 0x0F     //P36�˿���ΪCOM6����

#define  P37_FUN_IO        P3_FUN3 &= 0x0F                      //P37�˿���ΪIO����                 
#define  P37_FUN_PWM01     P3_FUN3 &= 0x0F; P3_FUN3 |= 0x10     //P37�˿���ΪPWM10����
#define  P37_FUN_PWM11     P3_FUN3 &= 0x0F; P3_FUN3 |= 0x20     //P37�˿���ΪPWM11����
#define  P37_FUN_PWM21     P3_FUN3 &= 0x0F; P3_FUN3 |= 0x30     //P37�˿���ΪPWM21����
#define  P37_FUN_TX1       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x40     //P37�˿���ΪTX1����
#define  P37_FUN_RX1       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x50     //P37�˿���ΪRX1����
#define  P37_FUN_SCL       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x60     //P37�˿���ΪSCL����
#define  P37_FUN_SDA       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x70     //P37�˿���ΪSDA����
#define  P37_FUN_T0G       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x80     //P37�˿���ΪT0G����
#define  P37_FUN_TIN1      P3_FUN3 &= 0x0F; P3_FUN3 |= 0x90     //P37�˿���ΪTIN1����
#define  P37_FUN_TO1       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x90     //P37�˿���ΪTO1����
#define  P37_FUN_CAP1      P3_FUN3 &= 0x0F; P3_FUN3 |= 0xA0     //P37�˿���ΪCAP1����
#define  P37_FUN_COM7      P3_FUN3 &= 0x0F; P3_FUN3 |= 0xF0     //P37�˿���ΪCOM7����

//�������
#define  P00_SET    P0_0 = 1                                    //P00�˿�����ߵ�ƽ
#define  P01_SET    P0_1 = 1                                    //P01�˿�����ߵ�ƽ
#define  P02_SET    P0_2 = 1                                    //P02�˿�����ߵ�ƽ
#define  P03_SET    P0_3 = 1                                    //P03�˿�����ߵ�ƽ
#define  P04_SET    P0_4 = 1                                    //P04�˿�����ߵ�ƽ
#define  P05_SET    P0_5 = 1                                    //P05�˿�����ߵ�ƽ
#define  P0_SET     P0_DAT = 0x3F                               //P0 �˿�����ߵ�ƽ

#define  P10_SET    P1_0 = 1                                    //P10�˿�����ߵ�ƽ
#define  P11_SET    P1_1 = 1                                    //P11�˿�����ߵ�ƽ
#define  P12_SET    P1_2 = 1                                    //P12�˿�����ߵ�ƽ
#define  P13_SET    P1_3 = 1                                    //P13�˿�����ߵ�ƽ
#define  P14_SET    P1_4 = 1                                    //P14�˿�����ߵ�ƽ
#define  P15_SET    P1_5 = 1                                    //P15�˿�����ߵ�ƽ
#define  P16_SET    P1_6 = 1                                    //P16�˿�����ߵ�ƽ
#define  P17_SET    P1_7 = 1                                    //P17�˿�����ߵ�ƽ
#define  P1_SET     P1_DAT = 0xFF                               //P1 �˿�����ߵ�ƽ

#define  P20_SET    P2_0 = 1                                    //P20�˿�����ߵ�ƽ
#define  P21_SET    P2_1 = 1                                    //P21�˿�����ߵ�ƽ
#define  P22_SET    P2_2 = 1                                    //P22�˿�����ߵ�ƽ
#define  P23_SET    P2_3 = 1                                    //P23�˿�����ߵ�ƽ
#define  P24_SET    P2_4 = 1                                    //P24�˿�����ߵ�ƽ
#define  P25_SET    P2_5 = 1                                    //P25�˿�����ߵ�ƽ
#define  P26_SET    P2_6 = 1                                    //P26�˿�����ߵ�ƽ
#define  P27_SET    P2_7 = 1                                    //P27�˿�����ߵ�ƽ
#define  P2_SET     P2_DAT = 0xFF                               //P2 �˿�����ߵ�ƽ

#define  P30_SET    P3_0 = 1                                    //P30�˿�����ߵ�ƽ
#define  P31_SET    P3_1 = 1                                    //P31�˿�����ߵ�ƽ
#define  P32_SET    P3_2 = 1                                    //P32�˿�����ߵ�ƽ
#define  P33_SET    P3_3 = 1                                    //P33�˿�����ߵ�ƽ
#define  P34_SET    P3_4 = 1                                    //P34�˿�����ߵ�ƽ
#define  P35_SET    P3_5 = 1                                    //P35�˿�����ߵ�ƽ
#define  P36_SET    P3_6 = 1                                    //P36�˿�����ߵ�ƽ
#define  P37_SET    P3_7 = 1                                    //P37�˿�����ߵ�ƽ
#define  P3_SET     P3_DAT = 0xFF                               //P3 �˿�����ߵ�ƽ


#define  P00_CLR    P0_0 = 0                                    //P00�˿�����͵�ƽ
#define  P01_CLR    P0_1 = 0                                    //P01�˿�����͵�ƽ
#define  P02_CLR    P0_2 = 0                                    //P02�˿�����͵�ƽ
#define  P03_CLR    P0_3 = 0                                    //P03�˿�����͵�ƽ
#define  P04_CLR    P0_4 = 0                                    //P04�˿�����͵�ƽ
#define  P05_CLR    P0_5 = 0                                    //P05�˿�����͵�ƽ
#define  P0_CLR     P0_DAT = 0x00                               //P0 �˿�����͵�ƽ

#define  P10_CLR    P1_0 = 0                                    //P10�˿�����͵�ƽ
#define  P11_CLR    P1_1 = 0                                    //P11�˿�����͵�ƽ
#define  P12_CLR    P1_2 = 0                                    //P12�˿�����͵�ƽ
#define  P13_CLR    P1_3 = 0                                    //P13�˿�����͵�ƽ
#define  P14_CLR    P1_4 = 0                                    //P14�˿�����͵�ƽ
#define  P15_CLR    P1_5 = 0                                    //P15�˿�����͵�ƽ
#define  P16_CLR    P1_6 = 0                                    //P16�˿�����͵�ƽ
#define  P17_CLR    P1_7 = 0                                    //P17�˿�����͵�ƽ
#define  P1_CLR     P1_DAT = 0x00                               //P1 �˿�����͵�ƽ

#define  P20_CLR    P2_0 = 0                                    //P20�˿�����͵�ƽ
#define  P21_CLR    P2_1 = 0                                    //P21�˿�����͵�ƽ
#define  P22_CLR    P2_2 = 0                                    //P22�˿�����͵�ƽ
#define  P23_CLR    P2_3 = 0                                    //P23�˿�����͵�ƽ
#define  P24_CLR    P2_4 = 0                                    //P24�˿�����͵�ƽ
#define  P25_CLR    P2_5 = 0                                    //P25�˿�����͵�ƽ
#define  P26_CLR    P2_6 = 0                                    //P26�˿�����͵�ƽ
#define  P27_CLR    P2_7 = 0                                    //P27�˿�����͵�ƽ
#define  P2_CLR     P2_DAT = 0x00                               //P2 �˿�����͵�ƽ

#define  P30_CLR    P3_0 = 0                                    //P30�˿�����͵�ƽ
#define  P31_CLR    P3_1 = 0                                    //P31�˿�����͵�ƽ
#define  P32_CLR    P3_2 = 0                                    //P32�˿�����͵�ƽ
#define  P33_CLR    P3_3 = 0                                    //P33�˿�����͵�ƽ
#define  P34_CLR    P3_4 = 0                                    //P34�˿�����͵�ƽ
#define  P35_CLR    P3_5 = 0                                    //P35�˿�����͵�ƽ
#define  P36_CLR    P3_6 = 0                                    //P36�˿�����͵�ƽ
#define  P37_CLR    P3_7 = 0                                    //P37�˿�����͵�ƽ
#define  P3_CLR     P3_DAT = 0x00                               //P3 �˿�����͵�ƽ

#define  P00_REVS    P0_0 ^= 1                                  //P10�˿ڵ�ƽ��ת  
#define  P01_REVS    P0_1 ^= 1                                  //P11�˿ڵ�ƽ��ת  
#define  P02_REVS    P0_2 ^= 1                                  //P12�˿ڵ�ƽ��ת  
#define  P03_REVS    P0_3 ^= 1                                  //P13�˿ڵ�ƽ��ת  
#define  P04_REVS    P0_4 ^= 1                                  //P14�˿ڵ�ƽ��ת  
#define  P05_REVS    P0_5 ^= 1                                  //P15�˿ڵ�ƽ��ת  
#define  P0_REVS     P0_DAT ^= 0x3F                             //P1 �˿ڵ�ƽ��ת  

#define  P10_REVS    P1_0 ^= 1                                  //P10�˿ڵ�ƽ��ת  
#define  P11_REVS    P1_1 ^= 1                                  //P11�˿ڵ�ƽ��ת  
#define  P12_REVS    P1_2 ^= 1                                  //P12�˿ڵ�ƽ��ת  
#define  P13_REVS    P1_3 ^= 1                                  //P13�˿ڵ�ƽ��ת  
#define  P14_REVS    P1_4 ^= 1                                  //P14�˿ڵ�ƽ��ת  
#define  P15_REVS    P1_5 ^= 1                                  //P15�˿ڵ�ƽ��ת  
#define  P16_REVS    P1_6 ^= 1                                  //P16�˿ڵ�ƽ��ת  
#define  P17_REVS    P1_7 ^= 1                                  //P17�˿ڵ�ƽ��ת  
#define  P1_REVS     P1_DAT ^= 0xFF                             //P1 �˿ڵ�ƽ��ת  

#define  P20_REVS    P2_0 ^= 1                                  //P20�˿ڵ�ƽ��ת                    
#define  P21_REVS    P2_1 ^= 1                                  //P21�˿ڵ�ƽ��ת  
#define  P22_REVS    P2_2 ^= 1                                  //P22�˿ڵ�ƽ��ת  
#define  P23_REVS    P2_3 ^= 1                                  //P23�˿ڵ�ƽ��ת  
#define  P24_REVS    P2_4 ^= 1                                  //P24�˿ڵ�ƽ��ת  
#define  P25_REVS    P2_5 ^= 1                                  //P25�˿ڵ�ƽ��ת  
#define  P26_REVS    P2_6 ^= 1                                  //P26�˿ڵ�ƽ��ת  
#define  P27_REVS    P2_7 ^= 1                                  //P27�˿ڵ�ƽ��ת  
#define  P2_REVS     P2_DAT ^= 0xFF                             //P2 �˿ڵ�ƽ��ת  

#define  P30_REVS    P3_0 ^= 1                                  //P30�˿ڵ�ƽ��ת  
#define  P31_REVS    P3_1 ^= 1                                  //P31�˿ڵ�ƽ��ת  
#define  P32_REVS    P3_2 ^= 1                                  //P32�˿ڵ�ƽ��ת  
#define  P33_REVS    P3_3 ^= 1                                  //P33�˿ڵ�ƽ��ת  
#define  P34_REVS    P3_4 ^= 1                                  //P34�˿ڵ�ƽ��ת  
#define  P35_REVS    P3_5 ^= 1                                  //P35�˿ڵ�ƽ��ת  
#define  P36_REVS    P3_6 ^= 1                                  //P36�˿ڵ�ƽ��ת  
#define  P37_REVS    P3_7 ^= 1                                  //P37�˿ڵ�ƽ��ת  
#define  P3_REVS     P3_DAT ^= 0xFF                             //P3 �˿ڵ�ƽ��ת  

//IO�������                                                    
#define  P00_OUT_EN     P0_OE |= 0x01                           //P00�˿�ʹ���������          
#define  P01_OUT_EN     P0_OE |= 0x02                           //P01�˿�ʹ���������      
#define  P02_OUT_EN     P0_OE |= 0x04                           //P02�˿�ʹ���������      
#define  P03_OUT_EN     P0_OE |= 0x08                           //P03�˿�ʹ���������      
#define  P04_OUT_EN     P0_OE |= 0x10                           //P04�˿�ʹ���������      
#define  P05_OUT_EN     P0_OE |= 0x20                           //P05�˿�ʹ���������     
#define  P0_OUT_EN      P0_OE  = 0x3F                           //P0 �˿�ʹ���������       

#define  P00_OUT_DIS    P0_OE &= 0xFE                           //P00�˿ڽ�ֹ�������    
#define  P01_OUT_DIS    P0_OE &= 0xFD                           //P01�˿ڽ�ֹ�������    
#define  P02_OUT_DIS    P0_OE &= 0xFB                           //P02�˿ڽ�ֹ�������    
#define  P03_OUT_DIS    P0_OE &= 0xF7                           //P03�˿ڽ�ֹ�������    
#define  P04_OUT_DIS    P0_OE &= 0xEF                           //P04�˿ڽ�ֹ�������    
#define  P05_OUT_DIS    P0_OE &= 0xDF                           //P05�˿ڽ�ֹ�������    
#define  P0_OUT_DIS     P0_OE  = 0x00                           //P0 �˿ڽ�ֹ�������    

#define  P10_OUT_EN     P1_OE |= 0x01                           //P10�˿�ʹ���������      
#define  P11_OUT_EN     P1_OE |= 0x02                           //P11�˿�ʹ���������    
#define  P12_OUT_EN     P1_OE |= 0x04                           //P12�˿�ʹ���������    
#define  P13_OUT_EN     P1_OE |= 0x08                           //P13�˿�ʹ���������    
#define  P14_OUT_EN     P1_OE |= 0x10                           //P14�˿�ʹ���������    
#define  P15_OUT_EN     P1_OE |= 0x20                           //P15�˿�ʹ���������   
#define  P16_OUT_EN     P1_OE |= 0x40                           //P16�˿�ʹ���������     
#define  P17_OUT_EN     P1_OE |= 0x80                           //P17�˿�ʹ���������     
#define  P1_OUT_EN      P1_OE  = 0xFF                           //P1 �˿�ʹ���������    

#define  P10_OUT_DIS    P1_OE &= 0xFE                           //P10�˿ڽ�ֹ�������  
#define  P11_OUT_DIS    P1_OE &= 0xFD                           //P11�˿ڽ�ֹ�������  
#define  P12_OUT_DIS    P1_OE &= 0xFB                           //P12�˿ڽ�ֹ�������  
#define  P13_OUT_DIS    P1_OE &= 0xF7                           //P13�˿ڽ�ֹ�������  
#define  P14_OUT_DIS    P1_OE &= 0xEF                           //P14�˿ڽ�ֹ�������  
#define  P15_OUT_DIS    P1_OE &= 0xDF                           //P15�˿ڽ�ֹ�������  
#define  P16_OUT_DIS    P1_OE &= 0xBF                           //P16�˿ڽ�ֹ�������  
#define  P17_OUT_DIS    P1_OE &= 0x7F                           //P17�˿ڽ�ֹ�������  
#define  P1_OUT_DIS     P1_OE  = 0x00                           //P1 �˿ڽ�ֹ�������  

#define  P20_OUT_EN     P2_OE |= 0x01                           //P10�˿�ʹ���������      
#define  P21_OUT_EN     P2_OE |= 0x02                           //P11�˿�ʹ���������    
#define  P22_OUT_EN     P2_OE |= 0x04                           //P12�˿�ʹ���������    
#define  P23_OUT_EN     P2_OE |= 0x08                           //P13�˿�ʹ���������    
#define  P24_OUT_EN     P2_OE |= 0x10                           //P14�˿�ʹ���������    
#define  P25_OUT_EN     P2_OE |= 0x20                           //P15�˿�ʹ���������   
#define  P26_OUT_EN     P2_OE |= 0x40                           //P16�˿�ʹ���������     
#define  P27_OUT_EN     P2_OE |= 0x80                           //P17�˿�ʹ���������     
#define  P2_OUT_EN      P2_OE  = 0xFF                           //P1 �˿�ʹ���������    

#define  P20_OUT_DIS    P2_OE &= 0xFE                           //P10�˿ڽ�ֹ�������  
#define  P21_OUT_DIS    P2_OE &= 0xFD                           //P11�˿ڽ�ֹ�������  
#define  P22_OUT_DIS    P2_OE &= 0xFB                           //P12�˿ڽ�ֹ�������  
#define  P23_OUT_DIS    P2_OE &= 0xF7                           //P13�˿ڽ�ֹ�������  
#define  P24_OUT_DIS    P2_OE &= 0xEF                           //P14�˿ڽ�ֹ�������  
#define  P25_OUT_DIS    P2_OE &= 0xDF                           //P15�˿ڽ�ֹ�������  
#define  P26_OUT_DIS    P2_OE &= 0xBF                           //P16�˿ڽ�ֹ�������  
#define  P27_OUT_DIS    P2_OE &= 0x7F                           //P17�˿ڽ�ֹ�������  
#define  P2_OUT_DIS     P2_OE  = 0x00                           //P1 �˿ڽ�ֹ�������  

#define  P30_OUT_EN     P3_OE |= 0x01                           //P10�˿�ʹ���������      
#define  P31_OUT_EN     P3_OE |= 0x02                           //P11�˿�ʹ���������    
#define  P32_OUT_EN     P3_OE |= 0x04                           //P12�˿�ʹ���������    
#define  P33_OUT_EN     P3_OE |= 0x08                           //P13�˿�ʹ���������    
#define  P34_OUT_EN     P3_OE |= 0x10                           //P14�˿�ʹ���������    
#define  P35_OUT_EN     P3_OE |= 0x20                           //P15�˿�ʹ���������   
#define  P36_OUT_EN     P3_OE |= 0x40                           //P16�˿�ʹ���������     
#define  P37_OUT_EN     P3_OE |= 0x80                           //P17�˿�ʹ���������     
#define  P3_OUT_EN      P3_OE  = 0xFF                           //P1 �˿�ʹ���������    

#define  P30_OUT_DIS    P3_OE &= 0xFE                           //P10�˿ڽ�ֹ�������  
#define  P31_OUT_DIS    P3_OE &= 0xFD                           //P11�˿ڽ�ֹ�������  
#define  P32_OUT_DIS    P3_OE &= 0xFB                           //P12�˿ڽ�ֹ�������  
#define  P33_OUT_DIS    P3_OE &= 0xF7                           //P13�˿ڽ�ֹ�������  
#define  P34_OUT_DIS    P3_OE &= 0xEF                           //P14�˿ڽ�ֹ�������  
#define  P35_OUT_DIS    P3_OE &= 0xDF                           //P15�˿ڽ�ֹ�������  
#define  P36_OUT_DIS    P3_OE &= 0xBF                           //P16�˿ڽ�ֹ�������  
#define  P37_OUT_DIS    P3_OE &= 0x7F                           //P17�˿ڽ�ֹ�������  
#define  P3_OUT_DIS     P3_OE  = 0x00                           //P1 �˿ڽ�ֹ�������  

//IO��������
#define  P00_IN_EN      P0_IE |= 0x01                           //P00�˿�ʹ�����빦��          
#define  P01_IN_EN      P0_IE |= 0x02                           //P01�˿�ʹ�����빦��      
#define  P02_IN_EN      P0_IE |= 0x04                           //P02�˿�ʹ�����빦��      
#define  P03_IN_EN      P0_IE |= 0x08                           //P03�˿�ʹ�����빦��      
#define  P04_IN_EN      P0_IE |= 0x10                           //P04�˿�ʹ�����빦��      
#define  P05_IN_EN      P0_IE |= 0x20                           //P05�˿�ʹ�����빦��     
#define  P0_IN_EN       P0_IE  = 0x3F                           //P0 �˿�ʹ�����빦��       

#define  P00_IN_DIS     P0_IE &= 0xFE                           //P00�˿ڽ�ֹ���빦��    
#define  P01_IN_DIS     P0_IE &= 0xFD                           //P01�˿ڽ�ֹ���빦��    
#define  P02_IN_DIS     P0_IE &= 0xFB                           //P02�˿ڽ�ֹ���빦��    
#define  P03_IN_DIS     P0_IE &= 0xF7                           //P03�˿ڽ�ֹ���빦��    
#define  P04_IN_DIS     P0_IE &= 0xEF                           //P04�˿ڽ�ֹ���빦��    
#define  P05_IN_DIS     P0_IE &= 0xDF                           //P05�˿ڽ�ֹ���빦��    
#define  P0_IN_DIS      P0_IE  = 0x00                           //P0 �˿ڽ�ֹ���빦��    

#define  P10_IN_EN      P1_IE |= 0x01                           //P10�˿�ʹ�����빦��      
#define  P11_IN_EN      P1_IE |= 0x02                           //P11�˿�ʹ�����빦��    
#define  P12_IN_EN      P1_IE |= 0x04                           //P12�˿�ʹ�����빦��    
#define  P13_IN_EN      P1_IE |= 0x08                           //P13�˿�ʹ�����빦��    
#define  P14_IN_EN      P1_IE |= 0x10                           //P14�˿�ʹ�����빦��    
#define  P15_IN_EN      P1_IE |= 0x20                           //P15�˿�ʹ�����빦��   
#define  P16_IN_EN      P1_IE |= 0x40                           //P16�˿�ʹ�����빦��     
#define  P17_IN_EN      P1_IE |= 0x80                           //P17�˿�ʹ�����빦��     
#define  P1_IN_EN       P1_IE  = 0xFF                           //P1 �˿�ʹ�����빦��    

#define  P10_IN_DIS     P1_IE &= 0xFE                           //P10�˿ڽ�ֹ���빦��  
#define  P11_IN_DIS     P1_IE &= 0xFD                           //P11�˿ڽ�ֹ���빦��  
#define  P12_IN_DIS     P1_IE &= 0xFB                           //P12�˿ڽ�ֹ���빦��  
#define  P13_IN_DIS     P1_IE &= 0xF7                           //P13�˿ڽ�ֹ���빦��  
#define  P14_IN_DIS     P1_IE &= 0xEF                           //P14�˿ڽ�ֹ���빦��  
#define  P15_IN_DIS     P1_IE &= 0xDF                           //P15�˿ڽ�ֹ���빦��  
#define  P16_IN_DIS     P1_IE &= 0xBF                           //P16�˿ڽ�ֹ���빦��  
#define  P17_IN_DIS     P1_IE &= 0x7F                           //P17�˿ڽ�ֹ���빦��  
#define  P1_IN_DIS      P1_IE  = 0x00                           //P1 �˿ڽ�ֹ���빦��  

#define  P20_IN_EN      P2_IE |= 0x01                           //P20�˿�ʹ�����빦��  
#define  P21_IN_EN      P2_IE |= 0x02                           //P21�˿�ʹ�����빦��  
#define  P22_IN_EN      P2_IE |= 0x04                           //P22�˿�ʹ�����빦��  
#define  P23_IN_EN      P2_IE |= 0x08                           //P23�˿�ʹ�����빦��  
#define  P24_IN_EN      P2_IE |= 0x10                           //P24�˿�ʹ�����빦��  
#define  P25_IN_EN      P2_IE |= 0x20                           //P25�˿�ʹ�����빦��  
#define  P26_IN_EN      P2_IE |= 0x40                           //P26�˿�ʹ�����빦��  
#define  P27_IN_EN      P2_IE |= 0x80                           //P27�˿�ʹ�����빦��  
#define  P2_IN_EN       P2_IE  = 0xFF                           //P2 �˿�ʹ�����빦��  

#define  P20_IN_DIS     P2_IE &= 0xFE                           //P20�˿ڽ�ֹ���빦��
#define  P21_IN_DIS     P2_IE &= 0xFD                           //P21�˿ڽ�ֹ���빦��
#define  P22_IN_DIS     P2_IE &= 0xFB                           //P22�˿ڽ�ֹ���빦��
#define  P23_IN_DIS     P2_IE &= 0xF7                           //P23�˿ڽ�ֹ���빦��
#define  P24_IN_DIS     P2_IE &= 0xEF                           //P24�˿ڽ�ֹ���빦��
#define  P25_IN_DIS     P2_IE &= 0xDF                           //P25�˿ڽ�ֹ���빦��
#define  P26_IN_DIS     P2_IE &= 0xBF                           //P26�˿ڽ�ֹ���빦��
#define  P27_IN_DIS     P2_IE &= 0x7F                           //P27�˿ڽ�ֹ���빦��
#define  P2_IN_DIS      P2_IE  = 0x00                           //P2 �˿ڽ�ֹ���빦��

#define  P30_IN_EN      P3_IE |= 0x01                           //P30�˿�ʹ�����빦��  
#define  P31_IN_EN      P3_IE |= 0x02                           //P31�˿�ʹ�����빦��  
#define  P32_IN_EN      P3_IE |= 0x04                           //P32�˿�ʹ�����빦��  
#define  P33_IN_EN      P3_IE |= 0x08                           //P33�˿�ʹ�����빦��  
#define  P34_IN_EN      P3_IE |= 0x10                           //P34�˿�ʹ�����빦��  
#define  P35_IN_EN      P3_IE |= 0x20                           //P35�˿�ʹ�����빦��  
#define  P36_IN_EN      P3_IE |= 0x40                           //P36�˿�ʹ�����빦��  
#define  P37_IN_EN      P3_IE |= 0x80                           //P37�˿�ʹ�����빦��  
#define  P3_IN_EN       P3_IE  = 0xFF                           //P3 �˿�ʹ�����빦��  

#define  P30_IN_DIS     P3_IE &= 0xFE                           //P30�˿ڽ�ֹ���빦��
#define  P31_IN_DIS     P3_IE &= 0xFD                           //P31�˿ڽ�ֹ���빦��
#define  P32_IN_DIS     P3_IE &= 0xFB                           //P32�˿ڽ�ֹ���빦��
#define  P33_IN_DIS     P3_IE &= 0xF7                           //P33�˿ڽ�ֹ���빦��
#define  P34_IN_DIS     P3_IE &= 0xEF                           //P34�˿ڽ�ֹ���빦��
#define  P35_IN_DIS     P3_IE &= 0xDF                           //P35�˿ڽ�ֹ���빦��
#define  P36_IN_DIS     P3_IE &= 0xBF                           //P36�˿ڽ�ֹ���빦��
#define  P37_IN_DIS     P3_IE &= 0x7F                           //P37�˿ڽ�ֹ���빦��
#define  P3_IN_DIS      P3_IE  = 0x00                           //P3 �˿ڽ�ֹ���빦��

//��������
#define  P00_PU_EN     P0_PUE |= 0x01                           //P00�˿�ʹ������������
#define  P01_PU_EN     P0_PUE |= 0x02                           //P01�˿�ʹ������������
#define  P02_PU_EN     P0_PUE |= 0x04                           //P02�˿�ʹ������������
#define  P03_PU_EN     P0_PUE |= 0x08                           //P03�˿�ʹ������������
#define  P04_PU_EN     P0_PUE |= 0x10                           //P04�˿�ʹ������������
#define  P05_PU_EN     P0_PUE |= 0x20                           //P05�˿�ʹ������������
#define  P0_PU_EN      P0_PUE = 0x3f                            //P0 �˿�ʹ������������

#define  P00_PU_DIS    P0_PUE &= 0xfe                           //P00�˿ڽ�ֹ����������
#define  P01_PU_DIS    P0_PUE &= 0xfd                           //P01�˿ڽ�ֹ����������
#define  P02_PU_DIS    P0_PUE &= 0xfb                           //P02�˿ڽ�ֹ����������
#define  P03_PU_DIS    P0_PUE &= 0xf7                           //P03�˿ڽ�ֹ����������
#define  P04_PU_DIS    P0_PUE &= 0xef                           //P04�˿ڽ�ֹ����������
#define  P05_PU_DIS    P0_PUE &= 0xdf                           //P05�˿ڽ�ֹ����������
#define  P0_PU_DIS     P0_PUE = 0x00                            //P0 �˿ڽ�ֹ����������

#define  P10_PU_EN     P1_PUE |= 0x01                           //P10�˿�ʹ������������
#define  P11_PU_EN     P1_PUE |= 0x02                           //P11�˿�ʹ������������
#define  P12_PU_EN     P1_PUE |= 0x04                           //P12�˿�ʹ������������
#define  P13_PU_EN     P1_PUE |= 0x08                           //P13�˿�ʹ������������
#define  P14_PU_EN     P1_PUE |= 0x10                           //P14�˿�ʹ������������
#define  P15_PU_EN     P1_PUE |= 0x20                           //P15�˿�ʹ������������
#define  P16_PU_EN     P1_PUE |= 0x40                           //P16�˿�ʹ������������
#define  P17_PU_EN     P1_PUE |= 0x80                           //P17�˿�ʹ������������
#define  P1_PU_EN      P1_PUE = 0xff                            //P1 �˿�ʹ������������

#define  P10_PU_DIS    P1_PUE &= 0xfe                           //P10�˿ڽ�ֹ����������
#define  P11_PU_DIS    P1_PUE &= 0xfd                           //P11�˿ڽ�ֹ����������
#define  P12_PU_DIS    P1_PUE &= 0xfb                           //P12�˿ڽ�ֹ����������
#define  P13_PU_DIS    P1_PUE &= 0xf7                           //P13�˿ڽ�ֹ����������
#define  P14_PU_DIS    P1_PUE &= 0xef                           //P14�˿ڽ�ֹ����������
#define  P15_PU_DIS    P1_PUE &= 0xdf                           //P15�˿ڽ�ֹ����������
#define  P16_PU_DIS    P1_PUE &= 0xbf                           //P16�˿ڽ�ֹ����������
#define  P17_PU_DIS    P1_PUE &= 0x7f                           //P17�˿ڽ�ֹ����������
#define  P1_PU_DIS     P1_PUE = 0x00                            //P1 �˿ڽ�ֹ����������

#define  P20_PU_EN     P2_PUE |= 0x01                           //P20�˿�ʹ������������
#define  P21_PU_EN     P2_PUE |= 0x02                           //P21�˿�ʹ������������
#define  P22_PU_EN     P2_PUE |= 0x04                           //P22�˿�ʹ������������
#define  P23_PU_EN     P2_PUE |= 0x08                           //P23�˿�ʹ������������
#define  P24_PU_EN     P2_PUE |= 0x10                           //P24�˿�ʹ������������
#define  P25_PU_EN     P2_PUE |= 0x20                           //P25�˿�ʹ������������
#define  P26_PU_EN     P2_PUE |= 0x40                           //P26�˿�ʹ������������
#define  P27_PU_EN     P2_PUE |= 0x80                           //P27�˿�ʹ������������
#define  P2_PU_EN      P2_PUE = 0xff                            //P2 �˿�ʹ������������

#define  P20_PU_DIS    P2_PUE &= 0xfe                           //P20�˿ڽ�ֹ����������
#define  P21_PU_DIS    P2_PUE &= 0xfd                           //P21�˿ڽ�ֹ����������
#define  P22_PU_DIS    P2_PUE &= 0xfb                           //P22�˿ڽ�ֹ����������
#define  P23_PU_DIS    P2_PUE &= 0xf7                           //P23�˿ڽ�ֹ����������
#define  P24_PU_DIS    P2_PUE &= 0xef                           //P24�˿ڽ�ֹ����������
#define  P25_PU_DIS    P2_PUE &= 0xdf                           //P25�˿ڽ�ֹ����������
#define  P26_PU_DIS    P2_PUE &= 0xbf                           //P26�˿ڽ�ֹ����������
#define  P27_PU_DIS    P2_PUE &= 0x7f                           //P27�˿ڽ�ֹ����������
#define  P2_PU_DIS     P2_PUE = 0x00                            //P2 �˿ڽ�ֹ����������
    
#define  P30_PU_EN     P3_PUE |= 0x01                           //P30�˿�ʹ������������
#define  P31_PU_EN     P3_PUE |= 0x02                           //P31�˿�ʹ������������
#define  P32_PU_EN     P3_PUE |= 0x04                           //P32�˿�ʹ������������
#define  P33_PU_EN     P3_PUE |= 0x08                           //P33�˿�ʹ������������
#define  P34_PU_EN     P3_PUE |= 0x10                           //P34�˿�ʹ������������
#define  P35_PU_EN     P3_PUE |= 0x20                           //P35�˿�ʹ������������
#define  P36_PU_EN     P3_PUE |= 0x40                           //P36�˿�ʹ������������
#define  P37_PU_EN     P3_PUE |= 0x80                           //P37�˿�ʹ������������
#define  P3_PU_EN      P3_PUE = 0xff                            //P3 �˿�ʹ������������

#define  P30_PU_DIS    P3_PUE &= 0xfe                           //P30�˿ڽ�ֹ����������
#define  P31_PU_DIS    P3_PUE &= 0xfd                           //P31�˿ڽ�ֹ����������
#define  P32_PU_DIS    P3_PUE &= 0xfb                           //P32�˿ڽ�ֹ����������
#define  P33_PU_DIS    P3_PUE &= 0xf7                           //P33�˿ڽ�ֹ����������
#define  P34_PU_DIS    P3_PUE &= 0xef                           //P34�˿ڽ�ֹ����������
#define  P35_PU_DIS    P3_PUE &= 0xdf                           //P35�˿ڽ�ֹ����������
#define  P36_PU_DIS    P3_PUE &= 0xbf                           //P36�˿ڽ�ֹ����������
#define  P37_PU_DIS    P3_PUE &= 0x7f                           //P37�˿ڽ�ֹ����������
#define  P3_PU_DIS     P3_PUE = 0x00                            //P3 �˿ڽ�ֹ����������

//��������
#define  P00_PD_EN     P0_PDE |= 0x01;                          //P00�˿�ʹ������������
#define  P01_PD_EN     P0_PDE |= 0x02;                          //P01�˿�ʹ������������
#define  P02_PD_EN     P0_PDE |= 0x04;                          //P02�˿�ʹ������������
#define  P03_PD_EN     P0_PDE |= 0x08;                          //P03�˿�ʹ������������
#define  P04_PD_EN     P0_PDE |= 0x10;                          //P04�˿�ʹ������������
#define  P05_PD_EN     P0_PDE |= 0x20;                          //P05�˿�ʹ������������
#define  P0_PD_EN      P0_PDE = 0x3f;                           //P0 �˿�ʹ������������

#define  P00_PD_DIS    P0_PDE &= 0xfe;                          //P00�˿ڽ�ֹ����������
#define  P01_PD_DIS    P0_PDE &= 0xfd;                          //P01�˿ڽ�ֹ����������
#define  P02_PD_DIS    P0_PDE &= 0xfb;                          //P02�˿ڽ�ֹ����������
#define  P03_PD_DIS    P0_PDE &= 0xf7;                          //P03�˿ڽ�ֹ����������
#define  P04_PD_DIS    P0_PDE &= 0xef;                          //P04�˿ڽ�ֹ����������
#define  P05_PD_DIS    P0_PDE &= 0xdf;                          //P05�˿ڽ�ֹ����������
#define  P0_PD_DIS     P0_PDE = 0x00;                           //P0 �˿ڽ�ֹ����������

#define  P10_PD_EN     P1_PDE |= 0x01;                          //P10�˿�ʹ������������
#define  P11_PD_EN     P1_PDE |= 0x02;                          //P11�˿�ʹ������������
#define  P12_PD_EN     P1_PDE |= 0x04;                          //P12�˿�ʹ������������
#define  P13_PD_EN     P1_PDE |= 0x08;                          //P13�˿�ʹ������������
#define  P14_PD_EN     P1_PDE |= 0x10;                          //P14�˿�ʹ������������
#define  P15_PD_EN     P1_PDE |= 0x20;                          //P15�˿�ʹ������������
#define  P16_PD_EN     P1_PDE |= 0x40;                          //P16�˿�ʹ������������
#define  P17_PD_EN     P1_PDE |= 0x80;                          //P17�˿�ʹ������������
#define  P1_PD_EN      P1_PDE = 0xff;                           //P1 �˿�ʹ������������

#define  P10_PD_DIS    P1_PDE &= 0xfe;                          //P10�˿ڽ�ֹ����������
#define  P11_PD_DIS    P1_PDE &= 0xfd;                          //P11�˿ڽ�ֹ����������
#define  P12_PD_DIS    P1_PDE &= 0xfb;                          //P12�˿ڽ�ֹ����������
#define  P13_PD_DIS    P1_PDE &= 0xf7;                          //P13�˿ڽ�ֹ����������
#define  P14_PD_DIS    P1_PDE &= 0xef;                          //P14�˿ڽ�ֹ����������
#define  P15_PD_DIS    P1_PDE &= 0xdf;                          //P15�˿ڽ�ֹ����������
#define  P16_PD_DIS    P1_PDE &= 0xbf;                          //P16�˿ڽ�ֹ����������
#define  P17_PD_DIS    P1_PDE &= 0x7f;                          //P17�˿ڽ�ֹ����������
#define  P1_PD_DIS     P1_PDE &= 0x00;                          //P1 �˿ڽ�ֹ����������

#define  P20_PD_EN     P2_PDE |= 0x01;                          //P20�˿�ʹ������������
#define  P21_PD_EN     P2_PDE |= 0x02;                          //P21�˿�ʹ������������
#define  P22_PD_EN     P2_PDE |= 0x04;                          //P22�˿�ʹ������������
#define  P23_PD_EN     P2_PDE |= 0x08;                          //P23�˿�ʹ������������
#define  P24_PD_EN     P2_PDE |= 0x10;                          //P24�˿�ʹ������������
#define  P25_PD_EN     P2_PDE |= 0x20;                          //P25�˿�ʹ������������
#define  P26_PD_EN     P2_PDE |= 0x40;                          //P26�˿�ʹ������������
#define  P27_PD_EN     P2_PDE |= 0x80;                          //P27�˿�ʹ������������
#define  P2_PD_EN      P2_PDE = 0xff;                           //P2 �˿�ʹ������������

#define  P20_PD_DIS    P2_PDE &= 0xfe;                          //P20�˿ڽ�ֹ����������
#define  P21_PD_DIS    P2_PDE &= 0xfd;                          //P21�˿ڽ�ֹ����������
#define  P22_PD_DIS    P2_PDE &= 0xfb;                          //P22�˿ڽ�ֹ����������
#define  P23_PD_DIS    P2_PDE &= 0xf7;                          //P23�˿ڽ�ֹ����������
#define  P24_PD_DIS    P2_PDE &= 0xef;                          //P24�˿ڽ�ֹ����������
#define  P25_PD_DIS    P2_PDE &= 0xdf;                          //P25�˿ڽ�ֹ����������
#define  P26_PD_DIS    P2_PDE &= 0xbf;                          //P26�˿ڽ�ֹ����������
#define  P27_PD_DIS    P2_PDE &= 0x7f;                          //P27�˿ڽ�ֹ����������
#define  P2_PD_DIS     P2_PDE = 0x00;                           //P2 �˿ڽ�ֹ����������

#define  P30_PD_EN     P3_PDE |= 0x01;                          //P30�˿�ʹ������������                        
#define  P31_PD_EN     P3_PDE |= 0x02;                          //P31�˿�ʹ������������
#define  P32_PD_EN     P3_PDE |= 0x04;                          //P32�˿�ʹ������������
#define  P33_PD_EN     P3_PDE |= 0x08;                          //P33�˿�ʹ������������
#define  P34_PD_EN     P3_PDE |= 0x10;                          //P34�˿�ʹ������������
#define  P35_PD_EN     P3_PDE |= 0x20;                          //P35�˿�ʹ������������
#define  P36_PD_EN     P3_PDE |= 0x40;                          //P36�˿�ʹ������������
#define  P37_PD_EN     P3_PDE |= 0x80;                          //P37�˿�ʹ������������
#define  P3_PD_EN      P3_PDE = 0xff;                           //P3 �˿�ʹ������������

#define  P30_PD_DIS    P3_PDE &= 0xfe;                          //P30�˿ڽ�ֹ����������
#define  P31_PD_DIS    P3_PDE &= 0xfd;                          //P31�˿ڽ�ֹ����������
#define  P32_PD_DIS    P3_PDE &= 0xfb;                          //P32�˿ڽ�ֹ����������
#define  P33_PD_DIS    P3_PDE &= 0xf7;                          //P33�˿ڽ�ֹ����������
#define  P34_PD_DIS    P3_PDE &= 0xef;                          //P34�˿ڽ�ֹ����������
#define  P35_PD_DIS    P3_PDE &= 0xdf;                          //P35�˿ڽ�ֹ����������
#define  P36_PD_DIS    P3_PDE &= 0xbf;                          //P36�˿ڽ�ֹ����������
#define  P37_PD_DIS    P3_PDE &= 0x7f;                          //P37�˿ڽ�ֹ����������
#define  P3_PD_DIS     P3_PDE &= 0x00;                          //P3 �˿ڽ�ֹ����������

//P0��©���ã�Ҫ��©�˿ڵ�ƽ������VDD��ƽ
#define  P00_OD_EN     P0_ODE  |= 0x01                          //P10�˿�ʹ�ܿ�©����
#define  P01_OD_EN     P0_ODE  |= 0x02                          //P11�˿�ʹ�ܿ�©����
#define  P02_OD_EN     P0_ODE  |= 0x04                          //P12�˿�ʹ�ܿ�©����
#define  P03_OD_EN     P0_ODE  |= 0x08                          //P13�˿�ʹ�ܿ�©����
#define  P04_OD_EN     P0_ODE  |= 0x10                          //P14�˿�ʹ�ܿ�©����
#define  P05_OD_EN     P0_ODE  |= 0x20                          //P15�˿�ʹ�ܿ�©����
#define  P0_OD_EN      P0_ODE  = 0x3f                           //P1�˿�ʹ�ܿ�©����

#define  P00_OD_DIS    P0_ODE  &= 0xfe                          //P10�˿ڽ�ֹ��©����
#define  P01_OD_DIS    P0_ODE  &= 0xfd                          //P11�˿ڽ�ֹ��©����
#define  P02_OD_DIS    P0_ODE  &= 0xfb                          //P12�˿ڽ�ֹ��©����
#define  P03_OD_DIS    P0_ODE  &= 0xf7                          //P13�˿ڽ�ֹ��©����
#define  P04_OD_DIS    P0_ODE  &= 0xef                          //P14�˿ڽ�ֹ��©����
#define  P05_OD_DIS    P0_ODE  &= 0xdf                          //P15�˿ڽ�ֹ��©����
#define  P0_OD_DIS     P0_ODE  = 0x00                           //P1�˿ڽ�ֹ��©����

//P1��©���ã�Ҫ��©�˿ڵ�ƽ������VDD��ƽ
#define  P10_OD_EN     P1_ODE  |= 0x01                          //P10�˿�ʹ�ܿ�©����
#define  P11_OD_EN     P1_ODE  |= 0x02                          //P11�˿�ʹ�ܿ�©����
#define  P12_OD_EN     P1_ODE  |= 0x04                          //P12�˿�ʹ�ܿ�©����
#define  P13_OD_EN     P1_ODE  |= 0x08                          //P13�˿�ʹ�ܿ�©����
#define  P14_OD_EN     P1_ODE  |= 0x10                          //P14�˿�ʹ�ܿ�©����
#define  P15_OD_EN     P1_ODE  |= 0x20                          //P15�˿�ʹ�ܿ�©����
#define  P16_OD_EN     P1_ODE  |= 0x40                          //P16�˿�ʹ�ܿ�©����
#define  P17_OD_EN     P1_ODE  |= 0x80                          //P17�˿�ʹ�ܿ�©����
#define  P1_OD_EN      P1_ODE  |= 0xff                          //P1 �˿�ʹ�ܿ�©����

#define  P10_OD_DIS    P1_ODE  &= 0xfe                          //P10�˿ڽ�ֹ��©����
#define  P11_OD_DIS    P1_ODE  &= 0xfd                          //P11�˿ڽ�ֹ��©����
#define  P12_OD_DIS    P1_ODE  &= 0xfb                          //P12�˿ڽ�ֹ��©����
#define  P13_OD_DIS    P1_ODE  &= 0xf7                          //P13�˿ڽ�ֹ��©����
#define  P14_OD_DIS    P1_ODE  &= 0xef                          //P14�˿ڽ�ֹ��©����
#define  P15_OD_DIS    P1_ODE  &= 0xdf                          //P15�˿ڽ�ֹ��©����
#define  P16_OD_DIS    P1_ODE  &= 0xbf                          //P16�˿ڽ�ֹ��©����
#define  P17_OD_DIS    P1_ODE  &= 0x7f                          //P17�˿ڽ�ֹ��©����
#define  P1_OD_DIS     P1_ODE  = 0x00                           //P1 �˿ڽ�ֹ��©����

//P2��©���ã�Ҫ��©�˿ڵ�ƽ������VDD��ƽ
#define  P20_OD_EN     P2_ODE  |= 0x01                          //P20�˿�ʹ�ܿ�©����
#define  P21_OD_EN     P2_ODE  |= 0x02                          //P21�˿�ʹ�ܿ�©����
#define  P22_OD_EN     P2_ODE  |= 0x04                          //P22�˿�ʹ�ܿ�©����
#define  P23_OD_EN     P2_ODE  |= 0x08                          //P23�˿�ʹ�ܿ�©����
#define  P24_OD_EN     P2_ODE  |= 0x10                          //P24�˿�ʹ�ܿ�©����
#define  P25_OD_EN     P2_ODE  |= 0x20                          //P25�˿�ʹ�ܿ�©����
#define  P26_OD_EN     P2_ODE  |= 0x40                          //P26�˿�ʹ�ܿ�©����
#define  P27_OD_EN     P2_ODE  |= 0x80                          //P27�˿�ʹ�ܿ�©����
#define  P2_OD_EN      P2_ODE  = 0xff                           //P2 �˿�ʹ�ܿ�©����

#define  P20_OD_DIS    P2_ODE  &= 0xfe                          //P20�˿ڽ�ֹ��©����
#define  P21_OD_DIS    P2_ODE  &= 0xfd                          //P21�˿ڽ�ֹ��©����
#define  P22_OD_DIS    P2_ODE  &= 0xfb                          //P22�˿ڽ�ֹ��©����
#define  P23_OD_DIS    P2_ODE  &= 0xf7                          //P23�˿ڽ�ֹ��©����
#define  P24_OD_DIS    P2_ODE  &= 0xef                          //P24�˿ڽ�ֹ��©����
#define  P25_OD_DIS    P2_ODE  &= 0xdf                          //P25�˿ڽ�ֹ��©����
#define  P26_OD_DIS    P2_ODE  &= 0xbf                          //P26�˿ڽ�ֹ��©����
#define  P27_OD_DIS    P2_ODE  &= 0x7f                          //P27�˿ڽ�ֹ��©����
#define  P2_OD_DIS     P2_ODE  = 0x00                           //P2 �˿ڽ�ֹ��©����

//P3��©���ã�Ҫ��©�˿ڵ�ƽ������VDD��ƽ
#define  P30_OD_EN     P3_ODE  |= 0x01                          //P30�˿�ʹ�ܿ�©����
#define  P31_OD_EN     P3_ODE  |= 0x02                          //P31�˿�ʹ�ܿ�©����
#define  P32_OD_EN     P3_ODE  |= 0x04                          //P32�˿�ʹ�ܿ�©����
#define  P33_OD_EN     P3_ODE  |= 0x08                          //P33�˿�ʹ�ܿ�©����
#define  P34_OD_EN     P3_ODE  |= 0x10                          //P34�˿�ʹ�ܿ�©����
#define  P35_OD_EN     P3_ODE  |= 0x20                          //P35�˿�ʹ�ܿ�©����
#define  P36_OD_EN     P3_ODE  |= 0x40                          //P36�˿�ʹ�ܿ�©����
#define  P37_OD_EN     P3_ODE  |= 0x80                          //P37�˿�ʹ�ܿ�©����
#define  P3_OD_EN      P3_ODE  = 0xff                           //P3 �˿�ʹ�ܿ�©����

#define  P30_OD_DIS    P3_ODE  &= 0xfe                          //P30�˿ڽ�ֹ��©����
#define  P31_OD_DIS    P3_ODE  &= 0xfd                          //P31�˿ڽ�ֹ��©����
#define  P32_OD_DIS    P3_ODE  &= 0xfb                          //P32�˿ڽ�ֹ��©����
#define  P33_OD_DIS    P3_ODE  &= 0xf7                          //P33�˿ڽ�ֹ��©����
#define  P34_OD_DIS    P3_ODE  &= 0xef                          //P34�˿ڽ�ֹ��©����
#define  P35_OD_DIS    P3_ODE  &= 0xdf                          //P35�˿ڽ�ֹ��©����
#define  P36_OD_DIS    P3_ODE  &= 0xbf                          //P36�˿ڽ�ֹ��©����
#define  P37_OD_DIS    P3_ODE  &= 0x7f                          //P37�˿ڽ�ֹ��©����
#define  P3_OD_DIS     P3_ODE  = 0x00                           //P3 �˿ڽ�ֹ��©����

//P0 SMITE SET
#define  P00_SMIT_EN     P0_SMITE  |= 0x01                      //P00�˿�ʹ��ʩ���ع���   
#define  P01_SMIT_EN     P0_SMITE  |= 0x02                      //P01�˿�ʹ��ʩ���ع���
#define  P02_SMIT_EN     P0_SMITE  |= 0x04                      //P02�˿�ʹ��ʩ���ع���
#define  P03_SMIT_EN     P0_SMITE  |= 0x08                      //P03�˿�ʹ��ʩ���ع���
#define  P04_SMIT_EN     P0_SMITE  |= 0x10                      //P04�˿�ʹ��ʩ���ع���
#define  P05_SMIT_EN     P0_SMITE  |= 0x20                      //P05�˿�ʹ��ʩ���ع���
#define  P0_SMIT_EN      P0_SMITE  |= 0x3f                      //P0 �˿�ʹ��ʩ���ع���

#define  P00_SMIT_DIS    P0_SMITE  &= 0xfe                      //P00�˿ڽ�ֹʩ���ع���
#define  P01_SMIT_DIS    P0_SMITE  &= 0xfd                      //P01�˿ڽ�ֹʩ���ع���
#define  P02_SMIT_DIS    P0_SMITE  &= 0xfb                      //P02�˿ڽ�ֹʩ���ع���
#define  P03_SMIT_DIS    P0_SMITE  &= 0xf7                      //P03�˿ڽ�ֹʩ���ع���
#define  P04_SMIT_DIS    P0_SMITE  &= 0xef                      //P04�˿ڽ�ֹʩ���ع���
#define  P05_SMIT_DIS    P0_SMITE  &= 0xdf                      //P05�˿ڽ�ֹʩ���ع���
#define  P0_SMIT_DIS     P0_SMITE  &= 0xc0                      //P0 �˿ڽ�ֹʩ���ع���

//P1 SMITE SET
#define  P10_SMIT_EN     P1_SMITE  |= 0x01                      //P10�˿�ʹ��ʩ���ع���
#define  P11_SMIT_EN     P1_SMITE  |= 0x02                      //P11�˿�ʹ��ʩ���ع���
#define  P12_SMIT_EN     P1_SMITE  |= 0x04                      //P12�˿�ʹ��ʩ���ع���
#define  P13_SMIT_EN     P1_SMITE  |= 0x08                      //P13�˿�ʹ��ʩ���ع���
#define  P14_SMIT_EN     P1_SMITE  |= 0x10                      //P14�˿�ʹ��ʩ���ع���
#define  P15_SMIT_EN     P1_SMITE  |= 0x20                      //P15�˿�ʹ��ʩ���ع���
#define  P16_SMIT_EN     P1_SMITE  |= 0x40                      //P16�˿�ʹ��ʩ���ع���
#define  P17_SMIT_EN     P1_SMITE  |= 0x80                      //P17�˿�ʹ��ʩ���ع���
#define  P1_SMIT_EN      P1_SMITE  = 0xff                       //P1 �˿�ʹ��ʩ���ع���

#define  P10_SMIT_DIS    P1_SMITE  &= 0xfe                      //P10�˿ڽ�ֹʩ���ع���
#define  P11_SMIT_DIS    P1_SMITE  &= 0xfd                      //P11�˿ڽ�ֹʩ���ع���
#define  P12_SMIT_DIS    P1_SMITE  &= 0xfb                      //P12�˿ڽ�ֹʩ���ع���
#define  P13_SMIT_DIS    P1_SMITE  &= 0xf7                      //P13�˿ڽ�ֹʩ���ع���
#define  P14_SMIT_DIS    P1_SMITE  &= 0xef                      //P14�˿ڽ�ֹʩ���ع���
#define  P15_SMIT_DIS    P1_SMITE  &= 0xdf                      //P15�˿ڽ�ֹʩ���ع���
#define  P16_SMIT_DIS    P1_SMITE  &= 0xbf                      //P16�˿ڽ�ֹʩ���ع���
#define  P17_SMIT_DIS    P1_SMITE  &= 0x7f                      //P17�˿ڽ�ֹʩ���ع���
#define  P1_SMIT_DIS     P1_SMITE  = 0x00                       //P1 �˿ڽ�ֹʩ���ع���

//P2 SMITE SET

#define  P20_SMIT_EN     P2_SMITE  |= 0x01                      //P20�˿�ʹ��ʩ���ع���
#define  P21_SMIT_EN     P2_SMITE  |= 0x02                      //P21�˿�ʹ��ʩ���ع���
#define  P22_SMIT_EN     P2_SMITE  |= 0x04                      //P22�˿�ʹ��ʩ���ع���
#define  P23_SMIT_EN     P2_SMITE  |= 0x08                      //P23�˿�ʹ��ʩ���ع���
#define  P24_SMIT_EN     P2_SMITE  |= 0x10                      //P24�˿�ʹ��ʩ���ع���
#define  P25_SMIT_EN     P2_SMITE  |= 0x20                      //P25�˿�ʹ��ʩ���ع���
#define  P26_SMIT_EN     P2_SMITE  |= 0x40                      //P26�˿�ʹ��ʩ���ع���
#define  P27_SMIT_EN     P2_SMITE  |= 0x80                      //P27�˿�ʹ��ʩ���ع���
#define  P2_SMIT_EN      P2_SMITE  = 0xff                       //P2 �˿�ʹ��ʩ���ع���

#define  P20_SMIT_DIS    P2_SMITE  &= 0xfe                      //P20�˿ڽ�ֹʩ���ع���
#define  P21_SMIT_DIS    P2_SMITE  &= 0xfd                      //P21�˿ڽ�ֹʩ���ع���
#define  P22_SMIT_DIS    P2_SMITE  &= 0xfb                      //P22�˿ڽ�ֹʩ���ع���
#define  P23_SMIT_DIS    P2_SMITE  &= 0xf7                      //P23�˿ڽ�ֹʩ���ع���
#define  P24_SMIT_DIS    P2_SMITE  &= 0xef                      //P24�˿ڽ�ֹʩ���ع���
#define  P25_SMIT_DIS    P2_SMITE  &= 0xdf                      //P25�˿ڽ�ֹʩ���ع���
#define  P26_SMIT_DIS    P2_SMITE  &= 0xbf                      //P26�˿ڽ�ֹʩ���ع���
#define  P27_SMIT_DIS    P2_SMITE  &= 0x7f                      //P27�˿ڽ�ֹʩ���ع���
#define  P2_SMIT_DIS     P2_SMITE  = 0x00                       //P2 �˿ڽ�ֹʩ���ع���

//P3 SMITE SET

#define  P30_SMIT_EN     P3_SMITE  |= 0x01                      //P30�˿�ʹ��ʩ���ع���
#define  P31_SMIT_EN     P3_SMITE  |= 0x02                      //P31�˿�ʹ��ʩ���ع���
#define  P32_SMIT_EN     P3_SMITE  |= 0x04                      //P32�˿�ʹ��ʩ���ع���
#define  P33_SMIT_EN     P3_SMITE  |= 0x08                      //P33�˿�ʹ��ʩ���ع���
#define  P34_SMIT_EN     P3_SMITE  |= 0x10                      //P34�˿�ʹ��ʩ���ع���
#define  P35_SMIT_EN     P3_SMITE  |= 0x20                      //P35�˿�ʹ��ʩ���ع���
#define  P36_SMIT_EN     P3_SMITE  |= 0x40                      //P36�˿�ʹ��ʩ���ع���
#define  P37_SMIT_EN     P3_SMITE  |= 0x80                      //P37�˿�ʹ��ʩ���ع���
#define  P3_SMIT_EN      P3_SMITE  = 0xff                       //P3 �˿�ʹ��ʩ���ع���

#define  P30_SMIT_DIS    P3_SMITE  &= 0xfe                      //P30�˿ڽ�ֹʩ���ع���
#define  P31_SMIT_DIS    P3_SMITE  &= 0xfd                      //P31�˿ڽ�ֹʩ���ع���
#define  P32_SMIT_DIS    P3_SMITE  &= 0xfb                      //P32�˿ڽ�ֹʩ���ع���
#define  P33_SMIT_DIS    P3_SMITE  &= 0xf7                      //P33�˿ڽ�ֹʩ���ع���
#define  P34_SMIT_DIS    P3_SMITE  &= 0xef                      //P34�˿ڽ�ֹʩ���ع���
#define  P35_SMIT_DIS    P3_SMITE  &= 0xdf                      //P35�˿ڽ�ֹʩ���ع���
#define  P36_SMIT_DIS    P3_SMITE  &= 0xbf                      //P36�˿ڽ�ֹʩ���ع���
#define  P37_SMIT_DIS    P3_SMITE  &= 0x7f                      //P37�˿ڽ�ֹʩ���ع���
#define  P3_SMIT_DIS     P3_SMITE  = 0x00                       //P3 �˿ڽ�ֹʩ���ع���

//P0 IOH SET  �ߵ�ƽ������������
#define  P00_IOH_SET0    P0_IOH_CL &= 0xFC                      //P00�˿ڸߵ�ƽ��������15MA
#define  P00_IOH_SET1    P0_IOH_CL &= 0xFC;P0_IOH_CL |= 0x01    //P00�˿ڸߵ�ƽ��������1MA
#define  P00_IOH_SET2    P0_IOH_CL &= 0xFC;P0_IOH_CL |= 0x02    //P00�˿ڸߵ�ƽ��������2MA
#define  P00_IOH_SET3    P0_IOH_CL &= 0xFC;P0_IOH_CL |= 0x03    //P00�˿ڸߵ�ƽ��������4MA

#define  P01_IOH_SET0    P0_IOH_CL &= 0xF3                      //P01�˿ڸߵ�ƽ��������15MA
#define  P01_IOH_SET1    P0_IOH_CL &= 0xF3;P0_IOH_CL |= 0x04    //P01�˿ڸߵ�ƽ��������1MA
#define  P01_IOH_SET2    P0_IOH_CL &= 0xF3;P0_IOH_CL |= 0x08    //P01�˿ڸߵ�ƽ��������2MA
#define  P01_IOH_SET3    P0_IOH_CL &= 0xF3;P0_IOH_CL |= 0x0C    //P01�˿ڸߵ�ƽ��������4MA

#define  P02_IOH_SET0    P0_IOH_CL &= 0xCF                      //P02�˿ڸߵ�ƽ��������15MA
#define  P02_IOH_SET1    P0_IOH_CL &= 0xCF;P0_IOH_CL |= 0x10    //P02�˿ڸߵ�ƽ��������1MA
#define  P02_IOH_SET2    P0_IOH_CL &= 0xCF;P0_IOH_CL |= 0x20    //P02�˿ڸߵ�ƽ��������2MA
#define  P02_IOH_SET3    P0_IOH_CL &= 0xCF;P0_IOH_CL |= 0x30    //P02�˿ڸߵ�ƽ��������4MA

#define  P03_IOH_SET0    P0_IOH_CL &= 0x3F                      //P03�˿ڸߵ�ƽ��������15MA
#define  P03_IOH_SET1    P0_IOH_CL &= 0x3F;P0_IOH_CL |= 0x40    //P03�˿ڸߵ�ƽ��������1MA
#define  P03_IOH_SET2    P0_IOH_CL &= 0x3F;P0_IOH_CL |= 0x80    //P03�˿ڸߵ�ƽ��������2MA
#define  P03_IOH_SET3    P0_IOH_CL &= 0x3F;P0_IOH_CL |= 0xC0    //P03�˿ڸߵ�ƽ��������4MA

//P1 IOH SET    �ߵ�ƽ������������
#define  P10_IOH_SET0    P1_IOH_CL &= 0xFC                      //P10�˿ڸߵ�ƽ��������15MA       
#define  P10_IOH_SET1    P1_IOH_CL &= 0xFC;P1_IOH_CL |= 0x01    //P10�˿ڸߵ�ƽ��������1MA
#define  P10_IOH_SET2    P1_IOH_CL &= 0xFC;P1_IOH_CL |= 0x02    //P10�˿ڸߵ�ƽ��������2MA
#define  P10_IOH_SET3    P1_IOH_CL &= 0xFC;P1_IOH_CL |= 0x03    //P10�˿ڸߵ�ƽ��������4MA

#define  P11_IOH_SET0    P1_IOH_CL &= 0xF3                      //P11�˿ڸߵ�ƽ��������15MA
#define  P11_IOH_SET1    P1_IOH_CL &= 0xF3;P1_IOH_CL |= 0x04    //P11�˿ڸߵ�ƽ��������1MA
#define  P11_IOH_SET2    P1_IOH_CL &= 0xF3;P1_IOH_CL |= 0x08    //P11�˿ڸߵ�ƽ��������2MA
#define  P11_IOH_SET3    P1_IOH_CL &= 0xF3;P1_IOH_CL |= 0x0C    //P11�˿ڸߵ�ƽ��������4MA

#define  P12_IOH_SET0    P1_IOH_CL &= 0xCF                      //P12�˿ڸߵ�ƽ��������15MA
#define  P12_IOH_SET1    P1_IOH_CL &= 0xCF;P1_IOH_CL |= 0x10    //P12�˿ڸߵ�ƽ��������1MA
#define  P12_IOH_SET2    P1_IOH_CL &= 0xCF;P1_IOH_CL |= 0x20    //P12�˿ڸߵ�ƽ��������2MA
#define  P12_IOH_SET3    P1_IOH_CL &= 0xCF;P1_IOH_CL |= 0x30    //P12�˿ڸߵ�ƽ��������4MA

#define  P13_IOH_SET0    P1_IOH_CL &= 0x3F                      //P13�˿ڸߵ�ƽ��������15MA
#define  P13_IOH_SET1    P1_IOH_CL &= 0x3F;P1_IOH_CL |= 0x40    //P13�˿ڸߵ�ƽ��������1MA
#define  P13_IOH_SET2    P1_IOH_CL &= 0x3F;P1_IOH_CL |= 0x80    //P13�˿ڸߵ�ƽ��������2MA
#define  P13_IOH_SET3    P1_IOH_CL &= 0x3F;P1_IOH_CL |= 0xC0    //P13�˿ڸߵ�ƽ��������4MA

#define  P14_IOH_SET0    P1_IOH_CH &= 0xFC                      //P14�˿ڸߵ�ƽ��������15MA
#define  P14_IOH_SET1    P1_IOH_CH &= 0xFC;P1_IOH_CH |= 0x01    //P14�˿ڸߵ�ƽ��������1MA
#define  P14_IOH_SET2    P1_IOH_CH &= 0xFC;P1_IOH_CH |= 0x02    //P14�˿ڸߵ�ƽ��������2MA
#define  P14_IOH_SET3    P1_IOH_CH &= 0xFC;P1_IOH_CH |= 0x03    //P14�˿ڸߵ�ƽ��������4MA

#define  P15_IOH_SET0    P1_IOH_CH &= 0xF3                      //P15�˿ڸߵ�ƽ��������15MA
#define  P15_IOH_SET1    P1_IOH_CH &= 0xF3;P1_IOH_CH |= 0x04    //P15�˿ڸߵ�ƽ��������1MA
#define  P15_IOH_SET2    P1_IOH_CH &= 0xF3;P1_IOH_CH |= 0x08    //P15�˿ڸߵ�ƽ��������2MA
#define  P15_IOH_SET3    P1_IOH_CH &= 0xF3;P1_IOH_CH |= 0x0C    //P15�˿ڸߵ�ƽ��������4MA

#define  P16_IOH_SET0    P1_IOH_CH &= 0xCF                      //P16�˿ڸߵ�ƽ��������15MA
#define  P16_IOH_SET1    P1_IOH_CH &= 0xCF;P1_IOH_CH |= 0x10    //P16�˿ڸߵ�ƽ��������1MA
#define  P16_IOH_SET2    P1_IOH_CH &= 0xCF;P1_IOH_CH |= 0x20    //P16�˿ڸߵ�ƽ��������2MA
#define  P16_IOH_SET3    P1_IOH_CH &= 0xCF;P1_IOH_CH |= 0x30    //P16�˿ڸߵ�ƽ��������4MA

#define  P17_IOH_SET0    P1_IOH_CH &= 0x3F                      //P17�˿ڸߵ�ƽ��������15MA
#define  P17_IOH_SET1    P1_IOH_CH &= 0x3F;P1_IOH_CH |= 0x40    //P17�˿ڸߵ�ƽ��������1MA
#define  P17_IOH_SET2    P1_IOH_CH &= 0x3F;P1_IOH_CH |= 0x80    //P17�˿ڸߵ�ƽ��������2MA
#define  P17_IOH_SET3    P1_IOH_CH &= 0x3F;P1_IOH_CH |= 0xC0    //P17�˿ڸߵ�ƽ��������4MA

//P3 IOL SET    �͵�ƽ������������
#define  P30_IOL_SET0    P3_IOL_CL &= 0xFE                      //P30�˿ڵ͵�ƽ��������15MA
#define  P30_IOL_SET1    P3_IOL_CL |= 0x01                      //P30�˿ڵ͵�ƽ��������80MA

#define  P31_IOL_SET0    P3_IOL_CL &= 0xFB                      //P31�˿ڵ͵�ƽ��������15MA      
#define  P31_IOL_SET1    P3_IOL_CL |= 0x04                      //P31�˿ڵ͵�ƽ��������80MA

#define  P32_IOL_SET0    P3_IOL_CL &= 0xEF                      //P32�˿ڵ͵�ƽ��������15MA
#define  P32_IOL_SET1    P3_IOL_CL |= 0x10                      //P32�˿ڵ͵�ƽ��������80MA

#define  P33_IOL_SET0    P3_IOL_CL &= 0xBF                      //P33�˿ڵ͵�ƽ��������15MA
#define  P33_IOL_SET1    P3_IOL_CL |= 0x40                      //P33�˿ڵ͵�ƽ��������80MA

#define  P34_IOL_SET0    P3_IOL_CH &= 0xFE                      //P34�˿ڵ͵�ƽ��������15MA
#define  P34_IOL_SET1    P3_IOL_CH |= 0x01                      //P34�˿ڵ͵�ƽ��������80MA

#define  P35_IOL_SET0    P3_IOL_CH &= 0xFB                      //P35�˿ڵ͵�ƽ��������15MA
#define  P35_IOL_SET1    P3_IOL_CH |= 0x04                      //P35�˿ڵ͵�ƽ��������80MA

#define  P36_IOL_SET0    P3_IOL_CH &= 0xEF                      //P36�˿ڵ͵�ƽ��������15MA
#define  P36_IOL_SET1    P3_IOL_CH |= 0x10                      //P36�˿ڵ͵�ƽ��������80MA

#define  P37_IOL_SET0    P3_IOL_CH &= 0xBF                      //P37�˿ڵ͵�ƽ��������15MA
#define  P37_IOL_SET1    P3_IOL_CH |= 0x40                      //P37�˿ڵ͵�ƽ��������80MA


//IO�ж�����ѡ��1
#define  P00_POS_INT_EN   EINT0_IOS &=0xfe;  EINT0_MD &=0xfe; EINT0_IE |= 0x01  //P00�����أ�ʹ���ⲿ�ж�
#define  P01_POS_INT_EN   EINT0_IOS &=0xfd;  EINT0_MD &=0xfd; EINT0_IE |= 0x02  //P01�����أ�ʹ���ⲿ�ж�
#define  P02_POS_INT_EN   EINT0_IOS &=0xfb;  EINT0_MD &=0xfb; EINT0_IE |= 0x04  //P02�����أ�ʹ���ⲿ�ж�
#define  P03_POS_INT_EN   EINT0_IOS &=0xf7;  EINT0_MD &=0xf7; EINT0_IE |= 0x08  //P03�����أ�ʹ���ⲿ�ж�
#define  P04_POS_INT_EN   EINT0_IOS &=0xef;  EINT0_MD &=0xef; EINT0_IE |= 0x10  //P04�����أ�ʹ���ⲿ�ж�
#define  P05_POS_INT_EN   EINT0_IOS &=0xdf;  EINT0_MD &=0xdf; EINT0_IE |= 0x20  //P05�����أ�ʹ���ⲿ�ж�

#define  P00_POS_INT_DIS  EINT0_IOS &=0xfe;  EINT0_MD &=0xfe; EINT0_IE &= 0xfe  //P00�����أ���ֹ�ⲿ�ж�
#define  P01_POS_INT_DIS  EINT0_IOS &=0xfd;  EINT0_MD &=0xfd; EINT0_IE &= 0xfd  //P01�����أ���ֹ�ⲿ�ж�
#define  P02_POS_INT_DIS  EINT0_IOS &=0xfb;  EINT0_MD &=0xfb; EINT0_IE &= 0xfb  //P02�����أ���ֹ�ⲿ�ж�
#define  P03_POS_INT_DIS  EINT0_IOS &=0xf7;  EINT0_MD &=0xf7; EINT0_IE &= 0xf7  //P03�����أ���ֹ�ⲿ�ж�
#define  P04_POS_INT_DIS  EINT0_IOS &=0xef;  EINT0_MD &=0xef; EINT0_IE &= 0xef  //P04�����أ���ֹ�ⲿ�ж�
#define  P05_POS_INT_DIS  EINT0_IOS &=0xdf;  EINT0_MD &=0xdf; EINT0_IE &= 0xdf  //P05�����أ���ֹ�ⲿ�ж�

#define  P00_NEG_INT_EN   EINT0_IOS &=0xfe;  EINT0_MD |=0x01; EINT0_IE |= 0x01 //P00�½��أ�ʹ���ⲿ�ж�
#define  P01_NEG_INT_EN   EINT0_IOS &=0xfd;  EINT0_MD |=0x02; EINT0_IE |= 0x02 //P01�½��أ�ʹ���ⲿ�ж�
#define  P02_NEG_INT_EN   EINT0_IOS &=0xfb;  EINT0_MD |=0x04; EINT0_IE |= 0x04 //P02�½��أ�ʹ���ⲿ�ж�
#define  P03_NEG_INT_EN   EINT0_IOS &=0xf7;  EINT0_MD |=0x08; EINT0_IE |= 0x08 //P03�½��أ�ʹ���ⲿ�ж�
#define  P04_NEG_INT_EN   EINT0_IOS &=0xef;  EINT0_MD |=0x10; EINT0_IE |= 0x10 //P04�½��أ�ʹ���ⲿ�ж�
#define  P05_NEG_INT_EN   EINT0_IOS &=0xdf;  EINT0_MD |=0x20; EINT0_IE |= 0x20 //P05�½��أ�ʹ���ⲿ�ж�

#define  P00_NEG_INT_DIS   EINT0_IOS &=0xfe; EINT0_MD |=0x01; EINT0_IE &= 0xfe //P00�½��أ���ֹ�ⲿ�ж�
#define  P01_NEG_INT_DIS   EINT0_IOS &=0xfd; EINT0_MD |=0x02; EINT0_IE &= 0xfd //P01�½��أ���ֹ�ⲿ�ж�
#define  P02_NEG_INT_DIS   EINT0_IOS &=0xfb; EINT0_MD |=0x04; EINT0_IE &= 0xfb //P02�½��أ���ֹ�ⲿ�ж�
#define  P03_NEG_INT_DIS   EINT0_IOS &=0xf7; EINT0_MD |=0x08; EINT0_IE &= 0xf7 //P03�½��أ���ֹ�ⲿ�ж�
#define  P04_NEG_INT_DIS   EINT0_IOS &=0xef; EINT0_MD |=0x10; EINT0_IE &= 0xef //P04�½��أ���ֹ�ⲿ�ж�
#define  P05_NEG_INT_DIS   EINT0_IOS &=0xdf; EINT0_MD |=0x20; EINT0_IE &= 0xdf //P05�½��أ���ֹ�ⲿ�ж�

//P1 INI
#define  P10_POS_INT_EN   EINT1_IOS &=0xfe;  EINT1_MD &=0xfe; EINT1_IE |= 0x01  //P10�����أ�ʹ���ⲿ�ж�
#define  P11_POS_INT_EN   EINT1_IOS &=0xfd;  EINT1_MD &=0xfd; EINT1_IE |= 0x02  //P11�����أ�ʹ���ⲿ�ж�
#define  P12_POS_INT_EN   EINT1_IOS &=0xfb;  EINT1_MD &=0xfb; EINT1_IE |= 0x04  //P12�����أ�ʹ���ⲿ�ж�
#define  P13_POS_INT_EN   EINT1_IOS &=0xf7;  EINT1_MD &=0xf7; EINT1_IE |= 0x08  //P13�����أ�ʹ���ⲿ�ж�
#define  P14_POS_INT_EN   EINT1_IOS &=0xef;  EINT1_MD &=0xef; EINT1_IE |= 0x10  //P14�����أ�ʹ���ⲿ�ж�
#define  P15_POS_INT_EN   EINT1_IOS &=0xdf;  EINT1_MD &=0xdf; EINT1_IE |= 0x20  //P15�����أ�ʹ���ⲿ�ж�
#define  P16_POS_INT_EN   EINT1_IOS &=0xbf;  EINT1_MD &=0xbf; EINT1_IE |= 0x40  //P16�����أ�ʹ���ⲿ�ж�
#define  P17_POS_INT_EN   EINT1_IOS &=0x7f;  EINT1_MD &=0x7f; EINT1_IE |= 0x80  //P17�����أ�ʹ���ⲿ�ж�

#define  P10_POS_INT_DIS   EINT1_IOS &=0xfe;  EINT1_MD &=0xfe; EINT1_IE &=0xfe  //P10�����أ���ֹ�ⲿ�ж�
#define  P11_POS_INT_DIS   EINT1_IOS &=0xfd;  EINT1_MD &=0xfd; EINT1_IE &=0xfd  //P11�����أ���ֹ�ⲿ�ж�
#define  P12_POS_INT_DIS   EINT1_IOS &=0xfb;  EINT1_MD &=0xfb; EINT1_IE &=0xfb  //P12�����أ���ֹ�ⲿ�ж�
#define  P13_POS_INT_DIS   EINT1_IOS &=0xf7;  EINT1_MD &=0xf7; EINT1_IE &=0xf7  //P13�����أ���ֹ�ⲿ�ж�
#define  P14_POS_INT_DIS   EINT1_IOS &=0xef;  EINT1_MD &=0xef; EINT1_IE &=0xef  //P14�����أ���ֹ�ⲿ�ж�
#define  P15_POS_INT_DIS   EINT1_IOS &=0xdf;  EINT1_MD &=0xdf; EINT1_IE &=0xdf  //P15�����أ���ֹ�ⲿ�ж�
#define  P16_POS_INT_DIS   EINT1_IOS &=0xbf;  EINT1_MD &=0xbf; EINT1_IE &=0xbf  //P16�����أ���ֹ�ⲿ�ж�
#define  P17_POS_INT_DIS   EINT1_IOS &=0x7f;  EINT1_MD &=0x7f; EINT1_IE &=0x7f  //P17�����أ���ֹ�ⲿ�ж�

#define  P10_NEG_INT_EN   EINT1_IOS &=0xfe;  EINT1_MD |= 0x01; EINT1_IE |= 0x01 //P10�½��أ�ʹ���ⲿ�ж�
#define  P11_NEG_INT_EN   EINT1_IOS &=0xfd;  EINT1_MD |= 0x02; EINT1_IE |= 0x02 //P11�½��أ�ʹ���ⲿ�ж�
#define  P12_NEG_INT_EN   EINT1_IOS &=0xfb;  EINT1_MD |= 0x04; EINT1_IE |= 0x04 //P12�½��أ�ʹ���ⲿ�ж�
#define  P13_NEG_INT_EN   EINT1_IOS &=0xf7;  EINT1_MD |= 0x08; EINT1_IE |= 0x08 //P13�½��أ�ʹ���ⲿ�ж�
#define  P14_NEG_INT_EN   EINT1_IOS &=0xef;  EINT1_MD |= 0x10; EINT1_IE |= 0x10 //P14�½��أ�ʹ���ⲿ�ж�
#define  P15_NEG_INT_EN   EINT1_IOS &=0xdf;  EINT1_MD |= 0x20; EINT1_IE |= 0x20 //P15�½��أ�ʹ���ⲿ�ж�
#define  P16_NEG_INT_EN   EINT1_IOS &=0xbf;  EINT1_MD |= 0x40; EINT1_IE |= 0x40 //P16�½��أ�ʹ���ⲿ�ж�
#define  P17_NEG_INT_EN   EINT1_IOS &=0x7f;  EINT1_MD |= 0x80; EINT1_IE |= 0x80 //P17�½��أ�ʹ���ⲿ�ж�

#define  P10_NEG_INT_DIS   EINT1_IOS &=0xfe;  EINT1_MD |= 0x01; EINT1_IE &=0xfe //P10�½��أ���ֹ�ⲿ�ж�
#define  P11_NEG_INT_DIS   EINT1_IOS &=0xfd;  EINT1_MD |= 0x02; EINT1_IE &=0xfd //P11�½��أ���ֹ�ⲿ�ж�
#define  P12_NEG_INT_DIS   EINT1_IOS &=0xfb;  EINT1_MD |= 0x04; EINT1_IE &=0xfb //P12�½��أ���ֹ�ⲿ�ж�
#define  P13_NEG_INT_DIS   EINT1_IOS &=0xf7;  EINT1_MD |= 0x08; EINT1_IE &=0xf7 //P13�½��أ���ֹ�ⲿ�ж�
#define  P14_NEG_INT_DIS   EINT1_IOS &=0xef;  EINT1_MD |= 0x10; EINT1_IE &=0xef //P14�½��أ���ֹ�ⲿ�ж�
#define  P15_NEG_INT_DIS   EINT1_IOS &=0xdf;  EINT1_MD |= 0x20; EINT1_IE &=0xdf //P15�½��أ���ֹ�ⲿ�ж�
#define  P16_NEG_INT_DIS   EINT1_IOS &=0xbf;  EINT1_MD |= 0x40; EINT1_IE &=0xbf //P16�½��أ���ֹ�ⲿ�ж�
#define  P17_NEG_INT_DIS   EINT1_IOS &=0x7f;  EINT1_MD |= 0x80; EINT1_IE &=0x7f //P17�½��أ���ֹ�ⲿ�ж� 

//IO�ж�����ѡ��2
#define  P20_POS_INT_EN   EINT0_IOS |=0x01;  EINT0_MD &=0xfe; EINT0_IE |= 0x01  //P20�����أ�ʹ���ⲿ�ж�
#define  P21_POS_INT_EN   EINT0_IOS |=0x02;  EINT0_MD &=0xfd; EINT0_IE |= 0x02  //P21�����أ�ʹ���ⲿ�ж�
#define  P22_POS_INT_EN   EINT0_IOS |=0x04;  EINT0_MD &=0xfb; EINT0_IE |= 0x04  //P22�����أ�ʹ���ⲿ�ж�
#define  P23_POS_INT_EN   EINT0_IOS |=0x08;  EINT0_MD &=0xf7; EINT0_IE |= 0x08  //P23�����أ�ʹ���ⲿ�ж�
#define  P24_POS_INT_EN   EINT0_IOS |=0x10;  EINT0_MD &=0xef; EINT0_IE |= 0x10  //P24�����أ�ʹ���ⲿ�ж�
#define  P25_POS_INT_EN   EINT0_IOS |=0x20;  EINT0_MD &=0xdf; EINT0_IE |= 0x20  //P25�����أ�ʹ���ⲿ�ж�
#define  P26_POS_INT_EN   EINT0_IOS |=0x40;  EINT0_MD &=0xbf; EINT0_IE |= 0x40  //P26�����أ�ʹ���ⲿ�ж�
#define  P27_POS_INT_EN   EINT0_IOS |=0x80;  EINT0_MD &=0x7f; EINT0_IE |= 0x80  //P27�����أ�ʹ���ⲿ�ж�

#define  P20_POS_INT_DIS  EINT0_IOS |=0x01;  EINT0_MD &=0xfe; EINT0_IE &= 0xfe  //P20�����أ���ֹ�ⲿ�ж�
#define  P21_POS_INT_DIS  EINT0_IOS |=0x02;  EINT0_MD &=0xfd; EINT0_IE &= 0xfd  //P21�����أ���ֹ�ⲿ�ж�
#define  P22_POS_INT_DIS  EINT0_IOS |=0x04;  EINT0_MD &=0xfb; EINT0_IE &= 0xfb  //P22�����أ���ֹ�ⲿ�ж�
#define  P23_POS_INT_DIS  EINT0_IOS |=0x08;  EINT0_MD &=0xf7; EINT0_IE &= 0xf7  //P23�����أ���ֹ�ⲿ�ж�
#define  P24_POS_INT_DIS  EINT0_IOS |=0x10;  EINT0_MD &=0xef; EINT0_IE &= 0xef  //P24�����أ���ֹ�ⲿ�ж�
#define  P25_POS_INT_DIS  EINT0_IOS |=0x20;  EINT0_MD &=0xdf; EINT0_IE &= 0xdf  //P25�����أ���ֹ�ⲿ�ж�
#define  P26_POS_INT_DIS  EINT0_IOS |=0x40;  EINT0_MD &=0xbf; EINT0_IE &= 0xbf  //P26�����أ���ֹ�ⲿ�ж�
#define  P27_POS_INT_DIS  EINT0_IOS |=0x80;  EINT0_MD &=0x7f; EINT0_IE &= 0x7f  //P27�����أ���ֹ�ⲿ�ж�

#define  P20_NEG_INT_EN  EINT0_IOS |=0x01;  EINT0_MD |=0x01; EINT0_IE |= 0x01   //P20�½��أ�ʹ���ⲿ�ж�
#define  P21_NEG_INT_EN  EINT0_IOS |=0x02;  EINT0_MD |=0x02; EINT0_IE |= 0x02   //P21�½��أ�ʹ���ⲿ�ж�
#define  P22_NEG_INT_EN  EINT0_IOS |=0x04;  EINT0_MD |=0x04; EINT0_IE |= 0x04   //P22�½��أ�ʹ���ⲿ�ж�
#define  P23_NEG_INT_EN  EINT0_IOS |=0x08;  EINT0_MD |=0x08; EINT0_IE |= 0x08   //P23�½��أ�ʹ���ⲿ�ж�
#define  P24_NEG_INT_EN  EINT0_IOS |=0x10;  EINT0_MD |=0x10; EINT0_IE |= 0x10   //P24�½��أ�ʹ���ⲿ�ж�
#define  P25_NEG_INT_EN  EINT0_IOS |=0x20;  EINT0_MD |=0x20; EINT0_IE |= 0x20   //P25�½��أ�ʹ���ⲿ�ж�
#define  P26_NEG_INT_EN  EINT0_IOS |=0x40;  EINT0_MD |=0x40; EINT0_IE |= 0x40   //P26�½��أ�ʹ���ⲿ�ж�
#define  P27_NEG_INT_EN  EINT0_IOS |=0x80;  EINT0_MD |=0x80; EINT0_IE |= 0x80   //P27�½��أ�ʹ���ⲿ�ж�

#define  P20_NEG_INT_DIS  EINT0_IOS |=0x01;  EINT0_MD |=0x01; EINT0_IE &= 0xfe  //P20�½��أ���ֹ�ⲿ�ж�
#define  P21_NEG_INT_DIS  EINT0_IOS |=0x02;  EINT0_MD |=0x02; EINT0_IE &= 0xfd  //P21�½��أ���ֹ�ⲿ�ж�
#define  P22_NEG_INT_DIS  EINT0_IOS |=0x04;  EINT0_MD |=0x04; EINT0_IE &= 0xfb  //P22�½��أ���ֹ�ⲿ�ж�
#define  P23_NEG_INT_DIS  EINT0_IOS |=0x08;  EINT0_MD |=0x08; EINT0_IE &= 0xf7  //P23�½��أ���ֹ�ⲿ�ж�
#define  P24_NEG_INT_DIS  EINT0_IOS |=0x10;  EINT0_MD |=0x10; EINT0_IE &= 0xef  //P24�½��أ���ֹ�ⲿ�ж�
#define  P25_NEG_INT_DIS  EINT0_IOS |=0x20;  EINT0_MD |=0x20; EINT0_IE &= 0xdf  //P25�½��أ���ֹ�ⲿ�ж�
#define  P26_NEG_INT_DIS  EINT0_IOS |=0x40;  EINT0_MD |=0x40; EINT0_IE &= 0xbf  //P26�½��أ���ֹ�ⲿ�ж�
#define  P27_NEG_INT_DIS  EINT0_IOS |=0x80;  EINT0_MD |=0x80; EINT0_IE &= 0x7f  //P27�½��أ���ֹ�ⲿ�ж�     

//P3 EINT SET
#define  P30_POS_INT_EN  EINT1_IOS |= 0x01;  EINT1_MD &=0xfe; EINT1_IE |= 0x01  //P30�����أ�ʹ���ⲿ�ж�
#define  P31_POS_INT_EN  EINT1_IOS |= 0x02;  EINT1_MD &=0xfd; EINT1_IE |= 0x02  //P31�����أ�ʹ���ⲿ�ж�
#define  P32_POS_INT_EN  EINT1_IOS |= 0x04;  EINT1_MD &=0xfb; EINT1_IE |= 0x04  //P32�����أ�ʹ���ⲿ�ж�
#define  P33_POS_INT_EN  EINT1_IOS |= 0x08;  EINT1_MD &=0xf7; EINT1_IE |= 0x08  //P33�����أ�ʹ���ⲿ�ж�
#define  P34_POS_INT_EN  EINT1_IOS |= 0x10;  EINT1_MD &=0xef; EINT1_IE |= 0x10  //P34�����أ�ʹ���ⲿ�ж�
#define  P35_POS_INT_EN  EINT1_IOS |= 0x20;  EINT1_MD &=0xdf; EINT1_IE |= 0x20  //P35�����أ�ʹ���ⲿ�ж�
#define  P36_POS_INT_EN  EINT1_IOS |= 0x40;  EINT1_MD &=0xbf; EINT1_IE |= 0x40  //P36�����أ�ʹ���ⲿ�ж�
#define  P37_POS_INT_EN  EINT1_IOS |= 0x80;  EINT1_MD &=0x7f; EINT1_IE |= 0x80  //P37�����أ�ʹ���ⲿ�ж�

#define  P30_POS_INT_DIS EINT1_IOS |= 0x01;  EINT1_MD &=0xfe; EINT1_IE &=0xfe   //P30�����أ���ֹ�ⲿ�ж�
#define  P31_POS_INT_DIS EINT1_IOS |= 0x02;  EINT1_MD &=0xfd; EINT1_IE &=0xfd   //P31�����أ���ֹ�ⲿ�ж�
#define  P32_POS_INT_DIS EINT1_IOS |= 0x04;  EINT1_MD &=0xfb; EINT1_IE &=0xfb   //P32�����أ���ֹ�ⲿ�ж�
#define  P33_POS_INT_DIS EINT1_IOS |= 0x08;  EINT1_MD &=0xf7; EINT1_IE &=0xf7   //P33�����أ���ֹ�ⲿ�ж�
#define  P34_POS_INT_DIS EINT1_IOS |= 0x10;  EINT1_MD &=0xef; EINT1_IE &=0xef   //P34�����أ���ֹ�ⲿ�ж�
#define  P35_POS_INT_DIS EINT1_IOS |= 0x20;  EINT1_MD &=0xdf; EINT1_IE &=0xdf   //P35�����أ���ֹ�ⲿ�ж�
#define  P36_POS_INT_DIS EINT1_IOS |= 0x40;  EINT1_MD &=0xbf; EINT1_IE &=0xbf   //P36�����أ���ֹ�ⲿ�ж�
#define  P37_POS_INT_DIS EINT1_IOS |= 0x80;  EINT1_MD &=0x7f; EINT1_IE &=0x7f   //P37�����أ���ֹ�ⲿ�ж�

#define  P30_NEG_INT_EN  EINT1_IOS |= 0x01;  EINT1_MD |= 0x01; EINT1_IE |= 0x01 //P30�½��أ�ʹ���ⲿ�ж�
#define  P31_NEG_INT_EN  EINT1_IOS |= 0x02;  EINT1_MD |= 0x02; EINT1_IE |= 0x02 //P31�½��أ�ʹ���ⲿ�ж�
#define  P32_NEG_INT_EN  EINT1_IOS |= 0x04;  EINT1_MD |= 0x04; EINT1_IE |= 0x04 //P32�½��أ�ʹ���ⲿ�ж�
#define  P33_NEG_INT_EN  EINT1_IOS |= 0x08;  EINT1_MD |= 0x08; EINT1_IE |= 0x08 //P33�½��أ�ʹ���ⲿ�ж�
#define  P34_NEG_INT_EN  EINT1_IOS |= 0x10;  EINT1_MD |= 0x10; EINT1_IE |= 0x10 //P34�½��أ�ʹ���ⲿ�ж�
#define  P35_NEG_INT_EN  EINT1_IOS |= 0x20;  EINT1_MD |= 0x20; EINT1_IE |= 0x20 //P35�½��أ�ʹ���ⲿ�ж�
#define  P36_NEG_INT_EN  EINT1_IOS |= 0x40;  EINT1_MD |= 0x40; EINT1_IE |= 0x40 //P36�½��أ�ʹ���ⲿ�ж�
#define  P37_NEG_INT_EN  EINT1_IOS |= 0x80;  EINT1_MD |= 0x80; EINT1_IE |= 0x80 //P37�½��أ�ʹ���ⲿ�ж�

#define  P30_NEG_INT_DIS EINT1_IOS |= 0x01;  EINT1_MD |= 0x01; EINT1_IE &=0xfe  //P30�½��أ���ֹ�ⲿ�ж�
#define  P31_NEG_INT_DIS EINT1_IOS |= 0x02;  EINT1_MD |= 0x02; EINT1_IE &=0xfd  //P31�½��أ���ֹ�ⲿ�ж�
#define  P32_NEG_INT_DIS EINT1_IOS |= 0x04;  EINT1_MD |= 0x04; EINT1_IE &=0xfb  //P32�½��أ���ֹ�ⲿ�ж�
#define  P33_NEG_INT_DIS EINT1_IOS |= 0x08;  EINT1_MD |= 0x08; EINT1_IE &=0xf7  //P33�½��أ���ֹ�ⲿ�ж�
#define  P34_NEG_INT_DIS EINT1_IOS |= 0x10;  EINT1_MD |= 0x10; EINT1_IE &=0xef  //P34�½��أ���ֹ�ⲿ�ж�
#define  P35_NEG_INT_DIS EINT1_IOS |= 0x20;  EINT1_MD |= 0x20; EINT1_IE &=0xdf  //P35�½��أ���ֹ�ⲿ�ж�
#define  P36_NEG_INT_DIS EINT1_IOS |= 0x40;  EINT1_MD |= 0x40; EINT1_IE &=0xbf  //P36�½��أ���ֹ�ⲿ�ж�
#define  P37_NEG_INT_DIS EINT1_IOS |= 0x80;  EINT1_MD |= 0x80; EINT1_IE &=0x7f  //P37�½��أ���ֹ�ⲿ�ж� 

#define  P00_INT_IF_CLR   EINT00_IF = 0                                         //���P00�ⲿ�жϱ�־λ
#define  P01_INT_IF_CLR   EINT01_IF = 0                                         //���P01�ⲿ�жϱ�־λ
#define  P02_INT_IF_CLR   EINT02_IF = 0                                         //���P02�ⲿ�жϱ�־λ
#define  P03_INT_IF_CLR   EINT03_IF = 0                                         //���P03�ⲿ�жϱ�־λ
#define  P04_INT_IF_CLR   EINT04_IF = 0                                         //���P04�ⲿ�жϱ�־λ
#define  P05_INT_IF_CLR   EINT05_IF = 0                                         //���P05�ⲿ�жϱ�־λ
    
#define  P10_INT_IF_CLR   EINT10_IF = 0                                         //���P10�ⲿ�жϱ�־λ
#define  P11_INT_IF_CLR   EINT11_IF = 0                                         //���P11�ⲿ�жϱ�־λ
#define  P12_INT_IF_CLR   EINT12_IF = 0                                         //���P12�ⲿ�жϱ�־λ
#define  P13_INT_IF_CLR   EINT13_IF = 0                                         //���P13�ⲿ�жϱ�־λ
#define  P14_INT_IF_CLR   EINT14_IF = 0                                         //���P14�ⲿ�жϱ�־λ
#define  P15_INT_IF_CLR   EINT15_IF = 0                                         //���P15�ⲿ�жϱ�־λ
#define  P16_INT_IF_CLR   EINT16_IF = 0                                         //���P16�ⲿ�жϱ�־λ
#define  P17_INT_IF_CLR   EINT17_IF = 0                                         //���P17�ⲿ�жϱ�־λ
    
#define  P20_INT_IF_CLR   EINT00_IF = 0                                         //���P20�ⲿ�жϱ�־λ
#define  P21_INT_IF_CLR   EINT01_IF = 0                                         //���P21�ⲿ�жϱ�־λ
#define  P22_INT_IF_CLR   EINT02_IF = 0                                         //���P22�ⲿ�жϱ�־λ
#define  P23_INT_IF_CLR   EINT03_IF = 0                                         //���P23�ⲿ�жϱ�־λ
#define  P24_INT_IF_CLR   EINT04_IF = 0                                         //���P24�ⲿ�жϱ�־λ
#define  P25_INT_IF_CLR   EINT05_IF = 0                                         //���P25�ⲿ�жϱ�־λ
#define  P26_INT_IF_CLR   EINT06_IF = 0                                         //���P26�ⲿ�жϱ�־λ
#define  P27_INT_IF_CLR   EINT07_IF = 0                                         //���P27�ⲿ�жϱ�־λ
    
#define  P30_INT_IF_CLR   EINT10_IF = 0                                         //���P30�ⲿ�жϱ�־λ
#define  P31_INT_IF_CLR   EINT11_IF = 0                                         //���P31�ⲿ�жϱ�־λ
#define  P32_INT_IF_CLR   EINT12_IF = 0                                         //���P32�ⲿ�жϱ�־λ
#define  P33_INT_IF_CLR   EINT13_IF = 0                                         //���P33�ⲿ�жϱ�־λ
#define  P34_INT_IF_CLR   EINT14_IF = 0                                         //���P34�ⲿ�жϱ�־λ
#define  P35_INT_IF_CLR   EINT15_IF = 0                                         //���P35�ⲿ�жϱ�־λ
#define  P36_INT_IF_CLR   EINT16_IF = 0                                         //���P36�ⲿ�жϱ�־λ
#define  P37_INT_IF_CLR   EINT17_IF = 0                                         //���P37�ⲿ�жϱ�־λ


//�жϿ���
#define  GIE_EN       GIE = 1                                                   //�������ж�
#define  INT0_EN      INT0_IE = 1                                               //����INT0�ж�
#define  INT1_EN      INT1_IE = 1                                               //����INT1�ж�
#define  INT2_EN      INT2_IE = 1                                               //����INT2�ж�
#define  INT3_EN      INT3_IE = 1                                               //����INT3�ж�
#define  INT4_EN      INT4_IE = 1                                               //����INT4�ж�
#define  INT5_EN      INT5_IE = 1                                               //����INT5�ж�
#define  INT6_EN      INT6_IE = 1                                               //����INT6�ж�

#define  GIE_DIS      GIE = 0                                                   //�ر����ж�
#define  INT0_DIS     INT0_IE = 0                                               //�ر�INT0�ж�
#define  INT1_DIS     INT1_IE = 0                                               //�ر�INT1�ж�
#define  INT2_DIS     INT2_IE = 0                                               //�ر�INT2�ж�
#define  INT3_DIS     INT3_IE = 0                                               //�ر�INT3�ж�
#define  INT4_DIS     INT4_IE = 0                                               //�ر�INT4�ж�
#define  INT5_DIS     INT5_IE = 0                                               //�ر�INT5�ж�
#define  INT6_DIS     INT6_IE = 0                                               //�ر�INT6�ж�

#define  INT0_PI_EN   INT0_IP = 1                                               //����INT0�����ȼ�
#define  INT1_PI_EN   INT1_IP = 1                                               //����INT1�����ȼ�
#define  INT2_PI_EN   INT2_IP = 1                                               //����INT2�����ȼ�
#define  INT3_PI_EN   INT3_IP = 1                                               //����INT3�����ȼ�
#define  INT4_PI_EN   INT4_IP = 1                                               //����INT4�����ȼ�
#define  INT5_PI_EN   INT5_IP = 1                                               //����INT5�����ȼ�
#define  INT6_PI_EN   INT6_IP = 1                                               //����INT6�����ȼ�

#define  INT0_PI_DIS  INT0_IP = 0                                               //����INT0�����ȼ�
#define  INT1_PI_DIS  INT1_IP = 0                                               //����INT1�����ȼ�
#define  INT2_PI_DIS  INT2_IP = 0                                               //����INT2�����ȼ�
#define  INT3_PI_DIS  INT3_IP = 0                                               //����INT3�����ȼ�
#define  INT4_PI_DIS  INT4_IP = 0                                               //����INT4�����ȼ�
#define  INT5_PI_DIS  INT5_IP = 0                                               //����INT5�����ȼ�
#define  INT6_PI_DIS  INT6_IP = 0                                               //����INT6�����ȼ�

#define  INT0_IF_CLR  INT0_IF = 0                                               //���INT0�жϱ�־λ
#define  INT1_IF_CLR  INT1_IF = 0                                               //���INT1�жϱ�־λ
#define  INT2_IF_CLR  INT2_IF = 0                                               //���INT2�жϱ�־λ
#define  INT3_IF_CLR  INT3_IF = 0                                               //���INT3�жϱ�־λ
#define  INT4_IF_CLR  INT4_IF = 0                                               //���INT4�жϱ�־λ
#define  INT5_IF_CLR  INT5_IF = 0                                               //���INT5�жϱ�־λ
#define  INT6_IF_CLR  INT6_IF = 0                                               //���INT6�жϱ�־λ
#define  INT_IF_CLR   INTn_IF = 0x00                                            //��������жϱ�־λ

//TMR �ж�
#define  TMR0_INT_EN  TMRn_IE |= 0x01                                           //ʹ�ܶ�ʱ��0�ж�
#define  TMR1_INT_EN  TMRn_IE |= 0x02                                           //ʹ�ܶ�ʱ��1�ж�
#define  TMR2_INT_EN  TMRn_IE |= 0x04                                           //ʹ�ܶ�ʱ��2�ж�
#define  TMR3_INT_EN  TMRn_IE |= 0x08                                           //ʹ�ܶ�ʱ��3�ж�
    
#define  TMR0_INT_DIS TMRn_IE &= 0xfe                                           //��ֹ��ʱ��0�ж�
#define  TMR1_INT_DIS TMRn_IE &= 0xfd                                           //��ֹ��ʱ��1�ж�
#define  TMR2_INT_DIS TMRn_IE &= 0xfb                                           //��ֹ��ʱ��2�ж�
#define  TMR3_INT_DIS TMRn_IE &= 0xf7                                           //��ֹ��ʱ��3�ж�

#define  TMR0_INT_IF_CLR TMR0_IF = 0                                            //�����ʱ��0�жϱ�־λ
#define  TMR1_INT_IF_CLR TMR1_IF = 0                                            //�����ʱ��1�жϱ�־λ
#define  TMR2_INT_IF_CLR TMR2_IF = 0                                            //�����ʱ��2�жϱ�־λ
#define  TMR3_INT_IF_CLR TMR3_IF = 0                                            //�����ʱ��3�жϱ�־λ

//CAP �ж�
#define  CAP0_INT_EN  CAPn_IE |= 0x01                                           //ʹ��CAP0�ж�
#define  CAP1_INT_EN  CAPn_IE |= 0x02                                           //ʹ��CAP1�ж�
#define  CAP2_INT_EN  CAPn_IE |= 0x04                                           //ʹ��CAP2�ж�

#define  CAP0_INT_DIS CAPn_IE &= 0xfe                                           //��ֹCAP0�ж�
#define  CAP1_INT_DIS CAPn_IE &= 0xfd                                           //��ֹCAP1�ж�
#define  CAP2_INT_DIS CAPn_IE &= 0xfb                                           //��ֹCAP2�ж�

#define  CAP0_INT_IF_CLR CAP0_IF = 0                                            //���CAP0�жϱ�־λ
#define  CAP1_INT_IF_CLR CAP1_IF = 0                                            //���CAP1�жϱ�־λ
#define  CAP2_INT_IF_CLR CAP2_IF = 0                                            //���CAP2�жϱ�־λ

//PWM �ж�
#define  PWM0_INT_EN  PWMn_IE |= 0x01                                           //ʹ��PWM0�ж�
#define  PWM1_INT_EN  PWMn_IE |= 0x02                                           //ʹ��PWM1�ж�
#define  PWM2_INT_EN  PWMn_IE |= 0x04                                           //ʹ��PWM2�ж�
#define  STP0_INT_EN  PWMn_IE |= 0x10                                           //ʹ��STP0�ж�
#define  STP1_INT_EN  PWMn_IE |= 0x20                                           //ʹ��STP1�ж�
#define  STP2_INT_EN  PWMn_IE |= 0x40                                           //ʹ��STP2�ж�

#define  PWM0_INT_DIS PWMn_IE &= 0xfe                                           //��ֹPWM0�ж�
#define  PWM1_INT_DIS PWMn_IE &= 0xfd                                           //��ֹPWM1�ж�
#define  PWM2_INT_DIS PWMn_IE &= 0xfb                                           //��ֹPWM2�ж�
#define  STP0_INT_DIS PWMn_IE &= 0xef                                           //��ֹSTP0�ж�
#define  STP1_INT_DIS PWMn_IE &= 0xdf                                           //��ֹSTP1�ж�
#define  STP2_INT_DIS PWMn_IE &= 0xbf                                           //��ֹSTP2�ж�

#define  PWM0_INT_IF_CLR PWM0_IF = 0                                            //���PWM0�жϱ�־λ
#define  PWM1_INT_IF_CLR PWM1_IF = 0                                            //���PWM1�жϱ�־λ
#define  PWM2_INT_IF_CLR PWM2_IF = 0                                            //���PWM2�жϱ�־λ
#define  STP0_INT_IF_CLR STP0_IF = 0                                            //���STP0�жϱ�־λ
#define  STP1_INT_IF_CLR STP1_IF = 0                                            //���STP1�жϱ�־λ
#define  STP2_INT_IF_CLR STP2_IF = 0                                            //���STP2�жϱ�־λ

//uart �ж�
#define  UART0_RX0_INT_EN  UART_IE |= 0x01                                      //ʹ��UART0_RX�ж�
#define  UART0_TX0_INT_EN  UART_IE |= 0x02                                      //ʹ��UART0_TX�ж�

#define  UART0_RX0_INT_DIS UART_IE &= 0xfe                                      //��ֹUART0_RX�ж�
#define  UART0_TX0_INT_DIS UART_IE &= 0xfd                                      //��ֹUART0_TX�ж�

#define  UART1_RX1_INT_EN  UART_IE |= 0x04                                      //ʹ��UART1_RX�ж�
#define  UART1_TX1_INT_EN  UART_IE |= 0x08                                      //ʹ��UART1_TX�ж�

#define  UART1_RX1_INT_DIS UART_IE &= 0xfB                                      //��ֹUART1_RX�ж�
#define  UART1_TX1_INT_DIS UART_IE &= 0xf7                                      //��ֹUART1_TX�ж�

#define  UART0_TX0_IF_CLR  TX0_IF = 0                                           //���UART0_RX�жϱ�־λ
#define  UART0_RX0_IF_CLR  RX0_IF = 0                                           //���UART0_TX�жϱ�־λ
#define  UART1_TX1_IF_CLR  TX1_IF = 0                                           //���UART1_RX�жϱ�־λ
#define  UART1_RX1_IF_CLR  RX1_IF = 0                                           //���UART1_TX�жϱ�־λ

//IIC �ж�
#define  IIC_INT_EN  IICn_IE |= 0x10                                            //ʹ��IIC�ж�
#define  IIC_INT_DIS IICn_IE &= 0xef                                            //��ֹIIC�ж�

#define  IIC_INT_IF_CLR IIC_IF = 0                                              //���IIC�жϱ�־λ

//SPI �ж�
#define  SPI_INT_EN  SPIn_IE |= 0x40                                            //ʹ��SPI�ж�
#define  SPI_INT_DIS SPIn_IE &= 0xbf                                            //��ֹSPI�ж�

#define  SPI_INT_IF_CLR SPIn_IF = 0                                             //���SPI�жϱ�־λ

//ģ���ж�
#define  ADC_INT_EN   AN_IE |= 0x01                                             //ʹ��ADC�ж�
#define  TK_INT_EN    AN_IE |= 0x02                                             //ʹ��TK�ж�
#define  LVD_INT_EN   AN_IE |= 0x04                                             //ʹ��LVD�ж�
#define  LED_INT_EN   AN_IE |= 0x10                                             //ʹ��LED�ж�
#define  COM_INT_EN   AN_IE |= 0x20                                             //ʹ��COM�ж�

#define  ADC_INT_DIS   AN_IE &= 0xfe                                            //��ֹADC�ж�
#define  TK_INT_DIS    AN_IE &= 0xfd                                            //��ֹTK�ж�
#define  LVD_INT_DIS   AN_IE &= 0xfb                                            //��ֹLVD�ж�
#define  LED_INT_DIS   AN_IE &= 0xef                                            //��ֹLED�ж�
#define  COM_INT_DIS   AN_IE &= 0xdf                                            //��ֹCOM�ж�


#define  ADC_INT_IF_CLR ADC_IF = 0                                              //���ADC�жϱ�־λ
#define  TK_INT_IF_CLR  TK_IF  = 0                                              //���TK�жϱ�־λ
#define  LVD_INT_IF_CLR LVD_IF = 0                                              //���LVD�жϱ�־λ
#define  LED_INT_IF_CLR LED_IF = 0                                              //���LED�жϱ�־λ
#define  COM_INT_IF_CLR COM_IF = 0                                              //���COM�жϱ�־λ

//TMR0
#define  TMR0_PST_1    TMR0_C0 &= 0xf0                                          //��ʱ��0���Ƶ����ʱ��0 1 ����������ж�
#define  TMR0_PST_2    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x01                        //��ʱ��0���Ƶ����ʱ��0 2 ����������ж�
#define  TMR0_PST_3    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x02                        //��ʱ��0���Ƶ����ʱ��0 3 ����������ж�
#define  TMR0_PST_4    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x03                        //��ʱ��0���Ƶ����ʱ��0 4 ����������ж�
#define  TMR0_PST_5    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x04                        //��ʱ��0���Ƶ����ʱ��0 5 ����������ж�
#define  TMR0_PST_6    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x05                        //��ʱ��0���Ƶ����ʱ��0 6 ����������ж�
#define  TMR0_PST_7    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x06                        //��ʱ��0���Ƶ����ʱ��0 7 ����������ж�
#define  TMR0_PST_8    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x07                        //��ʱ��0���Ƶ����ʱ��0 8 ����������ж�
#define  TMR0_PST_9    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x08                        //��ʱ��0���Ƶ����ʱ��0 9 ����������ж�
#define  TMR0_PST_10   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x09                        //��ʱ��0���Ƶ����ʱ��0 10����������ж�
#define  TMR0_PST_11   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0a                        //��ʱ��0���Ƶ����ʱ��0 11����������ж�
#define  TMR0_PST_12   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0b                        //��ʱ��0���Ƶ����ʱ��0 12����������ж�
#define  TMR0_PST_13   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0c                        //��ʱ��0���Ƶ����ʱ��0 13����������ж�
#define  TMR0_PST_14   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0d                        //��ʱ��0���Ƶ����ʱ��0 14����������ж�
#define  TMR0_PST_15   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0e                        //��ʱ��0���Ƶ����ʱ��0 15����������ж�
#define  TMR0_PST_16   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0f                        //��ʱ��0���Ƶ����ʱ��0 16����������ж�

#define  TMR0_SYSCLK   TMR0_C0 &= 0xcf                                          //��ʱ��0����ʱ��ΪSYS_CLK ϵͳʱ��
#define  TMR0_EXCK     TMR0_C0 &= 0xcf;  TMR0_C0 |= 0x10                        //��ʱ��0����ʱ��ΪEXCK ���ö˿�����
#define  TMR0_HRC      TMR0_C0 &= 0xcf;  TMR0_C0 |= 0x20                        //��ʱ��0����ʱ��ΪHRC �ڲ���Ƶʱ��
#define  TMR0_XOSC     TMR0_C0 &= 0xcf;  TMR0_C0 |= 0x30                        //��ʱ��0����ʱ��ΪXOSC ����

#define  TMR0_DIV8_EN  TMR0_C0 |= 0x40                                          //��ʱ��0ʹ�ܼ���ʱ��8��Ƶ
#define  TMR0_DIV8_DIS TMR0_C0 &= 0xbf                                          //��ʱ��0��ֹ����ʱ��8��Ƶ

#define  TMR0_EN       TMR0_C0 |= 0x80                                          //ʹ�ܶ�ʱ��0
#define  TMR0_DIS      TMR0_C0 &= 0x7f                                          //��ֹ��ʱ��0

#define  TMR0_GE_H_EN  TMR0_C1 = 0x01                                           //��ʱ��0�ſ�ʹ�� �ߵ�ƽʹ�ܶ�ʱ��0
#define  TMR0_GE_L_EN  TMR0_C1 = 0x03                                           //��ʱ��0�ſ�ʹ�� �͵�ƽʹ�ܶ�ʱ��0

#define  TMR0_GE_H_DIS TMR0_C1 = 0x00                                           //��ʱ��0�ſعر� �ߵ�ƽʹ�ܶ�ʱ��0
#define  TMR0_GE_L_DIS TMR0_C1 = 0x00                                           //��ʱ��0�ſعر� �͵�ƽʹ�ܶ�ʱ��0

#define  TMR0_CLR      TMR0L = 0x00;     TMR0H = 0x00                           // �����ʱ��0�����Ĵ���

//TMR1
#define  TMR1_PST_1    TMR1_C0 &= 0xf0                                          //��ʱ��1���Ƶ����ʱ��1 1 ����������ж�
#define  TMR1_PST_2    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x01                        //��ʱ��1���Ƶ����ʱ��1 2 ����������ж�
#define  TMR1_PST_3    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x02                        //��ʱ��1���Ƶ����ʱ��1 3 ����������ж�
#define  TMR1_PST_4    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x03                        //��ʱ��1���Ƶ����ʱ��1 4 ����������ж�
#define  TMR1_PST_5    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x04                        //��ʱ��1���Ƶ����ʱ��1 5 ����������ж�
#define  TMR1_PST_6    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x05                        //��ʱ��1���Ƶ����ʱ��1 6 ����������ж�
#define  TMR1_PST_7    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x06                        //��ʱ��1���Ƶ����ʱ��1 7 ����������ж�
#define  TMR1_PST_8    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x07                        //��ʱ��1���Ƶ����ʱ��1 8 ����������ж�
#define  TMR1_PST_9    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x08                        //��ʱ��1���Ƶ����ʱ��1 9 ����������ж�
#define  TMR1_PST_10   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x09                        //��ʱ��1���Ƶ����ʱ��1 10����������ж�
#define  TMR1_PST_11   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0a                        //��ʱ��1���Ƶ����ʱ��1 11����������ж�
#define  TMR1_PST_12   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0b                        //��ʱ��1���Ƶ����ʱ��1 12����������ж�
#define  TMR1_PST_13   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0c                        //��ʱ��1���Ƶ����ʱ��1 13����������ж�
#define  TMR1_PST_14   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0d                        //��ʱ��1���Ƶ����ʱ��1 14����������ж�
#define  TMR1_PST_15   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0e                        //��ʱ��1���Ƶ����ʱ��1 15����������ж�
#define  TMR1_PST_16   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0f                        //��ʱ��1���Ƶ����ʱ��1 16����������ж�

#define  TMR1_SYSCLK   TMR1_C0 &= 0xcf                                          //��ʱ��1����ʱ��ΪSYS_CLK ϵͳʱ��
#define  TMR1_EXCK     TMR1_C0 &= 0xcf;  TMR1_C0 |= 0x10                        //��ʱ��1����ʱ��ΪEXCK ���ö˿�����
#define  TMR1_HRC      TMR1_C0 &= 0xcf;  TMR1_C0 |= 0x20                        //��ʱ��1����ʱ��ΪHRC �ڲ���Ƶʱ��
#define  TMR1_LRC_10MS TMR1_C0 &= 0xcf;  TMR1_C0 |= 0x30                        //��ʱ��1����ʱ��ΪLRC 10Ms����

#define  TMR1_DIV8_EN  TMR1_C0 |= 0x40                                          //��ʱ��1ʹ�ܼ���ʱ��8��Ƶ
#define  TMR1_DIV8_DIS TMR1_C0 &= 0xbf                                          //��ʱ��1��ֹ����ʱ��8��Ƶ

#define  TMR1_EN       TMR1_C0 |= 0x80                                          //ʹ�ܶ�ʱ��1
#define  TMR1_DIS      TMR1_C0 &= 0x7f                                          //��ֹ��ʱ��1

#define  TMR1_GE_H_EN  TMR1_C1 = 0x04                                           //��ʱ��1�ſ�ʹ�� �ߵ�ƽʹ�ܶ�ʱ��1
#define  TMR1_GE_L_EN  TMR1_C1 = 0x0C                                           //��ʱ��1�ſ�ʹ�� �͵�ƽʹ�ܶ�ʱ��1

#define  TMR1_GE_H_DIS TMR1_C1 = 0x00                                           //��ʱ��1�ſعر� �ߵ�ƽʹ�ܶ�ʱ��1
#define  TMR1_GE_L_DIS TMR1_C1 = 0x00                                           //��ʱ��1�ſعر� �͵�ƽʹ�ܶ�ʱ��1

#define  TMR1_CLR      TMR1L = 0x00;     TMR1H = 0x00                           // �����ʱ��1�����Ĵ���

//TMR2
#define  TMR2_PST_1    TMR2_C0 &= 0xf0                                          //��ʱ��2���Ƶ����ʱ��2 1 ����������ж�
#define  TMR2_PST_2    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x01                        //��ʱ��2���Ƶ����ʱ��2 2 ����������ж�
#define  TMR2_PST_3    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x02                        //��ʱ��2���Ƶ����ʱ��2 3 ����������ж�
#define  TMR2_PST_4    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x03                        //��ʱ��2���Ƶ����ʱ��2 4 ����������ж�
#define  TMR2_PST_5    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x04                        //��ʱ��2���Ƶ����ʱ��2 5 ����������ж�
#define  TMR2_PST_6    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x05                        //��ʱ��2���Ƶ����ʱ��2 6 ����������ж�
#define  TMR2_PST_7    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x06                        //��ʱ��2���Ƶ����ʱ��2 7 ����������ж�
#define  TMR2_PST_8    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x07                        //��ʱ��2���Ƶ����ʱ��2 8 ����������ж�
#define  TMR2_PST_9    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x08                        //��ʱ��2���Ƶ����ʱ��2 9 ����������ж�
#define  TMR2_PST_10   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x09                        //��ʱ��2���Ƶ����ʱ��2 10����������ж�
#define  TMR2_PST_11   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0a                        //��ʱ��2���Ƶ����ʱ��2 11����������ж�
#define  TMR2_PST_12   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0b                        //��ʱ��2���Ƶ����ʱ��2 12����������ж�
#define  TMR2_PST_13   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0c                        //��ʱ��2���Ƶ����ʱ��2 13����������ж�
#define  TMR2_PST_14   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0d                        //��ʱ��2���Ƶ����ʱ��2 14����������ж�
#define  TMR2_PST_15   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0e                        //��ʱ��2���Ƶ����ʱ��2 15����������ж�
#define  TMR2_PST_16   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0f                        //��ʱ��2���Ƶ����ʱ��2 16����������ж�

#define  TMR2_SYSCLK   TMR2_C0 &= 0xcf                                          //��ʱ��2����ʱ��ΪSYS_CLK ϵͳʱ��
#define  TMR2_EXCK     TMR2_C0 &= 0xcf;  TMR2_C0 |= 0x10                        //��ʱ��2����ʱ��ΪEXCK ���ö˿�����
#define  TMR2_HRC      TMR2_C0 &= 0xcf;  TMR2_C0 |= 0x20                        //��ʱ��2����ʱ��ΪHRC �ڲ���Ƶʱ��
#define  TMR2_LRC      TMR2_C0 &= 0xcf;  TMR2_C0 |= 0x30                        //��ʱ��2����ʱ��ΪLRC ʱ��

#define  TMR2_DIV8_EN  TMR2_C0 |= 0x40                                          //��ʱ��2ʹ�ܼ���ʱ��8��Ƶ
#define  TMR2_DIV8_DIS TMR2_C0 &= 0xbf                                          //��ʱ��2��ֹ����ʱ��8��Ƶ

#define  TMR2_EN       TMR2_C0 |= 0x80                                          //ʹ�ܶ�ʱ��2
#define  TMR2_DIS      TMR2_C0 &= 0x7f                                          //��ֹ��ʱ��2

#define  TMR2_GE_H_EN  TMR2_C1 = 0x10                                           //��ʱ��2�ſ�ʹ�� �ߵ�ƽʹ�ܶ�ʱ��2
#define  TMR2_GE_L_EN  TMR2_C1 = 0x30                                           //��ʱ��2�ſ�ʹ�� �͵�ƽʹ�ܶ�ʱ��2

#define  TMR2_GE_H_DIS TMR2_C1 = 0x00                                           //��ʱ��2�ſعر� �ߵ�ƽʹ�ܶ�ʱ��2
#define  TMR2_GE_L_DIS TMR2_C1 = 0x00                                           //��ʱ��2�ſعر� �͵�ƽʹ�ܶ�ʱ��2

#define  TMR2_CLR      TMR2L = 0x00;     TMR2H = 0x00                           // �����ʱ��2�����Ĵ���

//TMR3
#define  TMR3_PST_1    TMR3_C0 &= 0xf0                                          //��ʱ��3���Ƶ����ʱ��3 1 ����������ж�
#define  TMR3_PST_2    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x01                        //��ʱ��3���Ƶ����ʱ��3 2 ����������ж�
#define  TMR3_PST_3    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x02                        //��ʱ��3���Ƶ����ʱ��3 3 ����������ж�
#define  TMR3_PST_4    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x03                        //��ʱ��3���Ƶ����ʱ��3 4 ����������ж�
#define  TMR3_PST_5    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x04                        //��ʱ��3���Ƶ����ʱ��3 5 ����������ж�
#define  TMR3_PST_6    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x05                        //��ʱ��3���Ƶ����ʱ��3 6 ����������ж�
#define  TMR3_PST_7    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x06                        //��ʱ��3���Ƶ����ʱ��3 7 ����������ж�
#define  TMR3_PST_8    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x07                        //��ʱ��3���Ƶ����ʱ��3 8 ����������ж�
#define  TMR3_PST_9    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x08                        //��ʱ��3���Ƶ����ʱ��3 9 ����������ж�
#define  TMR3_PST_10   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x09                        //��ʱ��3���Ƶ����ʱ��3 10����������ж�
#define  TMR3_PST_11   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0a                        //��ʱ��3���Ƶ����ʱ��3 11����������ж�
#define  TMR3_PST_12   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0b                        //��ʱ��3���Ƶ����ʱ��3 12����������ж�
#define  TMR3_PST_13   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0c                        //��ʱ��3���Ƶ����ʱ��3 13����������ж�
#define  TMR3_PST_14   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0d                        //��ʱ��3���Ƶ����ʱ��3 14����������ж�
#define  TMR3_PST_15   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0e                        //��ʱ��3���Ƶ����ʱ��3 15����������ж�
#define  TMR3_PST_16   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0f                        //��ʱ��3���Ƶ����ʱ��3 16����������ж�

#define  TMR3_SYSCLK   TMR3_C0 &= 0xcf                                          //��ʱ��3����ʱ��ΪSYS_CLK ϵͳʱ��
#define  TMR3_EXCK     TMR3_C0 &= 0xcf;  TMR3_C0 |= 0x10                        //��ʱ��3����ʱ��ΪEXCK ���ö˿�����
#define  TMR3_HRC      TMR3_C0 &= 0xcf;  TMR3_C0 |= 0x20                        //��ʱ��3����ʱ��ΪHRC �ڲ���Ƶʱ��
#define  TMR3_LRC      TMR3_C0 &= 0xcf;  TMR3_C0 |= 0x30                        //��ʱ��3����ʱ��ΪXOSC ����

#define  TMR3_DIV8_EN  TMR3_C0 |= 0x40                                          //��ʱ��3ʹ�ܼ���ʱ��8��Ƶ
#define  TMR3_DIV8_DIS TMR3_C0 &= 0xbf                                          //��ʱ��3��ֹ����ʱ��8��Ƶ

#define  TMR3_EN       TMR3_C0 |= 0x80                                          //ʹ�ܶ�ʱ��3
#define  TMR3_DIS      TMR3_C0 &= 0x7f                                          //��ֹ��ʱ��3

#define  TMR3_GE_H_EN  TMR3_C1 = 0x40                                           //��ʱ��3�ſ�ʹ�� �ߵ�ƽʹ�ܶ�ʱ��3
#define  TMR3_GE_L_EN  TMR3_C1 = 0xC0                                           //��ʱ��3�ſ�ʹ�� �͵�ƽʹ�ܶ�ʱ��3

#define  TMR3_GE_H_DIS TMR3_C1 = 0x00                                           //��ʱ��3�ſعر� �ߵ�ƽʹ�ܶ�ʱ��3
#define  TMR3_GE_L_DIS TMR3_C1 = 0x00                                           //��ʱ��3�ſعر� �͵�ƽʹ�ܶ�ʱ��3

#define  TMR3_CLR      TMR3L = 0x00;     TMR3H = 0x00                           // �����ʱ��3�����Ĵ���

//CAP0
#define  CAP0_MD_DIS   CAP0_C &= 0xfc                                           //CAP0�رղ�׽ģʽ
#define  CAP0_ADD_MD   CAP0_C &= 0xfc;    CAP0_C |= 0x02                        //CAP0��׽�ۼ�ģʽ(��׽�¼�����ʱ��ʱ��TMR �����ۼ�)
#define  CAP0_CLR_MD   CAP0_C |= 0x03                                           //CAP0��׽����ģʽ(��׽�¼�����ʱ����ʱ��TMR ����)

#define  CAP0_TMR0_S   CAP0_C &= 0xf3                                           //CAP0��׽����ʱ��Ϊ��ʱ��0
#define  CAP0_TMR1_S   CAP0_C &= 0xf3;    CAP0_C |= 0x04                        //CAP0��׽����ʱ��Ϊ��ʱ��1
#define  CAP0_TMR2_S   CAP0_C &= 0xf3;    CAP0_C |= 0x08                        //CAP0��׽����ʱ��Ϊ��ʱ��2
#define  CAP0_TMR3_S   CAP0_C |= 0x0c                                           //CAP0��׽����ʱ��Ϊ��ʱ��3

#define  CAP0_CAP_1    CAP0_C &= 0xcf                                           //CAP0��׽ 1 ���������ز���1 �β�׽�¼�
#define  CAP0_CAP_4    CAP0_C &= 0xcf;    CAP0_C |= 0x10                        //CAP0��׽ 4 ���������ز���1 �β�׽�¼�
#define  CAP0_CAP_8    CAP0_C &= 0xcf;    CAP0_C |= 0x20                        //CAP0��׽ 8 ���������ز���1 �β�׽�¼�
#define  CAP0_CAP_16   CAP0_C |= 0x30                                           //CAP0��׽ 16���������ز���1 �β�׽�¼�

#define  CAP0_CAP_NONE CAP0_C &= 0x3f                                           //CAP0��׽    ����
#define  CAP0_CAP_POS  CAP0_C &= 0x3f;    CAP0_C |= 0x40                        //CAP0��׽    �����ز�׽
#define  CAP0_CAP_NEG  CAP0_C &= 0x3f;    CAP0_C |= 0x80                        //CAP0��׽    �½��ز�׽
#define  CAP0_CAP_EDGE CAP0_C |= 0xc0                                           //CAP0��׽    �������½��ض���׽

//CAP1
#define  CAP1_MD_DIS   CAP1_C &= 0xfc                                           //CAP1�رղ�׽ģʽ
#define  CAP1_ADD_MD   CAP1_C &= 0xfc;    CAP1_C |= 0x02                        //CAP1��׽�ۼ�ģʽ(��׽�¼�����ʱ��ʱ��TMR �����ۼ�)
#define  CAP1_CLR_MD   CAP1_C |= 0x03                                           //CAP1��׽����ģʽ(��׽�¼�����ʱ����ʱ��TMR ����)

#define  CAP1_TMR0_S   CAP1_C &= 0xf3                                           //CAP1��׽����ʱ��Ϊ��ʱ��0
#define  CAP1_TMR1_S   CAP1_C &= 0xf3;    CAP1_C |= 0x04                        //CAP1��׽����ʱ��Ϊ��ʱ��1
#define  CAP1_TMR2_S   CAP1_C &= 0xf3;    CAP1_C |= 0x08                        //CAP1��׽����ʱ��Ϊ��ʱ��2
#define  CAP1_TMR3_S   CAP1_C |= 0x0c                                           //CAP1��׽����ʱ��Ϊ��ʱ��3

#define  CAP1_CAP_1    CAP1_C &= 0xcf                                           //CAP1��׽ 1 ���������ز���1 �β�׽�¼�
#define  CAP1_CAP_4    CAP1_C &= 0xcf;    CAP1_C |= 0x10                        //CAP1��׽ 4 ���������ز���1 �β�׽�¼�
#define  CAP1_CAP_8    CAP1_C &= 0xcf;    CAP1_C |= 0x20                        //CAP1��׽ 8 ���������ز���1 �β�׽�¼�
#define  CAP1_CAP_16   CAP1_C |= 0x30                                           //CAP1��׽ 16���������ز���1 �β�׽�¼�

#define  CAP1_CAP_NONE CAP1_C &= 0x3f                                           //CAP1��׽    ����
#define  CAP1_CAP_POS  CAP1_C &= 0x3f;    CAP1_C |= 0x40                        //CAP1��׽    �����ز�׽
#define  CAP1_CAP_NEG  CAP1_C &= 0x3f;    CAP1_C |= 0x80                        //CAP1��׽    �½��ز�׽
#define  CAP1_CAP_EDGE CAP1_C |= 0xc0                                           //CAP1��׽    �������½��ض���׽

//CAP2
#define  CAP2_MD_DIS   CAP2_C &= 0xfc                                           //CAP2�رղ�׽ģʽ
#define  CAP2_ADD_MD   CAP2_C &= 0xfc;    CAP2_C |= 0x02                        //CAP2��׽�ۼ�ģʽ(��׽�¼�����ʱ��ʱ��TMR �����ۼ�)
#define  CAP2_CLR_MD   CAP2_C |= 0x03                                           //CAP2��׽����ģʽ(��׽�¼�����ʱ����ʱ��TMR ����)

#define  CAP2_TMR0_S   CAP2_C &= 0xf3                                           //CAP2��׽����ʱ��Ϊ��ʱ��0
#define  CAP2_TMR1_S   CAP2_C &= 0xf3;    CAP2_C |= 0x04                        //CAP2��׽����ʱ��Ϊ��ʱ��1
#define  CAP2_TMR2_S   CAP2_C &= 0xf3;    CAP2_C |= 0x08                        //CAP2��׽����ʱ��Ϊ��ʱ��2
#define  CAP2_TMR3_S   CAP2_C |= 0x0c                                           //CAP2��׽����ʱ��Ϊ��ʱ��3

#define  CAP2_CAP_1    CAP2_C &= 0xcf                                           //CAP2��׽ 1 ���������ز���1 �β�׽�¼�
#define  CAP2_CAP_4    CAP2_C &= 0xcf;    CAP2_C |= 0x10                        //CAP2��׽ 4 ���������ز���1 �β�׽�¼�
#define  CAP2_CAP_8    CAP2_C &= 0xcf;    CAP2_C |= 0x20                        //CAP2��׽ 8 ���������ز���1 �β�׽�¼�
#define  CAP2_CAP_16   CAP2_C |= 0x30                                           //CAP2��׽ 16���������ز���1 �β�׽�¼�

#define  CAP2_CAP_NONE CAP2_C &= 0x3f                                           //CAP2��׽    ����
#define  CAP2_CAP_POS  CAP2_C &= 0x3f;    CAP2_C |= 0x40                        //CAP2��׽    �����ز�׽
#define  CAP2_CAP_NEG  CAP2_C &= 0x3f;    CAP2_C |= 0x80                        //CAP2��׽    �½��ز�׽
#define  CAP2_CAP_EDGE CAP2_C |= 0xc0                                           //CAP2��׽    �������½��ض���׽

//PWM0
#define  PWM0_MD_DIS   PWM0_C &= 0xfc                                           //�ر�PWM0
#define  PWM0_MD_EN    PWM0_C &= 0xfc;    PWM0_C |= 0x01                        //ʹ��PWM0

#define  PWM0_TMR0_S   PWM0_C &= 0xf3                                           //PWM0����ʱ��Ϊ��ʱ��0
#define  PWM0_TMR1_S   PWM0_C &= 0xf3;PWM0_C |= 0x04                            //PWM0����ʱ��Ϊ��ʱ��1
#define  PWM0_TMR2_S   PWM0_C &= 0xf3;PWM0_C |= 0x08                            //PWM0����ʱ��Ϊ��ʱ��2
#define  PWM0_TMR3_S   PWM0_C |= 0x0c                                           //PWM0����ʱ��Ϊ��ʱ��3

#define  PWM0_EDG_MD   PWM0_C &= 0xcf                                           //PWM0���ض���ģʽ
#define  PWM0_MID_MD   PWM0_C &= 0xcf;PWM0_C |= 0x10                            //PWM0���Ķ���ģʽ

#define  PWM0_STP_DIS  PWM0_C &= 0x3f                                           //PWM0  �ر�ɲ������
#define  PWM0_STP_LV   PWM0_C &= 0x3f;PWM0_C |= 0x40                            //PWM0  STP ���ö˿�����͵�ƽɲ��
#define  PWM0_STP_CMP_LV  PWM0_C &= 0x3f;PWM0_C |= 0x80                         //PWM0  �Ƚ��������ɲ��
#define  PWM0_STP_SOFT PWM0_C |= 0xc0                                           //PWM0  ���ɲ����д��11����������ɲ��״̬��


#define  PWM0_CH0_H_L  PWM0_OC &= 0xfe                                          //PWM00 ƥ���ǰ���ֵ1��ƥ�������0
#define  PWM0_CH0_L_H  PWM0_OC |= 0x01                                          //PWM00 ƥ���ǰ���ֵ0��ƥ�������1

#define  PWM0_CH1_H_L  PWM0_OC &= 0xfd                                          //PWM01 ƥ���ǰ���ֵ1��ƥ�������0
#define  PWM0_CH1_L_H  PWM0_OC |= 0x02                                          //PWM01 ƥ���ǰ���ֵ0��ƥ�������1

#define  PWM0_CH0_T_L  PWM0_OC &= 0xfb                                          //PWM00 ��ʼ����͵�ƽ
#define  PWM0_CH0_T_H  PWM0_OC |= 0x04                                          //PWM00 ��ʼ����ߵ�ƽ
    
#define  PWM0_CH1_T_L  PWM0_OC &= 0xf7                                          //PWM01 ��ʼ����͵�ƽ
#define  PWM0_CH1_T_H  PWM0_OC |= 0x08                                          //PWM01 ��ʼ����ߵ�ƽ

#define  PWM0_REX_0    PWM0_OC &= 0x0f                                          //PWM0ƽ��ռ�ձ�����λ
#define  PWM0_REX_1    PWM0_OC &= 0x0f; PWM0_OC |= 0x1f                         //PWM0ƽ��ռ�ձ�����λ
#define  PWM0_REX_2    PWM0_OC &= 0x0f; PWM0_OC |= 0x2f                         //PWM0ƽ��ռ�ձ�����λ
#define  PWM0_REX_3    PWM0_OC &= 0x0f; PWM0_OC |= 0x3f                         //PWM0ƽ��ռ�ձ�����λ
#define  PWM0_REX_4    PWM0_OC &= 0x0f; PWM0_OC |= 0x4f                         //PWM0ƽ��ռ�ձ�����λ
#define  PWM0_REX_5    PWM0_OC &= 0x0f; PWM0_OC |= 0x5f                         //PWM0ƽ��ռ�ձ�����λ
#define  PWM0_REX_6    PWM0_OC &= 0x0f; PWM0_OC |= 0x6f                         //PWM0ƽ��ռ�ձ�����λ
#define  PWM0_REX_7    PWM0_OC &= 0x0f; PWM0_OC |= 0x7f                         //PWM0ƽ��ռ�ձ�����λ


//PWM1
#define  PWM1_MD_DIS   PWM1_C &= 0xfc                                           //�ر�PWM1
#define  PWM1_MD_EN    PWM1_C &= 0xfc;    PWM1_C |= 0x01                        //ʹ��PWM1

#define  PWM1_TMR0_S   PWM1_C &= 0xf3                                           //PWM1����ʱ��Ϊ��ʱ��0
#define  PWM1_TMR1_S   PWM1_C &= 0xf3;PWM1_C |= 0x04                            //PWM1����ʱ��Ϊ��ʱ��1
#define  PWM1_TMR2_S   PWM1_C &= 0xf3;PWM1_C |= 0x08                            //PWM1����ʱ��Ϊ��ʱ��2
#define  PWM1_TMR3_S   PWM1_C |= 0x0c                                           //PWM1����ʱ��Ϊ��ʱ��3

#define  PWM1_EDG_MD   PWM1_C &= 0xcf                                           //PWM1���ض���ģʽ
#define  PWM1_MID_MD   PWM1_C &= 0xcf;PWM1_C |= 0x10                            //PWM1���Ķ���ģʽ

#define  PWM1_STP_DIS     PWM1_C &= 0x3f                                        //PWM1  �ر�ɲ������
#define  PWM1_STP_LV      PWM1_C &= 0x3f;PWM1_C |= 0x40                         //PWM1  STP ���ö˿�����͵�ƽɲ��
#define  PWM1_STP_CMP_LV  PWM1_C &= 0x3f;PWM1_C |= 0x80                         //PWM1  �Ƚ��������ɲ��
#define  PWM1_STP_SOFT    PWM1_C |= 0xc0                                        //PWM1  ���ɲ����д��11����������ɲ��״̬��


#define  PWM1_CH0_H_L  PWM1_OC &= 0xfe                                          //PWM10 ƥ���ǰ���ֵ1��ƥ�������0
#define  PWM1_CH0_L_H  PWM1_OC |= 0x01                                          //PWM10 ƥ���ǰ���ֵ0��ƥ�������1

#define  PWM1_CH1_H_L  PWM1_OC &= 0xfd                                          //PWM11 ƥ���ǰ���ֵ1��ƥ�������0
#define  PWM1_CH1_L_H  PWM1_OC |= 0x02                                          //PWM11 ƥ���ǰ���ֵ0��ƥ�������1

#define  PWM1_CH0_T_L  PWM1_OC &= 0xfb                                          //PWM10 ��ʼ����͵�ƽ
#define  PWM1_CH0_T_H  PWM1_OC |= 0x04                                          //PWM10 ��ʼ����ߵ�ƽ

#define  PWM1_CH1_T_L  PWM1_OC &= 0xf7                                          //PWM11 ��ʼ����͵�ƽ
#define  PWM1_CH1_T_H  PWM1_OC |= 0x08                                          //PWM11 ��ʼ����ߵ�ƽ

#define  PWM1_REX_0    PWM1_OC &= 0x0f                                          //PWM1ƽ��ռ�ձ�����λ
#define  PWM1_REX_1    PWM1_OC &= 0x0f; PWM1_OC |= 0x1f                         //PWM1ƽ��ռ�ձ�����λ
#define  PWM1_REX_2    PWM1_OC &= 0x0f; PWM1_OC |= 0x2f                         //PWM1ƽ��ռ�ձ�����λ
#define  PWM1_REX_3    PWM1_OC &= 0x0f; PWM1_OC |= 0x3f                         //PWM1ƽ��ռ�ձ�����λ
#define  PWM1_REX_4    PWM1_OC &= 0x0f; PWM1_OC |= 0x4f                         //PWM1ƽ��ռ�ձ�����λ
#define  PWM1_REX_5    PWM1_OC &= 0x0f; PWM1_OC |= 0x5f                         //PWM1ƽ��ռ�ձ�����λ
#define  PWM1_REX_6    PWM1_OC &= 0x0f; PWM1_OC |= 0x6f                         //PWM1ƽ��ռ�ձ�����λ
#define  PWM1_REX_7    PWM1_OC &= 0x0f; PWM1_OC |= 0x7f                         //PWM1ƽ��ռ�ձ�����λ



//PWM2
#define  PWM2_MD_DIS   PWM2_C &= 0xfc                                           //�ر�PWM2
#define  PWM2_MD_EN    PWM2_C &= 0xfc;    PWM2_C |= 0x01                        //ʹ��PWM2

#define  PWM2_TMR0_S   PWM2_C &= 0xf3                                           //PWM2����ʱ��Ϊ��ʱ��0
#define  PWM2_TMR1_S   PWM2_C &= 0xf3;PWM2_C |= 0x04                            //PWM2����ʱ��Ϊ��ʱ��1
#define  PWM2_TMR2_S   PWM2_C &= 0xf3;PWM2_C |= 0x08                            //PWM2����ʱ��Ϊ��ʱ��2
#define  PWM2_TMR3_S   PWM2_C |= 0x0c                                           //PWM2����ʱ��Ϊ��ʱ��3

#define  PWM2_EDG_MD   PWM2_C &= 0xcf                                           //PWM2���ض���ģʽ
#define  PWM2_MID_MD   PWM2_C &= 0xcf;PWM2_C |= 0x10                            //PWM2���Ķ���ģʽ

#define  PWM2_STP_DIS     PWM2_C &= 0x3f                                        //PWM2  �ر�ɲ������
#define  PWM2_STP_LV      PWM2_C &= 0x3f;PWM2_C |= 0x40                         //PWM2  STP ���ö˿�����͵�ƽɲ��
#define  PWM2_STP_CMP_LV  PWM2_C &= 0x3f;PWM2_C |= 0x80                         //PWM2  �Ƚ��������ɲ��
#define  PWM2_STP_SOFT    PWM2_C |= 0xc0                                        //PWM2  ���ɲ����д��11����������ɲ��״̬��


#define  PWM2_CH0_H_L  PWM2_OC &= 0xfe                                          //PWM20 ƥ���ǰ���ֵ1��ƥ�������0
#define  PWM2_CH0_L_H  PWM2_OC |= 0x01                                          //PWM20 ƥ���ǰ���ֵ0��ƥ�������1

#define  PWM2_CH1_H_L  PWM2_OC &= 0xfd                                          //PWM21 ƥ���ǰ���ֵ1��ƥ�������0
#define  PWM2_CH1_L_H  PWM2_OC |= 0x02                                          //PWM21 ƥ���ǰ���ֵ0��ƥ�������1

#define  PWM2_CH0_T_L  PWM2_OC &= 0xfb                                          //PWM20 ��ʼ����͵�ƽ
#define  PWM2_CH0_T_H  PWM2_OC |= 0x04                                          //PWM20 ��ʼ����ߵ�ƽ

#define  PWM2_CH1_T_L  PWM2_OC &= 0xf7                                          //PWM21 ��ʼ����͵�ƽ
#define  PWM2_CH1_T_H  PWM2_OC |= 0x08                                          //PWM21 ��ʼ����ߵ�ƽ

#define  PWM2_REX_0    PWM2_OC &= 0x0f                                          //PWM2ƽ��ռ�ձ�����λ
#define  PWM2_REX_1    PWM2_OC &= 0x0f; PWM2_OC |= 0x1f                         //PWM2ƽ��ռ�ձ�����λ
#define  PWM2_REX_2    PWM2_OC &= 0x0f; PWM2_OC |= 0x2f                         //PWM2ƽ��ռ�ձ�����λ
#define  PWM2_REX_3    PWM2_OC &= 0x0f; PWM2_OC |= 0x3f                         //PWM2ƽ��ռ�ձ�����λ
#define  PWM2_REX_4    PWM2_OC &= 0x0f; PWM2_OC |= 0x4f                         //PWM2ƽ��ռ�ձ�����λ
#define  PWM2_REX_5    PWM2_OC &= 0x0f; PWM2_OC |= 0x5f                         //PWM2ƽ��ռ�ձ�����λ
#define  PWM2_REX_6    PWM2_OC &= 0x0f; PWM2_OC |= 0x6f                         //PWM2ƽ��ռ�ձ�����λ
#define  PWM2_REX_7    PWM2_OC &= 0x0f; PWM2_OC |= 0x7f                         //PWM2ƽ��ռ�ձ�����λ

//SPI
#define  SPI_CLK_DIV2       SPI_C0 &= 0xF8                                      //SPI��Ƶ����2   ��Ƶ
#define  SPI_CLK_DIV4       SPI_C0 &= 0xF8;SPI_C0 |= 0x01                       //SPI��Ƶ����4   ��Ƶ
#define  SPI_CLK_DIV8       SPI_C0 &= 0xF8;SPI_C0 |= 0x02                       //SPI��Ƶ����8   ��Ƶ
#define  SPI_CLK_DIV16      SPI_C0 &= 0xF8;SPI_C0 |= 0x03                       //SPI��Ƶ����16  ��Ƶ
#define  SPI_CLK_DIV32      SPI_C0 &= 0xF8;SPI_C0 |= 0x04                       //SPI��Ƶ����32  ��Ƶ
#define  SPI_CLK_DIV64      SPI_C0 &= 0xF8;SPI_C0 |= 0x05                       //SPI��Ƶ����64  ��Ƶ
#define  SPI_CLK_DIV128     SPI_C0 &= 0xF8;SPI_C0 |= 0x06                       //SPI��Ƶ����128 ��Ƶ

#define  SPI_DIR_MSB        SPI_C0 &= 0xF7                                      //SPI�����ȷ���MSBλ�Ĵ��䷽ʽ
#define  SPI_DIR_LSB        SPI_C0 |= 0x08                                      //SPI�����ȷ���LSBλ�Ĵ��䷽ʽ
    
#define  SPI_CHPA_F         SPI_C0 &= 0xEF                                      //SPI���ݲ�����ʽ SCK ���ڵĵ�һ���زɼ�����
#define  SPI_CHPA_S         SPI_C0 |= 0x10                                      //SPI���ݲ�����ʽ SCK ���ڵĵڶ����زɼ�����

#define  SPI_CHOL_L         SPI_C0 &= 0xDF                                      //SPI�ܽſ���״̬ ����״̬��SCK ����0
#define  SPI_CHOL_H         SPI_C0 |= 0x20                                      //SPI�ܽſ���״̬ ����״̬��SCK ����1

#define  SPI_SSD_EN         SPI_C0 &= 0xBF                                      //SPI��SS �������λ  Ƭѡʹ��
#define  SPI_SSD_DIS        SPI_C0 |= 0x40                                      //SPI��SS �������λ  �ر�Ƭѡ

#define  SPI_SSC_SSPAD      SPI_C0 &= 0x7F                                      //SPI��SS ʹ�ܿ���λ  SS �ܽ���Ч
#define  SPI_SSC_SOFT       SPI_C0 |= 0x80                                      //SPI��SS ʹ�ܿ���λ  Ƭѡ�ź��������,��SPI_SSD ����

#define  SPI_EN             SPI_C1 |= 0x80                                      //SPIʹ�ܿ���λ ʹ��SPI����
#define  SPI_DIS            SPI_C1 &= 0xEF                                      //SPIʹ�ܿ���λ ��ֹSPI����

#define  SPI_M              SPI_C1 &= 0xBF                                      //SPI����ģʽ  ����ģʽ
#define  SPI_S              SPI_C1 |= 0x4F                                      //SPI����ģʽ  �ӻ�ģʽ

#define  SPI_WOL_CLR        SPI_C1 &= 0xFD                                      //SPI ��д��ͻ�������0
#define  SPI_RSSP_CLR       SPI_C1 &= 0xFE                                      //SPI �޽�������������0

//iic SCL ��SDA �����˲�ʱ�䣨Ҫ��ԶС�ڲ������趨��ʱ�����ڣ�
#define   IIC_FLT_1         IIC_C0 &= 0x0F                                      //�˲�ʱ��Tflt = 1  / Fsysclk
#define   IIC_FLT_2         IIC_C0 &= 0x0F;     IIC_C0 |= 0x10                  //�˲�ʱ��Tflt = 2  / Fsysclk
#define   IIC_FLT_3         IIC_C0 &= 0x0F;     IIC_C0 |= 0x20                  //�˲�ʱ��Tflt = 3  / Fsysclk
#define   IIC_FLT_4         IIC_C0 &= 0x0F;     IIC_C0 |= 0x30                  //�˲�ʱ��Tflt = 4  / Fsysclk
#define   IIC_FLT_5         IIC_C0 &= 0x0F;     IIC_C0 |= 0x40                  //�˲�ʱ��Tflt = 5  / Fsysclk
#define   IIC_FLT_6         IIC_C0 &= 0x0F;     IIC_C0 |= 0x50                  //�˲�ʱ��Tflt = 6  / Fsysclk
#define   IIC_FLT_7         IIC_C0 &= 0x0F;     IIC_C0 |= 0x60                  //�˲�ʱ��Tflt = 7  / Fsysclk
#define   IIC_FLT_8         IIC_C0 &= 0x0F;     IIC_C0 |= 0x70                  //�˲�ʱ��Tflt = 8  / Fsysclk
#define   IIC_FLT_9         IIC_C0 &= 0x0F;     IIC_C0 |= 0x80                  //�˲�ʱ��Tflt = 9  / Fsysclk
#define   IIC_FLT_10        IIC_C0 &= 0x0F;     IIC_C0 |= 0x90                  //�˲�ʱ��Tflt = 10 / Fsysclk
#define   IIC_FLT_11        IIC_C0 &= 0x0F;     IIC_C0 |= 0xa0                  //�˲�ʱ��Tflt = 11 / Fsysclk
#define   IIC_FLT_12        IIC_C0 &= 0x0F;     IIC_C0 |= 0xb0                  //�˲�ʱ��Tflt = 12 / Fsysclk
#define   IIC_FLT_13        IIC_C0 &= 0x0F;     IIC_C0 |= 0xc0                  //�˲�ʱ��Tflt = 13 / Fsysclk
#define   IIC_FLT_14        IIC_C0 &= 0x0F;     IIC_C0 |= 0xd0                  //�˲�ʱ��Tflt = 14 / Fsysclk
#define   IIC_FLT_15        IIC_C0 &= 0x0F;     IIC_C0 |= 0xe0                  //�˲�ʱ��Tflt = 15 / Fsysclk
#define   IIC_FLT_16        IIC_C0 &= 0x0F;     IIC_C0 |= 0xf0                  //�˲�ʱ��Tflt = 16 / Fsysclk

//IIC λ�ж�ģʽѡ��λ
#define   IIC_SSINT_EN      IIC_C0 &= 0xf7      // START ��STOP λ�����жϣ����1 ���ֽڵĽ��ջ��Ͳ����ж�
#define   IIC_SSINT_DIS     IIC_C0 |= 0x08      // START ��STOP λ�������жϣ����1 ���ֽڵĽ��ջ��Ͳ����ж�

//IIC �ȴ�����ʹ��λ
#define   IIC_WAIT_EN       IIC_C0 |= 0x04      // ʹ��IIC�ȴ�����
#define   IIC_WAIT_DIS      IIC_C0 &= 0xFB      // �ر�IIC�ȴ�����
//IIC ��/��ģʽѡ��λ
#define   IIC_M_MD          IIC_C0 &= 0xfD      // IIC����Ϊ����ģʽ
#define   IIC_S_MD          IIC_C0 |= 0x06      // IIC����Ϊ�Ӷ�ģʽ����ʹ��IIC�ȴ�����

//IIC ʹ��λ
#define   IIC_DIS           IIC_C0 &= 0xfE      // ��ֹIIC����
#define   IIC_EN            IIC_C0 |= 0x01      // ʹ��IIC����

//#define   IIC_START_TG      IIC_C1 |= 0x04;     while((IIC_C1&0x04)==0x04){}
//#define   IIC_STOP_TG       IIC_C1 |= 0x08;     while((IIC_C1&0x08)==0x08){}

// ACK λ����ѡ��λ
#define   IIC_ACK_TG        IIC_C1 &= 0xFE      // IIC����ACK
#define   IIC_NACK_TG       IIC_C1 |= 0x01      // IIC����NACK

//�ӻ��ȴ��ͷ�λ������IIC_MD=1 ����WTEN=1 ʱ�����壩
#define   IIC_WAIT_CLR      IIC_C1 |= 0x02      // ��1 �ͷŴӻ��ȴ�״̬�������һ�ֽڴ���ʱ��Ӳ���Զ����㣩

//IIC ��ʱʱ��
#define   IIC_OV_DIS        IIC_TOC = 0x00      //IIC��ʱʱ�� 0 
#define   IIC_OV_D64        IIC_TOC = 0x80      //IIC��ʱʱ�� 64    / Fsysclk
#define   IIC_OV_D128       IIC_TOC = 0x81      //IIC��ʱʱ�� 128   / Fsysclk
#define   IIC_OV_D256       IIC_TOC = 0x83      //IIC��ʱʱ�� 256   / Fsysclk
#define   IIC_OV_D512       IIC_TOC = 0x87      //IIC��ʱʱ�� 512   / Fsysclk
#define   IIC_OV_D1024      IIC_TOC = 0x8f      //IIC��ʱʱ�� 1024  / Fsysclk
#define   IIC_OV_D2048      IIC_TOC = 0x9f      //IIC��ʱʱ�� 2048  / Fsysclk
#define   IIC_OV_D4096      IIC_TOC = 0xaf      //IIC��ʱʱ�� 4096  / Fsysclk
#define   IIC_OV_D8192      IIC_TOC = 0xbf      //IIC��ʱʱ�� 8192  / Fsysclk

//UART0 TX
#define  UART0_TX_DIS       UART0_TXC = 0x00    //UART0���͹��ܹر�
#define  UART0_TX8_1S       UART0_TXC = 0x02    //UART0����ģʽΪ 8λ���ݣ�1λSTOPλ
#define  UART0_TX8_2S       UART0_TXC = 0x0a    //UART0����ģʽΪ 8λ���ݣ�2λSTOPλ

#define  UART0_TX9_1S_ODD   UART0_TXC = 0x06    //UART0����ģʽΪ 9λ���ݣ�1λSTOPλ
#define  UART0_TX9_2S_ODD   UART0_TXC = 0x0e    //UART0����ģʽΪ 9λ���ݣ�2λSTOPλ

#define  UART0_TX9_1S_EVEN  UART0_TXC = 0x16    //UART0����ģʽΪ 9λ���ݣ�1λSTOPλ����9λΪżУ��
#define  UART0_TX9_2S_EVEN  UART0_TXC = 0x1e    //UART0����ģʽΪ 9λ���ݣ�2λSTOPλ����9λΪżУ��

#define  UART0_TX9_1S_D0    UART0_TXC = 0x26    //UART0����ģʽΪ 9λ���ݣ�1λSTOPλ����9λΪ����0
#define  UART0_TX9_2S_D0    UART0_TXC = 0x2e    //UART0����ģʽΪ 9λ���ݣ�2λSTOPλ����9λΪ����0

#define  UART0_TX9_1S_D1    UART0_TXC = 0x26    //UART0����ģʽΪ 9λ���ݣ�1λSTOPλ����9λΪ����1
#define  UART0_TX9_2S_D1    UART0_TXC = 0x2e    //UART0����ģʽΪ 9λ���ݣ�2λSTOPλ����9λΪ����1

//UART0 RX
#define  UART0_RX_DIS       UART0_RXC = 0x00    //UART0���չ��ܹر�

#define  UART0_RX8          UART0_RXC = 0x01    //UART0��У�飬ʹ��8 λ���ݽ��գ���Ӱ����żУ���־PERR��
#define  UART0_RX9_D        UART0_RXC = 0x02    //UART0��У�飬ʹ��9 λ���ݽ��գ���Ӱ����żУ���־PERR��
#define  UART0_RX9_ODD      UART0_RXC = 0x03    //UART0��У�飬ʹ��9 λ���ݽ��գ�Ӱ����żУ���־PERR��
#define  UART0_RX9_EVEN     UART0_RXC = 0x0b    //UART0żУ�飬ʹ��8 λ���ݽ��գ���Ӱ����żУ���־PERR��

//UART1 TX
#define  UART1_TX_DIS       UART1_TXC = 0x00    //UART1���͹��ܹر�
#define  UART1_TX8_1S       UART1_TXC = 0x02    //UART1����ģʽΪ 8λ���ݣ�1λSTOPλ
#define  UART1_TX8_2S       UART1_TXC = 0x0a    //UART1����ģʽΪ 8λ���ݣ�2λSTOPλ

#define  UART1_TX9_1S_ODD   UART1_TXC = 0x06    //UART1����ģʽΪ 9λ���ݣ�1λSTOPλ
#define  UART1_TX9_2S_ODD   UART1_TXC = 0x0e    //UART1����ģʽΪ 9λ���ݣ�2λSTOPλ

#define  UART1_TX9_1S_EVEN  UART1_TXC = 0x16    //UART1����ģʽΪ 9λ���ݣ�1λSTOPλ����9λΪżУ��
#define  UART1_TX9_2S_EVEN  UART1_TXC = 0x1e    //UART1����ģʽΪ 9λ���ݣ�2λSTOPλ����9λΪżУ��

#define  UART1_TX9_1S_D0    UART1_TXC = 0x26    //UART1����ģʽΪ 9λ���ݣ�1λSTOPλ����9λΪ����0
#define  UART1_TX9_2S_D0    UART1_TXC = 0x2e    //UART1����ģʽΪ 9λ���ݣ�2λSTOPλ����9λΪ����0

#define  UART1_TX9_1S_D1    UART1_TXC = 0x26    //UART1����ģʽΪ 9λ���ݣ�1λSTOPλ����9λΪ����1
#define  UART1_TX9_2S_D1    UART1_TXC = 0x2e    //UART1����ģʽΪ 9λ���ݣ�2λSTOPλ����9λΪ����1

//UART RX                                       
#define  UART1_RX_DIS       UART1_RXC = 0x00    //UART1���չ��ܹر�

#define  UART1_RX8          UART1_RXC = 0x01    //UART1��У�飬ʹ��8 λ���ݽ��գ���Ӱ����żУ���־PERR��
#define  UART1_RX9_D        UART1_RXC = 0x02    //UART1��У�飬ʹ��9 λ���ݽ��գ���Ӱ����żУ���־PERR��
#define  UART1_RX9_ODD      UART1_RXC = 0x03    //UART1��У�飬ʹ��9 λ���ݽ��գ�Ӱ����żУ���־PERR��
#define  UART1_RX9_EVEN     UART1_RXC = 0x0b    //UART1żУ�飬ʹ��8 λ���ݽ��գ���Ӱ����żУ���־PERR��

//ADC
#define    ADC_EN           ADC_C0 |= 0x80                      //ʹ��ADC����
#define    ADC_DIS          ADC_C0 &= 0x7f                      //��ֹADC����
#define    ADC_SOFT_TG      ADC_C0 |= 0x80; ADC_C0 |= 0x40      //�������ADCת��������ADCת��
#define    ADC_TMR2_TG      ADC_C0 &= 0xC0; ADC_C0 |= 0x10      //��ʱ��2����ƥ��ADC_TR_R0ֵ�󴥷�ADCת��
#define    ADC_TMR2_PWM_TG  ADC_C0 |= 0x20                      //TMR2 ����ֵƥ��ADC_TR_R0 ֵ�󴥷�ADC����PWM1_R0+ADC_TR_R0 ���ٴδ���ADC,�˴���ע�����������������Ʋ�Ҫ�����
//ADC ����ͨ��ѡ��λ
#define    ADC_P20_AN0      ADC_C0 &= 0xF0                      //����ADC����ͨ��ΪAN0     P20_ADCͨ��AN0 
#define    ADC_P21_AN1      ADC_C0 &= 0xF0; ADC_C0 |= 0x01      //����ADC����ͨ��ΪAN1     P21_ADCͨ��AN1 
#define    ADC_P22_AN2      ADC_C0 &= 0xF0; ADC_C0 |= 0x02      //����ADC����ͨ��ΪAN2     P22_ADCͨ��AN2 
#define    ADC_P23_AN3      ADC_C0 &= 0xF0; ADC_C0 |= 0x03      //����ADC����ͨ��ΪAN3     P23_ADCͨ��AN3 
#define    ADC_P34_AN4      ADC_C0 &= 0xF0; ADC_C0 |= 0x04      //����ADC����ͨ��ΪAN4     P34_ADCͨ��AN4 
#define    ADC_P35_AN5      ADC_C0 &= 0xF0; ADC_C0 |= 0x05      //����ADC����ͨ��ΪAN5     P35_ADCͨ��AN5 
#define    ADC_P36_AN6      ADC_C0 &= 0xF0; ADC_C0 |= 0x06      //����ADC����ͨ��ΪAN6     P36_ADCͨ��AN6 
#define    ADC_P37_AN7      ADC_C0 &= 0xF0; ADC_C0 |= 0x07      //����ADC����ͨ��ΪAN7     P37_ADCͨ��AN7 
#define    ADC_P24_AN8      ADC_C0 &= 0xF0; ADC_C0 |= 0x08      //����ADC����ͨ��ΪAN8     P24_ADCͨ��AN8 
#define    ADC_P03_AN9      ADC_C0 &= 0xF0; ADC_C0 |= 0x09      //����ADC����ͨ��ΪAN9     P03_ADCͨ��AN9 
#define    ADC_P10_AN10     ADC_C0 &= 0xF0; ADC_C0 |= 0x0A      //����ADC����ͨ��ΪAN10    P10_ADCͨ��AN10
#define    ADC_VDD_DIV4     ADC_C0 &= 0xF0; ADC_C0 |= 0x0B      //����ADC����ͨ��Ϊ�ڲ�VDD/4
#define    ADC_CH_DIS       ADC_C0 |= 0x0F                      //�ر�ADC����ͨ��
//ADC �ο���ѹ����
#define    ADC_VREF_DIS     ADC_C1 &= 0x0F                                      //�ر��ڲ��ο���ѹ
#define    ADC_RVDD_AVG1    ADC_C1 &= 0x0F;   ADC_C1 = 0x20; ADC_C2 = 0x0A      //�ο���ѹѡ���ڲ�VDD��1 ��ת��
#define    ADC_RVDD_AVG2    ADC_C1 &= 0x0F;   ADC_C1 = 0x20; ADC_C2 = 0x1A      //�ο���ѹѡ���ڲ�VDD��2 ��ת��ȡƽ��
#define    ADC_RVDD_AVG4    ADC_C1 &= 0x0F;   ADC_C1 = 0x20; ADC_C2 = 0x2A      //�ο���ѹѡ���ڲ�VDD��4 ��ת��ȡƽ��
#define    ADC_RVDD_AVG8    ADC_C1 &= 0x0F;   ADC_C1 = 0x20; ADC_C2 = 0x3A      //�ο���ѹѡ���ڲ�VDD��8 ��ת��ȡƽ��

#define    ADC_RADVP_AVG1   ADC_C1 &= 0x0F;   ADC_C1 |= 0x10; ADC_C2 = 0x0A     //�ο���ѹѡ���ⲿ���룬1 ��ת��
#define    ADC_RADVP_AVG2   ADC_C1 &= 0x0F;   ADC_C1 |= 0x10; ADC_C2 = 0x1A     //�ο���ѹѡ���ⲿ���룬2 ��ת��ȡƽ��
#define    ADC_RADVP_AVG4   ADC_C1 &= 0x0F;   ADC_C1 |= 0x10; ADC_C2 = 0x2A     //�ο���ѹѡ���ⲿ���룬4 ��ת��ȡƽ��
#define    ADC_RADVP_AVG8   ADC_C1 &= 0x0F;   ADC_C1 |= 0x10; ADC_C2 = 0x3A     //�ο���ѹѡ���ⲿ���룬8 ��ת��ȡƽ��

#define    ADC_RVREF25_AVG1 ADC_C1 &= 0x0F;   ADC_C1 |= 0x80; ADC_C2 = 0x0A; VREF_C = 0xEB  //�ο���ѹѡ���ڲ�2.5V��1 ��ת��
#define    ADC_RVREF25_AVG2 ADC_C1 &= 0x0F;   ADC_C1 |= 0x80; ADC_C2 = 0x1A; VREF_C = 0xEB  //�ο���ѹѡ���ڲ�2.5V��2 ��ת��ȡƽ��
#define    ADC_RVREF25_AVG4 ADC_C1 &= 0x0F;   ADC_C1 |= 0x80; ADC_C2 = 0x2A; VREF_C = 0xEB  //�ο���ѹѡ���ڲ�2.5V��4 ��ת��ȡƽ��
#define    ADC_RVREF25_AVG8 ADC_C1 &= 0x0F;   ADC_C1 |= 0x80; ADC_C2 = 0x3A; VREF_C = 0xEB  //�ο���ѹѡ���ڲ�2.5V��8 ��ת��ȡƽ��

#define    ADC_RVREF2048_AVG1 ADC_C1 &= 0x0F;   ADC_C1 |= 0x90; ADC_C2 = 0x0A; VREF_C = 0xEB//�ο���ѹѡ���ڲ�2.048V��1 ��ת��
#define    ADC_RVREF2048_AVG2 ADC_C1 &= 0x0F;   ADC_C1 |= 0x90; ADC_C2 = 0x1A; VREF_C = 0xEB//�ο���ѹѡ���ڲ�2.048V��2 ��ת��ȡƽ��
#define    ADC_RVREF2048_AVG4 ADC_C1 &= 0x0F;   ADC_C1 |= 0x90; ADC_C2 = 0x2A; VREF_C = 0xEB//�ο���ѹѡ���ڲ�2.048V��4 ��ת��ȡƽ��
#define    ADC_RVREF2048_AVG8 ADC_C1 &= 0x0F;   ADC_C1 |= 0x90; ADC_C2 = 0x3A; VREF_C = 0xEB//�ο���ѹѡ���ڲ�2.048V��8 ��ת��ȡƽ��

#define    ADC_RVREF1024_AVG1  ADC_C1 &= 0x0F;   ADC_C1 |= 0xA0; ADC_C2 = 0x0A;VREF_C = 0xEB//�ο���ѹѡ���ڲ�1.024V��1 ��ת��
#define    ADC_RVREF1024_AVG2  ADC_C1 &= 0x0F;   ADC_C1 |= 0xA0; ADC_C2 = 0x1A;VREF_C = 0xEB//�ο���ѹѡ���ڲ�1.024V��2 ��ת��ȡƽ��
#define    ADC_RVREF1024_AVG4  ADC_C1 &= 0x0F;   ADC_C1 |= 0xA0; ADC_C2 = 0x2A;VREF_C = 0xEB//�ο���ѹѡ���ڲ�1.024V��4 ��ת��ȡƽ��
#define    ADC_RVREF1024_AVG8  ADC_C1 &= 0x0F;   ADC_C1 |= 0xA0; ADC_C2 = 0x3A;VREF_C = 0xEB//�ο���ѹѡ���ڲ�1.024V��8 ��ת��ȡƽ��

#define    ADC_RVREF15_AVG1  ADC_C1 &= 0x0F;   ADC_C1 |= 0xC0; ADC_C2 = 0x0A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�1.5V��1 ��ת��
#define    ADC_RVREF15_AVG2  ADC_C1 &= 0x0F;   ADC_C1 |= 0xC0; ADC_C2 = 0x1A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�1.5V��2 ��ת��ȡƽ��
#define    ADC_RVREF15_AVG4  ADC_C1 &= 0x0F;   ADC_C1 |= 0xC0; ADC_C2 = 0x2A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�1.5V��4 ��ת��ȡƽ��
#define    ADC_RVREF15_AVG8  ADC_C1 &= 0x0F;   ADC_C1 |= 0xC0; ADC_C2 = 0x3A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�1.5V��8 ��ת��ȡƽ��

#define    ADC_RVREF12_AVG1  ADC_C1 &= 0x0F;   ADC_C1 |= 0xD0; ADC_C2 = 0x0A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�1.2V��1 ��ת��
#define    ADC_RVREF12_AVG2  ADC_C1 &= 0x0F;   ADC_C1 |= 0xD0; ADC_C2 = 0x1A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�1.2V��2 ��ת��ȡƽ��
#define    ADC_RVREF12_AVG4  ADC_C1 &= 0x0F;   ADC_C1 |= 0xD0; ADC_C2 = 0x2A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�1.2V��4 ��ת��ȡƽ��
#define    ADC_RVREF12_AVG8  ADC_C1 &= 0x0F;   ADC_C1 |= 0xD0; ADC_C2 = 0x3A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�1.2V��8 ��ת��ȡƽ��

#define    ADC_RVREF05_AVG1  ADC_C1 &= 0x0F;   ADC_C1 |= 0xE0; ADC_C2 = 0x0A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�0.5V��1 ��ת��
#define    ADC_RVREF05_AVG2  ADC_C1 &= 0x0F;   ADC_C1 |= 0xE0; ADC_C2 = 0x1A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�0.5V��2 ��ת��ȡƽ��
#define    ADC_RVREF05_AVG4  ADC_C1 &= 0x0F;   ADC_C1 |= 0xE0; ADC_C2 = 0x2A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�0.5V��4 ��ת��ȡƽ��
#define    ADC_RVREF05_AVG8  ADC_C1 &= 0x0F;   ADC_C1 |= 0xE0; ADC_C2 = 0x3A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�0.5V��8 ��ת��ȡƽ��
  
#define    ADC_RVREF02_AVG1  ADC_C1 &= 0x0F;   ADC_C1 |= 0xF0; ADC_C2 = 0x0A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�0.2V��1 ��ת��
#define    ADC_RVREF02_AVG2  ADC_C1 &= 0x0F;   ADC_C1 |= 0xF0; ADC_C2 = 0x1A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�0.2V��2 ��ת��ȡƽ��
#define    ADC_RVREF02_AVG4  ADC_C1 &= 0x0F;   ADC_C1 |= 0xF0; ADC_C2 = 0x2A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�0.2V��4 ��ת��ȡƽ��
#define    ADC_RVREF02_AVG8  ADC_C1 &= 0x0F;   ADC_C1 |= 0xF0; ADC_C2 = 0x3A;VREF_C = 0xEB  //�ο���ѹѡ���ڲ�0.2V��8 ��ת��ȡƽ��
   
//VREF
#define    VREF_EN     VREF_C = 0xEB                // ʹ���ڲ��ο���ѹģ��
#define    VREF_DIS    VREF_C = 0x00                // �ر��ڲ��ο���ѹģ��

//�͵�ѹ���ģ��LVD
#define    LVD_EN      LVD_C |= 0x80                // ʹ��LVD�ڲ��͵�ѹ���ģ��
#define    LVD_DIS     LVD_C &= 0x7f                // ��ֹLVD�ڲ��͵�ѹ���ģ��
//LVD �ж�ģʽѡ��λ   
#define    LVD_IM_H    LVD_C |= 0x40                // ������ѹ�ɸ��ڱȽ���ֵ����LVD �ж�
#define    LVD_IM_L    LVD_C &= 0xBf                // ������ѹ�ɵ��ڱȽ���ֵ����LVD �ж�
//LVD �˲�ѡ��λ 
#define    LVD_FLT_EN  LVD_C |= 0x20                // LVD�˲�ѡ��7��LVD����ʱ��
#define    LVD_FLT_DIS LVD_C &= 0xdf                // �ر��˲���
//LVD ����ʱ��ѡ��λ   
#define    LVD_CLK_LRC   LVD_C |= 0x10              // LVDʱ��Ϊ�ڲ���Ƶʱ��LRC
#define    LVD_CLK_SYS   LVD_C &= 0xef              // LVDʱ��Ϊϵͳʱ��SYS_CLK
//������ѹѡ��λ  
#define    LVD_LVD_IN_1P2 LVD_C |= 0x08             // LVD���LVDIN���ùܽ�����ĵ�ѹֵ���Ƚ���ֵ��ѹ�̶�Ϊ1.2V��
#define    LVD_LVD_IN_VDD LVD_C |= 0xF7             // LVD���VDD�ĵ�ѹֵ

//LVD��ֵ��ѹѡ��λ�������ڼ��VDD��,�жϲ��ɻ��ѵ͹���ģʽ
#define    LVD_VDD_1P8  LVD_C &= 0xF0               //LVD��ֵ��ѹ����Ϊ1.8V
#define    LVD_VDD_2P2  LVD_C &= 0xF0;LVD_C |= 0x01 //LVD��ֵ��ѹ����Ϊ2.2V
#define    LVD_VDD_2P6  LVD_C &= 0xF0;LVD_C |= 0x02 //LVD��ֵ��ѹ����Ϊ2.6V
#define    LVD_VDD_3P0  LVD_C &= 0xF0;LVD_C |= 0x03 //LVD��ֵ��ѹ����Ϊ3.0V
#define    LVD_VDD_3P4  LVD_C &= 0xF0;LVD_C |= 0x04 //LVD��ֵ��ѹ����Ϊ3.4V
#define    LVD_VDD_3P8  LVD_C &= 0xF0;LVD_C |= 0x05 //LVD��ֵ��ѹ����Ϊ3.8V
#define    LVD_VDD_4P2  LVD_C &= 0xF0;LVD_C |= 0x06 //LVD��ֵ��ѹ����Ϊ4.2V
#define    LVD_VDD_4P6  LVD_C &= 0xF0;LVD_C |= 0x07 //LVD��ֵ��ѹ����Ϊ4.6V

#endif
