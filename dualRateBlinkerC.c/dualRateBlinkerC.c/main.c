// dualRateBlinkerC.c

#include <avr/io.h>
#define F_CPU 1000000UL        // define CPU clock speed for delay.h
#include <util/delay.h>

int main(void)
{
	DDRB = DDRB | 0b00100000;  // configure PB5 as an output
	DDRB = DDRB & 0b11111110;  // configure PB0 as an input
	PORTB = PORTB | 0b00000001; // pull-up PB0
	while (1)
	{
		PORTB = PORTB ^ 0b00100000; // toggle PB5
		if (PINB & 0b00000001)      // if PB0 is high
		_delay_ms(500);         // delay 500ms
		else
		_delay_ms(200);         // otherwise delay 200ms
	}
	return 0;
}
