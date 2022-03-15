#include "sys.h"
#include "usart.h" 
#include "delay.h" 
#include "stm32f4xx.h"
//ALIENTEK ̽����STM32F407������ ʵ��0
//�½�����ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾

int main(void)
{ 
	RCC->AHB1ENR = RCC_AHB1ENR_GPIOFEN;

	Stm32_Clock_Init(336,8,2,7);//����ʱ��,168Mhz
	
	delay_init(168);		//��ʼ����ʱ����
	uart_init(84,115200);	//���ڳ�ʼ��Ϊ115200
	
	GPIO_Set(GPIOF, 0x0600, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_SPEED_100M, GPIO_PUPD_PU);

	while(1)
	{
		printf("000   odr:%d\r\n",GPIOF->ODR);
		delay_ms(500);
		GPIOF->ODR = 1<<9 & 0x0200;
		printf("111   odr:%d\r\n",GPIOF->ODR);
		delay_ms(500);
		GPIOF->ODR = 1<<10 | 0x0400;
	}
}


