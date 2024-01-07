#include "../include/median.hpp"

namespace qymos
{
    namespace common
    {
        namespace filter
        {
            void Median::Set(uint16_t value)
            {
                _value[0] = _value[1];
                _value[1] = _value[2];
                _value[2] = value;
            }
            uint16_t Median::Get()
            {
                return (_value[0] < _value[1]) ? ((_value[1] < _value[2]) ? _value[1] : ((_value[2] < _value[0]) ? _value[0] : _value[2])) : ((_value[0] < _value[2]) ? _value[0] : ((_value[2] < _value[1]) ? _value[1] : _value[2]));
            }
        } // namespace filter

    } // namespace common

} // namespace qymos
