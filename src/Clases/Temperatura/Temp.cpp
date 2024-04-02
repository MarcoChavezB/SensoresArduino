#include "Temp.h"

Temp::Temp(const String& nombre, const String& unidad ,int pin1) {
  this->nombre = nombre;
  this->unidad = unidad;
  this->pin1 = pin1;
}

float Temp::medir(){
  int valorSensor = analogRead(pin1);
  float temperaturaCelsius = (valorSensor * 5.0 / 1023.0) * 100.0;
  return temperaturaCelsius;
}