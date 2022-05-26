#include "GCE_General.h"
/*************************************************
 // 功能描述    : 变量定义
***************************************************/
GCE_XDATA sht30_CONTROL  data_process={0};//SHT30数据
GCE_XDATA UUI08 SHT30_bit={0};//标志位
GCE_XDATA UI08  SHT30_err_cont=0;//传感器故障计数
GCE_XDATA UI08  SHT30_Command=1;  //是发送命令还是读转换数据
GCE_XDATA UI08  SHT30_err_Status=0;
/*************************************************
 // 函数名称    : IIC_Delay
 // 功能描述    : IIC专用延时
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void IIC_Delay(UI32 K)
{
   while(K--);
}
/*************************************************
 // 函数名称    : crc8_compute
 // 功能描述    : 数据校验
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
int  crc8_compute(UI08 *check_data, UI08 num_of_data)
{
 	UI08 bit_;        // bit mask
        UI08 crc = 0xFF; // calculated checksum
        UI08 byteCtr;    // byte counter

       // calculates 8-Bit checksum with given polynomial
       for(byteCtr = 0; byteCtr < num_of_data; byteCtr++)
       {
          crc ^= (check_data[byteCtr]);
 	 //crc校验，最高位是1就^0x31
         for(bit_ = 8; bit_ > 0; --bit_)
	 {
           if(crc & 0x80)
	   {
             crc = (crc << 1) ^ 0x31;
           }
	   else
	   {
             crc = (crc << 1);
           }
         }
       }
            return crc;
}
/*************************************************
 // 函数名称    : sht30_crc8_check
 // 功能描述    : 数据校验
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
/*
int sht30_crc8_check(UI08 *p,UI08 num_of_data,UI08 CrcData)
{
  UI08 crc1;
  crc1 = crc8_compute(p, num_of_data);// calculates 8-Bit checksum
   if(crc1 != CrcData)
   {return 1;}
   else
   {return 0;}
}*/
/*************************************************
 // 函数名称    : I2C_Dat_Init
 // 功能描述    : I2C变量初始化
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void I2C_Dat_Init(void)
{
   data_process.sht30_data_buffer[0]=0;
   data_process.sht30_data_buffer[1]=0;
   data_process.sht30_data_buffer[2]=0;
   data_process.sht30_data_buffer[3]=0;
   data_process.sht30_data_buffer[4]=0;
   data_process.sht30_data_buffer[5]=0;
   data_process.SHT30_temperature=0;
   data_process.SHT30_humidity=0;
   //
   SHT30_bit.byte=0;
}

/*************************************************
 // 函数名称    : i2c_start
 // 功能描述    : I2C起始信号：
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void i2c_start(void)
{
   SCL_output_init;
   SDA_output_init;
   //
   SDA_high;
   SCL_high;
   delayH;
   SDA_low;
   delayL;
   SCL_low;
   delayL;
}
/*************************************************
 // 函数名称    : i2c_stop
 // 功能描述    : I2C停止信号：
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void i2c_stop(void)
{
   SDA_output_init;
   SCL_low;
   delayL;
   SDA_low;
   delayL;
   SCL_high;
   delayL;
   SDA_high;
   delayL;

}
/*************************************************
 // 函数名称    : i2c_Ack
 // 功能描述    : I2C应答信号：
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void i2c_Ack(void)
{
   SCL_low;
   SDA_output_init;
   SDA_low;
   delayH;
   SCL_high;
   delayH;
   SCL_low;
   SDA_high;
   SDA_input_init;
   delayL;

}
/*************************************************
 // 函数名称    : i2c_NAck
 // 功能描述    : I2C无应答信号：
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void i2c_NAck(void)
{
    SCL_low;
    //delayL;
    SDA_output_init;
    SDA_high;
    delayH;
    SCL_high;
    delayH;
    SCL_low;
    delayL;
}
/*************************************************
 // 函数名称    : i2c_SendByte
 // 功能描述    : I2C发送单字节
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void i2c_SendByte(UI08 _ucByte)
{
    UI08 i=0;
	SCL_low;
	for(i=0;i<8;i++)
	{
	   delayL;
	   if(_ucByte&0x80)
	   {SDA_high;}
	   else
	   {SDA_low;}
	   delayL;
	   SCL_high;
	   delayH;
	   SCL_low;
	   _ucByte<<=1;
	}
}
/*************************************************
 // 函数名称    : Send_DATA
 // 功能描述    : I2C发送单字节、查询应答
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/

UI08 Send_DATA(UI08 data1)
{
    i2c_SendByte(data1);
    SDA_high;
    SDA_input_init;
    delayH;
    SCL_high;
    delayL;
    if(Sda)
    {
        SDA_output_init;
        i2c_stop();
        return 1;
    }
    delayL;
    SCL_low;
    //delayL;
    SDA_output_init;
    SDA_high;
    //delayL;
    return 0;
}

/*************************************************
 // 函数名称    : i2c_ReadByte
 // 功能描述    : I2C读取
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/

UI08 i2c_ReadByte(UI08 ack)
{
	UI08 i;
	UI08 Dat=0;
	SDA_input_init;//作为输入
	for (i = 0; i < 8; i++)
	{
	  SCL_low;
	  delayH;
	  SCL_high;
	  delayL;
	  Dat <<= 1;
	  if(Sda)  //下降沿读出数据
	  {Dat++;}
	  delayL;
	}
    //
    if(!ack)
    {i2c_NAck();}
    else
    {i2c_Ack();}
    //
	return Dat;
}

/*************************************************
 // 函数名称    : SHT30的初始化：
 // 功能描述    : 初始化：
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void SHT30_Init(void)
{
   	i2c_start();
        //
   	if(Send_DATA(0x88))//写地址
   	{return;}//无应答
	if(Send_DATA(0x21))//操作寄存器 高位 //  0x2130 指令传感器1s更新一次数值，规格书11页
	{return;}
    if(Send_DATA(0x30))//操作寄存器 低位
    {return;}
	//
    i2c_stop();
	SHT30_err_cont=0;
}
/*************************************************
 // 函数名称    : SHT30_Sleep_Deal
 // 功能描述    : SHT30睡眠时IO口处理
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/

void SHT30_Sleep_Deal(void)
{
   SCL_output_init;
   SDA_output_init;
   //
   SDA_high;
   SCL_high;
}

/*************************************************
 // 函数名称    : SHT30的读取数据：
 // 功能描述    : 数据读取
 // 入口参数    : 无
 // 出口参数    : 无
 //下面是开始读取数据，其中的数组p存放结果
 //前三个存放温度值，后三个是湿度值，在前三个温度值里面，
 //p[0]是温度的高八位，p[1]是低八位，p[2]是CRC校验，
***************************************************/
void sht30_read_temp_humi(UI08 *ptr)
{
   UI08 i;
   /*
   i2c_start();
   //
   if(Send_DATA(0x88))
   {return;}//无应答
   if(Send_DATA(0x21))//  0x2130 指令传感器1s更新一次数值，规格书11页
   {return;}
   if(Send_DATA(0x30))
   {return;}
   delayH;
   //READ
   */
   i2c_start();
   //
   if(Send_DATA(0x89))
   {return;}
   //前五次读取都要发送ack信号，最后一次就不用发了。
   for(i=0;i<sizeof(data_process.sht30_data_buffer)-1;i++)
   {
	ptr[i]=i2c_ReadByte(Ack);
   }
   /*ptr[0] = i2c_ReadByte(Ack);
   ptr[1] = i2c_ReadByte(Ack);
   ptr[2] = i2c_ReadByte(Ack);
   ptr[3] = i2c_ReadByte(Ack);
   ptr[4] = i2c_ReadByte(Ack);*/
   ptr[5] = i2c_ReadByte(Noack);
   //
   i2c_stop();
   //IIC通信有应答   清零错误次数
   SHT30_err_cont=0;

}
/*************************************************
 // 函数名称    : 数据处理函数
 // 功能描述    : 数据处理
 // 入口参数    : 无
 // 出口参数    : 无
 备注:示波器实测  Sht30_Deal 采集一次运行 35ms
***************************************************/
UI08 Sht30_Count=0;
void Sht30_Deal(void)
{
  UI08 crc_result=0;
  UI32 data_buf=0;
  UI08 i=0;
  //
  if(!_100ms_for_SHT30)//首次上电直接读一次
   {return;}
   _100ms_for_SHT30=0;

   Sht30_Count++;
   if(Sht30_Count<3)
   {return;}
   Sht30_Count=0;

   if(SHT30_err_cont<0xff)
   {SHT30_err_cont++;}
   if( (SHT30_err_cont>10)//出错累计十次
     ||((_Self_Test)&&(SHT30_err_cont>3)))
   {
          SHT30_err_Status=1;
   }
   else
   {
         SHT30_err_Status=0;
   }

   if(SHT30_Command)
   {
      SHT30_Init();
      SHT30_Command=0;
      return;
   }
   else
   {
      SHT30_Command=1;
   }
  //数据读取前先清零
  for(i=0;i<6;i++)
  {data_process.sht30_data_buffer[i]=0;}
  //
  sht30_read_temp_humi(data_process.sht30_data_buffer);

  //室温
  //T[F]=-49+315*St/65535
  //crc校验
   crc_result=crc8_compute(data_process.sht30_data_buffer,2);
  //crc校验

  if(crc_result==data_process.sht30_data_buffer[2])
  {
    data_buf=data_process.sht30_data_buffer[0] ;
    data_buf=(data_buf << 8);
    data_buf=data_buf + data_process.sht30_data_buffer[1];

    data_process.SHT30_temperature = data_buf; // 度F范围-49~266  其中转换出的值0代表-49F
  }

  //湿度
  //RH=100*Srh/65535
  //crc校验
  crc_result=crc8_compute(&data_process.sht30_data_buffer[3],2);
  if(crc_result==data_process.sht30_data_buffer[5])
  {
     data_buf=data_process.sht30_data_buffer[3];
     data_buf= (data_buf<< 8);
     data_buf=data_buf | data_process.sht30_data_buffer[4];
     data_process.SHT30_humidity = (UI08)(data_buf*100/ 65535);
  }

}
