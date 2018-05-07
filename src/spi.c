/***************************** Description **************************
* File Name			: spi.c
* Author			: Adam Bondyra
* Version			: V1.0.0
* Date				: 06/02/2018
* Description		: Low-level SPI operations
********************************************************************/

////// Includes //////
#include "spi.h"
#include "gpio.h"
#include "tim.h"
////// Declarations //////
SPI_InitTypeDef SPI_InitStructure;
extern DMA_InitTypeDef DMAInitSPI1Rx;
extern DMA_InitTypeDef DMAInitSPI1Tx;

/*************************** SPI_Conf ******************************
* Function Name		: SPI_Conf
* Description		: Configuration of SPI
* Input				: None
* Output			: None
* Return			: None
********************************************************************/
void SPI_Conf(void)
{
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;	    // Bidirectional mode
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;						    // Working as master
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;					    // Data size - 16bit
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;							    // Signals configuration
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;							    // NSS controlled by software
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;	    // Prescaler = 16 -> 84MHz/256
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;					    // First bit - MSB
	SPI_Init(SPI1, &SPI_InitStructure);
	SPI_Cmd(SPI1, ENABLE);												    // Enable SPI

	SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Rx, ENABLE);					    // Enable DMA connection
	SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Tx, ENABLE);
}

void _chip_Select(void) {
	GPIO_ResetBits(_SPI_GPIO,_CS_Pin);
}

void _chip_Deselect(void) {
	GPIO_SetBits(_SPI_GPIO,_CS_Pin);
}

uint16_t SPI_Transfer(uint16_t data){
	_chip_Deselect();
    delay_100n(182);
	_chip_Select();
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
	SPI_I2S_SendData(SPI1,data);
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
	return SPI_I2S_ReceiveData(SPI1);
}
