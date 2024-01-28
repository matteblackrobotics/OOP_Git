#include "MBR_Servo.h"

MBR_Servo::MBR_Servo(int servoPin, float degMin, float degMax, float msMin, float msMax){
    _servoPin = servoPin;
    _degMin = degMin;
    _degMax = degMax;
    _msMin = msMin;
    _msMax = msMax;
    _servo1.attach(_servoPin, _msMin, _msMax);
}

void MBR_Servo::moveServo(float _input){
    _deg = map(_input, 0.0, 100.0, _degMin, _degMax);
    _servo1.write(_deg);
}

void MBR_Servo::printServo(){
    Serial.print(" deg: ");
    Serial.print(_deg);
}
