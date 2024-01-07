#include "../include/pid.hpp"

namespace qymos
{
    namespace common
    {
        PidData *Pid::_data;

        void Pid::SetData(PidData *data)
        {
            _data = data;
        }
        bool Pid::Process()
        {
            if (_data->LastTime + _data->SampleTimeMs > HAL_GetTick())
                return false;
            _data->LastTime = HAL_GetTick();
            float error = _data->Point - _data->Inpit;
            _data->Integral = constrain(_data->Integral + (float)error * _data->SampleTimeMs * _data->Ki, _data->OutputMin, _data->OutputMax);
            float D = (error - _data->Error);
            _data->Error = error;
            _data->Output = constrain(error * _data->Kp + _data->Integral + D * _data->Kd, _data->OutputMin, _data->OutputMax);
            return true;
        }

    } // namespace common

} // namespace qymos
