#ifndef _GCE_SYSTEM_TIME_H_
#define _GCE_SYSTEM_TIME_H_

//////////////////////////////////////////////////////////////
#include "GCE_General.h" //系统 通用调用文件

//////////////////////////////////////////////////////////////
extern UUI16 flag_1ms_u16; /*1ms 时间标志*/
#define _1ms_for_EXV flag_1ms_u16.bit_.b0
#define _1ms_for_buzz flag_1ms_u16.bit_.b1
#define _1ms_for_remote flag_1ms_u16.bit_.b2
#define _1ms_for_ADC flag_1ms_u16.bit_.b3
#define _1ms_for_IO flag_1ms_u16.bit_.b4
#define _1ms_for_BLE flag_1ms_u16.bit_.b5
#define _1ms_for_TEST flag_1ms_u16.bit_.b6
#define _1ms_for_key flag_1ms_u16.bit_.b7
#define _1ms_for_LED flag_1ms_u16.bit_.b8
#define _1ms_for_FAN flag_1ms_u16.bit_.b9
#define _1ms_for_uart flag_1ms_u16.bit_.b10
#define _1ms_for_wifi flag_1ms_u16.bit_.b11
#define _1ms_for_display flag_1ms_u16.bit_.b12
#define _1ms_for_control flag_1ms_u16.bit_.b13
#define _1ms_for_EXT flag_1ms_u16.bit_.b14
#define _1ms_for_EEPROM flag_1ms_u16.bit_.b15
//////////////////////////////////////////////////////////////
extern UUI16 flag_10ms_u16; /*10ms 时间标志*/
#define _10ms_for_Motor flag_10ms_u16.bit_.b0
//#define _10ms_for_buzz     flag_10ms_u16.bit_.b1
//#define _10ms_for_remote   flag_10ms_u16.bit_.b2
#define _10ms_for_ADC flag_10ms_u16.bit_.b3
#define _10ms_for_IO flag_10ms_u16.bit_.b4
#define _10ms_for_Com flag_10ms_u16.bit_.b5
//#define _10ms_for_TEST     flag_10ms_u16.bit_.b6
//#define _10ms_for_key      flag_10ms_u16.bit_.b7
//#define _10ms_for_LED      flag_10ms_u16.bit_.b8
//#define _10ms_for_FAN      flag_10ms_u16.bit_.b9
//#define _10ms_for_uart     flag_10ms_u16.bit_.b10
//#define _10ms_for_wifi     flag_10ms_u16.bit_.b11
//#define _10ms_for_display  flag_10ms_u16.bit_.b12
//#define _10ms_for_control  flag_10ms_u16.bit_.b13
//#define _10ms_for_EXT  	   flag_10ms_u16.bit_.b14
//#define _10ms_for_EEPROM   flag_10ms_u16.bit_.b15
//////////////////////////////////////////////////////////////
extern UUI16 flag_100ms_u16; /*100ms 时间标志*/
#define _100ms_for_Motor flag_100ms_u16.bit_.b0
#define _100ms_for_Dust_Uart flag_100ms_u16.bit_.b1
#define _100ms_for_SHT30 flag_100ms_u16.bit_.b2
#define _100ms_for_ADC flag_100ms_u16.bit_.b3
//#define _100ms_for_IO       flag_100ms_u16.bit_.b4
//#define _100ms_for_BLE      flag_100ms_u16.bit_.b5
#define _100ms_for_TEST flag_100ms_u16.bit_.b6
//#define _100ms_for_key      flag_100ms_u16.bit_.b7
//#define _100ms_for_LED      flag_100ms_u16.bit_.b8
//#define _100ms_for_FAN      flag_100ms_u16.bit_.b9
//#define _100ms_for_uart     flag_100ms_u16.bit_.b10
//#define _100ms_for_wifi     flag_100ms_u16.bit_.b11
//#define _100ms_for_display  flag_100ms_u16.bit_.b12
//#define _100ms_for_control  flag_100ms_u16.bit_.b13
///#define _100ms_for_EXT  	flag_100ms_u16.bit_.b14
//#define _100ms_for_EEPROM   flag_100ms_u16.bit_.b15
//////////////////////////////////////////////////////////////
extern UUI16 flag_1S_u16; /*1S 时间标志*/
#define _1S_for_Motor flag_1S_u16.bit_.b0
//#define _1S_for_buzz     flag_1S_u16.bit_.b1
//#define _1S_for_remote   flag_1S_u16.bit_.b2
//#define _1S_for_ADC      flag_1S_u16.bit_.b3
//#define _1S_for_IO       flag_1S_u16.bit_.b4
//#define _1S_for_BLE      flag_1S_u16.bit_.b5
#define _1S_for_TEST flag_1S_u16.bit_.b6
//#define _1S_for_key      flag_1S_u16.bit_.b7
#define _1S_for_General_Func flag_1S_u16.bit_.b8
#define _1S_for_Com flag_1S_u16.bit_.b9
#define _1S_TXD_delay flag_1S_u16.bit_.b10
//#define _1S_for_wifi         flag_1S_u16.bit_.b11
//#define _1S_for_display      flag_1S_u16.bit_.b12
//#define _1S_for_uart0        flag_1S_u16.bit_.b13
//#define _1S_for_uart1  	     flag_1S_u16.bit_.b14
//#define _1S_for_EEPROM       flag_1S_u16.bit_.b15
//////////////////////////////////////////////////////////////
extern UI16 _100ms_delay_flag_; // 100ms延时标志
extern UI16 _10ms_delay_flag_;  // 10ms延时时标志
extern UI16 _1ms_delay_flag_;   // 1ms延时标志
//////////////////////////////////////////////////////////////
extern void SystemTimesGenerate(void);

#endif //_GCE_SYSTEM_TIME_H_