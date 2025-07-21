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

/**
 * Accel Pedal Pos expressed in PERCENT
 */
#if defined(MODE1_ACCEL_PEDAL_POS_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ACCEL_PEDAL_POS_HEADER                                      (uint16_t)0x7E0
#define MODE1_ACCEL_PEDAL_POS_PID                                         (uint16_t)0x5A
#define MODE1_ACCEL_PEDAL_POS_MODE                                        (uint8_t)MODE1
#define MODE1_ACCEL_PEDAL_POS_UUID                                        (uint32_t)((MODE1_ACCEL_PEDAL_POS_MODE << 16) | MODE1_ACCEL_PEDAL_POS_PID)
#define MODE1_ACCEL_PEDAL_POS_LEN                                         (uint8_t)0x1
#define MODE1_ACCEL_PEDAL_POS_UNITS                                       (uint16_t)PID_UNITS_PERCENT
#define MODE1_ACCEL_PEDAL_POS_LABEL                                       "APP"
#define MODE1_ACCEL_PEDAL_POS_DESC                                        "Accel Pedal Pos"
#define MODE1_ACCEL_PEDAL_POS_PERCENT_LOWER                               (float)0
#define MODE1_ACCEL_PEDAL_POS_PERCENT_UPPER                               (float)100
#define MODE1_ACCEL_PEDAL_POS_PERCENT_PRECISION                           (uint8_t)0
#endif

/**
 * Air-Fuel Ratio (Oxygen Sensor 1) expressed in RATIO
 */
#if defined(MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_HEADER                     (uint16_t)0x7E0
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_PID                        (uint16_t)0x34
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_MODE                       (uint8_t)MODE1
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_UUID                       (uint32_t)((MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_MODE << 16) | MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_PID)
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_LEN                        (uint8_t)0x4
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_UNITS                      (uint16_t)PID_UNITS_RATIO
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_LABEL                      "AFR"
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_DESC                       "Air-Fuel Ratio (Oxygen Sensor 1)"
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_RATIO_LOWER                (float)0
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_RATIO_UPPER                (float)29.4
#define MODE1_AIR_FUEL_RATIO_OXYGEN_SENSOR_1_RATIO_PRECISION            (uint8_t)2
#endif

/**
 * Ambient Air Temp expressed in CELSIUS
 */
#if defined(MODE22_AMBIENT_AIR_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_AMBIENT_AIR_TEMP_HEADER                                     (uint16_t)0x7E0
#define MODE22_AMBIENT_AIR_TEMP_PID                                        (uint16_t)0x057D
#define MODE22_AMBIENT_AIR_TEMP_MODE                                       (uint8_t)MODE22
#define MODE22_AMBIENT_AIR_TEMP_UUID                                       (uint32_t)((MODE22_AMBIENT_AIR_TEMP_MODE << 16) | MODE22_AMBIENT_AIR_TEMP_PID)
#define MODE22_AMBIENT_AIR_TEMP_LEN                                        (uint8_t)0x1
#define MODE22_AMBIENT_AIR_TEMP_UNITS                                      (uint16_t)PID_UNITS_CELSIUS
#define MODE22_AMBIENT_AIR_TEMP_LABEL                                      "AAT"
#define MODE22_AMBIENT_AIR_TEMP_DESC                                       "Ambient Air Temp"
#define MODE22_AMBIENT_AIR_TEMP_CELSIUS_LOWER                              (float)-40
#define MODE22_AMBIENT_AIR_TEMP_CELSIUS_UPPER                              (float)200
#define MODE22_AMBIENT_AIR_TEMP_CELSIUS_PRECISION                          (uint8_t)0
#define MODE22_AMBIENT_AIR_TEMP_FAHRENHEIT_LOWER                           (float)-40
#define MODE22_AMBIENT_AIR_TEMP_FAHRENHEIT_UPPER                           (float)400
#define MODE22_AMBIENT_AIR_TEMP_FAHRENHEIT_PRECISION                       (uint8_t)1
#endif

/**
 * Barometric Pressure expressed in KPA
 */
#if defined(MODE1_BAROMETRIC_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_BAROMETRIC_PRESSURE_HEADER                                  (uint16_t)0x7E0
#define MODE1_BAROMETRIC_PRESSURE_PID                                     (uint16_t)0x33
#define MODE1_BAROMETRIC_PRESSURE_MODE                                    (uint8_t)MODE1
#define MODE1_BAROMETRIC_PRESSURE_UUID                                    (uint32_t)((MODE1_BAROMETRIC_PRESSURE_MODE << 16) | MODE1_BAROMETRIC_PRESSURE_PID)
#define MODE1_BAROMETRIC_PRESSURE_LEN                                     (uint8_t)0x1
#define MODE1_BAROMETRIC_PRESSURE_UNITS                                   (uint16_t)PID_UNITS_KPA
#define MODE1_BAROMETRIC_PRESSURE_LABEL                                   "Baro"
#define MODE1_BAROMETRIC_PRESSURE_DESC                                    "Barometric Pressure"
#define MODE1_BAROMETRIC_PRESSURE_KPA_LOWER                               (float)0
#define MODE1_BAROMETRIC_PRESSURE_KPA_UPPER                               (float)255
#define MODE1_BAROMETRIC_PRESSURE_KPA_PRECISION                           (uint8_t)0
#define MODE1_BAROMETRIC_PRESSURE_PSI_LOWER                               (float)0
#define MODE1_BAROMETRIC_PRESSURE_PSI_UPPER                               (float)36
#define MODE1_BAROMETRIC_PRESSURE_PSI_PRECISION                           (uint8_t)1
#endif

/**
 * Boost expressed in KPA
 */
#if defined(MODE1_BOOST_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_BOOST_HEADER                                                (uint16_t)0x7E0
#define MODE1_BOOST_PID                                                   (uint16_t)0x6F
#define MODE1_BOOST_MODE                                                  (uint8_t)MODE1
#define MODE1_BOOST_UUID                                                  (uint32_t)((MODE1_BOOST_MODE << 16) | MODE1_BOOST_PID)
#define MODE1_BOOST_LEN                                                   (uint8_t)0x1
#define MODE1_BOOST_UNITS                                                 (uint16_t)PID_UNITS_KPA
#define MODE1_BOOST_LABEL                                                 "Boost"
#define MODE1_BOOST_DESC                                                  "Boost"
#define MODE1_BOOST_KPA_LOWER                                             (float)0
#define MODE1_BOOST_KPA_UPPER                                             (float)255
#define MODE1_BOOST_KPA_PRECISION                                         (uint8_t)1
#define MODE1_BOOST_PSI_LOWER                                             (float)0
#define MODE1_BOOST_PSI_UPPER                                             (float)36
#define MODE1_BOOST_PSI_PRECISION                                         (uint8_t)2
#endif

/**
 * Boost/Vacuum expressed in KPA
 */
#if defined(CALC1_BOOST_VACUUM_SUPPORTED) || !defined(LIMIT_PIDS)
#define CALC1_BOOST_VACUUM_HEADER                                         (uint16_t)0x7E0
#define CALC1_BOOST_VACUUM_PID                                            (uint16_t)0x6F
#define CALC1_BOOST_VACUUM_MODE                                           (uint8_t)CALC1
#define CALC1_BOOST_VACUUM_UUID                                           (uint32_t)((CALC1_BOOST_VACUUM_MODE << 16) | CALC1_BOOST_VACUUM_PID)
#define CALC1_BOOST_VACUUM_LEN                                            (uint8_t)0x0
#define CALC1_BOOST_VACUUM_UNITS                                          (uint16_t)PID_UNITS_KPA
#define CALC1_BOOST_VACUUM_LABEL                                          "Boost"
#define CALC1_BOOST_VACUUM_DESC                                           "Boost/Vacuum"
#define CALC1_BOOST_VACUUM_KPA_LOWER                                      (float)-82
#define CALC1_BOOST_VACUUM_KPA_UPPER                                      (float)170
#define CALC1_BOOST_VACUUM_KPA_PRECISION                                  (uint8_t)1
#define CALC1_BOOST_VACUUM_PSI_LOWER                                      (float)-12
#define CALC1_BOOST_VACUUM_PSI_UPPER                                      (float)24
#define CALC1_BOOST_VACUUM_PSI_PRECISION                                  (uint8_t)2
#endif

