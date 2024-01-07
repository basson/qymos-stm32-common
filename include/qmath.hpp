#pragma once

#include "stdint.h"

namespace qymos
{
    namespace common
    {
        namespace math
        {
            uint32_t Map(uint32_t in, uint32_t inMin, uint32_t inMax, uint32_t outMin, uint32_t outMax);
        } // namespace math

    } // namespace common

} // namespace qymos
