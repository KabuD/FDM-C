/***************************** Description **************************
* File Name			: main.c
* Author			: Adam Bondyra
* Version			: V1.0.0
* Date				: 06/02/2018
* Description		: TeleM - INNOLOT Telemetry Module F/W
********************************************************************/
/* Includes */
#include "main.h"
#include "gpio.h"
#include "rcc.h"
#include "nvic.h"
#include "tim.h"
#include "spi.h"
#include "usart.h"

int main(void)
{
	RCC_Conf();
	GPIO_Conf();
	NVIC_Conf();
	TIM_Conf();
	SPI_Conf();
	USART_Conf();

    freePosition=0;
    _STOP_MEAS=1;

	/* Infinite loop */
	while (1)
	{
	}
}




