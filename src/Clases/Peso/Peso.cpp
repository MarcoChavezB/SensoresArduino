#include "Peso.h"

Peso::Peso(const String& nombre, const String& unidad ,int pin1, int pin2) {
  this->nombre = nombre;
  this->unidad = unidad;
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->escala.begin(pin1, pin2);
}

void Peso::setupSensor(){
    escala.begin(pin1, pin2);
    escala.set_scale();
    delay(1000);
    escala.tare();
}

float Peso::medir(){
    float peso = escala.get_units();
    return peso;
}