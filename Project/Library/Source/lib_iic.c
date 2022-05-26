/*********************************************************
*文件名:	main.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2019/08/08
**********************************************************/

#include "lib_iic.h"

/*********************************************************
函数名:	IIC_BRR_WR
描  述:	IIC波特率设置
输入值: 8位值
输出值: 无
返回值: 无 
**********************************************************/
void IIC_BRR_WR(uchar brr)
{
    IIC_BRR =  brr;
}

/*********************************************************
函数名:	IIC_S_ADDR_WR
描  述:	IIC从机地址设置
输入值: 8位值
输出值: 无
返回值: 无 
**********************************************************/
void IIC_S_ADDR_WR(uchar addr)
{
    IIC_ADDR = addr;
}

/*********************************************************
函数名: IIC_DATA_WR
描  述:	IIC发送数据设置
输入值: 8位值
输出值: 无
返回值: 无 
**********************************************************/
void IIC_DATA_WR(uchar wr_data)
{
    while((IIC_STA & 0x04)==0X00){};
    IIC_DATA = wr_data;
}

/*********************************************************
函数名: IIC_M_ADDR_WR
描  述:	IIC发送数据设置
输入值: 8位值
输出值: 无
返回值: 无 
**********************************************************/
void IIC_M_ADDR_WR(uchar addr, uchar w_r)
{
    uchar  tmp_data;
    tmp_data = addr<<1;
    tmp_data = tmp_data + w_r;
    while((IIC_STA & 0x04)==0X00){};
    IIC_DATA = tmp_data;
}

/*********************************************************
函数名:	IIC_STA_RD
描  述:	读取接收数据
输入值: 无
输出值: 8位值
返回值: 无 
**********************************************************/
uchar IIC_STA_RD(void)
{
    uchar  tmp_data;	
    tmp_data = IIC_STA;
    return  tmp_data;
}

/*********************************************************
函数名:	IIC_DATA_RD
描  述:	读取接收数据
输入值: 无
输出值: 8位值
返回值: 无 
**********************************************************/
uchar IIC_DATA_RD(void)
{
    uchar  tmp_data;
    tmp_data = IIC_DATA;
    return  tmp_data;
}
/*********************************************************
函数名:	IIC_START_TG
描  述:	发送start信号
输入值: 无
输出值: 8位值
返回值: 无 
**********************************************************/
void IIC_START_TG(void) 
{
	uint TMP_CNT = 0;
    IIC_C1 |= 0X04;
	// TMP_CNT = 0;
	while((IIC_C1&0x04)==0x04)
    {
		TMP_CNT++;
		if(TMP_CNT > 60000) 
        {
			IIC_C0 &= 0XF7;
			IIC_C0 |= 0X08;
			break;
		}
    };
}
/*********************************************************
函数名:	IIC_STOP_TG
描  述:	发送Stop信号
输入值: 无
输出值: 8位值
返回值: 无 
**********************************************************/
void IIC_STOP_TG(void) 
{
	uint TMP_CNT;
    IIC_C1 |= 0X08;
	TMP_CNT = 0;
	while((IIC_C1&0x08)==0x08)
    {
		TMP_CNT++;
		if(TMP_CNT > 150) 
        {
			IIC_C0 &= 0XFE;
			IIC_C0 |= 0X01;
			break;
		}
    };
    IIC_C1 &= 0xF7;
}

#if 0
void IIC_START_TG(void) 
{
    uint TMP_CNT;
    IIC_C1 |= 0X04;
    TMP_CNT = 0;
    while((IIC_C1&0x04)==0x04)
    {
        TMP_CNT = TMP_CNT + 1;
        if(TMP_CNT>60000) 
        {
            IIC_C0 &= 0XFE;
            IIC_C0 |= 0X01;
            break;
        }
    };
	//IIC0_C1 &= 0Xfb;
}

void IIC_STOP_TG(void) 
{
    uint TMP_CNT;
    IIC_C1 |= 0X08;
    TMP_CNT = 0;
    while((IIC_STA&0x20)==0x00)
    {
        TMP_CNT = TMP_CNT + 1;
        if(TMP_CNT>150) 
        {
            IIC_C0 &= 0XFE;
            IIC_C0 |= 0X01;
            break;
        }
    };
    IIC_C1 &= 0XF7;
}
#endif

