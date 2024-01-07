#pragma once

#include "stdint.h"

namespace qymos
{
    namespace common
    {
        class BitMem
        {
        public:
            static void SetBit(uint8_t *buffer, uint32_t bitNumber, bool val);
            static bool GetBit(uint8_t *buffer, uint32_t bitNumber);
            static void SetBits(uint8_t *buffer, uint32_t start, uint32_t count, uint8_t *bits);
            static void GetBits(uint8_t *buffer, uint32_t start, uint32_t count, uint8_t *bits);
            static void SetBitsAll(uint8_t *buffer, uint32_t start, uint32_t count, bool bit);
        };

    } // namespace common

} // namespace qymos
