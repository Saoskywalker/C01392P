
#include "GCE_General.h"
//==============================================================================
//      2) Private defines
//==============================================================================
GCE_XDATA EXV_STATUS EXV_UD_status_out=STATUS1;
GCE_XDATA EXV_STATUS EXV_UD_status=STATUS1;
GCE_XDATA EXV_STATUS EXV_UD_status_buf=STATUS1;


GCE_XDATA Swing_Mode  EXV_SWING_Mode;
//GCE_XDATA Swing_Mode  EXV_SWING_Mode_old;

//GCE_XDATA EXV_STATUS EXV_LR_status_out=STATUS1;
//GCE_XDATA EXV_STATUS EXV_LR_status=STATUS1;
//GCE_XDATA EXV_STATUS EXV_LR_status_buf=STATUS1;

//
const UI08 step_tab_self[]={0x00,0x08,0x04,0x02,0x01};//步进电机测试运行数组

/*
1000
1100
0100
0110
0010
0011
0001
1001
*/
/*************************************************
 // 函数名称    : EXV_Data_init
 // 功能描述    :
 // 入口参数    : 无
 // 出口参数    : 无
************************************************/
void EXV_Data_Init(void)
{
 EXV_SWING_Mode=STOP_SWING;

 EXV_UD_status_out=STATUS_NO;
 EXV_UD_status=STATUS_NO;
 EXV_UD_status_buf=STATUS_NO;

 //EXV_LR_status_out=STATUS_NO;
 //EXV_LR_status=STATUS_NO;
 //EXV_LR_status_buf=STATUS_NO;
}

