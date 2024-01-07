#pragma once
#include "stdint.h"
namespace qymos
{
    namespace common
    {
        namespace filter
        {
            class Ema
            {
            private:
                float _k = 0.1;
                uint16_t _normalized = 0;

            public:
                void SetK(float k);
                void Set(uint16_t value);
                uint16_t Get();
            };

        } // namespace filter

    } // namespace common

} // namespace qymos
