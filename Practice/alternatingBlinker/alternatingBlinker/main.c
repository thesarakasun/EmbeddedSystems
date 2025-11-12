#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRB = DDRB | 0b00010001 ;
	PORTB = PORTB | 0b00000001 ;
	
    while (1) 
    {
		PORTB = PORTB ^ 0b00010001 ; 
		_delay_ms(500);
		   
		
		
	}
}