/**
 * Brake Pedal Status expressed in NONE
 */
#if defined(SNIFF_BRAKE_PEDAL_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_BRAKE_PEDAL_STATUS_HEADER                                   (uint16_t)0x7E0
#define SNIFF_BRAKE_PEDAL_STATUS_PID                                      (uint16_t)0x0802
#define SNIFF_BRAKE_PEDAL_STATUS_MODE                                     (uint8_t)SNIFF
#define SNIFF_BRAKE_PEDAL_STATUS_UUID                                     (uint32_t)((SNIFF_BRAKE_PEDAL_STATUS_MODE << 16) | SNIFF_BRAKE_PEDAL_STATUS_PID)
#define SNIFF_BRAKE_PEDAL_STATUS_LEN                                      (uint8_t)0x0
#define SNIFF_BRAKE_PEDAL_STATUS_UNITS                                    (uint16_t)PID_UNITS_NONE
#define SNIFF_BRAKE_PEDAL_STATUS_LABEL                                    "Brake Pedal"
#define SNIFF_BRAKE_PEDAL_STATUS_DESC                                     "Brake Pedal Status"
#define SNIFF_BRAKE_PEDAL_STATUS_NONE_LOWER                               (float)0
#define SNIFF_BRAKE_PEDAL_STATUS_NONE_UPPER                               (float)1
#define SNIFF_BRAKE_PEDAL_STATUS_NONE_PRECISION                           (uint8_t)0
#endif

/**
 * Calc engine load expressed in PERCENT
 */
#if defined(MODE1_CALC_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_CALC_ENGINE_LOAD_HEADER                                     (uint16_t)0x7E0
#define MODE1_CALC_ENGINE_LOAD_PID                                        (uint16_t)0x04
#define MODE1_CALC_ENGINE_LOAD_MODE                                       (uint8_t)MODE1
#define MODE1_CALC_ENGINE_LOAD_UUID                                       (uint32_t)((MODE1_CALC_ENGINE_LOAD_MODE << 16) | MODE1_CALC_ENGINE_LOAD_PID)
#define MODE1_CALC_ENGINE_LOAD_LEN                                        (uint8_t)0x1
#define MODE1_CALC_ENGINE_LOAD_UNITS                                      (uint16_t)PID_UNITS_PERCENT
#define MODE1_CALC_ENGINE_LOAD_LABEL                                      "Load"
#define MODE1_CALC_ENGINE_LOAD_DESC                                       "Calc engine load"
#define MODE1_CALC_ENGINE_LOAD_PERCENT_LOWER                              (float)0
#define MODE1_CALC_ENGINE_LOAD_PERCENT_UPPER                              (float)100
#define MODE1_CALC_ENGINE_LOAD_PERCENT_PRECISION                          (uint8_t)1
#endif

/**
 * Catalytic Temperature expressed in CELSIUS
 */
#if defined(MODE22_CATALYTIC_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_CATALYTIC_TEMPERATURE_HEADER                                (uint16_t)0x7E0
#define MODE22_CATALYTIC_TEMPERATURE_PID                                   (uint16_t)0xF43C
#define MODE22_CATALYTIC_TEMPERATURE_MODE                                  (uint8_t)MODE22
#define MODE22_CATALYTIC_TEMPERATURE_UUID                                  (uint32_t)((MODE22_CATALYTIC_TEMPERATURE_MODE << 16) | MODE22_CATALYTIC_TEMPERATURE_PID)
#define MODE22_CATALYTIC_TEMPERATURE_LEN                                   (uint8_t)0x2
#define MODE22_CATALYTIC_TEMPERATURE_UNITS                                 (uint16_t)PID_UNITS_CELSIUS
#define MODE22_CATALYTIC_TEMPERATURE_LABEL                                 "Cat Temp"
#define MODE22_CATALYTIC_TEMPERATURE_DESC                                  "Catalytic Temperature"
#define MODE22_CATALYTIC_TEMPERATURE_CELSIUS_LOWER                         (float)0
#define MODE22_CATALYTIC_TEMPERATURE_CELSIUS_UPPER                         (float)1000
#define MODE22_CATALYTIC_TEMPERATURE_CELSIUS_PRECISION                     (uint8_t)0
#define MODE22_CATALYTIC_TEMPERATURE_FAHRENHEIT_LOWER                      (float)0
#define MODE22_CATALYTIC_TEMPERATURE_FAHRENHEIT_UPPER                      (float)2000
#define MODE22_CATALYTIC_TEMPERATURE_FAHRENHEIT_PRECISION                  (uint8_t)0
#endif

/**
 * Charge Air Temp expressed in CELSIUS
 */
#if defined(MODE22_CHARGE_AIR_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_CHARGE_AIR_TEMP_HEADER                                      (uint16_t)0x7E0
#define MODE22_CHARGE_AIR_TEMP_PID                                         (uint16_t)0x0461
#define MODE22_CHARGE_AIR_TEMP_MODE                                        (uint8_t)MODE22
#define MODE22_CHARGE_AIR_TEMP_UUID                                        (uint32_t)((MODE22_CHARGE_AIR_TEMP_MODE << 16) | MODE22_CHARGE_AIR_TEMP_PID)
#define MODE22_CHARGE_AIR_TEMP_LEN                                         (uint8_t)0x2
#define MODE22_CHARGE_AIR_TEMP_UNITS                                       (uint16_t)PID_UNITS_CELSIUS
#define MODE22_CHARGE_AIR_TEMP_LABEL                                       "CAT"
#define MODE22_CHARGE_AIR_TEMP_DESC                                        "Charge Air Temp"
#define MODE22_CHARGE_AIR_TEMP_CELSIUS_LOWER                               (float)-40
#define MODE22_CHARGE_AIR_TEMP_CELSIUS_UPPER                               (float)200
#define MODE22_CHARGE_AIR_TEMP_CELSIUS_PRECISION                           (uint8_t)1
#define MODE22_CHARGE_AIR_TEMP_FAHRENHEIT_LOWER                            (float)-40
#define MODE22_CHARGE_AIR_TEMP_FAHRENHEIT_UPPER                            (float)400
#define MODE22_CHARGE_AIR_TEMP_FAHRENHEIT_PRECISION                        (uint8_t)1
#endif

/**
 * Commanded Air-Fuel Ratio expressed in RATIO
 */
#if defined(MODE1_COMMANDED_AIR_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_COMMANDED_AIR_FUEL_RATIO_HEADER                             (uint16_t)0x7E0
#define MODE1_COMMANDED_AIR_FUEL_RATIO_PID                                (uint16_t)0x44
#define MODE1_COMMANDED_AIR_FUEL_RATIO_MODE                               (uint8_t)MODE1
#define MODE1_COMMANDED_AIR_FUEL_RATIO_UUID                               (uint32_t)((MODE1_COMMANDED_AIR_FUEL_RATIO_MODE << 16) | MODE1_COMMANDED_AIR_FUEL_RATIO_PID)
#define MODE1_COMMANDED_AIR_FUEL_RATIO_LEN                                (uint8_t)0x2
#define MODE1_COMMANDED_AIR_FUEL_RATIO_UNITS                              (uint16_t)PID_UNITS_RATIO
#define MODE1_COMMANDED_AIR_FUEL_RATIO_LABEL                              "Cmd AFR"
#define MODE1_COMMANDED_AIR_FUEL_RATIO_DESC                               "Commanded Air-Fuel Ratio"
#define MODE1_COMMANDED_AIR_FUEL_RATIO_RATIO_LOWER                        (float)0
#define MODE1_COMMANDED_AIR_FUEL_RATIO_RATIO_UPPER                        (float)29.4
#define MODE1_COMMANDED_AIR_FUEL_RATIO_RATIO_PRECISION                    (uint8_t)2
#endif

