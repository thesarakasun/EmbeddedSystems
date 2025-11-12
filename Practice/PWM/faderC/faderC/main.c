#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    DDRD = DDRD | 0b00100000 ;
	TCCR0B = TCCR0B & 0b11110111;
	TCCR0A = TCCR0A | 0b00000011  ;
	TCCR0A = (TCCR0A & 0b11101111) | 0b00100000 ;
	TCCR0B = (TCCR0B & 0b1111011) | 0b00000011 ;
	
    while (1) 
    {
		for (int Pw=255; Pw>=0; Pw-=10){
			OCR0B= Pw;
			_delay_ms(50);
		}
		
		
    }
	return 0;
}

