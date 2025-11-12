#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB = DDRB | 0b00100000;
	DDRD = DDRD & 0b11101111;
	PORTD = PORTD | 0b00010000;
	TCCR0B = TCCR0B | 0b00000110;
	TCNT0 = 251;
	TIMSK0 = TIMSK0 | 0b00000001;
	sei();
	while (1)
	{
	}
	return 0;
}

ISR(TIMER0_OVF_vect)
{
	PORTB = PORTB ^ 0b00100000;
	TCNT0 = 251;
}