/**
 * Cruise Control CAN button expressed in NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_CAN_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_HEADER                            (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_PID                               (uint16_t)0x0306
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_MODE                              (uint8_t)SNIFF
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_UUID                              (uint32_t)((SNIFF_CRUISE_CONTROL_CAN_BUTTON_MODE << 16) | SNIFF_CRUISE_CONTROL_CAN_BUTTON_PID)
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_LEN                               (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_UNITS                             (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_LABEL                             "CAN Button"
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_DESC                              "Cruise Control CAN button"
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_NONE_LOWER                        (float)0
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_NONE_UPPER                        (float)1
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_NONE_PRECISION                    (uint8_t)0
#endif

/**
 * Cruise Control OFF button expressed in NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_OFF_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_HEADER                            (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_PID                               (uint16_t)0x0302
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_MODE                              (uint8_t)SNIFF
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_UUID                              (uint32_t)((SNIFF_CRUISE_CONTROL_OFF_BUTTON_MODE << 16) | SNIFF_CRUISE_CONTROL_OFF_BUTTON_PID)
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_LEN                               (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_UNITS                             (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_LABEL                             "OFF Button"
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_DESC                              "Cruise Control OFF button"
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_NONE_LOWER                        (float)0
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_NONE_UPPER                        (float)1
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_NONE_PRECISION                    (uint8_t)0
#endif

/**
 * Cruise Control OFF button toggle expressed in NONE
 */
#if defined(CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_SUPPORTED) || !defined(LIMIT_PIDS)
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_HEADER                     (uint16_t)0x7E0
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_PID                        (uint16_t)0x0302
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_MODE                       (uint8_t)CALC1
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UUID                       (uint32_t)((CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_MODE << 16) | CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_PID)
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_LEN                        (uint8_t)0x0
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UNITS                      (uint16_t)PID_UNITS_NONE
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_LABEL                      "OFF Button"
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_DESC                       "Cruise Control OFF button toggle"
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_NONE_LOWER                 (float)0
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_NONE_UPPER                 (float)1
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_NONE_PRECISION             (uint8_t)0
#endif

/**
 * Cruise Control ON button expressed in NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_ON_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_HEADER                             (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_PID                                (uint16_t)0x0301
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_MODE                               (uint8_t)SNIFF
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_UUID                               (uint32_t)((SNIFF_CRUISE_CONTROL_ON_BUTTON_MODE << 16) | SNIFF_CRUISE_CONTROL_ON_BUTTON_PID)
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_LEN                                (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_UNITS                              (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_LABEL                              "ON Button"
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_DESC                               "Cruise Control ON button"
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_NONE_LOWER                         (float)0
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_NONE_UPPER                         (float)1
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_NONE_PRECISION                     (uint8_t)0
#endif

/**
 * Cruise Control RES button expressed in NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_RES_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_HEADER                            (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_PID                               (uint16_t)0x0305
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_MODE                              (uint8_t)SNIFF
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_UUID                              (uint32_t)((SNIFF_CRUISE_CONTROL_RES_BUTTON_MODE << 16) | SNIFF_CRUISE_CONTROL_RES_BUTTON_PID)
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_LEN                               (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_UNITS                             (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_LABEL                             "RES Button"
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_DESC                              "Cruise Control RES button"
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_NONE_LOWER                        (float)0
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_NONE_UPPER                        (float)1
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_NONE_PRECISION                    (uint8_t)0
#endif

/**
 * Cruise Control SET Minus button expressed in NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_HEADER                      (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_PID                         (uint16_t)0x0304
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_MODE                        (uint8_t)SNIFF
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UUID                        (uint32_t)((SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_MODE << 16) | SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_PID)
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_LEN                         (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UNITS                       (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_LABEL                       "SET- Button"
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_DESC                        "Cruise Control SET Minus button"
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_NONE_LOWER                  (float)0
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_NONE_UPPER                  (float)1
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_NONE_PRECISION              (uint8_t)0
#endif

/**
 * Cruise Control SET Plus Button expressed in NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_HEADER                       (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_PID                          (uint16_t)0x0303
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_MODE                         (uint8_t)SNIFF
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UUID                         (uint32_t)((SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_MODE << 16) | SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_PID)
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_LEN                          (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UNITS                        (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_LABEL                        "SET+ Button"
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_DESC                         "Cruise Control SET Plus Button"
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_NONE_LOWER                   (float)0
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_NONE_UPPER                   (float)1
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_NONE_PRECISION               (uint8_t)0
#endif

/**
 * Emergency Brake Status expressed in NONE
 */
#if defined(SNIFF_EMERGENCY_BRAKE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_EMERGENCY_BRAKE_STATUS_HEADER                               (uint16_t)0x7E0
#define SNIFF_EMERGENCY_BRAKE_STATUS_PID                                  (uint16_t)0x0C82
#define SNIFF_EMERGENCY_BRAKE_STATUS_MODE                                 (uint8_t)SNIFF
#define SNIFF_EMERGENCY_BRAKE_STATUS_UUID                                 (uint32_t)((SNIFF_EMERGENCY_BRAKE_STATUS_MODE << 16) | SNIFF_EMERGENCY_BRAKE_STATUS_PID)
#define SNIFF_EMERGENCY_BRAKE_STATUS_LEN                                  (uint8_t)0x0
#define SNIFF_EMERGENCY_BRAKE_STATUS_UNITS                                (uint16_t)PID_UNITS_NONE
#define SNIFF_EMERGENCY_BRAKE_STATUS_LABEL                                "E-Brake"
#define SNIFF_EMERGENCY_BRAKE_STATUS_DESC                                 "Emergency Brake Status"
#define SNIFF_EMERGENCY_BRAKE_STATUS_NONE_LOWER                           (float)0
#define SNIFF_EMERGENCY_BRAKE_STATUS_NONE_UPPER                           (float)1
#define SNIFF_EMERGENCY_BRAKE_STATUS_NONE_PRECISION                       (uint8_t)0
#endif

/**
 * Engine Load expressed in PERCENT
 */
#if defined(MODE22_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_ENGINE_LOAD_HEADER                                          (uint16_t)0x7E0
#define MODE22_ENGINE_LOAD_PID                                             (uint16_t)0xF404
#define MODE22_ENGINE_LOAD_MODE                                            (uint8_t)MODE22
#define MODE22_ENGINE_LOAD_UUID                                            (uint32_t)((MODE22_ENGINE_LOAD_MODE << 16) | MODE22_ENGINE_LOAD_PID)
#define MODE22_ENGINE_LOAD_LEN                                             (uint8_t)0x1
#define MODE22_ENGINE_LOAD_UNITS                                           (uint16_t)PID_UNITS_PERCENT
#define MODE22_ENGINE_LOAD_LABEL                                           "Load"
#define MODE22_ENGINE_LOAD_DESC                                            "Engine Load"
#define MODE22_ENGINE_LOAD_PERCENT_LOWER                                   (float)0
#define MODE22_ENGINE_LOAD_PERCENT_UPPER                                   (float)100
#define MODE22_ENGINE_LOAD_PERCENT_PRECISION                               (uint8_t)1
#endif

