/*
 * CMPS10.cpp - Library for easy use of the CMPS10 tilt-compensating digital
 * compass.
 *
 * Copyright (C) 2013 Louis Taylor <kragniz@gmail.com>
 *
 * This code is released under the terms of the LGPLv3 licence.
 */

#include "Arduino.h"
#include "Wire.h"
#include "CMPS10.h"

byte _read_i2c(int address, int _register) {
  Wire.beginTransmission(address);
  Wire.write(_register);
  Wire.endTransmission();
  Wire.requestFrom(address, 1);
  return Wire.read();
}

CMPS10::CMPS10() {
    compass_address = 0x60;
}

int CMPS10::bearing() {
    return _read_i2c(compass_address, 1);
}
