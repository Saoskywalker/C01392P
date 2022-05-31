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

#define GCE_GIE(x)				 GIE = x // 总中断宏定义
//WDT-------------------------------------
//WDT_OP WDT 操作寄存器
//写：写入5AH 将WDT 计数器清0，且清除WDT 溢出标志
//读： WDT 未溢出读出为00H，WDT 溢出读出为01H，WDT 溢出唤醒读出为03H
#define GCE_CLRWDT()   WDT_OP=0x5A        //宏定义清狗指令

#define GCE_SOFT_RST            SOFT_RST = 0xA5 // 软件复位

#define GCE_SLEEP               PCON = 0x50; PCON = 0x01; PCON = 0xA0 // 进入sleep模式
#define GCE_IDLE                PCON = 0x50; PCON = 0x02; PCON = 0xA0 // 进入idle模式
//==========================================================================================
//ADC定义部分END
//==========================================================================================
#define GCE_ADC_TRG                   ADC_C0 |= bit6///开始转换
#define GCE_ADC_SET_CH(ch)            ADC_C0 = bit7|ch  ///启用ADC设置通道//设置通道
#define GCE_GET_ADC_VALUE            ((UI16)(ADC_DH << 8) | ADC_DL)// 获取ADC值
//ADC---------------------------------
#define ADC_USE_CHANNEL_TOTAL  4 //使用到的所有ADC通道数量

//#define TOIL_ADC_channel ADC_NUM_AN0        //通道0   未使用
//#define ADCNUM_NOTUSE ADC_NUM_AN1        //通道1   未使用
//#define TOIL_ADC_channel ADC_NUM_AN2        //通道2   未使用
//#define COMP_ADC_channel ADC_NUM_AN3        //通道3   未使用
#define Troom_ADC_channel ADC_NUM_AN4       //通道4  室温
#define HUM_ADC_channel ADC_NUM_AN5       //通道5   管温
#define COMP_ADC_channel ADC_NUM_AN6        //通道6   未使用
//#define ADCNUM_NOTUSE ADC_NUM_AN7        //通道7   未使用
//#define COMP_ADC_channel ADC_NUM_AN8        //1/4VDD  未使用
//#define ADCNUM_ROOM_T ADC_NUM_AN9        //通道9   未使用
#define TOIL_ADC_channel ADC_NUM_AN10       //通道10  未使用
//#define ADCNUM_NOTUSE ADC_NUM_AN11       ////固定选择内部1/4VDD 通道//未使用

#define ADC_USE_CHANNEL_TAB     TOIL_ADC_channel,COMP_ADC_channel,Troom_ADC_channel,HUM_ADC_channel   //此处将所用到的通道复制粘贴到此
#define ADC_USE_CHANNEL_FIRST   TOIL_ADC_channel //首次启动ADC采样通道
//==========================================================================================
//ADC定义部分START
//总共12通道12位SAR ADC，其中1路通道用亍VDD 检测，
//==========================================================================================
//使用的单个ADC通道定义
//==========================================================================================
//使用的全部ADC通道
//==========================================================================================

//==========================================================================================
//ADC定义部分END
//==========================================================================================
//==========================================================================================
//UART定义部分START
//总共2通道UART
//==========================================================================================
//UART---------------------------------
#define GCE_UART0_TXD  UART0_TXB
#define GCE_UART0_RXD  UART0_RXB


#define GCE_UART1_TXD  UART1_TXB
#define GCE_UART1_RXD  UART1_RXB
//==========================================================================================
//UART定义部分END
//==========================================================================================
//--<< PWM占空比 宏定义 >>------------------------------------------------------
#define USER_PWM00_DUTY(duty)    PWM0_R0H = (UI08)(duty >> 8); PWM0_R0L = (UI08)(duty) // PWM00通道占空比
#define USER_PWM01_DUTY(duty)    PWM0_R1H = (UI08)(duty >> 8); PWM0_R1L = (UI08)(duty) // PWM01通道占空比

