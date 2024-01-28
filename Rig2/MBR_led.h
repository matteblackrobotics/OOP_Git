#ifndef LED_h
#define LED_h

#include <Adafruit_NeoPixel.h>

class MBR_led{
    public:
        MBR_led(int pixelCount, int pinLED);
        int getPixelLast();
        void setupLED();
        void profile1();
        void profile2();
        void Bar(float _input);
        void Single(float _input);
        void printBar();
        void printSingle();
        void printProfile1();
        void printProfile2();

    private:
        int _pixelCount;
        int _pinLED;

        Adafruit_NeoPixel _ring1;

        int _pixelLast;
        float _brightness = 1.0;
        const int _brightnessMin = 10;
        const int _brightnessMax = 100;

        float _r = 10.0;
        float _g = 10.0;
        float _b = 10.0;
};

#endif