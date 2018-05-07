/***************************** Description **************************
* File Name			: nvic.c
* Author			: Przemyslaw Gasior
* Version			: V4.0.0
* Date				: 30/05/2017
* Description		: NVIC operation
********************************************************************/

////// Includes //////
#include "nvic.h"
#include "main.h"
#include "stm32f4xx_it.h"
#include "gpio.h"

////// Declarations //////
NVIC_InitTypeDef   NVIC_InitStructure;
EXTI_InitTypeDef   EXTI_InitStructure;

////// Global variables //////

/**************************** NVIC_Conf ******************************
* Function Name  : NVIC_Conf
* Description    : None
* Input          : None
* Output         : None
* Return         : None
********************************************************************/
void NVIC_Conf(void)
{
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);

	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_EnableIRQ(USART1_IRQn);
}












NVIC_InitTypeDef NVIC_InitStructure;
