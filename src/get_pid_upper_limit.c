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

float get_pid_upper_limit( uint32_t pid_uuid, PID_UNITS unit )
{
    switch( pid_uuid )
    {
        #if defined(MODE1_COMMANDED_AIR_TO_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_COMMANDED_AIR_TO_FUEL_RATIO_UUID:
                switch( unit )
                {
                    case PID_UNITS_RATIO:
                        return MODE1_COMMANDED_AIR_TO_FUEL_RATIO_RATIO_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_CALCULATED_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_CALCULATED_ENGINE_LOAD_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE1_CALCULATED_ENGINE_LOAD_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ENGINE_COOLANT_TEMPERATURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_CELSIUS:
                        return MODE1_ENGINE_COOLANT_TEMPERATURE_CELSIUS_UPPER;

                    case PID_UNITS_FAHRENHEIT:
                        return MODE1_ENGINE_COOLANT_TEMPERATURE_FAHRENHEIT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_LONG_TERM_FUEL_TRIM__BANK_1_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE1_LONG_TERM_FUEL_TRIM__BANK_1_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_LONG_TERM_FUEL_TRIM__BANK_2_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE1_LONG_TERM_FUEL_TRIM__BANK_2_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_FUEL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_FUEL_PRESSURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_KPA:
                        return MODE1_FUEL_PRESSURE_KPA_UPPER;

                    case PID_UNITS_PSI:
                        return MODE1_FUEL_PRESSURE_PSI_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_KPA:
                        return MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_KPA_UPPER;

                    case PID_UNITS_PSI:
                        return MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_PSI_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ENGINE_SPEED_UUID:
                switch( unit )
                {
                    case PID_UNITS_RPM:
                        return MODE1_ENGINE_SPEED_RPM_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_VEHICLE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_VEHICLE_SPEED_UUID:
                switch( unit )
                {
                    case PID_UNITS_KMH:
                        return MODE1_VEHICLE_SPEED_KMH_UPPER;

                    case PID_UNITS_MPH:
                        return MODE1_VEHICLE_SPEED_MPH_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_TIMING_ADVANCE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_TIMING_ADVANCE_UUID:
                switch( unit )
                {
                    case PID_UNITS_DEGREES:
                        return MODE1_TIMING_ADVANCE_DEGREES_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_INTAKE_AIR_TEMPERATURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_CELSIUS:
                        return MODE1_INTAKE_AIR_TEMPERATURE_CELSIUS_UPPER;

                    case PID_UNITS_FAHRENHEIT:
                        return MODE1_INTAKE_AIR_TEMPERATURE_FAHRENHEIT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_UUID:
                switch( unit )
                {
                    case PID_UNITS_GRAMSEC:
                        return MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_GRAMSEC_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_THROTTLE_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_THROTTLE_POSITION_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE1_THROTTLE_POSITION_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_OXYGEN_SENSOR_2_VOLTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_OXYGEN_SENSOR_2_VOLTAGE_UUID:
                switch( unit )
                {
                    case PID_UNITS_VOLTS:
                        return MODE1_OXYGEN_SENSOR_2_VOLTAGE_VOLTS_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_UUID:
                switch( unit )
                {
                    case PID_UNITS_KPA:
                        return MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_KPA_UPPER;

                    case PID_UNITS_PSI:
                        return MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_PSI_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_KPA:
                        return MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_KPA_UPPER;

                    case PID_UNITS_PSI:
                        return MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_PSI_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_AIR_TO_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_AIR_TO_FUEL_RATIO_UUID:
                switch( unit )
                {
                    case PID_UNITS_RATIO:
                        return MODE1_AIR_TO_FUEL_RATIO_RATIO_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_ENGINE_OIL_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ENGINE_OIL_TEMPERATURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_CELSIUS:
                        return MODE1_ENGINE_OIL_TEMPERATURE_CELSIUS_UPPER;

                    case PID_UNITS_FAHRENHEIT:
                        return MODE1_ENGINE_OIL_TEMPERATURE_FAHRENHEIT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_KPA:
                        return MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_KPA_UPPER;

                    case PID_UNITS_PSI:
                        return MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_PSI_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_LATERAL_G_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_LATERAL_G_UUID:
                switch( unit )
                {
                    case PID_UNITS_G_FORCE:
                        return MODE22_LATERAL_G_G_FORCE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_LONGITUDE_G_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_LONGITUDE_G_UUID:
                switch( unit )
                {
                    case PID_UNITS_G_FORCE:
                        return MODE22_LONGITUDE_G_G_FORCE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_UUID:
                switch( unit )
                {
                    case PID_UNITS_VOLTS:
                        return MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_VOLTS_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_IGNITION_CORRECTION_CYLINDER_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_IGNITION_CORRECTION_CYLINDER_1_UUID:
                switch( unit )
                {
                    case PID_UNITS_DEGREES:
                        return MODE22_IGNITION_CORRECTION_CYLINDER_1_DEGREES_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_INTAKE_AIR_TEMPERATURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_CELSIUS:
                        return MODE22_INTAKE_AIR_TEMPERATURE_CELSIUS_UPPER;

                    case PID_UNITS_FAHRENHEIT:
                        return MODE22_INTAKE_AIR_TEMPERATURE_FAHRENHEIT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_CHARGE_AIR_TEMPERATURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_CELSIUS:
                        return MODE22_CHARGE_AIR_TEMPERATURE_CELSIUS_UPPER;

                    case PID_UNITS_FAHRENHEIT:
                        return MODE22_CHARGE_AIR_TEMPERATURE_FAHRENHEIT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_MANIFOLD_CHARGE_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_MANIFOLD_CHARGE_TEMPERATURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_CELSIUS:
                        return MODE22_MANIFOLD_CHARGE_TEMPERATURE_CELSIUS_UPPER;

                    case PID_UNITS_FAHRENHEIT:
                        return MODE22_MANIFOLD_CHARGE_TEMPERATURE_FAHRENHEIT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_OCTANE_ADJUST_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_OCTANE_ADJUST_RATIO_UUID:
                switch( unit )
                {
                    case PID_UNITS_RATIO:
                        return MODE22_OCTANE_ADJUST_RATIO_RATIO_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_AMBIENT_AIR_TEMPERATURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_CELSIUS:
                        return MODE22_AMBIENT_AIR_TEMPERATURE_CELSIUS_UPPER;

                    case PID_UNITS_FAHRENHEIT:
                        return MODE22_AMBIENT_AIR_TEMPERATURE_FAHRENHEIT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_ENGINE_LOAD_PERCENTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_ENGINE_LOAD_PERCENTAGE_UUID:
                switch( unit )
                {
                    case PID_UNITS_PERCENT:
                        return MODE22_ENGINE_LOAD_PERCENTAGE_PERCENT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(MODE22_CATALYTIC_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_CATALYTIC_TEMPERATURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_CELSIUS:
                        return MODE22_CATALYTIC_TEMPERATURE_CELSIUS_UPPER;

                    case PID_UNITS_FAHRENHEIT:
                        return MODE22_CATALYTIC_TEMPERATURE_FAHRENHEIT_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_GAUGE_BRIGHTNESS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_GAUGE_BRIGHTNESS_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_GAUGE_BRIGHTNESS_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_VEHICLE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_VEHICLE_STATUS_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_VEHICLE_STATUS_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_BRAKE_PEDAL_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_BRAKE_PEDAL_STATUS_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_BRAKE_PEDAL_STATUS_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_EMERGENCY_BRAKE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_EMERGENCY_BRAKE_STATUS_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_EMERGENCY_BRAKE_STATUS_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_REVERSE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_REVERSE_STATUS_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_REVERSE_STATUS_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_ON_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_ON_BUTTON_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_CRUISE_CONTROL_ON_BUTTON_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_OFF_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_OFF_BUTTON_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_CRUISE_CONTROL_OFF_BUTTON_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_RES_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_RES_BUTTON_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_CRUISE_CONTROL_RES_BUTTON_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_CAN_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_CAN_BUTTON_UUID:
                switch( unit )
                {
                    case PID_UNITS_NONE:
                        return SNIFF_CRUISE_CONTROL_CAN_BUTTON_NONE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UUID:
                switch( unit )
                {
                    case PID_UNITS_KPA:
                        return CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_KPA_UPPER;

                    case PID_UNITS_PSI:
                        return CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_PSI_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_LATERAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_LATERAL_ACCELERATION_UUID:
                switch( unit )
                {
                    case PID_UNITS_G_FORCE:
                        return SNIFF_LATERAL_ACCELERATION_G_FORCE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

        #if defined(SNIFF_LONGITUDINAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_LONGITUDINAL_ACCELERATION_UUID:
                switch( unit )
                {
                    case PID_UNITS_G_FORCE:
                        return SNIFF_LONGITUDINAL_ACCELERATION_G_FORCE_UPPER;

                    default:
                        return LIMIT_ERROR;

                }
        #endif

            default:
                return 0;
    }
}