/*
 * CMPS10.h - Library for easy use of the CMPS10 tilt-compensating digital
 * compass.
 *
 * https://github.com/kragniz/CMPS10
 *
 * Copyright (C) 2013 Louis Taylor <kragniz@gmail.com>
 *
 * This code is released under the terms of the LGPLv3 licence.
 */

#ifndef CMPS10_h
#define CMPS10_h

#include "Arduino.h"

// I2C registers
#define COMPASS_BEARING      1
#define COMPASS_DECIMAL_HIGH 2
#define COMPASS_DECIMAL_LOW  3
#define COMPASS_PITCH        4
#define COMPASS_ROLL         5

// accelerometer registers
#define ACCEL_X_HIGH 16
#define ACCEL_X_LOW  17
#define ACCEL_Y_HIGH 18
#define ACCEL_Y_LOW  19
#define ACCEL_Z_HIGH 20
#define ACCEL_Z_LOW  21

class CMPS10 {
    public:
        CMPS10();
        CMPS10(int i2c_address);
        int bearing_byte();
        float bearing();
        int8_t pitch();
        int8_t roll();
        float acceleration();
        float acceleration_x();
        float acceleration_y();
        float acceleration_z();

    private:
        int compass_address;
        byte read_i2c(int address, int _register);
        float read_word(int high_address, int low_address);
        int16_t read_int16_t(int high_address, int low_address);
        void init(int i2c_address);
        float raw_to_g(int16_t raw);
};

#endif
