/*********************************************************
*文件名:	lib_tk.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2017/08/08
 **********************************************************/
#include "lib_tk.h"

extern xdata uchar ScanTimes;	
extern xdata uchar hm_tg;                 //人为启动标志位

extern idata uchar  SensorCounted;
xdata uchar flag;

idata uint  SFRDATA[AllSensorNums];  
xdata uint  BaseLine[AllSensorNums];

xdata uint  IIR_Filter[AllSensorNums];
idata uchar TKThreshold[AllSensorNums];
idata uint  RawData[AllSensorNums];
xdata uchar GetFinger[AllSensorNums];	    
xdata uchar MovingHold[AllSensorNums];	        
xdata uchar ConfirmMoveingFlag[AllSensorNums];	
xdata uint  BaseLineFollowSpeed[AllSensorNums]; 
xdata uchar SensorDiff[AllSensorNums];
xdata uchar hp_fast_ch[AllSensorNums];

/*********************************************************
函数名:	void TKThreshold_ini(void) 
描  述:	TouchKey按键阈值设置
输入值: 无
输出值: 无
返回值: 无 
**********************************************************/
void TKThreshold_ini(){
	idata uchar i;
  for (i = 0; i < AllSensorNums; i ++){
    switch (i){
#ifdef P00_TK_NUM			
      case P00_TK_NUM:
        TKThreshold[i] = TK_P00_ini;     
        break;
#endif
#ifdef P01_TK_NUM				
      case P01_TK_NUM:
        TKThreshold[i] = TK_P01_ini;  		
        break;
#endif
#ifdef P02_TK_NUM					
      case P02_TK_NUM:
        TKThreshold[i] = TK_P02_ini;  		
        break;
#endif
#ifdef P04_TK_NUM					
      case P04_TK_NUM:
        TKThreshold[i] = TK_P04_ini; 					
        break;
#endif
#ifdef P10_TK_NUM					
      case P10_TK_NUM:
        TKThreshold[i] = TK_P10_ini;  			
        break;
#endif
#ifdef P11_TK_NUM					
      case P11_TK_NUM:
        TKThreshold[i] = TK_P11_ini;			
        break;
#endif
#ifdef P12_TK_NUM					
      case P12_TK_NUM:  
        TKThreshold[i] = TK_P12_ini;   
			  break;
#endif
#ifdef P13_TK_NUM					
      case P13_TK_NUM:
        TKThreshold[i] = TK_P13_ini;   			
        break;
#endif
#ifdef P14_TK_NUM					
      case P14_TK_NUM:
        TKThreshold[i] = TK_P14_ini;   			
        break;
#endif
#ifdef P15_TK_NUM					
      case P15_TK_NUM:
        TKThreshold[i] = TK_P15_ini;  			
        break;
#endif
#ifdef P16_TK_NUM					
      case P16_TK_NUM:  
        TKThreshold[i] = TK_P16_ini;   			
        break;
#endif
#ifdef P17_TK_NUM					
      case P17_TK_NUM:  
        TKThreshold[i] = TK_P17_ini;  			
        break;
#endif
#ifdef P20_TK_NUM					
      case P20_TK_NUM:
        TKThreshold[i] = TK_P20_ini; 			
        break;
#endif
#ifdef P21_TK_NUM					
      case P21_TK_NUM:
        TKThreshold[i] = TK_P21_ini; 			
        break;
#endif
#ifdef P22_TK_NUM					
      case P22_TK_NUM:  
        TKThreshold[i] = TK_P22_ini;  			
        break;
#endif
#ifdef P23_TK_NUM					
      case P23_TK_NUM:
        TKThreshold[i] = TK_P23_ini;			
        break;
#endif
#ifdef P24_TK_NUM					
      case P24_TK_NUM:
        TKThreshold[i] = TK_P24_ini;    			
        break;
#endif
#ifdef P25_TK_NUM					
      case P25_TK_NUM:
        TKThreshold[i] = TK_P25_ini;   			
        break;
#endif
#ifdef P26_TK_NUM					
      case P26_TK_NUM:  
        TKThreshold[i] = TK_P26_ini;   			
        break;
#endif
#ifdef P27_TK_NUM					
      case P27_TK_NUM:  
        TKThreshold[i] = TK_P27_ini; 			
        break;			
#endif
#ifdef P34_TK_NUM					
      case P34_TK_NUM:
        TKThreshold[i] = TK_P34_ini;  	
        break;
#endif
#ifdef P35_TK_NUM					
      case P35_TK_NUM:
        TKThreshold[i] = TK_P35_ini; 			
        break;
#endif
#ifdef P36_TK_NUM					
      case P36_TK_NUM:  
        TKThreshold[i] = TK_P36_ini;   			
        break;
#endif
#ifdef P37_TK_NUM					
      case P37_TK_NUM:  
        TKThreshold[i] = TK_P37_ini;  			
        break;					
#endif			
      default: 
         break;
    }
	}
}