/**
 * Engine coolant temp expressed in CELSIUS
 */
#if defined(MODE1_ENGINE_COOLANT_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ENGINE_COOLANT_TEMP_HEADER                                  (uint16_t)0x7E0
#define MODE1_ENGINE_COOLANT_TEMP_PID                                     (uint16_t)0x05
#define MODE1_ENGINE_COOLANT_TEMP_MODE                                    (uint8_t)MODE1
#define MODE1_ENGINE_COOLANT_TEMP_UUID                                    (uint32_t)((MODE1_ENGINE_COOLANT_TEMP_MODE << 16) | MODE1_ENGINE_COOLANT_TEMP_PID)
#define MODE1_ENGINE_COOLANT_TEMP_LEN                                     (uint8_t)0x1
#define MODE1_ENGINE_COOLANT_TEMP_UNITS                                   (uint16_t)PID_UNITS_CELSIUS
#define MODE1_ENGINE_COOLANT_TEMP_LABEL                                   "ECT"
#define MODE1_ENGINE_COOLANT_TEMP_DESC                                    "Engine coolant temp"
#define MODE1_ENGINE_COOLANT_TEMP_CELSIUS_LOWER                           (float)-40
#define MODE1_ENGINE_COOLANT_TEMP_CELSIUS_UPPER                           (float)215
#define MODE1_ENGINE_COOLANT_TEMP_CELSIUS_PRECISION                       (uint8_t)0
#define MODE1_ENGINE_COOLANT_TEMP_FAHRENHEIT_LOWER                        (float)-40
#define MODE1_ENGINE_COOLANT_TEMP_FAHRENHEIT_UPPER                        (float)400
#define MODE1_ENGINE_COOLANT_TEMP_FAHRENHEIT_PRECISION                    (uint8_t)1
#endif

/**
 * Engine speed expressed in RPM
 */
#if defined(MODE1_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ENGINE_SPEED_HEADER                                         (uint16_t)0x7E0
#define MODE1_ENGINE_SPEED_PID                                            (uint16_t)0x0C
#define MODE1_ENGINE_SPEED_MODE                                           (uint8_t)MODE1
#define MODE1_ENGINE_SPEED_UUID                                           (uint32_t)((MODE1_ENGINE_SPEED_MODE << 16) | MODE1_ENGINE_SPEED_PID)
#define MODE1_ENGINE_SPEED_LEN                                            (uint8_t)0x2
#define MODE1_ENGINE_SPEED_UNITS                                          (uint16_t)PID_UNITS_RPM
#define MODE1_ENGINE_SPEED_LABEL                                          "RPM"
#define MODE1_ENGINE_SPEED_DESC                                           "Engine speed"
#define MODE1_ENGINE_SPEED_RPM_LOWER                                      (float)0
#define MODE1_ENGINE_SPEED_RPM_UPPER                                      (float)8000
#define MODE1_ENGINE_SPEED_RPM_PRECISION                                  (uint8_t)0
#endif

/**
 * Engine speed expressed in RPM
 */
#if defined(SNIFF_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_ENGINE_SPEED_HEADER                                         (uint16_t)0x7E0
#define SNIFF_ENGINE_SPEED_PID                                            (uint16_t)0x0C
#define SNIFF_ENGINE_SPEED_MODE                                           (uint8_t)SNIFF
#define SNIFF_ENGINE_SPEED_UUID                                           (uint32_t)((SNIFF_ENGINE_SPEED_MODE << 16) | SNIFF_ENGINE_SPEED_PID)
#define SNIFF_ENGINE_SPEED_LEN                                            (uint8_t)0x2
#define SNIFF_ENGINE_SPEED_UNITS                                          (uint16_t)PID_UNITS_RPM
#define SNIFF_ENGINE_SPEED_LABEL                                          "RPM"
#define SNIFF_ENGINE_SPEED_DESC                                           "Engine speed"
#define SNIFF_ENGINE_SPEED_RPM_LOWER                                      (float)0
#define SNIFF_ENGINE_SPEED_RPM_UPPER                                      (float)8000
#define SNIFF_ENGINE_SPEED_RPM_PRECISION                                  (uint8_t)0
#endif

/**
 * Fuel Pressure expressed in KPA
 */
#if defined(MODE1_FUEL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_FUEL_PRESSURE_HEADER                                        (uint16_t)0x7E0
#define MODE1_FUEL_PRESSURE_PID                                           (uint16_t)0x0A
#define MODE1_FUEL_PRESSURE_MODE                                          (uint8_t)MODE1
#define MODE1_FUEL_PRESSURE_UUID                                          (uint32_t)((MODE1_FUEL_PRESSURE_MODE << 16) | MODE1_FUEL_PRESSURE_PID)
#define MODE1_FUEL_PRESSURE_LEN                                           (uint8_t)0x1
#define MODE1_FUEL_PRESSURE_UNITS                                         (uint16_t)PID_UNITS_KPA
#define MODE1_FUEL_PRESSURE_LABEL                                         "Fuel"
#define MODE1_FUEL_PRESSURE_DESC                                          "Fuel Pressure"
#define MODE1_FUEL_PRESSURE_KPA_LOWER                                     (float)0
#define MODE1_FUEL_PRESSURE_KPA_UPPER                                     (float)765
#define MODE1_FUEL_PRESSURE_KPA_PRECISION                                 (uint8_t)0
#define MODE1_FUEL_PRESSURE_PSI_LOWER                                     (float)0
#define MODE1_FUEL_PRESSURE_PSI_UPPER                                     (float)110
#define MODE1_FUEL_PRESSURE_PSI_PRECISION                                 (uint8_t)1
#endif

/**
 * Fuel Rail Pressure expressed in KPA
 */
#if defined(MODE1_FUEL_RAIL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_FUEL_RAIL_PRESSURE_HEADER                                   (uint16_t)0x7E0
#define MODE1_FUEL_RAIL_PRESSURE_PID                                      (uint16_t)0x22
#define MODE1_FUEL_RAIL_PRESSURE_MODE                                     (uint8_t)MODE1
#define MODE1_FUEL_RAIL_PRESSURE_UUID                                     (uint32_t)((MODE1_FUEL_RAIL_PRESSURE_MODE << 16) | MODE1_FUEL_RAIL_PRESSURE_PID)
#define MODE1_FUEL_RAIL_PRESSURE_LEN                                      (uint8_t)0x2
#define MODE1_FUEL_RAIL_PRESSURE_UNITS                                    (uint16_t)PID_UNITS_KPA
#define MODE1_FUEL_RAIL_PRESSURE_LABEL                                    "Fuel"
#define MODE1_FUEL_RAIL_PRESSURE_DESC                                     "Fuel Rail Pressure"
#define MODE1_FUEL_RAIL_PRESSURE_KPA_LOWER                                (float)0
#define MODE1_FUEL_RAIL_PRESSURE_KPA_UPPER                                (float)5177
#define MODE1_FUEL_RAIL_PRESSURE_KPA_PRECISION                            (uint8_t)0
#define MODE1_FUEL_RAIL_PRESSURE_PSI_LOWER                                (float)0
#define MODE1_FUEL_RAIL_PRESSURE_PSI_UPPER                                (float)750
#define MODE1_FUEL_RAIL_PRESSURE_PSI_PRECISION                            (uint8_t)0
#endif

/**
 * Gauge Illum Level expressed in NONE
 */
