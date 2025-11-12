#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>



int main(void)
{
   
   DDRB = DDRB | 0b00100001;
   DDRD = DDRD & 0b01111111;
   PORTD = PORTD | 0b10000000;
   PCICR = PCICR | 0b00000100;
   PCMSK2 = PCMSK2 | 0b10000000;
   sei();
   
    while (1) 
    {
		PORTB= PORTB ^ 0b00100000;
		_delay_ms(300);
		
    }
	
	return 0;
	
}

ISR(PCINT2_vect){
	if((PIND & 0b10000000)==0){
		PORTB= PORTB ^ 0b00000001;
	}
}

