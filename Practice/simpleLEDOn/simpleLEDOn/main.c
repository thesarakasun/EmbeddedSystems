#include <avr/io.h>


int main(void)
{
    DDRB=DDRB | 0b00100000;
	PORTB=PORTB | 0b00100000;
	
    while (1) 
    {
    }
}

