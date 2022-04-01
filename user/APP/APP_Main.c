#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "App_Main.h"

#include "bsp_led.h"  
#include "bsp_debug.h"

static void Task01(void * argument);
osThreadId Task01_TaskHandle;

const osThreadAttr_t osID_Task01 = {
  .name = "osID_Task01",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

static void Task02(void * argument);
osThreadId Task02_TaskHandle;

const osThreadAttr_t osID_Task02 = {
  .name = "osID_Task02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

void APP_Main(void) {

      //�����߳�����01
  Task01_TaskHandle = osThreadNew(Task01, NULL, &osID_Task01);//�����߳�����01

	    //�����߳�����02
  Task02_TaskHandle = osThreadNew(Task02, NULL, &osID_Task02);//�����߳�����02


}




static void Task01(void * argument)
{

  for(;;)
  {
    led_check();
  }
}


static void Task02(void * argument)
{
	printf("�����ض���ɹ���pringtf��ӡ��Ϣ������\r\n");
  for(;;)
  {
    osDelay(1000);
  }
}


