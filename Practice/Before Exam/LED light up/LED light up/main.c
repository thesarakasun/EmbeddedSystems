#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    DDRB = DDRB | (1<<DDB0);
	DDRB = DDRB | ~(1<<DDB4);
	PORTB = PORTB | (1<<PORTB4) ;
	
	
    while (1) 
    {
		PORTB = PORTB ^ (1<<PORTB0);
		if(PINB & (1<<PINB4))
			_delay_ms(500);
		else
			_delay_ms(100);
		
		
    }
}

