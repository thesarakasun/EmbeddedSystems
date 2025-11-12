#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
    DDRB = DDRB | 0b00000001;
    DDRC = DDRC & 0b11111110;

    ADMUX = (ADMUX & 0b01111111) | 0b01000000;
    ADMUX = ADMUX & 0b11111000;
    ADCSRA = ADCSRA | 0b00000111;
    ADCSRA = ADCSRA | 0b10000000;
    ADCSRA = ADCSRA | 0b00001000;

    sei();

    ADCSRA = ADCSRA | 0b01000000;

    while (1) {
    }
    
    return 0;
}

ISR(ADC_vect) {
    float vIn = ADCW * 5.0 / 1024;

    if (vIn > 4.9) {
        PORTB = PORTB | 0b00000001;
    } else {
        PORTB = PORTB & 0b11111110;
    }

    ADCSRA = ADCSRA | 0b01000000;
}
