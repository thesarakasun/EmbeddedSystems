#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    DDRB=0b00000001;
    while (1) 
    {
		PORTB=0b00000001;
		_delay_ms(200);
		PORTB=0b00000000;
		_delay_ms(200);
    }
	return 0;
}

