

#include <avr/io.h>
#define F_CPU 1000000UL       
#include <util/delay.h>

int main(void)
{
	DDRB = DDRB | (1<<DDB4); 
	DDRB = DDRB & ~(1<<DDB0);
	PORTB = PORTB | (1<<PORTB0;
	while (1)
	{
		PORTB = PORTB ^ (1<<PORTB4; 
		if (PINB & (1<<PINB0))  
		_delay_ms(5000);       
		else
		_delay_ms(3000);       
	}
	return 0;
}
