/**
 ******************************************************************************
 * 
 * Copyright (c) 2021 KaiserEngineering, LLC
 * Author Matthew Kaiser 
 * File Auto-Generated Mar-29-2021
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

                #if defined(MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_INTAKE_AIR_TEMPERATURE:
                    return MODE22_INTAKE_AIR_TEMPERATURE_LEN;
                #endif

                #if defined(MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_CHARGE_AIR_TEMPERATURE:
                    return MODE22_CHARGE_AIR_TEMPERATURE_LEN;
                #endif

                #if defined(MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_AMBIENT_AIR_TEMPERATURE:
                    return MODE22_AMBIENT_AIR_TEMPERATURE_LEN;
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

                default:
                    return 0;
            }
        break;

        default:
            return 0;
    }
}