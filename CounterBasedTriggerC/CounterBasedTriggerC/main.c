#include <avr/io.h>

int main(void)
{
	DDRB = DDRB | 0b00100000;
	DDRD = DDRD & 0b11101111;
	PORTD = PORTD | 0b00010000;
	TCCR0B = TCCR0B | 0b00000110;
	TCNT0 = 0;
	while (1)
	{
		if (TCNT0 >= 5)
		{
			PORTB = PORTB ^ 0b00100000;
			TCNT0 = 0;
		}
	}
	return 0;
}
