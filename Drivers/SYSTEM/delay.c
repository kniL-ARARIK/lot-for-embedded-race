#include "stm32wbxx.h" // Device header
#include"stdint.h"
#include"delay.h"

uint32_t g_fac_us=0;
void delay_init(void)
{
	
	uint16_t sysclk = 64;//����ȫ�ֱ������ڴ��ϵͳʱ��

	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK_DIV8);//ȡ��Hal_Init()��systick������
	g_fac_us = sysclk / 8;//����ȫ�ֱ������ڴ��1us�����ʱ��
	
}
void delay_us(uint32_t nus)
{
	
	uint32_t temp;
	SysTick->LOAD = nus * g_fac_us;    //ʱ�����
	SysTick->VAL = 0x00;               //��ռ�����
	SysTick->CTRL |= 1 << 0 ;		   //��ʼ��ʱ
	do
	{
		temp = SysTick->CTRL;
	}
	while((temp & 0x01) &&! (temp & (1<<16)));
	
	SysTick->CTRL &= ~(1<<0);		   //�ر�SysTick
	SysTick->VAL = 0X00;			   //��ռ�����
}

void delay_ms(uint16_t nms)
{
	uint32_t i;
	for(i=0;i<nms;i++) delay_us(1000);
}





