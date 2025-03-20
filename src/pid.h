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
 * Commanded Air to Fuel Ratio expressed in PID_UNITS_RATIO
 */
#if defined(MODE1_COMMANDED_AIR_TO_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_COMMANDED_AIR_TO_FUEL_RATIO_HEADER                       (uint16_t)0x7E0
#define MODE1_COMMANDED_AIR_TO_FUEL_RATIO                              (uint16_t)0x44
#define MODE1_COMMANDED_AIR_TO_FUEL_RATIO_MODE                         MODE1
#define MODE1_COMMANDED_AIR_TO_FUEL_RATIO_LEN                          (uint8_t)0x2
#define MODE1_COMMANDED_AIR_TO_FUEL_RATIO_UNITS                        (uint16_t)PID_UNITS_RATIO
#define MODE1_COMMANDED_AIR_TO_FUEL_RATIO_LABEL                        "Cmd AFR"
#define MODE1_COMMANDED_AIR_TO_FUEL_RATIO_LOWER                        (float)0
#define MODE1_COMMANDED_AIR_TO_FUEL_RATIO_UPPER                        (float)29.4
#endif

/**
 * Calculated engine load expressed in PID_UNITS_PERCENT
 */
#if defined(MODE1_CALCULATED_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_CALCULATED_ENGINE_LOAD_HEADER                            (uint16_t)0x7E0
#define MODE1_CALCULATED_ENGINE_LOAD                                   (uint16_t)0x04
#define MODE1_CALCULATED_ENGINE_LOAD_MODE                              MODE1
#define MODE1_CALCULATED_ENGINE_LOAD_LEN                               (uint8_t)0x1
#define MODE1_CALCULATED_ENGINE_LOAD_UNITS                             (uint16_t)PID_UNITS_PERCENT
#define MODE1_CALCULATED_ENGINE_LOAD_LABEL                             "Load"
#define MODE1_CALCULATED_ENGINE_LOAD_LOWER                             (float)0
#define MODE1_CALCULATED_ENGINE_LOAD_UPPER                             (float)100
#endif

/**
 * Engine coolant temperature expressed in PID_UNITS_CELSIUS
 */
#if defined(MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ENGINE_COOLANT_TEMPERATURE_HEADER                        (uint16_t)0x7E0
#define MODE1_ENGINE_COOLANT_TEMPERATURE                               (uint16_t)0x05
#define MODE1_ENGINE_COOLANT_TEMPERATURE_MODE                          MODE1
#define MODE1_ENGINE_COOLANT_TEMPERATURE_LEN                           (uint8_t)0x1
#define MODE1_ENGINE_COOLANT_TEMPERATURE_UNITS                         (uint16_t)PID_UNITS_CELSIUS
#define MODE1_ENGINE_COOLANT_TEMPERATURE_LABEL                         "ECT"
#define MODE1_ENGINE_COOLANT_TEMPERATURE_LOWER                         (float)-40
#define MODE1_ENGINE_COOLANT_TEMPERATURE_UPPER                         (float)215
#endif

/**
 * Short term fuel trim - Bank 1 expressed in PID_UNITS_PERCENT
 */
#if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_HEADER                     (uint16_t)0x7E0
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_1                            (uint16_t)0x06
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_MODE                       MODE1
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_LEN                        (uint8_t)0x1
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_UNITS                      (uint16_t)PID_UNITS_PERCENT
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_LABEL                      "STFT1"
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_LOWER                      (float)-100
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_1_UPPER                      (float)99.2
#endif

/**
 * Long term fuel trim - Bank 1 expressed in PID_UNITS_PERCENT
 */
#if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_1_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_1_HEADER                      (uint16_t)0x7E0
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_1                             (uint16_t)0x07
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_1_MODE                        MODE1
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_1_LEN                         (uint8_t)0x1
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_1_UNITS                       (uint16_t)PID_UNITS_PERCENT
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_1_LABEL                       "LTFT1"
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_1_LOWER                       (float)-100
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_1_UPPER                       (float)99.2
#endif

/**
 * Short term fuel trim - Bank 2 expressed in PID_UNITS_PERCENT
 */
#if defined(MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_HEADER                     (uint16_t)0x7E0
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_2                            (uint16_t)0x08
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_MODE                       MODE1
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_LEN                        (uint8_t)0x1
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_UNITS                      (uint16_t)PID_UNITS_PERCENT
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_LABEL                      "STFT2"
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_LOWER                      (float)-100
#define MODE1_SHORT_TERM_FUEL_TRIM__BANK_2_UPPER                      (float)99.2
#endif

/**
 * Long term fuel trim - Bank 2 expressed in PID_UNITS_PERCENT
 */
