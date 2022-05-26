/*********************************************************
*文件名:	common.h
*作  者:	SINOMICON
*版  本:	V1.00
*日  期:	2019/10/20
*描  述:	公共头文件
*备  注:	通用数据类型和宏定义
**********************************************************/
#ifndef   __COMMON_H__
#define   __COMMON_H__

/* 定义数据类型 */
typedef unsigned char  uchar;	//无符号8位整型变量
typedef unsigned int   uint;	//无符号16位整型变量 
typedef unsigned long  ulong;   //无符号32位整型变量

typedef unsigned char  INT8U;   //无符号8位整型变量
typedef signed   char  INT8S;   //有符号8位整型变量
typedef unsigned int   INT16U;  //无符号16位整型变量 
typedef signed   int   INT16S;  //有符号16位整型变量
typedef unsigned long  INT32U;  //无符号32位整型变量
typedef signed   long  INT32S;	//有符号32位整型变量
typedef float          FP32;    //单精度浮点型变量 
typedef double         FP64;    //双精度浮点型变量

//system
#define  SystemReset    SYS_RST_FLAG = 0x08

//CLK
#define  HRC_EN         CLK_PR=0xA5;  CLK_C1 |= 0x01; CLK_PR=0x5a //使能内部高速振荡器HRC        
#define  HRC_DIS        CLK_PR=0xA5;  CLK_C1 &= 0xfe; CLK_PR=0x5a //禁止内部高速振荡器HRC
#define  XOSC_EN        CLK_PR=0xA5;  CLK_C1 |= 0x02; CLK_PR=0x5a //使能外部振荡器XOSC
#define  XOSC_DIS       CLK_PR=0xA5;  CLK_C1 |= 0xfd; CLK_PR=0x5a //禁止外部振荡器XOSC
    
#define  SYSCK_DIV1     CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x00; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//系统时钟为HRC/1  = 16M/1  = 16M
#define  SYSCK_DIV2     CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x01; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//系统时钟为HRC/2  = 16M/2  = 8M
#define  SYSCK_DIV4     CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x02; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//系统时钟为HRC/4  = 16M/4  = 4M
#define  SYSCK_DIV8     CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x03; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//系统时钟为HRC/8  = 16M/8  = 2M
#define  SYSCK_DIV16    CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x04; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//系统时钟为HRC/16 = 16M/16 = 1M
#define  SYSCK_DIV32    CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x05; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//系统时钟为HRC/32 = 16M/32 = 0.5M
#define  SYSCK_DIV64    CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x06; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//系统时钟为HRC/64 = 16M/64 = 0.25M
#define  SYSCK_DIV128   CLK_PR=0xA5;  ADC_TG_R0L = CLK_C0; ADC_TG_R0L &=0xf0; ADC_TG_R0L |=0x07; CLK_C0 = ADC_TG_R0L; CLK_PR=0x5a//系统时钟为HRC/128= 16M/128= 0.125M
    
#define  WKUP_T_4US     CLK_PR=0xA5;  WKUP_T = 0x08;  CLK_PR=0x5a //SLEEP 唤醒等待时间 4uS
#define  WKUP_T_8US     CLK_PR=0xA5;  WKUP_T = 0x18;  CLK_PR=0x5a //SLEEP 唤醒等待时间 8uS
#define  WKUP_T_DEF     CLK_PR=0xA5;  WKUP_T = 0xff;  CLK_PR=0x5a //SLEEP 唤醒等待时间
 
//iap
#define  EEPROMADDR     0x8200                                  //EEPROM起始地址
//wdt
#define  CLR_WDT        WDT_OP = 0x5A                           //清除看门狗
#define  WDT_EN         WDT_C  &= 0xdf                          //开启看门狗
#define  WDT_DIS        WDT_C  |= 0x20                          //关闭看门狗
//低频作为WDT时钟
#define  WDT_LRC_2560MS WDT_C  = 0x10                           //设置看门狗时钟为低频16K，WDT时间为2560MS
#define  WDT_LRC_2000MS WDT_C  = 0x11                           //设置看门狗时钟为低频16K，WDT时间为2000MS
#define  WDT_LRC_1500MS WDT_C  = 0x12                           //设置看门狗时钟为低频16K，WDT时间为1500MS
#define  WDT_LRC_1000MS WDT_C  = 0x13                           //设置看门狗时钟为低频16K，WDT时间为1000MS
#define  WDT_LRC_900MS  WDT_C  = 0x14                           //设置看门狗时钟为低频16K，WDT时间为900MS
#define  WDT_LRC_800MS  WDT_C  = 0x15                           //设置看门狗时钟为低频16K，WDT时间为800MS
#define  WDT_LRC_700MS  WDT_C  = 0x16                           //设置看门狗时钟为低频16K，WDT时间为700MS
#define  WDT_LRC_600MS  WDT_C  = 0x17                           //设置看门狗时钟为低频16K，WDT时间为600MS
#define  WDT_LRC_500MS  WDT_C  = 0x18                           //设置看门狗时钟为低频16K，WDT时间为500MS
#define  WDT_LRC_400MS  WDT_C  = 0x19                           //设置看门狗时钟为低频16K，WDT时间为400MS
#define  WDT_LRC_300MS  WDT_C  = 0x1a                           //设置看门狗时钟为低频16K，WDT时间为300MS
#define  WDT_LRC_200MS  WDT_C  = 0x1b                           //设置看门狗时钟为低频16K，WDT时间为200MS
#define  WDT_LRC_100MS  WDT_C  = 0x1c                           //设置看门狗时钟为低频16K，WDT时间为100MS
#define  WDT_LRC_50MS   WDT_C  = 0x1d                           //设置看门狗时钟为低频16K，WDT时间为50MS
#define  WDT_LRC_20MS   WDT_C  = 0x1e                           //设置看门狗时钟为低频16K，WDT时间为20MS
#define  WDT_LRC_10MS   WDT_C  = 0x1f                           //设置看门狗时钟为低频16K，WDT时间为10MS

#define  WDT_SYSCLK_8MS    WDT_C  = 0x00
#define  WDT_SYSCLK_4MS    WDT_C  = 0x01
#define  WDT_SYSCLK_2MS    WDT_C  = 0x02
#define  WDT_SYSCLK_1MS    WDT_C  = 0x03
#define  WDT_SYSCLK_512US  WDT_C  = 0x04
//low power
#define  SLEEP_MD     PCON = 0x50;  PCON = 0x01; PCON = 0xA0    //MCU进入SLEEP模式
#define  IDLE_MD      PCON = 0x50;  PCON = 0x02; PCON = 0xA0    //MCU进入IDLE模式

//P0_FUN设置
#define  P05_FUN_IO        P0_FUN2 &= 0x0F                      //P05端口作为IO功能       
#define  P05_FUN_PWM01     P0_FUN2 &= 0x0F; P0_FUN2 |= 0x10     //P05端口作为PWM10功能
#define  P05_FUN_PWM11     P0_FUN2 &= 0x0F; P0_FUN2 |= 0x20     //P05端口作为PWM11功能
#define  P05_FUN_PWM21     P0_FUN2 &= 0x0F; P0_FUN2 |= 0x30     //P05端口作为PWM21功能
#define  P05_FUN_TX0       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x40     //P05端口作为TX0功能
#define  P05_FUN_RX0       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x50     //P05端口作为RX0功能
#define  P05_FUN_SCL       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x60     //P05端口作为SCL功能
#define  P05_FUN_SDA       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x70     //P05端口作为SDA功能
#define  P05_FUN_T2G       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x80     //P05端口作为T2G功能
#define  P05_FUN_TIN1      P0_FUN2 &= 0x0F; P0_FUN2 |= 0x90     //P05端口作为TIN1功能
#define  P05_FUN_TO1       P0_FUN2 &= 0x0F; P0_FUN2 |= 0x90     //P05端口作为TO1功能
#define  P05_FUN_CAP2      P0_FUN2 &= 0x0F; P0_FUN2 |= 0xA0     //P05端口作为CAP2功能

#define  P04_FUN_IO        P0_FUN2 &= 0xF0                      //P04端口作为IO功能          
#define  P04_FUN_PWM00     P0_FUN2 &= 0xF0; P0_FUN2 |= 0x01     //P04端口作为PWM00功能
#define  P04_FUN_PWM10     P0_FUN2 &= 0xF0; P0_FUN2 |= 0x02     //P04端口作为PWM10功能
#define  P04_FUN_PWM20     P0_FUN2 &= 0xF0; P0_FUN2 |= 0x03     //P04端口作为PWM20功能
#define  P04_FUN_TX0       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x04     //P04端口作为TX0功能
#define  P04_FUN_RX0       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x05     //P04端口作为RX0功能
#define  P04_FUN_SCL       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x06     //P04端口作为SCL功能
#define  P04_FUN_SDA       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x07     //P04端口作为SDA功能
#define  P04_FUN_T3G       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x08     //P04端口作为T3G功能
#define  P04_FUN_TIN0      P0_FUN2 &= 0xF0; P0_FUN2 |= 0x09     //P04端口作为TIN0功能
#define  P04_FUN_TO0       P0_FUN2 &= 0xF0; P0_FUN2 |= 0x09     //P04端口作为TO0功能
#define  P04_FUN_CAP1A     P0_FUN2 &= 0xF0; P0_FUN2 |= 0x0A     //P04端口作为CAP1A功能

#define  P03_FUN_IO        P0_FUN1 &= 0x0F                      //P03端口作为IO功能                          
#define  P03_FUN_PWM01     P0_FUN1 &= 0x0F; P0_FUN1 |= 0x10     //P03端口作为PWM10功能
#define  P03_FUN_PWM11     P0_FUN1 &= 0x0F; P0_FUN1 |= 0x20     //P03端口作为PWM11功能
#define  P03_FUN_PWM21     P0_FUN1 &= 0x0F; P0_FUN1 |= 0x30     //P03端口作为PWM21功能
#define  P03_FUN_TX1       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x40     //P03端口作为TX1功能
#define  P03_FUN_RX1       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x50     //P03端口作为RX1功能
#define  P03_FUN_SCL       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x60     //P03端口作为SCL功能
#define  P03_FUN_SDA       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x70     //P03端口作为SDA功能
#define  P03_FUN_T0G       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x80     //P03端口作为T0G功能
#define  P03_FUN_TIN3      P0_FUN1 &= 0x0F; P0_FUN1 |= 0x90     //P03端口作为TIN3功能
#define  P03_FUN_TO3       P0_FUN1 &= 0x0F; P0_FUN1 |= 0x90     //P03端口作为TO3功能
#define  P03_FUN_CAP0      P0_FUN1 &= 0x0F; P0_FUN1 |= 0xA0     //P03端口作为CAP0功能
#define  P03_FUN_MOSI      P0_FUN1 &= 0x0F; P0_FUN1 |= 0xB0     //P03端口作为MOSI功能
#define  P03_FUN_SEG11     P0_FUN1 &= 0x0F; P0_FUN1 |= 0xF0     //P03端口作为SEG11功能

#define  P02_FUN_IO        P0_FUN1 &= 0xF0                      //P02端口作为IO功能            
#define  P02_FUN_PWM00     P0_FUN1 &= 0xF0; P0_FUN1 |= 0x01     //P02端口作为PWM00功能
#define  P02_FUN_PWM10     P0_FUN1 &= 0xF0; P0_FUN1 |= 0x02     //P02端口作为PWM10功能
#define  P02_FUN_PWM20     P0_FUN1 &= 0xF0; P0_FUN1 |= 0x03     //P02端口作为PWM20功能
#define  P02_FUN_TX1       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x04     //P02端口作为TX1功能
#define  P02_FUN_RX1       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x05     //P02端口作为RX1功能
#define  P02_FUN_SCL       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x06     //P02端口作为SCL功能
#define  P02_FUN_SDA       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x07     //P02端口作为SDA功能
#define  P02_FUN_T1G       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x08     //P02端口作为T1G功能
#define  P02_FUN_TIN2      P0_FUN1 &= 0xF0; P0_FUN1 |= 0x09     //P02端口作为TIN2功能
#define  P02_FUN_TO2       P0_FUN1 &= 0xF0; P0_FUN1 |= 0x09     //P02端口作为TO2功能
#define  P02_FUN_CAP2      P0_FUN1 &= 0xF0; P0_FUN1 |= 0x0A     //P02端口作为CAP2功能
#define  P02_FUN_MISO      P0_FUN1 &= 0xF0; P0_FUN1 |= 0x0B     //P02端口作为MISO功能
#define  P02_FUN_SEG10     P0_FUN1 &= 0xF0; P0_FUN1 |= 0x0F     //P02端口作为SEG10功能

#define  P01_FUN_IO        P0_FUN0 &= 0x0F                      //P01端口作为IO功能                          
#define  P01_FUN_PWM01     P0_FUN0 &= 0x0F; P0_FUN0 |= 0x10     //P01端口作为PWM10功能
#define  P01_FUN_PWM11     P0_FUN0 &= 0x0F; P0_FUN0 |= 0x20     //P01端口作为PWM11功能
#define  P01_FUN_PWM21     P0_FUN0 &= 0x0F; P0_FUN0 |= 0x30     //P01端口作为PWM21功能
#define  P01_FUN_TX0       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x40     //P01端口作为TX0功能
#define  P01_FUN_RX0       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x50     //P01端口作为RX0功能
#define  P01_FUN_SCL       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x60     //P01端口作为SCL功能
#define  P01_FUN_SDA       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x70     //P01端口作为SDA功能
#define  P01_FUN_T2G       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x80     //P01端口作为T2G功能
#define  P01_FUN_TIN1      P0_FUN0 &= 0x0F; P0_FUN0 |= 0x90     //P01端口作为TIN1功能
#define  P01_FUN_TO1       P0_FUN0 &= 0x0F; P0_FUN0 |= 0x90     //P01端口作为TO1功能
#define  P01_FUN_CAP1      P0_FUN0 &= 0x0F; P0_FUN0 |= 0xA0     //P01端口作为CAP1功能
#define  P01_FUN_SCK       P0_FUN0 &= 0x0F; P0_FUN0 |= 0xB0     //P01端口作为SCK功能
#define  P01_FUN_SEG09     P0_FUN0 &= 0x0F; P0_FUN0 |= 0xF0     //P01端口作为SEG9功能

#define  P00_FUN_IO        P0_FUN0 &= 0xF0                      //P00端口作为IO功能           
#define  P00_FUN_PWM00     P0_FUN0 &= 0xF0; P0_FUN0 |= 0x01     //P00端口作为PWM00功能
#define  P00_FUN_PWM10     P0_FUN0 &= 0xF0; P0_FUN0 |= 0x02     //P00端口作为PWM10功能
#define  P00_FUN_PWM20     P0_FUN0 &= 0xF0; P0_FUN0 |= 0x03     //P00端口作为PWM20功能
#define  P00_FUN_TX0       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x04     //P00端口作为TX0功能
#define  P00_FUN_RX0       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x05     //P00端口作为RX0功能
#define  P00_FUN_SCL       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x06     //P00端口作为SCL功能
#define  P00_FUN_SDA       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x07     //P00端口作为SDA功能
#define  P00_FUN_T3G       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x08     //P00端口作为T3G功能
#define  P00_FUN_TIN0      P0_FUN0 &= 0xF0; P0_FUN0 |= 0x09     //P00端口作为TIN0功能
#define  P00_FUN_TO0       P0_FUN0 &= 0xF0; P0_FUN0 |= 0x09     //P00端口作为TO0功能
#define  P00_FUN_CAP0      P0_FUN0 &= 0xF0; P0_FUN0 |= 0x0A     //P00端口作为CAP0功能
#define  P00_FUN_SS        P0_FUN0 &= 0xF0; P0_FUN0 |= 0x0B     //P00端口作为SS功能
#define  P00_FUN_SEG8      P0_FUN0 &= 0xF0; P0_FUN0 |= 0x0F     //P00端口作为SEG8功能

//P1_FUN设置
#define  P10_FUN_IO        P1_FUN0 &= 0xF0                      //P10端口作为IO功能           
#define  P10_FUN_PWM00     P1_FUN0 &= 0xF0; P1_FUN0 |= 0x01     //P10端口作为PWM00功能
#define  P10_FUN_PWM10     P1_FUN0 &= 0xF0; P1_FUN0 |= 0x02     //P10端口作为PWM10功能
#define  P10_FUN_PWM20     P1_FUN0 &= 0xF0; P1_FUN0 |= 0x03     //P10端口作为PWM20功能
#define  P10_FUN_TX0       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x04     //P10端口作为TX0功能
#define  P10_FUN_RX0       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x05     //P10端口作为RX0功能
#define  P10_FUN_SCL       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x06     //P10端口作为SCL功能
#define  P10_FUN_SDA       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x07     //P10端口作为SDA功能
#define  P10_FUN_T3G       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x08     //P10端口作为T3G功能
#define  P10_FUN_TIN2      P1_FUN0 &= 0xF0; P1_FUN0 |= 0x09     //P10端口作为TIN2功能
#define  P10_FUN_TO2       P1_FUN0 &= 0xF0; P1_FUN0 |= 0x09     //P10端口作为TO2功能
#define  P10_FUN_CAP2      P1_FUN0 &= 0xF0; P1_FUN0 |= 0x0A     //P10端口作为CAP2功能
#define  P10_FUN_SS        P1_FUN0 &= 0xF0; P1_FUN0 |= 0x0B     //P10端口作为SS功能
#define  P10_FUN_SEG0      P1_FUN0 &= 0xF0; P1_FUN0 |= 0x0F     //P10端口作为SEG0功能

#define  P11_FUN_IO        P1_FUN0 &= 0x0F                      //P11端口作为IO功能                             
#define  P11_FUN_PWM01     P1_FUN0 &= 0x0F; P1_FUN0 |= 0x10     //P11端口作为PWM10功能
#define  P11_FUN_PWM11     P1_FUN0 &= 0x0F; P1_FUN0 |= 0x20     //P11端口作为PWM11功能
#define  P11_FUN_PWM21     P1_FUN0 &= 0x0F; P1_FUN0 |= 0x30     //P11端口作为PWM21功能
#define  P11_FUN_TX0       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x40     //P11端口作为TX0功能
#define  P11_FUN_RX0       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x50     //P11端口作为RX0功能
#define  P11_FUN_SCL       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x60     //P11端口作为SCL功能
#define  P11_FUN_SDA       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x70     //P11端口作为SDA功能
#define  P11_FUN_T2G       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x80     //P11端口作为T2G功能
#define  P11_FUN_TIN3      P1_FUN0 &= 0x0F; P1_FUN0 |= 0x90     //P11端口作为TIN3功能
#define  P11_FUN_TO3       P1_FUN0 &= 0x0F; P1_FUN0 |= 0x90     //P11端口作为TO3功能
#define  P11_FUN_CAP0      P1_FUN0 &= 0x0F; P1_FUN0 |= 0xA0     //P11端口作为CAP0功能
#define  P11_FUN_SCK       P1_FUN0 &= 0x0F; P1_FUN0 |= 0xB0     //P11端口作为SCK功能
#define  P11_FUN_SEG1      P1_FUN0 &= 0x0F; P1_FUN0 |= 0xF0     //P11端口作为SEG1功能

#define  P12_FUN_IO        P1_FUN1 &= 0xF0                      //P12端口作为IO功能           
#define  P12_FUN_PWM00     P1_FUN1 &= 0xF0; P1_FUN1 |= 0x01     //P12端口作为PWM00功能
#define  P12_FUN_PWM10     P1_FUN1 &= 0xF0; P1_FUN1 |= 0x02     //P12端口作为PWM10功能
#define  P12_FUN_PWM20     P1_FUN1 &= 0xF0; P1_FUN1 |= 0x03     //P12端口作为PWM20功能
#define  P12_FUN_TX1       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x04     //P12端口作为TX1功能
#define  P12_FUN_RX1       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x05     //P12端口作为RX1功能
#define  P12_FUN_SCL       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x06     //P12端口作为SCL功能
#define  P12_FUN_SDA       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x07     //P12端口作为SDA功能
#define  P12_FUN_T1G       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x08     //P12端口作为T1G功能
#define  P12_FUN_TIN0      P1_FUN1 &= 0xF0; P1_FUN1 |= 0x09     //P12端口作为TIN0功能
#define  P12_FUN_TO0       P1_FUN1 &= 0xF0; P1_FUN1 |= 0x09     //P12端口作为TO0功能
#define  P12_FUN_CAP1      P1_FUN1 &= 0xF0; P1_FUN1 |= 0x0A     //P12端口作为CAP1功能
#define  P12_FUN_MISO      P1_FUN1 &= 0xF0; P1_FUN1 |= 0x0B     //P12端口作为MISO功能
#define  P12_FUN_SEG2      P1_FUN1 &= 0xF0; P1_FUN1 |= 0x0F     //P12端口作为SEG2功能

#define  P13_FUN_IO        P1_FUN1 &= 0x0F                      //P13端口作为IO功能                     
#define  P13_FUN_PWM01     P1_FUN1 &= 0x0F; P1_FUN1 |= 0x10     //P13端口作为PWM10功能
#define  P13_FUN_PWM11     P1_FUN1 &= 0x0F; P1_FUN1 |= 0x20     //P13端口作为PWM11功能
#define  P13_FUN_PWM21     P1_FUN1 &= 0x0F; P1_FUN1 |= 0x30     //P13端口作为PWM21功能
#define  P13_FUN_TX1       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x40     //P13端口作为TX1功能
#define  P13_FUN_RX1       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x50     //P13端口作为RX1功能
#define  P13_FUN_SCL       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x60     //P13端口作为SCL功能
#define  P13_FUN_SDA       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x70     //P13端口作为SDA功能
#define  P13_FUN_T0G       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x80     //P13端口作为T0G功能
#define  P13_FUN_TIN1      P1_FUN1 &= 0x0F; P1_FUN1 |= 0x90     //P13端口作为TIN1功能
#define  P13_FUN_TO1       P1_FUN1 &= 0x0F; P1_FUN1 |= 0x90     //P13端口作为TO1功能
#define  P13_FUN_CAP2      P1_FUN1 &= 0x0F; P1_FUN1 |= 0xA0     //P13端口作为CAP2功能
#define  P13_FUN_MOSI      P1_FUN1 &= 0x0F; P1_FUN1 |= 0xB0     //P13端口作为MOSI功能
#define  P13_FUN_SEG3      P1_FUN1 &= 0x0F; P1_FUN1 |= 0xF0     //P13端口作为SEG3功能

#define  P14_FUN_IO        P1_FUN2 &= 0xF0                      //P14端口作为IO功能   
#define  P14_FUN_PWM00     P1_FUN2 &= 0xF0; P1_FUN2 |= 0x01     //P14端口作为PWM00功能
#define  P14_FUN_PWM10     P1_FUN2 &= 0xF0; P1_FUN2 |= 0x02     //P14端口作为PWM10功能
#define  P14_FUN_PWM20     P1_FUN2 &= 0xF0; P1_FUN2 |= 0x03     //P14端口作为PWM20功能
#define  P14_FUN_TX0       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x04     //P14端口作为TX0功能
#define  P14_FUN_RX0       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x05     //P14端口作为RX0功能
#define  P14_FUN_SCL       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x06     //P14端口作为SCL功能
#define  P14_FUN_SDA       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x07     //P14端口作为SDA功能
#define  P14_FUN_T3G       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x08     //P14端口作为T3G功能
#define  P14_FUN_TIN2      P1_FUN2 &= 0xF0; P1_FUN2 |= 0x09     //P14端口作为TIN2功能
#define  P14_FUN_TO2       P1_FUN2 &= 0xF0; P1_FUN2 |= 0x09     //P14端口作为TO2功能
#define  P14_FUN_CAP0      P1_FUN2 &= 0xF0; P1_FUN2 |= 0x0A     //P14端口作为CAP0功能
#define  P14_FUN_SEG4      P1_FUN2 &= 0xF0; P1_FUN2 |= 0x0F     //P14端口作为SEG4功能

#define  P15_FUN_IO        P1_FUN2 &= 0x0F                      //P15端口作为IO功能                    
#define  P15_FUN_PWM01     P1_FUN2 &= 0x0F; P1_FUN2 |= 0x10     //P15端口作为PWM10功能
#define  P15_FUN_PWM11     P1_FUN2 &= 0x0F; P1_FUN2 |= 0x20     //P15端口作为PWM11功能
#define  P15_FUN_PWM21     P1_FUN2 &= 0x0F; P1_FUN2 |= 0x30     //P15端口作为PWM21功能
#define  P15_FUN_TX0       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x40     //P15端口作为TX0功能
#define  P15_FUN_RX0       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x50     //P15端口作为RX0功能
#define  P15_FUN_SCL       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x60     //P15端口作为SCL功能
#define  P15_FUN_SDA       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x70     //P15端口作为SDA功能
#define  P15_FUN_T2G       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x80     //P15端口作为T2G功能
#define  P15_FUN_TIN3      P1_FUN2 &= 0x0F; P1_FUN2 |= 0x90     //P15端口作为TIN3功能
#define  P15_FUN_TO3       P1_FUN2 &= 0x0F; P1_FUN2 |= 0x90     //P15端口作为TO3功能
#define  P15_FUN_CAP1      P1_FUN2 &= 0x0F; P1_FUN2 |= 0xA0     //P15端口作为CAP1功能
#define  P15_FUN_SEG5      P1_FUN2 &= 0x0F; P1_FUN2 |= 0xF0     //P15端口作为SEG5功能

