/*********************************************************
*文件名:	main.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2019/08/08
**********************************************************/

#include "lib_iap.h"

/*********************************************************
函数名:	IAP_UNLOCK
描  述:	flash 操作解锁
输入值: 
输出值: 无
返回值: 8位值，输出1表示成功，输出0表示失败 
**********************************************************/
uchar IAP_UNLOCK()
{
    uchar  pass;
    pass = 0;
    IAP_PR = 0xac;
    if(IAP_PR == 0X1) 
    {
        pass = 1;
    }
    else
    {
        pass = 0;
    }
    return  pass;
}

/*********************************************************
函数名:	IAP_LOCK
描  述:	flash 操作锁定
输入值: 
输出值: 无
返回值: 8位值，输出1表示成功，输出0表示失败 
**********************************************************/
uchar IAP_LOCK()
{
    uchar  pass;
    pass = 0;
    IAP_PR = 0x53;
    if(IAP_PR == 0X0)
    {
        pass = 1;
    }
    else 
    {
        pass = 0;
    }
    return  pass;
}

/*********************************************************
函数名:	IAP_ERASR
描  述:	flash 擦除
输入值: 页擦除地址
输出值: 无
返回值: 8位值，输出1表示擦除成功，输出0表示擦除失败 
**********************************************************/
uchar IAP_ERASE(uint addr)
{
    uchar  pass;
    uchar  rd_data;
    uint   IAP_tmp_addr;
    uint   i;
    uint   max_addr;
    pass = 1;
    if((addr&0x8000)==0x8000) 
    {
        IAP_AS = 0X5A;  //data flash
        max_addr = 0x100;
    }
    else 
    {
        IAP_AS = 0XA5;
        max_addr = 0x200;
    }

    IAP_AH = addr>>8;
    IAP_AL = 0X00;
    IAP_C0 = 0X01;
    IAP_C1 = 0X12;
    IAP_C0 = 0X00;
    for(i=0; i < max_addr; i = i+1) 
    {
        IAP_tmp_addr = addr + i;
        rd_data = *((uchar code *)(addr));
        if(rd_data != 0xff) 
        {
            pass = 0;
        }
    }
    return  pass;
}

/*********************************************************
函数名:	IAP_PROG
描  述:	flash 编程
输入值: 编程地址16位，编程数据8位
输出值: 无
返回值: 8位值，输出1表示成功，输出0表示失败 
**********************************************************/
uchar IAP_PROG(uint addr, uchar din)
{
    uchar  pass;
    uchar  PROG_tmp_data;
    pass = 0;
    if((addr&0x8000)==0x8000) 
    {
        IAP_AS = 0X5A;  //data flash
    }
    else 
    {
       IAP_AS = 0XA5;
    }

    IAP_AL = addr;
    IAP_AH = addr>>8;
    IAP_D = din;
    IAP_C0 = 0X01;
    IAP_C1 = 0X34;
    IAP_C0 = 0X00;
    PROG_tmp_data = *((uchar code *)(addr));
    if(PROG_tmp_data == din) 
    {
        pass = 1;
    }
    else
    {
        pass = 0;
    }
    IAP_D = 0xff;
    IAP_AH = 0xff;
    return  pass;
}


/*********************************************************
函数名:	IAP_DATA_RD
描  述:	flash 读出
输入值: 地址16位
输出值: flash 8位数据 
返回值: 
**********************************************************/
uchar IAP_DATA_RD(uint addr)
{
    uchar RD_tmp_data;
    RD_tmp_data = *((uchar code *)(addr));
    return  RD_tmp_data;
}
