#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Global variables
volatile uint8_t ClickCount = 0;
volatile uint8_t display = 0;

int main(void) {
    // LEDs PB0-PB2 as outputs
    DDRB = 0b00000111;
    PORTB = 0b00000000;

    // Buttons PD4 and PD5 as inputs with pull-ups
    DDRD = 0b11001111;   // PD4 and PD5 inputs
    PORTD = 0b00110000;  // pull-ups enabled on PD4 and PD5

    // Enable pin change interrupt for PD4 and PD5
    PCICR = 0b00000100;   // Enable PCINT[23:16] group
    PCMSK2 = 0b00110000;  // Enable PCINT20 (PD4) & PCINT21 (PD5)
    sei();                // Enable global interrupts

    while (1) {
        if (display) {
            PORTB = ClickCount & 0b00000111;
        } else {
            PORTB = 0b00000000;
        }
    }
}

// Pin change interrupt for PD4 and PD5
ISR(PCINT2_vect) {
    

    // Count button PD4
    if ((PIND & 0b00010000) == 0 && !display) {
        ClickCount++;
        if (ClickCount > 7) ClickCount = 0;
        while ((PIND & 0b00010000) == 0);
        _delay_ms(50);
    }

    // Display toggle PD5
    if ((PIND & 0b00100000) == 0) {
        if (display) {
            display = 0;
            ClickCount = 0;
        } else {
            display = 1;
        }
        while ((PIND & 0b00100000) == 0);
        _delay_ms(50);
    }
}