#if defined(MODE1_LONG_TERM_FUEL_TRIM__BANK_2_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_2_HEADER                      (uint16_t)0x7E0
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_2                             (uint16_t)0x09
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_2_MODE                        MODE1
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_2_LEN                         (uint8_t)0x1
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_2_UNITS                       (uint16_t)PID_UNITS_PERCENT
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_2_LABEL                       "LTFT2"
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_2_LOWER                       (float)-100
#define MODE1_LONG_TERM_FUEL_TRIM__BANK_2_UPPER                       (float)99.2
#endif

/**
 * Fuel Pressure expressed in PID_UNITS_KPA
 */
#if defined(MODE1_FUEL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_FUEL_PRESSURE_HEADER                                     (uint16_t)0x7E0
#define MODE1_FUEL_PRESSURE                                            (uint16_t)0x0A
#define MODE1_FUEL_PRESSURE_MODE                                       MODE1
#define MODE1_FUEL_PRESSURE_LEN                                        (uint8_t)0x1
#define MODE1_FUEL_PRESSURE_UNITS                                      (uint16_t)PID_UNITS_KPA
#define MODE1_FUEL_PRESSURE_LABEL                                      "Fuel"
#define MODE1_FUEL_PRESSURE_LOWER                                      (float)0
#define MODE1_FUEL_PRESSURE_UPPER                                      (float)765
#endif

/**
 * Intake manifold absolute pressure expressed in PID_UNITS_KPA
 */
#if defined(MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_HEADER                 (uint16_t)0x7E0
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE                        (uint16_t)0x0B
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_MODE                   MODE1
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LEN                    (uint8_t)0x1
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_UNITS                  (uint16_t)PID_UNITS_KPA
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LABEL                  "MAP"
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LOWER                  (float)0
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_UPPER                  (float)255
#endif

/**
 * Engine speed expressed in PID_UNITS_RPM
 */
#if defined(MODE1_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ENGINE_SPEED_HEADER                                      (uint16_t)0x7E0
#define MODE1_ENGINE_SPEED                                             (uint16_t)0x0C
#define MODE1_ENGINE_SPEED_MODE                                        MODE1
#define MODE1_ENGINE_SPEED_LEN                                         (uint8_t)0x2
#define MODE1_ENGINE_SPEED_UNITS                                       (uint16_t)PID_UNITS_RPM
#define MODE1_ENGINE_SPEED_LABEL                                       "RPM"
#define MODE1_ENGINE_SPEED_LOWER                                       (float)0
#define MODE1_ENGINE_SPEED_UPPER                                       (float)8000
#endif

/**
 * Vehicle speed expressed in PID_UNITS_KMH
 */
#if defined(MODE1_VEHICLE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_VEHICLE_SPEED_HEADER                                     (uint16_t)0x7E0
#define MODE1_VEHICLE_SPEED                                            (uint16_t)0x0D
#define MODE1_VEHICLE_SPEED_MODE                                       MODE1
#define MODE1_VEHICLE_SPEED_LEN                                        (uint8_t)0x1
#define MODE1_VEHICLE_SPEED_UNITS                                      (uint16_t)PID_UNITS_KMH
#define MODE1_VEHICLE_SPEED_LABEL                                      "Speed"
#define MODE1_VEHICLE_SPEED_LOWER                                      (float)0
#define MODE1_VEHICLE_SPEED_UPPER                                      (float)270
#endif

/**
 * Timing advance expressed in PID_UNITS_DEGREES
 */
#if defined(MODE1_TIMING_ADVANCE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_TIMING_ADVANCE_HEADER                                    (uint16_t)0x7E0
#define MODE1_TIMING_ADVANCE                                           (uint16_t)0x0E
#define MODE1_TIMING_ADVANCE_MODE                                      MODE1
#define MODE1_TIMING_ADVANCE_LEN                                       (uint8_t)0x1
#define MODE1_TIMING_ADVANCE_UNITS                                     (uint16_t)PID_UNITS_DEGREES
#define MODE1_TIMING_ADVANCE_LABEL                                     "Timing"
#define MODE1_TIMING_ADVANCE_LOWER                                     (float)-64
#define MODE1_TIMING_ADVANCE_UPPER                                     (float)63.5
#endif

/**
 * Intake air temperature expressed in PID_UNITS_CELSIUS
 */
