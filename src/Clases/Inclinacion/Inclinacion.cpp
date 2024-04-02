#include <Arduino.h>
#include "Inclinacion.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"


Inclinacion::Inclinacion(const String& nombre, int pinA1, int pinA2, int pinInt) {
  this->nombre = nombre;
  this->pinA1 = pinA1;
  this->pinA2 = pinA2;
  this->pinInt = pinInt;
  setupSensor();
  medir();
}
void Inclinacion::setupSensor(){
  Wire.begin();
  mpuSensor.initialize();
}

float Inclinacion::medir(){
  mpuSensor.getAcceleration(&ax, &ay, &az);
  float accel_ang_x = atan(ax / sqrt(pow(ay, 2) + pow(az, 2))) * (180.0 / 3.14);  
  
  if (accel_ang_x > 40 || accel_ang_x < -40) {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  } 
  return accel_ang_x;
}