#ifndef LED_h
#define LED_h

#include <Adafruit_NeoPixel.h>

#define pixelCount 24
#define ringPin 2

Adafruit_NeoPixel ring1 = Adafruit_NeoPixel(pixelCount, ringPin, NEO_GRB + NEO_KHZ800);

int pixelLast;
float brightness = 1.0;
const int brightnessMin = 10;
const int brightnessMax = 100;

float r = 10.0;
float g = 10.0;
float b = 10.0;

void setupLED(){
    ring1.begin();
    ring1.show();
    ring1.setBrightness(50);
}


void ledProfile1(){
    r = 50.0;
    g = 10.0;
    b = 20.0;
}

void ledProfile2(){
    r = 50.0;
    g = 200.0;
    b = 50.0;
}

void ledBar(){
    ring1.clear();
    pixelLast = map(input, 0.0, 99.0, 0, pixelCount); //[0:24] pixles, includes all off
    brightness = map(input, 0.0, 100.0, brightnessMin, brightnessMax)/100.0; // mapping doesn't map floats
    if(pixelLast == 0){
        ring1.clear();
    }
    else{
        for(int i=0; i<pixelLast; i++){
            float R = r * brightness;
            float G = g * brightness;
            float B = b * brightness;
            ring1.setPixelColor(i,R,G,B);
        }
    }
    ring1.show(); 
}


void ledSingle(){
    ring1.clear();
    pixelLast = map(input, 0.0, 99.0, 0, pixelCount); //[0:24] pixles, includes all off
    if(pixelLast == 0){
        ring1.clear();
    }
    else{
        int i = pixelLast-1;
        ring1.setPixelColor(i,r,g,b);
    }
    ring1.show();
}


void printledBar(){
    // if(serialOutState == 1){}
    Serial.print(" pixelLast: ");
    Serial.print(pixelLast);
    Serial.print(" brightness: ");
    Serial.print(brightness);
}

void printledSingle(){
    // if(serialOutState == 1){}
    Serial.print(" pixelLast: ");
    Serial.print(pixelLast);
}

void printledProfile1(){
    // if(serialOutState == 1){}
    Serial.print(" ledProfile1: ");
    Serial.print((int) r); Serial.print(".");
    Serial.print((int) g); Serial.print(".");
    Serial.print((int) b);
}

void printledProfile2(){
    // if(serialOutState == 1){}
    Serial.print(" ledProfile2: ");
    Serial.print((int) r); Serial.print(".");
    Serial.print((int) g); Serial.print(".");
    Serial.print((int) b);
}



#endif