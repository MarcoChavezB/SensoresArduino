#include "Temp.h"

Temp::Temp(const String& nombre, const String& unidad ,int pin1) : dht(pin1, DHT11) {
  this->nombre = nombre;
  this->unidad = unidad;
  this->pin1 = pin1;
  dht.begin();
}

float Temp::medir(){
  float t = dht.readTemperature();
  return t;
}
