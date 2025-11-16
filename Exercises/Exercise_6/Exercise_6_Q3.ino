#include <avr/io.h>
#include <avr/interrupt.h>

volatile int top = 0;

int main(void) {
  DDRD = DDRD | 0b01000000;                   // Output
  DDRC = DDRC & 0b11111110;                   // Input A0
  ADMUX = ADMUX & 0b11111000;                 // ADC Channel
  ADMUX = (ADMUX & 0b11111101) | 0b00000001;  // AVCC
  ADCSRA = ADCSRA | 0b10001000;

  TCCR0A = TCCR0A | 0b00000011;  // WGM
  TCCR0B = TCCR0B & 0b11110111;
  TCCR0A = (TCCR0A & 0b10111111) | 0b10000000;
  TCCR0B = (TCCR0B & 0b11111000) | 0b00000011;  // frequency
  OCR0A = 0;

  sei();


  ADCSRA = ADCSRA | 0b01000000;

  while (1) {
  }
}

ISR(ADC_vect) {

  float VIn = ADCW * 5.0 / 1024;
  float temp = VIn * 100;

  if (temp >= 35) {
    OCR0A = 255;
  } else if (temp < 25) {
    OCR0A = 0;
  } else if ((temp < 35) & (temp > 25)) {
    OCR0A = (((temp - 25.0) * 255.0) / 10.0);
  }

  ADCSRA = ADCSRA | 0b01000000;
}