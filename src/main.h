/***************************** Description **************************
* File Name			: main.h
* Author			: Adam Bondyra
* Version			: V1.0.0
* Date				: 06/02/2018
* Description		: Main header
********************************************************************/

#ifndef MAIN_H_
#define MAIN_H_

////// Includes //////
#include "stm32f4xx.h"
#include "math.h"
////// Defines //////

////// Array  //////
uint16_t _MEASUREMENTS[20000];

////// GLOBAL VARIABLES //////
uint16_t freePosition; // position of array
uint8_t part_A;  // first half of measurement to send
uint8_t part_B; // second half of measurement to send

#endif /* MAIN_H_ */
