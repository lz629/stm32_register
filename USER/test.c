#include "sys.h"
#include "usart.h" 
#include "delay.h" 
#include "stm32f4xx.h"
//ALIENTEK 探索者STM32F407开发板 实验0
//新建工程实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

int main(void)
{ 
	RCC->AHB1ENR = RCC_AHB1ENR_GPIOFEN;

	Stm32_Clock_Init(336,8,2,7);//设置时钟,168Mhz
	
	delay_init(168);		//初始化延时函数
	uart_init(84,115200);	//串口初始化为115200
	
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


