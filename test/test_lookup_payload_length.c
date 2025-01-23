
#ifdef TEST

#include "unity.h"

#include "lookup_payload_length.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_lookup_payload_length_mode1_invalid(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(MODE1, 0xFFFF));
}

void test_lookup_payload_length_mode22_invalid(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(MODE22, 0xFFFF));
}

void test_lookup_payload_length_sniff_invalid(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0xFFFF));
}

void test_lookup_payload_length_calc1_invalid(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(CALC1, 0xFFFF));
}

void test_lookup_payload_length_invalid_mode(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(0xFF, 0xFFFF));
}

void test_lookup_payload_length_mode1_commanded_air_to_fuel_ratio(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE1, 0x44));
}

void test_lookup_payload_length_mode1_calculated_engine_load(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x04));
}

void test_lookup_payload_length_mode1_engine_coolant_temperature(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x05));
}

void test_lookup_payload_length_mode1_short_term_fuel_trim__bank_1(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x06));
}

void test_lookup_payload_length_mode1_long_term_fuel_trim__bank_1(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x07));
}

void test_lookup_payload_length_mode1_short_term_fuel_trim__bank_2(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x08));
}

void test_lookup_payload_length_mode1_long_term_fuel_trim__bank_2(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x09));
}

void test_lookup_payload_length_mode1_fuel_pressure(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x0A));
}

void test_lookup_payload_length_mode1_intake_manifold_absolute_pressure(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x0B));
}

void test_lookup_payload_length_mode1_engine_speed(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE1, 0x0C));
}

void test_lookup_payload_length_mode1_vehicle_speed(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x0D));
}

void test_lookup_payload_length_mode1_timing_advance(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x0E));
}

void test_lookup_payload_length_mode1_intake_air_temperature(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x0F));
}

void test_lookup_payload_length_mode1_mass_air_flow_sensor_air_flow_rate(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x10));
}

void test_lookup_payload_length_mode1_throttle_position(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x11));
}

void test_lookup_payload_length_mode1_oxygen_sensor_2_voltage(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE1, 0x15));
}

void test_lookup_payload_length_mode1_fuel_rail_pressure_relative_to_manifold_vacuum(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE1, 0x22));
}

void test_lookup_payload_length_mode1_absolute_barometric_pressure(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x33));
}

void test_lookup_payload_length_mode1_air_to_fuel_ratio(void)
{
    TEST_ASSERT_EQUAL_INT(4, lookup_payload_length(MODE1, 0x34));
}

void test_lookup_payload_length_mode1_relative_accelerator_pedal_position(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x5A));
}

void test_lookup_payload_length_mode1_engine_oil_temperature(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x5C));
}

void test_lookup_payload_length_mode1_turbocharger_compressor_inlet_pressure(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE1, 0x6F));
}

void test_lookup_payload_length_mode22_lateral_g(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0x2B0C));
}

void test_lookup_payload_length_mode22_longitude_g(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0x2B11));
}

void test_lookup_payload_length_mode22_manifold_absolute_pressure_sensor_voltage_1(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0x0301));
}

void test_lookup_payload_length_mode22_low_pressure_fuel_pump_commanded_duty_cycle(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0x0307));
}

void test_lookup_payload_length_mode22_ignition_correction_cylinder_1(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0x03EC));
}

void test_lookup_payload_length_mode22_vct_intake_cam_solenoid_duty_cycle(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0x0316));
}

void test_lookup_payload_length_mode22_vct_exhaust_cam_solenoid_duty_cycle(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0x0317));
}

void test_lookup_payload_length_mode22_intake_air_temperature(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE22, 0xF40F));
}

void test_lookup_payload_length_mode22_charge_air_temperature(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0x0461));
}

void test_lookup_payload_length_mode22_manifold_charge_temperature(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE22, 0x03CA));
}

void test_lookup_payload_length_mode22_octane_adjust_ratio(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0x03E8));
}

void test_lookup_payload_length_mode22_ambient_air_temperature(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE22, 0x057D));
}

void test_lookup_payload_length_mode22_engine_load_percentage(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE22, 0xF404));
}

void test_lookup_payload_length_mode22_catalytic_temperature(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0xF43C));
}

void test_lookup_payload_length_sniff_gauge_brightness(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x01C8));
}

void test_lookup_payload_length_sniff_vehicle_status(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x1260));
}

void test_lookup_payload_length_sniff_brake_pedal_status(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x0802));
}

void test_lookup_payload_length_sniff_emergency_brake_status(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x0C82));
}

void test_lookup_payload_length_sniff_reverse_status(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x0803));
}

void test_lookup_payload_length_sniff_cruise_control_on_button(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x0301));
}

void test_lookup_payload_length_sniff_cruise_control_off_button(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x0302));
}

void test_lookup_payload_length_calc1_cruise_control_off_button_toggle(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(CALC1, 0x0302));
}

void test_lookup_payload_length_sniff_cruise_control_set_plus_button(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x0303));
}

void test_lookup_payload_length_sniff_cruise_control_set_minus_button(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x0304));
}

void test_lookup_payload_length_sniff_cruise_control_res_button(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x0305));
}

void test_lookup_payload_length_sniff_cruise_control_can_button(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x0306));
}

void test_lookup_payload_length_calc1_turbocharger_compressor_inlet_pressure(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(CALC1, 0x6F));
}

void test_lookup_payload_length_mode22_battery_charge(void)
{
    TEST_ASSERT_EQUAL_INT(1, lookup_payload_length(MODE22, 0x4028));
}

void test_lookup_payload_length_mode22_tire_pressure_lf(void)
{
    TEST_ASSERT_EQUAL_INT(2, lookup_payload_length(MODE22, 0x2813));
}

void test_lookup_payload_length_sniff_lateral_acceleration(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x1802));
}

void test_lookup_payload_length_sniff_longitudinal_acceleration(void)
{
    TEST_ASSERT_EQUAL_INT(0, lookup_payload_length(SNIFF, 0x1602));
}

#endif