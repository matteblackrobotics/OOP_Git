#ifndef Modes_h
#define Modes_h

int mode = 1;
#include "SerialIn.h"

void checkMode(){
    if(serialIn == "1"){
        mode = 1;
    }
    else if(serialIn == "2"){
        mode = 2;
    }
    else if(serialIn == "3"){
        mode = 3;
    }
}
// mode select checker

// mode 1
// map pot to servo 1:1

// mode 2
// map pot to servo 2:1
#endif