/*********************************************************
*文件名:	lib_tk_lp.h
*作  者:	sinomicon
*版  本:	V0.00
*日  期:	2017/05/20
*描  述:	
*备  注:    
**********************************************************/
#include "user.h"

//lp 模式按键通道设置
#define LP_AllSensorNums 4   //设置低功耗扫描分组数
/*设置低功耗下按键分组序号*/
#define LP_P26_TK_NUM    0
#define LP_P27_TK_NUM    0
#define LP_P04_TK_NUM    0

#define LP_P02_TK_NUM    1
#define LP_P15_TK_NUM    1
#define LP_P14_TK_NUM	   1

#define LP_P12_TK_NUM	   2
#define LP_P13_TK_NUM	   2
#define LP_P34_TK_NUM    2

#define LP_P35_TK_NUM    3
#define LP_P36_TK_NUM    3
#define LP_P37_TK_NUM    3

#define LS    0X05
/* TK低功耗模式灵敏度设置*/
#define LP_TK0_ini  LS
#define LP_TK1_ini  LS
#define LP_TK2_ini  LS
#define LP_TK3_ini  LS
#define LP_TK4_ini  LS
#define LP_TK5_ini  LS

/* TK寄存器值设定，以及模式定义*/
#define LP_REG_TK_C0   0xc0    //参见规格书TK_C1,无需设置
#define LP_REG_TK_C1   0x43    //参见规格书TK_C1,无需设置，目前使用内部滤波5次滤波，比较电压值为1.6V
#define LP_REG_TK_C2   0x00    //参见规格书TK_C2,充放电时钟设置，目前为系统时钟4分频，如果设置为0x08，为系统时钟6分频，如果设置为0x0c，为系统时钟8分频

uchar LP_tk_key(uchar LP_AllNums);
void LP_tk_data_store(void);
void LP_TK_scan();
void LP_TKInit();