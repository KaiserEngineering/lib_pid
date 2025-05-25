#include "lib_pid.h"

void lib_pid_clear_PID( PTR_PID_DATA ptr_pid )
{
    ptr_pid->pid_uuid = PID_UNASSIGNED;
    ptr_pid->pid_unit = PID_UNITS_RESERVED;
    ptr_pid->base_unit = PID_UNITS_RESERVED;
    ptr_pid->acquisition_type = PID_UNASSIGNED;
    ptr_pid->pid_value = 99999;
    ptr_pid->pid_min = INIT_MIN;
    ptr_pid->pid_max = INIT_MAX;
    ptr_pid->timestamp = 0;
    ptr_pid->devices = 0;
}

uint8_t get_mode_by_uuid( uint32_t pid_uuid )
{
	return (pid_uuid >> 16) & 0xFF;
}

uint16_t get_pid_by_uuid( uint32_t pid_uuid )
{
	return pid_uuid & 0xFFFF;
}

uint8_t load_pid_data( PTR_PID_DATA pid )
{
	// Verify the pid_uuid is valid
	if( pid->pid_uuid == PID_UNASSIGNED )
		return 0;

	// Verify the pid unit was set
	if( pid->pid_unit == PID_UNITS_RESERVED )
		return 0;

	// Load the labels
	get_pid_label(pid->pid_uuid, pid->label);
	get_unit_label(pid->pid_unit, pid->unit_label);

	// Load the base units
	pid->base_unit = get_pid_base_unit(pid->pid_uuid);

	// Load the list of supported units
	pid->num_units_supported = get_pid_units(pid->pid_uuid, &pid->supported_units);

	// Get the value limits
	pid->lower_limit = get_pid_lower_limit(pid->pid_uuid ,pid->pid_unit);
	pid->upper_limit = get_pid_upper_limit(pid->pid_uuid ,pid->pid_unit);
	pid->precision = get_pid_precision(pid->pid_uuid ,pid->pid_unit);

	return 1;
}
