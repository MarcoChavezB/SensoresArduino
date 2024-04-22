#include <Arduino.h>
#include "Clases/Distancia/Distancia.h"
#include "Clases/GPS/GPS.h"
#include "Clases/Inclinacion/Inclinacion.h"
#include "Clases/Luz/Luz.h"
#include "Clases/Peso/Peso.h"
#include "Clases/Velocidad/Velocidad.h"
#include "Clases/Comunicacion.h"
#include "Clases/Temperatura/Temp.h"
#include "Clases/Alarma/Alarma.h"

// Modelo base de cada sensor
struct SensorStruct
{
    String nombre;
    String unidad;
    int pin1;
    int pin2;
    int pin3;
};

SensorStruct sensores[] = {
    {"Peso", "gr", 2, 3},      //* Sensor de Peso (gramos)
    {"Gps", "latlong", 6, 7},  // Sensor GPS (sin unidad específica)
    {"Incli", "grd", 4, 5, 2}, //* Sensor de Inclinación (sda: A4, scl: A5, D5) (grados)
    {"Vel", "rpm", 6},    // Sensor de Velocidad (metros por segundo)
    {"Temp", "C", 5},           // Sensor de Temperatura (grados Celsius)
    // sensores no trabajados en python
    {"Dist", "cm", 3, 4},      // * Sensor de Distancia (trig, echo) (centímetros)
    {"Luz", "lux", A0},        // Sensor de Luz (lux) (A0 -)(vcc center) )(S - GND)
    {"Alar", "db", 11}       // Sensor de Alarma (D11)   

};

void setup()
{
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    Serial.begin(19200);
}

void loop()
{
    //   Peso peso(sensores[0].nombre, sensores[0].unidad , sensores[0].pin1, sensores[0].pin2);
    //GPS gps(sensores[2].nombre, sensores[2].unidad, sensores[2].pin1, sensores[2].pin2);

    Alarma alarma(sensores[7].nombre, sensores[7].unidad, sensores[7].pin1);
    Distancia distancia(sensores[5].nombre, sensores[5].unidad, sensores[5].pin1, sensores[5].pin2);
    Inclinacion inclinacion(sensores[2].nombre, sensores[2].unidad, sensores[2].pin1, sensores[2].pin2, sensores[2].pin3);
    Luz luz(sensores[6].nombre, sensores[6].unidad, sensores[6].pin1);
    Temp temperatura(sensores[4].nombre, sensores[4].unidad, sensores[4].pin1);
    Velocidad velocidad(sensores[3].nombre, sensores[3].unidad, sensores[3].pin1);

    Sensor *sensoresObjetos[] = {&distancia, &inclinacion, &temperatura, &luz, &alarma, &velocidad};
    

    Comunicacion comunicacion;
    const int Nsensores = sizeof(sensoresObjetos) / sizeof(sensoresObjetos[0]);
    for (int i = 0; i < Nsensores; i++)
    {
        comunicacion.medirYSerializar(sensoresObjetos[i], i);
    }
    delay(500);
}
