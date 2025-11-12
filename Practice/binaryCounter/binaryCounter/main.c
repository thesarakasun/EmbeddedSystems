#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRB = DDRB | 0b00000111; 
	int count = 0;

	while (1)
	{
		PORTB = (PORTB & 0b11111000) | (count & 0b00000111);
		_delay_ms(1000);
		count++;
		if (count > 7) count = 0;
	}
}
