#include "lib_pid.h"

void lib_pid_clear_PID( PTR_PID_DATA ptr_pid )
{
    ptr_pid->mode = PID_UNASSIGNED;
    ptr_pid->pid = PID_UNASSIGNED;
    ptr_pid->pid_unit = PID_UNITS_RESERVED;
    ptr_pid->base_unit = PID_UNITS_RESERVED;
    ptr_pid->acquisition_type = PID_UNASSIGNED;
    ptr_pid->pid_value = 99999;
    ptr_pid->timestamp = 0;
    ptr_pid->devices = 0;
}
