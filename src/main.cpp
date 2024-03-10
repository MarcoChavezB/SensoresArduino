#include <Arduino.h>
#include "Clases/Distancia/Distancia.h"
#include "Clases/GPS/GPS.h"
#include "Clases/Inclinacion/Inclinacion.h"
#include "Clases/Luz/Luz.h"
#include "Clases/Peso/Peso.h"
#include "Clases/Velocidad/Velocidad.h"
#include "Clases/Comunicacion.h"

// Modelo base de cada sensor
struct SensorStruct{
  String nombre;
  int pin1;
  int pin2;
};

SensorStruct sensores[] = {
  {"Peso", 2, 3},       // Sensor de Peso
  {"Dist", 4, 5},        // * Sensor de Distancia (trig, echo)
  {"GPS", 6, 7},         // Sensor GPS
  {"Incli", 8, 9},       // Sensor de Inclinación (MPU)
  {"Luz", 10, 11},         // Sensor de Luz
  {"Vel", 12, 13}          // Sensor de Velocidad
};


void setup(){
  Serial.begin(9600);
}
void loop(){
  Distancia distancia(sensores[1].nombre, sensores[1].pin1, sensores[1].pin2);
  Sensor* sensoresObjetos[] = {&distancia};
  Comunicacion comunicacion;
  comunicacion.medirYSerializar(sensoresObjetos[0], 1);
  delay(1000);
}