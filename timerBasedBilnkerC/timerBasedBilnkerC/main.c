// timerBasedBlinkerC.c

#include <avr/io.h>

int main(void)
{
	DDRB = DDRB | 0b00100000;
	TCCR1B = TCCR1B | 0b00000011;
	TCNT1 = 15536;
	while (1)
	{
		if (TIFR1 & 0b00000001)
		{
			PORTB = PORTB ^ 0b00100000;
			TCNT1 = 15536;
			TIFR1 = TIFR1 | 0b00000001;
		}
	}
	return 0;
}
