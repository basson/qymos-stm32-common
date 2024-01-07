#include "../include/time.hpp"


namespace qymos
{
    namespace common
    {
        namespace time
        {
            uint32_t GetMs()
            {
                return HAL_GetTick();
            }

            uint32_t GetUs()
            {
                return HAL_GetTick() / 1000;
            }

            uint32_t GetSec()
            {
                return GetUs() / 1000;
            }

        } // namespace time

    } // namespace common

} // namespace qymos