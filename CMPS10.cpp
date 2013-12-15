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

// I2C registers
#define COMPASS_BEARING 1
#define COMPASS_DECIMAL_HIGH 2
#define COMPASS_DECIMAL_LOW 3
#define COMPASS_PITCH 4
#define COMPASS_ROLL 5

#define COMPASS_I2C_ADDRESS 0x60

/*
 * Return a byte from a register in the I2C device on a particular address.
 */
byte CMPS10::read_i2c(int address, int _register) {
    Wire.beginTransmission(address);
    Wire.write(_register);
    Wire.endTransmission();
    Wire.requestFrom(address, 1);
    return Wire.read();
}

void CMPS10::init(int i2c_address) {
    compass_address = i2c_address;
    Wire.begin();
}

CMPS10::CMPS10(int i2c_address) {
    init(i2c_address);
}

CMPS10::CMPS10() {
    init(COMPASS_I2C_ADDRESS);
}

/*
 * Return the bearing in degrees. 0-359.9 for a full circle.
 */
double CMPS10::bearing() {
    int high = read_i2c(compass_address, COMPASS_DECIMAL_HIGH) << 8;
    int low = read_i2c(compass_address, COMPASS_DECIMAL_LOW);
    return (high + low) / 10.0;
}

/*
 * Return the bearing as a byte. 0-255 for a full circle.
 */
int CMPS10::bearing_byte() {
    return read_i2c(compass_address, COMPASS_BEARING);
}

/*
 * Return the pitch in degrees from the horizontal plane. 0 when the board is
 * flat and +/- 85 degrees when tilted in either direction.
 */
int8_t CMPS10::pitch() {
    return (int8_t) read_i2c(compass_address, COMPASS_PITCH);
}

/*
 * Return the roll in degrees from the horizontal plane. 0 when the board is
 * flat and +/- 85 degrees when tilted in either direction.
 */
int8_t CMPS10::roll() {
    return (int8_t) read_i2c(compass_address, COMPASS_ROLL);
}
