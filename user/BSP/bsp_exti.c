/**
  ******************************************************************************
  * @brief   I/O���ж�Ӧ��bsp
  ******************************************************************************
  ******************************************************************************
  */
  
#include "bsp_exti.h"
#include <stdio.h>
#include "bsp_debug.h"


EventGroupHandle_t EXTI_Key_Event_Handle =NULL;
 /**
  * @brief  ���� PA0 Ϊ���жϿڣ��������ж����ȼ�
  * @param  ��
  * @retval ��
  */
void EXTI_Key_Config(void)
{
		/* ���� Event_Handle */
    EXTI_Key_Event_Handle = xEventGroupCreate();	 
	 if(NULL != EXTI_Key_Event_Handle)
    debug_printf("infra_red_Event_Handle �¼������ɹ�!\r\n");
	 else
		debug_printf("infra_red_Event_Handle �¼�����ʧ��!\r\n");
}


BaseType_t xHigherPriorityTaskWoken = pdFALSE;

void KEY1_IRQHandler_APP(void)
{
	GPIO_PinState bitstatus = key01_state;
  //ȷ���Ƿ������EXTI Line�ж�
	if(__HAL_GPIO_EXTI_GET_IT(KEY01_Pin) != RESET) 
	{
		//key1 event 
			if(bitstatus == state_H)
			{
				xEventGroupSetBitsFromISR(EXTI_Key_Event_Handle,KEY01_DOWN_EVENT,&xHigherPriorityTaskWoken);
			}
		  else if(bitstatus == state_L)
			{
				xEventGroupSetBitsFromISR(EXTI_Key_Event_Handle,KEY01_UP_EVENT,&xHigherPriorityTaskWoken);
			}
			
		
    //����жϱ�־λ
		__HAL_GPIO_EXTI_CLEAR_IT(KEY01_Pin);     
	}  
}

void KEY2_IRQHandler_APP(void)
{
	GPIO_PinState bitstatus = key01_state;
  //ȷ���Ƿ������EXTI Line�ж�
	if(__HAL_GPIO_EXTI_GET_IT(KEY02_Pin) != RESET) 
	{
		//key2 event 
			if(bitstatus == state_H)
			{
				xEventGroupSetBitsFromISR(EXTI_Key_Event_Handle,KEY02_DOWN_EVENT,&xHigherPriorityTaskWoken);
			}
		  else if(bitstatus == state_L)
			{
				xEventGroupSetBitsFromISR(EXTI_Key_Event_Handle,KEY02_UP_EVENT,&xHigherPriorityTaskWoken);
			}	
		
    //����жϱ�־λ
		__HAL_GPIO_EXTI_CLEAR_IT(KEY02_Pin);     
	}  
}



