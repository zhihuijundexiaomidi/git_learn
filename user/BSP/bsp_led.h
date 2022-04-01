#ifndef _BSP_LED_H
#define	_BSP_LED_H
#include "stm32f4xx.h"
/*******************************************************/
//���ܿ���
#define 	cmsis_os_enable		1

/*******************************************************/

//���Ŷ���
/*******************************************************/
//R ��ɫ��
#define LED1_PIN                  GPIO_PIN_10                 
#define LED1_GPIO_PORT            GPIOH                      
#define LED1_GPIO_CLK_ENABLE()    __GPIOH_CLK_ENABLE()

//G ��ɫ��
#define LED2_PIN                  GPIO_PIN_11                 
#define LED2_GPIO_PORT            GPIOH                      
#define LED2_GPIO_CLK_ENABLE()    __GPIOH_CLK_ENABLE()

//B ��ɫ��
#define LED3_PIN                  GPIO_PIN_12                 
#define LED3_GPIO_PORT            GPIOH                       
#define LED3_GPIO_CLK_ENABLE()    __GPIOH_CLK_ENABLE()
/************************************************************/

/** ����LED������ĺ꣬
	* LED�͵�ƽ��������ON=0��OFF=1
	* ��LED�ߵ�ƽ�����Ѻ����ó�ON=1 ��OFF=0 ����
	*/
#define ON  GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

/* ���κ꣬��������������һ��ʹ�� */
#define LED_Red(a)	  HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_PIN,a)


#define LED_Green(a)	HAL_GPIO_WritePin(LED2_GPIO_PORT,LED2_PIN,a)


#define LED_Yellow(a)	HAL_GPIO_WritePin(LED2_GPIO_PORT,LED3_PIN,a)



/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)			{p->BSRR=i;}			  //����Ϊ�ߵ�ƽ		
#define digitalLo(p,i)			{p->BSRR=(uint32_t)i << 16;}				//����͵�ƽ
#define digitalToggle(p,i)	{p->ODR ^=i;}			//�����ת״̬


/* �������IO�ĺ� */
#define LED_Red_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define LED_Red_OFF		    digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define LED_Red_ON			  digitalLo(LED1_GPIO_PORT,LED1_PIN)

#define LED_Green_TOGGLE		digitalToggle(LED2_GPIO_PORT,LED2_PIN)
#define LED_Green_OFF		    digitalHi(LED2_GPIO_PORT,LED2_PIN)
#define LED_Green_ON			  digitalLo(LED2_GPIO_PORT,LED2_PIN)

#define LED_Yellow_TOGGLE		digitalToggle(LED3_GPIO_PORT,LED3_PIN)
#define LED_Yellow_OFF		  digitalHi(LED3_GPIO_PORT,LED3_PIN)
#define LED_Yellow_ON			  digitalLo(LED3_GPIO_PORT,LED3_PIN)


/* ������ɫ������߼��÷�ʹ��PWM�ɻ��ȫ����ɫ,��Ч������ */

//��
#define LED_RED  \
					LED1_ON;\
					LED2_OFF\
					LED3_OFF

//��
#define LED_GREEN		\
					LED1_OFF;\
					LED2_ON\
					LED3_OFF

//��
#define LED_BLUE	\
					LED1_OFF;\
					LED2_OFF\
					LED3_ON

					
//��(��+��)					
#define LED_YELLOW	\
					LED1_ON;\
					LED2_ON\
					LED3_OFF
//��(��+��)
#define LED_PURPLE	\
					LED1_ON;\
					LED2_OFF\
					LED3_ON

//��(��+��)
#define LED_CYAN \
					LED1_OFF;\
					LED2_ON\
					LED3_ON
					
//��(��+��+��)
#define LED_WHITE	\
					LED1_ON;\
					LED2_ON\
					LED3_ON
					
//��(ȫ���ر�)
#define LED_RGBOFF	\
					LED1_OFF;\
					LED2_OFF\
					LED3_OFF
typedef enum {
	LED_ID_START=0,
	red,
	yellow,
	green,
	LED_ID_END,
} led_id_t;		

typedef enum {
  led_ok=1,
	led_id_err,
	led_state_err,
} led_err_t;	


led_err_t led(uint8_t id,uint8_t state);


#if cmsis_os_enable 

void led_check(void);

#endif					

#endif /* __LED_H */