#if defined(MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_INTAKE_AIR_TEMPERATURE_HEADER                            (uint16_t)0x7E0
#define MODE1_INTAKE_AIR_TEMPERATURE                                   (uint16_t)0x0F
#define MODE1_INTAKE_AIR_TEMPERATURE_MODE                              MODE1
#define MODE1_INTAKE_AIR_TEMPERATURE_LEN                               (uint8_t)0x1
#define MODE1_INTAKE_AIR_TEMPERATURE_UNITS                             (uint16_t)PID_UNITS_CELSIUS
#define MODE1_INTAKE_AIR_TEMPERATURE_LABEL                             "IAT"
#define MODE1_INTAKE_AIR_TEMPERATURE_LOWER                             (float)-40
#define MODE1_INTAKE_AIR_TEMPERATURE_UPPER                             (float)200
#endif

/**
 * Mass air flow sensor air flow rate expressed in PID_UNITS_GRAMSEC
 */
#if defined(MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_HEADER                (uint16_t)0x7E0
#define MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE                       (uint16_t)0x10
#define MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_MODE                  MODE1
#define MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_LEN                   (uint8_t)0x1
#define MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_UNITS                 (uint16_t)PID_UNITS_GRAMSEC
#define MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_LABEL                 "MAF"
#define MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_LOWER                 (float)0
#define MODE1_MASS_AIR_FLOW_SENSOR_AIR_FLOW_RATE_UPPER                 (float)655.35
#endif

/**
 * Throttle position expressed in PID_UNITS_PERCENT
 */
#if defined(MODE1_THROTTLE_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_THROTTLE_POSITION_HEADER                                 (uint16_t)0x7E0
#define MODE1_THROTTLE_POSITION                                        (uint16_t)0x11
#define MODE1_THROTTLE_POSITION_MODE                                   MODE1
#define MODE1_THROTTLE_POSITION_LEN                                    (uint8_t)0x1
#define MODE1_THROTTLE_POSITION_UNITS                                  (uint16_t)PID_UNITS_PERCENT
#define MODE1_THROTTLE_POSITION_LABEL                                  "Throttle"
#define MODE1_THROTTLE_POSITION_LOWER                                  (float)0
#define MODE1_THROTTLE_POSITION_UPPER                                  (float)100
#endif

/**
 * Oxygen Sensor 2 Voltage expressed in PID_UNITS_VOLTS
 */
#if defined(MODE1_OXYGEN_SENSOR_2_VOLTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_OXYGEN_SENSOR_2_VOLTAGE_HEADER                           (uint16_t)0x7E0
#define MODE1_OXYGEN_SENSOR_2_VOLTAGE                                  (uint16_t)0x15
#define MODE1_OXYGEN_SENSOR_2_VOLTAGE_MODE                             MODE1
#define MODE1_OXYGEN_SENSOR_2_VOLTAGE_LEN                              (uint8_t)0x2
#define MODE1_OXYGEN_SENSOR_2_VOLTAGE_UNITS                            (uint16_t)PID_UNITS_VOLTS
#define MODE1_OXYGEN_SENSOR_2_VOLTAGE_LABEL                            "O2"
#define MODE1_OXYGEN_SENSOR_2_VOLTAGE_LOWER                            (float)0
#define MODE1_OXYGEN_SENSOR_2_VOLTAGE_UPPER                            (float)1.275
#endif

/**
 * Fuel Rail Pressure relative to manifold vacuum expressed in PID_UNITS_KPA
 */
#if defined(MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_HEADER    (uint16_t)0x7E0
#define MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM           (uint16_t)0x22
#define MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_MODE      MODE1
#define MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_LEN       (uint8_t)0x2
#define MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_UNITS     (uint16_t)PID_UNITS_KPA
#define MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_LABEL     "Fuel"
#define MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_LOWER     (float)0
#define MODE1_FUEL_RAIL_PRESSURE_RELATIVE_TO_MANIFOLD_VACUUM_UPPER     (float)5177
#endif

/**
 * Absolute barometric pressure expressed in PID_UNITS_KPA
 */
#if defined(MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_HEADER                      (uint16_t)0x7E0
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE                             (uint16_t)0x33
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_MODE                        MODE1
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_LEN                         (uint8_t)0x1
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_UNITS                       (uint16_t)PID_UNITS_KPA
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_LABEL                       "Baro"
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_LOWER                       (float)0
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_UPPER                       (float)255
#endif

/**
 * Air to Fuel Ratio expressed in PID_UNITS_RATIO
 */
#if defined(MODE1_AIR_TO_FUEL_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_AIR_TO_FUEL_RATIO_HEADER                                 (uint16_t)0x7E0
#define MODE1_AIR_TO_FUEL_RATIO                                        (uint16_t)0x34
#define MODE1_AIR_TO_FUEL_RATIO_MODE                                   MODE1
#define MODE1_AIR_TO_FUEL_RATIO_LEN                                    (uint8_t)0x4
#define MODE1_AIR_TO_FUEL_RATIO_UNITS                                  (uint16_t)PID_UNITS_RATIO
#define MODE1_AIR_TO_FUEL_RATIO_LABEL                                  "AFR"
#define MODE1_AIR_TO_FUEL_RATIO_LOWER                                  (float)0
#define MODE1_AIR_TO_FUEL_RATIO_UPPER                                  (float)29.4
#endif

