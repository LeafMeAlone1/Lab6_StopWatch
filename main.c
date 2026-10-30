#include "stm32l476xx.h"
#include "LCD.h"
#include "SYSTICKs.h"
void SysTick_Initialize (uint32_t ticks);
void SysTick_Handler (void);

int main(void){
	//SET UP
	LCD_Init();
	LCD_Clear();
	
	LCD_WriteData('C');
	LCD_DisplayString( (unsigned char*)"ECE");
	LCD_DisplayTime(10,33,1);
	
	//set up sysTick 	
	SysTick_Initialize(1600000);
	
	//implement sysTick 
  //	 SysTick_Handler();
 
	 
	//Setup external Interupts
	EXTI_Init();
	
	//Implement External Interupts
  //EXTI0_IRQHandler();
	//EXTI1_IRQHandler();
	//EXTI2_IRQHandler();
	
		
		
		
	//Coderun code
	while(1)
	{
		
	}

}




	
	
