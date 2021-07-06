/**
 ******************************************************************************
 * 
 * Copyright (c) 2021 KaiserEngineering, LLC
 * Author Matthew Kaiser 
 * File Auto-Generated Jul-05-2021
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ******************************************************************************
 */

#include "lib_pid.h"

uint8_t lookup_payload_length( uint8_t mode, uint16_t pid )
{
    switch( mode )
    {
        case MODE1:
            switch( pid )
            {
                #if defined(MODE1_CALCULATED_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_CALCULATED_ENGINE_LOAD:
                    return MODE1_CALCULATED_ENGINE_LOAD_LEN;
                #endif

                #if defined(MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_ENGINE_COOLANT_TEMPERATURE:
                    return MODE1_ENGINE_COOLANT_TEMPERATURE_LEN;
                #endif

                #if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_SHORT_TERM_FUEL_TRIM__BANK_1:
                    return MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_LEN;
                #endif

                #if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_LONG_TERM_FUEL_TRIM__BANK_1:
                    return MODE1_LONG_TERM_FUEL_TRIM__BANK_1_LEN;
                #endif

                #if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_SHORT_TERM_FUEL_TRIM__BANK_2:
                    return MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_LEN;
                #endif

                #if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_LONG_TERM_FUEL_TRIM__BANK_2:
                    return MODE1_LONG_TERM_FUEL_TRIM__BANK_2_LEN;
                #endif

                #if defined(MODE1_FUEL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_FUEL_PRESSURE:
                    return MODE1_FUEL_PRESSURE_LEN;
                #endif

                #if defined(MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE:
                    return MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LEN;
                #endif

                #if defined(MODE1_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_ENGINE_SPEED:
                    return MODE1_ENGINE_SPEED_LEN;
                #endif

                #if defined(MODE1_VEHICLE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_VEHICLE_SPEED:
                    return MODE1_VEHICLE_SPEED_LEN;
                #endif

                #if defined(MODE1_TIMING_ADVANCE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_TIMING_ADVANCE:
                    return MODE1_TIMING_ADVANCE_LEN;
                #endif

                #if defined(MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_INTAKE_AIR_TEMPERATURE:
                    return MODE1_INTAKE_AIR_TEMPERATURE_LEN;
                #endif

                #if defined(MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE:
                    return MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_LEN;
                #endif

                #if defined(MODE1_THROTTLE_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_THROTTLE_POSITION:
                    return MODE1_THROTTLE_POSITION_LEN;
                #endif

                #if defined(MODE1_OXYGEN_SENSOR_1_VOLTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_OXYGEN_SENSOR_1_VOLTAGE:
                    return MODE1_OXYGEN_SENSOR_1_VOLTAGE_LEN;
                #endif

                #if defined(MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_ABSOLUTE_BAROMETRIC_PRESSURE:
                    return MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_LEN;
                #endif

                #if defined(MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION:
                    return MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_LEN;
                #endif

                #if defined(MODE1_ENGINE_OIL_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_ENGINE_OIL_TEMPERATURE:
                    return MODE1_ENGINE_OIL_TEMPERATURE_LEN;
                #endif

                #if defined(MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE:
                    return MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LEN;
                #endif

                default:
                    return 0;
            }
        break;

        case MODE22:
            switch( pid )
            {
                #if defined(MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1:
                    return MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_LEN;
                #endif

                #if defined(MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE:
                    return MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_LEN;
                #endif

                #if defined(MODE22_IGNITION_CORRECTION_CYLINDER_1_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_IGNITION_CORRECTION_CYLINDER_1:
                    return MODE22_IGNITION_CORRECTION_CYLINDER_1_LEN;
                #endif

                #if defined(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE:
                    return MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_LEN;
                #endif

                #if defined(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE:
                    return MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_LEN;
                #endif

                #if defined(MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_INTAKE_AIR_TEMPERATURE:
                    return MODE22_INTAKE_AIR_TEMPERATURE_LEN;
                #endif

                #if defined(MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_CHARGE_AIR_TEMPERATURE:
                    return MODE22_CHARGE_AIR_TEMPERATURE_LEN;
                #endif

                #if defined(MODE22_MANIFOLD_CHARGE_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_MANIFOLD_CHARGE_TEMPERATURE:
                    return MODE22_MANIFOLD_CHARGE_TEMPERATURE_LEN;
                #endif

                #if defined(MODE22_OCTANE_ADJUST_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_OCTANE_ADJUST_RATIO:
                    return MODE22_OCTANE_ADJUST_RATIO_LEN;
                #endif

                #if defined(MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_AMBIENT_AIR_TEMPERATURE:
                    return MODE22_AMBIENT_AIR_TEMPERATURE_LEN;
                #endif

                #if defined(MODE22_ENGINE_LOAD_PERCENTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_ENGINE_LOAD_PERCENTAGE:
                    return MODE22_ENGINE_LOAD_PERCENTAGE_LEN;
                #endif

                default:
                    return 0;
            }
        break;

        case SNIFF:
            switch( pid )
            {
                #if defined(SNIFF_GAUGE_BRIGHTNESS_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_GAUGE_BRIGHTNESS:
                    return SNIFF_GAUGE_BRIGHTNESS_LEN;
                #endif

                #if defined(SNIFF_VEHICLE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_VEHICLE_STATUS:
                    return SNIFF_VEHICLE_STATUS_LEN;
                #endif

                #if defined(SNIFF_BRAKE_PEDAL_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_BRAKE_PEDAL_STATUS:
                    return SNIFF_BRAKE_PEDAL_STATUS_LEN;
                #endif

                #if defined(SNIFF_EMERGENCY_BRAKE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_EMERGENCY_BRAKE_STATUS:
                    return SNIFF_EMERGENCY_BRAKE_STATUS_LEN;
                #endif

                #if defined(SNIFF_REVERSE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_REVERSE_STATUS:
                    return SNIFF_REVERSE_STATUS_LEN;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_ON_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_ON_BUTTON:
                    return SNIFF_CRUISE_CONTROL_ON_BUTTON_LEN;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_OFF_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_OFF_BUTTON:
                    return SNIFF_CRUISE_CONTROL_OFF_BUTTON_LEN;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON:
                    return SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_LEN;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON:
                    return SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_LEN;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_RES_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_RES_BUTTON:
                    return SNIFF_CRUISE_CONTROL_RES_BUTTON_LEN;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_CAN_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_CAN_BUTTON:
                    return SNIFF_CRUISE_CONTROL_CAN_BUTTON_LEN;
                #endif

                default:
                    return 0;
            }
        break;

        case CALC1:
            switch( pid )
            {
                #if defined(CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE:
                    return CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LEN;
                #endif

                default:
                    return 0;
            }
        break;

        default:
            return 0;
    }
}