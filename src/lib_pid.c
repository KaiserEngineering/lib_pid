#include "lib_pid.h"

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