/**
 * Relative accelerator pedal position expressed in PID_UNITS_PERCENT
 */
#if defined(MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_HEADER               (uint16_t)0x7E0
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION                      (uint16_t)0x5A
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_MODE                 MODE1
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_LEN                  (uint8_t)0x1
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_UNITS                (uint16_t)PID_UNITS_PERCENT
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_LABEL                "APP"
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_LOWER                (float)0
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_UPPER                (float)100
#endif

/**
 * Engine oil temperature expressed in PID_UNITS_CELSIUS
 */
#if defined(MODE1_ENGINE_OIL_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ENGINE_OIL_TEMPERATURE_HEADER                            (uint16_t)0x7E0
#define MODE1_ENGINE_OIL_TEMPERATURE                                   (uint16_t)0x5C
#define MODE1_ENGINE_OIL_TEMPERATURE_MODE                              MODE1
#define MODE1_ENGINE_OIL_TEMPERATURE_LEN                               (uint8_t)0x1
#define MODE1_ENGINE_OIL_TEMPERATURE_UNITS                             (uint16_t)PID_UNITS_CELSIUS
#define MODE1_ENGINE_OIL_TEMPERATURE_LABEL                             "Oil Temp"
#define MODE1_ENGINE_OIL_TEMPERATURE_LOWER                             (float)-40
#define MODE1_ENGINE_OIL_TEMPERATURE_UPPER                             (float)200
#endif

/**
 * Turbocharger compressor inlet pressure expressed in PID_UNITS_KPA
 */
#if defined(MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_HEADER            (uint16_t)0x7E0
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE                   (uint16_t)0x6F
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_MODE              MODE1
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LEN               (uint8_t)0x1
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UNITS             (uint16_t)PID_UNITS_KPA
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LABEL             "Boost"
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LOWER             (float)0
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UPPER             (float)255
#endif

/**
 * Lateral G expressed in PID_UNITS_G_FORCE
 */
#if defined(MODE22_LATERAL_G_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_LATERAL_G_HEADER                                         (uint16_t)0x7E0
#define MODE22_LATERAL_G                                                (uint16_t)0x2B0C
#define MODE22_LATERAL_G_MODE                                           MODE22
#define MODE22_LATERAL_G_LEN                                            (uint8_t)0x2
#define MODE22_LATERAL_G_UNITS                                          (uint16_t)PID_UNITS_G_FORCE
#define MODE22_LATERAL_G_LABEL                                          "Lat G"
#define MODE22_LATERAL_G_LOWER                                          (float)-1
#define MODE22_LATERAL_G_UPPER                                          (float)1
#endif

/**
 * Longitude G expressed in PID_UNITS_G_FORCE
 */
#if defined(MODE22_LONGITUDE_G_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_LONGITUDE_G_HEADER                                       (uint16_t)0x7E0
#define MODE22_LONGITUDE_G                                              (uint16_t)0x2B11
#define MODE22_LONGITUDE_G_MODE                                         MODE22
#define MODE22_LONGITUDE_G_LEN                                          (uint8_t)0x2
#define MODE22_LONGITUDE_G_UNITS                                        (uint16_t)PID_UNITS_G_FORCE
#define MODE22_LONGITUDE_G_LABEL                                        "Long G"
#define MODE22_LONGITUDE_G_LOWER                                        (float)-1
#define MODE22_LONGITUDE_G_UPPER                                        (float)1
#endif

/**
 * Manifold Absolute Pressure Sensor Voltage 1 expressed in PID_UNITS_VOLTS
 */
#if defined(MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_HEADER       (uint16_t)0x7E0
#define MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1              (uint16_t)0x0301
#define MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_MODE         MODE22
#define MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_LEN          (uint8_t)0x2
#define MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_UNITS        (uint16_t)PID_UNITS_VOLTS
#define MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_LABEL        "MAP"
#define MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_LOWER        (float)0
#define MODE22_MANIFOLD_ABSOLUTE_PRESSURE_SENSOR_VOLTAGE_1_UPPER        (float)5
#endif

/**
 * Low Pressure Fuel Pump Commanded Duty Cycle expressed in PID_UNITS_PERCENT
 */
