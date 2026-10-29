#ifndef __STM32L476R_NUCLEO_SYSTICS_H
#define __STM32L476R_NUCLEO_SYSTICS_H

#include "stm32l476xx.h"
#include "LCD.h"



void SysTick_Initialize (uint32_t ticks);
void SysTick_Handler (void);
void EXTI_Init(void);
void EXTI_IRQHandler(void);

#endif