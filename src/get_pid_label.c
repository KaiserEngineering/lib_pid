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

uint8_t get_pid_label( uint8_t mode, uint16_t pid, char* label )
{
    switch( mode )
    {
        case MODE1:
            switch( pid )
            {
                #if defined(MODE1_COMMANDED_AIR_TO_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_COMMANDED_AIR_TO_FUEL_RATIO_PID:
                    memcpy(label, MODE1_COMMANDED_AIR_TO_FUEL_RATIO_LABEL, sizeof(MODE1_COMMANDED_AIR_TO_FUEL_RATIO_LABEL));
                    break;
                #endif

                #if defined(MODE1_CALCULATED_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_CALCULATED_ENGINE_LOAD_PID:
                    memcpy(label, MODE1_CALCULATED_ENGINE_LOAD_LABEL, sizeof(MODE1_CALCULATED_ENGINE_LOAD_LABEL));
                    break;
                #endif

                #if defined(MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_ENGINE_COOLANT_TEMPERATURE_PID:
                    memcpy(label, MODE1_ENGINE_COOLANT_TEMPERATURE_LABEL, sizeof(MODE1_ENGINE_COOLANT_TEMPERATURE_LABEL));
                    break;
                #endif

                #if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_PID:
                    memcpy(label, MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_LABEL, sizeof(MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_LABEL));
                    break;
                #endif

                #if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_LONG_TERM_FUEL_TRIM__BANK_1_PID:
                    memcpy(label, MODE1_LONG_TERM_FUEL_TRIM__BANK_1_LABEL, sizeof(MODE1_LONG_TERM_FUEL_TRIM__BANK_1_LABEL));
                    break;
                #endif

                #if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_PID:
                    memcpy(label, MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_LABEL, sizeof(MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_LABEL));
                    break;
                #endif

                #if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_LONG_TERM_FUEL_TRIM__BANK_2_PID:
                    memcpy(label, MODE1_LONG_TERM_FUEL_TRIM__BANK_2_LABEL, sizeof(MODE1_LONG_TERM_FUEL_TRIM__BANK_2_LABEL));
                    break;
                #endif

                #if defined(MODE1_FUEL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_FUEL_PRESSURE_PID:
                    memcpy(label, MODE1_FUEL_PRESSURE_LABEL, sizeof(MODE1_FUEL_PRESSURE_LABEL));
                    break;
                #endif

                #if defined(MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_PID:
                    memcpy(label, MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LABEL, sizeof(MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LABEL));
                    break;
                #endif

                #if defined(MODE1_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_ENGINE_SPEED_PID:
                    memcpy(label, MODE1_ENGINE_SPEED_LABEL, sizeof(MODE1_ENGINE_SPEED_LABEL));
                    break;
                #endif

                #if defined(MODE1_VEHICLE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_VEHICLE_SPEED_PID:
                    memcpy(label, MODE1_VEHICLE_SPEED_LABEL, sizeof(MODE1_VEHICLE_SPEED_LABEL));
                    break;
                #endif

                #if defined(MODE1_TIMING_ADVANCE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_TIMING_ADVANCE_PID:
                    memcpy(label, MODE1_TIMING_ADVANCE_LABEL, sizeof(MODE1_TIMING_ADVANCE_LABEL));
                    break;
                #endif

                #if defined(MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_INTAKE_AIR_TEMPERATURE_PID:
                    memcpy(label, MODE1_INTAKE_AIR_TEMPERATURE_LABEL, sizeof(MODE1_INTAKE_AIR_TEMPERATURE_LABEL));
                    break;
                #endif

                #if defined(MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_PID:
                    memcpy(label, MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_LABEL, sizeof(MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_LABEL));
                    break;
                #endif

                #if defined(MODE1_THROTTLE_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_THROTTLE_POSITION_PID:
                    memcpy(label, MODE1_THROTTLE_POSITION_LABEL, sizeof(MODE1_THROTTLE_POSITION_LABEL));
                    break;
                #endif

                #if defined(MODE1_OXYGEN_SENSOR_2_VOLTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_OXYGEN_SENSOR_2_VOLTAGE_PID:
                    memcpy(label, MODE1_OXYGEN_SENSOR_2_VOLTAGE_LABEL, sizeof(MODE1_OXYGEN_SENSOR_2_VOLTAGE_LABEL));
                    break;
                #endif

                #if defined(MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_PID:
                    memcpy(label, MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_LABEL, sizeof(MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_LABEL));
                    break;
                #endif

                #if defined(MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_PID:
                    memcpy(label, MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_LABEL, sizeof(MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_LABEL));
                    break;
                #endif

                #if defined(MODE1_AIR_TO_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_AIR_TO_FUEL_RATIO_PID:
                    memcpy(label, MODE1_AIR_TO_FUEL_RATIO_LABEL, sizeof(MODE1_AIR_TO_FUEL_RATIO_LABEL));
                    break;
                #endif

                #if defined(MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_PID:
                    memcpy(label, MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_LABEL, sizeof(MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_LABEL));
                    break;
                #endif

                #if defined(MODE1_ENGINE_OIL_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_ENGINE_OIL_TEMPERATURE_PID:
                    memcpy(label, MODE1_ENGINE_OIL_TEMPERATURE_LABEL, sizeof(MODE1_ENGINE_OIL_TEMPERATURE_LABEL));
                    break;
                #endif

                #if defined(MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_PID:
                    memcpy(label, MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LABEL, sizeof(MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LABEL));
                    break;
                #endif

                default:
                    return 0;
            }
        break;

        case MODE22:
            switch( pid )
            {
                #if defined(MODE22_LATERAL_G_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_LATERAL_G_PID:
                    memcpy(label, MODE22_LATERAL_G_LABEL, sizeof(MODE22_LATERAL_G_LABEL));
                    break;
                #endif

                #if defined(MODE22_LONGITUDE_G_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_LONGITUDE_G_PID:
                    memcpy(label, MODE22_LONGITUDE_G_LABEL, sizeof(MODE22_LONGITUDE_G_LABEL));
                    break;
                #endif

                #if defined(MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_PID:
                    memcpy(label, MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_LABEL, sizeof(MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_LABEL));
                    break;
                #endif

                #if defined(MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_PID:
                    memcpy(label, MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_LABEL, sizeof(MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_LABEL));
                    break;
                #endif

                #if defined(MODE22_IGNITION_CORRECTION_CYLINDER_1_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_IGNITION_CORRECTION_CYLINDER_1_PID:
                    memcpy(label, MODE22_IGNITION_CORRECTION_CYLINDER_1_LABEL, sizeof(MODE22_IGNITION_CORRECTION_CYLINDER_1_LABEL));
                    break;
                #endif

                #if defined(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_PID:
                    memcpy(label, MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_LABEL, sizeof(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_LABEL));
                    break;
                #endif

                #if defined(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_PID:
                    memcpy(label, MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_LABEL, sizeof(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_LABEL));
                    break;
                #endif

                #if defined(MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_INTAKE_AIR_TEMPERATURE_PID:
                    memcpy(label, MODE22_INTAKE_AIR_TEMPERATURE_LABEL, sizeof(MODE22_INTAKE_AIR_TEMPERATURE_LABEL));
                    break;
                #endif

                #if defined(MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_CHARGE_AIR_TEMPERATURE_PID:
                    memcpy(label, MODE22_CHARGE_AIR_TEMPERATURE_LABEL, sizeof(MODE22_CHARGE_AIR_TEMPERATURE_LABEL));
                    break;
                #endif

                #if defined(MODE22_MANIFOLD_CHARGE_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_MANIFOLD_CHARGE_TEMPERATURE_PID:
                    memcpy(label, MODE22_MANIFOLD_CHARGE_TEMPERATURE_LABEL, sizeof(MODE22_MANIFOLD_CHARGE_TEMPERATURE_LABEL));
                    break;
                #endif

                #if defined(MODE22_OCTANE_ADJUST_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_OCTANE_ADJUST_RATIO_PID:
                    memcpy(label, MODE22_OCTANE_ADJUST_RATIO_LABEL, sizeof(MODE22_OCTANE_ADJUST_RATIO_LABEL));
                    break;
                #endif

                #if defined(MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_AMBIENT_AIR_TEMPERATURE_PID:
                    memcpy(label, MODE22_AMBIENT_AIR_TEMPERATURE_LABEL, sizeof(MODE22_AMBIENT_AIR_TEMPERATURE_LABEL));
                    break;
                #endif

                #if defined(MODE22_ENGINE_LOAD_PERCENTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_ENGINE_LOAD_PERCENTAGE_PID:
                    memcpy(label, MODE22_ENGINE_LOAD_PERCENTAGE_LABEL, sizeof(MODE22_ENGINE_LOAD_PERCENTAGE_LABEL));
                    break;
                #endif

                #if defined(MODE22_CATALYTIC_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case MODE22_CATALYTIC_TEMPERATURE_PID:
                    memcpy(label, MODE22_CATALYTIC_TEMPERATURE_LABEL, sizeof(MODE22_CATALYTIC_TEMPERATURE_LABEL));
                    break;
                #endif

                default:
                    return 0;
            }
        break;

        case SNIFF:
            switch( pid )
            {
                #if defined(SNIFF_GAUGE_BRIGHTNESS_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_GAUGE_BRIGHTNESS_PID:
                    memcpy(label, SNIFF_GAUGE_BRIGHTNESS_LABEL, sizeof(SNIFF_GAUGE_BRIGHTNESS_LABEL));
                    break;
                #endif

                #if defined(SNIFF_VEHICLE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_VEHICLE_STATUS_PID:
                    memcpy(label, SNIFF_VEHICLE_STATUS_LABEL, sizeof(SNIFF_VEHICLE_STATUS_LABEL));
                    break;
                #endif

                #if defined(SNIFF_BRAKE_PEDAL_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_BRAKE_PEDAL_STATUS_PID:
                    memcpy(label, SNIFF_BRAKE_PEDAL_STATUS_LABEL, sizeof(SNIFF_BRAKE_PEDAL_STATUS_LABEL));
                    break;
                #endif

                #if defined(SNIFF_EMERGENCY_BRAKE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_EMERGENCY_BRAKE_STATUS_PID:
                    memcpy(label, SNIFF_EMERGENCY_BRAKE_STATUS_LABEL, sizeof(SNIFF_EMERGENCY_BRAKE_STATUS_LABEL));
                    break;
                #endif

                #if defined(SNIFF_REVERSE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_REVERSE_STATUS_PID:
                    memcpy(label, SNIFF_REVERSE_STATUS_LABEL, sizeof(SNIFF_REVERSE_STATUS_LABEL));
                    break;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_ON_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_ON_BUTTON_PID:
                    memcpy(label, SNIFF_CRUISE_CONTROL_ON_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_ON_BUTTON_LABEL));
                    break;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_OFF_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_OFF_BUTTON_PID:
                    memcpy(label, SNIFF_CRUISE_CONTROL_OFF_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_OFF_BUTTON_LABEL));
                    break;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_PID:
                    memcpy(label, SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_LABEL));
                    break;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_PID:
                    memcpy(label, SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_LABEL));
                    break;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_RES_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_RES_BUTTON_PID:
                    memcpy(label, SNIFF_CRUISE_CONTROL_RES_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_RES_BUTTON_LABEL));
                    break;
                #endif

                #if defined(SNIFF_CRUISE_CONTROL_CAN_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_CRUISE_CONTROL_CAN_BUTTON_PID:
                    memcpy(label, SNIFF_CRUISE_CONTROL_CAN_BUTTON_LABEL, sizeof(SNIFF_CRUISE_CONTROL_CAN_BUTTON_LABEL));
                    break;
                #endif

                #if defined(SNIFF_LATERAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_LATERAL_ACCELERATION_PID:
                    memcpy(label, SNIFF_LATERAL_ACCELERATION_LABEL, sizeof(SNIFF_LATERAL_ACCELERATION_LABEL));
                    break;
                #endif

                #if defined(SNIFF_LONGITUDINAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
                case SNIFF_LONGITUDINAL_ACCELERATION_PID:
                    memcpy(label, SNIFF_LONGITUDINAL_ACCELERATION_LABEL, sizeof(SNIFF_LONGITUDINAL_ACCELERATION_LABEL));
                    break;
                #endif

                default:
                    return 0;
            }
        break;

        case CALC1:
            switch( pid )
            {
                #if defined(CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_SUPPORTED) || !defined(LIMIT_PIDS)
                case CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_PID:
                    memcpy(label, CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_LABEL, sizeof(CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_LABEL));
                    break;
                #endif

                #if defined(CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
                case CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_PID:
                    memcpy(label, CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LABEL, sizeof(CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LABEL));
                    break;
                #endif

                default:
                    return 0;
            }
        break;

        default:
            return 0;
    }
}
