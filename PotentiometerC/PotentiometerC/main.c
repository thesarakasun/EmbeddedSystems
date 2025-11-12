// voltMeterC.c
#include <avr/io.h>

int main(void)
{
    DDRB = DDRB | 0b00001111;
    DDRC = DDRC & 0b11111110;

    ADMUX = ((ADMUX & 0b01111111) | 0b01000000)& 0b11111000;
    //ADMUX = ADMUX & 0b11111000;
    ADCSRA = ADCSRA | 0b00000111;
    ADCSRA = ADCSRA | 0b10000000;

    while (1)
    {
        ADCSRA = ADCSRA | 0b01000000;         // Start conversion
        while (ADCSRA & 0b01000000);          // Wait for conversion to finish

        float vIn = ADCW * 5.0 / 1024;        // Convert ADC value to voltage
        PORTB = PORTB & 0b11110000;           // Clear lower 4 bits

        if (vIn > 4)
            PORTB = PORTB | 0b00001111;
        else if (vIn > 3)
            PORTB = PORTB | 0b00000111;
        else if (vIn > 2)
            PORTB = PORTB | 0b00000011;
        else if (vIn > 1)
            PORTB = PORTB | 0b00000001;
        else if (vIn > 0)
            PORTB = PORTB | 0b00000001;
    }

    return 0;
}
