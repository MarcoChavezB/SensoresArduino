#ifndef MotorDirection_H
#define MotorDirection_H
#include "../src/Clases/Sensor.h"
#include <Servo.h>

class MotorDirection{
   public :
   int leftMotor;
   int rightMotor;
  Servo motor_left;
  Servo motor_right;

    MotorDirection(int leftMotor, int rightMotor);
    void go();
    void back();
    void right();
    void left();
    void stop();
    void configure();
    void leftMotorControl(int value);
    void rightMotorControl(int value);
    void listenDirection();
};


#endif