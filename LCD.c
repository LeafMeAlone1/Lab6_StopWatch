#include "LCD.h"
#include "stdio.h"



void delay_ms(unsigned int ms) {
	unsigned int i, j;
	for (i = 0; i < ms; i++)
	{
		for (j = 0; j < 16000; j++);
	}
	
}

void delay_us(unsigned int us) {
	unsigned int i, j;
	for (i = 0; i < us; i++)
	{
		for (j = 0; j < 16; j++);	}
	
}



void LCD_WriteCom(unsigned char com) {
		
	
	 
	GPIOB->ODR &= 0xFFFFFFFD;									//set RS to 0
	
	unsigned char com1, com2;
	com1= (com&0xf0);
	com2= (com&0x0f)<<4;
	GPIOB->ODR &= 0xFFFFFFFB;									// set E = 0;
	
	// send upper command data (com1)
	GPIOB->ODR &= 0xFFFFFF87;
	GPIOB->ODR |= (com1>>1);
	
	Pulse();
	
	// send lower command data (com2)
	GPIOB->ODR &= 0xFFFFFF87;
	GPIOB->ODR |= (com2>>1);
	
	Pulse();
	
	
	
									
}
void LCD_WriteData(unsigned char dat) {
	GPIOB->ODR |= 0x00000002;	//Set RS back to 1
	unsigned char dat1, dat2;
	dat1= (dat&0xf0);
	dat2= (dat&0x0f)<<4;
	GPIOB->ODR &= 0xFFFFFFFB;									// set E = 0;
	
	
	// send upper info data (dat1)
	GPIOB->ODR &= 0xFFFFFF87;
	GPIOB->ODR |= (dat1>>1);
	
	
	Pulse();
	
	
	// send lower info data (dat2)
	GPIOB->ODR &= 0xFFFFFF87;
	GPIOB->ODR |= (dat2>>1);
	
	
	Pulse();
}
void LCD_Init(void){

	
	// Enable the HSI clock
	RCC ->CR  |= RCC_CR_HSION;
	//check when clock is ready
	while((RCC->CR & RCC_CR_HSIRDY) == 0);
	
	//set GPIOB clock on
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	
	// switch to HSI clock
	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_HSI;

	//make sure we are using HSI clock 
	while((RCC->CFGR & RCC_CFGR_SWS_HSI) == 0);
	
	//Set    PB1 to PB6 as outputs
	GPIOB->MODER &= 0xFFFFC553;
	GPIOB->MODER |= 0x00001554;	
	
	
	// Display initialization
	LCD_WriteCom(0x28);  //put into 4-bit mode
	LCD_WriteCom(0x0c); //display switch
	LCD_WriteCom(0x06); // input mode Style setting
	LCD_WriteCom(0x01); //clear
	LCD_WriteCom(0x40); // reset adress to start
	
	
	delay_ms(50);

}void LCD_Clear(void){
	LCD_WriteCom(0x01); //clear
	delay_ms(1);
}





void LCD_DisplayString(unsigned char *ptr) {
	unsigned char i;
	
		for (i=0; ptr[i]!= '\0'; i++)
		{
			LCD_WriteData(ptr[i]);
		}
	
	
}

void LCD_DisplayTime(unsigned int min, unsigned int sec, unsigned int microsec)
{
	char TimeString[20]; //helps conver numbers to string
	
	//write on first line
	LCD_WriteCom(0x40);
	//LCD_WriteCom(0x80);
	
	
	//display min
	sprintf(TimeString, "%02u:%02u:%01u", min,sec,microsec); // Convert integer to string
	LCD_DisplayString((unsigned char*) TimeString );
}

void Pulse()
{
	GPIOB->ODR |= 0x00000004;									//set E=1;
	delay_us(40);
	GPIOB->ODR &= 0xFFFFFFFB;									////set E=0;
	delay_us(40);
}


	
	/*
uint32_t getPin(GPIO_TypeDef * port, uint32_t pin){
	uint32_t temp >> pin;					//Shift the value over by the value of that pin
	temp &= 0x00000001;						//mask to only read that pin
	return temp;									//return the value of that pin
	
}



void setPin(GPIO_TypeDef * port, uint32_t pin, uint32_t value){
	uint32_t temp = port->ODR;
	uint32_t mask = 1 << pin;
	if (value){										//if we're setting it too high
		temp 1 = mask;
	}
	else{													//if we're setting to to low
		temp &= ~mask;
	}
	port->ODR = temp;
}
*/
