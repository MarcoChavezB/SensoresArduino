#include <Arduino.h>
#include "Clases/Distancia/Distancia.h"
#include "Clases/GPS/GPS.h"
#include "Clases/Inclinacion/Inclinacion.h"
#include "Clases/Luz/Luz.h"
#include "Clases/Peso/Peso.h"
#include "Clases/Velocidad/Velocidad.h"
#include "Clases/Comunicacion.h"
#include "Clases/Temperatura/Temp.h"


// Modelo base de cada sensor
struct SensorStruct{
  String nombre;
  int pin1;
  int pin2;
  int pin3;
};

SensorStruct sensores[] = {
  {"Peso", 2, 3},       //* Sensor de Peso
  {"Dist", 4, 5},        // * Sensor de Distancia (trig, echo)
  {"GPS", 6, 7},         // Sensor GPS
  {"Incli", 4, 5, 2},    //* Sensor de Inclinación (A4, A5, D2)
  {"Luz", 10, 11},       // Sensor de Luz
  {"Vel", 12, 13},        // Sensor de Velocidad
  {"Temp", 2}       // Sensor de Temperatura
  };


void setup(){
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void loop(){
   Distancia distancia(sensores[1].nombre, sensores[1].pin1, sensores[1].pin2);
   Peso peso(sensores[0].nombre, sensores[0].pin1, sensores[0].pin2);
   Inclinacion inclinacion(sensores[3].nombre, sensores[3].pin1, sensores[3].pin2, sensores[3].pin3);
   Temp temperatura(sensores[6].nombre, sensores[6].pin1);

  Sensor* sensoresObjetos[] = {&distancia, &temperatura, &peso, &inclinacion};
  Comunicacion comunicacion;
  const int Nsensores = sizeof(sensoresObjetos)/sizeof(sensoresObjetos[0]);
  for (int i = 0; i < Nsensores; i++){
      comunicacion.medirYSerializar(sensoresObjetos[i], i);
  }
  
  delay(2000);
}