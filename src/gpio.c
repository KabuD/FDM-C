/***************************** Description **************************
* File Name			: gpio.c
* Author			: Adam Bondyra
* Version			: V1.0.0
* Date				: 06/02/2018
* Description		: GPIO config and operations
********************************************************************/

////// Includes //////
#include "gpio.h"

////// Definitions //////
GPIO_InitTypeDef  GPIO_InitStructure;

/**************************** GPIO_Conf ******************************
* Function Name  : GPIO_Conf
* Description    : Configuration of GPIO
* Input          : None
* Output         : None
* Return         : None
********************************************************************/
void GPIO_Conf(void)
{
	// Configure Diodes
	GPIO_InitStructure.GPIO_Pin =  _Diode_Inf1 | _Diode_Inf2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(_Diode_GPIO, &GPIO_InitStructure);

	//SPI Bus
	GPIO_InitStructure.GPIO_Pin =  _SCK_Pin | _MISO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(_SPI_GPIO, &GPIO_InitStructure);


	GPIO_PinAFConfig(_SPI_GPIO, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(_SPI_GPIO, GPIO_PinSource6, GPIO_AF_SPI1);

	GPIO_InitStructure.GPIO_Pin =  _CS_Pin | _RST_Pin| _MOSI_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(_SPI_GPIO, &GPIO_InitStructure);

	GPIO_SetBits(_SPI_GPIO,_MOSI_Pin);

	// USART
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = _Tx_Pin | _Rx_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(_USART_GPIO, &GPIO_InitStructure);

	GPIO_ResetBits(_USART_GPIO,_Rx_Pin);

	GPIO_PinAFConfig(_USART_GPIO, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(_USART_GPIO, GPIO_PinSource10, GPIO_AF_USART1);
}
