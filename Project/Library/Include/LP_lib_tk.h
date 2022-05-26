/*********************************************************
*�ļ���:	lib_tk_lp.h
*��  ��:	sinomicon
*��  ��:	V0.00
*��  ��:	2017/05/20
*��  ��:	
*��  ע:    
**********************************************************/
#include "user.h"

//lp ģʽ����ͨ������
#define LP_AllSensorNums 4   //���õ͹���ɨ�������
/*���õ͹����°����������*/
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
/* TK�͹���ģʽ����������*/
#define LP_TK0_ini  LS
#define LP_TK1_ini  LS
#define LP_TK2_ini  LS
#define LP_TK3_ini  LS
#define LP_TK4_ini  LS
#define LP_TK5_ini  LS

/* TK�Ĵ���ֵ�趨���Լ�ģʽ����*/
#define LP_REG_TK_C0   0xc0    //�μ������TK_C1,��������
#define LP_REG_TK_C1   0x43    //�μ������TK_C1,�������ã�Ŀǰʹ���ڲ��˲�5���˲����Ƚϵ�ѹֵΪ1.6V
#define LP_REG_TK_C2   0x00    //�μ������TK_C2,��ŵ�ʱ�����ã�ĿǰΪϵͳʱ��4��Ƶ���������Ϊ0x08��Ϊϵͳʱ��6��Ƶ���������Ϊ0x0c��Ϊϵͳʱ��8��Ƶ

uchar LP_tk_key(uchar LP_AllNums);
void LP_tk_data_store(void);
void LP_TK_scan();
void LP_TKInit();