/*********************************************************
函数名:	void Sensor_ini(void) 
描  述:	TouchKey背景值扫描功能
输入值: 无
输出值: 无
返回值: 无 
**********************************************************/
void Sensor_ini(uchar scan_time, uchar reg_tk_c0,uchar reg_tk_c1,uchar reg_tk_c2)
{
  idata uchar int_cnt;
	xdata uint ov_cnt;
  P0_OE |= 0x20;  
  P0_5 = 0;
  VREF_C = REG_VREF_C;  
  TK_C0 = reg_tk_c0;
  TK_C1 = reg_tk_c1;
  TK_C2 = reg_tk_c2;
  P0_OE &= 0xdf; 
  SensorCounted = 0;

  if(scan_time != 0 ) {
    ScanTimes = 0;
  }
  TKThreshold_ini();
  hm_tg =0;
  int_cnt =0;
  while (int_cnt < scan_time){	
   WDT_OP=0x5a;
   SensorCounted = 0;
   while(SensorCounted<AllSensorNums){
			TK_scan();
			ov_cnt  =0;
			while(TK_IF==0) {
				ov_cnt = ov_cnt + 1;
				CLR_WDT;
				if(ov_cnt>0xfff0) {	
					TK_C0 &= 0x7f;
					TK_C0 |= 0x80;
					break;
				}
			};
			tk_data_store();
	 }
	 TK_key_out(AllSensorNums,5,FLOW_MODE,MAX_KEY_MUL,MKEY_LIMIT_CNT);
	 TK_key_out(AllSensorNums,5,FLOW_MODE,MAX_KEY_MUL,MKEY_LIMIT_CNT);	 
   int_cnt = int_cnt + 1;
  }
  SensorCounted = 0;
}


