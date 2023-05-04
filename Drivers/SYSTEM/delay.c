#include "stm32wbxx.h" // Device header
#include"stdint.h"
#include"delay.h"

uint32_t g_fac_us=0;
void delay_init(void)
{
	
	uint16_t sysclk = 64;//声明全局变量用于存放系统时钟

	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK_DIV8);//取消Hal_Init()对systick的配置
	g_fac_us = sysclk / 8;//定义全局变量用于存放1us所需的时间
	
}
void delay_us(uint32_t nus)
{
	
	uint32_t temp;
	SysTick->LOAD = nus * g_fac_us;    //时间加载
	SysTick->VAL = 0x00;               //清空计数器
	SysTick->CTRL |= 1 << 0 ;		   //开始计时
	do
	{
		temp = SysTick->CTRL;
	}
	while((temp & 0x01) &&! (temp & (1<<16)));
	
	SysTick->CTRL &= ~(1<<0);		   //关闭SysTick
	SysTick->VAL = 0X00;			   //清空计数器
}

void delay_ms(uint16_t nms)
{
	uint32_t i;
	for(i=0;i<nms;i++) delay_us(1000);
}





