#include "lib_pid.h"

void lib_pid_clear_PID( PTR_PID_DATA ptr_pid )
{
    ptr_pid->mode = PID_UNASSIGNED;
    ptr_pid->pid = PID_UNASSIGNED;
    ptr_pid->pid_unit = PID_UNITS_NOT_APPLICABLE;
    ptr_pid->base_unit = PID_UNITS_NOT_APPLICABLE;
    ptr_pid->acquisition_type = PID_UNASSIGNED;
    ptr_pid->pid_value = 0;
    ptr_pid->timestamp = 0;
    ptr_pid->devices = 0;
}

float get_pid_value( uint8_t mode, uint16_t pid, uint8_t data[] )
{
    switch( mode )
    {
        case MODE1:
            switch( pid )
            {
                /*    Equation: (A * 100) / 255    */
                #ifdef MODE1_CALCULATED_ENGINE_LOAD_VALUE_SUPPORTED
                    #ifndef MODE1_EQ_100_TIMES_A_OVER_255
                    #define MODE1_EQ_100_TIMES_A_OVER_255
                    #endif
                case MODE1_CALCULATED_ENGINE_LOAD_VALUE:
                #endif

                #ifdef MODE1_EQ_100_TIMES_A_OVER_255
                    return (((float)data[A]) * (float)100) / (float)255;
                    break;
                #endif

                #ifdef MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED
                    #ifndef MODE1_EQ_A_MINUS_40
                    #define MODE1_EQ_A_MINUS_40
                    #endif
                case MODE1_INTAKE_AIR_TEMPERATURE:
                #endif

                #ifdef MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED
                    #ifndef MODE1_EQ_A_MINUS_40
                    #define MODE1_EQ_A_MINUS_40
                    #endif
                case MODE1_ENGINE_COOLANT_TEMPERATURE:
                #endif

                #ifdef MODE1_AMBIENT_AIR_TEMPERATURE_SUPPORTED
                    #ifndef MODE1_EQ_A_MINUS_40
                    #define MODE1_EQ_A_MINUS_40
                    #endif
                case MODE1_AMBIENT_AIR_TEMPERATURE:
                #endif

                #ifdef MODE1_EQ_A_MINUS_40
                    return ((float)data[A] - (float)40);
                    break;
                #endif

                #ifdef MODE1_ENGINE_RPM_SUPPORTED
                    #ifndef MODE1_EQ_256_TIMES_A_PLUS_B_OVER_255
                    #define MODE1_EQ_256_TIMES_A_PLUS_B_OVER_255
                    #endif
                case MODE1_ENGINE_RPM:
                #endif

                #ifdef MODE1_EQ_256_TIMES_A_PLUS_B_OVER_255
                    return (((float)256 * (float)data[A] ) + (float)data[B] ) / (float)4;
                    break;
                #endif

                #ifdef MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED
                    #ifndef MODE1_EQ_A
                    #define MODE1_EQ_A
                    #endif
                case MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE:
                #endif

                #ifdef MODE1_VEHICLE_SPEED_SUPPORTED
                    #ifndef MODE1_EQ_A
                    #define MODE1_EQ_A
                    #endif
                case MODE1_VEHICLE_SPEED:
                #endif

                #ifdef MODE1_BAROMETRIC_PRESSURE_SUPPORTED
                    #ifndef MODE1_EQ_A
                    #define MODE1_EQ_A
                    #endif
                case MODE1_BAROMETRIC_PRESSURE:
                #endif

                #ifdef MODE1_EQ_A
                    return (float)data[A];
                    break;
                #endif

                #ifdef MODE1_MAF_AIR_FLOW_RATE_SUPPORTED
                    #ifndef MODE1_EQ_256_TIMES_A_PLUS_B_OVER_100
                    #define MODE1_EQ_256_TIMES_A_PLUS_B_OVER_100
                    #endif
                case MODE1_MAF_AIR_FLOW_RATE:
                #endif

                #ifdef MODE1_EQ_256_TIMES_A_PLUS_B_OVER_100
                    return (((float)256 * (float)data[A] ) + (float)data[B] ) / (float)100;
                    break;
                #endif

                default:
                    return -1;
                    break;
            }

        case MODE22:
            switch( pid )
            {
                #ifdef MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED
                    #ifndef MODE22_EQ_256_TIMES_A_PLUS_B_OVER_64
                    #define MODE22_EQ_256_TIMES_A_PLUS_B_OVER_64
                    #endif
                case MODE22_CHARGE_AIR_TEMPERATURE:
                #endif

                #ifdef MODE22_EQ_256_TIMES_A_PLUS_B_OVER_64
                    return (((float)256 * (float)data[A] ) + (float)data[B] ) / (float)64;
                #endif

                #ifdef MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED
                    #ifndef MODE22_EQ_A_MINUS_40
                    #define MODE22_EQ_A_MINUS_40
                    #endif
                case MODE22_INTAKE_AIR_TEMPERATURE:
                #endif

                #ifdef MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED
                    #ifndef MODE22_EQ_A_MINUS_40
                    #define MODE22_EQ_A_MINUS_40
                    #endif
                case MODE22_AMBIENT_AIR_TEMPERATURE:
                #endif

                #ifdef MODE22_EQ_A_MINUS_40
                    return ((float)data[A] - (float)40);
                    break;
                #endif

                default:
                    return -1;
                    break;
            }

        default:
            return -1;
    }
}

