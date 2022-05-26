/*********************************************************
*文件名:	lib_tk.h
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2017/05/20
*描  述:	
*备  注:    
**********************************************************/
#ifndef   __LIBTK_H__
#define   __LIBTK_H__
#include "user.h"

//设置管脚总数
#define AllSensorNums 8   //设置按键数

//设置对应按键序号
#define P10_TK_NUM	  0
#define P11_TK_NUM	  1
#define P12_TK_NUM	  2

#define P13_TK_NUM	  3	
#define P14_TK_NUM	  4	
#define P15_TK_NUM    5

#define P16_TK_NUM    6
#define P17_TK_NUM    7

//#define P35_TK_NUM    9
//#define P01_TK_NUM	  6
//#define P34_TK_NUM    7
//#define P00_TK_NUM	  10	
//#define P24_TK_NUM    12	
//#define P04_TK_NUM    13			
//#define P22_TK_NUM    14			
//#define P23_TK_NUM    15			
//#define P21_TK_NUM    16		
//#define P20_TK_NUM    17			
//#define P26_TK_NUM    18			
//#define P27_TK_NUM    19			
//#define P37_TK_NUM    20		
//#define P36_TK_NUM    21		
//#define P02_TK_NUM    22		
//#define P25_TK_NUM    23		

#define HS    10
/* TK高功耗模式灵敏度设置*/  //获取手指按下的变化量，取该变化量30~70%作为灵敏度设置
//设置范围为0~256，值越小灵敏度越高，一般不要小于8
#define TK_P10_ini  10
#define TK_P11_ini  10
#define TK_P12_ini  10  
#define TK_P13_ini  10
#define TK_P14_ini  10
#define TK_P15_ini  10
#define TK_P16_ini  10
#define TK_P17_ini  10

#define TK_P00_ini  HS
#define TK_P01_ini  HS
#define TK_P02_ini  HS
#define TK_P04_ini  HS

#define TK_P20_ini  HS
#define TK_P21_ini  HS
#define TK_P22_ini  HS
#define TK_P23_ini  HS
#define TK_P24_ini  HS
#define TK_P25_ini  HS
#define TK_P26_ini  HS
#define TK_P27_ini  HS

#define TK_P34_ini  10
#define TK_P35_ini  10
#define TK_P36_ini  HS
#define TK_P37_ini  HS

#define FLOW_MODE      0        //背景值跟踪速度bit<4:0>, 0~31，数值越大，跟踪熟读越快，bit7如果设置成1，则在按键被按下也会进行跟踪
#define MAX_KEY_MUL    1        //超过多个TK键同时被按下，将重新跟踪背景值，目前设置为2个
#define MKEY_LIMIT_CNT 5000     //0~65536多键被按下多少次后将重新跟踪背景值,目前是5000次（每次循环1个键按200us计算）

/* TK寄存器值设定，以及模式定义*/
#define REG_TK_C0   0xc0    //参见规格书TK_C0,无需设置
#define REG_TK_C1   0x43    //参见规格书TK_C1,无需设置，目前使用内部滤波5次滤波，比较电压值为1.5V
#define REG_TK_C2   0x04    //参见规格书TK_C2,充放电时钟设置，目前为系统时钟4分频，如果设置为0x08，为系统时钟6分频，如果设置为0x0c，为系统时钟8分频
#define TK_ini_t    0x07    //初始化扫描次数，需大于6次
//*******************************************************************************
//以下内容请勿修改
//*******************************************************************************
#define HP_MOOD     0x00    //高功耗模式
#define LP_MOOD     0x01    //低功耗模式
/* TouchKey寄存器设置*/
#define REG_VREF_C  0xeb
#define tk1_sel     0x01
#define tk2_sel     0x02
#define tk3_sel     0x04
#define tk4_sel     0x08
#define tk5_sel     0x10
#define tk6_sel     0x20
#define tk7_sel     0x40
#define tk8_sel     0x80
#define tk9_sel     0x01
#define tk10_sel    0x02
#define tk11_sel    0x04
#define tk12_sel    0x08
#define tk13_sel    0x10
#define tk14_sel    0x20
#define tk15_sel    0x40
#define tk16_sel    0x80
#define tk17_sel    0x01
#define tk18_sel    0x02
#define tk19_sel    0x04
#define tk20_sel    0x08
#define tk21_sel    0x10
#define tk22_sel    0x20
#define tk23_sel    0x40
#define tk24_sel    0x80


#define tk9_p00_oe    0xfe
#define tk10_p01_oe   0xfd
#define tk11_p02_oe   0xfb
#define tk12_p04_oe   0xef

#define tk1_p10_oe    0xfe
#define tk2_p11_oe    0xfd
#define tk3_p12_oe    0xfb
#define tk4_p13_oe    0xf7
#define tk5_p14_oe    0xef
#define tk6_p15_oe    0xdf
#define tk7_p16_oe    0xbf
#define tk8_p17_oe    0x7f

#define tk20_p20_oe   0xfe
#define tk19_p21_oe   0xfd
#define tk18_p22_oe   0xfb
#define tk17_p23_oe   0xf7
#define tk16_p24_oe   0xef
#define tk15_p25_oe   0xdf
#define tk14_p26_oe   0xbf
#define tk13_p27_oe   0x7f

#define tk24_p34_oe   0xef
#define tk23_p35_oe   0xdf
#define tk22_p36_oe   0xbf
#define tk21_p37_oe   0x7f

#define TK_ini  Sensor_ini(TK_ini_t,REG_TK_C0,REG_TK_C1,REG_TK_C2)

void Sensor_ini(uchar ini_time,uchar reg_tk_c0,uchar reg_tk_c1,uchar reg_tk_c2);  //扫描背景值
void TK_scan();               //按键扫描
void tk_data_store(void);     //扫描数据储存
void TKThreshold_ini(void);   //TouchKey按键阈值设置
ulong TK_key_out(uchar AllNums, uchar Debounce, uchar flow_mode,uchar Max_key_num,uint Max_key_cnt);  //按键计算

#endif