#define  P16_FUN_IO        P1_FUN3 &= 0xF0                      //P16端口作为IO功能                   
#define  P16_FUN_PWM00     P1_FUN3 &= 0xF0; P1_FUN3 |= 0x01     //P16端口作为PWM00功能
#define  P16_FUN_PWM10     P1_FUN3 &= 0xF0; P1_FUN3 |= 0x02     //P16端口作为PWM10功能
#define  P16_FUN_PWM20     P1_FUN3 &= 0xF0; P1_FUN3 |= 0x03     //P16端口作为PWM20功能
#define  P16_FUN_TX1       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x04     //P16端口作为TX1功能
#define  P16_FUN_RX1       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x05     //P16端口作为RX1功能
#define  P16_FUN_SCL       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x06     //P16端口作为SCL功能
#define  P16_FUN_SDA       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x07     //P16端口作为SDA功能
#define  P16_FUN_T1G       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x08     //P16端口作为T1G功能
#define  P16_FUN_TIN3      P1_FUN3 &= 0xF0; P1_FUN3 |= 0x09     //P16端口作为TIN3功能
#define  P16_FUN_TO3       P1_FUN3 &= 0xF0; P1_FUN3 |= 0x09     //P16端口作为TO3功能
#define  P16_FUN_CAP2      P1_FUN3 &= 0xF0; P1_FUN3 |= 0x0A     //P16端口作为CAP2功能
#define  P16_FUN_SEG6      P1_FUN3 &= 0xF0; P1_FUN3 |= 0x0F     //P16端口作为SEG6功能

#define  P17_FUN_IO        P1_FUN3 &= 0x0F                      //P17端口作为IO功能   
#define  P17_FUN_PWM01     P1_FUN3 &= 0x0F; P1_FUN3 |= 0x10     //P17端口作为PWM10功能
#define  P17_FUN_PWM11     P1_FUN3 &= 0x0F; P1_FUN3 |= 0x20     //P17端口作为PWM11功能
#define  P17_FUN_PWM21     P1_FUN3 &= 0x0F; P1_FUN3 |= 0x30     //P17端口作为PWM21功能
#define  P17_FUN_TX1       P1_FUN3 &= 0x0F; P1_FUN3 |= 0x40     //P17端口作为TX1功能
#define  P17_FUN_RX1  	   P1_FUN3 &= 0x0F; P1_FUN3 |= 0x50     //P17端口作为RX1功能
#define  P17_FUN_SCL       P1_FUN3 &= 0x0F; P1_FUN3 |= 0x60     //P17端口作为SCL功能
#define  P17_FUN_SDA       P1_FUN3 &= 0x0F; P1_FUN3 |= 0x70     //P17端口作为SDA功能
#define  P17_FUN_T0G       P1_FUN3 &= 0x0F; P1_FUN3 |= 0x80     //P17端口作为T0G功能
#define  P17_FUN_TIN2      P1_FUN3 &= 0x0F; P1_FUN3 |= 0x90     //P17端口作为TIN2功能
#define  P17_FUN_TO2       P1_FUN3 &= 0x0F; P1_FUN3 |= 0x90     //P17端口作为TO2功能
#define  P17_FUN_CAP2      P1_FUN3 &= 0x0F; P1_FUN3 |= 0xA0     //P17端口作为CAP2功能
#define  P17_FUN_SEG7      P1_FUN3 &= 0x0F; P1_FUN3 |= 0xF0     //P17端口作为SEG7功能

//P2_FUN设置
#define  P20_FUN_IO        P2_FUN0 &= 0xF0                      //P23端口作为IO功能                            
#define  P20_FUN_PWM00     P2_FUN0 &= 0xF0; P2_FUN0 |= 0x01     //P23端口作为PWM00功能
#define  P20_FUN_PWM10     P2_FUN0 &= 0xF0; P2_FUN0 |= 0x02     //P23端口作为PWM10功能
#define  P20_FUN_PWM20     P2_FUN0 &= 0xF0; P2_FUN0 |= 0x03     //P23端口作为PWM20功能
#define  P20_FUN_TX0       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x04     //P23端口作为TX0功能
#define  P20_FUN_RX0       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x05     //P23端口作为RX0功能
#define  P20_FUN_SCL       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x06     //P23端口作为SCL功能
#define  P20_FUN_SDA       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x07     //P23端口作为SDA功能
#define  P20_FUN_T3G       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x08     //P23端口作为T3G功能
#define  P20_FUN_TIN0      P2_FUN0 &= 0xF0; P2_FUN0 |= 0x09     //P23端口作为TIN0功能
#define  P20_FUN_TO0       P2_FUN0 &= 0xF0; P2_FUN0 |= 0x09     //P23端口作为TO0功能
#define  P20_FUN_CAP1      P2_FUN0 &= 0xF0; P2_FUN0 |= 0x0A     //P23端口作为CAP1功能
#define  P20_FUN_SS        P2_FUN0 &= 0xF0; P2_FUN0 |= 0x0B     //P23端口作为SS功能

#define  P21_FUN_IO        P2_FUN0 &= 0x0F                      //P21端口作为IO功能                           
#define  P21_FUN_PWM01     P2_FUN0 &= 0x0F; P2_FUN0 |= 0x10     //P21端口作为PWM10功能
#define  P21_FUN_PWM11     P2_FUN0 &= 0x0F; P2_FUN0 |= 0x20     //P21端口作为PWM11功能
#define  P21_FUN_PWM21     P2_FUN0 &= 0x0F; P2_FUN0 |= 0x30     //P21端口作为PWM21功能
#define  P21_FUN_TX0       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x40     //P21端口作为TX0功能
#define  P21_FUN_RX0       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x50     //P21端口作为RX0功能
#define  P21_FUN_SCL       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x60     //P21端口作为SCL功能
#define  P21_FUN_SDA       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x70     //P21端口作为SDA功能
#define  P21_FUN_T2G       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x80     //P21端口作为T2G功能
#define  P21_FUN_TIN1      P2_FUN0 &= 0x0F; P2_FUN0 |= 0x90     //P21端口作为TIN1功能
#define  P21_FUN_TO1       P2_FUN0 &= 0x0F; P2_FUN0 |= 0x90     //P21端口作为TO1功能
#define  P21_FUN_CAP2      P2_FUN0 &= 0x0F; P2_FUN0 |= 0xA0     //P21端口作为CAP2功能
#define  P21_FUN_SCK       P2_FUN0 &= 0x0F; P2_FUN0 |= 0xB0     //P21端口作为SCK功能

#define  P22_FUN_IO        P2_FUN1 &= 0xF0                      //P22端口作为IO功能                            
#define  P22_FUN_PWM00     P2_FUN1 &= 0xF0; P2_FUN1 |= 0x01     //P22端口作为PWM10功能
#define  P22_FUN_PWM10     P2_FUN1 &= 0xF0; P2_FUN1 |= 0x02     //P22端口作为PWM11功能
#define  P22_FUN_PWM20     P2_FUN1 &= 0xF0; P2_FUN1 |= 0x03     //P22端口作为PWM21功能
#define  P22_FUN_TX1       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x04     //P22端口作为TX1功能
#define  P22_FUN_RX1       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x05     //P22端口作为RX1功能
#define  P22_FUN_SCL       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x06     //P22端口作为SCL功能
#define  P22_FUN_SDA       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x07     //P22端口作为SDA功能
#define  P22_FUN_T1G       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x08     //P22端口作为T1G功能
#define  P22_FUN_TIN2      P2_FUN1 &= 0xF0; P2_FUN1 |= 0x09     //P22端口作为TIN2功能
#define  P22_FUN_TO2       P2_FUN1 &= 0xF0; P2_FUN1 |= 0x09     //P22端口作为TO2功能
#define  P22_FUN_CAP0      P2_FUN1 &= 0xF0; P2_FUN1 |= 0x0A     //P22端口作为CAP0功能
#define  P22_FUN_MISO      P2_FUN1 &= 0xF0; P2_FUN1 |= 0x0B     //P22端口作为MISO功能

#define  P23_FUN_IO        P2_FUN1 &= 0x0F                      //P23端口作为IO功能           
#define  P23_FUN_PWM01     P2_FUN1 &= 0x0F; P2_FUN1 |= 0x10     //P23端口作为PWM10功能
#define  P23_FUN_PWM11     P2_FUN1 &= 0x0F; P2_FUN1 |= 0x20     //P23端口作为PWM11功能
#define  P23_FUN_PWM21     P2_FUN1 &= 0x0F; P2_FUN1 |= 0x30     //P23端口作为PWM21功能
#define  P23_FUN_TX1       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x40     //P23端口作为TX1功能
#define  P23_FUN_RX1       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x50     //P23端口作为RX1功能
#define  P23_FUN_SCL       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x60     //P23端口作为SCL功能
#define  P23_FUN_SDA       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x70     //P23端口作为SDA功能
#define  P23_FUN_T0G       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x80     //P23端口作为T0G功能
#define  P23_FUN_TIN3      P2_FUN1 &= 0x0F; P2_FUN1 |= 0x90     //P23端口作为TIN3功能
#define  P23_FUN_TO3       P2_FUN1 &= 0x0F; P2_FUN1 |= 0x90     //P23端口作为TO3功能
#define  P23_FUN_CAP1      P2_FUN1 &= 0x0F; P2_FUN1 |= 0xA0     //P23端口作为CAP1功能
#define  P23_FUN_MOSI      P2_FUN1 &= 0x0F; P2_FUN1 |= 0xB0     //P23端口作为MOSI功能

#define  P24_FUN_IO        P2_FUN2 &= 0xF0                      //P24端口作为IO功能                            
#define  P24_FUN_PWM00     P2_FUN2 &= 0xF0; P2_FUN2 |= 0x01     //P24端口作为PWM00功能
#define  P24_FUN_PWM10     P2_FUN2 &= 0xF0; P2_FUN2 |= 0x02     //P24端口作为PWM10功能
#define  P24_FUN_PWM20     P2_FUN2 &= 0xF0; P2_FUN2 |= 0x03     //P24端口作为PWM20功能
#define  P24_FUN_TX0       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x04     //P24端口作为TX0功能
#define  P24_FUN_RX0       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x05     //P24端口作为RX0功能
#define  P24_FUN_SCL       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x06     //P24端口作为SCL功能
#define  P24_FUN_SDA       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x07     //P24端口作为SDA功能
#define  P24_FUN_T3G       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x08     //P24端口作为T3G功能
#define  P24_FUN_TIN0      P2_FUN2 &= 0xF0; P2_FUN2 |= 0x09     //P24端口作为TIN0功能
#define  P24_FUN_TO0       P2_FUN2 &= 0xF0; P2_FUN2 |= 0x09     //P24端口作为TO0功能
#define  P24_FUN_CAP2      P2_FUN2 &= 0xF0; P2_FUN2 |= 0x0A     //P24端口作为CAP2功能

#define  P25_FUN_IO        P2_FUN2 &= 0x0F                      //P25端口作为IO功能           
#define  P25_FUN_PWM01     P2_FUN2 &= 0x0F; P2_FUN2 |= 0x10     //P25端口作为PWM10功能
#define  P25_FUN_PWM11     P2_FUN2 &= 0x0F; P2_FUN2 |= 0x20     //P25端口作为PWM11功能
#define  P25_FUN_PWM21     P2_FUN2 &= 0x0F; P2_FUN2 |= 0x30     //P25端口作为PWM21功能
#define  P25_FUN_TX0       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x40     //P25端口作为TX0功能
#define  P25_FUN_RX0       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x50     //P25端口作为RX0功能
#define  P25_FUN_SCL       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x60     //P25端口作为SCL功能
#define  P25_FUN_SDA       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x70     //P25端口作为SDA功能
#define  P25_FUN_T2G       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x80     //P25端口作为T2G功能
#define  P25_FUN_TIN1      P2_FUN2 &= 0x0F; P2_FUN2 |= 0x90     //P25端口作为TIN1功能
#define  P25_FUN_TO1       P2_FUN2 &= 0x0F; P2_FUN2 |= 0x90     //P25端口作为TO1功能
#define  P25_FUN_CAP0      P2_FUN2 &= 0x0F; P2_FUN2 |= 0xA0     //P25端口作为CAP0功能

#define  P26_FUN_IO        P2_FUN3 &= 0xF0                      //P26端口作为IO功能                             
#define  P26_FUN_PWM00     P2_FUN3 &= 0xF0; P2_FUN3 |= 0x01     //P26端口作为PWM00功能
#define  P26_FUN_PWM10     P2_FUN3 &= 0xF0; P2_FUN3 |= 0x02     //P26端口作为PWM10功能
#define  P26_FUN_PWM20     P2_FUN3 &= 0xF0; P2_FUN3 |= 0x03     //P26端口作为PWM20功能
#define  P26_FUN_TX1       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x04     //P26端口作为TX1功能
#define  P26_FUN_RX1       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x05     //P26端口作为RX1功能
#define  P26_FUN_SCL       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x06     //P26端口作为SCL功能
#define  P26_FUN_SDA       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x07     //P26端口作为SDA功能
#define  P26_FUN_T1G       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x08     //P26端口作为T1G功能
#define  P26_FUN_TIN2      P2_FUN3 &= 0xF0; P2_FUN3 |= 0x09     //P26端口作为TIN2功能
#define  P26_FUN_TO2       P2_FUN3 &= 0xF0; P2_FUN3 |= 0x09     //P26端口作为TO2功能
#define  P26_FUN_CAP1      P2_FUN3 &= 0xF0; P2_FUN3 |= 0x0A     //P26端口作为CAP1功能

#define  P27_FUN_IO        P2_FUN3 &= 0x0F                      //P27端口作为IO功能           
#define  P27_FUN_PWM01     P2_FUN3 &= 0x0F; P2_FUN3 |= 0x10     //P27端口作为PWM10功能
#define  P27_FUN_PWM11     P2_FUN3 &= 0x0F; P2_FUN3 |= 0x20     //P27端口作为PWM11功能
#define  P27_FUN_PWM21     P2_FUN3 &= 0x0F; P2_FUN3 |= 0x30     //P27端口作为PWM21功能
#define  P27_FUN_TX1       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x40     //P27端口作为TX1功能
#define  P27_FUN_RX1       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x50     //P27端口作为RX1功能
#define  P27_FUN_SCL       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x60     //P27端口作为SCL功能
#define  P27_FUN_SDA       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x70     //P27端口作为SDA功能
#define  P27_FUN_T0G       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x80     //P27端口作为T0G功能
#define  P27_FUN_TIN3      P2_FUN3 &= 0x0F; P2_FUN3 |= 0x90     //P27端口作为TIN3功能
#define  P27_FUN_TO3       P2_FUN3 &= 0x0F; P2_FUN3 |= 0x90     //P27端口作为TO3功能
#define  P27_FUN_CAP2A     P2_FUN3 &= 0x0F; P2_FUN3 |= 0xA0     //P27端口作为CAP2A功能

//P3_FUN设置
#define  P30_FUN_IO        P3_FUN0 &= 0xF0                      //P33端口作为IO功能                            
#define  P30_FUN_PWM00     P3_FUN0 &= 0xF0; P3_FUN0 |= 0x01     //P33端口作为PWM10功能
#define  P30_FUN_PWM10     P3_FUN0 &= 0xF0; P3_FUN0 |= 0x02     //P33端口作为PWM11功能
#define  P30_FUN_PWM20     P3_FUN0 &= 0xF0; P3_FUN0 |= 0x03     //P33端口作为PWM21功能
#define  P30_FUN_TX0       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x04     //P33端口作为TX0功能
#define  P30_FUN_RX0       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x05     //P33端口作为RX0功能
#define  P30_FUN_SCL       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x06     //P33端口作为SCL功能
#define  P30_FUN_SDA       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x07     //P33端口作为SDA功能
#define  P30_FUN_T3G       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x08     //P33端口作为T3G功能
#define  P30_FUN_TIN0      P3_FUN0 &= 0xF0; P3_FUN0 |= 0x09     //P33端口作为TIN0功能
#define  P30_FUN_TO0       P3_FUN0 &= 0xF0; P3_FUN0 |= 0x09     //P33端口作为TO0功能
#define  P30_FUN_CAP0      P3_FUN0 &= 0xF0; P3_FUN0 |= 0x0A     //P33端口作为CAP0功能
#define  P30_FUN_SS        P3_FUN0 &= 0xF0; P3_FUN0 |= 0x0B     //P33端口作为SS功能
#define  P30_FUN_COM0      P3_FUN0 &= 0xF0; P3_FUN0 |= 0x0F     //P33端口作为COM0功能

#define  P31_FUN_IO        P3_FUN0 &= 0x0F                      //P31端口作为IO功能                
#define  P31_FUN_PWM01     P3_FUN0 &= 0x0F; P3_FUN0 |= 0x10     //P31端口作为PWM10功能
#define  P31_FUN_PWM11     P3_FUN0 &= 0x0F; P3_FUN0 |= 0x20     //P31端口作为PWM11功能
#define  P31_FUN_PWM21     P3_FUN0 &= 0x0F; P3_FUN0 |= 0x30     //P31端口作为PWM21功能
#define  P31_FUN_TX0       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x40     //P31端口作为TX0功能
#define  P31_FUN_RX0       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x50     //P31端口作为RX0功能
#define  P31_FUN_SCL       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x60     //P31端口作为SCL功能
#define  P31_FUN_SDA       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x70     //P31端口作为SDA功能
#define  P31_FUN_T2G       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x80     //P31端口作为T2G功能
#define  P31_FUN_TIN1      P3_FUN0 &= 0x0F; P3_FUN0 |= 0x90     //P31端口作为TIN1功能
#define  P31_FUN_TO1       P3_FUN0 &= 0x0F; P3_FUN0 |= 0x90     //P31端口作为TO1功能
#define  P31_FUN_CAP1      P3_FUN0 &= 0x0F; P3_FUN0 |= 0xA0     //P31端口作为CAP1功能
#define  P31_FUN_SCK       P3_FUN0 &= 0x0F; P3_FUN0 |= 0xB0     //P31端口作为SCK功能
#define  P31_FUN_COM1      P3_FUN0 &= 0x0F; P3_FUN0 |= 0xF0     //P31端口作为COM1功能

#define  P32_FUN_IO        P3_FUN1 &= 0xF0                      //P32端口作为IO功能                             
#define  P32_FUN_PWM00     P3_FUN1 &= 0xF0; P3_FUN1 |= 0x01     //P32端口作为PWM00功能
#define  P32_FUN_PWM10     P3_FUN1 &= 0xF0; P3_FUN1 |= 0x02     //P32端口作为PWM10功能
#define  P32_FUN_PWM20     P3_FUN1 &= 0xF0; P3_FUN1 |= 0x03     //P32端口作为PWM20功能
#define  P32_FUN_TX1       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x04     //P32端口作为TX1功能
#define  P32_FUN_RX1       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x05     //P32端口作为RX1功能
#define  P32_FUN_SCL       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x06     //P32端口作为SCL功能
#define  P32_FUN_SDA       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x07     //P32端口作为SDA功能
#define  P32_FUN_T1G       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x08     //P32端口作为T1G功能
#define  P32_FUN_TIN2      P3_FUN1 &= 0xF0; P3_FUN1 |= 0x09     //P32端口作为TIN2功能
#define  P32_FUN_TO2       P3_FUN1 &= 0xF0; P3_FUN1 |= 0x09     //P32端口作为TO2功能
#define  P32_FUN_CAP2      P3_FUN1 &= 0xF0; P3_FUN1 |= 0x0A     //P32端口作为CAP2功能
#define  P32_FUN_MISO      P3_FUN1 &= 0xF0; P3_FUN1 |= 0x0B     //P32端口作为MISO功能
#define  P32_FUN_COM2      P3_FUN1 &= 0xF0; P3_FUN1 |= 0x0F     //P32端口作为COM2功能

#define  P33_FUN_IO        P3_FUN1 &= 0x0F                      //P33端口作为IO功能                                   
#define  P33_FUN_PWM01     P3_FUN1 &= 0x0F; P3_FUN1 |= 0x10     //P33端口作为PWM10功能
#define  P33_FUN_PWM11     P3_FUN1 &= 0x0F; P3_FUN1 |= 0x20     //P33端口作为PWM11功能
#define  P33_FUN_PWM21     P3_FUN1 &= 0x0F; P3_FUN1 |= 0x30     //P33端口作为PWM21功能
#define  P33_FUN_TX1       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x40     //P33端口作为TX1功能
#define  P33_FUN_RX1       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x50     //P33端口作为RX1功能
#define  P33_FUN_SCL       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x60     //P33端口作为SCL功能
#define  P33_FUN_SDA       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x70     //P33端口作为SDA功能
#define  P33_FUN_T0G       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x80     //P33端口作为T0G功能
#define  P33_FUN_TIN3      P3_FUN1 &= 0x0F; P3_FUN1 |= 0x90     //P33端口作为TIN3功能
#define  P33_FUN_TO3       P3_FUN1 &= 0x0F; P3_FUN1 |= 0x90     //P33端口作为TO3功能
#define  P33_FUN_CAP0      P3_FUN1 &= 0x0F; P3_FUN1 |= 0xA0     //P33端口作为CAP0功能
#define  P33_FUN_MOSI      P3_FUN1 &= 0x0F; P3_FUN1 |= 0xB0     //P33端口作为MOSI功能
#define  P33_FUN_COM3      P3_FUN1 &= 0x0F; P3_FUN1 |= 0xF0     //P33端口作为COM3功能

#define  P34_FUN_IO        P3_FUN2 &= 0xF0                      //P34端口作为IO功能                                          
#define  P34_FUN_PWM00     P3_FUN2 &= 0xF0; P3_FUN2 |= 0x01     //P34端口作为PWM00功能
#define  P34_FUN_PWM10     P3_FUN2 &= 0xF0; P3_FUN2 |= 0x02     //P34端口作为PWM10功能
#define  P34_FUN_PWM20     P3_FUN2 &= 0xF0; P3_FUN2 |= 0x03     //P34端口作为PWM20功能
#define  P34_FUN_TX0       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x04     //P34端口作为TX0功能
#define  P34_FUN_RX0       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x05     //P34端口作为RX0功能
#define  P34_FUN_SCL       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x06     //P34端口作为SCL功能
#define  P34_FUN_SDA       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x07     //P34端口作为SDA功能
#define  P34_FUN_T3G       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x08     //P34端口作为T3G功能
#define  P34_FUN_TIN0      P3_FUN2 &= 0xF0; P3_FUN2 |= 0x09     //P34端口作为TIN0功能
#define  P34_FUN_TO0       P3_FUN2 &= 0xF0; P3_FUN2 |= 0x09     //P34端口作为TO0功能
#define  P34_FUN_CAP1      P3_FUN2 &= 0xF0; P3_FUN2 |= 0x0A     //P34端口作为CAP1功能
#define  P34_FUN_COM4      P3_FUN2 &= 0xF0; P3_FUN2 |= 0x0F     //P34端口作为COM4功能

#define  P35_FUN_IO        P3_FUN2 &= 0x0F                      //P35端口作为IO功能                 
#define  P35_FUN_PWM01     P3_FUN2 &= 0x0F; P3_FUN2 |= 0x10     //P35端口作为PWM10功能
#define  P35_FUN_PWM11     P3_FUN2 &= 0x0F; P3_FUN2 |= 0x20     //P35端口作为PWM11功能
#define  P35_FUN_PWM21     P3_FUN2 &= 0x0F; P3_FUN2 |= 0x30     //P35端口作为PWM21功能
#define  P35_FUN_TX0       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x40     //P35端口作为TX0功能
#define  P35_FUN_RX0       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x50     //P35端口作为RX0功能
#define  P35_FUN_SCL       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x60     //P35端口作为SCL功能
#define  P35_FUN_SDA       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x70     //P35端口作为SDA功能
#define  P35_FUN_T2G       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x80     //P35端口作为T2G功能
#define  P35_FUN_TIN1      P3_FUN2 &= 0x0F; P3_FUN2 |= 0x90     //P35端口作为TIN1功能
#define  P35_FUN_TO1       P3_FUN2 &= 0x0F; P3_FUN2 |= 0x90     //P35端口作为TO1功能
#define  P35_FUN_CAP2      P3_FUN2 &= 0x0F; P3_FUN2 |= 0xA0     //P35端口作为CAP2功能
#define  P35_FUN_COM5      P3_FUN2 &= 0x0F; P3_FUN2 |= 0xF0     //P35端口作为COM5功能

#define  P36_FUN_IO        P3_FUN3 &= 0xF0                      //P36端口作为IO功能                 
#define  P36_FUN_PWM00     P3_FUN3 &= 0xF0; P3_FUN3 |= 0x01     //P36端口作为PWM00功能
#define  P36_FUN_PWM10     P3_FUN3 &= 0xF0; P3_FUN3 |= 0x02     //P36端口作为PWM10功能
#define  P36_FUN_PWM20     P3_FUN3 &= 0xF0; P3_FUN3 |= 0x03     //P36端口作为PWM20功能
#define  P36_FUN_TX1       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x04     //P36端口作为TX1功能
#define  P36_FUN_RX1       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x05     //P36端口作为RX1功能
#define  P36_FUN_SCL       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x06     //P36端口作为SCL功能
#define  P36_FUN_SDA       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x07     //P36端口作为SDA功能
#define  P36_FUN_T1G       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x08     //P36端口作为T1G功能
#define  P36_FUN_TIN0      P3_FUN3 &= 0xF0; P3_FUN3 |= 0x09     //P36端口作为TIN0功能
#define  P36_FUN_TO0       P3_FUN3 &= 0xF0; P3_FUN3 |= 0x09     //P36端口作为TO0功能
#define  P36_FUN_CAP0      P3_FUN3 &= 0xF0; P3_FUN3 |= 0x0A     //P36端口作为CAP0功能
#define  P36_FUN_COM6      P3_FUN3 &= 0xF0; P3_FUN3 |= 0x0F     //P36端口作为COM6功能