#if defined(MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_HEADER       (uint16_t)0x7E0
#define MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE              (uint16_t)0x0307
#define MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_MODE         MODE22
#define MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_LEN          (uint8_t)0x2
#define MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_UNITS        (uint16_t)PID_UNITS_PERCENT
#define MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_LABEL        "LPFP DC"
#define MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_LOWER        (float)0
#define MODE22_LOW_PRESSURE_FUEL_PUMP_COMMANDED_DUTY_CYCLE_UPPER        (float)100
#endif

/**
 * Ignition Correction Cylinder 1 expressed in PID_UNITS_DEGREES
 */
#if defined(MODE22_IGNITION_CORRECTION_CYLINDER_1_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_HEADER                    (uint16_t)0x7E0
#define MODE22_IGNITION_CORRECTION_CYLINDER_1                           (uint16_t)0x03EC
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_MODE                      MODE22
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_LEN                       (uint8_t)0x2
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_UNITS                     (uint16_t)PID_UNITS_DEGREES
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_LABEL                     "IGN 1"
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_LOWER                     (float)-16
#define MODE22_IGNITION_CORRECTION_CYLINDER_1_UPPER                     (float)16
#endif

/**
 * VCT Intake Cam Solenoid Duty Cycle expressed in PID_UNITS_PERCENT
 */
#if defined(MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_HEADER                (uint16_t)0x7E0
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE                       (uint16_t)0x0316
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_MODE                  MODE22
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_LEN                   (uint8_t)0x2
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UNITS                 (uint16_t)PID_UNITS_PERCENT
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_LABEL                 "VCT Int DC"
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_LOWER                 (float)0
#define MODE22_VCT_INTAKE_CAM_SOLENOID_DUTY_CYCLE_UPPER                 (float)100
#endif

/**
 * VCT Exhaust Cam Solenoid Duty Cycle expressed in PID_UNITS_PERCENT
 */
#if defined(MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_HEADER               (uint16_t)0x7E0
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE                      (uint16_t)0x0317
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_MODE                 MODE22
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_LEN                  (uint8_t)0x2
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UNITS                (uint16_t)PID_UNITS_PERCENT
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_LABEL                "VCT Exh DC"
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_LOWER                (float)0
#define MODE22_VCT_EXHAUST_CAM_SOLENOID_DUTY_CYCLE_UPPER                (float)100
#endif

/**
 * Intake air temperature expressed in PID_UNITS_CELSIUS
 */
#if defined(MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_INTAKE_AIR_TEMPERATURE_HEADER                            (uint16_t)0x7E0
#define MODE22_INTAKE_AIR_TEMPERATURE                                   (uint16_t)0xF40F
#define MODE22_INTAKE_AIR_TEMPERATURE_MODE                              MODE22
#define MODE22_INTAKE_AIR_TEMPERATURE_LEN                               (uint8_t)0x1
#define MODE22_INTAKE_AIR_TEMPERATURE_UNITS                             (uint16_t)PID_UNITS_CELSIUS
#define MODE22_INTAKE_AIR_TEMPERATURE_LABEL                             "IAT"
#define MODE22_INTAKE_AIR_TEMPERATURE_LOWER                             (float)-40
#define MODE22_INTAKE_AIR_TEMPERATURE_UPPER                             (float)200
#endif

/**
 * Charge air temperature expressed in PID_UNITS_CELSIUS
 */
#if defined(MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_CHARGE_AIR_TEMPERATURE_HEADER                            (uint16_t)0x7E0
#define MODE22_CHARGE_AIR_TEMPERATURE                                   (uint16_t)0x0461
#define MODE22_CHARGE_AIR_TEMPERATURE_MODE                              MODE22
#define MODE22_CHARGE_AIR_TEMPERATURE_LEN                               (uint8_t)0x2
#define MODE22_CHARGE_AIR_TEMPERATURE_UNITS                             (uint16_t)PID_UNITS_CELSIUS
#define MODE22_CHARGE_AIR_TEMPERATURE_LABEL                             "CAT"
#define MODE22_CHARGE_AIR_TEMPERATURE_LOWER                             (float)-40
#define MODE22_CHARGE_AIR_TEMPERATURE_UPPER                             (float)200
#endif

/**
 * Manifold charge temperature expressed in PID_UNITS_CELSIUS
 */
#if defined(MODE22_MANIFOLD_CHARGE_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_MANIFOLD_CHARGE_TEMPERATURE_HEADER                       (uint16_t)0x7E0
#define MODE22_MANIFOLD_CHARGE_TEMPERATURE                              (uint16_t)0x03CA
#define MODE22_MANIFOLD_CHARGE_TEMPERATURE_MODE                         MODE22
#define MODE22_MANIFOLD_CHARGE_TEMPERATURE_LEN                          (uint8_t)0x1
#define MODE22_MANIFOLD_CHARGE_TEMPERATURE_UNITS                        (uint16_t)PID_UNITS_CELSIUS
#define MODE22_MANIFOLD_CHARGE_TEMPERATURE_LABEL                        "MCT"
#define MODE22_MANIFOLD_CHARGE_TEMPERATURE_LOWER                        (float)-40
#define MODE22_MANIFOLD_CHARGE_TEMPERATURE_UPPER                        (float)200
#endif

