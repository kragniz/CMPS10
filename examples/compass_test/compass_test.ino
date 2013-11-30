#include <Wire.h>

#include <CMPS10.h>

CMPS10 compass;

void setup(){
  Serial.begin(9600);
}

void loop() {
  Serial.print("Bearing: ");
  Serial.print(compass.bearing());
  
  Serial.print(" Pitch: ");
  Serial.println((int) compass.pitch());
  delay(100);
}


  