/*************************************************
 // 函数名称    : EXV_UD_Ligic
 // 功能描述    :
 // 入口参数    : 无
 // 出口参数    : 无
************************************************/
//STATUS1 上电快速关闭全程
//STATUS2 关机慢关全程
//STATUS3 待机到开机时快速打开全程
//STATUS4 摆动
//STATUS5 定位在45度
void EXV_UD_Ligic(void)
{
  switch(EXV_UD_status_out)
  {
     case STATUS1:
     {
          EXV_UD_status=EXV_UD_status_out;
     }break;
     case STATUS2:
     {
          EXV_UD_status=EXV_UD_status_out;
     }break;
     case STATUS3:
     {
     	  if((EXV_UD_status==STATUS1)||(EXV_UD_status==STATUS2))
     	  {
              if((EXV_UD.EXV_Step_Now==UD_degree00)&&(EXV_UD.EXV_Step_Target==UD_degree00))
     	      {
	          EXV_UD_status=EXV_UD_status_out;
	      }
              //EXV_UD_status=EXV_UD_status_out;
	  }
	  else if(EXV_UD_status==STATUS4)
	  {
	      EXV_UD_status=EXV_UD_status_out;
	  }
     	  else if(EXV_UD_status==STATUS5)
     	  {
              EXV_UD_status=EXV_UD_status_out;
	  }
     }break;
     case STATUS4:
     {
     	  if((EXV_UD_status==STATUS1)||(EXV_UD_status==STATUS2))
     	  {
              if((EXV_UD.EXV_Step_Now==UD_degree00)&&(EXV_UD.EXV_Step_Target==UD_degree00))
     	      {
		  EXV_UD_status=STATUS3;
	      }
              //EXV_UD_status=STATUS3;
	  }
	  else if(EXV_UD_status==STATUS3)
	  {
              if((EXV_UD.EXV_Step_Now>=UD_degree90)&&(EXV_UD.EXV_Step_Target>=UD_degree90))
     	      {
	          EXV_UD_status=EXV_UD_status_out;
	          EXV_UD.EXV_Step_Now=UD_degree90;
	          EXV_UD.EXV_Step_Target=UD_degree90;
	      }
	  }
     	  else if(EXV_UD_status==STATUS5)
     	  {
             EXV_UD_status=EXV_UD_status_out;
	  }
     }break;
     case STATUS5:
     {
     	  if((EXV_UD_status==STATUS1)||(EXV_UD_status==STATUS2))
     	  {
	      if((EXV_UD.EXV_Step_Now==UD_degree00)&&(EXV_UD.EXV_Step_Target==UD_degree00))
     	      {
		  EXV_UD_status=STATUS3;
	      }
              //EXV_UD_status=STATUS3;
	  }
	  else if(EXV_UD_status==STATUS3)
	  {
              if((EXV_UD.EXV_Step_Now>=UD_degree90)&&(EXV_UD.EXV_Step_Target>=UD_degree90))
     	      {
	          EXV_UD_status=EXV_UD_status_out;
	          EXV_UD.EXV_Step_Now=UD_degree90;
	          EXV_UD.EXV_Step_Target=UD_degree90;
	      }
	  }
     	  else if(EXV_UD_status==STATUS4)
     	  {
             EXV_UD_status=EXV_UD_status_out;
	  }
     }break;
  };


  //
  switch(EXV_UD_status)
  {
     //STATUS1 快速关闭全程
     case STATUS1:
     {
        if(EXV_UD_status_buf!=EXV_UD_status)
        {
           EXV_UD_status_buf=EXV_UD_status;
           EXV_UD.EXV_Step_Time=EXV_UD_step_short_time;
	   EXV_UD.EXV_Step_Now=UD_degree90+UD_degree_Closs;//全关多走50步
	   EXV_UD.EXV_Step_Target=0;
	}
     };break;
     //STATUS2 慢速关闭全程
     case STATUS2:
     {
        if(EXV_UD_status_buf!=EXV_UD_status)
        {
           EXV_UD_status_buf=EXV_UD_status;
           EXV_UD.EXV_Step_Time=EXV_UD_step_long_time; // EXV_step_long_time
	   EXV_UD.EXV_Step_Now=UD_degree90+UD_degree_Closs;//全关多走50步
	   EXV_UD.EXV_Step_Target=0;
	}
     };break;
     //STATUS3 快速打开全程
     case STATUS3:
     {
        if(EXV_UD_status_buf!=EXV_UD_status)
        {
           EXV_UD_status_buf=EXV_UD_status;
           EXV_UD.EXV_Step_Time=EXV_UD_step_short_time;
	   //EXV_UD.EXV_Step_Now=0;//开大最大时有限位时不用屏蔽
	   EXV_UD.EXV_Step_Target=UD_degree90;
	}

      };break;
     //STATUS4 摆动
     case STATUS4:
     {
       if(EXV_UD_status_buf!=EXV_UD_status)
       {
           EXV_UD_status_buf=EXV_UD_status;
           EXV_UD.EXV_Step_Time=EXV_UD_step_long_time;
	   EXV_UD.EXV_Step_Target=UD_degree90;
       }

       if(EXV_UD.EXV_Step_Now==EXV_UD.EXV_Step_Target)
       {
           if(EXV_UD.EXV_Step_Now==UD_degree90)
  	   {
  		EXV_UD.EXV_Step_Target=UD_degree45;
           }
  	   else
  	   {
  		EXV_UD.EXV_Step_Target=UD_degree90;
  	   }
       }
     };break;
     case STATUS5:
     {
       if(EXV_UD_status_buf!=EXV_UD_status)
       {
           EXV_UD_status_buf=EXV_UD_status;
           EXV_UD.EXV_Step_Time=EXV_UD_step_long_time;
	   EXV_UD.EXV_Step_Target=UD_degree45;
       }
     };break;
  }


}


