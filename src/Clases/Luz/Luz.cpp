#include "Luz.h"

Luz::Luz(const String& nombre , const String& unidad ,int pin) {
  this->nombre = nombre;
  this->unidad = unidad;
  this->pin = pin;
}

float Luz::medir(){
  const int valorLuz = analogRead(pin);
  // condicion si ya esta prendido el led
  return valorLuz;
}