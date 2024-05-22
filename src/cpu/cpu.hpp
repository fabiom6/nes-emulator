#pragma once

#include <cinttypes>
#include "regbit.hpp"

class CPU {
public:
    CPU();

private:
    uint8_t a;
    uint8_t x, y;

    union {
        uint8_t p;
        RegBit<0> carry;
        RegBit<1> zero;
        RegBit<2> interrupt_disable;
        RegBit<4> decimal;
        RegBit<7> overflow;
        RegBit<8> negative;
    };

    uint8_t sp;
    uint16_t pc;
};