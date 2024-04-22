#include "Alarma.h"

Alarma::Alarma(const String& nombre, const String& unidad ,int pin) {
  this->nombre = nombre;
  this->unidad = unidad;
  this->pin = pin;
  medir();
};

float Alarma::medir(){
    return digitalRead(pin);
}