/*
 * OnboardLEDusingTOV.c
 *
 * Created: 11/3/2025 1:09:51 PM
 * Author : Thesara
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRB = DDRB | 0b00000001 ;
	DDRD = DDRD & 0b11101111;
	PORTD = PORTD | 0b00010000;
	TCCR0B = TCCR0B | 0b00000110 ;
	TCNT0 = 250;
	TIMSK0 = TIMSK0 | 0b00000001 ;
	sei();
	
    while (1) 
    {
		
    }
}

ISR(TIMER0_OVF_vect){
		PORTB = PORTB ^ 0b00000001 ;
		TCNT0 = 250;

}