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
#ifndef __GCE_MCU_INIT_H
#define __GCE_MCU_INIT_H

extern void ADC_Init(void);

#define MHz 1000000
#define KHz 1000

#define _CORE_C51		0
#define _CORE_Other		1

#if (_CORE_ == _CORE_C51)
#define GCE_CONST  code
#define GCE_XDATA  xdata
#define GCE_IDATA  idata
#else
#define GCE_CONST  const
#define GCE_XDATA
#define GCE_IDATA
#endif

//------------------------------------------------------------------------------
// VDD电压
#define VDD_VOLT_3D3V   3300 // 3.3V系统
#define VDD_VOLT_5V     5000 // 5V系统

//------------------------------------------------------------------------------
// 主频时钟类型
#define SYS_CLK_HSI     0
#define SYS_CLK_HSE     1

#define SYS_CLK_HSI_16MHz     16
#define SYS_CLK_HSI_8MHz      8

// 根据主频类型选晶振值
#if (SYS_CLK_TYPE == SYS_CLK_HSI)
    #if (VDD_VOLT_VALUE == VDD_VOLT_5V) // 不同电压,支持不同频率,可修改对应频率值.
        #define SYS_CLK_VALUE   (SYS_CLK_HSI_8MHz * MHz)
    #else //if(VDD_VOLT_VALUE == VDD_VOLT_3D3V)
        #define SYS_CLK_VALUE   (SYS_CLK_HSI_8MHz * MHz)
    #endif
#else
    #define SYS_CLK_VALUE   SYS_CLK_HSE_VALUE
#endif

// 看门狗时间配置
typedef enum
{
    WDT_TIME_2560mS  = 0,
    WDT_TIME_2000mS  = 1,
    WDT_TIME_1500mS  = 2,
    WDT_TIME_1000mS  = 3,
    WDT_TIME_900mS  = 4,
    WDT_TIME_800mS  = 5,
    WDT_TIME_700mS  = 6,
    WDT_TIME_600mS  = 7,
    WDT_TIME_500mS  = 8,
    WDT_TIME_400mS  = 9,
    WDT_TIME_300mS  = 0xA,
    WDT_TIME_200mS  = 0xB,
    WDT_TIME_100mS  = 0xC,
    WDT_TIME_60mS   = 0xD,
    WDT_TIME_30mS  = 0xE,
    WDT_TIME_20mS  = 0xF,
}TE_WDT_TIME_TYPE;

//------------------------------------------------------------------------------
// 主程序基准时间选择(默认1ms,使用其他时间,需评审)
typedef enum
{
    SYS_TIME_125US = 125,  // 周期125uS
    SYS_TIME_250US = 250,  // 周期250uS
    SYS_TIME_500US = 500,  // 周期500uS
    SYS_TIME_1MS   = 1000,  // 周期1mS
}TE_SYS_TIME_TYPE;
#define  SYSCLK_CNT  (SYS_TIME_1MS/SYS_TIME_VALUE)

//ADC---------------------------------
enum{
	ADC_NUM_AN0=0x00, //通道0
	ADC_NUM_AN1=0x01, //通道1
	ADC_NUM_AN2=0x02, //通道2
	ADC_NUM_AN3=0x03, //通道3
	ADC_NUM_AN4=0x04, //通道4
	ADC_NUM_AN5=0x05, //通道5
	ADC_NUM_AN6=0x06, //通道6
	ADC_NUM_AN7=0x07, //通道7
	ADC_NUM_AN8=0x08, //1/VDD
	ADC_NUM_AN9=0x09, //通道9
	ADC_NUM_AN10=0x0A, //通道10
	ADC_NUM_AN11=0x0B, //通道11
};

// Uart波特率配置(如下列出常用波特率,如不满足,可新增)
typedef enum
{
    UART_BAUDRATE_2400   = 2400,   // 波特率 2400
    UART_BAUDRATE_4800   = 4800,   // 波特率 4800
    UART_BAUDRATE_9600   = 9600,   // 波特率 9600
    UART_BAUDRATE_19200   = 19200,   // 波特率 19200
    UART_BAUDRATE_38400   = 38400,   // 波特率 38400
    UART_BAUDRATE_57600   = 57600,   // 波特率 57600
    //UART_BAUDRATE_115200 = 115200,  // 波特率 115200
}TE_UART_BAUDRATE_TYPE;
#define UART_BAUDRATE_115200 115200  // 波特率 115200


// PWM频率配置(如下列出常用频率,如不满足,可新增)
typedef enum
{
	PWM_FREQ_1K=1000, //1K
	PWM_FREQ_2K=2000, //2K
	PWM_FREQ_4K=4000, //4K
	PWM_FREQ_8K=8000, //8K
	PWM_FREQ_16K=16000, //16K
	PWM_FREQ_20K=20000, //20K
}TE_PWM_FREQ_TYPE;
#define PWM0_PERIOD_VALUE        (UI16)((SYS_CLK_VALUE>>1) / PWM0_FREQ_VALUE) // PWM0周期值
#define PWM1_PERIOD_VALUE        (UI16)((SYS_CLK_VALUE >> 4) / PWM1_FREQ_VALUE) // PWM1周期值
#define PWM2_PERIOD_VALUE        (UI16)((SYS_CLK_VALUE >> 4) / PWM1_FREQ_VALUE) // PWM2周期值
//------------------------------------------------------------------------------
// PWM输出极性POLARITY
#define PWM_POLARITY_L_H  0  //先低后高
#define PWM_POLARITY_H_L  !PWM_POLARITY_L_H  //先高后低
//------------------------------------------------------------------------------
// LVD低电压检测配置
typedef enum
{
    LVD_VOLT_1_8V = 0,   // LVD低电压检测阈值1.8V
    LVD_VOLT_2_2V = 1,   // LVD低电压检测阈值2.2V
    LVD_VOLT_2_6V = 2,   // LVD低电压检测阈值2.6V
    LVD_VOLT_3_0V = 3,   // LVD低电压检测阈值3.0V
    LVD_VOLT_3_4V = 4,   // LVD低电压检测阈值3.4V
    LVD_VOLT_3_8V = 5,   // LVD低电压检测阈值3.8V
    LVD_VOLT_4_2V = 6,   // LVD低电压检测阈值4.2V
    LVD_VOLT_4_6V = 7,   // LVD低电压检测阈值4.6V
}TE_LVD_VOLT_TYPE;
//====================================================================================
void MCU_Initial(void);

#if(GCE_LOWPOWER_EN)
extern void MCU_Enter_Sleep(void);
#endif

#endif /* __GCE_MCU_INIT_H */