/*********************************************************
void TK_scan()
描  述:	TouchKey按键扫描
输入值: 无
输出值: 无
返回值: 无 
**********************************************************/	   
void TK_scan(){
	TK_IF = 0;
  if ((SensorCounted < AllSensorNums) && (TK_C0&0x01)==0x00) {
		P0_OE |= 0x20;
		P0_5 = 0;
    switch (SensorCounted){
#ifdef P00_TK_NUM
      case P00_TK_NUM:
        P0_OE &= tk9_p00_oe;  //p00
        TK_CHEM = tk9_sel;
        TK_CHEL = 0X00;
        TK_CHEH = 0X00;			
        break;
#endif
			
#ifdef P01_TK_NUM
      case P01_TK_NUM:
        P0_OE &= tk10_p01_oe;  //p01
        TK_CHEM = tk10_sel;			
        TK_CHEH = 0X00;
        TK_CHEL = 0X00;
        break;
#endif
#ifdef P02_TK_NUM
      case P02_TK_NUM:
        P0_OE &= tk11_p02_oe;  //p02
        TK_CHEM = tk11_sel;
        TK_CHEL = 0X00;
			  TK_CHEH = 0X00;
        break;
#endif
#ifdef P04_TK_NUM
      case P04_TK_NUM:
        P0_OE &= tk12_p04_oe;  //p04
        TK_CHEM = tk12_sel;
        TK_CHEL = 0X00;
			  TK_CHEH = 0X00;
        break;
#endif
#ifdef P10_TK_NUM
      case P10_TK_NUM:
        P1_OE &= tk1_p10_oe;  //p10
        TK_CHEL = tk1_sel;
        TK_CHEH = 0X00;
			  TK_CHEM = 0X00;
        break;
#endif
			
#ifdef P11_TK_NUM
      case P11_TK_NUM:  
        P1_OE &= tk2_p11_oe;  //p11
        TK_CHEL = tk2_sel;
        TK_CHEH = 0X00;
			  TK_CHEM = 0X00;			
        break;
#endif
#ifdef P12_TK_NUM
      case P12_TK_NUM:
        P1_OE &= tk3_p12_oe;  //p12
        TK_CHEL = tk3_sel;
        TK_CHEH = 0X00;
			  TK_CHEM = 0X00;			
        break;
#endif
#ifdef P13_TK_NUM
      case P13_TK_NUM:
        P1_OE &= tk4_p13_oe;  //p13
        TK_CHEL = tk4_sel;
        TK_CHEH = 0X00;
			  TK_CHEM = 0X00;			
        break;
#endif
#ifdef P14_TK_NUM
      case P14_TK_NUM:  
        P1_OE &= tk5_p14_oe;  //p14
        TK_CHEL = tk5_sel;
        TK_CHEH = 0X00;
			  TK_CHEM = 0X00;			
        break;
#endif
#ifdef P15_TK_NUM
      case P15_TK_NUM:
        P1_OE &= tk6_p15_oe; //p15
        TK_CHEL = tk6_sel;
        TK_CHEH = 0X00;
			  TK_CHEM = 0X00;			
        break;
#endif
#ifdef P16_TK_NUM
      case P16_TK_NUM:
        P1_OE &= tk7_p16_oe; //p16
        TK_CHEL = tk7_sel;
        TK_CHEH = 0X00;
			  TK_CHEM = 0X00;
        break;
#endif
#ifdef P17_TK_NUM
      case P17_TK_NUM:
        P1_OE &= tk8_p17_oe; //p17
        TK_CHEL = tk8_sel;
        TK_CHEM = 0X00;
			  TK_CHEH = 0X00;
        break;
#endif
#ifdef P20_TK_NUM			
      case P20_TK_NUM:  
        P2_OE &= tk20_p20_oe; //p20
        TK_CHEH = tk20_sel;
        TK_CHEL = 0X00;
			  TK_CHEM = 0X00;
        break;
#endif
#ifdef P21_TK_NUM					
      case P21_TK_NUM:  
        P2_OE &= tk19_p21_oe; //p21
        TK_CHEH = tk19_sel;
        TK_CHEM = 0X00;			
        TK_CHEL = 0X00;
        break;
#endif
#ifdef P22_TK_NUM	
      case P22_TK_NUM:  
        P2_OE &= tk18_p22_oe; //p22
        TK_CHEH = tk18_sel;
        TK_CHEL = 0X00;
        TK_CHEM = 0X00;					
        break;
#endif
#ifdef P23_TK_NUM				
      case P23_TK_NUM:  
        P2_OE &= tk17_p23_oe; //p23
        TK_CHEH = tk17_sel;
        TK_CHEL = 0X00;
        TK_CHEM = 0X00;					
        break;	
#endif
#ifdef P24_TK_NUM				
      case P24_TK_NUM:  
        P2_OE &= tk16_p24_oe; //p24
        TK_CHEM = tk16_sel;
        TK_CHEH = 0X00;			
        TK_CHEL = 0X00;
        break;
#endif
#ifdef P25_TK_NUM				
      case P25_TK_NUM:  
        P2_OE &= tk15_p25_oe; //p25
        TK_CHEM = tk15_sel;
        TK_CHEH = 0X00;			
        TK_CHEL = 0X00;
        break;
#endif
#ifdef P26_TK_NUM				
      case P26_TK_NUM:  
        P2_OE &= tk14_p26_oe; //p26
        TK_CHEM = tk14_sel;
        TK_CHEH = 0X00;			
        TK_CHEL = 0X00;
        break;
#endif
#ifdef P27_TK_NUM				
      case P27_TK_NUM:  
        P2_OE &= tk13_p27_oe; //p27
        TK_CHEM = tk13_sel;
        TK_CHEH = 0X00;			
        TK_CHEL = 0X00;
        break;	
#endif
#ifdef P34_TK_NUM	
      case P34_TK_NUM:  
        P3_OE &= tk24_p34_oe; //p34
        TK_CHEH = tk24_sel;
        TK_CHEM = 0X00;			
        TK_CHEL = 0X00;
        break;			
#endif
#ifdef P35_TK_NUM				
      case P35_TK_NUM:  
        P3_OE &= tk23_p35_oe; //p35
        TK_CHEH = tk23_sel;
        TK_CHEM = 0X00;			
        TK_CHEL = 0X00;
        break;
#endif
#ifdef P36_TK_NUM				
      case P36_TK_NUM:  
        P3_OE &= tk22_p36_oe; //p36
        TK_CHEH = tk22_sel;
        TK_CHEM = 0X00;			
        TK_CHEL = 0X00;
        break;	
#endif
#ifdef P37_TK_NUM				
      case P37_TK_NUM:  
        P3_OE &= tk21_p37_oe; //p37
        TK_CHEH = tk21_sel;
        TK_CHEM = 0X00;			
        TK_CHEL = 0X00;
        break;							
#endif						
      default: 
        TK_CHEH = 0X00;
        TK_CHEL = 0X00;
        TK_CHEM = 0X00;			
        break;
    }
	  WDT_OP=0x5a;   //clr wdt
	  TK_IF = 0;
		if((TK_C0&0x01)==0x00){
			if(TK_IF==0x00) {
				hm_tg = 0;
				P0_OE &= 0xDF; 
				TK_C0 |= 0x01;
			}
		}
	}
}
/*********************************************************
void tk_data_store()
描  述:	TouchKey按键扫描
输入值: 无
输出值: 无
返回值: 无 
**********************************************************/	   		
void tk_data_store(){
	if(SensorCounted==0){
    flag = 0;
	}
	if(TK_IF&&(hm_tg==0)){
		P0_OE |= 0x20;
		P0_5 = 0;
		if((TK_C0 & 0x0C) == 0) {
			SFRDATA[SensorCounted] = TK_CNTH;
			SFRDATA[SensorCounted] = SFRDATA[SensorCounted]<<8;
			SFRDATA[SensorCounted] = SFRDATA[SensorCounted] + TK_CNTL;
			switch (SensorCounted){
#ifdef P00_TK_NUM
				case P00_TK_NUM:
					P0_OE |= (~tk9_p00_oe);  //p00
					break;
#endif
#ifdef P01_TK_NUM
				case P01_TK_NUM:
					P0_OE |= (~tk10_p01_oe);  //p01
					break;
#endif
#ifdef P02_TK_NUM
				case P02_TK_NUM:
					P0_OE |= (~tk11_p02_oe);  //p02
					break;
#endif
#ifdef P04_TK_NUM
				case P04_TK_NUM:
					P0_OE |= (~tk12_p04_oe);  //p04
					break;
#endif				
#ifdef P10_TK_NUM
				case P10_TK_NUM:
					P1_OE |= (~tk1_p10_oe);  //p10
					break;
#endif
#ifdef P11_TK_NUM
				case P11_TK_NUM:
					P1_OE |= (~tk2_p11_oe);  //p11
					break;
#endif
#ifdef P12_TK_NUM
				case P12_TK_NUM:  
					P1_OE |= (~tk3_p12_oe);  //p12
					break;
#endif
#ifdef P13_TK_NUM
				case P13_TK_NUM:
					P1_OE |= (~tk4_p13_oe); //p13
					break;
#endif
#ifdef P14_TK_NUM
				case P14_TK_NUM:
					P1_OE |= (~tk5_p14_oe); //p14
					break;
#endif
#ifdef P15_TK_NUM
				case P15_TK_NUM:
					P1_OE |= (~tk6_p15_oe); //p15
					break;
#endif
#ifdef P16_TK_NUM
				case P16_TK_NUM:  
					P1_OE |= (~tk7_p16_oe); //p16
					break;
#endif
#ifdef P17_TK_NUM
				case P17_TK_NUM:  
					P1_OE |= (~tk8_p17_oe); //p17
					break;
#endif
							
#ifdef P20_TK_NUM
				case P20_TK_NUM:  
					P2_OE |= (~tk20_p20_oe); //p20
					break;
#endif

				
#ifdef P21_TK_NUM
				case P21_TK_NUM:  
					P2_OE |= (~tk19_p21_oe); //p21
					break;
#endif
#ifdef P22_TK_NUM
				case P22_TK_NUM:  
					P2_OE |= (~tk18_p22_oe); //p22
					break;
#endif				

#ifdef P23_TK_NUM
				case P23_TK_NUM:  
					P2_OE |= (~tk17_p23_oe); //p23
					break;
#endif		
#ifdef P24_TK_NUM
				case P24_TK_NUM:  
					P2_OE |= (~tk16_p24_oe); //p24
					break;
#endif					
#ifdef P25_TK_NUM
				case P25_TK_NUM:  
					P2_OE |= (~tk15_p25_oe); //p25
					break;
#endif		
#ifdef P26_TK_NUM
				case P26_TK_NUM:  
					P2_OE |= (~tk14_p26_oe); //p26
					break;
#endif
#ifdef P27_TK_NUM
				case P27_TK_NUM:  
					P2_OE |= (~tk13_p27_oe); //p27
					break;
#endif	
#ifdef P34_TK_NUM
				case P34_TK_NUM:  
					P3_OE |= (~tk24_p34_oe); //p34
					break;
#endif					
#ifdef P35_TK_NUM
				case P35_TK_NUM:  
					P3_OE |= (~tk23_p35_oe); //p35
					break;
#endif		
#ifdef P36_TK_NUM
				case P36_TK_NUM:  
					P3_OE |= (~tk22_p36_oe); //p36
					break;
#endif		
#ifdef P37_TK_NUM
				case P37_TK_NUM:  
					P3_OE |= (~tk21_p37_oe); //p37
					break;
#endif					
				default:
					TK_CHEH = 0X00;
					TK_CHEM = 0X00;
					TK_CHEL = 0X00;				
					break;
			}
			if(flag<0){
				flag = flag + 1;
			}
			else{
				SensorCounted ++;
			}
		}
		else
		{
			TK_C0 &= 0x7f;
			TK_C0 |= 0x80;
		}
    TK_IF = 0;
	  TK_CHEH = 0X00;
  	TK_CHEL = 0X00;
  	TK_CHEM = 0X00;		
	}
	if((TK_C0&0X04)==0X04) {  //如果出错无法产生中断，增加出错保护机制
		TK_C0 &= 0x7f;
		TK_C0 |= 0x80;
	}
}
