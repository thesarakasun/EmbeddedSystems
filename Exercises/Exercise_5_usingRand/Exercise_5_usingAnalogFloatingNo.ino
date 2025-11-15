#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

#define F_CPU 16000000UL

int main(void) {
    // LEDs: PB0 = Red, PB1 = Orange, PB2 = Green, PB3 = Blue
    DDRB |= 0b00001111;      // PB0–PB3 OUTPUT
    DDRD &= 0b11110011;      // PD2 = Ready, PD3 = React INPUT
    PORTD |= 0b00001100;     // Pull-ups on PD2 & PD3

    // ADC setup for floating analog input (ADC0)
    ADMUX = 0b01000000;      // Select ADC0, AVCC as reference
    ADCSRA = 0b10000111;     // Enable ADC, prescaler 128

    // Timer1: 16-bit timer for reaction measurement
    TCCR1B = 0b00000101;     // Prescaler 1024

    while (1) {
        // Wait for "Ready" button (PD2 active LOW)
        while (PIND & 0b00000100);
        _delay_ms(50); // debounce

        // Turn off all LEDs
        PORTB &= 0b11110000;

        // ---------- Generate random delay 1–10 seconds using ADC ----------
        ADCSRA |= 0b01000000;           // Start ADC conversion (ADSC=1)
        while (ADCSRA & 0b01000000);    // Wait until conversion finishes
        unsigned int seed = ADC;        // Read ADC0
        srand(seed);                     // Seed RNG

        int delayTimeMs = (rand() % 9000) + 1000; // 1000–9999 ms

        // Delay loop (10 ms increments)
        for (int t = 0; t < delayTimeMs; t += 10) {
            _delay_ms(10);
        }

        // ---------- Signal user ----------
        PORTB |= 0b00001000; // Blue LED ON

        // Start Timer1
        TCNT1 = 0;
        TIFR1 |= 0b00000001; // Clear Timer1 overflow flag (TOV1)

        // Wait for "React" button (PD3 active LOW)
        while (PIND & 0b00001000);
        _delay_ms(50); // debounce

        // Stop Timer1
        unsigned int count = TCNT1;
        PORTB &= 0b11110111; // Blue LED OFF

        // Convert timer ticks to milliseconds
        float reactionTimeMs = ((float)count * 1024.0) * 1000 / F_CPU;

        // ---------- Display result ----------
        if (reactionTimeMs < 1000) {
            PORTB |= 0b00000100; // Green
        } else if (reactionTimeMs < 2000) {
            PORTB |= 0b00000010; // Orange
        } else {
            PORTB |= 0b00000001; // Red
        }

        _delay_ms(1000); // Hold result
        PORTB &= 0b11110000; // Turn off result LEDs
    }

    return 0;
}
