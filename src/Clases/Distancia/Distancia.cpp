#include "Distancia.h"

Distancia::Distancia(const String& nombre, const String& unidad ,int trigPin, int echoPin) {
  this->nombre = nombre;
  this->unidad = unidad;
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  medir();
};

float Distancia::medir(){
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    float duration = pulseIn(echoPin, HIGH);
    float distance = duration * 0.034 / 2;
    return distance;
}