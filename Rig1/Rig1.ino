// map pot to servo and led
// have different modes
// be able to read the state of the system....mode, input, pixel, deg


#include <Arduino.h>
#include "State.h"
#include "Pot.h"
#include "LED.h"
#include "ServoMotor.h"
#include "Mode.h"
#include "SerialIn.h"

//

void setup() 
{
 Serial.begin(115200);
 setupLED();
 setupServo();
 // printSystemConfig()
}

void loop() 
{
  checkSerialIn();
  checkMode();
  input = pot1.readNorm();
  printVitals();

  switch(mode){
    case 1:
      ledProfile1();
      ledSingle();
      printledProfile1();
      printledSingle();
    break;

    case 2:
        ledProfile1();
        ledBar();  
        printledProfile1();
        printledBar();
    break;

    case 3:
      ledProfile2();
      ledBar();   // no argument
      moveServo(input); // specific argument
      printledProfile2();
      printledBar();
      printServo();
    break;
  }
  Serial.println();  
}

void printVitals(){
    Serial.print(" mode: ");
    Serial.print(mode);
    Serial.print(" input: ");
    Serial.print(input);
}
