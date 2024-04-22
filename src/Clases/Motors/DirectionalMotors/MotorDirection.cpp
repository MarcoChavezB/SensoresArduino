#include "MotorDirection.h"
#include <Servo.h>


MotorDirection::MotorDirection(int leftMotor, int rightMotor) {
  this->leftMotor = leftMotor;
  this->rightMotor = rightMotor;
  this->configure();
}

void MotorDirection::configure(){
  this->motor_left.attach(leftMotor);
  this->motor_right.attach(rightMotor);

  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
}

void MotorDirection::leftMotorControl(int value){
  this->motor_left.write(map(value, -100, 100, 1000, 2000));
}

void MotorDirection::rightMotorControl(int value){
  this->motor_right.write(map(value, -100, 100, 1000, 2000));
}

void MotorDirection::go(){
  Serial.println("Go");
  this->leftMotorControl(100);
  this->rightMotorControl(-100);
}

void MotorDirection::back(){
  Serial.println("Back");
  this->leftMotorControl(-100);
  this->rightMotorControl(100);
}

void MotorDirection::right(){
  Serial.println("Right");
  this->leftMotorControl(100);
  this->rightMotorControl(100);
}

void MotorDirection::left(){
  Serial.println("Left");
  this->leftMotorControl(-100);
  this->rightMotorControl(-100);
}

void MotorDirection::stop(){
  Serial.println("Stop");
  this->leftMotorControl(0);
  this->rightMotorControl(0);
}

void MotorDirection::listenDirection(){
  if(Serial.available() > 0){
    char data = Serial.read();
    switch(data){
      case 'w':
        this->go();
        break;
      case 's':
        this->back();
        break;
      case 'a':
        this->left();
        break;
      case 'd':
        this->right();
        break;
      case 'x':
        this->stop();
        break;
    }
  }
}
