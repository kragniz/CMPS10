#include <Wire.h>

#include <CMPS10.h>

CMPS10 compass;

void setup(){
  Serial.begin(9600);
}

float x, y, z;

void loop() {
  x = compass.acceleration_x();
  y = compass.acceleration_y();
  z = compass.acceleration_z();

  Serial.print("Force on accelerometer: ");
  Serial.println(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

  delay(100);
}
