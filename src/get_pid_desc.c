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

uint8_t get_pid_desc( uint32_t pid_uuid, char* desc )
{
    for( uint8_t i = 0; i < LABEL_MAX_CHAR; i++ )
        desc[i] = '\0';

    switch( pid_uuid )
    {
        #if defined(MODE1_COMMANDED_AIR_TO_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_COMMANDED_AIR_TO_FUEL_RATIO_UUID:
                memcpy(desc, MODE1_COMMANDED_AIR_TO_FUEL_RATIO_DESC, sizeof(MODE1_COMMANDED_AIR_TO_FUEL_RATIO_DESC));
                break;
        #endif

        #if defined(MODE1_CALCULATED_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_CALCULATED_ENGINE_LOAD_UUID:
                memcpy(desc, MODE1_CALCULATED_ENGINE_LOAD_DESC, sizeof(MODE1_CALCULATED_ENGINE_LOAD_DESC));
                break;
        #endif

        #if defined(MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ENGINE_COOLANT_TEMPERATURE_UUID:
                memcpy(desc, MODE1_ENGINE_COOLANT_TEMPERATURE_DESC, sizeof(MODE1_ENGINE_COOLANT_TEMPERATURE_DESC));
                break;
        #endif

        #if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_UUID:
                memcpy(desc, MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_DESC, sizeof(MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_DESC));
                break;
        #endif

        #if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_LONG_TERM_FUEL_TRIM__BANK_1_UUID:
                memcpy(desc, MODE1_LONG_TERM_FUEL_TRIM__BANK_1_DESC, sizeof(MODE1_LONG_TERM_FUEL_TRIM__BANK_1_DESC));
                break;
        #endif

        #if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_UUID:
                memcpy(desc, MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_DESC, sizeof(MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_DESC));
                break;
        #endif

        #if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_LONG_TERM_FUEL_TRIM__BANK_2_UUID:
                memcpy(desc, MODE1_LONG_TERM_FUEL_TRIM__BANK_2_DESC, sizeof(MODE1_LONG_TERM_FUEL_TRIM__BANK_2_DESC));
                break;
        #endif

        #if defined(MODE1_FUEL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_FUEL_PRESSURE_UUID:
                memcpy(desc, MODE1_FUEL_PRESSURE_DESC, sizeof(MODE1_FUEL_PRESSURE_DESC));
                break;
        #endif

        #if defined(MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_UUID:
                memcpy(desc, MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_DESC, sizeof(MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_DESC));
                break;
        #endif

        #if defined(MODE1_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ENGINE_SPEED_UUID:
                memcpy(desc, MODE1_ENGINE_SPEED_DESC, sizeof(MODE1_ENGINE_SPEED_DESC));
                break;
        #endif

        #if defined(MODE1_VEHICLE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_VEHICLE_SPEED_UUID:
                memcpy(desc, MODE1_VEHICLE_SPEED_DESC, sizeof(MODE1_VEHICLE_SPEED_DESC));
                break;
        #endif

        #if defined(MODE1_TIMING_ADVANCE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_TIMING_ADVANCE_UUID:
                memcpy(desc, MODE1_TIMING_ADVANCE_DESC, sizeof(MODE1_TIMING_ADVANCE_DESC));
                break;
        #endif

        #if defined(MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_INTAKE_AIR_TEMPERATURE_UUID:
                memcpy(desc, MODE1_INTAKE_AIR_TEMPERATURE_DESC, sizeof(MODE1_INTAKE_AIR_TEMPERATURE_DESC));
                break;
        #endif

        #if defined(MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_UUID:
                memcpy(desc, MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_DESC, sizeof(MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_DESC));
                break;
        #endif

        #if defined(MODE1_THROTTLE_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_THROTTLE_POSITION_UUID:
                memcpy(desc, MODE1_THROTTLE_POSITION_DESC, sizeof(MODE1_THROTTLE_POSITION_DESC));
                break;
        #endif

        #if defined(MODE1_OXYGEN_SENSOR_2_VOLTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_OXYGEN_SENSOR_2_VOLTAGE_UUID:
                memcpy(desc, MODE1_OXYGEN_SENSOR_2_VOLTAGE_DESC, sizeof(MODE1_OXYGEN_SENSOR_2_VOLTAGE_DESC));
                break;
        #endif

        #if defined(MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_UUID:
                memcpy(desc, MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_DESC, sizeof(MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_DESC));
                break;
        #endif

        #if defined(MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_UUID:
                memcpy(desc, MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_DESC, sizeof(MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_DESC));
                break;
        #endif

        #if defined(MODE1_AIR_TO_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_AIR_TO_FUEL_RATIO_UUID:
                memcpy(desc, MODE1_AIR_TO_FUEL_RATIO_DESC, sizeof(MODE1_AIR_TO_FUEL_RATIO_DESC));
                break;
        #endif

        #if defined(MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_UUID:
                memcpy(desc, MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_DESC, sizeof(MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_DESC));
                break;
        #endif

        #if defined(MODE1_ENGINE_OIL_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ENGINE_OIL_TEMPERATURE_UUID:
                memcpy(desc, MODE1_ENGINE_OIL_TEMPERATURE_DESC, sizeof(MODE1_ENGINE_OIL_TEMPERATURE_DESC));
                break;
        #endif

        #if defined(MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UUID:
                memcpy(desc, MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_DESC, sizeof(MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_DESC));
                break;
        #endif

        #if defined(MODE22_LATERAL_G_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_LATERAL_G_UUID:
                memcpy(desc, MODE22_LATERAL_G_DESC, sizeof(MODE22_LATERAL_G_DESC));
                break;
        #endif

        #if defined(MODE22_LONGITUDE_G_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_LONGITUDE_G_UUID:
                memcpy(desc, MODE22_LONGITUDE_G_DESC, sizeof(MODE22_LONGITUDE_G_DESC));
                break;
        #endif

        #if defined(MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_UUID:
                memcpy(desc, MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_DESC, sizeof(MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_DESC));
                break;
        #endif

        #if defined(MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_UUID:
                memcpy(desc, MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_DESC, sizeof(MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_DESC));
                break;
        #endif

        #if defined(MODE22_IGNITION_CORRECTION_CYLINDER_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_IGNITION_CORRECTION_CYLINDER_1_UUID:
                memcpy(desc, MODE22_IGNITION_CORRECTION_CYLINDER_1_DESC, sizeof(MODE22_IGNITION_CORRECTION_CYLINDER_1_DESC));
                break;
        #endif

        #if defined(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UUID:
                memcpy(desc, MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_DESC, sizeof(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_DESC));
                break;
        #endif

        #if defined(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UUID:
                memcpy(desc, MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_DESC, sizeof(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_DESC));
                break;
        #endif

        #if defined(MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_INTAKE_AIR_TEMPERATURE_UUID:
                memcpy(desc, MODE22_INTAKE_AIR_TEMPERATURE_DESC, sizeof(MODE22_INTAKE_AIR_TEMPERATURE_DESC));
                break;
        #endif

        #if defined(MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_CHARGE_AIR_TEMPERATURE_UUID:
                memcpy(desc, MODE22_CHARGE_AIR_TEMPERATURE_DESC, sizeof(MODE22_CHARGE_AIR_TEMPERATURE_DESC));
                break;
        #endif

        #if defined(MODE22_MANIFOLD_CHARGE_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_MANIFOLD_CHARGE_TEMPERATURE_UUID:
                memcpy(desc, MODE22_MANIFOLD_CHARGE_TEMPERATURE_DESC, sizeof(MODE22_MANIFOLD_CHARGE_TEMPERATURE_DESC));
                break;
        #endif

        #if defined(MODE22_OCTANE_ADJUST_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_OCTANE_ADJUST_RATIO_UUID:
                memcpy(desc, MODE22_OCTANE_ADJUST_RATIO_DESC, sizeof(MODE22_OCTANE_ADJUST_RATIO_DESC));
                break;
        #endif

        #if defined(MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_AMBIENT_AIR_TEMPERATURE_UUID:
                memcpy(desc, MODE22_AMBIENT_AIR_TEMPERATURE_DESC, sizeof(MODE22_AMBIENT_AIR_TEMPERATURE_DESC));
                break;
        #endif

        #if defined(MODE22_ENGINE_LOAD_PERCENTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_ENGINE_LOAD_PERCENTAGE_UUID:
                memcpy(desc, MODE22_ENGINE_LOAD_PERCENTAGE_DESC, sizeof(MODE22_ENGINE_LOAD_PERCENTAGE_DESC));
                break;
        #endif

        #if defined(MODE22_CATALYTIC_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_CATALYTIC_TEMPERATURE_UUID:
                memcpy(desc, MODE22_CATALYTIC_TEMPERATURE_DESC, sizeof(MODE22_CATALYTIC_TEMPERATURE_DESC));
                break;
        #endif

        #if defined(SNIFF_GAUGE_BRIGHTNESS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_GAUGE_BRIGHTNESS_UUID:
                memcpy(desc, SNIFF_GAUGE_BRIGHTNESS_DESC, sizeof(SNIFF_GAUGE_BRIGHTNESS_DESC));
                break;
        #endif

        #if defined(SNIFF_VEHICLE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_VEHICLE_STATUS_UUID:
                memcpy(desc, SNIFF_VEHICLE_STATUS_DESC, sizeof(SNIFF_VEHICLE_STATUS_DESC));
                break;
        #endif

        #if defined(SNIFF_BRAKE_PEDAL_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_BRAKE_PEDAL_STATUS_UUID:
                memcpy(desc, SNIFF_BRAKE_PEDAL_STATUS_DESC, sizeof(SNIFF_BRAKE_PEDAL_STATUS_DESC));
                break;
        #endif

        #if defined(SNIFF_EMERGENCY_BRAKE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_EMERGENCY_BRAKE_STATUS_UUID:
                memcpy(desc, SNIFF_EMERGENCY_BRAKE_STATUS_DESC, sizeof(SNIFF_EMERGENCY_BRAKE_STATUS_DESC));
                break;
        #endif

        #if defined(SNIFF_REVERSE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_REVERSE_STATUS_UUID:
                memcpy(desc, SNIFF_REVERSE_STATUS_DESC, sizeof(SNIFF_REVERSE_STATUS_DESC));
                break;
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_ON_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_ON_BUTTON_UUID:
                memcpy(desc, SNIFF_CRUISE_CONTROL_ON_BUTTON_DESC, sizeof(SNIFF_CRUISE_CONTROL_ON_BUTTON_DESC));
                break;
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_OFF_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_OFF_BUTTON_UUID:
                memcpy(desc, SNIFF_CRUISE_CONTROL_OFF_BUTTON_DESC, sizeof(SNIFF_CRUISE_CONTROL_OFF_BUTTON_DESC));
                break;
        #endif

        #if defined(CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UUID:
                memcpy(desc, CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_DESC, sizeof(CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_DESC));
                break;
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UUID:
                memcpy(desc, SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_DESC, sizeof(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_DESC));
                break;
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UUID:
                memcpy(desc, SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_DESC, sizeof(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_DESC));
                break;
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_RES_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_RES_BUTTON_UUID:
                memcpy(desc, SNIFF_CRUISE_CONTROL_RES_BUTTON_DESC, sizeof(SNIFF_CRUISE_CONTROL_RES_BUTTON_DESC));
                break;
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_CAN_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_CAN_BUTTON_UUID:
                memcpy(desc, SNIFF_CRUISE_CONTROL_CAN_BUTTON_DESC, sizeof(SNIFF_CRUISE_CONTROL_CAN_BUTTON_DESC));
                break;
        #endif

        #if defined(CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UUID:
                memcpy(desc, CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_DESC, sizeof(CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_DESC));
                break;
        #endif

        #if defined(SNIFF_LATERAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_LATERAL_ACCELERATION_UUID:
                memcpy(desc, SNIFF_LATERAL_ACCELERATION_DESC, sizeof(SNIFF_LATERAL_ACCELERATION_DESC));
                break;
        #endif

        #if defined(SNIFF_LONGITUDINAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_LONGITUDINAL_ACCELERATION_UUID:
                memcpy(desc, SNIFF_LONGITUDINAL_ACCELERATION_DESC, sizeof(SNIFF_LONGITUDINAL_ACCELERATION_DESC));
                break;
        #endif

            default:
                return 0;
    }
    return 1;
}