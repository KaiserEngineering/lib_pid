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

float get_pid_value( uint8_t mode, uint16_t pid, uint8_t data[] )
{
    switch( mode )
    {
        case MODE1:
            switch( pid )
            {
                #if defined(MODE1_CALCULATED_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_100_TIMES_A_OVER_255
                    #define MODE1_100_TIMES_A_OVER_255
                    #endif
                    case MODE1_CALCULATED_ENGINE_LOAD:
                #endif

                #if defined(MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_100_TIMES_A_OVER_255
                    #define MODE1_100_TIMES_A_OVER_255
                    #endif
                    case MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION:
                #endif

                #ifdef MODE1_100_TIMES_A_OVER_255
                    return (((float)data[A]) * (float)100) / (float)255;
                #endif

                #if defined(MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_A_MINUS_40
                    #define MODE1_A_MINUS_40
                    #endif
                    case MODE1_ENGINE_COOLANT_TEMPERATURE:
                #endif

                #if defined(MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_A_MINUS_40
                    #define MODE1_A_MINUS_40
                    #endif
                    case MODE1_INTAKE_AIR_TEMPERATURE:
                #endif

                #if defined(MODE1_ENGINE_OIL_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_A_MINUS_40
                    #define MODE1_A_MINUS_40
                    #endif
                    case MODE1_ENGINE_OIL_TEMPERATURE:
                #endif

                #ifdef MODE1_A_MINUS_40
                    return ((float)data[A] - (float)40);
                #endif

                #if defined(MODE1_FUEL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_A_TIMES_3
                    #define MODE1_A_TIMES_3
                    #endif
                    case MODE1_FUEL_PRESSURE:
                #endif

                #ifdef MODE1_A_TIMES_3
                    return (float)data[A] * (float)3;
                #endif

                #if defined(MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_A
                    #define MODE1_A
                    #endif
                    case MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE:
                #endif

                #if defined(MODE1_VEHICLE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_A
                    #define MODE1_A
                    #endif
                    case MODE1_VEHICLE_SPEED:
                #endif

                #if defined(MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_A
                    #define MODE1_A
                    #endif
                    case MODE1_ABSOLUTE_BAROMETRIC_PRESSURE:
                #endif

                #ifdef MODE1_A
                    return (float)data[A];
                #endif

                #if defined(MODE1_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_256_TIMES_A_PLUS_B_OVER_255
                    #define MODE1_256_TIMES_A_PLUS_B_OVER_255
                    #endif
                    case MODE1_ENGINE_SPEED:
                #endif

                #ifdef MODE1_256_TIMES_A_PLUS_B_OVER_255
                    return (((float)256 * (float)data[A] ) + (float)data[B] ) / (float)4;
                #endif

                #if defined(MODE1_TIMING_ADVANCE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_A_OVER_2_MINUS_64
                    #define MODE1_A_OVER_2_MINUS_64
                    #endif
                    case MODE1_TIMING_ADVANCE:
                #endif

                #ifdef MODE1_A_OVER_2_MINUS_64
                    return ((float)data[A] / (float)2) - (float)64;
                #endif

                #if defined(MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE1_UNDEFINED
                    #define MODE1_UNDEFINED
                    #endif
                    case MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE:
                #endif

                #ifdef MODE1_UNDEFINED
                    return 0;
                #endif

                default:
                    return 0;
            }
        break;

        case MODE22:
            switch( pid )
            {
                #if defined(MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE22_256_TIMES_A_SIGNED_PLUS_B_OVER_1024
                    #define MODE22_256_TIMES_A_SIGNED_PLUS_B_OVER_1024
                    #endif
                    case MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1:
                #endif

                #ifdef MODE22_256_TIMES_A_SIGNED_PLUS_B_OVER_1024
                    return (((float)256 * (float)((int8_t)data[A]) ) + (float)data[B] ) / (float)1024;
                #endif

                #if defined(MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE22_256_TIMES_A_PLUS_B_OVER_327_DOT_68
                    #define MODE22_256_TIMES_A_PLUS_B_OVER_327_DOT_68
                    #endif
                    case MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE:
                #endif

                #ifdef MODE22_256_TIMES_A_PLUS_B_OVER_327_DOT_68
                    return (((float)256 * (float)(data[A]) ) + (float)data[B] ) / (float)327.68;
                #endif

                #if defined(MODE22_IGNITION_CORRECTION_CYLINDER_1_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE22_256_TIMES_A_SIGNED_PLUS_B_OVER_NEG_512
                    #define MODE22_256_TIMES_A_SIGNED_PLUS_B_OVER_NEG_512
                    #endif
                    case MODE22_IGNITION_CORRECTION_CYLINDER_1:
                #endif

                #ifdef MODE22_256_TIMES_A_SIGNED_PLUS_B_OVER_NEG_512
                    return (((float)256 * (float)((int8_t)data[A]) ) + (float)data[B] ) / (float)-512;
                #endif

                #if defined(MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE22_A_MINUS_40
                    #define MODE22_A_MINUS_40
                    #endif
                    case MODE22_INTAKE_AIR_TEMPERATURE:
                #endif

                #if defined(MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE22_A_MINUS_40
                    #define MODE22_A_MINUS_40
                    #endif
                    case MODE22_AMBIENT_AIR_TEMPERATURE:
                #endif

                #ifdef MODE22_A_MINUS_40
                    return ((float)data[A] - (float)40);
                #endif

                #if defined(MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef MODE22_256_TIMES_A_PLUS_B_OVER_64
                    #define MODE22_256_TIMES_A_PLUS_B_OVER_64
                    #endif
                    case MODE22_CHARGE_AIR_TEMPERATURE:
                #endif

                #ifdef MODE22_256_TIMES_A_PLUS_B_OVER_64
                    return (((float)256 * (float)data[A] ) + (float)data[B] ) / (float)64;
                #endif

                default:
                    return 0;
            }
        break;

        case SNIFF:
            switch( pid )
            {
                #if defined(SNIFF_GAUGE_BRIGHTNESS_SUPPORTED) || !defined(LIMIT_PIDS)
                    #ifndef SNIFF_UNDEFINED
                    #define SNIFF_UNDEFINED
                    #endif
                    case SNIFF_GAUGE_BRIGHTNESS:
                #endif

                #ifdef SNIFF_UNDEFINED
                    return 0;
                #endif

                default:
                    return 0;
            }
        break;

        default:
            return 0;
    }
}