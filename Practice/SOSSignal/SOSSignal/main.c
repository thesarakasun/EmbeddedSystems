#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    DDRB = DDRB | 0b00000001 ;
	
	
    while (1) 
    {
		for (int i=0;i<3;i++)
		{PORTB = PORTB | 0b00000001 ;
			_delay_ms(100);
			PORTB = PORTB & 0b11111110;
			_delay_ms(100);
		}
		for (int i=0;i<3;i++)
		{PORTB = PORTB | 0b00000001 ;
			_delay_ms(200);
			PORTB = PORTB & 0b11111110;
			_delay_ms(200);
		}
    }
}

