#include "stm32f4xx.h"                  // Device header
// PD15 LD6


void delay(void);

int main(){
	
	RCC->AHB1ENR |= 1000; // enable PORTD clock  - 1bit/digit 16bits
	GPIOD->MODER |= 0x40000000; // make pin D as output
	// enable MODR for GPIOA 4bits/digit (2bits-inputs for MODR) 
	// (pin 0 to pin 15 "2bits/pin")   32 bits
	// 01 00 - 00 00 - 00 00  -  00 00 		- 00 00 -  00 00 - 00 00 - 00 00 
		
	
while(1){
	GPIOD->ODR 	|= 0x8000u; // write to GPIOA  1bit/digit  16bits (0b 1000 0000 0000 0000) (from pin 0 to 15)
	delay();

	GPIOD->ODR &=~0x8000u;
	delay();

}	
}	

void delay(void){
	volatile int i;
for(i=0;i<500000;i++);
}
