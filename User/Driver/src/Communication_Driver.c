#include "GCE_General.h"

GCE_XDATA   UI08 txd_buf[txd_length]={0};
GCE_XDATA   UI08 rxd_buf[rece_data_lenth]={0};
GCE_XDATA   UUI08  communication_bit1={0};
GCE_XDATA   UI08 pulse_cnt=0;
GCE_XDATA   UI08 txd_byte=0;
GCE_XDATA   UI08 txd_bit=0;
GCE_XDATA   UI08 Rxd_bits=0;
GCE_XDATA   UI08 Rxd_bytes=0;
GCE_XDATA   UI08 Communication_Width_Count=0;
GCE_XDATA   UI08 TXD_L_timer=0;//低电平时间
/*************************************************
 // 函数名称    : void communication_Txd_IRQ(void)
 // 功能描述    : 底层通信发送函数
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void Communication_Txd_IRQ(void)
{
      //if(!_txd_en)
      //{return;}
      //
      pulse_cnt++;

      if(_txd_data) //发数据
      {
	 TXD_L_timer=5;
        if(txd_buf[txd_byte]&txd_bit)
        {
          if(pulse_cnt>=COM_ONE)
          {
            pulse_cnt=0;
            txd_bit<<=1;
          }
        }
        else
        {
           if(pulse_cnt>=COM_ZERO)
           {
             pulse_cnt=0;
             txd_bit<<=1;
           }
        }
        if(0x00==txd_bit)
 	{
 	   txd_bit=0x01;
           if(++txd_byte>=txd_length)
 	   {
                 pulse_cnt=0;
 	 	 txd_byte=0;
 	 	 _txd_end=1;
                 _txd_data=0;
                 _txd_start=0;
 	   }
 	}
      }
      else if(_txd_start)//发头码
      {
	   Comm_output_init;
	   TXD_L_timer=5+1;
           if(pulse_cnt>=(COM_HEAD+1))
  	   {
              pulse_cnt=0;
              txd_bit=0x01;
              _txd_start=0;
              _txd_data=1;
  	      _txd_end=0;
           }
      }
      else if(_txd_end)
      {
	  TXD_L_timer=5;
          if(pulse_cnt>=COM_ZERO)
          {
                 _txd_start=0;
                 _txd_data=0;
  		 _txd_end=0;
                 _txd_en=0;
		 Comm_input_init;
          }
      }
      else
      {
             _txd_start=1;
             _txd_data=0;
  	     _txd_end=0;
             _txd_en=0;
	     Comm_input_init;
      }
      //
      if(pulse_cnt<TXD_L_timer)
      {Txd_L;}
      else
      {Txd_H;}
      //
}
/*************************************************
 // 函数名称    : void communication_Rxd_IRQ(void)
 // 功能描述    : 底层通信接收函数
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void Communication_Rxd_IRQ(void)
{
         //if((communication_width_count>=(COM_HEAD-6))&&(communication_width_count<=(COM_HEAD+6)))//30
         if((Communication_Width_Count>=(COM_HEAD-3))&&(Communication_Width_Count<=(COM_HEAD+3)))//30
         {
             _Rxd_start=1;
             Rxd_bits=0x01;
             Rxd_bytes=0;
	         rxd_buf[Rxd_bytes]=0;
             return;
         }

         if(!_Rxd_start)
         {
            return;

         }

         if(Rxd_bytes>=rece_data_lenth)
         {
             _Rxd_start=0;
            return;
	}

         //if((communication_width_count>=(COM_ONE-4))&&(communication_width_count<=(COM_ONE+4)))//18
         if((Communication_Width_Count>=(COM_ONE-2))&&(Communication_Width_Count<=(COM_ONE+2)))//18
         {
             rxd_buf[Rxd_bytes]|=Rxd_bits;
         }
         //else if((communication_width_count>=(COM_ZERO-4))&&(communication_width_count<=(COM_ZERO+4)))// 8
         else if((Communication_Width_Count>=(COM_ZERO-2))&&(Communication_Width_Count<=(COM_ZERO+2)))// 8
         {
            rxd_buf[Rxd_bytes]&=~Rxd_bits;
         }
         else
         {
            _Rxd_start=0;
            return;
         }

         Rxd_bits<<=1;
         if(0==Rxd_bits)
         {
             Rxd_bits=0x01;
             Rxd_bytes++;
             if(Rxd_bytes>=rece_data_lenth)
             {
                 _Rxd_OK=1;
                 _Rxd_start=0;
             }
			 else
			 {
                 rxd_buf[Rxd_bytes]=0;
			 }
         }


}

/*************************************************
 // 函数名称    : void communication_Rxd(void)
 // 功能描述    : 底层通信接收函数
 // 入口参数    : 无
 // 出口参数    : 无
***************************************************/
void Communication_Rxd_IRQ_deal(void)
{
         Communication_Width_Count++;
        if(!Rxd_IO)
        {
            if(_Rxd_IO_)
            {
                _Rxd_IO_=0;
                Communication_Rxd_IRQ();
                Communication_Width_Count=0;
            }
        }
        else
        {_Rxd_IO_=1;}
}
