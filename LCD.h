#ifndef __STM32L476R_NUCLEO_LCD_H
#define __STM32L476R_NUCLEO_LCD_H

#include "stm32l476xx.h"



void delay_ms(unsigned int ms);
void LCD_WriteCom(unsigned char com);
void LCD_WriteData(unsigned char dat);
void LCD_DisplayString(unsigned char *ptr);
void LCD_DisplayTime(unsigned int min, unsigned int sec, unsigned int microsec);

void LCD_Init(void);
void LCD_Clear(void);
void Pulse(void);

#endif


