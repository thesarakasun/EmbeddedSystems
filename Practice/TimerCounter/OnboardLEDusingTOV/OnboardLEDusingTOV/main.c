/*
 * OnboardLEDusingTOV.c
 *
 * Created: 11/3/2025 1:09:51 PM
 * Author : Thesara
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB = DDRB | 0b00000001 ;
	DDRD = DDRD & 0b11101111;
	PORTD = PORTD | 0b00010000;
	TCCR0B = TCCR0B | 0b00000110 ;
	TCNT0 = 250;
	
    while (1) 
    {
		if(TIFR0 & 0b00000001){
			PORTB = PORTB ^ 0b00000001 ;
			TCNT0 = 250;
			TIFR0 = TIFR0 | 0b00000001;
		}
		
    }
}

