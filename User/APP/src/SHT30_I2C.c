#include "GCE_General.h"
/*************************************************
 // ��������    : ��������
***************************************************/
GCE_XDATA sht30_CONTROL  data_process={0};//SHT30����
GCE_XDATA UUI08 SHT30_bit={0};//��־λ
GCE_XDATA UI08  SHT30_err_cont=0;//���������ϼ���
GCE_XDATA UI08  SHT30_Command=1;  //�Ƿ�������Ƕ�ת������
GCE_XDATA UI08  SHT30_err_Status=0;
/*************************************************
 // ��������    : IIC_Delay
 // ��������    : IICר����ʱ
 // ��ڲ���    : ��
 // ���ڲ���    : ��
***************************************************/
void IIC_Delay(UI32 K)
{
   while(K--);
}
/*************************************************
 // ��������    : crc8_compute
 // ��������    : ����У��
 // ��ڲ���    : ��
 // ���ڲ���    : ��
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
 	 //crcУ�飬���λ��1��^0x31
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
 // ��������    : sht30_crc8_check
 // ��������    : ����У��
 // ��ڲ���    : ��
 // ���ڲ���    : ��
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
 // ��������    : I2C_Dat_Init
 // ��������    : I2C������ʼ��
 // ��ڲ���    : ��
 // ���ڲ���    : ��
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
 // ��������    : i2c_start
 // ��������    : I2C��ʼ�źţ�
 // ��ڲ���    : ��
 // ���ڲ���    : ��
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
 // ��������    : i2c_stop
 // ��������    : I2Cֹͣ�źţ�
 // ��ڲ���    : ��
 // ���ڲ���    : ��
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
 // ��������    : i2c_Ack
 // ��������    : I2CӦ���źţ�
 // ��ڲ���    : ��
 // ���ڲ���    : ��
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
 // ��������    : i2c_NAck
 // ��������    : I2C��Ӧ���źţ�
 // ��ڲ���    : ��
 // ���ڲ���    : ��
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
 // ��������    : i2c_SendByte
 // ��������    : I2C���͵��ֽ�
 // ��ڲ���    : ��
 // ���ڲ���    : ��
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
 // ��������    : Send_DATA
 // ��������    : I2C���͵��ֽڡ���ѯӦ��
 // ��ڲ���    : ��
 // ���ڲ���    : ��
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
 // ��������    : i2c_ReadByte
 // ��������    : I2C��ȡ
 // ��ڲ���    : ��
 // ���ڲ���    : ��
***************************************************/

UI08 i2c_ReadByte(UI08 ack)
{
	UI08 i;
	UI08 Dat=0;
	SDA_input_init;//��Ϊ����
	for (i = 0; i < 8; i++)
	{
	  SCL_low;
	  delayH;
	  SCL_high;
	  delayL;
	  Dat <<= 1;
	  if(Sda)  //�½��ض�������
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
 // ��������    : SHT30�ĳ�ʼ����
 // ��������    : ��ʼ����
 // ��ڲ���    : ��
 // ���ڲ���    : ��
***************************************************/
void SHT30_Init(void)
{
   	i2c_start();
        //
   	if(Send_DATA(0x88))//д��ַ
   	{return;}//��Ӧ��
	if(Send_DATA(0x21))//�����Ĵ��� ��λ //  0x2130 ָ�����1s����һ����ֵ�������11ҳ
	{return;}
    if(Send_DATA(0x30))//�����Ĵ��� ��λ
    {return;}
	//
    i2c_stop();
	SHT30_err_cont=0;
}
/*************************************************
 // ��������    : SHT30_Sleep_Deal
 // ��������    : SHT30˯��ʱIO�ڴ���
 // ��ڲ���    : ��
 // ���ڲ���    : ��
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
 // ��������    : SHT30�Ķ�ȡ���ݣ�
 // ��������    : ���ݶ�ȡ
 // ��ڲ���    : ��
 // ���ڲ���    : ��
 //�����ǿ�ʼ��ȡ���ݣ����е�����p��Ž��
 //ǰ��������¶�ֵ����������ʪ��ֵ����ǰ�����¶�ֵ���棬
 //p[0]���¶ȵĸ߰�λ��p[1]�ǵͰ�λ��p[2]��CRCУ�飬
***************************************************/
void sht30_read_temp_humi(UI08 *ptr)
{
   UI08 i;
   /*
   i2c_start();
   //
   if(Send_DATA(0x88))
   {return;}//��Ӧ��
   if(Send_DATA(0x21))//  0x2130 ָ�����1s����һ����ֵ�������11ҳ
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
   //ǰ��ζ�ȡ��Ҫ����ack�źţ����һ�ξͲ��÷��ˡ�
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
   //IICͨ����Ӧ��   ����������
   SHT30_err_cont=0;

}
/*************************************************
 // ��������    : ���ݴ�����
 // ��������    : ���ݴ���
 // ��ڲ���    : ��
 // ���ڲ���    : ��
 ��ע:ʾ����ʵ��  Sht30_Deal �ɼ�һ������ 35ms
***************************************************/
UI08 Sht30_Count=0;
void Sht30_Deal(void)
{
  UI08 crc_result=0;
  UI32 data_buf=0;
  UI08 i=0;
  //
  if(!_100ms_for_SHT30)//�״��ϵ�ֱ�Ӷ�һ��
   {return;}
   _100ms_for_SHT30=0;

   Sht30_Count++;
   if(Sht30_Count<3)
   {return;}
   Sht30_Count=0;

   if(SHT30_err_cont<0xff)
   {SHT30_err_cont++;}
   if( (SHT30_err_cont>10)//�����ۼ�ʮ��
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
  //���ݶ�ȡǰ������
  for(i=0;i<6;i++)
  {data_process.sht30_data_buffer[i]=0;}
  //
  sht30_read_temp_humi(data_process.sht30_data_buffer);

  //����
  //T[F]=-49+315*St/65535
  //crcУ��
   crc_result=crc8_compute(data_process.sht30_data_buffer,2);
  //crcУ��

  if(crc_result==data_process.sht30_data_buffer[2])
  {
    data_buf=data_process.sht30_data_buffer[0] ;
    data_buf=(data_buf << 8);
    data_buf=data_buf + data_process.sht30_data_buffer[1];

    data_process.SHT30_temperature = data_buf; // ��F��Χ-49~266  ����ת������ֵ0����-49F
  }

  //ʪ��
  //RH=100*Srh/65535
  //crcУ��
  crc_result=crc8_compute(&data_process.sht30_data_buffer[3],2);
  if(crc_result==data_process.sht30_data_buffer[5])
  {
     data_buf=data_process.sht30_data_buffer[3];
     data_buf= (data_buf<< 8);
     data_buf=data_buf | data_process.sht30_data_buffer[4];
     data_process.SHT30_humidity = (UI08)(data_buf*100/ 65535);
  }

}
