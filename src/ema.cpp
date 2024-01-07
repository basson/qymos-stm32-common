#include "../include/ema.hpp"

namespace qymos
{
    namespace common
    {
        namespace filter
        {
            void Ema::SetK(float k)
            {
                if (k > 1)
                    k = 1;
                _k = k;
            }
            void Ema::Set(uint16_t value)
            {
                _normalized += (value - _normalized) * _k;
            }
            uint16_t Ema::Get()
            {
                return _normalized;
            }

        } // namespace filter

    } // namespace common

} // namespace qymos
