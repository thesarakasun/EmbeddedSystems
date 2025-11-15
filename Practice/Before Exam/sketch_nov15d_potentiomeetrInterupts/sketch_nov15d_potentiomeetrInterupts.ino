#include <avr/io.h>
#include <avr/interrupt.h>

ISR(ADC_vect) {

    uint16_t adcValue = ADCW;
    float vIn = adcValue * 5.0 / 1024.0;

    PORTB &= 0b11100000;     // clear PB0–PB4

    if (vIn > 4.0)
        PORTB |= 0b00011111;
    else if (vIn > 3.0)
        PORTB |= 0b00001111;
    else if (vIn > 2.0)
        PORTB |= 0b00000111;
    else if (vIn > 1.0)
        PORTB |= 0b00000011;
    else if (vIn > 0.1)
        PORTB |= 0b00000001;

    ADCSRA |= 0b01000000;    // start next conversion
}

int main(void) {

    DDRB |= 0b00011111;
    DDRC &= 0b11111110;

    ADMUX  = 0b01000000;     // AVcc, ADC0
    ADCSRA = 0b10001111;     // enable ADC + interrupt + prescaler 128

    sei();
    ADCSRA |= 0b01000000;

    while(1);
}
