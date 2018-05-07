/***************************** Description **************************
* File Name			: tim.c
* Author			: Adam Bondyra
* Version			: V1.0.0
* Date				: 06/02/2018
* Description		: Timer Config
********************************************************************/
#include "tim.h"

volatile uint32_t timer_ms = 0;

/**************************** TIM_Conf ******************************
* Function Name  : TIM_Conf
* Description    : Configuration of Timers
* Input          : None
* Output         : None
* Return         : None
********************************************************************/

void TIM_Conf(){

	SysTick_Config(SystemCoreClock/1000);  //1ms

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Period = 89;  //10 us
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode =  TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM3, DISABLE);

	TIM_TimeBaseStructure.TIM_Period = 0;  //1 us timer for timing the tests
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode =  TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM4, DISABLE);

	TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	TIM_ITConfig(TIM3, TIM_IT_Update, DISABLE);
}

void delay_ms(int time)
{
	 timer_ms = time;
	 while (timer_ms);
}
void delay_100n(int time)
{
	TIM4->ARR=time;
	TIM_Cmd(TIM4, ENABLE);
	while(TIM_GetFlagStatus(TIM4,TIM_FLAG_Update)==RESET);
	TIM_Cmd(TIM4,DISABLE);
	TIM_ClearFlag(TIM4,TIM_FLAG_Update);
}

