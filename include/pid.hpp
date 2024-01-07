#pragma once

#include "stdint.h"
#include "stm32f1xx.h"

#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))

namespace qymos
{
    namespace common
    {
        struct PidData
        {
            float Kp;
            float Ki;
            float Kd;
            float Inpit;
            float Point;
            float Error;
            float Integral;
            float LastError;
            float SampleTimeMs;
            float LastTime;
            float OutputMin = 0;
            float OutputMax = 255;
            float Output = 0;
        };

        class Pid
        {
        private:
            static PidData *_data;

        public:
            static void SetData(PidData *data);
            static bool Process();
        };

    } // namespace common

} // namespace qymos
