#pragma once

#include "StructWithHash.h"

class TestStruct : public StructWithHash {

    public:

        uint8_t x = 0;
        uint16_t y = 0;
        uint16_t z = 0;


    void reset() {

        x = 0;
        y = 0;
        z = 0;

    }

};