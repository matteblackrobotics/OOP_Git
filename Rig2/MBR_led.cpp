#include "MBR_led.h"

MBR_led::MBR_led(int pixelCount, int pinLED){
    _pixelCount = pixelCount;
    _pinLED = pinLED;
    Adafruit_NeoPixel _ring1 = Adafruit_NeoPixel(_pixelCount, _pinLED, NEO_GRB + NEO_KHZ800);
    _ring1.begin();
    _ring1.clear();
    _ring1.show();
}

int MBR_led::getPixelLast(){
    return _pixelLast;
}

void MBR_led::setupLED(){
    _ring1.begin();
    _ring1.show();
    _ring1.setBrightness(50);
}

void MBR_led::profile1(){
    _r = 50.0;
    _g = 10.0;
    _b = 20.0;
}

void MBR_led::profile2(){
    _r = 50.0;
    _g = 200.0;
    _b = 50.0;
}

void MBR_led::Bar(float _input){
    _ring1.clear();
    _pixelLast = map(_input, 0.0, 99.0, 0, _pixelCount); //[0:24] pixles, includes all off
    _brightness = map(_input, 0.0, 100.0, _brightnessMin, _brightnessMax)/100.0; // mapping doesn't map floats
    if(_pixelLast == 0){
        _ring1.clear();
    }
    else{
        for(int i=0; i<_pixelLast; i++){
            float _R = _r * _brightness;
            float _G = _g * _brightness;
            float _B = _b * _brightness;
            _ring1.setPixelColor(i,_R,_G,_B);
        }
    }
    _ring1.show(); 
}


void MBR_led::Single(float _input){
    _ring1.clear();
    _pixelLast = map(_input, 0.0, 99.0, 0, _pixelCount); //[0:24] pixles, includes all off
    if(_pixelLast == 0){
        _ring1.clear();
    }
    else{
        int i = _pixelLast-1;
        _ring1.setPixelColor(i,_r,_g,_b);
    }
    _ring1.show();
}


void MBR_led::printBar(){
    // if(serialOutState == 1){}
    Serial.print(" pixelLast: ");
    Serial.print(_pixelLast);
    Serial.print(" brightness: ");
    Serial.print(_brightness);
}

void MBR_led::printSingle(){
    // if(serialOutState == 1){}
    Serial.print(" pixelLast: ");
    Serial.print(_pixelLast);
}

void MBR_led::printProfile1(){
    // if(serialOutState == 1){}
    Serial.print(" ledProfile1: ");
    Serial.print((int) _r); Serial.print(".");
    Serial.print((int) _g); Serial.print(".");
    Serial.print((int) _b);
}

void MBR_led::printProfile2(){
    // if(serialOutState == 1){}
    Serial.print(" ledProfile2: ");
    Serial.print((int) _r); Serial.print(".");
    Serial.print((int) _g); Serial.print(".");
    Serial.print((int) _b);
}