#if defined(SNIFF_GAUGE_ILLUM_LEVEL_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_GAUGE_ILLUM_LEVEL_HEADER                                    (uint16_t)0x7E0
#define SNIFF_GAUGE_ILLUM_LEVEL_PID                                       (uint16_t)0x01C8
#define SNIFF_GAUGE_ILLUM_LEVEL_MODE                                      (uint8_t)SNIFF
#define SNIFF_GAUGE_ILLUM_LEVEL_UUID                                      (uint32_t)((SNIFF_GAUGE_ILLUM_LEVEL_MODE << 16) | SNIFF_GAUGE_ILLUM_LEVEL_PID)
#define SNIFF_GAUGE_ILLUM_LEVEL_LEN                                       (uint8_t)0x0
#define SNIFF_GAUGE_ILLUM_LEVEL_UNITS                                     (uint16_t)PID_UNITS_NONE
#define SNIFF_GAUGE_ILLUM_LEVEL_LABEL                                     "Brightness"
#define SNIFF_GAUGE_ILLUM_LEVEL_DESC                                      "Gauge Illum Level"
#define SNIFF_GAUGE_ILLUM_LEVEL_NONE_LOWER                                (float)0
#define SNIFF_GAUGE_ILLUM_LEVEL_NONE_UPPER                                (float)31
#define SNIFF_GAUGE_ILLUM_LEVEL_NONE_PRECISION                            (uint8_t)0
#endif

/**
 * Ignition Correction Cylinder 1 expressed in DEGREES
 */
#if defined(MODE22_IGNITION_CORRECTION_CYLINDER_1_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_HEADER                       (uint16_t)0x7E0
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_PID                          (uint16_t)0x03EC
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_MODE                         (uint8_t)MODE22
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_UUID                         (uint32_t)((MODE22_IGNITION_CORRECTION_CYLINDER_1_MODE << 16) | MODE22_IGNITION_CORRECTION_CYLINDER_1_PID)
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_LEN                          (uint8_t)0x2
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_UNITS                        (uint16_t)PID_UNITS_DEGREES
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_LABEL                        "IGN 1"
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_DESC                         "Ignition Correction Cylinder 1"
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_DEGREES_LOWER                (float)-16
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_DEGREES_UPPER                (float)16
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_DEGREES_PRECISION            (uint8_t)2
#endif

/**
 * Intake Air Temp expressed in CELSIUS
 */
#if defined(MODE1_INTAKE_AIR_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_INTAKE_AIR_TEMP_HEADER                                      (uint16_t)0x7E0
#define MODE1_INTAKE_AIR_TEMP_PID                                         (uint16_t)0x0F
#define MODE1_INTAKE_AIR_TEMP_MODE                                        (uint8_t)MODE1
#define MODE1_INTAKE_AIR_TEMP_UUID                                        (uint32_t)((MODE1_INTAKE_AIR_TEMP_MODE << 16) | MODE1_INTAKE_AIR_TEMP_PID)
#define MODE1_INTAKE_AIR_TEMP_LEN                                         (uint8_t)0x1
#define MODE1_INTAKE_AIR_TEMP_UNITS                                       (uint16_t)PID_UNITS_CELSIUS
#define MODE1_INTAKE_AIR_TEMP_LABEL                                       "IAT"
#define MODE1_INTAKE_AIR_TEMP_DESC                                        "Intake Air Temp"
#define MODE1_INTAKE_AIR_TEMP_CELSIUS_LOWER                               (float)-40
#define MODE1_INTAKE_AIR_TEMP_CELSIUS_UPPER                               (float)200
#define MODE1_INTAKE_AIR_TEMP_CELSIUS_PRECISION                           (uint8_t)0
#define MODE1_INTAKE_AIR_TEMP_FAHRENHEIT_LOWER                            (float)-40
#define MODE1_INTAKE_AIR_TEMP_FAHRENHEIT_UPPER                            (float)400
#define MODE1_INTAKE_AIR_TEMP_FAHRENHEIT_PRECISION                        (uint8_t)1
#endif

/**
 * Intake Air Temp expressed in CELSIUS
 */
#if defined(MODE22_INTAKE_AIR_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_INTAKE_AIR_TEMP_HEADER                                      (uint16_t)0x7E0
#define MODE22_INTAKE_AIR_TEMP_PID                                         (uint16_t)0xF40F
#define MODE22_INTAKE_AIR_TEMP_MODE                                        (uint8_t)MODE22
#define MODE22_INTAKE_AIR_TEMP_UUID                                        (uint32_t)((MODE22_INTAKE_AIR_TEMP_MODE << 16) | MODE22_INTAKE_AIR_TEMP_PID)
#define MODE22_INTAKE_AIR_TEMP_LEN                                         (uint8_t)0x1
#define MODE22_INTAKE_AIR_TEMP_UNITS                                       (uint16_t)PID_UNITS_CELSIUS
#define MODE22_INTAKE_AIR_TEMP_LABEL                                       "IAT"
#define MODE22_INTAKE_AIR_TEMP_DESC                                        "Intake Air Temp"
#define MODE22_INTAKE_AIR_TEMP_CELSIUS_LOWER                               (float)-40
#define MODE22_INTAKE_AIR_TEMP_CELSIUS_UPPER                               (float)200
#define MODE22_INTAKE_AIR_TEMP_CELSIUS_PRECISION                           (uint8_t)0
#define MODE22_INTAKE_AIR_TEMP_FAHRENHEIT_LOWER                            (float)-40
#define MODE22_INTAKE_AIR_TEMP_FAHRENHEIT_UPPER                            (float)400
#define MODE22_INTAKE_AIR_TEMP_FAHRENHEIT_PRECISION                        (uint8_t)1
#endif

/**
 * LP Fuel Duty Cycle expressed in PERCENT
 */
#if defined(MODE22_LP_FUEL_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_LP_FUEL_DUTY_CYCLE_HEADER                                   (uint16_t)0x7E0
#define MODE22_LP_FUEL_DUTY_CYCLE_PID                                      (uint16_t)0x0307
#define MODE22_LP_FUEL_DUTY_CYCLE_MODE                                     (uint8_t)MODE22
#define MODE22_LP_FUEL_DUTY_CYCLE_UUID                                     (uint32_t)((MODE22_LP_FUEL_DUTY_CYCLE_MODE << 16) | MODE22_LP_FUEL_DUTY_CYCLE_PID)
#define MODE22_LP_FUEL_DUTY_CYCLE_LEN                                      (uint8_t)0x2
#define MODE22_LP_FUEL_DUTY_CYCLE_UNITS                                    (uint16_t)PID_UNITS_PERCENT
#define MODE22_LP_FUEL_DUTY_CYCLE_LABEL                                    "LPFP DC"
#define MODE22_LP_FUEL_DUTY_CYCLE_DESC                                     "LP Fuel Duty Cycle"
#define MODE22_LP_FUEL_DUTY_CYCLE_PERCENT_LOWER                            (float)0
#define MODE22_LP_FUEL_DUTY_CYCLE_PERCENT_UPPER                            (float)100
#define MODE22_LP_FUEL_DUTY_CYCLE_PERCENT_PRECISION                        (uint8_t)0
#endif

/**
 * Lateral Acceleration expressed in G_FORCE
 */
#if defined(SNIFF_LATERAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_LATERAL_ACCELERATION_HEADER                                 (uint16_t)0x180
#define SNIFF_LATERAL_ACCELERATION_PID                                    (uint16_t)0x1802
#define SNIFF_LATERAL_ACCELERATION_MODE                                   (uint8_t)SNIFF
#define SNIFF_LATERAL_ACCELERATION_UUID                                   (uint32_t)((SNIFF_LATERAL_ACCELERATION_MODE << 16) | SNIFF_LATERAL_ACCELERATION_PID)
#define SNIFF_LATERAL_ACCELERATION_LEN                                    (uint8_t)0x0
#define SNIFF_LATERAL_ACCELERATION_UNITS                                  (uint16_t)PID_UNITS_G_FORCE
#define SNIFF_LATERAL_ACCELERATION_LABEL                                  "Lat Accel"
#define SNIFF_LATERAL_ACCELERATION_DESC                                   "Lateral Acceleration"
#define SNIFF_LATERAL_ACCELERATION_G_FORCE_LOWER                          (float)0
#define SNIFF_LATERAL_ACCELERATION_G_FORCE_UPPER                          (float)2
#define SNIFF_LATERAL_ACCELERATION_G_FORCE_PRECISION                      (uint8_t)2
#endif