#define  P37_FUN_IO        P3_FUN3 &= 0x0F                      //P37端口作为IO功能                 
#define  P37_FUN_PWM01     P3_FUN3 &= 0x0F; P3_FUN3 |= 0x10     //P37端口作为PWM10功能
#define  P37_FUN_PWM11     P3_FUN3 &= 0x0F; P3_FUN3 |= 0x20     //P37端口作为PWM11功能
#define  P37_FUN_PWM21     P3_FUN3 &= 0x0F; P3_FUN3 |= 0x30     //P37端口作为PWM21功能
#define  P37_FUN_TX1       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x40     //P37端口作为TX1功能
#define  P37_FUN_RX1       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x50     //P37端口作为RX1功能
#define  P37_FUN_SCL       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x60     //P37端口作为SCL功能
#define  P37_FUN_SDA       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x70     //P37端口作为SDA功能
#define  P37_FUN_T0G       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x80     //P37端口作为T0G功能
#define  P37_FUN_TIN1      P3_FUN3 &= 0x0F; P3_FUN3 |= 0x90     //P37端口作为TIN1功能
#define  P37_FUN_TO1       P3_FUN3 &= 0x0F; P3_FUN3 |= 0x90     //P37端口作为TO1功能
#define  P37_FUN_CAP1      P3_FUN3 &= 0x0F; P3_FUN3 |= 0xA0     //P37端口作为CAP1功能
#define  P37_FUN_COM7      P3_FUN3 &= 0x0F; P3_FUN3 |= 0xF0     //P37端口作为COM7功能

//输出控制
#define  P00_SET    P0_0 = 1                                    //P00端口输出高电平
#define  P01_SET    P0_1 = 1                                    //P01端口输出高电平
#define  P02_SET    P0_2 = 1                                    //P02端口输出高电平
#define  P03_SET    P0_3 = 1                                    //P03端口输出高电平
#define  P04_SET    P0_4 = 1                                    //P04端口输出高电平
#define  P05_SET    P0_5 = 1                                    //P05端口输出高电平
#define  P0_SET     P0_DAT = 0x3F                               //P0 端口输出高电平

#define  P10_SET    P1_0 = 1                                    //P10端口输出高电平
#define  P11_SET    P1_1 = 1                                    //P11端口输出高电平
#define  P12_SET    P1_2 = 1                                    //P12端口输出高电平
#define  P13_SET    P1_3 = 1                                    //P13端口输出高电平
#define  P14_SET    P1_4 = 1                                    //P14端口输出高电平
#define  P15_SET    P1_5 = 1                                    //P15端口输出高电平
#define  P16_SET    P1_6 = 1                                    //P16端口输出高电平
#define  P17_SET    P1_7 = 1                                    //P17端口输出高电平
#define  P1_SET     P1_DAT = 0xFF                               //P1 端口输出高电平

#define  P20_SET    P2_0 = 1                                    //P20端口输出高电平
#define  P21_SET    P2_1 = 1                                    //P21端口输出高电平
#define  P22_SET    P2_2 = 1                                    //P22端口输出高电平
#define  P23_SET    P2_3 = 1                                    //P23端口输出高电平
#define  P24_SET    P2_4 = 1                                    //P24端口输出高电平
#define  P25_SET    P2_5 = 1                                    //P25端口输出高电平
#define  P26_SET    P2_6 = 1                                    //P26端口输出高电平
#define  P27_SET    P2_7 = 1                                    //P27端口输出高电平
#define  P2_SET     P2_DAT = 0xFF                               //P2 端口输出高电平

#define  P30_SET    P3_0 = 1                                    //P30端口输出高电平
#define  P31_SET    P3_1 = 1                                    //P31端口输出高电平
#define  P32_SET    P3_2 = 1                                    //P32端口输出高电平
#define  P33_SET    P3_3 = 1                                    //P33端口输出高电平
#define  P34_SET    P3_4 = 1                                    //P34端口输出高电平
#define  P35_SET    P3_5 = 1                                    //P35端口输出高电平
#define  P36_SET    P3_6 = 1                                    //P36端口输出高电平
#define  P37_SET    P3_7 = 1                                    //P37端口输出高电平
#define  P3_SET     P3_DAT = 0xFF                               //P3 端口输出高电平


#define  P00_CLR    P0_0 = 0                                    //P00端口输出低电平
#define  P01_CLR    P0_1 = 0                                    //P01端口输出低电平
#define  P02_CLR    P0_2 = 0                                    //P02端口输出低电平
#define  P03_CLR    P0_3 = 0                                    //P03端口输出低电平
#define  P04_CLR    P0_4 = 0                                    //P04端口输出低电平
#define  P05_CLR    P0_5 = 0                                    //P05端口输出低电平
#define  P0_CLR     P0_DAT = 0x00                               //P0 端口输出低电平

#define  P10_CLR    P1_0 = 0                                    //P10端口输出低电平
#define  P11_CLR    P1_1 = 0                                    //P11端口输出低电平
#define  P12_CLR    P1_2 = 0                                    //P12端口输出低电平
#define  P13_CLR    P1_3 = 0                                    //P13端口输出低电平
#define  P14_CLR    P1_4 = 0                                    //P14端口输出低电平
#define  P15_CLR    P1_5 = 0                                    //P15端口输出低电平
#define  P16_CLR    P1_6 = 0                                    //P16端口输出低电平
#define  P17_CLR    P1_7 = 0                                    //P17端口输出低电平
#define  P1_CLR     P1_DAT = 0x00                               //P1 端口输出低电平

#define  P20_CLR    P2_0 = 0                                    //P20端口输出低电平
#define  P21_CLR    P2_1 = 0                                    //P21端口输出低电平
#define  P22_CLR    P2_2 = 0                                    //P22端口输出低电平
#define  P23_CLR    P2_3 = 0                                    //P23端口输出低电平
#define  P24_CLR    P2_4 = 0                                    //P24端口输出低电平
#define  P25_CLR    P2_5 = 0                                    //P25端口输出低电平
#define  P26_CLR    P2_6 = 0                                    //P26端口输出低电平
#define  P27_CLR    P2_7 = 0                                    //P27端口输出低电平
#define  P2_CLR     P2_DAT = 0x00                               //P2 端口输出低电平

#define  P30_CLR    P3_0 = 0                                    //P30端口输出低电平
#define  P31_CLR    P3_1 = 0                                    //P31端口输出低电平
#define  P32_CLR    P3_2 = 0                                    //P32端口输出低电平
#define  P33_CLR    P3_3 = 0                                    //P33端口输出低电平
#define  P34_CLR    P3_4 = 0                                    //P34端口输出低电平
#define  P35_CLR    P3_5 = 0                                    //P35端口输出低电平
#define  P36_CLR    P3_6 = 0                                    //P36端口输出低电平
#define  P37_CLR    P3_7 = 0                                    //P37端口输出低电平
#define  P3_CLR     P3_DAT = 0x00                               //P3 端口输出低电平

#define  P00_REVS    P0_0 ^= 1                                  //P10端口电平翻转  
#define  P01_REVS    P0_1 ^= 1                                  //P11端口电平翻转  
#define  P02_REVS    P0_2 ^= 1                                  //P12端口电平翻转  
#define  P03_REVS    P0_3 ^= 1                                  //P13端口电平翻转  
#define  P04_REVS    P0_4 ^= 1                                  //P14端口电平翻转  
#define  P05_REVS    P0_5 ^= 1                                  //P15端口电平翻转  
#define  P0_REVS     P0_DAT ^= 0x3F                             //P1 端口电平翻转  

#define  P10_REVS    P1_0 ^= 1                                  //P10端口电平翻转  
#define  P11_REVS    P1_1 ^= 1                                  //P11端口电平翻转  
#define  P12_REVS    P1_2 ^= 1                                  //P12端口电平翻转  
#define  P13_REVS    P1_3 ^= 1                                  //P13端口电平翻转  
#define  P14_REVS    P1_4 ^= 1                                  //P14端口电平翻转  
#define  P15_REVS    P1_5 ^= 1                                  //P15端口电平翻转  
#define  P16_REVS    P1_6 ^= 1                                  //P16端口电平翻转  
#define  P17_REVS    P1_7 ^= 1                                  //P17端口电平翻转  
#define  P1_REVS     P1_DAT ^= 0xFF                             //P1 端口电平翻转  

#define  P20_REVS    P2_0 ^= 1                                  //P20端口电平翻转                    
#define  P21_REVS    P2_1 ^= 1                                  //P21端口电平翻转  
#define  P22_REVS    P2_2 ^= 1                                  //P22端口电平翻转  
#define  P23_REVS    P2_3 ^= 1                                  //P23端口电平翻转  
#define  P24_REVS    P2_4 ^= 1                                  //P24端口电平翻转  
#define  P25_REVS    P2_5 ^= 1                                  //P25端口电平翻转  
#define  P26_REVS    P2_6 ^= 1                                  //P26端口电平翻转  
#define  P27_REVS    P2_7 ^= 1                                  //P27端口电平翻转  
#define  P2_REVS     P2_DAT ^= 0xFF                             //P2 端口电平翻转  

#define  P30_REVS    P3_0 ^= 1                                  //P30端口电平翻转  
#define  P31_REVS    P3_1 ^= 1                                  //P31端口电平翻转  
#define  P32_REVS    P3_2 ^= 1                                  //P32端口电平翻转  
#define  P33_REVS    P3_3 ^= 1                                  //P33端口电平翻转  
#define  P34_REVS    P3_4 ^= 1                                  //P34端口电平翻转  
#define  P35_REVS    P3_5 ^= 1                                  //P35端口电平翻转  
#define  P36_REVS    P3_6 ^= 1                                  //P36端口电平翻转  
#define  P37_REVS    P3_7 ^= 1                                  //P37端口电平翻转  
#define  P3_REVS     P3_DAT ^= 0xFF                             //P3 端口电平翻转  

//IO输出设置                                                    
#define  P00_OUT_EN     P0_OE |= 0x01                           //P00端口使能输出功能          
#define  P01_OUT_EN     P0_OE |= 0x02                           //P01端口使能输出功能      
#define  P02_OUT_EN     P0_OE |= 0x04                           //P02端口使能输出功能      
#define  P03_OUT_EN     P0_OE |= 0x08                           //P03端口使能输出功能      
#define  P04_OUT_EN     P0_OE |= 0x10                           //P04端口使能输出功能      
#define  P05_OUT_EN     P0_OE |= 0x20                           //P05端口使能输出功能     
#define  P0_OUT_EN      P0_OE  = 0x3F                           //P0 端口使能输出功能       

#define  P00_OUT_DIS    P0_OE &= 0xFE                           //P00端口禁止输出功能    
#define  P01_OUT_DIS    P0_OE &= 0xFD                           //P01端口禁止输出功能    
#define  P02_OUT_DIS    P0_OE &= 0xFB                           //P02端口禁止输出功能    
#define  P03_OUT_DIS    P0_OE &= 0xF7                           //P03端口禁止输出功能    
#define  P04_OUT_DIS    P0_OE &= 0xEF                           //P04端口禁止输出功能    
#define  P05_OUT_DIS    P0_OE &= 0xDF                           //P05端口禁止输出功能    
#define  P0_OUT_DIS     P0_OE  = 0x00                           //P0 端口禁止输出功能    

#define  P10_OUT_EN     P1_OE |= 0x01                           //P10端口使能输出功能      
#define  P11_OUT_EN     P1_OE |= 0x02                           //P11端口使能输出功能    
#define  P12_OUT_EN     P1_OE |= 0x04                           //P12端口使能输出功能    
#define  P13_OUT_EN     P1_OE |= 0x08                           //P13端口使能输出功能    
#define  P14_OUT_EN     P1_OE |= 0x10                           //P14端口使能输出功能    
#define  P15_OUT_EN     P1_OE |= 0x20                           //P15端口使能输出功能   
#define  P16_OUT_EN     P1_OE |= 0x40                           //P16端口使能输出功能     
#define  P17_OUT_EN     P1_OE |= 0x80                           //P17端口使能输出功能     
#define  P1_OUT_EN      P1_OE  = 0xFF                           //P1 端口使能输出功能    

#define  P10_OUT_DIS    P1_OE &= 0xFE                           //P10端口禁止输出功能  
#define  P11_OUT_DIS    P1_OE &= 0xFD                           //P11端口禁止输出功能  
#define  P12_OUT_DIS    P1_OE &= 0xFB                           //P12端口禁止输出功能  
#define  P13_OUT_DIS    P1_OE &= 0xF7                           //P13端口禁止输出功能  
#define  P14_OUT_DIS    P1_OE &= 0xEF                           //P14端口禁止输出功能  
#define  P15_OUT_DIS    P1_OE &= 0xDF                           //P15端口禁止输出功能  
#define  P16_OUT_DIS    P1_OE &= 0xBF                           //P16端口禁止输出功能  
#define  P17_OUT_DIS    P1_OE &= 0x7F                           //P17端口禁止输出功能  
#define  P1_OUT_DIS     P1_OE  = 0x00                           //P1 端口禁止输出功能  

#define  P20_OUT_EN     P2_OE |= 0x01                           //P10端口使能输出功能      
#define  P21_OUT_EN     P2_OE |= 0x02                           //P11端口使能输出功能    
#define  P22_OUT_EN     P2_OE |= 0x04                           //P12端口使能输出功能    
#define  P23_OUT_EN     P2_OE |= 0x08                           //P13端口使能输出功能    
#define  P24_OUT_EN     P2_OE |= 0x10                           //P14端口使能输出功能    
#define  P25_OUT_EN     P2_OE |= 0x20                           //P15端口使能输出功能   
#define  P26_OUT_EN     P2_OE |= 0x40                           //P16端口使能输出功能     
#define  P27_OUT_EN     P2_OE |= 0x80                           //P17端口使能输出功能     
#define  P2_OUT_EN      P2_OE  = 0xFF                           //P1 端口使能输出功能    

#define  P20_OUT_DIS    P2_OE &= 0xFE                           //P10端口禁止输出功能  
#define  P21_OUT_DIS    P2_OE &= 0xFD                           //P11端口禁止输出功能  
#define  P22_OUT_DIS    P2_OE &= 0xFB                           //P12端口禁止输出功能  
#define  P23_OUT_DIS    P2_OE &= 0xF7                           //P13端口禁止输出功能  
#define  P24_OUT_DIS    P2_OE &= 0xEF                           //P14端口禁止输出功能  
#define  P25_OUT_DIS    P2_OE &= 0xDF                           //P15端口禁止输出功能  
#define  P26_OUT_DIS    P2_OE &= 0xBF                           //P16端口禁止输出功能  
#define  P27_OUT_DIS    P2_OE &= 0x7F                           //P17端口禁止输出功能  
#define  P2_OUT_DIS     P2_OE  = 0x00                           //P1 端口禁止输出功能  

#define  P30_OUT_EN     P3_OE |= 0x01                           //P10端口使能输出功能      
#define  P31_OUT_EN     P3_OE |= 0x02                           //P11端口使能输出功能    
#define  P32_OUT_EN     P3_OE |= 0x04                           //P12端口使能输出功能    
#define  P33_OUT_EN     P3_OE |= 0x08                           //P13端口使能输出功能    
#define  P34_OUT_EN     P3_OE |= 0x10                           //P14端口使能输出功能    
#define  P35_OUT_EN     P3_OE |= 0x20                           //P15端口使能输出功能   
#define  P36_OUT_EN     P3_OE |= 0x40                           //P16端口使能输出功能     
#define  P37_OUT_EN     P3_OE |= 0x80                           //P17端口使能输出功能     
#define  P3_OUT_EN      P3_OE  = 0xFF                           //P1 端口使能输出功能    

#define  P30_OUT_DIS    P3_OE &= 0xFE                           //P10端口禁止输出功能  
#define  P31_OUT_DIS    P3_OE &= 0xFD                           //P11端口禁止输出功能  
#define  P32_OUT_DIS    P3_OE &= 0xFB                           //P12端口禁止输出功能  
#define  P33_OUT_DIS    P3_OE &= 0xF7                           //P13端口禁止输出功能  
#define  P34_OUT_DIS    P3_OE &= 0xEF                           //P14端口禁止输出功能  
#define  P35_OUT_DIS    P3_OE &= 0xDF                           //P15端口禁止输出功能  
#define  P36_OUT_DIS    P3_OE &= 0xBF                           //P16端口禁止输出功能  
#define  P37_OUT_DIS    P3_OE &= 0x7F                           //P17端口禁止输出功能  
#define  P3_OUT_DIS     P3_OE  = 0x00                           //P1 端口禁止输出功能  

//IO输入设置
#define  P00_IN_EN      P0_IE |= 0x01                           //P00端口使能输入功能          
#define  P01_IN_EN      P0_IE |= 0x02                           //P01端口使能输入功能      
#define  P02_IN_EN      P0_IE |= 0x04                           //P02端口使能输入功能      
#define  P03_IN_EN      P0_IE |= 0x08                           //P03端口使能输入功能      
#define  P04_IN_EN      P0_IE |= 0x10                           //P04端口使能输入功能      
#define  P05_IN_EN      P0_IE |= 0x20                           //P05端口使能输入功能     
#define  P0_IN_EN       P0_IE  = 0x3F                           //P0 端口使能输入功能       

#define  P00_IN_DIS     P0_IE &= 0xFE                           //P00端口禁止输入功能    
#define  P01_IN_DIS     P0_IE &= 0xFD                           //P01端口禁止输入功能    
#define  P02_IN_DIS     P0_IE &= 0xFB                           //P02端口禁止输入功能    
#define  P03_IN_DIS     P0_IE &= 0xF7                           //P03端口禁止输入功能    
#define  P04_IN_DIS     P0_IE &= 0xEF                           //P04端口禁止输入功能    
#define  P05_IN_DIS     P0_IE &= 0xDF                           //P05端口禁止输入功能    
#define  P0_IN_DIS      P0_IE  = 0x00                           //P0 端口禁止输入功能    

#define  P10_IN_EN      P1_IE |= 0x01                           //P10端口使能输入功能      
#define  P11_IN_EN      P1_IE |= 0x02                           //P11端口使能输入功能    
#define  P12_IN_EN      P1_IE |= 0x04                           //P12端口使能输入功能    
#define  P13_IN_EN      P1_IE |= 0x08                           //P13端口使能输入功能    
#define  P14_IN_EN      P1_IE |= 0x10                           //P14端口使能输入功能    
#define  P15_IN_EN      P1_IE |= 0x20                           //P15端口使能输入功能   
#define  P16_IN_EN      P1_IE |= 0x40                           //P16端口使能输入功能     
#define  P17_IN_EN      P1_IE |= 0x80                           //P17端口使能输入功能     
#define  P1_IN_EN       P1_IE  = 0xFF                           //P1 端口使能输入功能    

#define  P10_IN_DIS     P1_IE &= 0xFE                           //P10端口禁止输入功能  
#define  P11_IN_DIS     P1_IE &= 0xFD                           //P11端口禁止输入功能  
#define  P12_IN_DIS     P1_IE &= 0xFB                           //P12端口禁止输入功能  
#define  P13_IN_DIS     P1_IE &= 0xF7                           //P13端口禁止输入功能  
#define  P14_IN_DIS     P1_IE &= 0xEF                           //P14端口禁止输入功能  
#define  P15_IN_DIS     P1_IE &= 0xDF                           //P15端口禁止输入功能  
#define  P16_IN_DIS     P1_IE &= 0xBF                           //P16端口禁止输入功能  
#define  P17_IN_DIS     P1_IE &= 0x7F                           //P17端口禁止输入功能  
#define  P1_IN_DIS      P1_IE  = 0x00                           //P1 端口禁止输入功能  

#define  P20_IN_EN      P2_IE |= 0x01                           //P20端口使能输入功能  
#define  P21_IN_EN      P2_IE |= 0x02                           //P21端口使能输入功能  
#define  P22_IN_EN      P2_IE |= 0x04                           //P22端口使能输入功能  
#define  P23_IN_EN      P2_IE |= 0x08                           //P23端口使能输入功能  
#define  P24_IN_EN      P2_IE |= 0x10                           //P24端口使能输入功能  
#define  P25_IN_EN      P2_IE |= 0x20                           //P25端口使能输入功能  
#define  P26_IN_EN      P2_IE |= 0x40                           //P26端口使能输入功能  
#define  P27_IN_EN      P2_IE |= 0x80                           //P27端口使能输入功能  
#define  P2_IN_EN       P2_IE  = 0xFF                           //P2 端口使能输入功能  

#define  P20_IN_DIS     P2_IE &= 0xFE                           //P20端口禁止输入功能
#define  P21_IN_DIS     P2_IE &= 0xFD                           //P21端口禁止输入功能
#define  P22_IN_DIS     P2_IE &= 0xFB                           //P22端口禁止输入功能
#define  P23_IN_DIS     P2_IE &= 0xF7                           //P23端口禁止输入功能
#define  P24_IN_DIS     P2_IE &= 0xEF                           //P24端口禁止输入功能
#define  P25_IN_DIS     P2_IE &= 0xDF                           //P25端口禁止输入功能
#define  P26_IN_DIS     P2_IE &= 0xBF                           //P26端口禁止输入功能
#define  P27_IN_DIS     P2_IE &= 0x7F                           //P27端口禁止输入功能
#define  P2_IN_DIS      P2_IE  = 0x00                           //P2 端口禁止输入功能

#define  P30_IN_EN      P3_IE |= 0x01                           //P30端口使能输入功能  
#define  P31_IN_EN      P3_IE |= 0x02                           //P31端口使能输入功能  
#define  P32_IN_EN      P3_IE |= 0x04                           //P32端口使能输入功能  
#define  P33_IN_EN      P3_IE |= 0x08                           //P33端口使能输入功能  
#define  P34_IN_EN      P3_IE |= 0x10                           //P34端口使能输入功能  
#define  P35_IN_EN      P3_IE |= 0x20                           //P35端口使能输入功能  
#define  P36_IN_EN      P3_IE |= 0x40                           //P36端口使能输入功能  
#define  P37_IN_EN      P3_IE |= 0x80                           //P37端口使能输入功能  
#define  P3_IN_EN       P3_IE  = 0xFF                           //P3 端口使能输入功能  

#define  P30_IN_DIS     P3_IE &= 0xFE                           //P30端口禁止输入功能
#define  P31_IN_DIS     P3_IE &= 0xFD                           //P31端口禁止输入功能
#define  P32_IN_DIS     P3_IE &= 0xFB                           //P32端口禁止输入功能
#define  P33_IN_DIS     P3_IE &= 0xF7                           //P33端口禁止输入功能
#define  P34_IN_DIS     P3_IE &= 0xEF                           //P34端口禁止输入功能
#define  P35_IN_DIS     P3_IE &= 0xDF                           //P35端口禁止输入功能
#define  P36_IN_DIS     P3_IE &= 0xBF                           //P36端口禁止输入功能
#define  P37_IN_DIS     P3_IE &= 0x7F                           //P37端口禁止输入功能
#define  P3_IN_DIS      P3_IE  = 0x00                           //P3 端口禁止输入功能

//上拉设置
#define  P00_PU_EN     P0_PUE |= 0x01                           //P00端口使能弱上拉功能
#define  P01_PU_EN     P0_PUE |= 0x02                           //P01端口使能弱上拉功能
#define  P02_PU_EN     P0_PUE |= 0x04                           //P02端口使能弱上拉功能
#define  P03_PU_EN     P0_PUE |= 0x08                           //P03端口使能弱上拉功能
#define  P04_PU_EN     P0_PUE |= 0x10                           //P04端口使能弱上拉功能
#define  P05_PU_EN     P0_PUE |= 0x20                           //P05端口使能弱上拉功能
#define  P0_PU_EN      P0_PUE = 0x3f                            //P0 端口使能弱上拉功能

#define  P00_PU_DIS    P0_PUE &= 0xfe                           //P00端口禁止弱上拉功能
#define  P01_PU_DIS    P0_PUE &= 0xfd                           //P01端口禁止弱上拉功能
#define  P02_PU_DIS    P0_PUE &= 0xfb                           //P02端口禁止弱上拉功能
#define  P03_PU_DIS    P0_PUE &= 0xf7                           //P03端口禁止弱上拉功能
#define  P04_PU_DIS    P0_PUE &= 0xef                           //P04端口禁止弱上拉功能
#define  P05_PU_DIS    P0_PUE &= 0xdf                           //P05端口禁止弱上拉功能
#define  P0_PU_DIS     P0_PUE = 0x00                            //P0 端口禁止弱上拉功能

#define  P10_PU_EN     P1_PUE |= 0x01                           //P10端口使能弱上拉功能
#define  P11_PU_EN     P1_PUE |= 0x02                           //P11端口使能弱上拉功能
#define  P12_PU_EN     P1_PUE |= 0x04                           //P12端口使能弱上拉功能
#define  P13_PU_EN     P1_PUE |= 0x08                           //P13端口使能弱上拉功能
#define  P14_PU_EN     P1_PUE |= 0x10                           //P14端口使能弱上拉功能
#define  P15_PU_EN     P1_PUE |= 0x20                           //P15端口使能弱上拉功能
#define  P16_PU_EN     P1_PUE |= 0x40                           //P16端口使能弱上拉功能
#define  P17_PU_EN     P1_PUE |= 0x80                           //P17端口使能弱上拉功能
#define  P1_PU_EN      P1_PUE = 0xff                            //P1 端口使能弱上拉功能

#define  P10_PU_DIS    P1_PUE &= 0xfe                           //P10端口禁止弱上拉功能
#define  P11_PU_DIS    P1_PUE &= 0xfd                           //P11端口禁止弱上拉功能
#define  P12_PU_DIS    P1_PUE &= 0xfb                           //P12端口禁止弱上拉功能
#define  P13_PU_DIS    P1_PUE &= 0xf7                           //P13端口禁止弱上拉功能
#define  P14_PU_DIS    P1_PUE &= 0xef                           //P14端口禁止弱上拉功能
#define  P15_PU_DIS    P1_PUE &= 0xdf                           //P15端口禁止弱上拉功能
#define  P16_PU_DIS    P1_PUE &= 0xbf                           //P16端口禁止弱上拉功能
#define  P17_PU_DIS    P1_PUE &= 0x7f                           //P17端口禁止弱上拉功能
#define  P1_PU_DIS     P1_PUE = 0x00                            //P1 端口禁止弱上拉功能

