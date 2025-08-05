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

PID_UNITS get_pid_base_unit( uint32_t pid_uuid )
{
    switch( pid_uuid )
    {
            case MODE1_ACCEL_PEDAL_POS_UUID:
                return MODE1_ACCEL_PEDAL_POS_UNITS;

            case MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_UUID:
                return MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_UNITS;

            case MODE22_AMBIENT_AIR_TEMP_UUID:
                return MODE22_AMBIENT_AIR_TEMP_UNITS;

            case MODE1_BAROMETRIC_PRESSURE_UUID:
                return MODE1_BAROMETRIC_PRESSURE_UNITS;

            case MODE1_BOOST_UUID:
                return MODE1_BOOST_UNITS;

            case CALC1_BOOST_VACUUM_UUID:
                return CALC1_BOOST_VACUUM_UNITS;

            case SNIFF_BRAKE_PEDAL_STATUS_UUID:
                return SNIFF_BRAKE_PEDAL_STATUS_UNITS;

            case MODE1_CALC_ENGINE_LOAD_UUID:
                return MODE1_CALC_ENGINE_LOAD_UNITS;

            case MODE22_CATALYTIC_TEMPERATURE_UUID:
                return MODE22_CATALYTIC_TEMPERATURE_UNITS;

            case MODE22_CHARGE_AIR_TEMP_ST_UUID:
                return MODE22_CHARGE_AIR_TEMP_ST_UNITS;

            case MODE1_COMMANDED_AIR_FUEL_RATIO_UUID:
                return MODE1_COMMANDED_AIR_FUEL_RATIO_UNITS;

            case SNIFF_CRUISE_CONTROL_CAN_BUTTON_UUID:
                return SNIFF_CRUISE_CONTROL_CAN_BUTTON_UNITS;

            case SNIFF_CRUISE_CONTROL_OFF_BUTTON_UUID:
                return SNIFF_CRUISE_CONTROL_OFF_BUTTON_UNITS;

            case CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UUID:
                return CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UNITS;

            case SNIFF_CRUISE_CONTROL_ON_BUTTON_UUID:
                return SNIFF_CRUISE_CONTROL_ON_BUTTON_UNITS;

            case SNIFF_CRUISE_CONTROL_RES_BUTTON_UUID:
                return SNIFF_CRUISE_CONTROL_RES_BUTTON_UNITS;

            case SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UUID:
                return SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UNITS;

            case SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UUID:
                return SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UNITS;

            case SNIFF_EMERGENCY_BRAKE_STATUS_UUID:
                return SNIFF_EMERGENCY_BRAKE_STATUS_UNITS;

            case MODE22_ENGINE_LOAD_UUID:
                return MODE22_ENGINE_LOAD_UNITS;

            case MODE1_ENGINE_COOLANT_TEMP_UUID:
                return MODE1_ENGINE_COOLANT_TEMP_UNITS;

            case MODE1_ENGINE_SPEED_UUID:
                return MODE1_ENGINE_SPEED_UNITS;

            case SNIFF_ENGINE_SPEED_UUID:
                return SNIFF_ENGINE_SPEED_UNITS;

            case MODE1_FUEL_PRESSURE_UUID:
                return MODE1_FUEL_PRESSURE_UNITS;

            case MODE1_FUEL_RAIL_PRESSURE_UUID:
                return MODE1_FUEL_RAIL_PRESSURE_UNITS;

            case SNIFF_GAUGE_ILLUM_LEVEL_UUID:
                return SNIFF_GAUGE_ILLUM_LEVEL_UNITS;

            case MODE22_IGNITION_CORRECTION_CYLINDER_1_UUID:
                return MODE22_IGNITION_CORRECTION_CYLINDER_1_UNITS;

            case MODE1_INTAKE_AIR_TEMP_UUID:
                return MODE1_INTAKE_AIR_TEMP_UNITS;

            case MODE22_INTAKE_AIR_TEMP_UUID:
                return MODE22_INTAKE_AIR_TEMP_UNITS;

            case MODE22_LP_FUEL_DUTY_CYCLE_UUID:
                return MODE22_LP_FUEL_DUTY_CYCLE_UNITS;

            case SNIFF_LATERAL_ACCELERATION_UUID:
                return SNIFF_LATERAL_ACCELERATION_UNITS;

            case MODE1_LONG_TERM_FUEL_TRIM_BANK_1_UUID:
                return MODE1_LONG_TERM_FUEL_TRIM_BANK_1_UNITS;

            case MODE1_LONG_TERM_FUEL_TRIM_BANK_2_UUID:
                return MODE1_LONG_TERM_FUEL_TRIM_BANK_2_UNITS;

            case SNIFF_LONGITUDINAL_ACCELERATION_UUID:
                return SNIFF_LONGITUDINAL_ACCELERATION_UNITS;

            case MODE1_MANIFOLD_ABS_PRESS_UUID:
                return MODE1_MANIFOLD_ABS_PRESS_UNITS;

            case MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_UUID:
                return MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_UNITS;

            case MODE22_MANIFOLD_CHARGE_TEMP_RS_UUID:
                return MODE22_MANIFOLD_CHARGE_TEMP_RS_UNITS;

            case MODE1_MASS_AIR_FLOW_UUID:
                return MODE1_MASS_AIR_FLOW_UNITS;

            case MODE1_O2_SENSOR_2_VOLTS_UUID:
                return MODE1_O2_SENSOR_2_VOLTS_UNITS;

            case MODE22_OCTANE_ADJUST_RATIO_UUID:
                return MODE22_OCTANE_ADJUST_RATIO_UNITS;

            case MODE1_OIL_TEMP_UUID:
                return MODE1_OIL_TEMP_UNITS;

            case SNIFF_REVERSE_STATUS_UUID:
                return SNIFF_REVERSE_STATUS_UNITS;

            case MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_UUID:
                return MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_UNITS;

            case MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_UUID:
                return MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_UNITS;

            case MODE1_THROTTLE_POSITION_UUID:
                return MODE1_THROTTLE_POSITION_UNITS;

            case MODE1_TIMING_ADVANCE_UUID:
                return MODE1_TIMING_ADVANCE_UNITS;

            case MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UUID:
                return MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UNITS;

            case MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UUID:
                return MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UNITS;

            case MODE1_VEHICLE_SPEED_UUID:
                return MODE1_VEHICLE_SPEED_UNITS;

            case SNIFF_VEHICLE_STATUS_UUID:
                return SNIFF_VEHICLE_STATUS_UNITS;

            default:
                return 0;
    }
}