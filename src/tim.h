/***************************** Description **************************
* File Name			: tim.h
* Author			: Adam Bondyra
* Version			: V1.0.0
* Date				: 06/02/2018
* Description		: Timer Config header and defines
********************************************************************/
#ifndef TIM_H_
#define TIM_H_

////// Includes //////
#include "main.h"
#include "stm32f4xx_tim.h"


////// Defines //////

////// Prototypes //////
void TIM_Conf(void);
void delay_ms(int time);

#endif /* TIM_H_ */
