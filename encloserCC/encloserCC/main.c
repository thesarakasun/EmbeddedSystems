#include <avr/io.h>

void transmitChar(char ch)
{
	while (!(UCSR0A & 0b00100000));
	UDR0 = ch;
}

int main(void)
{
	UBRR0 = 16000000 / (16 * 9600UL) - 1;
	UCSR0B = UCSR0B & 0b11111111;
	UCSR0C = UCSR0C | 0b00000110;
	UCSR0B = UCSR0B | 0b00011000;

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