PID_UNITS get_pid_base_unit( uint8_t mode, uint16_t PID )
{
    switch ( mode )
    {
        case MODE1:
            switch ( PID )
            {
                #ifdef MODE1_CALCULATED_ENGINE_LOAD_VALUE_SUPPORTED
                case MODE1_CALCULATED_ENGINE_LOAD_VALUE:
                    return MODE1_CALCULATED_ENGINE_LOAD_UNITS;
                #endif

                #ifdef MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED
                case MODE1_ENGINE_COOLANT_TEMPERATURE:
                    return MODE1_ENGINE_COOLANT_TEMPERATURE_UNITS;
                #endif

                #ifdef MODE1_ENGINE_RPM_SUPPORTED
                case MODE1_ENGINE_RPM:
                    return MODE1_ENGINE_RPM_UNITS;
                #endif

                #ifdef MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED
                case MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE:
                    return MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_UNITS;
                #endif

                #ifdef MODE1_VEHICLE_SPEED_SUPPORTED
                case MODE1_VEHICLE_SPEED:
                    return MODE1_VEHICLE_SPEED_UNITS;
                #endif

                #ifdef MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED
                case MODE1_INTAKE_AIR_TEMPERATURE:
                    return MODE1_INTAKE_AIR_TEMPERATURE_UNITS;
                #endif

                #ifdef MODE1_MAF_AIR_FLOW_RATE_SUPPORTED
                case MODE1_MAF_AIR_FLOW_RATE:
                    return MODE1_MAF_AIR_FLOW_RATE_UNITS;
                #endif

                #ifdef MODE1_THROTTLE_POSITION_SUPPORTED
                case MODE1_THROTTLE_POSITION:
                    return MODE1_THROTTLE_POSITION_UNITS;
                #endif

                #ifdef MODE1_BAROMETRIC_PRESSURE_SUPPORTED
                case MODE1_BAROMETRIC_PRESSURE:
                    return MODE1_BAROMETRIC_PRESSURE_UNITS;
                #endif

                #ifdef MODE1_ABSOLUTE_LOAD_VALUE_SUPPORTED
                case MODE1_ABSOLUTE_LOAD_VALUE:
                    return MODE1_ABSOLUTE_LOAD_VALUE_UNITS;
                #endif

                #ifdef MODE1_AMBIENT_AIR_TEMPERATURE_SUPPORTED
                case MODE1_AMBIENT_AIR_TEMPERATURE:
                    return MODE1_AMBIENT_AIR_TEMPERATURE_UNITS;
                #endif

                #ifdef MODE1_TURBO_INLET_PRESSURE_SUPPORTED
                case MODE1_TURBO_INLET_PRESSURE:
                    return MODE1_TURBO_INLET_PRESSURE_UNITS;
                #endif

                default:
                    return 0x00;
            }
            break;

        case MODE22:
            switch ( PID )
            {
                #ifdef MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED
                case MODE22_INTAKE_AIR_TEMPERATURE:
                    return MODE22_INTAKE_AIR_TEMPERATURE_UNITS;
                #endif

                #ifdef MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED
                case MODE22_CHARGE_AIR_TEMPERATURE:
                    return MODE22_CHARGE_AIR_TEMPERATURE_UNITS;
                #endif

                #ifdef MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED
                case MODE22_AMBIENT_AIR_TEMPERATURE:
                    return MODE22_AMBIENT_AIR_TEMPERATURE_UNITS;
                #endif

                default:
                    return 0;
            }
            break;

        default:
            return 0;
        }
}