#define USER_PWM10_DUTY(duty)    PWM1_R0H = (UI08)(duty >> 8); PWM1_R0L = (UI08)(duty) // PWM10通道占空比
#define USER_PWM11_DUTY(duty)    PWM1_R1H = (UI08)(duty >> 8); PWM1_R1L = (UI08)(duty) // PWM11通道占空比

#define USER_PWM20_DUTY(duty)    PWM2_R0H = (UI08)(duty >> 8); PWM2_R0L = (UI08)(duty) // PWM20通道占空比
#define USER_PWM21_DUTY(duty)    PWM2_R1H = (UI08)(duty >> 8); PWM2_R1L = (UI08)(duty) // PWM21通道占空比



//==========================================================================================
//IO定义部分START
//总共30个IO
//==========================================================================================
//使用的单个IO通道定义
//IO---------------------------------
//调试IO请设为输出---------------------------------
//#define DEBUG_IO_PORT  P2_3
#define DEBUG_IO_PORT  P2_4
#define DEBUG_IO_XOR  (DEBUG_IO_PORT^=1)
#define DEBUG_IO_H  (DEBUG_IO_PORT=1)
#define DEBUG_IO_L  (DEBUG_IO_PORT=0)


#define  Txd_H             P1_3=1
#define  Txd_L             P1_3=0
#define  Rxd_IO            (P1_4)
//#define  Comm_input_init     P27_OUT_DIS,P27_IN_EN //配置通信口为输入
//#define  Comm_output_init    P27_IN_DIS,P27_OUT_EN //配置通信口为输出
#define  Comm_input_init      //配置通信口为输入
#define  Comm_output_init     //配置通信口为输出

////
#define  SCL_output_init     P32_IN_DIS,P32_OUT_EN //配置通信口为输入
#define  SDA_output_init     P31_IN_DIS,P31_OUT_EN //配置通信口为输出
#define  SDA_input_init      P31_OUT_DIS,P31_IN_EN //配置通信口为输出

#define SDA_high    P3_1=1
#define SDA_low     P3_1=0

#define SCL_high    P3_2=1
#define SCL_low     P3_2=0

#define Sda         (P3_1)  //HUM1
#define Scl         (P3_2)  //HUM2 或者 HUM_AD
////

#define HUM1_L P3_1 = 0
#define HUM1_H P3_1 = 1
#define HUM2_L P3_2 = 0
#define HUM2_H P3_2 = 1

#define  WATER_IO      (P0_2)  //水满开关IO

#define  Filt_IO       (P2_4)      //滤网接入开关IO

//#define  AC_110V_IO        (P3_2)
//Motor
#define  Motor_POWER_OFF      P3_7=0
#define  Motor_POWER_ON       P3_7=1

#define  Motor_CW_EN          P2_2=0 //电机正反转控制
#define  Motor_CCW_EN         P2_2=1
#define  PWM_DUTY_Set(duty)   USER_PWM01_DUTY(duty)
//

#define  COMP_OFF          P0_1=0
#define  COMP_ON           P0_1=1

#define  UVC_OFF           P0_5=0
#define  UVC_ON            P0_5=1


//上下摆动步进电机段码
#define  EXV_UD_A_H      P1_5=1
#define  EXV_UD_A_L      P1_5=0

#define  EXV_UD_B_H      P1_6=1
#define  EXV_UD_B_L      P1_6=0

#define  EXV_UD_C_H      P1_7=1
#define  EXV_UD_C_L      P1_7=0

#define  EXV_UD_D_H      P0_0=1
#define  EXV_UD_D_L      P0_0=0

//左右摆动步进电机段码
//#define  EXV_LR_A_H      P3_0=1
//#define  EXV_LR_A_L      P3_0=0

//#define  EXV_LR_B_H      P3_1=1
//#define  EXV_LR_B_L      P3_1=0

//#define  EXV_LR_C_H      P1_6=1
//#define  EXV_LR_C_L      P1_6=0

//#define  EXV_LR_D_H      P1_5=1
//#define  EXV_LR_D_L      P1_5=0


#endif /* __GCE_RDF_H */

