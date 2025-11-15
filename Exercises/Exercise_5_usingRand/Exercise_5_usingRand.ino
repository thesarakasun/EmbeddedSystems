#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

#define F_CPU 16000000UL

int main(void) {
    // LEDs: PB0 = Red, PB1 = Orange, PB2 = Green, PB3 = Blue (Signal)
    DDRB |= 0b00001111;      // LEDs OUTPUT
    DDRD &= 0b11110011;      // PD2 = Ready, PD3 = React INPUT
    PORTD |= 0b00001100;     // Pull-ups on switches

    // Timer0: for seeding RNG
    TCCR0B = 0b00000101;     // Prescaler 1024

    // Timer1: 16-bit timer for reaction measurement
    TCCR1B = 0b00000101;     // Prescaler 1024

    while (1) {
        // Wait for "Ready" button (PD2)
        while (PIND & 0b00000100); // PD2 active LOW
        _delay_ms(50); // simple debounce

        // Turn off all LEDs
        PORTB &= 0b11110000;

        // Generate random delay 1–10 seconds
        unsigned char seed = TCNT0;
        srand(seed);
        int delayTimeMs = (rand() % 9000) + 1000; // 1000–10000 ms

        // Delay loop
        for (int t = 0; t < delayTimeMs; t += 10) {
            _delay_ms(10);
        }

        // Turn on Blue LED (signal)
        PORTB |= 0b00001000;

        // Start Timer1 for reaction measurement
        TCNT1 = 0;
        TIFR1 |= (1 << TOV1);

        // Wait for "React" button (PD3)
        while (PIND & 0b00001000); // PD3 active LOW
        _delay_ms(50); // simple debounce

        // Stop timer1
        unsigned int count = TCNT1;

        // Turn off Blue LED
        PORTB &= 0b11110111;

        // Convert count to ms
        float reactionTimeMs = (float)count * 1024.0 / (F_CPU / 1000.0); 

        // Show result on LEDs
        if (reactionTimeMs < 1000) {
            PORTB |= 0b00000100; // Green
        } else if (reactionTimeMs < 2000) {
            PORTB |= 0b00000010; // red
        } else {
            PORTB |= 0b00000001; // blue
        }

        // Hold result for 1 second
        _delay_ms(1000);

        // Turn off result LEDs
        PORTB &= 0b11110000;
    }
    return 0;
}
