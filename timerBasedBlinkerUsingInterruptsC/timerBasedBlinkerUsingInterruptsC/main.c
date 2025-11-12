#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB = DDRB | 0b00100000;
	TCCR1B = TCCR1B | 0b00000011;
	TCNT1 = 15536;
	TIMSK1 = TIMSK1 | 0b00000001;
	sei();
	while (1)
	{
	}
	return 0;
}

ISR(TIMER1_OVF_vect)
{
	PORTB = PORTB ^ 0b00100000;
	TCNT1 = 15536;
}
