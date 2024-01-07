#include "../include/soft_timer.hpp"

namespace qymos
{
    namespace common
    {
        namespace time
        {
            SoftTimer::SoftTimer(uint32_t intervalMs, bool isRepeat)
            {
                _intervalMs = intervalMs;
                _isRepeat = isRepeat;
            }
            void SoftTimer::SetInterval(uint32_t intervalMs)
            {
                _intervalMs = intervalMs;
            }
            void SoftTimer::SetRepeat(bool repeat)
            {
                _isRepeat = repeat;
            }
            void SoftTimer::On()
            {
                _isOn = true;
                _isElapsed = false;
                _lastMs = HAL_GetTick();
            }
            void SoftTimer::Off()
            {
                _isOn = false;
            }
            void SoftTimer::Process()
            {
                if (_isOn && !_isElapsed)
                {
                    if (_lastMs + _intervalMs <= HAL_GetTick())
                    {
                        _lastMs = HAL_GetTick();
                        _isElapsed = true;
                        if (!_isRepeat)
                            _isOn = false;
                    }
                }
            }
            bool SoftTimer::Elapsed()
            {
                bool temp;
                temp = _isElapsed;
                if (_isElapsed)
                    _isElapsed = false;
                return temp;
            }

        } // namespace time

    } // namespace common

} // namespace qymos