/**
 * Octane Adjust Ratio expressed in PID_UNITS_RATIO
 */
#if defined(MODE22_OCTANE_ADJUST_RATIO_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_OCTANE_ADJUST_RATIO_HEADER                               (uint16_t)0x7E0
#define MODE22_OCTANE_ADJUST_RATIO                                      (uint16_t)0x03E8
#define MODE22_OCTANE_ADJUST_RATIO_MODE                                 MODE22
#define MODE22_OCTANE_ADJUST_RATIO_LEN                                  (uint8_t)0x2
#define MODE22_OCTANE_ADJUST_RATIO_UNITS                                (uint16_t)PID_UNITS_RATIO
#define MODE22_OCTANE_ADJUST_RATIO_LABEL                                "OAR"
#define MODE22_OCTANE_ADJUST_RATIO_LOWER                                (float)-1
#define MODE22_OCTANE_ADJUST_RATIO_UPPER                                (float)1
#endif

/**
 * Ambient air temperature expressed in PID_UNITS_CELSIUS
 */
#if defined(MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_AMBIENT_AIR_TEMPERATURE_HEADER                           (uint16_t)0x7E0
#define MODE22_AMBIENT_AIR_TEMPERATURE                                  (uint16_t)0x057D
#define MODE22_AMBIENT_AIR_TEMPERATURE_MODE                             MODE22
#define MODE22_AMBIENT_AIR_TEMPERATURE_LEN                              (uint8_t)0x1
#define MODE22_AMBIENT_AIR_TEMPERATURE_UNITS                            (uint16_t)PID_UNITS_CELSIUS
#define MODE22_AMBIENT_AIR_TEMPERATURE_LABEL                            "AAT"
#define MODE22_AMBIENT_AIR_TEMPERATURE_LOWER                            (float)-40
#define MODE22_AMBIENT_AIR_TEMPERATURE_UPPER                            (float)200
#endif

/**
 * Engine load percentage expressed in PID_UNITS_PERCENT
 */
#if defined(MODE22_ENGINE_LOAD_PERCENTAGE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_ENGINE_LOAD_PERCENTAGE_HEADER                            (uint16_t)0x7E0
#define MODE22_ENGINE_LOAD_PERCENTAGE                                   (uint16_t)0xF404
#define MODE22_ENGINE_LOAD_PERCENTAGE_MODE                              MODE22
#define MODE22_ENGINE_LOAD_PERCENTAGE_LEN                               (uint8_t)0x1
#define MODE22_ENGINE_LOAD_PERCENTAGE_UNITS                             (uint16_t)PID_UNITS_PERCENT
#define MODE22_ENGINE_LOAD_PERCENTAGE_LABEL                             "Load"
#define MODE22_ENGINE_LOAD_PERCENTAGE_LOWER                             (float)0
#define MODE22_ENGINE_LOAD_PERCENTAGE_UPPER                             (float)100
#endif

/**
 * Catalytic Temperature expressed in PID_UNITS_CELSIUS
 */
#if defined(MODE22_CATALYTIC_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_CATALYTIC_TEMPERATURE_HEADER                             (uint16_t)0x7E0
#define MODE22_CATALYTIC_TEMPERATURE                                    (uint16_t)0xF43C
#define MODE22_CATALYTIC_TEMPERATURE_MODE                               MODE22
#define MODE22_CATALYTIC_TEMPERATURE_LEN                                (uint8_t)0x2
#define MODE22_CATALYTIC_TEMPERATURE_UNITS                              (uint16_t)PID_UNITS_CELSIUS
#define MODE22_CATALYTIC_TEMPERATURE_LABEL                              "Cat Temp"
#define MODE22_CATALYTIC_TEMPERATURE_LOWER                              (float)0
#define MODE22_CATALYTIC_TEMPERATURE_UPPER                              (float)1000
#endif

