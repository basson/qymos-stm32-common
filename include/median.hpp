#pragma once
#include "stdint.h"

namespace qymos
{
    namespace common
    {
        namespace filter
        {
            class Median
            {
            private:
                uint16_t _value[3] = {0, 0, 0};

            public:
                void Set(uint16_t value);
                uint16_t Get();
            };

        } // namespace filter

    } // namespace common

} // namespace qymos