#define  P20_PU_EN     P2_PUE |= 0x01                           //P20端口使能弱上拉功能
#define  P21_PU_EN     P2_PUE |= 0x02                           //P21端口使能弱上拉功能
#define  P22_PU_EN     P2_PUE |= 0x04                           //P22端口使能弱上拉功能
#define  P23_PU_EN     P2_PUE |= 0x08                           //P23端口使能弱上拉功能
#define  P24_PU_EN     P2_PUE |= 0x10                           //P24端口使能弱上拉功能
#define  P25_PU_EN     P2_PUE |= 0x20                           //P25端口使能弱上拉功能
#define  P26_PU_EN     P2_PUE |= 0x40                           //P26端口使能弱上拉功能
#define  P27_PU_EN     P2_PUE |= 0x80                           //P27端口使能弱上拉功能
#define  P2_PU_EN      P2_PUE = 0xff                            //P2 端口使能弱上拉功能

#define  P20_PU_DIS    P2_PUE &= 0xfe                           //P20端口禁止弱上拉功能
#define  P21_PU_DIS    P2_PUE &= 0xfd                           //P21端口禁止弱上拉功能
#define  P22_PU_DIS    P2_PUE &= 0xfb                           //P22端口禁止弱上拉功能
#define  P23_PU_DIS    P2_PUE &= 0xf7                           //P23端口禁止弱上拉功能
#define  P24_PU_DIS    P2_PUE &= 0xef                           //P24端口禁止弱上拉功能
#define  P25_PU_DIS    P2_PUE &= 0xdf                           //P25端口禁止弱上拉功能
#define  P26_PU_DIS    P2_PUE &= 0xbf                           //P26端口禁止弱上拉功能
#define  P27_PU_DIS    P2_PUE &= 0x7f                           //P27端口禁止弱上拉功能
#define  P2_PU_DIS     P2_PUE = 0x00                            //P2 端口禁止弱上拉功能
    
#define  P30_PU_EN     P3_PUE |= 0x01                           //P30端口使能弱上拉功能
#define  P31_PU_EN     P3_PUE |= 0x02                           //P31端口使能弱上拉功能
#define  P32_PU_EN     P3_PUE |= 0x04                           //P32端口使能弱上拉功能
#define  P33_PU_EN     P3_PUE |= 0x08                           //P33端口使能弱上拉功能
#define  P34_PU_EN     P3_PUE |= 0x10                           //P34端口使能弱上拉功能
#define  P35_PU_EN     P3_PUE |= 0x20                           //P35端口使能弱上拉功能
#define  P36_PU_EN     P3_PUE |= 0x40                           //P36端口使能弱上拉功能
#define  P37_PU_EN     P3_PUE |= 0x80                           //P37端口使能弱上拉功能
#define  P3_PU_EN      P3_PUE = 0xff                            //P3 端口使能弱上拉功能

#define  P30_PU_DIS    P3_PUE &= 0xfe                           //P30端口禁止弱上拉功能
#define  P31_PU_DIS    P3_PUE &= 0xfd                           //P31端口禁止弱上拉功能
#define  P32_PU_DIS    P3_PUE &= 0xfb                           //P32端口禁止弱上拉功能
#define  P33_PU_DIS    P3_PUE &= 0xf7                           //P33端口禁止弱上拉功能
#define  P34_PU_DIS    P3_PUE &= 0xef                           //P34端口禁止弱上拉功能
#define  P35_PU_DIS    P3_PUE &= 0xdf                           //P35端口禁止弱上拉功能
#define  P36_PU_DIS    P3_PUE &= 0xbf                           //P36端口禁止弱上拉功能
#define  P37_PU_DIS    P3_PUE &= 0x7f                           //P37端口禁止弱上拉功能
#define  P3_PU_DIS     P3_PUE = 0x00                            //P3 端口禁止弱上拉功能

//下拉设置
#define  P00_PD_EN     P0_PDE |= 0x01;                          //P00端口使能弱下拉功能
#define  P01_PD_EN     P0_PDE |= 0x02;                          //P01端口使能弱下拉功能
#define  P02_PD_EN     P0_PDE |= 0x04;                          //P02端口使能弱下拉功能
#define  P03_PD_EN     P0_PDE |= 0x08;                          //P03端口使能弱下拉功能
#define  P04_PD_EN     P0_PDE |= 0x10;                          //P04端口使能弱下拉功能
#define  P05_PD_EN     P0_PDE |= 0x20;                          //P05端口使能弱下拉功能
#define  P0_PD_EN      P0_PDE = 0x3f;                           //P0 端口使能弱下拉功能

#define  P00_PD_DIS    P0_PDE &= 0xfe;                          //P00端口禁止弱下拉功能
#define  P01_PD_DIS    P0_PDE &= 0xfd;                          //P01端口禁止弱下拉功能
#define  P02_PD_DIS    P0_PDE &= 0xfb;                          //P02端口禁止弱下拉功能
#define  P03_PD_DIS    P0_PDE &= 0xf7;                          //P03端口禁止弱下拉功能
#define  P04_PD_DIS    P0_PDE &= 0xef;                          //P04端口禁止弱下拉功能
#define  P05_PD_DIS    P0_PDE &= 0xdf;                          //P05端口禁止弱下拉功能
#define  P0_PD_DIS     P0_PDE = 0x00;                           //P0 端口禁止弱下拉功能

#define  P10_PD_EN     P1_PDE |= 0x01;                          //P10端口使能弱下拉功能
#define  P11_PD_EN     P1_PDE |= 0x02;                          //P11端口使能弱下拉功能
#define  P12_PD_EN     P1_PDE |= 0x04;                          //P12端口使能弱下拉功能
#define  P13_PD_EN     P1_PDE |= 0x08;                          //P13端口使能弱下拉功能
#define  P14_PD_EN     P1_PDE |= 0x10;                          //P14端口使能弱下拉功能
#define  P15_PD_EN     P1_PDE |= 0x20;                          //P15端口使能弱下拉功能
#define  P16_PD_EN     P1_PDE |= 0x40;                          //P16端口使能弱下拉功能
#define  P17_PD_EN     P1_PDE |= 0x80;                          //P17端口使能弱下拉功能
#define  P1_PD_EN      P1_PDE = 0xff;                           //P1 端口使能弱下拉功能

#define  P10_PD_DIS    P1_PDE &= 0xfe;                          //P10端口禁止弱下拉功能
#define  P11_PD_DIS    P1_PDE &= 0xfd;                          //P11端口禁止弱下拉功能
#define  P12_PD_DIS    P1_PDE &= 0xfb;                          //P12端口禁止弱下拉功能
#define  P13_PD_DIS    P1_PDE &= 0xf7;                          //P13端口禁止弱下拉功能
#define  P14_PD_DIS    P1_PDE &= 0xef;                          //P14端口禁止弱下拉功能
#define  P15_PD_DIS    P1_PDE &= 0xdf;                          //P15端口禁止弱下拉功能
#define  P16_PD_DIS    P1_PDE &= 0xbf;                          //P16端口禁止弱下拉功能
#define  P17_PD_DIS    P1_PDE &= 0x7f;                          //P17端口禁止弱下拉功能
#define  P1_PD_DIS     P1_PDE &= 0x00;                          //P1 端口禁止弱下拉功能

#define  P20_PD_EN     P2_PDE |= 0x01;                          //P20端口使能弱下拉功能
#define  P21_PD_EN     P2_PDE |= 0x02;                          //P21端口使能弱下拉功能
#define  P22_PD_EN     P2_PDE |= 0x04;                          //P22端口使能弱下拉功能
#define  P23_PD_EN     P2_PDE |= 0x08;                          //P23端口使能弱下拉功能
#define  P24_PD_EN     P2_PDE |= 0x10;                          //P24端口使能弱下拉功能
#define  P25_PD_EN     P2_PDE |= 0x20;                          //P25端口使能弱下拉功能
#define  P26_PD_EN     P2_PDE |= 0x40;                          //P26端口使能弱下拉功能
#define  P27_PD_EN     P2_PDE |= 0x80;                          //P27端口使能弱下拉功能
#define  P2_PD_EN      P2_PDE = 0xff;                           //P2 端口使能弱下拉功能

#define  P20_PD_DIS    P2_PDE &= 0xfe;                          //P20端口禁止弱下拉功能
#define  P21_PD_DIS    P2_PDE &= 0xfd;                          //P21端口禁止弱下拉功能
#define  P22_PD_DIS    P2_PDE &= 0xfb;                          //P22端口禁止弱下拉功能
#define  P23_PD_DIS    P2_PDE &= 0xf7;                          //P23端口禁止弱下拉功能
#define  P24_PD_DIS    P2_PDE &= 0xef;                          //P24端口禁止弱下拉功能
#define  P25_PD_DIS    P2_PDE &= 0xdf;                          //P25端口禁止弱下拉功能
#define  P26_PD_DIS    P2_PDE &= 0xbf;                          //P26端口禁止弱下拉功能
#define  P27_PD_DIS    P2_PDE &= 0x7f;                          //P27端口禁止弱下拉功能
#define  P2_PD_DIS     P2_PDE = 0x00;                           //P2 端口禁止弱下拉功能

#define  P30_PD_EN     P3_PDE |= 0x01;                          //P30端口使能弱下拉功能                        
#define  P31_PD_EN     P3_PDE |= 0x02;                          //P31端口使能弱下拉功能
#define  P32_PD_EN     P3_PDE |= 0x04;                          //P32端口使能弱下拉功能
#define  P33_PD_EN     P3_PDE |= 0x08;                          //P33端口使能弱下拉功能
#define  P34_PD_EN     P3_PDE |= 0x10;                          //P34端口使能弱下拉功能
#define  P35_PD_EN     P3_PDE |= 0x20;                          //P35端口使能弱下拉功能
#define  P36_PD_EN     P3_PDE |= 0x40;                          //P36端口使能弱下拉功能
#define  P37_PD_EN     P3_PDE |= 0x80;                          //P37端口使能弱下拉功能
#define  P3_PD_EN      P3_PDE = 0xff;                           //P3 端口使能弱下拉功能

#define  P30_PD_DIS    P3_PDE &= 0xfe;                          //P30端口禁止弱下拉功能
#define  P31_PD_DIS    P3_PDE &= 0xfd;                          //P31端口禁止弱下拉功能
#define  P32_PD_DIS    P3_PDE &= 0xfb;                          //P32端口禁止弱下拉功能
#define  P33_PD_DIS    P3_PDE &= 0xf7;                          //P33端口禁止弱下拉功能
#define  P34_PD_DIS    P3_PDE &= 0xef;                          //P34端口禁止弱下拉功能
#define  P35_PD_DIS    P3_PDE &= 0xdf;                          //P35端口禁止弱下拉功能
#define  P36_PD_DIS    P3_PDE &= 0xbf;                          //P36端口禁止弱下拉功能
#define  P37_PD_DIS    P3_PDE &= 0x7f;                          //P37端口禁止弱下拉功能
#define  P3_PD_DIS     P3_PDE &= 0x00;                          //P3 端口禁止弱下拉功能

//P0开漏设置，要求开漏端口电平不高于VDD电平
#define  P00_OD_EN     P0_ODE  |= 0x01                          //P10端口使能开漏功能
#define  P01_OD_EN     P0_ODE  |= 0x02                          //P11端口使能开漏功能
#define  P02_OD_EN     P0_ODE  |= 0x04                          //P12端口使能开漏功能
#define  P03_OD_EN     P0_ODE  |= 0x08                          //P13端口使能开漏功能
#define  P04_OD_EN     P0_ODE  |= 0x10                          //P14端口使能开漏功能
#define  P05_OD_EN     P0_ODE  |= 0x20                          //P15端口使能开漏功能
#define  P0_OD_EN      P0_ODE  = 0x3f                           //P1端口使能开漏功能

#define  P00_OD_DIS    P0_ODE  &= 0xfe                          //P10端口禁止开漏功能
#define  P01_OD_DIS    P0_ODE  &= 0xfd                          //P11端口禁止开漏功能
#define  P02_OD_DIS    P0_ODE  &= 0xfb                          //P12端口禁止开漏功能
#define  P03_OD_DIS    P0_ODE  &= 0xf7                          //P13端口禁止开漏功能
#define  P04_OD_DIS    P0_ODE  &= 0xef                          //P14端口禁止开漏功能
#define  P05_OD_DIS    P0_ODE  &= 0xdf                          //P15端口禁止开漏功能
#define  P0_OD_DIS     P0_ODE  = 0x00                           //P1端口禁止开漏功能

//P1开漏设置，要求开漏端口电平不高于VDD电平
#define  P10_OD_EN     P1_ODE  |= 0x01                          //P10端口使能开漏功能
#define  P11_OD_EN     P1_ODE  |= 0x02                          //P11端口使能开漏功能
#define  P12_OD_EN     P1_ODE  |= 0x04                          //P12端口使能开漏功能
#define  P13_OD_EN     P1_ODE  |= 0x08                          //P13端口使能开漏功能
#define  P14_OD_EN     P1_ODE  |= 0x10                          //P14端口使能开漏功能
#define  P15_OD_EN     P1_ODE  |= 0x20                          //P15端口使能开漏功能
#define  P16_OD_EN     P1_ODE  |= 0x40                          //P16端口使能开漏功能
#define  P17_OD_EN     P1_ODE  |= 0x80                          //P17端口使能开漏功能
#define  P1_OD_EN      P1_ODE  |= 0xff                          //P1 端口使能开漏功能

#define  P10_OD_DIS    P1_ODE  &= 0xfe                          //P10端口禁止开漏功能
#define  P11_OD_DIS    P1_ODE  &= 0xfd                          //P11端口禁止开漏功能
#define  P12_OD_DIS    P1_ODE  &= 0xfb                          //P12端口禁止开漏功能
#define  P13_OD_DIS    P1_ODE  &= 0xf7                          //P13端口禁止开漏功能
#define  P14_OD_DIS    P1_ODE  &= 0xef                          //P14端口禁止开漏功能
#define  P15_OD_DIS    P1_ODE  &= 0xdf                          //P15端口禁止开漏功能
#define  P16_OD_DIS    P1_ODE  &= 0xbf                          //P16端口禁止开漏功能
#define  P17_OD_DIS    P1_ODE  &= 0x7f                          //P17端口禁止开漏功能
#define  P1_OD_DIS     P1_ODE  = 0x00                           //P1 端口禁止开漏功能

//P2开漏设置，要求开漏端口电平不高于VDD电平
#define  P20_OD_EN     P2_ODE  |= 0x01                          //P20端口使能开漏功能
#define  P21_OD_EN     P2_ODE  |= 0x02                          //P21端口使能开漏功能
#define  P22_OD_EN     P2_ODE  |= 0x04                          //P22端口使能开漏功能
#define  P23_OD_EN     P2_ODE  |= 0x08                          //P23端口使能开漏功能
#define  P24_OD_EN     P2_ODE  |= 0x10                          //P24端口使能开漏功能
#define  P25_OD_EN     P2_ODE  |= 0x20                          //P25端口使能开漏功能
#define  P26_OD_EN     P2_ODE  |= 0x40                          //P26端口使能开漏功能
#define  P27_OD_EN     P2_ODE  |= 0x80                          //P27端口使能开漏功能
#define  P2_OD_EN      P2_ODE  = 0xff                           //P2 端口使能开漏功能

#define  P20_OD_DIS    P2_ODE  &= 0xfe                          //P20端口禁止开漏功能
#define  P21_OD_DIS    P2_ODE  &= 0xfd                          //P21端口禁止开漏功能
#define  P22_OD_DIS    P2_ODE  &= 0xfb                          //P22端口禁止开漏功能
#define  P23_OD_DIS    P2_ODE  &= 0xf7                          //P23端口禁止开漏功能
#define  P24_OD_DIS    P2_ODE  &= 0xef                          //P24端口禁止开漏功能
#define  P25_OD_DIS    P2_ODE  &= 0xdf                          //P25端口禁止开漏功能
#define  P26_OD_DIS    P2_ODE  &= 0xbf                          //P26端口禁止开漏功能
#define  P27_OD_DIS    P2_ODE  &= 0x7f                          //P27端口禁止开漏功能
#define  P2_OD_DIS     P2_ODE  = 0x00                           //P2 端口禁止开漏功能

//P3开漏设置，要求开漏端口电平不高于VDD电平
#define  P30_OD_EN     P3_ODE  |= 0x01                          //P30端口使能开漏功能
#define  P31_OD_EN     P3_ODE  |= 0x02                          //P31端口使能开漏功能
#define  P32_OD_EN     P3_ODE  |= 0x04                          //P32端口使能开漏功能
#define  P33_OD_EN     P3_ODE  |= 0x08                          //P33端口使能开漏功能
#define  P34_OD_EN     P3_ODE  |= 0x10                          //P34端口使能开漏功能
#define  P35_OD_EN     P3_ODE  |= 0x20                          //P35端口使能开漏功能
#define  P36_OD_EN     P3_ODE  |= 0x40                          //P36端口使能开漏功能
#define  P37_OD_EN     P3_ODE  |= 0x80                          //P37端口使能开漏功能
#define  P3_OD_EN      P3_ODE  = 0xff                           //P3 端口使能开漏功能

#define  P30_OD_DIS    P3_ODE  &= 0xfe                          //P30端口禁止开漏功能
#define  P31_OD_DIS    P3_ODE  &= 0xfd                          //P31端口禁止开漏功能
#define  P32_OD_DIS    P3_ODE  &= 0xfb                          //P32端口禁止开漏功能
#define  P33_OD_DIS    P3_ODE  &= 0xf7                          //P33端口禁止开漏功能
#define  P34_OD_DIS    P3_ODE  &= 0xef                          //P34端口禁止开漏功能
#define  P35_OD_DIS    P3_ODE  &= 0xdf                          //P35端口禁止开漏功能
#define  P36_OD_DIS    P3_ODE  &= 0xbf                          //P36端口禁止开漏功能
#define  P37_OD_DIS    P3_ODE  &= 0x7f                          //P37端口禁止开漏功能
#define  P3_OD_DIS     P3_ODE  = 0x00                           //P3 端口禁止开漏功能

//P0 SMITE SET
#define  P00_SMIT_EN     P0_SMITE  |= 0x01                      //P00端口使能施密特功能   
#define  P01_SMIT_EN     P0_SMITE  |= 0x02                      //P01端口使能施密特功能
#define  P02_SMIT_EN     P0_SMITE  |= 0x04                      //P02端口使能施密特功能
#define  P03_SMIT_EN     P0_SMITE  |= 0x08                      //P03端口使能施密特功能
#define  P04_SMIT_EN     P0_SMITE  |= 0x10                      //P04端口使能施密特功能
#define  P05_SMIT_EN     P0_SMITE  |= 0x20                      //P05端口使能施密特功能
#define  P0_SMIT_EN      P0_SMITE  |= 0x3f                      //P0 端口使能施密特功能

#define  P00_SMIT_DIS    P0_SMITE  &= 0xfe                      //P00端口禁止施密特功能
#define  P01_SMIT_DIS    P0_SMITE  &= 0xfd                      //P01端口禁止施密特功能
#define  P02_SMIT_DIS    P0_SMITE  &= 0xfb                      //P02端口禁止施密特功能
#define  P03_SMIT_DIS    P0_SMITE  &= 0xf7                      //P03端口禁止施密特功能
#define  P04_SMIT_DIS    P0_SMITE  &= 0xef                      //P04端口禁止施密特功能
#define  P05_SMIT_DIS    P0_SMITE  &= 0xdf                      //P05端口禁止施密特功能
#define  P0_SMIT_DIS     P0_SMITE  &= 0xc0                      //P0 端口禁止施密特功能

//P1 SMITE SET
#define  P10_SMIT_EN     P1_SMITE  |= 0x01                      //P10端口使能施密特功能
#define  P11_SMIT_EN     P1_SMITE  |= 0x02                      //P11端口使能施密特功能
#define  P12_SMIT_EN     P1_SMITE  |= 0x04                      //P12端口使能施密特功能
#define  P13_SMIT_EN     P1_SMITE  |= 0x08                      //P13端口使能施密特功能
#define  P14_SMIT_EN     P1_SMITE  |= 0x10                      //P14端口使能施密特功能
#define  P15_SMIT_EN     P1_SMITE  |= 0x20                      //P15端口使能施密特功能
#define  P16_SMIT_EN     P1_SMITE  |= 0x40                      //P16端口使能施密特功能
#define  P17_SMIT_EN     P1_SMITE  |= 0x80                      //P17端口使能施密特功能
#define  P1_SMIT_EN      P1_SMITE  = 0xff                       //P1 端口使能施密特功能

#define  P10_SMIT_DIS    P1_SMITE  &= 0xfe                      //P10端口禁止施密特功能
#define  P11_SMIT_DIS    P1_SMITE  &= 0xfd                      //P11端口禁止施密特功能
#define  P12_SMIT_DIS    P1_SMITE  &= 0xfb                      //P12端口禁止施密特功能
#define  P13_SMIT_DIS    P1_SMITE  &= 0xf7                      //P13端口禁止施密特功能
#define  P14_SMIT_DIS    P1_SMITE  &= 0xef                      //P14端口禁止施密特功能
#define  P15_SMIT_DIS    P1_SMITE  &= 0xdf                      //P15端口禁止施密特功能
#define  P16_SMIT_DIS    P1_SMITE  &= 0xbf                      //P16端口禁止施密特功能
#define  P17_SMIT_DIS    P1_SMITE  &= 0x7f                      //P17端口禁止施密特功能
#define  P1_SMIT_DIS     P1_SMITE  = 0x00                       //P1 端口禁止施密特功能

//P2 SMITE SET

#define  P20_SMIT_EN     P2_SMITE  |= 0x01                      //P20端口使能施密特功能
#define  P21_SMIT_EN     P2_SMITE  |= 0x02                      //P21端口使能施密特功能
#define  P22_SMIT_EN     P2_SMITE  |= 0x04                      //P22端口使能施密特功能
#define  P23_SMIT_EN     P2_SMITE  |= 0x08                      //P23端口使能施密特功能
#define  P24_SMIT_EN     P2_SMITE  |= 0x10                      //P24端口使能施密特功能
#define  P25_SMIT_EN     P2_SMITE  |= 0x20                      //P25端口使能施密特功能
#define  P26_SMIT_EN     P2_SMITE  |= 0x40                      //P26端口使能施密特功能
#define  P27_SMIT_EN     P2_SMITE  |= 0x80                      //P27端口使能施密特功能
#define  P2_SMIT_EN      P2_SMITE  = 0xff                       //P2 端口使能施密特功能

#define  P20_SMIT_DIS    P2_SMITE  &= 0xfe                      //P20端口禁止施密特功能
#define  P21_SMIT_DIS    P2_SMITE  &= 0xfd                      //P21端口禁止施密特功能
#define  P22_SMIT_DIS    P2_SMITE  &= 0xfb                      //P22端口禁止施密特功能
#define  P23_SMIT_DIS    P2_SMITE  &= 0xf7                      //P23端口禁止施密特功能
#define  P24_SMIT_DIS    P2_SMITE  &= 0xef                      //P24端口禁止施密特功能
#define  P25_SMIT_DIS    P2_SMITE  &= 0xdf                      //P25端口禁止施密特功能
#define  P26_SMIT_DIS    P2_SMITE  &= 0xbf                      //P26端口禁止施密特功能
#define  P27_SMIT_DIS    P2_SMITE  &= 0x7f                      //P27端口禁止施密特功能
#define  P2_SMIT_DIS     P2_SMITE  = 0x00                       //P2 端口禁止施密特功能

//P3 SMITE SET

#define  P30_SMIT_EN     P3_SMITE  |= 0x01                      //P30端口使能施密特功能
#define  P31_SMIT_EN     P3_SMITE  |= 0x02                      //P31端口使能施密特功能
#define  P32_SMIT_EN     P3_SMITE  |= 0x04                      //P32端口使能施密特功能
#define  P33_SMIT_EN     P3_SMITE  |= 0x08                      //P33端口使能施密特功能
#define  P34_SMIT_EN     P3_SMITE  |= 0x10                      //P34端口使能施密特功能
#define  P35_SMIT_EN     P3_SMITE  |= 0x20                      //P35端口使能施密特功能
#define  P36_SMIT_EN     P3_SMITE  |= 0x40                      //P36端口使能施密特功能
#define  P37_SMIT_EN     P3_SMITE  |= 0x80                      //P37端口使能施密特功能
#define  P3_SMIT_EN      P3_SMITE  = 0xff                       //P3 端口使能施密特功能

#define  P30_SMIT_DIS    P3_SMITE  &= 0xfe                      //P30端口禁止施密特功能
#define  P31_SMIT_DIS    P3_SMITE  &= 0xfd                      //P31端口禁止施密特功能
#define  P32_SMIT_DIS    P3_SMITE  &= 0xfb                      //P32端口禁止施密特功能
#define  P33_SMIT_DIS    P3_SMITE  &= 0xf7                      //P33端口禁止施密特功能
#define  P34_SMIT_DIS    P3_SMITE  &= 0xef                      //P34端口禁止施密特功能
#define  P35_SMIT_DIS    P3_SMITE  &= 0xdf                      //P35端口禁止施密特功能
#define  P36_SMIT_DIS    P3_SMITE  &= 0xbf                      //P36端口禁止施密特功能
#define  P37_SMIT_DIS    P3_SMITE  &= 0x7f                      //P37端口禁止施密特功能
#define  P3_SMIT_DIS     P3_SMITE  = 0x00                       //P3 端口禁止施密特功能

