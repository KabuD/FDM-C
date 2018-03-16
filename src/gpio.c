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
	GPIO_InitStructure.GPIO_Pin =  _Diode_Inf1 | _Diode_Inf2 | _Diode_Err;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(_Diode_GPIO, &GPIO_InitStructure);

	//SPI Bus
	GPIO_InitStructure.GPIO_Pin =  _SCK_Pin | _MISO_Pin | _MOSI_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(_SPI_GPIO, &GPIO_InitStructure);

	GPIO_PinAFConfig(_SPI_GPIO, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(_SPI_GPIO, GPIO_PinSource6, GPIO_AF_SPI1);
	GPIO_PinAFConfig(_SPI_GPIO, GPIO_PinSource7, GPIO_AF_SPI1);

	GPIO_InitStructure.GPIO_Pin =  _CS_Pin | _RST_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(_SPI_GPIO, &GPIO_InitStructure);

}
