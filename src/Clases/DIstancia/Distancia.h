#ifndef Distancia_h
#define Distancia_h
#include <Arduino.h>
#include "../src/Clases/Sensor.h"

class Distancia : public Sensor{
  public:
    int trigPin;
    int echoPin;

    Distancia(const String& nombre ,int trigPin, int echoPin){
      this->nombre = nombre;
      this->trigPin = trigPin;
      this->echoPin = echoPin;
      this->medir();
    }

    float medir() override{
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
};

#endif