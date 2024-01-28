#ifndef ServoMotor_h
#define ServoMotor_h

#include <Servo.h>

Servo servo1;

int deg;
int degMin = 0;
int degMax = 180;
const int servoPin = 3;

void setupServo(){
    servo1.attach(servoPin, 500, 2500);
}

void moveServo(float input)
{
  deg = map(input, 0.0, 100.0, degMin, degMax);
  servo1.write(deg);
}
#endif

void printServo(){
    Serial.print(" deg: ");
    Serial.print(deg);
}