#include <avr/io.h>

void transmitChar(char ch)
{
	while (!(UCSR0A & 0b00100000));
	UDR0 = ch;
}

int main(void)
{
	UBRR0 = 16000000 / (16 * 9600UL) - 1;
	UCSRB = UCSRB & 0b11111111;
	UCSRC = UCSRC | 0b00000110;
	UCSRB = UCSRB | 0b00011000;

	while (1)
	{
		while (!(UCSR0A & 0b10000000));
		char ch = UDR0;
		transmitChar('[');
		transmitChar(ch);
		transmitChar(']');
	}

	return 0;
}
