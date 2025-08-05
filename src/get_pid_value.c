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
            case MODE1_ACCEL_PEDAL_POS_UUID:
            case MODE1_CALC_ENGINE_LOAD_UUID:
            case MODE22_ENGINE_LOAD_UUID:
            case MODE1_THROTTLE_POSITION_UUID:
                return (((float)data[OBDII_BYTEA]) * (float)100) / (float)255;

            case MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_UUID:
            case MODE1_COMMANDED_AIR_FUEL_RATIO_UUID:
                return ((((float)256 *(float)data[OBDII_BYTEA]) + (float)data[OBDII_BYTEB]) * (float)29.4) / (float)65536;

            case MODE22_AMBIENT_AIR_TEMP_UUID:
                return ((float)data[OBDII_BYTEA] / (float)2) - (float)40;

            case MODE1_BAROMETRIC_PRESSURE_UUID:
            case MODE1_MANIFOLD_ABS_PRESS_UUID:
            case MODE1_VEHICLE_SPEED_UUID:
                return (float)data[OBDII_BYTEA];

            case MODE1_BOOST_UUID:
            case CALC1_BOOST_VACUUM_UUID:
            case SNIFF_BRAKE_PEDAL_STATUS_UUID:
            case SNIFF_CRUISE_CONTROL_CAN_BUTTON_UUID:
            case SNIFF_CRUISE_CONTROL_OFF_BUTTON_UUID:
            case CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UUID:
            case SNIFF_CRUISE_CONTROL_ON_BUTTON_UUID:
            case SNIFF_CRUISE_CONTROL_RES_BUTTON_UUID:
            case SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UUID:
            case SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UUID:
            case SNIFF_EMERGENCY_BRAKE_STATUS_UUID:
            case SNIFF_GAUGE_ILLUM_LEVEL_UUID:
            case SNIFF_LATERAL_ACCELERATION_UUID:
            case SNIFF_LONGITUDINAL_ACCELERATION_UUID:
            case SNIFF_REVERSE_STATUS_UUID:
            case SNIFF_VEHICLE_STATUS_UUID:
                return 0;

            case MODE22_CATALYTIC_TEMPERATURE_UUID:
                return ((((float)256 * (float)data[OBDII_BYTEA] ) + (float)data[OBDII_BYTEB] ) / (float)10)-(float)40;

            case MODE22_CHARGE_AIR_TEMP_ST_UUID:
                return (((float)256 * (float)(int8_t)data[OBDII_BYTEA] ) + (float)data[OBDII_BYTEB] ) / (float)64;

            case MODE1_ENGINE_COOLANT_TEMP_UUID:
            case MODE1_INTAKE_AIR_TEMP_UUID:
            case MODE22_INTAKE_AIR_TEMP_UUID:
            case MODE22_MANIFOLD_CHARGE_TEMP_RS_UUID:
            case MODE1_OIL_TEMP_UUID:
                return ((float)data[OBDII_BYTEA] - (float)40);

            case MODE1_ENGINE_SPEED_UUID:
            case SNIFF_ENGINE_SPEED_UUID:
                return (((float)256 * (float)data[OBDII_BYTEA] ) + (float)data[OBDII_BYTEB] ) / (float)4;

            case MODE1_FUEL_PRESSURE_UUID:
                return (float)data[OBDII_BYTEA] * (float)3;

            case MODE1_FUEL_RAIL_PRESSURE_UUID:
                return ((float)0.079 * (((float)256 * (float)data[OBDII_BYTEA]) + (float)data[OBDII_BYTEB]));

            case MODE22_IGNITION_CORRECTION_CYLINDER_1_UUID:
                return (((float)256 * (float)((int8_t)data[OBDII_BYTEA]) ) + (float)data[OBDII_BYTEB] ) / (float)-512;

            case MODE22_LP_FUEL_DUTY_CYCLE_UUID:
            case MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UUID:
            case MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UUID:
                return (((float)256 * (float)(data[OBDII_BYTEA]) ) + (float)data[OBDII_BYTEB] ) / (float)327.68;

            case MODE1_LONG_TERM_FUEL_TRIM_BANK_1_UUID:
            case MODE1_LONG_TERM_FUEL_TRIM_BANK_2_UUID:
            case MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_UUID:
            case MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_UUID:
                return (((float)100 / (float)128) * (float)(data[OBDII_BYTEA])) - (float)100;

            case MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_UUID:
                return (((float)256 * (float)((int8_t)data[OBDII_BYTEA]) ) + (float)data[OBDII_BYTEB] ) / (float)1024;

            case MODE1_MASS_AIR_FLOW_UUID:
                return (((float)256 * (float)(data[OBDII_BYTEA]) ) + (float)data[OBDII_BYTEB] ) / (float)100;

            case MODE1_O2_SENSOR_2_VOLTS_UUID:
                return (float)data[OBDII_BYTEA] / (float)255;

            case MODE22_OCTANE_ADJUST_RATIO_UUID:
                return (((float)256 * (float)((int8_t)data[OBDII_BYTEA]) ) + (float)data[OBDII_BYTEB] ) / (float)16384;

            case MODE1_TIMING_ADVANCE_UUID:
                return ((float)data[OBDII_BYTEA] / (float)2) - (float)64;

        default:
             return 0;
    }
}