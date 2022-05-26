//******************************************************************************
// 版    权 : 深圳市高科润电子有限公司所有(2030)
// 文件名称 : GCE_MCU_Config.h
// 功能描述 : MCU配置文件
// 作    者 : 周智伟
// 创建日期 : 2021.5.12
// 版    本 : V0.0.0
// 变更记录 : V0.0.1/2021.6.16/周智伟
//            1.首次创建
//******************************************************************************
#ifndef __GCE_MCU_CONFIG_H__
#define __GCE_MCU_CONFIG_H__

#define _CORE_  			_CORE_C51 // 目前只有_CORE_C51和_CORE_Other两种选项
//#define _CORE_  			_CORE_Other // 目前只有_CORE_C51和_CORE_Other两种选项

//******************************************************************************
//                                 macro definitions
//******************************************************************************
//------------------------------------------------------------------------------
// MCU资源使用情况(GCE_DISABLE-未用,GCE_ENABLE-使用)
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
#define GCE_LVD_EN          GCE_DISABLE // 低压检测功能

//------------------------------------------------------------------------------
// 供电电压,必须填写正确.
//#define VDD_VOLT_VALUE          VDD_VOLT_3D3V// 3.3V
#define VDD_VOLT_VALUE          VDD_VOLT_5V //5V
//------------------------------------------------------------------------------
// 主频时钟类型
#define SYS_CLK_TYPE            SYS_CLK_HSI // 内部主频
#define SYS_CLK_HSE_VALUE       (16UL*MHz)    // 16MHz(选择外部晶振时,需要用户填晶振值)

//------------------------------------------------------------------------------
#define WDT_TIME_VALUE (WDT_TIME_1000mS)  //设置看门狗复位时间，只允许选取TE_WDT_TIME_TYPE枚举变量
//------------------------------------------------------------------------------
// LVD低电压检测配置
#define LVD_VOLT_VALUE          LVD_VOLT_3_8V // 值为TE_LVD_VOLT_TYPE类型
//SYS_TIME_125US/SYS_TIME_250US/SYS_TIME_500US/SYS_TIME_1MS
//设置定时时间，只允许选取TE_SYS_TIME_TYPE枚举变量
#define SYS_TIME_VALUE        SYS_TIME_125US
#define  SYSCLK_EN  GCE_DISABLE
//------------------------------------------------------------------------------
//PWM0-----------------------------------
#define PWM0_FREQ_VALUE PWM_FREQ_20K//1KHZ// 值为TE_PWM_FREQ_TYPE类型
#define PWM00_POLARITY  PWM_POLARITY_L_H
#define PWM10_POLARITY  PWM_POLARITY_H_L
#define PWM0_DT_TIME    10
//PWM1-----------------------------------
#define PWM1_FREQ_VALUE PWM_FREQ_2K //2KHZ// 值为TE_PWM_FREQ_TYPE类型
#define PWM01_POLARITY  PWM_POLARITY_L_H
#define PWM11_POLARITY  PWM_POLARITY_L_H
//------------------------------------------------------------------------------
//PWM2-----------------------------------
#define PWM2_FREQ_VALUE PWM_FREQ_4K //2KHZ// 值为TE_PWM_FREQ_TYPE类型
#define PWM02_POLARITY  PWM_POLARITY_L_H
#define PWM12_POLARITY  PWM_POLARITY_L_H
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Uart波特率配置
#define UART0_BAUDRATE_VALUE     UART_BAUDRATE_9600 // 值为TE_UART_BAUDRATE_TYPE类型
#define UART1_BAUDRATE_VALUE     UART_BAUDRATE_9600 // 值为TE_UART_BAUDRATE_TYPE类型


#endif////__GCE_MCU_CONFIG_H__