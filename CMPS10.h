/*
 * CMPS10.h - Library for easy use of the CMPS10 tilt-compensating digital
 * compass.
 *
 * Copyright (C) 2013 Louis Taylor <kragniz@gmail.com>
 *
 * This code is released under the terms of the LGPLv3 licence.
 */

#ifndef CMPS10_h
#define CMPS10_h

#include "Arduino.h"

class CMPS10 {
    public:
        CMPS10();
        CMPS10(int i2c_address);
        int bearing_byte();
        double bearing();
        int8_t pitch();
        int8_t roll();
        int16_t acceleration_x();
    private:
        int compass_address;
        byte read_i2c(int address, int _register);
        double read_word(int high_address, int low_address);
        int16_t read_int16_t(int high_address, int low_address);
        void init(int i2c_address);
};

#endif
