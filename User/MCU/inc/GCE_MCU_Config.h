//******************************************************************************
// ��    Ȩ : �����и߿���������޹�˾����(2030)
// �ļ����� : GCE_MCU_Config.h
// �������� : MCU�����ļ�
// ��    �� : ����ΰ
// �������� : 2021.5.12
// ��    �� : V0.0.0
// �����¼ : V0.0.1/2021.6.16/����ΰ
//            1.�״δ���
//******************************************************************************
#ifndef __GCE_MCU_CONFIG_H__
#define __GCE_MCU_CONFIG_H__

#define _CORE_  			_CORE_C51 // Ŀǰֻ��_CORE_C51��_CORE_Other����ѡ��
//#define _CORE_  			_CORE_Other // Ŀǰֻ��_CORE_C51��_CORE_Other����ѡ��

//******************************************************************************
//                                 macro definitions
//******************************************************************************
//------------------------------------------------------------------------------
// MCU��Դʹ�����(GCE_DISABLE-δ��,GCE_ENABLE-ʹ��)
#define GCE_EEPROM_EN       GCE_DISABLE
#define GCE_TIMER0_IT_EN    GCE_ENABLE
#define GCE_EXT0_EN         GCE_ENABLE
#define GCE_EXT1_EN         GCE_ENABLE
#define GCE_ADC_EN          GCE_ENABLE
#define GCE_UART0_EN        GCE_DISABLE
#define GCE_UART1_EN        GCE_DISABLE
#define GCE_PRIORITY_EN     GCE_ENABLE
#define GCE_TIMER1_PWM0_EN  GCE_ENABLE
#define GCE_TIMER2_PWM1_EN  GCE_DISABLE
#define GCE_TK_EN           GCE_DISABLE
#define GCE_LOWPOWER_EN     GCE_ENABLE
#define GCE_LVD_EN          GCE_DISABLE // ��ѹ��⹦��

//------------------------------------------------------------------------------
// �����ѹ,������д��ȷ.
//#define VDD_VOLT_VALUE          VDD_VOLT_3D3V// 3.3V
#define VDD_VOLT_VALUE          VDD_VOLT_5V //5V
//------------------------------------------------------------------------------
// ��Ƶʱ������
#define SYS_CLK_TYPE            SYS_CLK_HSI // �ڲ���Ƶ
#define SYS_CLK_HSE_VALUE       (16UL*MHz)    // 16MHz(ѡ���ⲿ����ʱ,��Ҫ�û����ֵ)

//------------------------------------------------------------------------------
#define WDT_TIME_VALUE (WDT_TIME_1000mS)  //���ÿ��Ź���λʱ�䣬ֻ����ѡȡTE_WDT_TIME_TYPEö�ٱ���
//------------------------------------------------------------------------------
// LVD�͵�ѹ�������
#define LVD_VOLT_VALUE          LVD_VOLT_3_8V // ֵΪTE_LVD_VOLT_TYPE����
//SYS_TIME_125US/SYS_TIME_250US/SYS_TIME_500US/SYS_TIME_1MS
//���ö�ʱʱ�䣬ֻ����ѡȡTE_SYS_TIME_TYPEö�ٱ���
#define SYS_TIME_VALUE        SYS_TIME_125US
#define  SYSCLK_EN  GCE_DISABLE
//------------------------------------------------------------------------------
//PWM0-----------------------------------
#define PWM0_FREQ_VALUE PWM_FREQ_20K//1KHZ// ֵΪTE_PWM_FREQ_TYPE����
#define PWM00_POLARITY  PWM_POLARITY_L_H
#define PWM10_POLARITY  PWM_POLARITY_H_L
#define PWM0_DT_TIME    10
//PWM1-----------------------------------
#define PWM1_FREQ_VALUE PWM_FREQ_2K //2KHZ// ֵΪTE_PWM_FREQ_TYPE����
#define PWM01_POLARITY  PWM_POLARITY_L_H
#define PWM11_POLARITY  PWM_POLARITY_L_H
//------------------------------------------------------------------------------
//PWM2-----------------------------------
#define PWM2_FREQ_VALUE PWM_FREQ_4K //2KHZ// ֵΪTE_PWM_FREQ_TYPE����
#define PWM02_POLARITY  PWM_POLARITY_L_H
#define PWM12_POLARITY  PWM_POLARITY_L_H
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Uart����������
#define UART0_BAUDRATE_VALUE     UART_BAUDRATE_9600 // ֵΪTE_UART_BAUDRATE_TYPE����
#define UART1_BAUDRATE_VALUE     UART_BAUDRATE_9600 // ֵΪTE_UART_BAUDRATE_TYPE����


#endif////__GCE_MCU_CONFIG_H__