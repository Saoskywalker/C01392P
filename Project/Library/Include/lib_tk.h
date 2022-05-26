/*********************************************************
*�ļ���:	lib_tk.h
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ��:	2017/05/20
*��  ��:	
*��  ע:    
**********************************************************/
#ifndef   __LIBTK_H__
#define   __LIBTK_H__
#include "user.h"

//���ùܽ�����
#define AllSensorNums 8   //���ð�����

//���ö�Ӧ�������
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
/* TK�߹���ģʽ����������*/  //��ȡ��ָ���µı仯����ȡ�ñ仯��30~70%��Ϊ����������
//���÷�ΧΪ0~256��ֵԽС������Խ�ߣ�һ�㲻ҪС��8
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

#define FLOW_MODE      0        //����ֵ�����ٶ�bit<4:0>, 0~31����ֵԽ�󣬸������Խ�죬bit7������ó�1�����ڰ���������Ҳ����и���
#define MAX_KEY_MUL    1        //�������TK��ͬʱ�����£������¸��ٱ���ֵ��Ŀǰ����Ϊ2��
#define MKEY_LIMIT_CNT 5000     //0~65536��������¶��ٴκ����¸��ٱ���ֵ,Ŀǰ��5000�Σ�ÿ��ѭ��1������200us���㣩

/* TK�Ĵ���ֵ�趨���Լ�ģʽ����*/
#define REG_TK_C0   0xc0    //�μ������TK_C0,��������
#define REG_TK_C1   0x43    //�μ������TK_C1,�������ã�Ŀǰʹ���ڲ��˲�5���˲����Ƚϵ�ѹֵΪ1.5V
#define REG_TK_C2   0x04    //�μ������TK_C2,��ŵ�ʱ�����ã�ĿǰΪϵͳʱ��4��Ƶ���������Ϊ0x08��Ϊϵͳʱ��6��Ƶ���������Ϊ0x0c��Ϊϵͳʱ��8��Ƶ
#define TK_ini_t    0x07    //��ʼ��ɨ������������6��
//*******************************************************************************
//�������������޸�
//*******************************************************************************
#define HP_MOOD     0x00    //�߹���ģʽ
#define LP_MOOD     0x01    //�͹���ģʽ
/* TouchKey�Ĵ�������*/
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

void Sensor_ini(uchar ini_time,uchar reg_tk_c0,uchar reg_tk_c1,uchar reg_tk_c2);  //ɨ�豳��ֵ
void TK_scan();               //����ɨ��
void tk_data_store(void);     //ɨ�����ݴ���
void TKThreshold_ini(void);   //TouchKey������ֵ����
ulong TK_key_out(uchar AllNums, uchar Debounce, uchar flow_mode,uchar Max_key_num,uint Max_key_cnt);  //��������

#endif
