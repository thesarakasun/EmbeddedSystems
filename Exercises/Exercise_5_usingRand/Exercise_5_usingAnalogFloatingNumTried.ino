#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>

int main(void){


  DDRB |= 0b00001111;
  DDRD &= 0b11110011;
  PORTD|= 0b00001100;
  ADMUX = 0b01000000;
  ADCSRA |= 0b1000111;
  TCCR1B = (TCCR1B & 0b11111101 ) | 0b00000101;

  while(1){

    PORTB &= 0b11110000;
    while(PIND & 0b00000100);
    _delay_ms(50);
    ADCSRA |= 0b01000000;
    while(ADCSRA & 0b01000000);

    unsigned int seed= ADCW ;
    srand(seed);
    int time1 = (rand() % 9000) + 1000 ;

    for(int i=0;i<time1;i+=10)
      _delay_ms(10);

    PORTB |= 0b00001000;
    TCNT1 = 0;
    TIFR1 |= 0b00000001;

    while(PIND & 0b00001000);
    _delay_ms(50);

    PORTB &= 0b11110000;
    unsigned int time2 = TCNT1;
    float time3 = (float(time2) * 1024 *1000)/ F_CPU; 

    if(time3<1000)
      PORTB |= 0b00000001;
    else if(time3<2000)
      PORTB |= 0b00000010;
    else
      PORTB |= 0b00000100;


    _delay_ms(2000);
  






  }

}