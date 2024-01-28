#ifndef ServoMotor_h
#define ServoMotor_h

#include <Arduino.h>
#include <Servo.h>

class MBR_Servo{
  public:
    Servo _servo1;
    MBR_Servo(int servoPin, float degMin, float degMax, float msMin, float msMax);
    void moveServo(float input);
    void printServo();
    
  private:
    int _servoPin;
    float _deg;
    float _degMin;
    float _degMax;
    float _msMin;
    float _msMax;
};

#endif