//P0 IOH SET  高电平驱动电流设置
#define  P00_IOH_SET0    P0_IOH_CL &= 0xFC                      //P00端口高电平驱动电流15MA
#define  P00_IOH_SET1    P0_IOH_CL &= 0xFC;P0_IOH_CL |= 0x01    //P00端口高电平驱动电流1MA
#define  P00_IOH_SET2    P0_IOH_CL &= 0xFC;P0_IOH_CL |= 0x02    //P00端口高电平驱动电流2MA
#define  P00_IOH_SET3    P0_IOH_CL &= 0xFC;P0_IOH_CL |= 0x03    //P00端口高电平驱动电流4MA

#define  P01_IOH_SET0    P0_IOH_CL &= 0xF3                      //P01端口高电平驱动电流15MA
#define  P01_IOH_SET1    P0_IOH_CL &= 0xF3;P0_IOH_CL |= 0x04    //P01端口高电平驱动电流1MA
#define  P01_IOH_SET2    P0_IOH_CL &= 0xF3;P0_IOH_CL |= 0x08    //P01端口高电平驱动电流2MA
#define  P01_IOH_SET3    P0_IOH_CL &= 0xF3;P0_IOH_CL |= 0x0C    //P01端口高电平驱动电流4MA

#define  P02_IOH_SET0    P0_IOH_CL &= 0xCF                      //P02端口高电平驱动电流15MA
#define  P02_IOH_SET1    P0_IOH_CL &= 0xCF;P0_IOH_CL |= 0x10    //P02端口高电平驱动电流1MA
#define  P02_IOH_SET2    P0_IOH_CL &= 0xCF;P0_IOH_CL |= 0x20    //P02端口高电平驱动电流2MA
#define  P02_IOH_SET3    P0_IOH_CL &= 0xCF;P0_IOH_CL |= 0x30    //P02端口高电平驱动电流4MA

#define  P03_IOH_SET0    P0_IOH_CL &= 0x3F                      //P03端口高电平驱动电流15MA
#define  P03_IOH_SET1    P0_IOH_CL &= 0x3F;P0_IOH_CL |= 0x40    //P03端口高电平驱动电流1MA
#define  P03_IOH_SET2    P0_IOH_CL &= 0x3F;P0_IOH_CL |= 0x80    //P03端口高电平驱动电流2MA
#define  P03_IOH_SET3    P0_IOH_CL &= 0x3F;P0_IOH_CL |= 0xC0    //P03端口高电平驱动电流4MA

//P1 IOH SET    高电平驱动电流设置
#define  P10_IOH_SET0    P1_IOH_CL &= 0xFC                      //P10端口高电平驱动电流15MA       
#define  P10_IOH_SET1    P1_IOH_CL &= 0xFC;P1_IOH_CL |= 0x01    //P10端口高电平驱动电流1MA
#define  P10_IOH_SET2    P1_IOH_CL &= 0xFC;P1_IOH_CL |= 0x02    //P10端口高电平驱动电流2MA
#define  P10_IOH_SET3    P1_IOH_CL &= 0xFC;P1_IOH_CL |= 0x03    //P10端口高电平驱动电流4MA

#define  P11_IOH_SET0    P1_IOH_CL &= 0xF3                      //P11端口高电平驱动电流15MA
#define  P11_IOH_SET1    P1_IOH_CL &= 0xF3;P1_IOH_CL |= 0x04    //P11端口高电平驱动电流1MA
#define  P11_IOH_SET2    P1_IOH_CL &= 0xF3;P1_IOH_CL |= 0x08    //P11端口高电平驱动电流2MA
#define  P11_IOH_SET3    P1_IOH_CL &= 0xF3;P1_IOH_CL |= 0x0C    //P11端口高电平驱动电流4MA

#define  P12_IOH_SET0    P1_IOH_CL &= 0xCF                      //P12端口高电平驱动电流15MA
#define  P12_IOH_SET1    P1_IOH_CL &= 0xCF;P1_IOH_CL |= 0x10    //P12端口高电平驱动电流1MA
#define  P12_IOH_SET2    P1_IOH_CL &= 0xCF;P1_IOH_CL |= 0x20    //P12端口高电平驱动电流2MA
#define  P12_IOH_SET3    P1_IOH_CL &= 0xCF;P1_IOH_CL |= 0x30    //P12端口高电平驱动电流4MA

#define  P13_IOH_SET0    P1_IOH_CL &= 0x3F                      //P13端口高电平驱动电流15MA
#define  P13_IOH_SET1    P1_IOH_CL &= 0x3F;P1_IOH_CL |= 0x40    //P13端口高电平驱动电流1MA
#define  P13_IOH_SET2    P1_IOH_CL &= 0x3F;P1_IOH_CL |= 0x80    //P13端口高电平驱动电流2MA
#define  P13_IOH_SET3    P1_IOH_CL &= 0x3F;P1_IOH_CL |= 0xC0    //P13端口高电平驱动电流4MA

#define  P14_IOH_SET0    P1_IOH_CH &= 0xFC                      //P14端口高电平驱动电流15MA
#define  P14_IOH_SET1    P1_IOH_CH &= 0xFC;P1_IOH_CH |= 0x01    //P14端口高电平驱动电流1MA
#define  P14_IOH_SET2    P1_IOH_CH &= 0xFC;P1_IOH_CH |= 0x02    //P14端口高电平驱动电流2MA
#define  P14_IOH_SET3    P1_IOH_CH &= 0xFC;P1_IOH_CH |= 0x03    //P14端口高电平驱动电流4MA

#define  P15_IOH_SET0    P1_IOH_CH &= 0xF3                      //P15端口高电平驱动电流15MA
#define  P15_IOH_SET1    P1_IOH_CH &= 0xF3;P1_IOH_CH |= 0x04    //P15端口高电平驱动电流1MA
#define  P15_IOH_SET2    P1_IOH_CH &= 0xF3;P1_IOH_CH |= 0x08    //P15端口高电平驱动电流2MA
#define  P15_IOH_SET3    P1_IOH_CH &= 0xF3;P1_IOH_CH |= 0x0C    //P15端口高电平驱动电流4MA

#define  P16_IOH_SET0    P1_IOH_CH &= 0xCF                      //P16端口高电平驱动电流15MA
#define  P16_IOH_SET1    P1_IOH_CH &= 0xCF;P1_IOH_CH |= 0x10    //P16端口高电平驱动电流1MA
#define  P16_IOH_SET2    P1_IOH_CH &= 0xCF;P1_IOH_CH |= 0x20    //P16端口高电平驱动电流2MA
#define  P16_IOH_SET3    P1_IOH_CH &= 0xCF;P1_IOH_CH |= 0x30    //P16端口高电平驱动电流4MA

#define  P17_IOH_SET0    P1_IOH_CH &= 0x3F                      //P17端口高电平驱动电流15MA
#define  P17_IOH_SET1    P1_IOH_CH &= 0x3F;P1_IOH_CH |= 0x40    //P17端口高电平驱动电流1MA
#define  P17_IOH_SET2    P1_IOH_CH &= 0x3F;P1_IOH_CH |= 0x80    //P17端口高电平驱动电流2MA
#define  P17_IOH_SET3    P1_IOH_CH &= 0x3F;P1_IOH_CH |= 0xC0    //P17端口高电平驱动电流4MA

//P3 IOL SET    低电平驱动电流设置
#define  P30_IOL_SET0    P3_IOL_CL &= 0xFE                      //P30端口低电平驱动电流15MA
#define  P30_IOL_SET1    P3_IOL_CL |= 0x01                      //P30端口低电平驱动电流80MA

#define  P31_IOL_SET0    P3_IOL_CL &= 0xFB                      //P31端口低电平驱动电流15MA      
#define  P31_IOL_SET1    P3_IOL_CL |= 0x04                      //P31端口低电平驱动电流80MA

#define  P32_IOL_SET0    P3_IOL_CL &= 0xEF                      //P32端口低电平驱动电流15MA
#define  P32_IOL_SET1    P3_IOL_CL |= 0x10                      //P32端口低电平驱动电流80MA

#define  P33_IOL_SET0    P3_IOL_CL &= 0xBF                      //P33端口低电平驱动电流15MA
#define  P33_IOL_SET1    P3_IOL_CL |= 0x40                      //P33端口低电平驱动电流80MA

#define  P34_IOL_SET0    P3_IOL_CH &= 0xFE                      //P34端口低电平驱动电流15MA
#define  P34_IOL_SET1    P3_IOL_CH |= 0x01                      //P34端口低电平驱动电流80MA

#define  P35_IOL_SET0    P3_IOL_CH &= 0xFB                      //P35端口低电平驱动电流15MA
#define  P35_IOL_SET1    P3_IOL_CH |= 0x04                      //P35端口低电平驱动电流80MA

#define  P36_IOL_SET0    P3_IOL_CH &= 0xEF                      //P36端口低电平驱动电流15MA
#define  P36_IOL_SET1    P3_IOL_CH |= 0x10                      //P36端口低电平驱动电流80MA

#define  P37_IOL_SET0    P3_IOL_CH &= 0xBF                      //P37端口低电平驱动电流15MA
#define  P37_IOL_SET1    P3_IOL_CH |= 0x40                      //P37端口低电平驱动电流80MA


//IO中断设置选择1
#define  P00_POS_INT_EN   EINT0_IOS &=0xfe;  EINT0_MD &=0xfe; EINT0_IE |= 0x01  //P00上升沿，使能外部中断
#define  P01_POS_INT_EN   EINT0_IOS &=0xfd;  EINT0_MD &=0xfd; EINT0_IE |= 0x02  //P01上升沿，使能外部中断
#define  P02_POS_INT_EN   EINT0_IOS &=0xfb;  EINT0_MD &=0xfb; EINT0_IE |= 0x04  //P02上升沿，使能外部中断
#define  P03_POS_INT_EN   EINT0_IOS &=0xf7;  EINT0_MD &=0xf7; EINT0_IE |= 0x08  //P03上升沿，使能外部中断
#define  P04_POS_INT_EN   EINT0_IOS &=0xef;  EINT0_MD &=0xef; EINT0_IE |= 0x10  //P04上升沿，使能外部中断
#define  P05_POS_INT_EN   EINT0_IOS &=0xdf;  EINT0_MD &=0xdf; EINT0_IE |= 0x20  //P05上升沿，使能外部中断

#define  P00_POS_INT_DIS  EINT0_IOS &=0xfe;  EINT0_MD &=0xfe; EINT0_IE &= 0xfe  //P00上升沿，禁止外部中断
#define  P01_POS_INT_DIS  EINT0_IOS &=0xfd;  EINT0_MD &=0xfd; EINT0_IE &= 0xfd  //P01上升沿，禁止外部中断
#define  P02_POS_INT_DIS  EINT0_IOS &=0xfb;  EINT0_MD &=0xfb; EINT0_IE &= 0xfb  //P02上升沿，禁止外部中断
#define  P03_POS_INT_DIS  EINT0_IOS &=0xf7;  EINT0_MD &=0xf7; EINT0_IE &= 0xf7  //P03上升沿，禁止外部中断
#define  P04_POS_INT_DIS  EINT0_IOS &=0xef;  EINT0_MD &=0xef; EINT0_IE &= 0xef  //P04上升沿，禁止外部中断
#define  P05_POS_INT_DIS  EINT0_IOS &=0xdf;  EINT0_MD &=0xdf; EINT0_IE &= 0xdf  //P05上升沿，禁止外部中断

#define  P00_NEG_INT_EN   EINT0_IOS &=0xfe;  EINT0_MD |=0x01; EINT0_IE |= 0x01 //P00下降沿，使能外部中断
#define  P01_NEG_INT_EN   EINT0_IOS &=0xfd;  EINT0_MD |=0x02; EINT0_IE |= 0x02 //P01下降沿，使能外部中断
#define  P02_NEG_INT_EN   EINT0_IOS &=0xfb;  EINT0_MD |=0x04; EINT0_IE |= 0x04 //P02下降沿，使能外部中断
#define  P03_NEG_INT_EN   EINT0_IOS &=0xf7;  EINT0_MD |=0x08; EINT0_IE |= 0x08 //P03下降沿，使能外部中断
#define  P04_NEG_INT_EN   EINT0_IOS &=0xef;  EINT0_MD |=0x10; EINT0_IE |= 0x10 //P04下降沿，使能外部中断
#define  P05_NEG_INT_EN   EINT0_IOS &=0xdf;  EINT0_MD |=0x20; EINT0_IE |= 0x20 //P05下降沿，使能外部中断

#define  P00_NEG_INT_DIS   EINT0_IOS &=0xfe; EINT0_MD |=0x01; EINT0_IE &= 0xfe //P00下降沿，禁止外部中断
#define  P01_NEG_INT_DIS   EINT0_IOS &=0xfd; EINT0_MD |=0x02; EINT0_IE &= 0xfd //P01下降沿，禁止外部中断
#define  P02_NEG_INT_DIS   EINT0_IOS &=0xfb; EINT0_MD |=0x04; EINT0_IE &= 0xfb //P02下降沿，禁止外部中断
#define  P03_NEG_INT_DIS   EINT0_IOS &=0xf7; EINT0_MD |=0x08; EINT0_IE &= 0xf7 //P03下降沿，禁止外部中断
#define  P04_NEG_INT_DIS   EINT0_IOS &=0xef; EINT0_MD |=0x10; EINT0_IE &= 0xef //P04下降沿，禁止外部中断
#define  P05_NEG_INT_DIS   EINT0_IOS &=0xdf; EINT0_MD |=0x20; EINT0_IE &= 0xdf //P05下降沿，禁止外部中断

//P1 INI
#define  P10_POS_INT_EN   EINT1_IOS &=0xfe;  EINT1_MD &=0xfe; EINT1_IE |= 0x01  //P10上升沿，使能外部中断
#define  P11_POS_INT_EN   EINT1_IOS &=0xfd;  EINT1_MD &=0xfd; EINT1_IE |= 0x02  //P11上升沿，使能外部中断
#define  P12_POS_INT_EN   EINT1_IOS &=0xfb;  EINT1_MD &=0xfb; EINT1_IE |= 0x04  //P12上升沿，使能外部中断
#define  P13_POS_INT_EN   EINT1_IOS &=0xf7;  EINT1_MD &=0xf7; EINT1_IE |= 0x08  //P13上升沿，使能外部中断
#define  P14_POS_INT_EN   EINT1_IOS &=0xef;  EINT1_MD &=0xef; EINT1_IE |= 0x10  //P14上升沿，使能外部中断
#define  P15_POS_INT_EN   EINT1_IOS &=0xdf;  EINT1_MD &=0xdf; EINT1_IE |= 0x20  //P15上升沿，使能外部中断
#define  P16_POS_INT_EN   EINT1_IOS &=0xbf;  EINT1_MD &=0xbf; EINT1_IE |= 0x40  //P16上升沿，使能外部中断
#define  P17_POS_INT_EN   EINT1_IOS &=0x7f;  EINT1_MD &=0x7f; EINT1_IE |= 0x80  //P17上升沿，使能外部中断

#define  P10_POS_INT_DIS   EINT1_IOS &=0xfe;  EINT1_MD &=0xfe; EINT1_IE &=0xfe  //P10上升沿，禁止外部中断
#define  P11_POS_INT_DIS   EINT1_IOS &=0xfd;  EINT1_MD &=0xfd; EINT1_IE &=0xfd  //P11上升沿，禁止外部中断
#define  P12_POS_INT_DIS   EINT1_IOS &=0xfb;  EINT1_MD &=0xfb; EINT1_IE &=0xfb  //P12上升沿，禁止外部中断
#define  P13_POS_INT_DIS   EINT1_IOS &=0xf7;  EINT1_MD &=0xf7; EINT1_IE &=0xf7  //P13上升沿，禁止外部中断
#define  P14_POS_INT_DIS   EINT1_IOS &=0xef;  EINT1_MD &=0xef; EINT1_IE &=0xef  //P14上升沿，禁止外部中断
#define  P15_POS_INT_DIS   EINT1_IOS &=0xdf;  EINT1_MD &=0xdf; EINT1_IE &=0xdf  //P15上升沿，禁止外部中断
#define  P16_POS_INT_DIS   EINT1_IOS &=0xbf;  EINT1_MD &=0xbf; EINT1_IE &=0xbf  //P16上升沿，禁止外部中断
#define  P17_POS_INT_DIS   EINT1_IOS &=0x7f;  EINT1_MD &=0x7f; EINT1_IE &=0x7f  //P17上升沿，禁止外部中断

#define  P10_NEG_INT_EN   EINT1_IOS &=0xfe;  EINT1_MD |= 0x01; EINT1_IE |= 0x01 //P10下降沿，使能外部中断
#define  P11_NEG_INT_EN   EINT1_IOS &=0xfd;  EINT1_MD |= 0x02; EINT1_IE |= 0x02 //P11下降沿，使能外部中断
#define  P12_NEG_INT_EN   EINT1_IOS &=0xfb;  EINT1_MD |= 0x04; EINT1_IE |= 0x04 //P12下降沿，使能外部中断
#define  P13_NEG_INT_EN   EINT1_IOS &=0xf7;  EINT1_MD |= 0x08; EINT1_IE |= 0x08 //P13下降沿，使能外部中断
#define  P14_NEG_INT_EN   EINT1_IOS &=0xef;  EINT1_MD |= 0x10; EINT1_IE |= 0x10 //P14下降沿，使能外部中断
#define  P15_NEG_INT_EN   EINT1_IOS &=0xdf;  EINT1_MD |= 0x20; EINT1_IE |= 0x20 //P15下降沿，使能外部中断
#define  P16_NEG_INT_EN   EINT1_IOS &=0xbf;  EINT1_MD |= 0x40; EINT1_IE |= 0x40 //P16下降沿，使能外部中断
#define  P17_NEG_INT_EN   EINT1_IOS &=0x7f;  EINT1_MD |= 0x80; EINT1_IE |= 0x80 //P17下降沿，使能外部中断

#define  P10_NEG_INT_DIS   EINT1_IOS &=0xfe;  EINT1_MD |= 0x01; EINT1_IE &=0xfe //P10下降沿，禁止外部中断
#define  P11_NEG_INT_DIS   EINT1_IOS &=0xfd;  EINT1_MD |= 0x02; EINT1_IE &=0xfd //P11下降沿，禁止外部中断
#define  P12_NEG_INT_DIS   EINT1_IOS &=0xfb;  EINT1_MD |= 0x04; EINT1_IE &=0xfb //P12下降沿，禁止外部中断
#define  P13_NEG_INT_DIS   EINT1_IOS &=0xf7;  EINT1_MD |= 0x08; EINT1_IE &=0xf7 //P13下降沿，禁止外部中断
#define  P14_NEG_INT_DIS   EINT1_IOS &=0xef;  EINT1_MD |= 0x10; EINT1_IE &=0xef //P14下降沿，禁止外部中断
#define  P15_NEG_INT_DIS   EINT1_IOS &=0xdf;  EINT1_MD |= 0x20; EINT1_IE &=0xdf //P15下降沿，禁止外部中断
#define  P16_NEG_INT_DIS   EINT1_IOS &=0xbf;  EINT1_MD |= 0x40; EINT1_IE &=0xbf //P16下降沿，禁止外部中断
#define  P17_NEG_INT_DIS   EINT1_IOS &=0x7f;  EINT1_MD |= 0x80; EINT1_IE &=0x7f //P17下降沿，禁止外部中断 

//IO中断设置选择2
#define  P20_POS_INT_EN   EINT0_IOS |=0x01;  EINT0_MD &=0xfe; EINT0_IE |= 0x01  //P20上升沿，使能外部中断
#define  P21_POS_INT_EN   EINT0_IOS |=0x02;  EINT0_MD &=0xfd; EINT0_IE |= 0x02  //P21上升沿，使能外部中断
#define  P22_POS_INT_EN   EINT0_IOS |=0x04;  EINT0_MD &=0xfb; EINT0_IE |= 0x04  //P22上升沿，使能外部中断
#define  P23_POS_INT_EN   EINT0_IOS |=0x08;  EINT0_MD &=0xf7; EINT0_IE |= 0x08  //P23上升沿，使能外部中断
#define  P24_POS_INT_EN   EINT0_IOS |=0x10;  EINT0_MD &=0xef; EINT0_IE |= 0x10  //P24上升沿，使能外部中断
#define  P25_POS_INT_EN   EINT0_IOS |=0x20;  EINT0_MD &=0xdf; EINT0_IE |= 0x20  //P25上升沿，使能外部中断
#define  P26_POS_INT_EN   EINT0_IOS |=0x40;  EINT0_MD &=0xbf; EINT0_IE |= 0x40  //P26上升沿，使能外部中断
#define  P27_POS_INT_EN   EINT0_IOS |=0x80;  EINT0_MD &=0x7f; EINT0_IE |= 0x80  //P27上升沿，使能外部中断

#define  P20_POS_INT_DIS  EINT0_IOS |=0x01;  EINT0_MD &=0xfe; EINT0_IE &= 0xfe  //P20上升沿，禁止外部中断
#define  P21_POS_INT_DIS  EINT0_IOS |=0x02;  EINT0_MD &=0xfd; EINT0_IE &= 0xfd  //P21上升沿，禁止外部中断
#define  P22_POS_INT_DIS  EINT0_IOS |=0x04;  EINT0_MD &=0xfb; EINT0_IE &= 0xfb  //P22上升沿，禁止外部中断
#define  P23_POS_INT_DIS  EINT0_IOS |=0x08;  EINT0_MD &=0xf7; EINT0_IE &= 0xf7  //P23上升沿，禁止外部中断
#define  P24_POS_INT_DIS  EINT0_IOS |=0x10;  EINT0_MD &=0xef; EINT0_IE &= 0xef  //P24上升沿，禁止外部中断
#define  P25_POS_INT_DIS  EINT0_IOS |=0x20;  EINT0_MD &=0xdf; EINT0_IE &= 0xdf  //P25上升沿，禁止外部中断
#define  P26_POS_INT_DIS  EINT0_IOS |=0x40;  EINT0_MD &=0xbf; EINT0_IE &= 0xbf  //P26上升沿，禁止外部中断
#define  P27_POS_INT_DIS  EINT0_IOS |=0x80;  EINT0_MD &=0x7f; EINT0_IE &= 0x7f  //P27上升沿，禁止外部中断

#define  P20_NEG_INT_EN  EINT0_IOS |=0x01;  EINT0_MD |=0x01; EINT0_IE |= 0x01   //P20下降沿，使能外部中断
#define  P21_NEG_INT_EN  EINT0_IOS |=0x02;  EINT0_MD |=0x02; EINT0_IE |= 0x02   //P21下降沿，使能外部中断
#define  P22_NEG_INT_EN  EINT0_IOS |=0x04;  EINT0_MD |=0x04; EINT0_IE |= 0x04   //P22下降沿，使能外部中断
#define  P23_NEG_INT_EN  EINT0_IOS |=0x08;  EINT0_MD |=0x08; EINT0_IE |= 0x08   //P23下降沿，使能外部中断
#define  P24_NEG_INT_EN  EINT0_IOS |=0x10;  EINT0_MD |=0x10; EINT0_IE |= 0x10   //P24下降沿，使能外部中断
#define  P25_NEG_INT_EN  EINT0_IOS |=0x20;  EINT0_MD |=0x20; EINT0_IE |= 0x20   //P25下降沿，使能外部中断
#define  P26_NEG_INT_EN  EINT0_IOS |=0x40;  EINT0_MD |=0x40; EINT0_IE |= 0x40   //P26下降沿，使能外部中断
#define  P27_NEG_INT_EN  EINT0_IOS |=0x80;  EINT0_MD |=0x80; EINT0_IE |= 0x80   //P27下降沿，使能外部中断

#define  P20_NEG_INT_DIS  EINT0_IOS |=0x01;  EINT0_MD |=0x01; EINT0_IE &= 0xfe  //P20下降沿，禁止外部中断
#define  P21_NEG_INT_DIS  EINT0_IOS |=0x02;  EINT0_MD |=0x02; EINT0_IE &= 0xfd  //P21下降沿，禁止外部中断
#define  P22_NEG_INT_DIS  EINT0_IOS |=0x04;  EINT0_MD |=0x04; EINT0_IE &= 0xfb  //P22下降沿，禁止外部中断
#define  P23_NEG_INT_DIS  EINT0_IOS |=0x08;  EINT0_MD |=0x08; EINT0_IE &= 0xf7  //P23下降沿，禁止外部中断
#define  P24_NEG_INT_DIS  EINT0_IOS |=0x10;  EINT0_MD |=0x10; EINT0_IE &= 0xef  //P24下降沿，禁止外部中断
#define  P25_NEG_INT_DIS  EINT0_IOS |=0x20;  EINT0_MD |=0x20; EINT0_IE &= 0xdf  //P25下降沿，禁止外部中断
#define  P26_NEG_INT_DIS  EINT0_IOS |=0x40;  EINT0_MD |=0x40; EINT0_IE &= 0xbf  //P26下降沿，禁止外部中断
#define  P27_NEG_INT_DIS  EINT0_IOS |=0x80;  EINT0_MD |=0x80; EINT0_IE &= 0x7f  //P27下降沿，禁止外部中断     

