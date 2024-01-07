#pragma once
#include "stdint.h"
#include "stm32f1xx.h"

namespace qymos
{
    namespace common
    {
        namespace time
        {
            uint32_t GetMs();

            uint32_t GetUs();

            uint32_t GetSec();

        } // namespace time

    } // namespace common

} // namespace qymos
