#include "Velocidad.h"

Velocidad::Velocidad(const String& nombre , const String& unidad ,int pint1) {
  this->nombre = nombre;
  this->unidad = unidad;
  this->pint1 = pint1;
  pinMode(pint1, INPUT);
}

float Velocidad::medir(){
    int estadoSensor = digitalRead(pint1);
    unsigned long tiempoAnterior = 0;
    unsigned long tiempoActual = 0;
    unsigned long tiempoDiferencial = 0;
    int rpm;

    if (estadoSensor == HIGH){
    tiempoActual = micros();
    tiempoDiferencial = tiempoActual - tiempoAnterior;
    rpm = 60000000 / tiempoDiferencial; 
    tiempoAnterior = tiempoActual;
    return rpm;
    }
    else{
        return 0.0;
    }
}