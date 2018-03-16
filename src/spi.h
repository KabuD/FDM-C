/***************************** Description **************************
* File Name			: spi.h
* Author			: Adam Bondyra
* Version			: V1.0.0
* Date				: 06/02/2018
* Description		: Low-level SPI operations header
********************************************************************/

#ifndef SPI_H_
#define SPI_H_

////// Includes //////
#include "stm32f4xx.h"
#include "main.h"

////// Defines //////
#define RFM_SPI_READ 		0
#define RFM_SPI_WRITE		1

////// Prototypes //////
void SPI_Conf(void);
void _chip_Select();
void _chip_Deselect();

uint8_t SPI_Transfer(uint8_t addr);

#endif /* SPI_H_ */