/**
 * Long term fuel trim Bank 1 expressed in PERCENT
 */
#if defined(MODE1_LONG_TERM_FUEL_TRIM_BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_HEADER                           (uint16_t)0x7E0
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_PID                              (uint16_t)0x07
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_MODE                             (uint8_t)MODE1
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_UUID                             (uint32_t)((MODE1_LONG_TERM_FUEL_TRIM_BANK_1_MODE << 16) | MODE1_LONG_TERM_FUEL_TRIM_BANK_1_PID)
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_LEN                              (uint8_t)0x1
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_UNITS                            (uint16_t)PID_UNITS_PERCENT
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_LABEL                            "LTFT1"
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_DESC                             "Long term fuel trim Bank 1"
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_PERCENT_LOWER                    (float)-100
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_PERCENT_UPPER                    (float)99.2
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_1_PERCENT_PRECISION                (uint8_t)1
#endif

/**
 * Long term fuel trim Bank 2 expressed in PERCENT
 */
#if defined(MODE1_LONG_TERM_FUEL_TRIM_BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_HEADER                           (uint16_t)0x7E0
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_PID                              (uint16_t)0x09
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_MODE                             (uint8_t)MODE1
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_UUID                             (uint32_t)((MODE1_LONG_TERM_FUEL_TRIM_BANK_2_MODE << 16) | MODE1_LONG_TERM_FUEL_TRIM_BANK_2_PID)
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_LEN                              (uint8_t)0x1
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_UNITS                            (uint16_t)PID_UNITS_PERCENT
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_LABEL                            "LTFT2"
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_DESC                             "Long term fuel trim Bank 2"
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_PERCENT_LOWER                    (float)-100
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_PERCENT_UPPER                    (float)99.2
#define MODE1_LONG_TERM_FUEL_TRIM_BANK_2_PERCENT_PRECISION                (uint8_t)0
#endif

/**
 * Longitudinal Acceleration expressed in G_FORCE
 */
#if defined(SNIFF_LONGITUDINAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_LONGITUDINAL_ACCELERATION_HEADER                            (uint16_t)0x160
#define SNIFF_LONGITUDINAL_ACCELERATION_PID                               (uint16_t)0x1602
#define SNIFF_LONGITUDINAL_ACCELERATION_MODE                              (uint8_t)SNIFF
#define SNIFF_LONGITUDINAL_ACCELERATION_UUID                              (uint32_t)((SNIFF_LONGITUDINAL_ACCELERATION_MODE << 16) | SNIFF_LONGITUDINAL_ACCELERATION_PID)
#define SNIFF_LONGITUDINAL_ACCELERATION_LEN                               (uint8_t)0x0
#define SNIFF_LONGITUDINAL_ACCELERATION_UNITS                             (uint16_t)PID_UNITS_G_FORCE
#define SNIFF_LONGITUDINAL_ACCELERATION_LABEL                             "Long Accel"
#define SNIFF_LONGITUDINAL_ACCELERATION_DESC                              "Longitudinal Acceleration"
#define SNIFF_LONGITUDINAL_ACCELERATION_G_FORCE_LOWER                     (float)0
#define SNIFF_LONGITUDINAL_ACCELERATION_G_FORCE_UPPER                     (float)2
#define SNIFF_LONGITUDINAL_ACCELERATION_G_FORCE_PRECISION                 (uint8_t)2
#endif

/**
 * Manifold Abs Press expressed in KPA
 */
#if defined(MODE1_MANIFOLD_ABS_PRESS_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_MANIFOLD_ABS_PRESS_HEADER                                   (uint16_t)0x7E0
#define MODE1_MANIFOLD_ABS_PRESS_PID                                      (uint16_t)0x0B
#define MODE1_MANIFOLD_ABS_PRESS_MODE                                     (uint8_t)MODE1
#define MODE1_MANIFOLD_ABS_PRESS_UUID                                     (uint32_t)((MODE1_MANIFOLD_ABS_PRESS_MODE << 16) | MODE1_MANIFOLD_ABS_PRESS_PID)
#define MODE1_MANIFOLD_ABS_PRESS_LEN                                      (uint8_t)0x1
#define MODE1_MANIFOLD_ABS_PRESS_UNITS                                    (uint16_t)PID_UNITS_KPA
#define MODE1_MANIFOLD_ABS_PRESS_LABEL                                    "MAP"
#define MODE1_MANIFOLD_ABS_PRESS_DESC                                     "Manifold Abs Press"
#define MODE1_MANIFOLD_ABS_PRESS_KPA_LOWER                                (float)0
#define MODE1_MANIFOLD_ABS_PRESS_KPA_UPPER                                (float)255
#define MODE1_MANIFOLD_ABS_PRESS_KPA_PRECISION                            (uint8_t)0
#define MODE1_MANIFOLD_ABS_PRESS_PSI_LOWER                                (float)0
#define MODE1_MANIFOLD_ABS_PRESS_PSI_UPPER                                (float)36
#define MODE1_MANIFOLD_ABS_PRESS_PSI_PRECISION                            (uint8_t)1
#endif

/**
 * Manifold Abs Press Sensor 1 Volt expressed in VOLTS
 */
#if defined(MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_HEADER                     (uint16_t)0x7E0
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_PID                        (uint16_t)0x0301
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_MODE                       (uint8_t)MODE22
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_UUID                       (uint32_t)((MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_MODE << 16) | MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_PID)
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_LEN                        (uint8_t)0x2
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_UNITS                      (uint16_t)PID_UNITS_VOLTS
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_LABEL                      "MAP"
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_DESC                       "Manifold Abs Press Sensor 1 Volt"
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_VOLTS_LOWER                (float)0
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_VOLTS_UPPER                (float)5
#define MODE22_MANIFOLD_ABS_PRESS_SENSOR_1_VOLT_VOLTS_PRECISION            (uint8_t)2
#endif

/**
 * Manifold Charge Temp expressed in CELSIUS
 */
#if defined(MODE22_MANIFOLD_CHARGE_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_MANIFOLD_CHARGE_TEMP_HEADER                                 (uint16_t)0x7E0
#define MODE22_MANIFOLD_CHARGE_TEMP_PID                                    (uint16_t)0x03CA
#define MODE22_MANIFOLD_CHARGE_TEMP_MODE                                   (uint8_t)MODE22
#define MODE22_MANIFOLD_CHARGE_TEMP_UUID                                   (uint32_t)((MODE22_MANIFOLD_CHARGE_TEMP_MODE << 16) | MODE22_MANIFOLD_CHARGE_TEMP_PID)
#define MODE22_MANIFOLD_CHARGE_TEMP_LEN                                    (uint8_t)0x1
#define MODE22_MANIFOLD_CHARGE_TEMP_UNITS                                  (uint16_t)PID_UNITS_CELSIUS
#define MODE22_MANIFOLD_CHARGE_TEMP_LABEL                                  "MCT"
#define MODE22_MANIFOLD_CHARGE_TEMP_DESC                                   "Manifold Charge Temp"
#define MODE22_MANIFOLD_CHARGE_TEMP_CELSIUS_LOWER                          (float)-40
#define MODE22_MANIFOLD_CHARGE_TEMP_CELSIUS_UPPER                          (float)200
#define MODE22_MANIFOLD_CHARGE_TEMP_CELSIUS_PRECISION                      (uint8_t)0
#define MODE22_MANIFOLD_CHARGE_TEMP_FAHRENHEIT_LOWER                       (float)-40
#define MODE22_MANIFOLD_CHARGE_TEMP_FAHRENHEIT_UPPER                       (float)400
#define MODE22_MANIFOLD_CHARGE_TEMP_FAHRENHEIT_PRECISION                   (uint8_t)1
#endif

