#ifndef CMPS10_h
#define CMPS10_h

#include "Arduino.h"

class CMPS10 {
    public:
        CMPS10();
        int bearing();
    private:
        int compass_address;
};

#endif
