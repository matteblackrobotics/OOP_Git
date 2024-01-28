// map pot to servo and led
// have different modes
// be able to read the state of the system....mode, input, pixel, deg

#include <Arduino.h>
#include "State.h"
#include "Pot.h"
#include "MBR_led.h"
#include "MBR_Servo.h"
#include "Mode.h"
#include "SerialIn.h"

// central source of truth
// pot stuff
float pot_input;

//LED stuff
MBR_led ring1(24, 2);
float pixelLast;
float brightness;

//Servo stuff
float degree_servo;
MBR_Servo servo1(3, 0.0, 100.0, 500.0, 2500.0);


void setup() {
 Serial.begin(115200);
 //ring1.setupLED();
 // printSystemConfig()
}

void loop(){
  checkSerialIn();
  checkMode();
  pot_input = pot1.readNorm();

  switch(mode){
    case 1:
      ring1.profile1();
      ring1.Single(pot_input);
    break;

    case 2:
      ring1.profile1();
      ring1.Bar(pot_input);  
    break;

    case 3:
      ring1.profile2();
      ring1.Bar(pot_input);   // no argument
      servo1.moveServo(pot_input); // specific argument
    break;
    case 4:
    break;
  }
  printSerial(); 
}

void printVitals(){
    Serial.print(" mode: ");
    Serial.print(mode);
    Serial.print(" pot_input: ");
    Serial.print(pot_input);
}


// centralized way
void printSerial(){
  printVitals();
  switch(mode){
    case 1: 
      ring1.printProfile1();
      ring1.printSingle();
    break;

    case 2: 
      ring1.printProfile1();
      ring1.printBar();
    break;

    case 3:
      ring1.printProfile2();
      ring1.printBar();
      servo1.printServo();
    break;
  }
  Serial.println();
}