//P3 EINT SET
#define  P30_POS_INT_EN  EINT1_IOS |= 0x01;  EINT1_MD &=0xfe; EINT1_IE |= 0x01  //P30上升沿，使能外部中断
#define  P31_POS_INT_EN  EINT1_IOS |= 0x02;  EINT1_MD &=0xfd; EINT1_IE |= 0x02  //P31上升沿，使能外部中断
#define  P32_POS_INT_EN  EINT1_IOS |= 0x04;  EINT1_MD &=0xfb; EINT1_IE |= 0x04  //P32上升沿，使能外部中断
#define  P33_POS_INT_EN  EINT1_IOS |= 0x08;  EINT1_MD &=0xf7; EINT1_IE |= 0x08  //P33上升沿，使能外部中断
#define  P34_POS_INT_EN  EINT1_IOS |= 0x10;  EINT1_MD &=0xef; EINT1_IE |= 0x10  //P34上升沿，使能外部中断
#define  P35_POS_INT_EN  EINT1_IOS |= 0x20;  EINT1_MD &=0xdf; EINT1_IE |= 0x20  //P35上升沿，使能外部中断
#define  P36_POS_INT_EN  EINT1_IOS |= 0x40;  EINT1_MD &=0xbf; EINT1_IE |= 0x40  //P36上升沿，使能外部中断
#define  P37_POS_INT_EN  EINT1_IOS |= 0x80;  EINT1_MD &=0x7f; EINT1_IE |= 0x80  //P37上升沿，使能外部中断

#define  P30_POS_INT_DIS EINT1_IOS |= 0x01;  EINT1_MD &=0xfe; EINT1_IE &=0xfe   //P30上升沿，禁止外部中断
#define  P31_POS_INT_DIS EINT1_IOS |= 0x02;  EINT1_MD &=0xfd; EINT1_IE &=0xfd   //P31上升沿，禁止外部中断
#define  P32_POS_INT_DIS EINT1_IOS |= 0x04;  EINT1_MD &=0xfb; EINT1_IE &=0xfb   //P32上升沿，禁止外部中断
#define  P33_POS_INT_DIS EINT1_IOS |= 0x08;  EINT1_MD &=0xf7; EINT1_IE &=0xf7   //P33上升沿，禁止外部中断
#define  P34_POS_INT_DIS EINT1_IOS |= 0x10;  EINT1_MD &=0xef; EINT1_IE &=0xef   //P34上升沿，禁止外部中断
#define  P35_POS_INT_DIS EINT1_IOS |= 0x20;  EINT1_MD &=0xdf; EINT1_IE &=0xdf   //P35上升沿，禁止外部中断
#define  P36_POS_INT_DIS EINT1_IOS |= 0x40;  EINT1_MD &=0xbf; EINT1_IE &=0xbf   //P36上升沿，禁止外部中断
#define  P37_POS_INT_DIS EINT1_IOS |= 0x80;  EINT1_MD &=0x7f; EINT1_IE &=0x7f   //P37上升沿，禁止外部中断

#define  P30_NEG_INT_EN  EINT1_IOS |= 0x01;  EINT1_MD |= 0x01; EINT1_IE |= 0x01 //P30下降沿，使能外部中断
#define  P31_NEG_INT_EN  EINT1_IOS |= 0x02;  EINT1_MD |= 0x02; EINT1_IE |= 0x02 //P31下降沿，使能外部中断
#define  P32_NEG_INT_EN  EINT1_IOS |= 0x04;  EINT1_MD |= 0x04; EINT1_IE |= 0x04 //P32下降沿，使能外部中断
#define  P33_NEG_INT_EN  EINT1_IOS |= 0x08;  EINT1_MD |= 0x08; EINT1_IE |= 0x08 //P33下降沿，使能外部中断
#define  P34_NEG_INT_EN  EINT1_IOS |= 0x10;  EINT1_MD |= 0x10; EINT1_IE |= 0x10 //P34下降沿，使能外部中断
#define  P35_NEG_INT_EN  EINT1_IOS |= 0x20;  EINT1_MD |= 0x20; EINT1_IE |= 0x20 //P35下降沿，使能外部中断
#define  P36_NEG_INT_EN  EINT1_IOS |= 0x40;  EINT1_MD |= 0x40; EINT1_IE |= 0x40 //P36下降沿，使能外部中断
#define  P37_NEG_INT_EN  EINT1_IOS |= 0x80;  EINT1_MD |= 0x80; EINT1_IE |= 0x80 //P37下降沿，使能外部中断

#define  P30_NEG_INT_DIS EINT1_IOS |= 0x01;  EINT1_MD |= 0x01; EINT1_IE &=0xfe  //P30下降沿，禁止外部中断
#define  P31_NEG_INT_DIS EINT1_IOS |= 0x02;  EINT1_MD |= 0x02; EINT1_IE &=0xfd  //P31下降沿，禁止外部中断
#define  P32_NEG_INT_DIS EINT1_IOS |= 0x04;  EINT1_MD |= 0x04; EINT1_IE &=0xfb  //P32下降沿，禁止外部中断
#define  P33_NEG_INT_DIS EINT1_IOS |= 0x08;  EINT1_MD |= 0x08; EINT1_IE &=0xf7  //P33下降沿，禁止外部中断
#define  P34_NEG_INT_DIS EINT1_IOS |= 0x10;  EINT1_MD |= 0x10; EINT1_IE &=0xef  //P34下降沿，禁止外部中断
#define  P35_NEG_INT_DIS EINT1_IOS |= 0x20;  EINT1_MD |= 0x20; EINT1_IE &=0xdf  //P35下降沿，禁止外部中断
#define  P36_NEG_INT_DIS EINT1_IOS |= 0x40;  EINT1_MD |= 0x40; EINT1_IE &=0xbf  //P36下降沿，禁止外部中断
#define  P37_NEG_INT_DIS EINT1_IOS |= 0x80;  EINT1_MD |= 0x80; EINT1_IE &=0x7f  //P37下降沿，禁止外部中断 

#define  P00_INT_IF_CLR   EINT00_IF = 0                                         //清除P00外部中断标志位
#define  P01_INT_IF_CLR   EINT01_IF = 0                                         //清除P01外部中断标志位
#define  P02_INT_IF_CLR   EINT02_IF = 0                                         //清除P02外部中断标志位
#define  P03_INT_IF_CLR   EINT03_IF = 0                                         //清除P03外部中断标志位
#define  P04_INT_IF_CLR   EINT04_IF = 0                                         //清除P04外部中断标志位
#define  P05_INT_IF_CLR   EINT05_IF = 0                                         //清除P05外部中断标志位
    
#define  P10_INT_IF_CLR   EINT10_IF = 0                                         //清除P10外部中断标志位
#define  P11_INT_IF_CLR   EINT11_IF = 0                                         //清除P11外部中断标志位
#define  P12_INT_IF_CLR   EINT12_IF = 0                                         //清除P12外部中断标志位
#define  P13_INT_IF_CLR   EINT13_IF = 0                                         //清除P13外部中断标志位
#define  P14_INT_IF_CLR   EINT14_IF = 0                                         //清除P14外部中断标志位
#define  P15_INT_IF_CLR   EINT15_IF = 0                                         //清除P15外部中断标志位
#define  P16_INT_IF_CLR   EINT16_IF = 0                                         //清除P16外部中断标志位
#define  P17_INT_IF_CLR   EINT17_IF = 0                                         //清除P17外部中断标志位
    
#define  P20_INT_IF_CLR   EINT00_IF = 0                                         //清除P20外部中断标志位
#define  P21_INT_IF_CLR   EINT01_IF = 0                                         //清除P21外部中断标志位
#define  P22_INT_IF_CLR   EINT02_IF = 0                                         //清除P22外部中断标志位
#define  P23_INT_IF_CLR   EINT03_IF = 0                                         //清除P23外部中断标志位
#define  P24_INT_IF_CLR   EINT04_IF = 0                                         //清除P24外部中断标志位
#define  P25_INT_IF_CLR   EINT05_IF = 0                                         //清除P25外部中断标志位
#define  P26_INT_IF_CLR   EINT06_IF = 0                                         //清除P26外部中断标志位
#define  P27_INT_IF_CLR   EINT07_IF = 0                                         //清除P27外部中断标志位
    
#define  P30_INT_IF_CLR   EINT10_IF = 0                                         //清除P30外部中断标志位
#define  P31_INT_IF_CLR   EINT11_IF = 0                                         //清除P31外部中断标志位
#define  P32_INT_IF_CLR   EINT12_IF = 0                                         //清除P32外部中断标志位
#define  P33_INT_IF_CLR   EINT13_IF = 0                                         //清除P33外部中断标志位
#define  P34_INT_IF_CLR   EINT14_IF = 0                                         //清除P34外部中断标志位
#define  P35_INT_IF_CLR   EINT15_IF = 0                                         //清除P35外部中断标志位
#define  P36_INT_IF_CLR   EINT16_IF = 0                                         //清除P36外部中断标志位
#define  P37_INT_IF_CLR   EINT17_IF = 0                                         //清除P37外部中断标志位


//中断控制
#define  GIE_EN       GIE = 1                                                   //开启中中断
#define  INT0_EN      INT0_IE = 1                                               //开启INT0中断
#define  INT1_EN      INT1_IE = 1                                               //开启INT1中断
#define  INT2_EN      INT2_IE = 1                                               //开启INT2中断
#define  INT3_EN      INT3_IE = 1                                               //开启INT3中断
#define  INT4_EN      INT4_IE = 1                                               //开启INT4中断
#define  INT5_EN      INT5_IE = 1                                               //开启INT5中断
#define  INT6_EN      INT6_IE = 1                                               //开启INT6中断

#define  GIE_DIS      GIE = 0                                                   //关闭中中断
#define  INT0_DIS     INT0_IE = 0                                               //关闭INT0中断
#define  INT1_DIS     INT1_IE = 0                                               //关闭INT1中断
#define  INT2_DIS     INT2_IE = 0                                               //关闭INT2中断
#define  INT3_DIS     INT3_IE = 0                                               //关闭INT3中断
#define  INT4_DIS     INT4_IE = 0                                               //关闭INT4中断
#define  INT5_DIS     INT5_IE = 0                                               //关闭INT5中断
#define  INT6_DIS     INT6_IE = 0                                               //关闭INT6中断

#define  INT0_PI_EN   INT0_IP = 1                                               //设置INT0高优先级
#define  INT1_PI_EN   INT1_IP = 1                                               //设置INT1高优先级
#define  INT2_PI_EN   INT2_IP = 1                                               //设置INT2高优先级
#define  INT3_PI_EN   INT3_IP = 1                                               //设置INT3高优先级
#define  INT4_PI_EN   INT4_IP = 1                                               //设置INT4高优先级
#define  INT5_PI_EN   INT5_IP = 1                                               //设置INT5高优先级
#define  INT6_PI_EN   INT6_IP = 1                                               //设置INT6高优先级

#define  INT0_PI_DIS  INT0_IP = 0                                               //设置INT0低优先级
#define  INT1_PI_DIS  INT1_IP = 0                                               //设置INT1低优先级
#define  INT2_PI_DIS  INT2_IP = 0                                               //设置INT2低优先级
#define  INT3_PI_DIS  INT3_IP = 0                                               //设置INT3低优先级
#define  INT4_PI_DIS  INT4_IP = 0                                               //设置INT4低优先级
#define  INT5_PI_DIS  INT5_IP = 0                                               //设置INT5低优先级
#define  INT6_PI_DIS  INT6_IP = 0                                               //设置INT6低优先级

#define  INT0_IF_CLR  INT0_IF = 0                                               //清除INT0中断标志位
#define  INT1_IF_CLR  INT1_IF = 0                                               //清除INT1中断标志位
#define  INT2_IF_CLR  INT2_IF = 0                                               //清除INT2中断标志位
#define  INT3_IF_CLR  INT3_IF = 0                                               //清除INT3中断标志位
#define  INT4_IF_CLR  INT4_IF = 0                                               //清除INT4中断标志位
#define  INT5_IF_CLR  INT5_IF = 0                                               //清除INT5中断标志位
#define  INT6_IF_CLR  INT6_IF = 0                                               //清除INT6中断标志位
#define  INT_IF_CLR   INTn_IF = 0x00                                            //清除所有中断标志位

//TMR 中断
#define  TMR0_INT_EN  TMRn_IE |= 0x01                                           //使能定时器0中断
#define  TMR1_INT_EN  TMRn_IE |= 0x02                                           //使能定时器1中断
#define  TMR2_INT_EN  TMRn_IE |= 0x04                                           //使能定时器2中断
#define  TMR3_INT_EN  TMRn_IE |= 0x08                                           //使能定时器3中断
    
#define  TMR0_INT_DIS TMRn_IE &= 0xfe                                           //禁止定时器0中断
#define  TMR1_INT_DIS TMRn_IE &= 0xfd                                           //禁止定时器1中断
#define  TMR2_INT_DIS TMRn_IE &= 0xfb                                           //禁止定时器2中断
#define  TMR3_INT_DIS TMRn_IE &= 0xf7                                           //禁止定时器3中断

#define  TMR0_INT_IF_CLR TMR0_IF = 0                                            //清除定时器0中断标志位
#define  TMR1_INT_IF_CLR TMR1_IF = 0                                            //清除定时器1中断标志位
#define  TMR2_INT_IF_CLR TMR2_IF = 0                                            //清除定时器2中断标志位
#define  TMR3_INT_IF_CLR TMR3_IF = 0                                            //清除定时器3中断标志位

//CAP 中断
#define  CAP0_INT_EN  CAPn_IE |= 0x01                                           //使能CAP0中断
#define  CAP1_INT_EN  CAPn_IE |= 0x02                                           //使能CAP1中断
#define  CAP2_INT_EN  CAPn_IE |= 0x04                                           //使能CAP2中断

#define  CAP0_INT_DIS CAPn_IE &= 0xfe                                           //禁止CAP0中断
#define  CAP1_INT_DIS CAPn_IE &= 0xfd                                           //禁止CAP1中断
#define  CAP2_INT_DIS CAPn_IE &= 0xfb                                           //禁止CAP2中断

#define  CAP0_INT_IF_CLR CAP0_IF = 0                                            //清除CAP0中断标志位
#define  CAP1_INT_IF_CLR CAP1_IF = 0                                            //清除CAP1中断标志位
#define  CAP2_INT_IF_CLR CAP2_IF = 0                                            //清除CAP2中断标志位

//PWM 中断
#define  PWM0_INT_EN  PWMn_IE |= 0x01                                           //使能PWM0中断
#define  PWM1_INT_EN  PWMn_IE |= 0x02                                           //使能PWM1中断
#define  PWM2_INT_EN  PWMn_IE |= 0x04                                           //使能PWM2中断
#define  STP0_INT_EN  PWMn_IE |= 0x10                                           //使能STP0中断
#define  STP1_INT_EN  PWMn_IE |= 0x20                                           //使能STP1中断
#define  STP2_INT_EN  PWMn_IE |= 0x40                                           //使能STP2中断

#define  PWM0_INT_DIS PWMn_IE &= 0xfe                                           //禁止PWM0中断
#define  PWM1_INT_DIS PWMn_IE &= 0xfd                                           //禁止PWM1中断
#define  PWM2_INT_DIS PWMn_IE &= 0xfb                                           //禁止PWM2中断
#define  STP0_INT_DIS PWMn_IE &= 0xef                                           //禁止STP0中断
#define  STP1_INT_DIS PWMn_IE &= 0xdf                                           //禁止STP1中断
#define  STP2_INT_DIS PWMn_IE &= 0xbf                                           //禁止STP2中断

#define  PWM0_INT_IF_CLR PWM0_IF = 0                                            //清除PWM0中断标志位
#define  PWM1_INT_IF_CLR PWM1_IF = 0                                            //清除PWM1中断标志位
#define  PWM2_INT_IF_CLR PWM2_IF = 0                                            //清除PWM2中断标志位
#define  STP0_INT_IF_CLR STP0_IF = 0                                            //清除STP0中断标志位
#define  STP1_INT_IF_CLR STP1_IF = 0                                            //清除STP1中断标志位
#define  STP2_INT_IF_CLR STP2_IF = 0                                            //清除STP2中断标志位

//uart 中断
#define  UART0_RX0_INT_EN  UART_IE |= 0x01                                      //使能UART0_RX中断
#define  UART0_TX0_INT_EN  UART_IE |= 0x02                                      //使能UART0_TX中断

#define  UART0_RX0_INT_DIS UART_IE &= 0xfe                                      //禁止UART0_RX中断
#define  UART0_TX0_INT_DIS UART_IE &= 0xfd                                      //禁止UART0_TX中断

#define  UART1_RX1_INT_EN  UART_IE |= 0x04                                      //使能UART1_RX中断
#define  UART1_TX1_INT_EN  UART_IE |= 0x08                                      //使能UART1_TX中断

#define  UART1_RX1_INT_DIS UART_IE &= 0xfB                                      //禁止UART1_RX中断
#define  UART1_TX1_INT_DIS UART_IE &= 0xf7                                      //禁止UART1_TX中断

#define  UART0_TX0_IF_CLR  TX0_IF = 0                                           //清除UART0_RX中断标志位
#define  UART0_RX0_IF_CLR  RX0_IF = 0                                           //清除UART0_TX中断标志位
#define  UART1_TX1_IF_CLR  TX1_IF = 0                                           //清除UART1_RX中断标志位
#define  UART1_RX1_IF_CLR  RX1_IF = 0                                           //清除UART1_TX中断标志位

//IIC 中断
#define  IIC_INT_EN  IICn_IE |= 0x10                                            //使能IIC中断
#define  IIC_INT_DIS IICn_IE &= 0xef                                            //禁止IIC中断

#define  IIC_INT_IF_CLR IIC_IF = 0                                              //清除IIC中断标志位

//SPI 中断
#define  SPI_INT_EN  SPIn_IE |= 0x40                                            //使能SPI中断
#define  SPI_INT_DIS SPIn_IE &= 0xbf                                            //禁止SPI中断

#define  SPI_INT_IF_CLR SPIn_IF = 0                                             //清除SPI中断标志位

//模拟中断
#define  ADC_INT_EN   AN_IE |= 0x01                                             //使能ADC中断
#define  TK_INT_EN    AN_IE |= 0x02                                             //使能TK中断
#define  LVD_INT_EN   AN_IE |= 0x04                                             //使能LVD中断
#define  LED_INT_EN   AN_IE |= 0x10                                             //使能LED中断
#define  COM_INT_EN   AN_IE |= 0x20                                             //使能COM中断

#define  ADC_INT_DIS   AN_IE &= 0xfe                                            //禁止ADC中断
#define  TK_INT_DIS    AN_IE &= 0xfd                                            //禁止TK中断
#define  LVD_INT_DIS   AN_IE &= 0xfb                                            //禁止LVD中断
#define  LED_INT_DIS   AN_IE &= 0xef                                            //禁止LED中断
#define  COM_INT_DIS   AN_IE &= 0xdf                                            //禁止COM中断


#define  ADC_INT_IF_CLR ADC_IF = 0                                              //清除ADC中断标志位
#define  TK_INT_IF_CLR  TK_IF  = 0                                              //清除TK中断标志位
#define  LVD_INT_IF_CLR LVD_IF = 0                                              //清除LVD中断标志位
#define  LED_INT_IF_CLR LED_IF = 0                                              //清除LED中断标志位
#define  COM_INT_IF_CLR COM_IF = 0                                              //清除COM中断标志位

//TMR0
#define  TMR0_PST_1    TMR0_C0 &= 0xf0                                          //定时器0后分频，定时器0 1 次溢出产生中断
#define  TMR0_PST_2    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x01                        //定时器0后分频，定时器0 2 次溢出产生中断
#define  TMR0_PST_3    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x02                        //定时器0后分频，定时器0 3 次溢出产生中断
#define  TMR0_PST_4    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x03                        //定时器0后分频，定时器0 4 次溢出产生中断
#define  TMR0_PST_5    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x04                        //定时器0后分频，定时器0 5 次溢出产生中断
#define  TMR0_PST_6    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x05                        //定时器0后分频，定时器0 6 次溢出产生中断
#define  TMR0_PST_7    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x06                        //定时器0后分频，定时器0 7 次溢出产生中断
#define  TMR0_PST_8    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x07                        //定时器0后分频，定时器0 8 次溢出产生中断
#define  TMR0_PST_9    TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x08                        //定时器0后分频，定时器0 9 次溢出产生中断
#define  TMR0_PST_10   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x09                        //定时器0后分频，定时器0 10次溢出产生中断
#define  TMR0_PST_11   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0a                        //定时器0后分频，定时器0 11次溢出产生中断
#define  TMR0_PST_12   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0b                        //定时器0后分频，定时器0 12次溢出产生中断
#define  TMR0_PST_13   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0c                        //定时器0后分频，定时器0 13次溢出产生中断
#define  TMR0_PST_14   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0d                        //定时器0后分频，定时器0 14次溢出产生中断
#define  TMR0_PST_15   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0e                        //定时器0后分频，定时器0 15次溢出产生中断
#define  TMR0_PST_16   TMR0_C0 &= 0xf0;  TMR0_C0 |= 0x0f                        //定时器0后分频，定时器0 16次溢出产生中断

#define  TMR0_SYSCLK   TMR0_C0 &= 0xcf                                          //定时器0计数时钟为SYS_CLK 系统时钟
#define  TMR0_EXCK     TMR0_C0 &= 0xcf;  TMR0_C0 |= 0x10                        //定时器0计数时钟为EXCK 复用端口输入
#define  TMR0_HRC      TMR0_C0 &= 0xcf;  TMR0_C0 |= 0x20                        //定时器0计数时钟为HRC 内部高频时钟
#define  TMR0_XOSC     TMR0_C0 &= 0xcf;  TMR0_C0 |= 0x30                        //定时器0计数时钟为XOSC 振荡器

#define  TMR0_DIV8_EN  TMR0_C0 |= 0x40                                          //定时器0使能计数时钟8分频
#define  TMR0_DIV8_DIS TMR0_C0 &= 0xbf                                          //定时器0禁止计数时钟8分频

#define  TMR0_EN       TMR0_C0 |= 0x80                                          //使能定时器0
#define  TMR0_DIS      TMR0_C0 &= 0x7f                                          //禁止定时器0

#define  TMR0_GE_H_EN  TMR0_C1 = 0x01                                           //定时器0门控使能 高电平使能定时器0
#define  TMR0_GE_L_EN  TMR0_C1 = 0x03                                           //定时器0门控使能 低电平使能定时器0

#define  TMR0_GE_H_DIS TMR0_C1 = 0x00                                           //定时器0门控关闭 高电平使能定时器0
#define  TMR0_GE_L_DIS TMR0_C1 = 0x00                                           //定时器0门控关闭 低电平使能定时器0

#define  TMR0_CLR      TMR0L = 0x00;     TMR0H = 0x00                           // 清除定时器0计数寄存器

//TMR1
#define  TMR1_PST_1    TMR1_C0 &= 0xf0                                          //定时器1后分频，定时器1 1 次溢出产生中断
#define  TMR1_PST_2    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x01                        //定时器1后分频，定时器1 2 次溢出产生中断
#define  TMR1_PST_3    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x02                        //定时器1后分频，定时器1 3 次溢出产生中断
#define  TMR1_PST_4    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x03                        //定时器1后分频，定时器1 4 次溢出产生中断
#define  TMR1_PST_5    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x04                        //定时器1后分频，定时器1 5 次溢出产生中断
#define  TMR1_PST_6    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x05                        //定时器1后分频，定时器1 6 次溢出产生中断
#define  TMR1_PST_7    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x06                        //定时器1后分频，定时器1 7 次溢出产生中断
#define  TMR1_PST_8    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x07                        //定时器1后分频，定时器1 8 次溢出产生中断
#define  TMR1_PST_9    TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x08                        //定时器1后分频，定时器1 9 次溢出产生中断
#define  TMR1_PST_10   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x09                        //定时器1后分频，定时器1 10次溢出产生中断
#define  TMR1_PST_11   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0a                        //定时器1后分频，定时器1 11次溢出产生中断
#define  TMR1_PST_12   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0b                        //定时器1后分频，定时器1 12次溢出产生中断
#define  TMR1_PST_13   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0c                        //定时器1后分频，定时器1 13次溢出产生中断
#define  TMR1_PST_14   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0d                        //定时器1后分频，定时器1 14次溢出产生中断
#define  TMR1_PST_15   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0e                        //定时器1后分频，定时器1 15次溢出产生中断
#define  TMR1_PST_16   TMR1_C0 &= 0xf0;  TMR1_C0 |= 0x0f                        //定时器1后分频，定时器1 16次溢出产生中断

#define  TMR1_SYSCLK   TMR1_C0 &= 0xcf                                          //定时器1计数时钟为SYS_CLK 系统时钟
#define  TMR1_EXCK     TMR1_C0 &= 0xcf;  TMR1_C0 |= 0x10                        //定时器1计数时钟为EXCK 复用端口输入
#define  TMR1_HRC      TMR1_C0 &= 0xcf;  TMR1_C0 |= 0x20                        //定时器1计数时钟为HRC 内部高频时钟
#define  TMR1_LRC_10MS TMR1_C0 &= 0xcf;  TMR1_C0 |= 0x30                        //定时器1计数时钟为LRC 10Ms脉冲

#define  TMR1_DIV8_EN  TMR1_C0 |= 0x40                                          //定时器1使能计数时钟8分频
#define  TMR1_DIV8_DIS TMR1_C0 &= 0xbf                                          //定时器1禁止计数时钟8分频

#define  TMR1_EN       TMR1_C0 |= 0x80                                          //使能定时器1
#define  TMR1_DIS      TMR1_C0 &= 0x7f                                          //禁止定时器1

#define  TMR1_GE_H_EN  TMR1_C1 = 0x04                                           //定时器1门控使能 高电平使能定时器1
#define  TMR1_GE_L_EN  TMR1_C1 = 0x0C                                           //定时器1门控使能 低电平使能定时器1

#define  TMR1_GE_H_DIS TMR1_C1 = 0x00                                           //定时器1门控关闭 高电平使能定时器1
#define  TMR1_GE_L_DIS TMR1_C1 = 0x00                                           //定时器1门控关闭 低电平使能定时器1

