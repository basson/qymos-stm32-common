#pragma once

#include "stm32f1xx.h"

namespace qymos
{
    namespace common
    {
        namespace time
        {
            class SoftTimer
            {
            private:
                uint32_t _lastMs = 0;
                uint32_t _intervalMs = 0;
                bool _isRepeat = false;
                bool _isElapsed = false;
                bool _isOn = false;

            public:
                SoftTimer(){};
                SoftTimer(uint32_t intervalMs, bool isRepeat = false);
                void SetInterval(uint32_t intervalMs);
                void SetRepeat(bool repeat = true);
                void On();
                void Off();
                void Process();
                bool Elapsed();
            };

        } // namespace time

    } // namespace common

} // namespace qymos
