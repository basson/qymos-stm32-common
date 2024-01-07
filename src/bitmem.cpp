#include "../include/bitmem.hpp"

namespace qymos
{
    namespace common
    {

        void BitMem::SetBit(uint8_t *buffer, uint32_t bitNumber, bool val)
        {
            uint32_t index = bitNumber / 8;
            uint8_t position = bitNumber % 8;
            uint8_t byte = buffer[index];
            if (val)
                buffer[index] = (byte | (1 << position));
            else
                buffer[index] = (byte & (~(1 << position)));
        }
        bool BitMem::GetBit(uint8_t *buffer, uint32_t bitNumber)
        {
            uint32_t index = bitNumber / 8;
            uint8_t position = bitNumber % 8;
            uint8_t byte = buffer[index];
            return (byte >> position) & 0x1;
        }
        void BitMem::SetBits(uint8_t *buffer, uint32_t start, uint32_t count, uint8_t *bits)
        {
            for (uint32_t i = start; i < count; i++)
            {
                SetBit(buffer, i, GetBit(bits, start - i));
            }
        }
        void BitMem::SetBitsAll(uint8_t *buffer, uint32_t start, uint32_t count, bool bit)
        {
            for (uint32_t i = start; i < count; i++)
            {
                SetBit(buffer, i, bit);
            }
        }
        void BitMem::GetBits(uint8_t *buffer, uint32_t start, uint32_t count, uint8_t *bits)
        {
            uint32_t a = 0;
            for (uint32_t i = start; i < count; i++)
            {
                bits[a] = GetBit(buffer, i);
                a++;
            }
        }

    } // namespace common

} // namespace qymos
