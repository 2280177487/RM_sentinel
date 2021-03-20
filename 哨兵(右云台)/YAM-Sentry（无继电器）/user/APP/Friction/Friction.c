#include "Friction.h"
#include "Pwm.h"
#include "remote_control.h"
#include "start_task.h"

#define High_Friction_Speed    800
#define Mid_Friction_Speed     600
#define Low_Friction_Speed     400
#define Stop_Friction_Speed    0


extern  RC_ctrl_t rc_ctrl;

extern eRemoteMode remoteMode;

bool FRICTION_FLAG = TRUE;


//Ħ����Ŀ���ٶ�
float Speed_Mode;
float Friction_Speed_Target;

//Ħ���ֵȼ�Ŀ��ת��
float Frict_Speed_Level_Target;

//Ħ����ʵ������ٶ�,������б�����
float Friction_Speed_Real;

float kRc_Friction = 0.7 ;


void FRICTION_Ctrl( void )
{

	Friction_Rc_Ctrl();
	
	Friction_Ramp();
	
	TIM4_FrictionPwmOutp(Friction_Speed_Real, Friction_Speed_Real);
	TIM5_FrictionPwmOutp(Friction_Speed_Real, Friction_Speed_Real);
	TIM8_FrictionPwmOutp(Friction_Speed_Real, Friction_Speed_Real,Friction_Speed_Real,Friction_Speed_Real);
	
}







void Friction_Ramp(void)
{
	if (Friction_Speed_Real < Friction_Speed_Target)//����
	{
		Friction_Speed_Real += 5;
		
		if(Friction_Speed_Real > Friction_Speed_Target)
		{
			Friction_Speed_Real = Friction_Speed_Target;
		}
	}
	else if (Friction_Speed_Real > Friction_Speed_Target)//�ر�
	{
		Friction_Speed_Real -= 5;
	}
	
	if (Friction_Speed_Real < 0)
	{
		Friction_Speed_Real = 0;
	}
}



/**
  * @brief  ��ȡ��ǰĦ����PWM���ֵ
  * @param  void
  * @retval ʵ��PWMֵ
  * @attention ������ֹĦ�����ٶȹ��͵�����²��̵�ת��
  */
float Fric_GetSpeedReal(void)
{
	return Friction_Speed_Real;
}
