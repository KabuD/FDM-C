/***************************** Description **************************
* File Name			: usart.c
* Author			: Paweł Drapik
* Version			: V1.0.0
* Date				: 18/04/2018
* Description		: Usart Config
********************************************************************/

#include "usart.h"
#include "main.h"

uint32_t checkSumH;
uint8_t checkSum;


void USART_Conf(void)
{
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 460000;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART1, &USART_InitStructure);

	USART_Cmd(USART1, ENABLE);
}
void USART_Send_Data(uint16_t Data)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	USART_SendData(USART1, Data);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
}
void USART_SendArray()
{
	  for(int j=0;j<2000;j++)
		  {
			  checkSumH=0;
			  USART_Send_Data(0x01); // Start of transmission
			  for (int i=10*j;i<10*(j+1);i++)
			  {
				  part_A = (uint8_t)((_MEASUREMENTS[i] & 0xFF00) >> 8);
				  part_B = (uint8_t)((_MEASUREMENTS[i] & 0x00FF));
				  USART_Send_Data(part_A);
				  USART_Send_Data(part_B);
				  checkSumH+=part_A+part_B;
		      }
			  USART_Send_Data(0x02); // End of transmission
			  checkSum=(uint8_t)((checkSumH & 0x00FF));
			  USART_Send_Data(checkSum);
		  }
}
void USART_RecieveNumbers()
{
uint8_t num_ofPackages;
uint8_t itr=0;
//getting the first data which will indicate the number of packages to be sent
while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
	num_ofPackages=USART_ReceiveData(USART1);

uint8_t buffor[1000]; // array containing packages indicators
while(itr!=num_ofPackages*2)// until we won't get the end of dataframe
{
    while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
    buffor[itr]=USART_ReceiveData(USART1);
    itr++;
}
for(int i=0;i<num_ofPackages*2;i=i+2)
{
	USART_SendPackages((uint16_t)(buffor[i] << 8) | buffor[i+1]);
}
}


void USART_SendPackages(uint16_t whichOnes)
{
	  checkSumH=0;
	  USART_Send_Data(0x01); // Start of transmission
	  for (int i=10*whichOnes;i<10*(whichOnes+1);i++)
	  {
	  part_A = (uint8_t)((_MEASUREMENTS[i] & 0xFF00) >> 8);
	  part_B = (uint8_t)((_MEASUREMENTS[i] & 0x00FF));
	  USART_Send_Data(part_A);
	  USART_Send_Data(part_B);
	  checkSumH+=part_A+part_B;
	 }
	  USART_Send_Data(0x02); // End of transmission
	  checkSum=(uint8_t)((checkSumH & 0x00FF));
	  USART_Send_Data(checkSum);
}
