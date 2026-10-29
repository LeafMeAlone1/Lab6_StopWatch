#include "stm32l476xx.h"
#include "LCD.h"
#include "SYSTICKs.h"
void SysTick_Initialize (uint32_t ticks);
void SysTick_Handler (void);

int main(void){
	//SET UP
	LCD_Init();
	LCD_Clear();
	
	LCD_WriteData('B');
	
	//set up sysTick 	
	SysTick_Initialize(60000);
	
	//implement sysTick 
	 SysTick_Handler ();
 
	 
	//Setup external Interupts
	EXTI_Init();
	
	//Implement External Interupts
  EXTI_IRQHandler();
	
		
		
		
	//Coderun code
	while(1)
	{
		
	}

}




	
	
