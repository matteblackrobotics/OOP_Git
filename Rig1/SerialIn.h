// read serial in
// reset serial string
// check is numeric

#ifndef SerialIn_h
#define SerialIn_h

#include <Arduino.h>

String serialIn;  // string data in
float numberIn;     // float data conversion

// printSerialIn()
// checkSerialIn()
// resetSerialString()


// printSerialIn
// prints serial input
void printSerialIn(){
  Serial.print("Serial Input: ");
  Serial.println(serialIn);
}


// checkSerialIn
// when available, stores serial input as string serialIn
void checkSerialIn()
{
  if(Serial.available()) // to initiate
  {
    while(Serial.available()) // reads entire serial buffer?
    {
      serialIn = Serial.readString();  // read until timeout
      serialIn.trim();                 // remove any \r \n whitespace at the end of the String
      printSerialIn();
    }
  }
}


// resetSerialString
void resetSerialString(){
  serialIn = "null";
}


// isStringNumeric
// check if string contains only numbers one character at a time
bool isStringNumeric(String str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (!isdigit(str.charAt(i))) {
      return false; // Return false if any non-digit character is found
    }
  }
  return true; // Return true if all characters are digits
}



/*

// printCommandsSerialIn
// prints SerialIn specific commands
void printCommandsSerialIn(){
  Serial.println("SerialIn Commands:");
  Serial.println("commands = printCommands()");
  Serial.println("help = printCommands()");
  Serial.println("");
}


// setupSerialIn
// print commands and wait for ok to procceed
// do not need
void setupSerialIn()
{
  //printCommandsSerialIn();
  // ok to proceed
  if(1){
    Serial.println("type 'ok' to proceed");
    while(serialIn != "ok"){
      checkSerialIn();
    }
    resetSerialString();
  }
}



// printCommands
void printCommands(){
  printCommandsSerialIn();
  printCommandsSerialOut();
  printCommandsServo();
  //printCommandsModes(); // <<<<<<<<
  Serial.println();
}


// processSerialInSerialIn
// process serialIn specific information

// may not be needed
void processSerialInSerialIn(){
  if(serialIn == "commands" || serialIn == "help"){
    printCommands();
  }  
}

// may not be needed
// processSerialIn
// process serialIn and checks across all header cases
void processSerialIn()
{
  processSerialInSerialIn();
  processSerialInSerialOut();
  processSerialServo();
  //processSerialInModes(); // <<<<<<<<
}



// main function
void serialInManager()
{
  checkSerialIn();
  processSerialIn();
  resetSerialString();
}



*/
#endif