/**
 * Gauge Brightness expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_GAUGE_BRIGHTNESS_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_GAUGE_BRIGHTNESS_HEADER                                  (uint16_t)0x7E0
#define SNIFF_GAUGE_BRIGHTNESS                                         (uint16_t)0x01C8
#define SNIFF_GAUGE_BRIGHTNESS_MODE                                    SNIFF
#define SNIFF_GAUGE_BRIGHTNESS_LEN                                     (uint8_t)0x0
#define SNIFF_GAUGE_BRIGHTNESS_UNITS                                   (uint16_t)PID_UNITS_NONE
#define SNIFF_GAUGE_BRIGHTNESS_LABEL                                   "Brightness"
#define SNIFF_GAUGE_BRIGHTNESS_LOWER                                   (float)0
#define SNIFF_GAUGE_BRIGHTNESS_UPPER                                   (float)31
#endif

/**
 * Vehicle Status expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_VEHICLE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_VEHICLE_STATUS_HEADER                                    (uint16_t)0x7E0
#define SNIFF_VEHICLE_STATUS                                           (uint16_t)0x1260
#define SNIFF_VEHICLE_STATUS_MODE                                      SNIFF
#define SNIFF_VEHICLE_STATUS_LEN                                       (uint8_t)0x0
#define SNIFF_VEHICLE_STATUS_UNITS                                     (uint16_t)PID_UNITS_NONE
#define SNIFF_VEHICLE_STATUS_LABEL                                     "Status"
#define SNIFF_VEHICLE_STATUS_LOWER                                     (float)0
#define SNIFF_VEHICLE_STATUS_UPPER                                     (float)1
#endif

/**
 * Brake Pedal Status expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_BRAKE_PEDAL_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_BRAKE_PEDAL_STATUS_HEADER                                (uint16_t)0x7E0
#define SNIFF_BRAKE_PEDAL_STATUS                                       (uint16_t)0x0802
#define SNIFF_BRAKE_PEDAL_STATUS_MODE                                  SNIFF
#define SNIFF_BRAKE_PEDAL_STATUS_LEN                                   (uint8_t)0x0
#define SNIFF_BRAKE_PEDAL_STATUS_UNITS                                 (uint16_t)PID_UNITS_NONE
#define SNIFF_BRAKE_PEDAL_STATUS_LABEL                                 "Brake Pedal"
#define SNIFF_BRAKE_PEDAL_STATUS_LOWER                                 (float)0
#define SNIFF_BRAKE_PEDAL_STATUS_UPPER                                 (float)1
#endif

/**
 * Emergency Brake Status expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_EMERGENCY_BRAKE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_EMERGENCY_BRAKE_STATUS_HEADER                            (uint16_t)0x7E0
#define SNIFF_EMERGENCY_BRAKE_STATUS                                   (uint16_t)0x0C82
#define SNIFF_EMERGENCY_BRAKE_STATUS_MODE                              SNIFF
#define SNIFF_EMERGENCY_BRAKE_STATUS_LEN                               (uint8_t)0x0
#define SNIFF_EMERGENCY_BRAKE_STATUS_UNITS                             (uint16_t)PID_UNITS_NONE
#define SNIFF_EMERGENCY_BRAKE_STATUS_LABEL                             "E-Brake"
#define SNIFF_EMERGENCY_BRAKE_STATUS_LOWER                             (float)0
#define SNIFF_EMERGENCY_BRAKE_STATUS_UPPER                             (float)1
#endif

/**
 * Reverse Status expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_REVERSE_STATUS_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_REVERSE_STATUS_HEADER                                    (uint16_t)0x7E0
#define SNIFF_REVERSE_STATUS                                           (uint16_t)0x0803
#define SNIFF_REVERSE_STATUS_MODE                                      SNIFF
#define SNIFF_REVERSE_STATUS_LEN                                       (uint8_t)0x0
#define SNIFF_REVERSE_STATUS_UNITS                                     (uint16_t)PID_UNITS_NONE
#define SNIFF_REVERSE_STATUS_LABEL                                     "Reverse"
#define SNIFF_REVERSE_STATUS_LOWER                                     (float)0
#define SNIFF_REVERSE_STATUS_UPPER                                     (float)1
#endif

/**
 * Cruise Control ON button expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_ON_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_HEADER                          (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_ON_BUTTON                                 (uint16_t)0x0301
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_MODE                            SNIFF
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_LEN                             (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_UNITS                           (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_LABEL                           "ON Button"
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_LOWER                           (float)0
#define SNIFF_CRUISE_CONTROL_ON_BUTTON_UPPER                           (float)1
#endif

/**
 * Cruise Control OFF button expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_OFF_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_HEADER                         (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON                                (uint16_t)0x0302
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_MODE                           SNIFF
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_LEN                            (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_UNITS                          (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_LABEL                          "OFF Button"
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_LOWER                          (float)0
#define SNIFF_CRUISE_CONTROL_OFF_BUTTON_UPPER                          (float)1
#endif

/**
 * Cruise Control OFF button Toggle expressed in PID_UNITS_NONE
 */