/**
 * Mass Air Flow expressed in GRAMSEC
 */
#if defined(MODE1_MASS_AIR_FLOW_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_MASS_AIR_FLOW_HEADER                                        (uint16_t)0x7E0
#define MODE1_MASS_AIR_FLOW_PID                                           (uint16_t)0x10
#define MODE1_MASS_AIR_FLOW_MODE                                          (uint8_t)MODE1
#define MODE1_MASS_AIR_FLOW_UUID                                          (uint32_t)((MODE1_MASS_AIR_FLOW_MODE << 16) | MODE1_MASS_AIR_FLOW_PID)
#define MODE1_MASS_AIR_FLOW_LEN                                           (uint8_t)0x1
#define MODE1_MASS_AIR_FLOW_UNITS                                         (uint16_t)PID_UNITS_GRAMSEC
#define MODE1_MASS_AIR_FLOW_LABEL                                         "MAF"
#define MODE1_MASS_AIR_FLOW_DESC                                          "Mass Air Flow"
#define MODE1_MASS_AIR_FLOW_GRAMSEC_LOWER                                 (float)0
#define MODE1_MASS_AIR_FLOW_GRAMSEC_UPPER                                 (float)655.35
#define MODE1_MASS_AIR_FLOW_GRAMSEC_PRECISION                             (uint8_t)0
#endif

/**
 * O2 Sensor 2 Volts expressed in VOLTS
 */
#if defined(MODE1_O2_SENSOR_2_VOLTS_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_O2_SENSOR_2_VOLTS_HEADER                                    (uint16_t)0x7E0
#define MODE1_O2_SENSOR_2_VOLTS_PID                                       (uint16_t)0x15
#define MODE1_O2_SENSOR_2_VOLTS_MODE                                      (uint8_t)MODE1
#define MODE1_O2_SENSOR_2_VOLTS_UUID                                      (uint32_t)((MODE1_O2_SENSOR_2_VOLTS_MODE << 16) | MODE1_O2_SENSOR_2_VOLTS_PID)
#define MODE1_O2_SENSOR_2_VOLTS_LEN                                       (uint8_t)0x2
#define MODE1_O2_SENSOR_2_VOLTS_UNITS                                     (uint16_t)PID_UNITS_VOLTS
#define MODE1_O2_SENSOR_2_VOLTS_LABEL                                     "O2"
#define MODE1_O2_SENSOR_2_VOLTS_DESC                                      "O2 Sensor 2 Volts"
#define MODE1_O2_SENSOR_2_VOLTS_VOLTS_LOWER                               (float)0
#define MODE1_O2_SENSOR_2_VOLTS_VOLTS_UPPER                               (float)1.275
#define MODE1_O2_SENSOR_2_VOLTS_VOLTS_PRECISION                           (uint8_t)2
#endif

/**
 * Octane Adjust Ratio expressed in RATIO
 */
#if defined(MODE22_OCTANE_ADJUST_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_OCTANE_ADJUST_RATIO_HEADER                                  (uint16_t)0x7E0
#define MODE22_OCTANE_ADJUST_RATIO_PID                                     (uint16_t)0x03E8
#define MODE22_OCTANE_ADJUST_RATIO_MODE                                    (uint8_t)MODE22
#define MODE22_OCTANE_ADJUST_RATIO_UUID                                    (uint32_t)((MODE22_OCTANE_ADJUST_RATIO_MODE << 16) | MODE22_OCTANE_ADJUST_RATIO_PID)
#define MODE22_OCTANE_ADJUST_RATIO_LEN                                     (uint8_t)0x2
#define MODE22_OCTANE_ADJUST_RATIO_UNITS                                   (uint16_t)PID_UNITS_RATIO
#define MODE22_OCTANE_ADJUST_RATIO_LABEL                                   "OAR"
#define MODE22_OCTANE_ADJUST_RATIO_DESC                                    "Octane Adjust Ratio"
#define MODE22_OCTANE_ADJUST_RATIO_RATIO_LOWER                             (float)-1
#define MODE22_OCTANE_ADJUST_RATIO_RATIO_UPPER                             (float)1
#define MODE22_OCTANE_ADJUST_RATIO_RATIO_PRECISION                         (uint8_t)2
#endif

/**
 * Oil Temp expressed in CELSIUS
 */
#if defined(MODE1_OIL_TEMP_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_OIL_TEMP_HEADER                                             (uint16_t)0x7E0
#define MODE1_OIL_TEMP_PID                                                (uint16_t)0x5C
#define MODE1_OIL_TEMP_MODE                                               (uint8_t)MODE1
#define MODE1_OIL_TEMP_UUID                                               (uint32_t)((MODE1_OIL_TEMP_MODE << 16) | MODE1_OIL_TEMP_PID)
#define MODE1_OIL_TEMP_LEN                                                (uint8_t)0x1
#define MODE1_OIL_TEMP_UNITS                                              (uint16_t)PID_UNITS_CELSIUS
#define MODE1_OIL_TEMP_LABEL                                              "Oil Temp"
#define MODE1_OIL_TEMP_DESC                                               "Oil Temp"
#define MODE1_OIL_TEMP_CELSIUS_LOWER                                      (float)-40
#define MODE1_OIL_TEMP_CELSIUS_UPPER                                      (float)200
#define MODE1_OIL_TEMP_CELSIUS_PRECISION                                  (uint8_t)0
#define MODE1_OIL_TEMP_FAHRENHEIT_LOWER                                   (float)-40
#define MODE1_OIL_TEMP_FAHRENHEIT_UPPER                                   (float)400
#define MODE1_OIL_TEMP_FAHRENHEIT_PRECISION                               (uint8_t)1
#endif

/**
 * Reverse Status expressed in NONE
 */
#if defined(SNIFF_REVERSE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_REVERSE_STATUS_HEADER                                       (uint16_t)0x7E0
#define SNIFF_REVERSE_STATUS_PID                                          (uint16_t)0x0803
#define SNIFF_REVERSE_STATUS_MODE                                         (uint8_t)SNIFF
#define SNIFF_REVERSE_STATUS_UUID                                         (uint32_t)((SNIFF_REVERSE_STATUS_MODE << 16) | SNIFF_REVERSE_STATUS_PID)
#define SNIFF_REVERSE_STATUS_LEN                                          (uint8_t)0x0
#define SNIFF_REVERSE_STATUS_UNITS                                        (uint16_t)PID_UNITS_NONE
#define SNIFF_REVERSE_STATUS_LABEL                                        "Reverse"
#define SNIFF_REVERSE_STATUS_DESC                                         "Reverse Status"
#define SNIFF_REVERSE_STATUS_NONE_LOWER                                   (float)0
#define SNIFF_REVERSE_STATUS_NONE_UPPER                                   (float)1
#define SNIFF_REVERSE_STATUS_NONE_PRECISION                               (uint8_t)0
#endif

/**
 * Short term fuel trim Bank 1 expressed in PERCENT
 */
#if defined(MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_HEADER                          (uint16_t)0x7E0
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_PID                             (uint16_t)0x06
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_MODE                            (uint8_t)MODE1
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_UUID                            (uint32_t)((MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_MODE << 16) | MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_PID)
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_LEN                             (uint8_t)0x1
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_UNITS                           (uint16_t)PID_UNITS_PERCENT
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_LABEL                           "STFT1"
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_DESC                            "Short term fuel trim Bank 1"
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_PERCENT_LOWER                   (float)-100
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_PERCENT_UPPER                   (float)99.2
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_1_PERCENT_PRECISION               (uint8_t)1
#endif

