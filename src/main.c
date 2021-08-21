#include <avr/io.h>
#include <util/delay.h>

#define INPUT 0
#define OUTPUT 1

#define LOW 0 
#define HIGH 1

#define PIN_LED PB0

void init();
void toggleLED();
void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);

int main() {
  init();
  while (1) { //loop forever
    digitalWrite(PIN_LED, HIGH);
    _delay_ms(500);
    digitalWrite(PIN_LED, LOW);
    _delay_ms(500);
  }

  return 0;
}


void init() {
  pinMode(0, OUTPUT);
}

void toggleLED() {
  if (PORTB & 0x01) {
    PORTB &= ~(0x01);
  }
  else {
    PORTB |= 0x01;
  }
}

void pinMode(uint8_t pin, uint8_t inOut) {
  if (pin > 5) return; //Attiny only has pins 1 to 5

  if (!inOut) DDRB &= ~(0x01 << pin);
  else DDRB |= (0x01 << pin);
}

void digitalWrite(uint8_t pin, uint8_t level) {
  if (pin > 5) return; //Attiny only has pins 1 to 5

  if (!level) PORTB &= ~(0x01 << pin);
  else PORTB |= (0x01 << pin);
}