/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  lilingxiong
  * @version V0.1
  * @date    2022-03-30
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************************
  * @attention
  *һ�еĿ��˶�Ҫ�ӵ�ƿ�ʼ˵��mxcub�ܹ�ֱ�ӳ�ʼ���ײ������ֻ��Ҫ�Ѱ弶֧�ְ��Ľӿں�
  *��Ӧ��Ӳ���ӿڹ�����һ��ledֻ�Ǽ򵥵�GPIO�������������hal���Ѿ��������ЩӲ���ӿڡ�����
	*ֻ��Ҫ�Ӷ���һ�����֣��ù��ܿ�������ֱ�۾Ϳ����ˡ�
  ******************************************************************************
  */
	
#include "bsp_led.h"   
#include "stdint.h"
led_err_t led(uint8_t id,uint8_t state)
{
	led_err_t ERR=led_ok;
	if(id <= LED_ID_START || id >= LED_ID_END)
	{
		ERR=led_id_err;//���ش����ID��Ϣ
	}
	if(state != OFF && state != LED_ID_END)
	{
		ERR=led_state_err;//���ش����ID��Ϣ
	}
	if(state == OFF)
	{
				switch(id)
			{
				case red:LED_Red_OFF;break;
				case yellow:LED_Yellow_OFF;break;
				case green:LED_Green_OFF;break;
				default: break;
			}
	}
	else if(state == ON)
	{
			switch(id)
			{
				case red:LED_Red_ON;break;
				case yellow:LED_Yellow_ON;break;
				case green:LED_Green_ON;break;
				default: break;
			}
	}
	return ERR;
	
}



#if cmsis_os_enable
#include "cmsis_os.h"

void led_check(void)
{
	int i = 0;
	for(i=LED_ID_START+1;i<LED_ID_END;i++)
	{
			led(i,ON);
			osDelay(1000);//�ӳ�һ��
			led(i,OFF);
//		  osDelay(1000);//�ӳ�һ��
	}
}

#endif


