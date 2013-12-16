/*
 * CMPS10.cpp - Library for easy use of the CMPS10 tilt-compensating digital
 * compass.
 *
 * https://github.com/kragniz/CMPS10
 *
 * Copyright (C) 2013 Louis Taylor <kragniz@gmail.com>
 *
 * This code is released under the terms of the LGPLv3 licence.
 */

#include "Arduino.h"
#include "Wire.h"
#include "CMPS10.h"

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

float CMPS10::read_word(int high_address, int low_address) {
    int high = read_i2c(compass_address, high_address) << 8;
    int low = read_i2c(compass_address, low_address);
    return (high + low) / 10.0;
}

int16_t CMPS10::read_int16_t(int high_address, int low_address) {
    int high = read_i2c(compass_address, high_address) << 8;
    int low = read_i2c(compass_address, low_address);
    return high + low;
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
float CMPS10::bearing() {
    return read_word(COMPASS_DECIMAL_HIGH, COMPASS_DECIMAL_LOW);
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

float CMPS10::raw_to_g(int16_t raw) {
    return raw / (65536.0/4);
}

float CMPS10::acceleration_x() {
    return raw_to_g(read_int16_t(ACCEL_X_HIGH, ACCEL_X_LOW));
}

float CMPS10::acceleration_y() {
    return raw_to_g(read_int16_t(ACCEL_Y_HIGH, ACCEL_Y_LOW));
}

float CMPS10::acceleration_z() {
    return raw_to_g(read_int16_t(ACCEL_Z_HIGH, ACCEL_Z_LOW));
}

float CMPS10::acceleration() {
    return sqrt(
                pow(this->acceleration_x(), 2) +
                pow(this->acceleration_y(), 2) +
                pow(this->acceleration_z(), 2)
           );
}