uint8_t lookup_payload_length( uint8_t mode, uint16_t PID )
{
    switch ( mode )
    {
        case MODE1:
            switch ( PID )
            {
                #ifdef MODE1_CALCULATED_ENGINE_LOAD_VALUE_SUPPORTED
                case MODE1_CALCULATED_ENGINE_LOAD_VALUE:
                    return MODE1_CALCULATED_ENGINE_LOAD_VALUE_LEN;
                #endif

                #ifdef MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED
                case MODE1_ENGINE_COOLANT_TEMPERATURE:
                    return MODE1_ENGINE_COOLANT_TEMPERATURE_LEN;
                #endif

                #ifdef MODE1_ENGINE_RPM_SUPPORTED
                case MODE1_ENGINE_RPM:
                    return MODE1_ENGINE_RPM_LEN;
                #endif

                #ifdef MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED
                case MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE:
                    return MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LEN;
                #endif

                #ifdef MODE1_VEHICLE_SPEED_SUPPORTED
                case MODE1_VEHICLE_SPEED:
                    return MODE1_VEHICLE_SPEED_LEN;
                #endif

                #ifdef MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED
                case MODE1_INTAKE_AIR_TEMPERATURE:
                    return MODE1_INTAKE_AIR_TEMPERATURE_LEN;
                #endif

                #ifdef MODE1_MAF_AIR_FLOW_RATE_SUPPORTED
                case MODE1_MAF_AIR_FLOW_RATE:
                    return MODE1_MAF_AIR_FLOW_RATE_LEN;
                #endif

                #ifdef MODE1_THROTTLE_POSITION_SUPPORTED
                case MODE1_THROTTLE_POSITION:
                    return MODE1_THROTTLE_POSITION_LEN;
                #endif

                #ifdef MODE1_BAROMETRIC_PRESSURE_SUPPORTED
                case MODE1_BAROMETRIC_PRESSURE:
                    return MODE1_BAROMETRIC_PRESSURE_LEN;
                #endif

                #ifdef MODE1_ABSOLUTE_LOAD_VALUE_SUPPORTED
                case MODE1_ABSOLUTE_LOAD_VALUE:
                    return MODE1_ABSOLUTE_LOAD_VALUE_LEN;
                #endif

                #ifdef MODE1_AMBIENT_AIR_TEMPERATURE_SUPPORTED
                case MODE1_AMBIENT_AIR_TEMPERATURE:
                    return MODE1_AMBIENT_AIR_TEMPERATURE_LEN;
                #endif

                default:
                    return 0x00;
            }
            break;

        case MODE22:
            switch ( PID )
            {
                #ifdef MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED
                case MODE22_INTAKE_AIR_TEMPERATURE:
                    return MODE22_INTAKE_AIR_TEMPERATURE_LEN;
                #endif

                #ifdef MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED
                case MODE22_CHARGE_AIR_TEMPERATURE:
                    return MODE22_CHARGE_AIR_TEMPERATURE_LEN;
                #endif

                #ifdef MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED
                case MODE22_AMBIENT_AIR_TEMPERATURE:
                    return MODE22_AMBIENT_AIR_TEMPERATURE_LEN;
                #endif

                default:
                    return 0;
            }
            break;

        default:
            return 0;
        }
}