#define  TMR1_CLR      TMR1L = 0x00;     TMR1H = 0x00                           // 清除定时器1计数寄存器

//TMR2
#define  TMR2_PST_1    TMR2_C0 &= 0xf0                                          //定时器2后分频，定时器2 1 次溢出产生中断
#define  TMR2_PST_2    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x01                        //定时器2后分频，定时器2 2 次溢出产生中断
#define  TMR2_PST_3    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x02                        //定时器2后分频，定时器2 3 次溢出产生中断
#define  TMR2_PST_4    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x03                        //定时器2后分频，定时器2 4 次溢出产生中断
#define  TMR2_PST_5    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x04                        //定时器2后分频，定时器2 5 次溢出产生中断
#define  TMR2_PST_6    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x05                        //定时器2后分频，定时器2 6 次溢出产生中断
#define  TMR2_PST_7    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x06                        //定时器2后分频，定时器2 7 次溢出产生中断
#define  TMR2_PST_8    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x07                        //定时器2后分频，定时器2 8 次溢出产生中断
#define  TMR2_PST_9    TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x08                        //定时器2后分频，定时器2 9 次溢出产生中断
#define  TMR2_PST_10   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x09                        //定时器2后分频，定时器2 10次溢出产生中断
#define  TMR2_PST_11   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0a                        //定时器2后分频，定时器2 11次溢出产生中断
#define  TMR2_PST_12   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0b                        //定时器2后分频，定时器2 12次溢出产生中断
#define  TMR2_PST_13   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0c                        //定时器2后分频，定时器2 13次溢出产生中断
#define  TMR2_PST_14   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0d                        //定时器2后分频，定时器2 14次溢出产生中断
#define  TMR2_PST_15   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0e                        //定时器2后分频，定时器2 15次溢出产生中断
#define  TMR2_PST_16   TMR2_C0 &= 0xf0;  TMR2_C0 |= 0x0f                        //定时器2后分频，定时器2 16次溢出产生中断

#define  TMR2_SYSCLK   TMR2_C0 &= 0xcf                                          //定时器2计数时钟为SYS_CLK 系统时钟
#define  TMR2_EXCK     TMR2_C0 &= 0xcf;  TMR2_C0 |= 0x10                        //定时器2计数时钟为EXCK 复用端口输入
#define  TMR2_HRC      TMR2_C0 &= 0xcf;  TMR2_C0 |= 0x20                        //定时器2计数时钟为HRC 内部高频时钟
#define  TMR2_LRC      TMR2_C0 &= 0xcf;  TMR2_C0 |= 0x30                        //定时器2计数时钟为LRC 时钟

#define  TMR2_DIV8_EN  TMR2_C0 |= 0x40                                          //定时器2使能计数时钟8分频
#define  TMR2_DIV8_DIS TMR2_C0 &= 0xbf                                          //定时器2禁止计数时钟8分频

#define  TMR2_EN       TMR2_C0 |= 0x80                                          //使能定时器2
#define  TMR2_DIS      TMR2_C0 &= 0x7f                                          //禁止定时器2

#define  TMR2_GE_H_EN  TMR2_C1 = 0x10                                           //定时器2门控使能 高电平使能定时器2
#define  TMR2_GE_L_EN  TMR2_C1 = 0x30                                           //定时器2门控使能 低电平使能定时器2

#define  TMR2_GE_H_DIS TMR2_C1 = 0x00                                           //定时器2门控关闭 高电平使能定时器2
#define  TMR2_GE_L_DIS TMR2_C1 = 0x00                                           //定时器2门控关闭 低电平使能定时器2

#define  TMR2_CLR      TMR2L = 0x00;     TMR2H = 0x00                           // 清除定时器2计数寄存器

//TMR3
#define  TMR3_PST_1    TMR3_C0 &= 0xf0                                          //定时器3后分频，定时器3 1 次溢出产生中断
#define  TMR3_PST_2    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x01                        //定时器3后分频，定时器3 2 次溢出产生中断
#define  TMR3_PST_3    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x02                        //定时器3后分频，定时器3 3 次溢出产生中断
#define  TMR3_PST_4    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x03                        //定时器3后分频，定时器3 4 次溢出产生中断
#define  TMR3_PST_5    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x04                        //定时器3后分频，定时器3 5 次溢出产生中断
#define  TMR3_PST_6    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x05                        //定时器3后分频，定时器3 6 次溢出产生中断
#define  TMR3_PST_7    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x06                        //定时器3后分频，定时器3 7 次溢出产生中断
#define  TMR3_PST_8    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x07                        //定时器3后分频，定时器3 8 次溢出产生中断
#define  TMR3_PST_9    TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x08                        //定时器3后分频，定时器3 9 次溢出产生中断
#define  TMR3_PST_10   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x09                        //定时器3后分频，定时器3 10次溢出产生中断
#define  TMR3_PST_11   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0a                        //定时器3后分频，定时器3 11次溢出产生中断
#define  TMR3_PST_12   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0b                        //定时器3后分频，定时器3 12次溢出产生中断
#define  TMR3_PST_13   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0c                        //定时器3后分频，定时器3 13次溢出产生中断
#define  TMR3_PST_14   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0d                        //定时器3后分频，定时器3 14次溢出产生中断
#define  TMR3_PST_15   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0e                        //定时器3后分频，定时器3 15次溢出产生中断
#define  TMR3_PST_16   TMR3_C0 &= 0xf0;  TMR3_C0 |= 0x0f                        //定时器3后分频，定时器3 16次溢出产生中断

#define  TMR3_SYSCLK   TMR3_C0 &= 0xcf                                          //定时器3计数时钟为SYS_CLK 系统时钟
#define  TMR3_EXCK     TMR3_C0 &= 0xcf;  TMR3_C0 |= 0x10                        //定时器3计数时钟为EXCK 复用端口输入
#define  TMR3_HRC      TMR3_C0 &= 0xcf;  TMR3_C0 |= 0x20                        //定时器3计数时钟为HRC 内部高频时钟
#define  TMR3_LRC      TMR3_C0 &= 0xcf;  TMR3_C0 |= 0x30                        //定时器3计数时钟为XOSC 振荡器

#define  TMR3_DIV8_EN  TMR3_C0 |= 0x40                                          //定时器3使能计数时钟8分频
#define  TMR3_DIV8_DIS TMR3_C0 &= 0xbf                                          //定时器3禁止计数时钟8分频

#define  TMR3_EN       TMR3_C0 |= 0x80                                          //使能定时器3
#define  TMR3_DIS      TMR3_C0 &= 0x7f                                          //禁止定时器3

#define  TMR3_GE_H_EN  TMR3_C1 = 0x40                                           //定时器3门控使能 高电平使能定时器3
#define  TMR3_GE_L_EN  TMR3_C1 = 0xC0                                           //定时器3门控使能 低电平使能定时器3

#define  TMR3_GE_H_DIS TMR3_C1 = 0x00                                           //定时器3门控关闭 高电平使能定时器3
#define  TMR3_GE_L_DIS TMR3_C1 = 0x00                                           //定时器3门控关闭 低电平使能定时器3

#define  TMR3_CLR      TMR3L = 0x00;     TMR3H = 0x00                           // 清除定时器3计数寄存器

//CAP0
#define  CAP0_MD_DIS   CAP0_C &= 0xfc                                           //CAP0关闭捕捉模式
#define  CAP0_ADD_MD   CAP0_C &= 0xfc;    CAP0_C |= 0x02                        //CAP0捕捉累加模式(捕捉事件发生时，时基TMR 继续累加)
#define  CAP0_CLR_MD   CAP0_C |= 0x03                                           //CAP0捕捉清零模式(捕捉事件发生时，将时基TMR 清零)

#define  CAP0_TMR0_S   CAP0_C &= 0xf3                                           //CAP0捕捉工作时基为定时器0
#define  CAP0_TMR1_S   CAP0_C &= 0xf3;    CAP0_C |= 0x04                        //CAP0捕捉工作时基为定时器1
#define  CAP0_TMR2_S   CAP0_C &= 0xf3;    CAP0_C |= 0x08                        //CAP0捕捉工作时基为定时器2
#define  CAP0_TMR3_S   CAP0_C |= 0x0c                                           //CAP0捕捉工作时基为定时器3

#define  CAP0_CAP_1    CAP0_C &= 0xcf                                           //CAP0捕捉 1 个触发边沿产生1 次捕捉事件
#define  CAP0_CAP_4    CAP0_C &= 0xcf;    CAP0_C |= 0x10                        //CAP0捕捉 4 个触发边沿产生1 次捕捉事件
#define  CAP0_CAP_8    CAP0_C &= 0xcf;    CAP0_C |= 0x20                        //CAP0捕捉 8 个触发边沿产生1 次捕捉事件
#define  CAP0_CAP_16   CAP0_C |= 0x30                                           //CAP0捕捉 16个触发边沿产生1 次捕捉事件

#define  CAP0_CAP_NONE CAP0_C &= 0x3f                                           //CAP0捕捉    保留
#define  CAP0_CAP_POS  CAP0_C &= 0x3f;    CAP0_C |= 0x40                        //CAP0捕捉    上升沿捕捉
#define  CAP0_CAP_NEG  CAP0_C &= 0x3f;    CAP0_C |= 0x80                        //CAP0捕捉    下降沿捕捉
#define  CAP0_CAP_EDGE CAP0_C |= 0xc0                                           //CAP0捕捉    上升和下降沿都捕捉

//CAP1
#define  CAP1_MD_DIS   CAP1_C &= 0xfc                                           //CAP1关闭捕捉模式
#define  CAP1_ADD_MD   CAP1_C &= 0xfc;    CAP1_C |= 0x02                        //CAP1捕捉累加模式(捕捉事件发生时，时基TMR 继续累加)
#define  CAP1_CLR_MD   CAP1_C |= 0x03                                           //CAP1捕捉清零模式(捕捉事件发生时，将时基TMR 清零)

#define  CAP1_TMR0_S   CAP1_C &= 0xf3                                           //CAP1捕捉工作时基为定时器0
#define  CAP1_TMR1_S   CAP1_C &= 0xf3;    CAP1_C |= 0x04                        //CAP1捕捉工作时基为定时器1
#define  CAP1_TMR2_S   CAP1_C &= 0xf3;    CAP1_C |= 0x08                        //CAP1捕捉工作时基为定时器2
#define  CAP1_TMR3_S   CAP1_C |= 0x0c                                           //CAP1捕捉工作时基为定时器3

#define  CAP1_CAP_1    CAP1_C &= 0xcf                                           //CAP1捕捉 1 个触发边沿产生1 次捕捉事件
#define  CAP1_CAP_4    CAP1_C &= 0xcf;    CAP1_C |= 0x10                        //CAP1捕捉 4 个触发边沿产生1 次捕捉事件
#define  CAP1_CAP_8    CAP1_C &= 0xcf;    CAP1_C |= 0x20                        //CAP1捕捉 8 个触发边沿产生1 次捕捉事件
#define  CAP1_CAP_16   CAP1_C |= 0x30                                           //CAP1捕捉 16个触发边沿产生1 次捕捉事件

#define  CAP1_CAP_NONE CAP1_C &= 0x3f                                           //CAP1捕捉    保留
#define  CAP1_CAP_POS  CAP1_C &= 0x3f;    CAP1_C |= 0x40                        //CAP1捕捉    上升沿捕捉
#define  CAP1_CAP_NEG  CAP1_C &= 0x3f;    CAP1_C |= 0x80                        //CAP1捕捉    下降沿捕捉
#define  CAP1_CAP_EDGE CAP1_C |= 0xc0                                           //CAP1捕捉    上升和下降沿都捕捉

//CAP2
#define  CAP2_MD_DIS   CAP2_C &= 0xfc                                           //CAP2关闭捕捉模式
#define  CAP2_ADD_MD   CAP2_C &= 0xfc;    CAP2_C |= 0x02                        //CAP2捕捉累加模式(捕捉事件发生时，时基TMR 继续累加)
#define  CAP2_CLR_MD   CAP2_C |= 0x03                                           //CAP2捕捉清零模式(捕捉事件发生时，将时基TMR 清零)

#define  CAP2_TMR0_S   CAP2_C &= 0xf3                                           //CAP2捕捉工作时基为定时器0
#define  CAP2_TMR1_S   CAP2_C &= 0xf3;    CAP2_C |= 0x04                        //CAP2捕捉工作时基为定时器1
#define  CAP2_TMR2_S   CAP2_C &= 0xf3;    CAP2_C |= 0x08                        //CAP2捕捉工作时基为定时器2
#define  CAP2_TMR3_S   CAP2_C |= 0x0c                                           //CAP2捕捉工作时基为定时器3

#define  CAP2_CAP_1    CAP2_C &= 0xcf                                           //CAP2捕捉 1 个触发边沿产生1 次捕捉事件
#define  CAP2_CAP_4    CAP2_C &= 0xcf;    CAP2_C |= 0x10                        //CAP2捕捉 4 个触发边沿产生1 次捕捉事件
#define  CAP2_CAP_8    CAP2_C &= 0xcf;    CAP2_C |= 0x20                        //CAP2捕捉 8 个触发边沿产生1 次捕捉事件
#define  CAP2_CAP_16   CAP2_C |= 0x30                                           //CAP2捕捉 16个触发边沿产生1 次捕捉事件

#define  CAP2_CAP_NONE CAP2_C &= 0x3f                                           //CAP2捕捉    保留
#define  CAP2_CAP_POS  CAP2_C &= 0x3f;    CAP2_C |= 0x40                        //CAP2捕捉    上升沿捕捉
#define  CAP2_CAP_NEG  CAP2_C &= 0x3f;    CAP2_C |= 0x80                        //CAP2捕捉    下降沿捕捉
#define  CAP2_CAP_EDGE CAP2_C |= 0xc0                                           //CAP2捕捉    上升和下降沿都捕捉

//PWM0
#define  PWM0_MD_DIS   PWM0_C &= 0xfc                                           //关闭PWM0
#define  PWM0_MD_EN    PWM0_C &= 0xfc;    PWM0_C |= 0x01                        //使能PWM0

#define  PWM0_TMR0_S   PWM0_C &= 0xf3                                           //PWM0工作时基为定时器0
#define  PWM0_TMR1_S   PWM0_C &= 0xf3;PWM0_C |= 0x04                            //PWM0工作时基为定时器1
#define  PWM0_TMR2_S   PWM0_C &= 0xf3;PWM0_C |= 0x08                            //PWM0工作时基为定时器2
#define  PWM0_TMR3_S   PWM0_C |= 0x0c                                           //PWM0工作时基为定时器3

#define  PWM0_EDG_MD   PWM0_C &= 0xcf                                           //PWM0边沿对齐模式
#define  PWM0_MID_MD   PWM0_C &= 0xcf;PWM0_C |= 0x10                            //PWM0中心对齐模式

#define  PWM0_STP_DIS  PWM0_C &= 0x3f                                           //PWM0  关闭刹车功能
#define  PWM0_STP_LV   PWM0_C &= 0x3f;PWM0_C |= 0x40                            //PWM0  STP 复用端口输入低电平刹车
#define  PWM0_STP_CMP_LV  PWM0_C &= 0x3f;PWM0_C |= 0x80                         //PWM0  比较器输出低刹车
#define  PWM0_STP_SOFT PWM0_C |= 0xc0                                           //PWM0  软件刹车（写“11”立即进入刹车状态）


#define  PWM0_CH0_H_L  PWM0_OC &= 0xfe                                          //PWM00 匹配点前输出值1，匹配点后输出0
#define  PWM0_CH0_L_H  PWM0_OC |= 0x01                                          //PWM00 匹配点前输出值0，匹配点后输出1

#define  PWM0_CH1_H_L  PWM0_OC &= 0xfd                                          //PWM01 匹配点前输出值1，匹配点后输出0
#define  PWM0_CH1_L_H  PWM0_OC |= 0x02                                          //PWM01 匹配点前输出值0，匹配点后输出1

#define  PWM0_CH0_T_L  PWM0_OC &= 0xfb                                          //PWM00 初始输出低电平
#define  PWM0_CH0_T_H  PWM0_OC |= 0x04                                          //PWM00 初始输出高电平
    
#define  PWM0_CH1_T_L  PWM0_OC &= 0xf7                                          //PWM01 初始输出低电平
#define  PWM0_CH1_T_H  PWM0_OC |= 0x08                                          //PWM01 初始输出高电平

#define  PWM0_REX_0    PWM0_OC &= 0x0f                                          //PWM0平均占空比扩张位
#define  PWM0_REX_1    PWM0_OC &= 0x0f; PWM0_OC |= 0x1f                         //PWM0平均占空比扩张位
#define  PWM0_REX_2    PWM0_OC &= 0x0f; PWM0_OC |= 0x2f                         //PWM0平均占空比扩张位
#define  PWM0_REX_3    PWM0_OC &= 0x0f; PWM0_OC |= 0x3f                         //PWM0平均占空比扩张位
#define  PWM0_REX_4    PWM0_OC &= 0x0f; PWM0_OC |= 0x4f                         //PWM0平均占空比扩张位
#define  PWM0_REX_5    PWM0_OC &= 0x0f; PWM0_OC |= 0x5f                         //PWM0平均占空比扩张位
#define  PWM0_REX_6    PWM0_OC &= 0x0f; PWM0_OC |= 0x6f                         //PWM0平均占空比扩张位
#define  PWM0_REX_7    PWM0_OC &= 0x0f; PWM0_OC |= 0x7f                         //PWM0平均占空比扩张位


//PWM1
#define  PWM1_MD_DIS   PWM1_C &= 0xfc                                           //关闭PWM1
#define  PWM1_MD_EN    PWM1_C &= 0xfc;    PWM1_C |= 0x01                        //使能PWM1

#define  PWM1_TMR0_S   PWM1_C &= 0xf3                                           //PWM1工作时基为定时器0
#define  PWM1_TMR1_S   PWM1_C &= 0xf3;PWM1_C |= 0x04                            //PWM1工作时基为定时器1
#define  PWM1_TMR2_S   PWM1_C &= 0xf3;PWM1_C |= 0x08                            //PWM1工作时基为定时器2
#define  PWM1_TMR3_S   PWM1_C |= 0x0c                                           //PWM1工作时基为定时器3

#define  PWM1_EDG_MD   PWM1_C &= 0xcf                                           //PWM1边沿对齐模式
#define  PWM1_MID_MD   PWM1_C &= 0xcf;PWM1_C |= 0x10                            //PWM1中心对齐模式

#define  PWM1_STP_DIS     PWM1_C &= 0x3f                                        //PWM1  关闭刹车功能
#define  PWM1_STP_LV      PWM1_C &= 0x3f;PWM1_C |= 0x40                         //PWM1  STP 复用端口输入低电平刹车
#define  PWM1_STP_CMP_LV  PWM1_C &= 0x3f;PWM1_C |= 0x80                         //PWM1  比较器输出低刹车
#define  PWM1_STP_SOFT    PWM1_C |= 0xc0                                        //PWM1  软件刹车（写“11”立即进入刹车状态）


#define  PWM1_CH0_H_L  PWM1_OC &= 0xfe                                          //PWM10 匹配点前输出值1，匹配点后输出0
#define  PWM1_CH0_L_H  PWM1_OC |= 0x01                                          //PWM10 匹配点前输出值0，匹配点后输出1

#define  PWM1_CH1_H_L  PWM1_OC &= 0xfd                                          //PWM11 匹配点前输出值1，匹配点后输出0
#define  PWM1_CH1_L_H  PWM1_OC |= 0x02                                          //PWM11 匹配点前输出值0，匹配点后输出1

#define  PWM1_CH0_T_L  PWM1_OC &= 0xfb                                          //PWM10 初始输出低电平
#define  PWM1_CH0_T_H  PWM1_OC |= 0x04                                          //PWM10 初始输出高电平

#define  PWM1_CH1_T_L  PWM1_OC &= 0xf7                                          //PWM11 初始输出低电平
#define  PWM1_CH1_T_H  PWM1_OC |= 0x08                                          //PWM11 初始输出高电平

#define  PWM1_REX_0    PWM1_OC &= 0x0f                                          //PWM1平均占空比扩张位
#define  PWM1_REX_1    PWM1_OC &= 0x0f; PWM1_OC |= 0x1f                         //PWM1平均占空比扩张位
#define  PWM1_REX_2    PWM1_OC &= 0x0f; PWM1_OC |= 0x2f                         //PWM1平均占空比扩张位
#define  PWM1_REX_3    PWM1_OC &= 0x0f; PWM1_OC |= 0x3f                         //PWM1平均占空比扩张位
#define  PWM1_REX_4    PWM1_OC &= 0x0f; PWM1_OC |= 0x4f                         //PWM1平均占空比扩张位
#define  PWM1_REX_5    PWM1_OC &= 0x0f; PWM1_OC |= 0x5f                         //PWM1平均占空比扩张位
#define  PWM1_REX_6    PWM1_OC &= 0x0f; PWM1_OC |= 0x6f                         //PWM1平均占空比扩张位
#define  PWM1_REX_7    PWM1_OC &= 0x0f; PWM1_OC |= 0x7f                         //PWM1平均占空比扩张位



//PWM2
#define  PWM2_MD_DIS   PWM2_C &= 0xfc                                           //关闭PWM2
#define  PWM2_MD_EN    PWM2_C &= 0xfc;    PWM2_C |= 0x01                        //使能PWM2

#define  PWM2_TMR0_S   PWM2_C &= 0xf3                                           //PWM2工作时基为定时器0
#define  PWM2_TMR1_S   PWM2_C &= 0xf3;PWM2_C |= 0x04                            //PWM2工作时基为定时器1
#define  PWM2_TMR2_S   PWM2_C &= 0xf3;PWM2_C |= 0x08                            //PWM2工作时基为定时器2
#define  PWM2_TMR3_S   PWM2_C |= 0x0c                                           //PWM2工作时基为定时器3

#define  PWM2_EDG_MD   PWM2_C &= 0xcf                                           //PWM2边沿对齐模式
#define  PWM2_MID_MD   PWM2_C &= 0xcf;PWM2_C |= 0x10                            //PWM2中心对齐模式

#define  PWM2_STP_DIS     PWM2_C &= 0x3f                                        //PWM2  关闭刹车功能
#define  PWM2_STP_LV      PWM2_C &= 0x3f;PWM2_C |= 0x40                         //PWM2  STP 复用端口输入低电平刹车
#define  PWM2_STP_CMP_LV  PWM2_C &= 0x3f;PWM2_C |= 0x80                         //PWM2  比较器输出低刹车
#define  PWM2_STP_SOFT    PWM2_C |= 0xc0                                        //PWM2  软件刹车（写“11”立即进入刹车状态）


#define  PWM2_CH0_H_L  PWM2_OC &= 0xfe                                          //PWM20 匹配点前输出值1，匹配点后输出0
#define  PWM2_CH0_L_H  PWM2_OC |= 0x01                                          //PWM20 匹配点前输出值0，匹配点后输出1

#define  PWM2_CH1_H_L  PWM2_OC &= 0xfd                                          //PWM21 匹配点前输出值1，匹配点后输出0
#define  PWM2_CH1_L_H  PWM2_OC |= 0x02                                          //PWM21 匹配点前输出值0，匹配点后输出1

#define  PWM2_CH0_T_L  PWM2_OC &= 0xfb                                          //PWM20 初始输出低电平
#define  PWM2_CH0_T_H  PWM2_OC |= 0x04                                          //PWM20 初始输出高电平

#define  PWM2_CH1_T_L  PWM2_OC &= 0xf7                                          //PWM21 初始输出低电平
#define  PWM2_CH1_T_H  PWM2_OC |= 0x08                                          //PWM21 初始输出高电平

#define  PWM2_REX_0    PWM2_OC &= 0x0f                                          //PWM2平均占空比扩张位
#define  PWM2_REX_1    PWM2_OC &= 0x0f; PWM2_OC |= 0x1f                         //PWM2平均占空比扩张位
#define  PWM2_REX_2    PWM2_OC &= 0x0f; PWM2_OC |= 0x2f                         //PWM2平均占空比扩张位
#define  PWM2_REX_3    PWM2_OC &= 0x0f; PWM2_OC |= 0x3f                         //PWM2平均占空比扩张位
#define  PWM2_REX_4    PWM2_OC &= 0x0f; PWM2_OC |= 0x4f                         //PWM2平均占空比扩张位
#define  PWM2_REX_5    PWM2_OC &= 0x0f; PWM2_OC |= 0x5f                         //PWM2平均占空比扩张位
#define  PWM2_REX_6    PWM2_OC &= 0x0f; PWM2_OC |= 0x6f                         //PWM2平均占空比扩张位
#define  PWM2_REX_7    PWM2_OC &= 0x0f; PWM2_OC |= 0x7f                         //PWM2平均占空比扩张位

//SPI
#define  SPI_CLK_DIV2       SPI_C0 &= 0xF8                                      //SPI分频器，2   分频
#define  SPI_CLK_DIV4       SPI_C0 &= 0xF8;SPI_C0 |= 0x01                       //SPI分频器，4   分频
#define  SPI_CLK_DIV8       SPI_C0 &= 0xF8;SPI_C0 |= 0x02                       //SPI分频器，8   分频
#define  SPI_CLK_DIV16      SPI_C0 &= 0xF8;SPI_C0 |= 0x03                       //SPI分频器，16  分频
#define  SPI_CLK_DIV32      SPI_C0 &= 0xF8;SPI_C0 |= 0x04                       //SPI分频器，32  分频
#define  SPI_CLK_DIV64      SPI_C0 &= 0xF8;SPI_C0 |= 0x05                       //SPI分频器，64  分频
#define  SPI_CLK_DIV128     SPI_C0 &= 0xF8;SPI_C0 |= 0x06                       //SPI分频器，128 分频

