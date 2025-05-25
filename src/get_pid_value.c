/**
 ******************************************************************************
 * 
 * Copyright (c) 2025 KaiserEngineering, LLC
 * Author Matthew Kaiser 
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

float get_pid_value( uint32_t pid_uuid, uint8_t data[] )
{
    switch( pid_uuid )
    {
        #if defined(MODE1_COMMANDED_AIR_TO_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_29D4_OVER_65536_TIMES_256_A_PLUS_B
            #define FORMULA_29D4_OVER_65536_TIMES_256_A_PLUS_B
            #endif
            case MODE1_COMMANDED_AIR_TO_FUEL_RATIO_UUID:
        #endif

        #if defined(MODE1_AIR_TO_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_29D4_OVER_65536_TIMES_256_A_PLUS_B
            #define FORMULA_29D4_OVER_65536_TIMES_256_A_PLUS_B
            #endif
            case MODE1_AIR_TO_FUEL_RATIO_UUID:
        #endif

        #ifdef FORMULA_29D4_OVER_65536_TIMES_256_A_PLUS_B
            return ((((float)256 *(float)data[A]) + (float)data[B]) * (float)29.4) / (float)65536;
        #endif

        #if defined(MODE1_CALCULATED_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_100_TIMES_A_OVER_255
            #define FORMULA_100_TIMES_A_OVER_255
            #endif
            case MODE1_CALCULATED_ENGINE_LOAD_UUID:
        #endif

        #if defined(MODE1_THROTTLE_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_100_TIMES_A_OVER_255
            #define FORMULA_100_TIMES_A_OVER_255
            #endif
            case MODE1_THROTTLE_POSITION_UUID:
        #endif

        #if defined(MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_100_TIMES_A_OVER_255
            #define FORMULA_100_TIMES_A_OVER_255
            #endif
            case MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_UUID:
        #endif

        #if defined(MODE22_ENGINE_LOAD_PERCENTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_100_TIMES_A_OVER_255
            #define FORMULA_100_TIMES_A_OVER_255
            #endif
            case MODE22_ENGINE_LOAD_PERCENTAGE_UUID:
        #endif

        #ifdef FORMULA_100_TIMES_A_OVER_255
            return (((float)data[A]) * (float)100) / (float)255;
        #endif

        #if defined(MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A_MINUS_40
            #define FORMULA_A_MINUS_40
            #endif
            case MODE1_ENGINE_COOLANT_TEMPERATURE_UUID:
        #endif

        #if defined(MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A_MINUS_40
            #define FORMULA_A_MINUS_40
            #endif
            case MODE1_INTAKE_AIR_TEMPERATURE_UUID:
        #endif

        #if defined(MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A_MINUS_40
            #define FORMULA_A_MINUS_40
            #endif
            case MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_UUID:
        #endif

        #if defined(MODE1_ENGINE_OIL_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A_MINUS_40
            #define FORMULA_A_MINUS_40
            #endif
            case MODE1_ENGINE_OIL_TEMPERATURE_UUID:
        #endif

        #if defined(MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A_MINUS_40
            #define FORMULA_A_MINUS_40
            #endif
            case MODE22_INTAKE_AIR_TEMPERATURE_UUID:
        #endif

        #if defined(MODE22_MANIFOLD_CHARGE_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A_MINUS_40
            #define FORMULA_A_MINUS_40
            #endif
            case MODE22_MANIFOLD_CHARGE_TEMPERATURE_UUID:
        #endif

        #ifdef FORMULA_A_MINUS_40
            return ((float)data[A] - (float)40);
        #endif

        #if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_100_OVER_128_TIMES_A_MINUS_100
            #define FORMULA_100_OVER_128_TIMES_A_MINUS_100
            #endif
            case MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_UUID:
        #endif

        #if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_100_OVER_128_TIMES_A_MINUS_100
            #define FORMULA_100_OVER_128_TIMES_A_MINUS_100
            #endif
            case MODE1_LONG_TERM_FUEL_TRIM__BANK_1_UUID:
        #endif

        #if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_100_OVER_128_TIMES_A_MINUS_100
            #define FORMULA_100_OVER_128_TIMES_A_MINUS_100
            #endif
            case MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_UUID:
        #endif

        #if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_100_OVER_128_TIMES_A_MINUS_100
            #define FORMULA_100_OVER_128_TIMES_A_MINUS_100
            #endif
            case MODE1_LONG_TERM_FUEL_TRIM__BANK_2_UUID:
        #endif

        #ifdef FORMULA_100_OVER_128_TIMES_A_MINUS_100
            return (((float)100 / (float)128) * (float)(data[A])) - (float)100;
        #endif

        #if defined(MODE1_FUEL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A_TIMES_3
            #define FORMULA_A_TIMES_3
            #endif
            case MODE1_FUEL_PRESSURE_UUID:
        #endif

        #ifdef FORMULA_A_TIMES_3
            return (float)data[A] * (float)3;
        #endif

        #if defined(MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A
            #define FORMULA_A
            #endif
            case MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_UUID:
        #endif

        #if defined(MODE1_VEHICLE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A
            #define FORMULA_A
            #endif
            case MODE1_VEHICLE_SPEED_UUID:
        #endif

        #if defined(MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A
            #define FORMULA_A
            #endif
            case MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_UUID:
        #endif

        #ifdef FORMULA_A
            return (float)data[A];
        #endif

        #if defined(MODE1_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_PLUS_B_OVER_4
            #define FORMULA_256_TIMES_A_PLUS_B_OVER_4
            #endif
            case MODE1_ENGINE_SPEED_UUID:
        #endif

        #ifdef FORMULA_256_TIMES_A_PLUS_B_OVER_4
            return (((float)256 * (float)data[A] ) + (float)data[B] ) / (float)4;
        #endif

        #if defined(MODE1_TIMING_ADVANCE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A_OVER_2_MINUS_64
            #define FORMULA_A_OVER_2_MINUS_64
            #endif
            case MODE1_TIMING_ADVANCE_UUID:
        #endif

        #ifdef FORMULA_A_OVER_2_MINUS_64
            return ((float)data[A] / (float)2) - (float)64;
        #endif

        #if defined(MODE1_OXYGEN_SENSOR_2_VOLTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A_OVER_200
            #define FORMULA_A_OVER_200
            #endif
            case MODE1_OXYGEN_SENSOR_2_VOLTAGE_UUID:
        #endif

        #ifdef FORMULA_A_OVER_200
            return (float)data[A] / (float)255;
        #endif

        #if defined(MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_ZERO_DOT_079_TIMES_256_TIMES_A_PLUS_B
            #define FORMULA_ZERO_DOT_079_TIMES_256_TIMES_A_PLUS_B
            #endif
            case MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_UUID:
        #endif

        #ifdef FORMULA_ZERO_DOT_079_TIMES_256_TIMES_A_PLUS_B
            return ((float)0.079 * (((float)256 * (float)data[A]) + (float)data[B]));
        #endif

        #if defined(MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UUID:
        #endif

        #if defined(SNIFF_GAUGE_BRIGHTNESS_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_GAUGE_BRIGHTNESS_UUID:
        #endif

        #if defined(SNIFF_VEHICLE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_VEHICLE_STATUS_UUID:
        #endif

        #if defined(SNIFF_BRAKE_PEDAL_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_BRAKE_PEDAL_STATUS_UUID:
        #endif

        #if defined(SNIFF_EMERGENCY_BRAKE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_EMERGENCY_BRAKE_STATUS_UUID:
        #endif

        #if defined(SNIFF_REVERSE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_REVERSE_STATUS_UUID:
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_ON_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_CRUISE_CONTROL_ON_BUTTON_UUID:
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_OFF_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_CRUISE_CONTROL_OFF_BUTTON_UUID:
        #endif

        #if defined(CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UUID:
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UUID:
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UUID:
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_RES_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_CRUISE_CONTROL_RES_BUTTON_UUID:
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_CAN_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_CRUISE_CONTROL_CAN_BUTTON_UUID:
        #endif

        #if defined(CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UUID:
        #endif

        #if defined(SNIFF_LATERAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_LATERAL_ACCELERATION_UUID:
        #endif

        #if defined(SNIFF_LONGITUDINAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_UNDEFINED
            #define FORMULA_UNDEFINED
            #endif
            case SNIFF_LONGITUDINAL_ACCELERATION_UUID:
        #endif

        #ifdef FORMULA_UNDEFINED
            return 0;
        #endif

        #if defined(MODE22_LATERAL_G_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_SIGNED_PLUS_B_TIMES_0_DOT_002
            #define FORMULA_256_TIMES_A_SIGNED_PLUS_B_TIMES_0_DOT_002
            #endif
            case MODE22_LATERAL_G_UUID:
        #endif

        #if defined(MODE22_LONGITUDE_G_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_SIGNED_PLUS_B_TIMES_0_DOT_002
            #define FORMULA_256_TIMES_A_SIGNED_PLUS_B_TIMES_0_DOT_002
            #endif
            case MODE22_LONGITUDE_G_UUID:
        #endif

        #ifdef FORMULA_256_TIMES_A_SIGNED_PLUS_B_TIMES_0_DOT_002
            return (((float)256 * (float)((int8_t)data[A]) ) + (float)data[B] ) * (float)0.002;
        #endif

        #if defined(MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_1024
            #define FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_1024
            #endif
            case MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_UUID:
        #endif

        #ifdef FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_1024
            return (((float)256 * (float)((int8_t)data[A]) ) + (float)data[B] ) / (float)1024;
        #endif

        #if defined(MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_PLUS_B_OVER_327_DOT_68
            #define FORMULA_256_TIMES_A_PLUS_B_OVER_327_DOT_68
            #endif
            case MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_UUID:
        #endif

        #if defined(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_PLUS_B_OVER_327_DOT_68
            #define FORMULA_256_TIMES_A_PLUS_B_OVER_327_DOT_68
            #endif
            case MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UUID:
        #endif

        #if defined(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_PLUS_B_OVER_327_DOT_68
            #define FORMULA_256_TIMES_A_PLUS_B_OVER_327_DOT_68
            #endif
            case MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UUID:
        #endif

        #ifdef FORMULA_256_TIMES_A_PLUS_B_OVER_327_DOT_68
            return (((float)256 * (float)(data[A]) ) + (float)data[B] ) / (float)327.68;
        #endif

        #if defined(MODE22_IGNITION_CORRECTION_CYLINDER_1_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_NEG_512
            #define FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_NEG_512
            #endif
            case MODE22_IGNITION_CORRECTION_CYLINDER_1_UUID:
        #endif

        #ifdef FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_NEG_512
            return (((float)256 * (float)((int8_t)data[A]) ) + (float)data[B] ) / (float)-512;
        #endif

        #if defined(MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_64
            #define FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_64
            #endif
            case MODE22_CHARGE_AIR_TEMPERATURE_UUID:
        #endif

        #ifdef FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_64
            return (((float)256 * (float)(int8_t)data[A] ) + (float)data[B] ) / (float)64;
        #endif

        #if defined(MODE22_OCTANE_ADJUST_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_16384
            #define FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_16384
            #endif
            case MODE22_OCTANE_ADJUST_RATIO_UUID:
        #endif

        #ifdef FORMULA_256_TIMES_A_SIGNED_PLUS_B_OVER_16384
            return (((float)256 * (float)((int8_t)data[A]) ) + (float)data[B] ) / (float)16384;
        #endif

        #if defined(MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_A_OVER_2_MINUS_40
            #define FORMULA_A_OVER_2_MINUS_40
            #endif
            case MODE22_AMBIENT_AIR_TEMPERATURE_UUID:
        #endif

        #ifdef FORMULA_A_OVER_2_MINUS_40
            return ((float)data[A] / (float)2) - (float)40;
        #endif

        #if defined(MODE22_CATALYTIC_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            #ifndef FORMULA_256_TIMES_A_PLUS_B_OVER_10_MINUS_40
            #define FORMULA_256_TIMES_A_PLUS_B_OVER_10_MINUS_40
            #endif
            case MODE22_CATALYTIC_TEMPERATURE_UUID:
        #endif

        #ifdef FORMULA_256_TIMES_A_PLUS_B_OVER_10_MINUS_40
            return ((((float)256 * (float)data[A] ) + (float)data[B] ) / (float)10)-(float)40;
        #endif

        default:
             return 0;
    }
}