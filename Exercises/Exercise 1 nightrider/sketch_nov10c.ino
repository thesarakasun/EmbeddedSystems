#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


void forward();
void backward();
const int del = 500;

int main(void)
{
	DDRB = DDRB | 0b00011111;
    PORTB =  0b00000001;

	
    while (1) 
    {
	
        forward();
        backward();
    }
}

void forward(){
    while(!(PORTB & (1<<4))){
        _delay_ms(del);
        PORTB = PORTB * 2 ;
    }


}

void backward(){
 while(!(PORTB & (1<<0))){
        _delay_ms(del);
        PORTB = PORTB / 2 ;
    }

}