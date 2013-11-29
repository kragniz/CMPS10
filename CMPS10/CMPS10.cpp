#include "Arduino.h"
#include "CMPS10.h"

CMPS10::CMPS10() {
    compass_address = 0x60;
    Serial.println("initiased");
}
