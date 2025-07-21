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

static const PID_UNITS celsius_fahrenheit_list[] = {PID_UNITS_CELSIUS, PID_UNITS_FAHRENHEIT};
static const PID_UNITS degrees_list[] = {PID_UNITS_DEGREES};
static const PID_UNITS gramsec_list[] = {PID_UNITS_GRAMSEC};
static const PID_UNITS g_force_list[] = {PID_UNITS_G_FORCE};
static const PID_UNITS kmh_mph_list[] = {PID_UNITS_KMH, PID_UNITS_MPH};
static const PID_UNITS kpa_psi_list[] = {PID_UNITS_KPA, PID_UNITS_PSI};
static const PID_UNITS none_list[] = {PID_UNITS_NONE};
static const PID_UNITS percent_list[] = {PID_UNITS_PERCENT};
static const PID_UNITS ratio_list[] = {PID_UNITS_RATIO};
static const PID_UNITS rpm_list[] = {PID_UNITS_RPM};
static const PID_UNITS volts_list[] = {PID_UNITS_VOLTS};

uint8_t get_pid_units( uint32_t pid_uuid, const PID_UNITS **units )
{
    switch( pid_uuid )
    {
        #if defined(MODE1_COMMANDED_AIR_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_COMMANDED_AIR_FUEL_RATIO_UUID:
                *units = ratio_list;
                return sizeof(ratio_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_CALC_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_CALC_ENGINE_LOAD_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_ENGINE_COOLANT_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ENGINE_COOLANT_TEMP_UUID:
                *units = celsius_fahrenheit_list;
                return sizeof(celsius_fahrenheit_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_LONG_TERM_FUEL_TRIM_BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_LONG_TERM_FUEL_TRIM_BANK_1_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_LONG_TERM_FUEL_TRIM_BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_LONG_TERM_FUEL_TRIM_BANK_2_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_FUEL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_FUEL_PRESSURE_UUID:
                *units = kpa_psi_list;
                return sizeof(kpa_psi_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_MANIFOLD_ABS_PRESS_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_MANIFOLD_ABS_PRESS_UUID:
                *units = kpa_psi_list;
                return sizeof(kpa_psi_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ENGINE_SPEED_UUID:
                *units = rpm_list;
                return sizeof(rpm_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_ENGINE_SPEED_UUID:
                *units = rpm_list;
                return sizeof(rpm_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_VEHICLE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_VEHICLE_SPEED_UUID:
                *units = kmh_mph_list;
                return sizeof(kmh_mph_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_TIMING_ADVANCE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_TIMING_ADVANCE_UUID:
                *units = degrees_list;
                return sizeof(degrees_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_INTAKE_AIR_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_INTAKE_AIR_TEMP_UUID:
                *units = celsius_fahrenheit_list;
                return sizeof(celsius_fahrenheit_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_MASS_AIR_FLOW_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_MASS_AIR_FLOW_UUID:
                *units = gramsec_list;
                return sizeof(gramsec_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_THROTTLE_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_THROTTLE_POSITION_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_O2_SENSOR_2_VOLTS_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_O2_SENSOR_2_VOLTS_UUID:
                *units = volts_list;
                return sizeof(volts_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_FUEL_RAIL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_FUEL_RAIL_PRESSURE_UUID:
                *units = kpa_psi_list;
                return sizeof(kpa_psi_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_BAROMETRIC_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_BAROMETRIC_PRESSURE_UUID:
                *units = kpa_psi_list;
                return sizeof(kpa_psi_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_UUID:
                *units = ratio_list;
                return sizeof(ratio_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_ACCEL_PEDAL_POS_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_ACCEL_PEDAL_POS_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_OIL_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_OIL_TEMP_UUID:
                *units = celsius_fahrenheit_list;
                return sizeof(celsius_fahrenheit_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE1_BOOST_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE1_BOOST_UUID:
                *units = kpa_psi_list;
                return sizeof(kpa_psi_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_UUID:
                *units = volts_list;
                return sizeof(volts_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_LP_FUEL_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_LP_FUEL_DUTY_CYCLE_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_IGNITION_CORRECTION_CYLINDER_1_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_IGNITION_CORRECTION_CYLINDER_1_UUID:
                *units = degrees_list;
                return sizeof(degrees_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_INTAKE_AIR_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_INTAKE_AIR_TEMP_UUID:
                *units = celsius_fahrenheit_list;
                return sizeof(celsius_fahrenheit_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_CHARGE_AIR_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_CHARGE_AIR_TEMP_UUID:
                *units = celsius_fahrenheit_list;
                return sizeof(celsius_fahrenheit_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_MANIFOLD_CHARGE_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_MANIFOLD_CHARGE_TEMP_UUID:
                *units = celsius_fahrenheit_list;
                return sizeof(celsius_fahrenheit_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_OCTANE_ADJUST_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_OCTANE_ADJUST_RATIO_UUID:
                *units = ratio_list;
                return sizeof(ratio_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_AMBIENT_AIR_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_AMBIENT_AIR_TEMP_UUID:
                *units = celsius_fahrenheit_list;
                return sizeof(celsius_fahrenheit_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_ENGINE_LOAD_UUID:
                *units = percent_list;
                return sizeof(percent_list) / sizeof(PID_UNITS);
        #endif

        #if defined(MODE22_CATALYTIC_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
            case MODE22_CATALYTIC_TEMPERATURE_UUID:
                *units = celsius_fahrenheit_list;
                return sizeof(celsius_fahrenheit_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_GAUGE_ILLUM_LEVEL_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_GAUGE_ILLUM_LEVEL_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_VEHICLE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_VEHICLE_STATUS_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_BRAKE_PEDAL_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_BRAKE_PEDAL_STATUS_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_EMERGENCY_BRAKE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_EMERGENCY_BRAKE_STATUS_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_REVERSE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_REVERSE_STATUS_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_ON_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_ON_BUTTON_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_OFF_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_OFF_BUTTON_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_SUPPORTED) || !defined(LIMIT_PIDS)
            case CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_RES_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_RES_BUTTON_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_CRUISE_CONTROL_CAN_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_CRUISE_CONTROL_CAN_BUTTON_UUID:
                *units = none_list;
                return sizeof(none_list) / sizeof(PID_UNITS);
        #endif

        #if defined(CALC1_BOOST_VACUUM_SUPPORTED) || !defined(LIMIT_PIDS)
            case CALC1_BOOST_VACUUM_UUID:
                *units = kpa_psi_list;
                return sizeof(kpa_psi_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_LATERAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_LATERAL_ACCELERATION_UUID:
                *units = g_force_list;
                return sizeof(g_force_list) / sizeof(PID_UNITS);
        #endif

        #if defined(SNIFF_LONGITUDINAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
            case SNIFF_LONGITUDINAL_ACCELERATION_UUID:
                *units = g_force_list;
                return sizeof(g_force_list) / sizeof(PID_UNITS);
        #endif

            default:
                return 0;
    }
}