/*************************************************
 // 函数名称    : EXV_UD_Ligic
 // 功能描述    :
 // 入口参数    : 无
 // 出口参数    : 无
************************************************/
//STATUS1 上电快速关闭全程
//STATUS2 关机慢关全程
//STATUS3 待机到开机时快速打开全程
//STATUS4 摆动
//STATUS5 定位在45度
/*
void EXV_LR_Ligic(void)
{
  switch(EXV_LR_status_out)
  {
     case STATUS1:
     {
          EXV_LR_status=EXV_LR_status_out;
     }break;
     case STATUS2:
     {
          EXV_LR_status=EXV_LR_status_out;
     }break;
     case STATUS3:
     {
     	  if((EXV_LR_status==STATUS1)||(EXV_LR_status==STATUS2))
     	  {
              if((EXV_LR.EXV_Step_Now==LR_degree00)&&(EXV_LR.EXV_Step_Target==LR_degree00))
     	      {
	          EXV_LR_status=EXV_LR_status_out;
	      }
              //EXV_LR_status=EXV_LR_status_out;
	  }
	  else if(EXV_LR_status==STATUS4)
	  {
	      EXV_LR_status=EXV_LR_status_out;
	  }
     	  else if(EXV_LR_status==STATUS5)
     	  {
              EXV_LR_status=EXV_LR_status_out;
	  }
     }break;
     case STATUS4:
     {
     	  if((EXV_LR_status==STATUS1)||(EXV_LR_status==STATUS2))
     	  {
              if((EXV_LR.EXV_Step_Now==LR_degree00)&&(EXV_LR.EXV_Step_Target==LR_degree00))
     	      {
		  EXV_LR_status=STATUS3;
	      }
              //EXV_LR_status=STATUS3;
	  }
	  else if(EXV_LR_status==STATUS3)
	  {
              if((EXV_LR.EXV_Step_Now>=LR_degree120)&&(EXV_LR.EXV_Step_Target>=LR_degree120))
     	      {
	          EXV_LR_status=EXV_LR_status_out;
	          EXV_LR.EXV_Step_Now=LR_degree120;
	          EXV_LR.EXV_Step_Target=LR_degree120;
	      }
	  }
     	  else if(EXV_LR_status==STATUS5)
     	  {
             EXV_LR_status=EXV_LR_status_out;
	  }
     }break;
     case STATUS5:
     {
     	  if((EXV_LR_status==STATUS1)||(EXV_LR_status==STATUS2))
     	  {
	      if((EXV_LR.EXV_Step_Now==LR_degree00)&&(EXV_LR.EXV_Step_Target==LR_degree00))
     	      {
		  EXV_LR_status=STATUS3;
	      }
              //EXV_UD_status=STATUS3;
	  }
	  else if(EXV_LR_status==STATUS3)
	  {
              if((EXV_LR.EXV_Step_Now>=LR_degree120)&&(EXV_LR.EXV_Step_Target>=LR_degree120))
     	      {
	          EXV_LR_status=EXV_LR_status_out;
	          EXV_LR.EXV_Step_Now=LR_degree120;
	          EXV_LR.EXV_Step_Target=LR_degree120;
	      }
	  }
     	  else if(EXV_LR_status==STATUS4)
     	  {
             EXV_LR_status=EXV_LR_status_out;
	  }
     }break;
  };


  //
  switch(EXV_LR_status)
  {
     //STATUS1 快速关闭全程
     case STATUS1:
     {
        if(EXV_LR_status_buf!=EXV_LR_status)
        {
           EXV_LR_status_buf=EXV_LR_status;
           EXV_LR.EXV_Step_Time=EXV_LR_step_short_time;
	   EXV_LR.EXV_Step_Now=LR_degree120+50;//全关多走50步
	   EXV_LR.EXV_Step_Target=0;
	}
     };break;
     //STATUS2 慢速关闭全程
     case STATUS2:
     {
        if(EXV_LR_status_buf!=EXV_LR_status)
        {
           EXV_LR_status_buf=EXV_LR_status;
           EXV_LR.EXV_Step_Time=EXV_LR_step_long_time;
	   EXV_LR.EXV_Step_Now=LR_degree120+50;//全关多走50步
	   EXV_LR.EXV_Step_Target=0;
	}
     };break;
     //STATUS3 快速打开全程
     case STATUS3:
     {
        if(EXV_LR_status_buf!=EXV_LR_status)
        {
           EXV_LR_status_buf=EXV_LR_status;
           EXV_LR.EXV_Step_Time=EXV_LR_step_short_time;
	   //EXV_UD.EXV_Step_Now=0;//开大最大时有限位时不用屏蔽
	   EXV_LR.EXV_Step_Target=LR_degree120;
	}

      };break;
     //STATUS4 摆动
     case STATUS4:
     {
       if(EXV_LR_status_buf!=EXV_LR_status)
       {
           EXV_LR_status_buf=EXV_LR_status;
           EXV_LR.EXV_Step_Time=EXV_LR_step_long_time;
	   EXV_LR.EXV_Step_Target=LR_degree120;
       }

       if(EXV_LR.EXV_Step_Now==EXV_LR.EXV_Step_Target)
       {
           if(EXV_LR.EXV_Step_Now==LR_degree120)
  	   {
  		EXV_LR.EXV_Step_Target=LR_degree60;
           }
  	   else
  	   {
  		EXV_LR.EXV_Step_Target=LR_degree120;
  	   }
       }
     };break;
     case STATUS5:
     {
       if(EXV_LR_status_buf!=EXV_LR_status)
       {
           EXV_LR_status_buf=EXV_LR_status;
           EXV_LR.EXV_Step_Time=EXV_LR_step_long_time;
	   EXV_LR.EXV_Step_Target=LR_degree90;
       }
     };break;
  }


}
*/
/*************************************************
 // 函数名称    : exv_Self_Test
 // 功能描述    :
 // 入口参数    : 无
 // 出口参数    : 无
************************************************/
void exv_Self_Test(void)
{
    UI08  buf=0;
    static  UI08  exv_Self_Test_timer=0;//自检LED灯延迟时间
    //
    if(EXV_UD.EXV_Step_Time_Cnt<8)
    {return;}
    EXV_UD.EXV_Step_Time_Cnt=0;
    //
    if(++exv_Self_Test_timer<50)
    {return;}
    exv_Self_Test_timer=0;
    //
    if(EXV_UD.EXV_Step_Cnt>=5)
    {EXV_UD.EXV_Step_Cnt=1;}
    //
    buf=step_tab_self[EXV_UD.EXV_Step_Cnt++];
    EXV_UD_Out(buf);
}
/*************************************************
 // 函数名称    : exv_control
 // 功能描述    :
 // 入口参数    : 无
 // 出口参数    : 无
************************************************/
void EXV_Control(void)
{
  if(_Self_Test)
  {
    exv_Self_Test();
      return;
  }

  switch(EXV_SWING_Mode)
  {
      case AUTO_SWING://自动摆
      {
            EXV_UD_status_out=STATUS4;
	    //EXV_LR_status_out=STATUS4;
      }break;
      case LEFT_RIGHT_SWING://左右摆
      {
           EXV_UD_status_out=STATUS5;
	   //EXV_LR_status_out=STATUS4;
      }break;
      case UP_DOWN_SWING://上下摆
      {
           EXV_UD_status_out=STATUS4;
	   //EXV_LR_status_out=STATUS5;
      }break;
      case STOP_SWING://停止摆
      {
      	   if(_Power_Status)
      	   {
              EXV_UD_status_out=STATUS5;
	      //EXV_LR_status_out=STATUS5;
	   }
	   else
	   {
              EXV_UD_status_out=STATUS1;
	      //EXV_LR_status_out=STATUS1;
	   }
      }break;
  };

  EXV_UD_Ligic();
  //EXV_LR_Ligic();
}

//////////////////////////////////////////////////////////
//
//      eeeeeeeeee       n           nn      ddddddddd
//     ee               nnn         nn      dd       dd
//    ee               nn   n      nn      dd        dd
//   eeeeeeeeee       nn     n    nn      dd         dd
//  ee               nn       n  nn      dd         dd
// ee               nn         nnn      dd         dd
//eeeeeeeeee       nn          nn      ddddddddddd
//
//Designed by caozhongfu 2011.03.30
///////////////////////////////////////////////////////////
/******** (C) COPYRIGHT 2011 GCE -----END OF FILE ********/
