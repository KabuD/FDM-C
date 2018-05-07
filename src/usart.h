/***************************** Description **************************
* File Name			: usart.h
* Author			: Paweł Drapik
* Version			: V1.0.0
* Date				: 18/04/2018
* Description		: Usart Config header and defines
********************************************************************/
#ifndef USART_H_
#define USART_H_


////// Includes //////
#include "main.h"
#include "stm32f4xx_usart.h"


////// Defines //////
#define aof_ALL 1
#define aof_FEW 0

////// Prototypes //////
void USART_Conf(void);
void USART_Send_Data(uint16_t Data);
void USART_SendArray();
void USART_RecieveNumbers();
void USART_SendPackages(uint16_t whichOnes);

#endif /* USART_H_ */
