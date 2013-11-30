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
        uint8_t bearing();
        int8_t pitch();
        int8_t roll();
    private:
        int compass_address;
};

#endif
