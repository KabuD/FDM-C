/***************************** Description **************************
* File Name			: gpio.h
* Author			: Adam Bondyra
* Version			: V1.0.0
* Date				: 06/02/2018
* Description		: GPIO Header
********************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

////// Includes //////
#include "main.h"

////// Defines //////
#define	_Diode_Inf1  		GPIO_Pin_8
#define	_Diode_Inf2  		GPIO_Pin_9
#define _Diode_GPIO			GPIOB
////// SPI ///////
#define _CS_Pin	   			GPIO_Pin_4
#define _SCK_Pin			GPIO_Pin_5
#define _MISO_Pin			GPIO_Pin_6
#define _MOSI_Pin			GPIO_Pin_7
#define _RST_Pin			GPIO_Pin_2
#define _SPI_GPIO			GPIOA
////// USART ///////
#define _Tx_Pin             GPIO_Pin_9
#define _Rx_Pin             GPIO_Pin_10
#define _USART_GPIO         GPIOA
////// Prototypes //////
void GPIO_Conf(void);

#endif /* GPIO_H_ */