#define  SPI_DIR_MSB        SPI_C0 &= 0xF7                                      //SPI采用先发送MSB位的传输方式
#define  SPI_DIR_LSB        SPI_C0 |= 0x08                                      //SPI采用先发送LSB位的传输方式
    
#define  SPI_CHPA_F         SPI_C0 &= 0xEF                                      //SPI数据采样格式 SCK 周期的第一个沿采集数据
#define  SPI_CHPA_S         SPI_C0 |= 0x10                                      //SPI数据采样格式 SCK 周期的第二个沿采集数据

#define  SPI_CHOL_L         SPI_C0 &= 0xDF                                      //SPI管脚空闲状态 空闲状态是SCK 保持0
#define  SPI_CHOL_H         SPI_C0 |= 0x20                                      //SPI管脚空闲状态 空闲状态是SCK 保持1

#define  SPI_SSD_EN         SPI_C0 &= 0xBF                                      //SPI的SS 软件控制位  片选使能
#define  SPI_SSD_DIS        SPI_C0 |= 0x40                                      //SPI的SS 软件控制位  关闭片选

#define  SPI_SSC_SSPAD      SPI_C0 &= 0x7F                                      //SPI的SS 使能控制位  SS 管脚有效
#define  SPI_SSC_SOFT       SPI_C0 |= 0x80                                      //SPI的SS 使能控制位  片选信号软件控制,受SPI_SSD 控制

#define  SPI_EN             SPI_C1 |= 0x80                                      //SPI使能控制位 使能SPI功能
#define  SPI_DIS            SPI_C1 &= 0xEF                                      //SPI使能控制位 禁止SPI功能

#define  SPI_M              SPI_C1 &= 0xBF                                      //SPI主从模式  主控模式
#define  SPI_S              SPI_C1 |= 0x4F                                      //SPI主从模式  从机模式

#define  SPI_WOL_CLR        SPI_C1 &= 0xFD                                      //SPI 无写冲突，软件清0
#define  SPI_RSSP_CLR       SPI_C1 &= 0xFE                                      //SPI 无接收溢出，软件清0

//iic SCL 和SDA 采样滤波时间（要求远小于波特率设定的时钟周期）
#define   IIC_FLT_1         IIC_C0 &= 0x0F                                      //滤波时间Tflt = 1  / Fsysclk
#define   IIC_FLT_2         IIC_C0 &= 0x0F;     IIC_C0 |= 0x10                  //滤波时间Tflt = 2  / Fsysclk
#define   IIC_FLT_3         IIC_C0 &= 0x0F;     IIC_C0 |= 0x20                  //滤波时间Tflt = 3  / Fsysclk
#define   IIC_FLT_4         IIC_C0 &= 0x0F;     IIC_C0 |= 0x30                  //滤波时间Tflt = 4  / Fsysclk
#define   IIC_FLT_5         IIC_C0 &= 0x0F;     IIC_C0 |= 0x40                  //滤波时间Tflt = 5  / Fsysclk
#define   IIC_FLT_6         IIC_C0 &= 0x0F;     IIC_C0 |= 0x50                  //滤波时间Tflt = 6  / Fsysclk
#define   IIC_FLT_7         IIC_C0 &= 0x0F;     IIC_C0 |= 0x60                  //滤波时间Tflt = 7  / Fsysclk
#define   IIC_FLT_8         IIC_C0 &= 0x0F;     IIC_C0 |= 0x70                  //滤波时间Tflt = 8  / Fsysclk
#define   IIC_FLT_9         IIC_C0 &= 0x0F;     IIC_C0 |= 0x80                  //滤波时间Tflt = 9  / Fsysclk
#define   IIC_FLT_10        IIC_C0 &= 0x0F;     IIC_C0 |= 0x90                  //滤波时间Tflt = 10 / Fsysclk
#define   IIC_FLT_11        IIC_C0 &= 0x0F;     IIC_C0 |= 0xa0                  //滤波时间Tflt = 11 / Fsysclk
#define   IIC_FLT_12        IIC_C0 &= 0x0F;     IIC_C0 |= 0xb0                  //滤波时间Tflt = 12 / Fsysclk
#define   IIC_FLT_13        IIC_C0 &= 0x0F;     IIC_C0 |= 0xc0                  //滤波时间Tflt = 13 / Fsysclk
#define   IIC_FLT_14        IIC_C0 &= 0x0F;     IIC_C0 |= 0xd0                  //滤波时间Tflt = 14 / Fsysclk
#define   IIC_FLT_15        IIC_C0 &= 0x0F;     IIC_C0 |= 0xe0                  //滤波时间Tflt = 15 / Fsysclk
#define   IIC_FLT_16        IIC_C0 &= 0x0F;     IIC_C0 |= 0xf0                  //滤波时间Tflt = 16 / Fsysclk

//IIC 位中断模式选择位
#define   IIC_SSINT_EN      IIC_C0 &= 0xf7      // START 和STOP 位产生中断，完成1 个字节的接收或发送产生中断
#define   IIC_SSINT_DIS     IIC_C0 |= 0x08      // START 和STOP 位不产生中断，完成1 个字节的接收或发送产生中断

//IIC 等待功能使能位
#define   IIC_WAIT_EN       IIC_C0 |= 0x04      // 使能IIC等待功能
#define   IIC_WAIT_DIS      IIC_C0 &= 0xFB      // 关闭IIC等待功能
//IIC 主/从模式选择位
#define   IIC_M_MD          IIC_C0 &= 0xfD      // IIC设置为主控模式
#define   IIC_S_MD          IIC_C0 |= 0x06      // IIC设置为从动模式并且使能IIC等待功能

//IIC 使能位
#define   IIC_DIS           IIC_C0 &= 0xfE      // 禁止IIC功能
#define   IIC_EN            IIC_C0 |= 0x01      // 使能IIC功能

//#define   IIC_START_TG      IIC_C1 |= 0x04;     while((IIC_C1&0x04)==0x04){}
//#define   IIC_STOP_TG       IIC_C1 |= 0x08;     while((IIC_C1&0x08)==0x08){}

// ACK 位发送选择位
#define   IIC_ACK_TG        IIC_C1 &= 0xFE      // IIC发送ACK
#define   IIC_NACK_TG       IIC_C1 |= 0x01      // IIC发送NACK

//从机等待释放位（仅在IIC_MD=1 并且WTEN=1 时有意义）
#define   IIC_WAIT_CLR      IIC_C1 |= 0x02      // 置1 释放从机等待状态（完成下一字节传送时，硬件自动清零）

//IIC 超时时间
#define   IIC_OV_DIS        IIC_TOC = 0x00      //IIC超时时间 0 
#define   IIC_OV_D64        IIC_TOC = 0x80      //IIC超时时间 64    / Fsysclk
#define   IIC_OV_D128       IIC_TOC = 0x81      //IIC超时时间 128   / Fsysclk
#define   IIC_OV_D256       IIC_TOC = 0x83      //IIC超时时间 256   / Fsysclk
#define   IIC_OV_D512       IIC_TOC = 0x87      //IIC超时时间 512   / Fsysclk
#define   IIC_OV_D1024      IIC_TOC = 0x8f      //IIC超时时间 1024  / Fsysclk
#define   IIC_OV_D2048      IIC_TOC = 0x9f      //IIC超时时间 2048  / Fsysclk
#define   IIC_OV_D4096      IIC_TOC = 0xaf      //IIC超时时间 4096  / Fsysclk
#define   IIC_OV_D8192      IIC_TOC = 0xbf      //IIC超时时间 8192  / Fsysclk

//UART0 TX
#define  UART0_TX_DIS       UART0_TXC = 0x00    //UART0发送功能关闭
#define  UART0_TX8_1S       UART0_TXC = 0x02    //UART0发送模式为 8位数据，1位STOP位
#define  UART0_TX8_2S       UART0_TXC = 0x0a    //UART0发送模式为 8位数据，2位STOP位

#define  UART0_TX9_1S_ODD   UART0_TXC = 0x06    //UART0发送模式为 9位数据，1位STOP位
#define  UART0_TX9_2S_ODD   UART0_TXC = 0x0e    //UART0发送模式为 9位数据，2位STOP位

#define  UART0_TX9_1S_EVEN  UART0_TXC = 0x16    //UART0发送模式为 9位数据，1位STOP位，第9位为偶校验
#define  UART0_TX9_2S_EVEN  UART0_TXC = 0x1e    //UART0发送模式为 9位数据，2位STOP位，第9位为偶校验

#define  UART0_TX9_1S_D0    UART0_TXC = 0x26    //UART0发送模式为 9位数据，1位STOP位，第9位为数据0
#define  UART0_TX9_2S_D0    UART0_TXC = 0x2e    //UART0发送模式为 9位数据，2位STOP位，第9位为数据0

#define  UART0_TX9_1S_D1    UART0_TXC = 0x26    //UART0发送模式为 9位数据，1位STOP位，第9位为数据1
#define  UART0_TX9_2S_D1    UART0_TXC = 0x2e    //UART0发送模式为 9位数据，2位STOP位，第9位为数据1

//UART0 RX
#define  UART0_RX_DIS       UART0_RXC = 0x00    //UART0接收功能关闭

#define  UART0_RX8          UART0_RXC = 0x01    //UART0奇校验，使能8 位数据接收（不影响奇偶校验标志PERR）
#define  UART0_RX9_D        UART0_RXC = 0x02    //UART0奇校验，使能9 位数据接收（不影响奇偶校验标志PERR）
#define  UART0_RX9_ODD      UART0_RXC = 0x03    //UART0奇校验，使能9 位数据接收（影响奇偶校验标志PERR）
#define  UART0_RX9_EVEN     UART0_RXC = 0x0b    //UART0偶校验，使能8 位数据接收（不影响奇偶校验标志PERR）

//UART1 TX
#define  UART1_TX_DIS       UART1_TXC = 0x00    //UART1发送功能关闭
#define  UART1_TX8_1S       UART1_TXC = 0x02    //UART1发送模式为 8位数据，1位STOP位
#define  UART1_TX8_2S       UART1_TXC = 0x0a    //UART1发送模式为 8位数据，2位STOP位

#define  UART1_TX9_1S_ODD   UART1_TXC = 0x06    //UART1发送模式为 9位数据，1位STOP位
#define  UART1_TX9_2S_ODD   UART1_TXC = 0x0e    //UART1发送模式为 9位数据，2位STOP位

#define  UART1_TX9_1S_EVEN  UART1_TXC = 0x16    //UART1发送模式为 9位数据，1位STOP位，第9位为偶校验
#define  UART1_TX9_2S_EVEN  UART1_TXC = 0x1e    //UART1发送模式为 9位数据，2位STOP位，第9位为偶校验

#define  UART1_TX9_1S_D0    UART1_TXC = 0x26    //UART1发送模式为 9位数据，1位STOP位，第9位为数据0
#define  UART1_TX9_2S_D0    UART1_TXC = 0x2e    //UART1发送模式为 9位数据，2位STOP位，第9位为数据0

#define  UART1_TX9_1S_D1    UART1_TXC = 0x26    //UART1发送模式为 9位数据，1位STOP位，第9位为数据1
#define  UART1_TX9_2S_D1    UART1_TXC = 0x2e    //UART1发送模式为 9位数据，2位STOP位，第9位为数据1

//UART RX                                       
#define  UART1_RX_DIS       UART1_RXC = 0x00    //UART1接收功能关闭

#define  UART1_RX8          UART1_RXC = 0x01    //UART1奇校验，使能8 位数据接收（不影响奇偶校验标志PERR）
#define  UART1_RX9_D        UART1_RXC = 0x02    //UART1奇校验，使能9 位数据接收（不影响奇偶校验标志PERR）
#define  UART1_RX9_ODD      UART1_RXC = 0x03    //UART1奇校验，使能9 位数据接收（影响奇偶校验标志PERR）
#define  UART1_RX9_EVEN     UART1_RXC = 0x0b    //UART1偶校验，使能8 位数据接收（不影响奇偶校验标志PERR）

//ADC
#define    ADC_EN           ADC_C0 |= 0x80                      //使能ADC功能
#define    ADC_DIS          ADC_C0 &= 0x7f                      //禁止ADC功能
#define    ADC_SOFT_TG      ADC_C0 |= 0x80; ADC_C0 |= 0x40      //软件触发ADC转换，开启ADC转换
#define    ADC_TMR2_TG      ADC_C0 &= 0xC0; ADC_C0 |= 0x10      //定时器2计数匹配ADC_TR_R0值后触发ADC转换
#define    ADC_TMR2_PWM_TG  ADC_C0 |= 0x20                      //TMR2 计数值匹配ADC_TR_R0 值后触发ADC，再PWM1_R0+ADC_TR_R0 后再次触发ADC,此处需注意的是整体的周期限制不要溢出。
//ADC 采样通道选择位
#define    ADC_P20_AN0      ADC_C0 &= 0xF0                      //设置ADC采样通道为AN0     P20_ADC通道AN0 
#define    ADC_P21_AN1      ADC_C0 &= 0xF0; ADC_C0 |= 0x01      //设置ADC采样通道为AN1     P21_ADC通道AN1 
#define    ADC_P22_AN2      ADC_C0 &= 0xF0; ADC_C0 |= 0x02      //设置ADC采样通道为AN2     P22_ADC通道AN2 
#define    ADC_P23_AN3      ADC_C0 &= 0xF0; ADC_C0 |= 0x03      //设置ADC采样通道为AN3     P23_ADC通道AN3 
#define    ADC_P34_AN4      ADC_C0 &= 0xF0; ADC_C0 |= 0x04      //设置ADC采样通道为AN4     P34_ADC通道AN4 
#define    ADC_P35_AN5      ADC_C0 &= 0xF0; ADC_C0 |= 0x05      //设置ADC采样通道为AN5     P35_ADC通道AN5 
#define    ADC_P36_AN6      ADC_C0 &= 0xF0; ADC_C0 |= 0x06      //设置ADC采样通道为AN6     P36_ADC通道AN6 
#define    ADC_P37_AN7      ADC_C0 &= 0xF0; ADC_C0 |= 0x07      //设置ADC采样通道为AN7     P37_ADC通道AN7 
#define    ADC_P24_AN8      ADC_C0 &= 0xF0; ADC_C0 |= 0x08      //设置ADC采样通道为AN8     P24_ADC通道AN8 
#define    ADC_P03_AN9      ADC_C0 &= 0xF0; ADC_C0 |= 0x09      //设置ADC采样通道为AN9     P03_ADC通道AN9 
#define    ADC_P10_AN10     ADC_C0 &= 0xF0; ADC_C0 |= 0x0A      //设置ADC采样通道为AN10    P10_ADC通道AN10
#define    ADC_VDD_DIV4     ADC_C0 &= 0xF0; ADC_C0 |= 0x0B      //设置ADC采样通道为内部VDD/4
#define    ADC_CH_DIS       ADC_C0 |= 0x0F                      //关闭ADC采样通道
//ADC 参考电压设置
#define    ADC_VREF_DIS     ADC_C1 &= 0x0F                                      //关闭内部参考电压
#define    ADC_RVDD_AVG1    ADC_C1 &= 0x0F;   ADC_C1 = 0x20; ADC_C2 = 0x0A      //参考电压选择内部VDD，1 次转换
#define    ADC_RVDD_AVG2    ADC_C1 &= 0x0F;   ADC_C1 = 0x20; ADC_C2 = 0x1A      //参考电压选择内部VDD，2 次转换取平均
#define    ADC_RVDD_AVG4    ADC_C1 &= 0x0F;   ADC_C1 = 0x20; ADC_C2 = 0x2A      //参考电压选择内部VDD，4 次转换取平均
#define    ADC_RVDD_AVG8    ADC_C1 &= 0x0F;   ADC_C1 = 0x20; ADC_C2 = 0x3A      //参考电压选择内部VDD，8 次转换取平均

#define    ADC_RADVP_AVG1   ADC_C1 &= 0x0F;   ADC_C1 |= 0x10; ADC_C2 = 0x0A     //参考电压选择外部输入，1 次转换
#define    ADC_RADVP_AVG2   ADC_C1 &= 0x0F;   ADC_C1 |= 0x10; ADC_C2 = 0x1A     //参考电压选择外部输入，2 次转换取平均
#define    ADC_RADVP_AVG4   ADC_C1 &= 0x0F;   ADC_C1 |= 0x10; ADC_C2 = 0x2A     //参考电压选择外部输入，4 次转换取平均
#define    ADC_RADVP_AVG8   ADC_C1 &= 0x0F;   ADC_C1 |= 0x10; ADC_C2 = 0x3A     //参考电压选择外部输入，8 次转换取平均

#define    ADC_RVREF25_AVG1 ADC_C1 &= 0x0F;   ADC_C1 |= 0x80; ADC_C2 = 0x0A; VREF_C = 0xEB  //参考电压选择内部2.5V，1 次转换
#define    ADC_RVREF25_AVG2 ADC_C1 &= 0x0F;   ADC_C1 |= 0x80; ADC_C2 = 0x1A; VREF_C = 0xEB  //参考电压选择内部2.5V，2 次转换取平均
#define    ADC_RVREF25_AVG4 ADC_C1 &= 0x0F;   ADC_C1 |= 0x80; ADC_C2 = 0x2A; VREF_C = 0xEB  //参考电压选择内部2.5V，4 次转换取平均
#define    ADC_RVREF25_AVG8 ADC_C1 &= 0x0F;   ADC_C1 |= 0x80; ADC_C2 = 0x3A; VREF_C = 0xEB  //参考电压选择内部2.5V，8 次转换取平均

#define    ADC_RVREF2048_AVG1 ADC_C1 &= 0x0F;   ADC_C1 |= 0x90; ADC_C2 = 0x0A; VREF_C = 0xEB//参考电压选择内部2.048V，1 次转换
#define    ADC_RVREF2048_AVG2 ADC_C1 &= 0x0F;   ADC_C1 |= 0x90; ADC_C2 = 0x1A; VREF_C = 0xEB//参考电压选择内部2.048V，2 次转换取平均
#define    ADC_RVREF2048_AVG4 ADC_C1 &= 0x0F;   ADC_C1 |= 0x90; ADC_C2 = 0x2A; VREF_C = 0xEB//参考电压选择内部2.048V，4 次转换取平均
#define    ADC_RVREF2048_AVG8 ADC_C1 &= 0x0F;   ADC_C1 |= 0x90; ADC_C2 = 0x3A; VREF_C = 0xEB//参考电压选择内部2.048V，8 次转换取平均

#define    ADC_RVREF1024_AVG1  ADC_C1 &= 0x0F;   ADC_C1 |= 0xA0; ADC_C2 = 0x0A;VREF_C = 0xEB//参考电压选择内部1.024V，1 次转换
#define    ADC_RVREF1024_AVG2  ADC_C1 &= 0x0F;   ADC_C1 |= 0xA0; ADC_C2 = 0x1A;VREF_C = 0xEB//参考电压选择内部1.024V，2 次转换取平均
#define    ADC_RVREF1024_AVG4  ADC_C1 &= 0x0F;   ADC_C1 |= 0xA0; ADC_C2 = 0x2A;VREF_C = 0xEB//参考电压选择内部1.024V，4 次转换取平均
#define    ADC_RVREF1024_AVG8  ADC_C1 &= 0x0F;   ADC_C1 |= 0xA0; ADC_C2 = 0x3A;VREF_C = 0xEB//参考电压选择内部1.024V，8 次转换取平均

#define    ADC_RVREF15_AVG1  ADC_C1 &= 0x0F;   ADC_C1 |= 0xC0; ADC_C2 = 0x0A;VREF_C = 0xEB  //参考电压选择内部1.5V，1 次转换
#define    ADC_RVREF15_AVG2  ADC_C1 &= 0x0F;   ADC_C1 |= 0xC0; ADC_C2 = 0x1A;VREF_C = 0xEB  //参考电压选择内部1.5V，2 次转换取平均
#define    ADC_RVREF15_AVG4  ADC_C1 &= 0x0F;   ADC_C1 |= 0xC0; ADC_C2 = 0x2A;VREF_C = 0xEB  //参考电压选择内部1.5V，4 次转换取平均
#define    ADC_RVREF15_AVG8  ADC_C1 &= 0x0F;   ADC_C1 |= 0xC0; ADC_C2 = 0x3A;VREF_C = 0xEB  //参考电压选择内部1.5V，8 次转换取平均

#define    ADC_RVREF12_AVG1  ADC_C1 &= 0x0F;   ADC_C1 |= 0xD0; ADC_C2 = 0x0A;VREF_C = 0xEB  //参考电压选择内部1.2V，1 次转换
#define    ADC_RVREF12_AVG2  ADC_C1 &= 0x0F;   ADC_C1 |= 0xD0; ADC_C2 = 0x1A;VREF_C = 0xEB  //参考电压选择内部1.2V，2 次转换取平均
#define    ADC_RVREF12_AVG4  ADC_C1 &= 0x0F;   ADC_C1 |= 0xD0; ADC_C2 = 0x2A;VREF_C = 0xEB  //参考电压选择内部1.2V，4 次转换取平均
#define    ADC_RVREF12_AVG8  ADC_C1 &= 0x0F;   ADC_C1 |= 0xD0; ADC_C2 = 0x3A;VREF_C = 0xEB  //参考电压选择内部1.2V，8 次转换取平均

#define    ADC_RVREF05_AVG1  ADC_C1 &= 0x0F;   ADC_C1 |= 0xE0; ADC_C2 = 0x0A;VREF_C = 0xEB  //参考电压选择内部0.5V，1 次转换
#define    ADC_RVREF05_AVG2  ADC_C1 &= 0x0F;   ADC_C1 |= 0xE0; ADC_C2 = 0x1A;VREF_C = 0xEB  //参考电压选择内部0.5V，2 次转换取平均
#define    ADC_RVREF05_AVG4  ADC_C1 &= 0x0F;   ADC_C1 |= 0xE0; ADC_C2 = 0x2A;VREF_C = 0xEB  //参考电压选择内部0.5V，4 次转换取平均
#define    ADC_RVREF05_AVG8  ADC_C1 &= 0x0F;   ADC_C1 |= 0xE0; ADC_C2 = 0x3A;VREF_C = 0xEB  //参考电压选择内部0.5V，8 次转换取平均
  
#define    ADC_RVREF02_AVG1  ADC_C1 &= 0x0F;   ADC_C1 |= 0xF0; ADC_C2 = 0x0A;VREF_C = 0xEB  //参考电压选择内部0.2V，1 次转换
#define    ADC_RVREF02_AVG2  ADC_C1 &= 0x0F;   ADC_C1 |= 0xF0; ADC_C2 = 0x1A;VREF_C = 0xEB  //参考电压选择内部0.2V，2 次转换取平均
#define    ADC_RVREF02_AVG4  ADC_C1 &= 0x0F;   ADC_C1 |= 0xF0; ADC_C2 = 0x2A;VREF_C = 0xEB  //参考电压选择内部0.2V，4 次转换取平均
#define    ADC_RVREF02_AVG8  ADC_C1 &= 0x0F;   ADC_C1 |= 0xF0; ADC_C2 = 0x3A;VREF_C = 0xEB  //参考电压选择内部0.2V，8 次转换取平均
   
//VREF
#define    VREF_EN     VREF_C = 0xEB                // 使能内部参考电压模块
#define    VREF_DIS    VREF_C = 0x00                // 关闭内部参考电压模块

//低电压检测模块LVD
#define    LVD_EN      LVD_C |= 0x80                // 使能LVD内部低电压检测模块
#define    LVD_DIS     LVD_C &= 0x7f                // 禁止LVD内部低电压检测模块
//LVD 中断模式选择位   
#define    LVD_IM_H    LVD_C |= 0x40                // 被监测电压由高于比较阈值产生LVD 中断
#define    LVD_IM_L    LVD_C &= 0xBf                // 被监测电压由低于比较阈值产生LVD 中断
//LVD 滤波选择位 
#define    LVD_FLT_EN  LVD_C |= 0x20                // LVD滤波选择7个LVD工作时钟
#define    LVD_FLT_DIS LVD_C &= 0xdf                // 关闭滤波器
//LVD 工作时钟选择位   
#define    LVD_CLK_LRC   LVD_C |= 0x10              // LVD时钟为内部低频时钟LRC
#define    LVD_CLK_SYS   LVD_C &= 0xef              // LVD时钟为系统时钟SYS_CLK
//被监测电压选择位  
#define    LVD_LVD_IN_1P2 LVD_C |= 0x08             // LVD监测LVDIN复用管脚输入的电压值（比较阈值电压固定为1.2V）
#define    LVD_LVD_IN_VDD LVD_C |= 0xF7             // LVD监测VDD的电压值

//LVD阈值电压选择位（仅用于监测VDD）,中断不可唤醒低功耗模式
#define    LVD_VDD_1P8  LVD_C &= 0xF0               //LVD阈值电压设置为1.8V
#define    LVD_VDD_2P2  LVD_C &= 0xF0;LVD_C |= 0x01 //LVD阈值电压设置为2.2V
#define    LVD_VDD_2P6  LVD_C &= 0xF0;LVD_C |= 0x02 //LVD阈值电压设置为2.6V
#define    LVD_VDD_3P0  LVD_C &= 0xF0;LVD_C |= 0x03 //LVD阈值电压设置为3.0V
#define    LVD_VDD_3P4  LVD_C &= 0xF0;LVD_C |= 0x04 //LVD阈值电压设置为3.4V
#define    LVD_VDD_3P8  LVD_C &= 0xF0;LVD_C |= 0x05 //LVD阈值电压设置为3.8V
#define    LVD_VDD_4P2  LVD_C &= 0xF0;LVD_C |= 0x06 //LVD阈值电压设置为4.2V
#define    LVD_VDD_4P6  LVD_C &= 0xF0;LVD_C |= 0x07 //LVD阈值电压设置为4.6V

#endif
