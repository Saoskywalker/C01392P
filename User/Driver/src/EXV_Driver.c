
#include "GCE_General.h"

//���°�Ҷ���
GCE_XDATA sEXVPARA EXV_UD;
GCE_CONST UI08 UD_Step_Tab[] = {0x08, 0x0c, 0x04, 0x06, 0x02, 0x03, 0x01, 0x09};

//���°�Ҷ���
// GCE_XDATA  sEXVPARA  EXV_LR;
// GCE_CONST  UI08 LR_Step_Tab[]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};
/*************************************************
 // ��������    : EXV_UD_Out
 // ��������    :
 // ��ڲ���    :
 // ���ڲ���    : ��
************************************************/
void EXV_UD_Out(UI08 _io_data)
{
	if (_io_data & bit0)
	{
		EXV_UD_A_H;
	}
	else
	{
		EXV_UD_A_L;
	}

	if (_io_data & bit1)
	{
		EXV_UD_B_H;
	}
	else
	{
		EXV_UD_B_L;
	}

	if (_io_data & bit2)
	{
		EXV_UD_C_H;
	}
	else
	{
		EXV_UD_C_L;
	}

	if (_io_data & bit3)
	{
		EXV_UD_D_H;
	}
	else
	{
		EXV_UD_D_L;
	}
}

/*
void EXV_LR_Out(UI08 _io_data)
{
	if(_io_data&bit0)
		{EXV_LR_A_H;}
	else
	{EXV_LR_A_L;}

	if(_io_data&bit1)
		{EXV_LR_B_H;}
	else
	{EXV_LR_B_L;}

	if(_io_data&bit2)
		{EXV_LR_C_H;}
	else
	{EXV_LR_C_L;}

	if(_io_data&bit3)
		{EXV_LR_D_H;}
	else
	{EXV_LR_D_L;}
}
*/
/*************************************************
 // ��������    : EXV_UD_run
 // ��������    :
 // ��ڲ���    : ��
 // ���ڲ���    : ��
************************************************/
void EXV_UD_run(void)
{
	if (EXV_UD.EXV_Excit_Time < 0xffff)
	{
		EXV_UD.EXV_Excit_Time++;
	}

	EXV_UD.EXV_Step_Time_Cnt++;

	if (EXV_UD.EXV_Step_Now == EXV_UD.EXV_Step_Target)
	{
		EXV_UD.EXV_Excit_Time = 0;
		EXV_UD_Out(0x00); //�ر�ȫ�����
		return;
	}

	if (EXV_UD.EXV_Excit_Time < 500) //�´�0.5s
	{
		EXV_UD_Out(UD_Step_Tab[EXV_UD.EXV_Step_Cnt]);
		EXV_UD.EXV_Step_Time_Cnt = 0;
		return;
	}

	if (EXV_UD.EXV_Step_Time_Cnt < EXV_UD.EXV_Step_Time)
	{
		return;
	}

	EXV_UD.EXV_Step_Time_Cnt = 0;
	//
	if (EXV_UD.EXV_Step_Target > EXV_UD.EXV_Step_Now) //��ת
	{
		if (EXV_UD.EXV_Step_Cnt == 0)
		{
			EXV_UD.EXV_Step_Cnt = 7;
		}
		else
		{
			EXV_UD.EXV_Step_Cnt--;
		}
		EXV_UD.EXV_Step_Now++;
	}
	else if (EXV_UD.EXV_Step_Target < EXV_UD.EXV_Step_Now) //��ת
	{
		EXV_UD.EXV_Step_Cnt++;
		if (EXV_UD.EXV_Step_Cnt >= 8)
		{
			EXV_UD.EXV_Step_Cnt = 0;
		}
		EXV_UD.EXV_Step_Now--;
	}

	EXV_UD_Out(UD_Step_Tab[EXV_UD.EXV_Step_Cnt]);
}

/*************************************************
 // ��������    : EXV_LR_run
 // ��������    :
 // ��ڲ���    : ��
 // ���ڲ���    : ��
************************************************/
/*
void EXV_LR_run(void)
{
		if(EXV_LR.EXV_Excit_Time<0xffff)
	{ EXV_LR.EXV_Excit_Time++; }

	EXV_LR.EXV_Step_Time_Cnt++;

	if(EXV_LR.EXV_Step_Now==EXV_LR.EXV_Step_Target)
	{
		  EXV_LR.EXV_Excit_Time=0;
	  EXV_LR_Out(0x00);//�ر�ȫ�����
	   return;
	}

	if(EXV_LR.EXV_Excit_Time<500)//�´�0.5s
	{
		EXV_LR_Out(LR_Step_Tab[EXV_LR.EXV_Step_Cnt]);
		EXV_LR.EXV_Step_Time_Cnt=0;
		return;
	}

	if(EXV_LR.EXV_Step_Time_Cnt<EXV_LR.EXV_Step_Time)
	{return;}

	EXV_LR.EXV_Step_Time_Cnt=0;
	//
		if(EXV_LR.EXV_Step_Target>EXV_LR.EXV_Step_Now)//��ת
		{
		if(EXV_LR.EXV_Step_Cnt==0)
		{EXV_LR.EXV_Step_Cnt=7;}
		else
		{EXV_LR.EXV_Step_Cnt--;}
		EXV_LR.EXV_Step_Now++;
	}
	else if(EXV_LR.EXV_Step_Target<EXV_LR.EXV_Step_Now)//��ת
	{
		EXV_LR.EXV_Step_Cnt++;
			if(EXV_LR.EXV_Step_Cnt>=8)
		{EXV_LR.EXV_Step_Cnt=0;}
			EXV_LR.EXV_Step_Now--;
	}

		EXV_LR_Out(LR_Step_Tab[EXV_LR.EXV_Step_Cnt]);
}
*/
