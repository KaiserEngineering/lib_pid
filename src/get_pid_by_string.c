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

uint32_t get_pid_by_string(const char *str)
{
        if(strcmp(str, MODE1_ACCEL_PEDAL_POS_DESC) == 0) return MODE1_ACCEL_PEDAL_POS_UUID;

        if(strcmp(str, MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_DESC) == 0) return MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_UUID;

        if(strcmp(str, MODE22_AMBIENT_AIR_TEMP_DESC) == 0) return MODE22_AMBIENT_AIR_TEMP_UUID;

        if(strcmp(str, MODE1_BAROMETRIC_PRESSURE_DESC) == 0) return MODE1_BAROMETRIC_PRESSURE_UUID;

        if(strcmp(str, MODE1_BOOST_DESC) == 0) return MODE1_BOOST_UUID;

        if(strcmp(str, CALC1_BOOST_VACUUM_DESC) == 0) return CALC1_BOOST_VACUUM_UUID;

        if(strcmp(str, SNIFF_BRAKE_PEDAL_STATUS_DESC) == 0) return SNIFF_BRAKE_PEDAL_STATUS_UUID;

        if(strcmp(str, MODE1_CALC_ENGINE_LOAD_DESC) == 0) return MODE1_CALC_ENGINE_LOAD_UUID;

        if(strcmp(str, MODE22_CATALYTIC_TEMPERATURE_DESC) == 0) return MODE22_CATALYTIC_TEMPERATURE_UUID;

        if(strcmp(str, MODE22_CHARGE_AIR_TEMP_DESC) == 0) return MODE22_CHARGE_AIR_TEMP_UUID;

        if(strcmp(str, MODE1_COMMANDED_AIR_FUEL_RATIO_DESC) == 0) return MODE1_COMMANDED_AIR_FUEL_RATIO_UUID;

        if(strcmp(str, SNIFF_CRUISE_CONTROL_CAN_BUTTON_DESC) == 0) return SNIFF_CRUISE_CONTROL_CAN_BUTTON_UUID;

        if(strcmp(str, SNIFF_CRUISE_CONTROL_OFF_BUTTON_DESC) == 0) return SNIFF_CRUISE_CONTROL_OFF_BUTTON_UUID;

        if(strcmp(str, CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_DESC) == 0) return CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UUID;

        if(strcmp(str, SNIFF_CRUISE_CONTROL_ON_BUTTON_DESC) == 0) return SNIFF_CRUISE_CONTROL_ON_BUTTON_UUID;

        if(strcmp(str, SNIFF_CRUISE_CONTROL_RES_BUTTON_DESC) == 0) return SNIFF_CRUISE_CONTROL_RES_BUTTON_UUID;

        if(strcmp(str, SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_DESC) == 0) return SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UUID;

        if(strcmp(str, SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_DESC) == 0) return SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UUID;

        if(strcmp(str, SNIFF_EMERGENCY_BRAKE_STATUS_DESC) == 0) return SNIFF_EMERGENCY_BRAKE_STATUS_UUID;

        if(strcmp(str, MODE22_ENGINE_LOAD_DESC) == 0) return MODE22_ENGINE_LOAD_UUID;

        if(strcmp(str, MODE1_ENGINE_COOLANT_TEMP_DESC) == 0) return MODE1_ENGINE_COOLANT_TEMP_UUID;

        if(strcmp(str, MODE1_ENGINE_SPEED_DESC) == 0) return MODE1_ENGINE_SPEED_UUID;

        if(strcmp(str, SNIFF_ENGINE_SPEED_DESC) == 0) return SNIFF_ENGINE_SPEED_UUID;

        if(strcmp(str, MODE1_FUEL_PRESSURE_DESC) == 0) return MODE1_FUEL_PRESSURE_UUID;

        if(strcmp(str, MODE1_FUEL_RAIL_PRESSURE_DESC) == 0) return MODE1_FUEL_RAIL_PRESSURE_UUID;

        if(strcmp(str, SNIFF_GAUGE_ILLUM_LEVEL_DESC) == 0) return SNIFF_GAUGE_ILLUM_LEVEL_UUID;

        if(strcmp(str, MODE22_IGNITION_CORRECTION_CYLINDER_1_DESC) == 0) return MODE22_IGNITION_CORRECTION_CYLINDER_1_UUID;

        if(strcmp(str, MODE1_INTAKE_AIR_TEMP_DESC) == 0) return MODE1_INTAKE_AIR_TEMP_UUID;

        if(strcmp(str, MODE22_INTAKE_AIR_TEMP_DESC) == 0) return MODE22_INTAKE_AIR_TEMP_UUID;

        if(strcmp(str, MODE22_LP_FUEL_DUTY_CYCLE_DESC) == 0) return MODE22_LP_FUEL_DUTY_CYCLE_UUID;

        if(strcmp(str, SNIFF_LATERAL_ACCELERATION_DESC) == 0) return SNIFF_LATERAL_ACCELERATION_UUID;

        if(strcmp(str, MODE1_LONG_TERM_FUEL_TRIM_BANK_1_DESC) == 0) return MODE1_LONG_TERM_FUEL_TRIM_BANK_1_UUID;

        if(strcmp(str, MODE1_LONG_TERM_FUEL_TRIM_BANK_2_DESC) == 0) return MODE1_LONG_TERM_FUEL_TRIM_BANK_2_UUID;

        if(strcmp(str, SNIFF_LONGITUDINAL_ACCELERATION_DESC) == 0) return SNIFF_LONGITUDINAL_ACCELERATION_UUID;

        if(strcmp(str, MODE1_MANIFOLD_ABS_PRESS_DESC) == 0) return MODE1_MANIFOLD_ABS_PRESS_UUID;

        if(strcmp(str, MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_DESC) == 0) return MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_UUID;

        if(strcmp(str, MODE22_MANIFOLD_CHARGE_TEMP_DESC) == 0) return MODE22_MANIFOLD_CHARGE_TEMP_UUID;

        if(strcmp(str, MODE1_MASS_AIR_FLOW_DESC) == 0) return MODE1_MASS_AIR_FLOW_UUID;

        if(strcmp(str, MODE1_O2_SENSOR_2_VOLTS_DESC) == 0) return MODE1_O2_SENSOR_2_VOLTS_UUID;

        if(strcmp(str, MODE22_OCTANE_ADJUST_RATIO_DESC) == 0) return MODE22_OCTANE_ADJUST_RATIO_UUID;

        if(strcmp(str, MODE1_OIL_TEMP_DESC) == 0) return MODE1_OIL_TEMP_UUID;

        if(strcmp(str, SNIFF_REVERSE_STATUS_DESC) == 0) return SNIFF_REVERSE_STATUS_UUID;

        if(strcmp(str, MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_DESC) == 0) return MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_UUID;

        if(strcmp(str, MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_DESC) == 0) return MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_UUID;

        if(strcmp(str, MODE1_THROTTLE_POSITION_DESC) == 0) return MODE1_THROTTLE_POSITION_UUID;

        if(strcmp(str, MODE1_TIMING_ADVANCE_DESC) == 0) return MODE1_TIMING_ADVANCE_UUID;

        if(strcmp(str, MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_DESC) == 0) return MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UUID;

        if(strcmp(str, MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_DESC) == 0) return MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UUID;

        if(strcmp(str, MODE1_VEHICLE_SPEED_DESC) == 0) return MODE1_VEHICLE_SPEED_UUID;

        if(strcmp(str, SNIFF_VEHICLE_STATUS_DESC) == 0) return SNIFF_VEHICLE_STATUS_UUID;

    return 0x00000000;
}
