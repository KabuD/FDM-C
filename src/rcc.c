/***************************** Description **************************
* File Name			: rcc.c
* Author			: Przemys³aw G¹sior
* Version			: V4.0.0
* Date				: 30/05/2017
* Description		: RCC operation
********************************************************************/

////// Includes //////
#include "rcc.h"
#include "main.h"
#include "stm32f4xx.h"

/**************************** RCC_Conf ******************************
* Function Name  : RCC_Conf
* Description    : None
* Input          : None
* Output         : None
* Return         : None
********************************************************************/
void RCC_Conf(void)
{
	// AHB1
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB, ENABLE);
	// AHB2
	// APB1
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	// APB2
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
}
