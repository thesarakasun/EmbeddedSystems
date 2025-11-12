#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRD = DDRD | 0b01000000;
	DDRB = DDRB | 0b00000010;

	TCCR0B = TCCR0B & 0b11111011;
	TCCR0A = TCCR0A | 0b00000011;
	TCCR0A = (TCCR0A & 0b00111111) | 0b10000000;
	TCCR0B = (TCCR0B & 0b11111000) | 0b00000101;

	TCCR1B = TCCR1B & 0b11111011;
	TCCR1A = TCCR1A | 0b00000011;
	TCCR1A = (TCCR1A & 0b00111111) | 0b10000000;
	TCCR1B = (TCCR1B & 0b11111000) | 0b00000011;

	while (1)
	{
		for (int pulseWidth = 0; pulseWidth <= 255; pulseWidth += 5)
		{
			OCR0A = pulseWidth;
			OCR1A = 255-pulseWidth;
			_delay_ms(40);
		}
	}

	return 0;
}
