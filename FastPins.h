#pragma once
#include <Arduino.h>

void writeP(uint8_t pin, bool x) {  //ускоренная запись пинов
  if (x == 1) {
    if (pin < 8) PORTD |= 1 << pin;
    else if (pin < 14) PORTB |= 1 << (pin - 8);
    else if (pin < 20) PORTC |= 1 << (pin - 14);
    else return;
  }
  else {
     if (pin < 8) PORTD &= ~(1 << pin);
    else if (pin < 14) PORTB &= ~(1 << (pin - 8));
    else if (pin < 20) PORTC &= ~(1 << (pin - 14));
    else return;
  }
  
}

bool readP(uint8_t pin){ //fast pin read
    bool x;
    if (pin < 8) (x = (PIND & (1 << pin)));
    else if (pin < 14) (x = (PINB & (1 << (pin-8))));
    else if (pin < 20) (x = (PINC & (1 << (pin-14))));
    return x;
}