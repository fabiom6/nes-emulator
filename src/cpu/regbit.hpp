#pragma once
#include <cinttypes>

template <unsigned bitno, unsigned nbits = 1, typename T = uint8_t>
class RegBit {
private:
    T data;
    enum { mask = (1u << nbits) - 1u };

public:
    template <typename T2>
    RegBit& operator=(T2 val) {
        data = (data & ~(mask << bitno)) | (val & mask) << bitno; 
    }

    operator unsigned() const { return (data >> bitno) & mask; }
};