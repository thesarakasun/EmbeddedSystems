/*
 * DelayLEDwithTimers.c
 *
 * Created: 11/15/2025 4:11:11 PM
 * Author : Thesara
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRB = DDRB | (1<<DDB0);
	TCCR1B = (TCCR1B & 0b11111100) | (0b00000100);
	TIMSK1 = TIMSK1 | (1<<TOIE1) ;
	sei();
	TCNT1 = 34286; 
    while (1) 
    {
		
    }
}

ISR(TIMER1_OVF_vect){
	
	PORTB = PORTB ^ 0b00000001;
	TCNT1 = 34286;
	
}

