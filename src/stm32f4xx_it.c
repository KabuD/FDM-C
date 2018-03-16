/***************************** Description **************************
* File Name			: stm32f4xx_it.c
* Author			: Adam Bondyra
* Version			: V1.0.0
* Date				: 06/02/2018
* Description		: Interrupt handlers
********************************************************************/

// Includes
#include "stm32f4xx_it.h"
#include "main.h"
#include "gpio.h"
#include "spi.h"
#include "tim.h"

// Private macro
// Private variables
extern volatile uint32_t timer_ms;
// Private function prototypes
// Private functions


/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f40xx.s/startup_stm32f427x.s).                         */
/******************************************************************************/
void TIM3_IRQHandler(void)
{
        	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
        	{
        		GPIO_ToggleBits(_Diode_GPIO, _Diode_Inf1);
        		GPIO_ToggleBits(_Diode_GPIO, _Diode_Inf2);
        		GPIO_ToggleBits(_Diode_GPIO,_Diode_Err);
			}
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
}

/**************************** SysTick_Handler ******************************
* Function Name  : SysTick_Handler
* Description    : SysTick handler for dummy delay function
* Input          : None
* Output         : None
* Return         : None
********************************************************************/
void SysTick_Handler()
{
 if (timer_ms) {
 timer_ms--;
 }
}
/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}



/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}



/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
