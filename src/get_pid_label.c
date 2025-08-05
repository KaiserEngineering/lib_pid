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

uint8_t get_pid_label( uint32_t pid_uuid, char* label )
{
    for( uint8_t i = 0; i < LABEL_MAX_CHAR; i++ )
        label[i] = '\0';

    switch( pid_uuid )
    {
            case MODE1_ACCEL_PEDAL_POS_UUID:
                memcpy(label, MODE1_ACCEL_PEDAL_POS_LABEL, sizeof(MODE1_ACCEL_PEDAL_POS_LABEL));
                break;

            case MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_UUID:
                memcpy(label, MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_LABEL, sizeof(MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_LABEL));
                break;

            case MODE22_AMBIENT_AIR_TEMP_UUID:
                memcpy(label, MODE22_AMBIENT_AIR_TEMP_LABEL, sizeof(MODE22_AMBIENT_AIR_TEMP_LABEL));
                break;

            case MODE1_BAROMETRIC_PRESSURE_UUID:
                memcpy(label, MODE1_BAROMETRIC_PRESSURE_LABEL, sizeof(MODE1_BAROMETRIC_PRESSURE_LABEL));
                break;

            case MODE1_BOOST_UUID:
                memcpy(label, MODE1_BOOST_LABEL, sizeof(MODE1_BOOST_LABEL));
                break;

            case CALC1_BOOST_VACUUM_UUID:
                memcpy(label, CALC1_BOOST_VACUUM_LABEL, sizeof(CALC1_BOOST_VACUUM_LABEL));
                break;

            case SNIFF_BRAKE_PEDAL_STATUS_UUID:
                memcpy(label, SNIFF_BRAKE_PEDAL_STATUS_LABEL, sizeof(SNIFF_BRAKE_PEDAL_STATUS_LABEL));
                break;

            case MODE1_CALC_ENGINE_LOAD_UUID:
                memcpy(label, MODE1_CALC_ENGINE_LOAD_LABEL, sizeof(MODE1_CALC_ENGINE_LOAD_LABEL));
                break;

            case MODE22_CATALYTIC_TEMPERATURE_UUID:
                memcpy(label, MODE22_CATALYTIC_TEMPERATURE_LABEL, sizeof(MODE22_CATALYTIC_TEMPERATURE_LABEL));
                break;

            case MODE22_CHARGE_AIR_TEMP_ST_UUID:
                memcpy(label, MODE22_CHARGE_AIR_TEMP_ST_LABEL, sizeof(MODE22_CHARGE_AIR_TEMP_ST_LABEL));
                break;

            case MODE1_COMMANDED_AIR_FUEL_RATIO_UUID:
                memcpy(label, MODE1_COMMANDED_AIR_FUEL_RATIO_LABEL, sizeof(MODE1_COMMANDED_AIR_FUEL_RATIO_LABEL));
                break;

            case SNIFF_CRUISE_CONTROL_CAN_BUTTON_UUID:
                memcpy(label, SNIFF_CRUISE_CONTROL_CAN_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_CAN_BUTTON_LABEL));
                break;

            case SNIFF_CRUISE_CONTROL_OFF_BUTTON_UUID:
                memcpy(label, SNIFF_CRUISE_CONTROL_OFF_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_OFF_BUTTON_LABEL));
                break;

            case CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UUID:
                memcpy(label, CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_LABEL, sizeof(CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_LABEL));
                break;

            case SNIFF_CRUISE_CONTROL_ON_BUTTON_UUID:
                memcpy(label, SNIFF_CRUISE_CONTROL_ON_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_ON_BUTTON_LABEL));
                break;

            case SNIFF_CRUISE_CONTROL_RES_BUTTON_UUID:
                memcpy(label, SNIFF_CRUISE_CONTROL_RES_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_RES_BUTTON_LABEL));
                break;

            case SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UUID:
                memcpy(label, SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_LABEL));
                break;

            case SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UUID:
                memcpy(label, SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_LABEL));
                break;

            case SNIFF_EMERGENCY_BRAKE_STATUS_UUID:
                memcpy(label, SNIFF_EMERGENCY_BRAKE_STATUS_LABEL, sizeof(SNIFF_EMERGENCY_BRAKE_STATUS_LABEL));
                break;

            case MODE22_ENGINE_LOAD_UUID:
                memcpy(label, MODE22_ENGINE_LOAD_LABEL, sizeof(MODE22_ENGINE_LOAD_LABEL));
                break;

            case MODE1_ENGINE_COOLANT_TEMP_UUID:
                memcpy(label, MODE1_ENGINE_COOLANT_TEMP_LABEL, sizeof(MODE1_ENGINE_COOLANT_TEMP_LABEL));
                break;

            case MODE1_ENGINE_SPEED_UUID:
                memcpy(label, MODE1_ENGINE_SPEED_LABEL, sizeof(MODE1_ENGINE_SPEED_LABEL));
                break;

            case SNIFF_ENGINE_SPEED_UUID:
                memcpy(label, SNIFF_ENGINE_SPEED_LABEL, sizeof(SNIFF_ENGINE_SPEED_LABEL));
                break;

            case MODE1_FUEL_PRESSURE_UUID:
                memcpy(label, MODE1_FUEL_PRESSURE_LABEL, sizeof(MODE1_FUEL_PRESSURE_LABEL));
                break;

            case MODE1_FUEL_RAIL_PRESSURE_UUID:
                memcpy(label, MODE1_FUEL_RAIL_PRESSURE_LABEL, sizeof(MODE1_FUEL_RAIL_PRESSURE_LABEL));
                break;

            case SNIFF_GAUGE_ILLUM_LEVEL_UUID:
                memcpy(label, SNIFF_GAUGE_ILLUM_LEVEL_LABEL, sizeof(SNIFF_GAUGE_ILLUM_LEVEL_LABEL));
                break;

            case MODE22_IGNITION_CORRECTION_CYLINDER_1_UUID:
                memcpy(label, MODE22_IGNITION_CORRECTION_CYLINDER_1_LABEL, sizeof(MODE22_IGNITION_CORRECTION_CYLINDER_1_LABEL));
                break;

            case MODE1_INTAKE_AIR_TEMP_UUID:
                memcpy(label, MODE1_INTAKE_AIR_TEMP_LABEL, sizeof(MODE1_INTAKE_AIR_TEMP_LABEL));
                break;

            case MODE22_INTAKE_AIR_TEMP_UUID:
                memcpy(label, MODE22_INTAKE_AIR_TEMP_LABEL, sizeof(MODE22_INTAKE_AIR_TEMP_LABEL));
                break;

            case MODE22_LP_FUEL_DUTY_CYCLE_UUID:
                memcpy(label, MODE22_LP_FUEL_DUTY_CYCLE_LABEL, sizeof(MODE22_LP_FUEL_DUTY_CYCLE_LABEL));
                break;

            case SNIFF_LATERAL_ACCELERATION_UUID:
                memcpy(label, SNIFF_LATERAL_ACCELERATION_LABEL, sizeof(SNIFF_LATERAL_ACCELERATION_LABEL));
                break;

            case MODE1_LONG_TERM_FUEL_TRIM_BANK_1_UUID:
                memcpy(label, MODE1_LONG_TERM_FUEL_TRIM_BANK_1_LABEL, sizeof(MODE1_LONG_TERM_FUEL_TRIM_BANK_1_LABEL));
                break;

            case MODE1_LONG_TERM_FUEL_TRIM_BANK_2_UUID:
                memcpy(label, MODE1_LONG_TERM_FUEL_TRIM_BANK_2_LABEL, sizeof(MODE1_LONG_TERM_FUEL_TRIM_BANK_2_LABEL));
                break;

            case SNIFF_LONGITUDINAL_ACCELERATION_UUID:
                memcpy(label, SNIFF_LONGITUDINAL_ACCELERATION_LABEL, sizeof(SNIFF_LONGITUDINAL_ACCELERATION_LABEL));
                break;

            case MODE1_MANIFOLD_ABS_PRESS_UUID:
                memcpy(label, MODE1_MANIFOLD_ABS_PRESS_LABEL, sizeof(MODE1_MANIFOLD_ABS_PRESS_LABEL));
                break;

            case MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_UUID:
                memcpy(label, MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_LABEL, sizeof(MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_LABEL));
                break;

            case MODE22_MANIFOLD_CHARGE_TEMP_RS_UUID:
                memcpy(label, MODE22_MANIFOLD_CHARGE_TEMP_RS_LABEL, sizeof(MODE22_MANIFOLD_CHARGE_TEMP_RS_LABEL));
                break;

            case MODE1_MASS_AIR_FLOW_UUID:
                memcpy(label, MODE1_MASS_AIR_FLOW_LABEL, sizeof(MODE1_MASS_AIR_FLOW_LABEL));
                break;

            case MODE1_O2_SENSOR_2_VOLTS_UUID:
                memcpy(label, MODE1_O2_SENSOR_2_VOLTS_LABEL, sizeof(MODE1_O2_SENSOR_2_VOLTS_LABEL));
                break;

            case MODE22_OCTANE_ADJUST_RATIO_UUID:
                memcpy(label, MODE22_OCTANE_ADJUST_RATIO_LABEL, sizeof(MODE22_OCTANE_ADJUST_RATIO_LABEL));
                break;

            case MODE1_OIL_TEMP_UUID:
                memcpy(label, MODE1_OIL_TEMP_LABEL, sizeof(MODE1_OIL_TEMP_LABEL));
                break;

            case SNIFF_REVERSE_STATUS_UUID:
                memcpy(label, SNIFF_REVERSE_STATUS_LABEL, sizeof(SNIFF_REVERSE_STATUS_LABEL));
                break;

            case MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_UUID:
                memcpy(label, MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_LABEL, sizeof(MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_LABEL));
                break;

            case MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_UUID:
                memcpy(label, MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_LABEL, sizeof(MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_LABEL));
                break;

            case MODE1_THROTTLE_POSITION_UUID:
                memcpy(label, MODE1_THROTTLE_POSITION_LABEL, sizeof(MODE1_THROTTLE_POSITION_LABEL));
                break;

            case MODE1_TIMING_ADVANCE_UUID:
                memcpy(label, MODE1_TIMING_ADVANCE_LABEL, sizeof(MODE1_TIMING_ADVANCE_LABEL));
                break;

            case MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UUID:
                memcpy(label, MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_LABEL, sizeof(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_LABEL));
                break;

            case MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UUID:
                memcpy(label, MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_LABEL, sizeof(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_LABEL));
                break;

            case MODE1_VEHICLE_SPEED_UUID:
                memcpy(label, MODE1_VEHICLE_SPEED_LABEL, sizeof(MODE1_VEHICLE_SPEED_LABEL));
                break;

            case SNIFF_VEHICLE_STATUS_UUID:
                memcpy(label, SNIFF_VEHICLE_STATUS_LABEL, sizeof(SNIFF_VEHICLE_STATUS_LABEL));
                break;

            default:
                return 0;
    }
    return 1;
}