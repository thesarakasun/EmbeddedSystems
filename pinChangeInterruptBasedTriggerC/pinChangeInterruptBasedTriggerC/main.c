#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB = DDRB | 0b00100001;
	DDRD = DDRD & 0b11111011;
	PORTD = PORTD | 0b00000100;
	PCICR = PCICR | 0b00000100;
	PCMSK2 = PCMSK2 | 0b00000100;
	sei();

	while(1)
	{
		PORTB = PORTB ^ 0b00100000;
		_delay_ms(2000);
	}
	return 0;
}

ISR(PCINT2_vect)
{
	if ((PIND & 0b00000100) == 0)
	PORTB = PORTB ^ 0b00000001;
}