/**
 * Short term fuel trim Bank 2 expressed in PERCENT
 */
#if defined(MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_HEADER                          (uint16_t)0x7E0
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_PID                             (uint16_t)0x08
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_MODE                            (uint8_t)MODE1
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_UUID                            (uint32_t)((MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_MODE << 16) | MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_PID)
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_LEN                             (uint8_t)0x1
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_UNITS                           (uint16_t)PID_UNITS_PERCENT
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_LABEL                           "STFT2"
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_DESC                            "Short term fuel trim Bank 2"
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_PERCENT_LOWER                   (float)-100
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_PERCENT_UPPER                   (float)99.2
#define MODE1_SHORT_TERM_FUEL_TRIM_BANK_2_PERCENT_PRECISION               (uint8_t)0
#endif

/**
 * Throttle Position expressed in PERCENT
 */
#if defined(MODE1_THROTTLE_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_THROTTLE_POSITION_HEADER                                    (uint16_t)0x7E0
#define MODE1_THROTTLE_POSITION_PID                                       (uint16_t)0x11
#define MODE1_THROTTLE_POSITION_MODE                                      (uint8_t)MODE1
#define MODE1_THROTTLE_POSITION_UUID                                      (uint32_t)((MODE1_THROTTLE_POSITION_MODE << 16) | MODE1_THROTTLE_POSITION_PID)
#define MODE1_THROTTLE_POSITION_LEN                                       (uint8_t)0x1
#define MODE1_THROTTLE_POSITION_UNITS                                     (uint16_t)PID_UNITS_PERCENT
#define MODE1_THROTTLE_POSITION_LABEL                                     "Throttle"
#define MODE1_THROTTLE_POSITION_DESC                                      "Throttle Position"
#define MODE1_THROTTLE_POSITION_PERCENT_LOWER                             (float)0
#define MODE1_THROTTLE_POSITION_PERCENT_UPPER                             (float)100
#define MODE1_THROTTLE_POSITION_PERCENT_PRECISION                         (uint8_t)1
#endif

/**
 * Timing Advance expressed in DEGREES
 */
#if defined(MODE1_TIMING_ADVANCE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_TIMING_ADVANCE_HEADER                                       (uint16_t)0x7E0
#define MODE1_TIMING_ADVANCE_PID                                          (uint16_t)0x0E
#define MODE1_TIMING_ADVANCE_MODE                                         (uint8_t)MODE1
#define MODE1_TIMING_ADVANCE_UUID                                         (uint32_t)((MODE1_TIMING_ADVANCE_MODE << 16) | MODE1_TIMING_ADVANCE_PID)
#define MODE1_TIMING_ADVANCE_LEN                                          (uint8_t)0x1
#define MODE1_TIMING_ADVANCE_UNITS                                        (uint16_t)PID_UNITS_DEGREES
#define MODE1_TIMING_ADVANCE_LABEL                                        "Timing"
#define MODE1_TIMING_ADVANCE_DESC                                         "Timing Advance"
#define MODE1_TIMING_ADVANCE_DEGREES_LOWER                                (float)-64
#define MODE1_TIMING_ADVANCE_DEGREES_UPPER                                (float)63.5
#define MODE1_TIMING_ADVANCE_DEGREES_PRECISION                            (uint8_t)1
#endif

/**
 * VCT Exhaust Cam Solenoid Duty Cycle expressed in PERCENT
 */
#if defined(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_HEADER                  (uint16_t)0x7E0
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_PID                     (uint16_t)0x0317
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_MODE                    (uint8_t)MODE22
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UUID                    (uint32_t)((MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_MODE << 16) | MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_PID)
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_LEN                     (uint8_t)0x2
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UNITS                   (uint16_t)PID_UNITS_PERCENT
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_LABEL                   "VCT Exh DC"
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_DESC                    "VCT Exhaust Cam Solenoid Duty Cycle"
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_PERCENT_LOWER           (float)0
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_PERCENT_UPPER           (float)100
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_PERCENT_PRECISION       (uint8_t)1
#endif

/**
 * VCT Intake Cam Solenoid Duty Cycle expressed in PERCENT
 */
#if defined(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_HEADER                   (uint16_t)0x7E0
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_PID                      (uint16_t)0x0316
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_MODE                     (uint8_t)MODE22
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UUID                     (uint32_t)((MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_MODE << 16) | MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_PID)
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_LEN                      (uint8_t)0x2
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UNITS                    (uint16_t)PID_UNITS_PERCENT
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_LABEL                    "VCT Int DC"
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_DESC                     "VCT Intake Cam Solenoid Duty Cycle"
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_PERCENT_LOWER            (float)0
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_PERCENT_UPPER            (float)100
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_PERCENT_PRECISION        (uint8_t)1
#endif

/**
 * Vehicle Speed expressed in KMH
 */
#if defined(MODE1_VEHICLE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_VEHICLE_SPEED_HEADER                                        (uint16_t)0x7E0
#define MODE1_VEHICLE_SPEED_PID                                           (uint16_t)0x0D
#define MODE1_VEHICLE_SPEED_MODE                                          (uint8_t)MODE1
#define MODE1_VEHICLE_SPEED_UUID                                          (uint32_t)((MODE1_VEHICLE_SPEED_MODE << 16) | MODE1_VEHICLE_SPEED_PID)
#define MODE1_VEHICLE_SPEED_LEN                                           (uint8_t)0x1
#define MODE1_VEHICLE_SPEED_UNITS                                         (uint16_t)PID_UNITS_KMH
#define MODE1_VEHICLE_SPEED_LABEL                                         "Speed"
#define MODE1_VEHICLE_SPEED_DESC                                          "Vehicle Speed"
#define MODE1_VEHICLE_SPEED_KMH_LOWER                                     (float)0
#define MODE1_VEHICLE_SPEED_KMH_UPPER                                     (float)270
#define MODE1_VEHICLE_SPEED_KMH_PRECISION                                 (uint8_t)0
#define MODE1_VEHICLE_SPEED_MPH_LOWER                                     (float)0
#define MODE1_VEHICLE_SPEED_MPH_UPPER                                     (float)180
#define MODE1_VEHICLE_SPEED_MPH_PRECISION                                 (uint8_t)0
#endif

/**
 * Vehicle Status expressed in NONE
 */
#if defined(SNIFF_VEHICLE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_VEHICLE_STATUS_HEADER                                       (uint16_t)0x7E0
#define SNIFF_VEHICLE_STATUS_PID                                          (uint16_t)0x1260
#define SNIFF_VEHICLE_STATUS_MODE                                         (uint8_t)SNIFF
#define SNIFF_VEHICLE_STATUS_UUID                                         (uint32_t)((SNIFF_VEHICLE_STATUS_MODE << 16) | SNIFF_VEHICLE_STATUS_PID)
#define SNIFF_VEHICLE_STATUS_LEN                                          (uint8_t)0x0
#define SNIFF_VEHICLE_STATUS_UNITS                                        (uint16_t)PID_UNITS_NONE
#define SNIFF_VEHICLE_STATUS_LABEL                                        "Status"
#define SNIFF_VEHICLE_STATUS_DESC                                         "Vehicle Status"
#define SNIFF_VEHICLE_STATUS_NONE_LOWER                                   (float)0
#define SNIFF_VEHICLE_STATUS_NONE_UPPER                                   (float)1
#define SNIFF_VEHICLE_STATUS_NONE_PRECISION                               (uint8_t)0
#endif