#if defined(CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_SUPPORTED) || !defined(LIMIT_PIDS)
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_HEADER                  (uint16_t)0x7E0
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE                         (uint16_t)0x0302
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_MODE                    CALC1
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_LEN                     (uint8_t)0x0
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UNITS                   (uint16_t)PID_UNITS_NONE
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_LABEL                   "OFF Button"
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_LOWER                   (float)0
#define CALC1_CRUISE_CONTROL_OFF_BUTTON_TOGGLE_UPPER                   (float)1
#endif

/**
 * Cruise Control SET plus button expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_HEADER                    (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON                           (uint16_t)0x0303
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_MODE                      SNIFF
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_LEN                       (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UNITS                     (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_LABEL                     "SET+ Button"
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_LOWER                     (float)0
#define SNIFF_CRUISE_CONTROL_SET_PLUS_BUTTON_UPPER                     (float)1
#endif

/**
 * Cruise Control SET minus button expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_HEADER                   (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON                          (uint16_t)0x0304
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_MODE                     SNIFF
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_LEN                      (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UNITS                    (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_LABEL                    "SET- Button"
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_LOWER                    (float)0
#define SNIFF_CRUISE_CONTROL_SET_MINUS_BUTTON_UPPER                    (float)1
#endif

/**
 * Cruise Control RES button expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_RES_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_HEADER                         (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_RES_BUTTON                                (uint16_t)0x0305
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_MODE                           SNIFF
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_LEN                            (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_UNITS                          (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_LABEL                          "RES Button"
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_LOWER                          (float)0
#define SNIFF_CRUISE_CONTROL_RES_BUTTON_UPPER                          (float)1
#endif

/**
 * Cruise Control CAN button expressed in PID_UNITS_NONE
 */
#if defined(SNIFF_CRUISE_CONTROL_CAN_BUTTON_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_HEADER                         (uint16_t)0x7E0
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON                                (uint16_t)0x0306
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_MODE                           SNIFF
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_LEN                            (uint8_t)0x0
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_UNITS                          (uint16_t)PID_UNITS_NONE
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_LABEL                          "CAN Button"
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_LOWER                          (float)0
#define SNIFF_CRUISE_CONTROL_CAN_BUTTON_UPPER                          (float)1
#endif

/**
 * Turbocharger compressor inlet pressure expressed in PID_UNITS_KPA
 */
#if defined(CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_HEADER            (uint16_t)0x7E0
#define CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE                   (uint16_t)0x6F
#define CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_MODE              CALC1
#define CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LEN               (uint8_t)0x0
#define CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UNITS             (uint16_t)PID_UNITS_KPA
#define CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LABEL             "Boost"
#define CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LOWER             (float)-82
#define CALC1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UPPER             (float)170
#endif

/**
 * Lateral Acceleration expressed in PID_UNITS_G_FORCE
 */
#if defined(SNIFF_LATERAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_LATERAL_ACCELERATION_HEADER                              (uint16_t)0x180
#define SNIFF_LATERAL_ACCELERATION                                     (uint16_t)0x1802
#define SNIFF_LATERAL_ACCELERATION_MODE                                SNIFF
#define SNIFF_LATERAL_ACCELERATION_LEN                                 (uint8_t)0x0
#define SNIFF_LATERAL_ACCELERATION_UNITS                               (uint16_t)PID_UNITS_G_FORCE
#define SNIFF_LATERAL_ACCELERATION_LABEL                               "Lat Accel"
#define SNIFF_LATERAL_ACCELERATION_LOWER                               (float)0
#define SNIFF_LATERAL_ACCELERATION_UPPER                               (float)2
#endif

/**
 * Longitudinal Acceleration expressed in PID_UNITS_G_FORCE
 */
#if defined(SNIFF_LONGITUDINAL_ACCELERATION_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_LONGITUDINAL_ACCELERATION_HEADER                         (uint16_t)0x160
#define SNIFF_LONGITUDINAL_ACCELERATION                                (uint16_t)0x1602
#define SNIFF_LONGITUDINAL_ACCELERATION_MODE                           SNIFF
#define SNIFF_LONGITUDINAL_ACCELERATION_LEN                            (uint8_t)0x0
#define SNIFF_LONGITUDINAL_ACCELERATION_UNITS                          (uint16_t)PID_UNITS_G_FORCE
#define SNIFF_LONGITUDINAL_ACCELERATION_LABEL                          "Long Accel"
#define SNIFF_LONGITUDINAL_ACCELERATION_LOWER                          (float)0
#define SNIFF_LONGITUDINAL_ACCELERATION_UPPER                          (float)2
#endif

