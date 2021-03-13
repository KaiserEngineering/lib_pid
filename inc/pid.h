/**
 ******************************************************************************
 * 
 * Copyright (c) 2021 KaiserEngineering, LLC
 * Author Matthew Kaiser 
 * File Auto-Generated Mar-13-2021
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
 * Calculated engine load expressed in PID_UNITS_PERCENT
 */
#if defined(MODE1_CALCULATED_ENGINE_LOAD_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_CALCULATED_ENGINE_LOAD                          (uint16_t)0x04
#define MODE1_CALCULATED_ENGINE_LOAD_LEN                      (uint8_t)0x1
#define MODE1_CALCULATED_ENGINE_LOAD_UNITS                    (uint16_t)PID_UNITS_PERCENT
#endif

/**
 * Engine coolant temperature expressed in PID_UNITS_CELCIUS
 */
#if defined(MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ENGINE_COOLANT_TEMPERATURE                      (uint16_t)0x05
#define MODE1_ENGINE_COOLANT_TEMPERATURE_LEN                  (uint8_t)0x1
#define MODE1_ENGINE_COOLANT_TEMPERATURE_UNITS                (uint16_t)PID_UNITS_CELCIUS
#endif

/**
 * Fuel Pressure expressed in PID_UNITS_KPA
 */
#if defined(MODE1_FUEL_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_FUEL_PRESSURE                                   (uint16_t)0x0A
#define MODE1_FUEL_PRESSURE_LEN                               (uint8_t)0x1
#define MODE1_FUEL_PRESSURE_UNITS                             (uint16_t)PID_UNITS_KPA
#endif

/**
 * Intake manifold absolute pressure expressed in PID_UNITS_KPA
 */
#if defined(MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE               (uint16_t)0x0B
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LEN           (uint8_t)0x1
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_UNITS         (uint16_t)PID_UNITS_KPA
#endif

/**
 * Engine speed expressed in PID_UNITS_RPM
 */
#if defined(MODE1_ENGINE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ENGINE_SPEED                                    (uint16_t)0x0C
#define MODE1_ENGINE_SPEED_LEN                                (uint8_t)0x2
#define MODE1_ENGINE_SPEED_UNITS                              (uint16_t)PID_UNITS_RPM
#endif

/**
 * Vehicle speed expressed in PID_UNITS_KMH
 */
#if defined(MODE1_VEHICLE_SPEED_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_VEHICLE_SPEED                                   (uint16_t)0x0D
#define MODE1_VEHICLE_SPEED_LEN                               (uint8_t)0x1
#define MODE1_VEHICLE_SPEED_UNITS                             (uint16_t)PID_UNITS_KMH
#endif

/**
 * Timing advance expressed in PID_UNITS_DEGREES
 */
#if defined(MODE1_TIMING_ADVANCE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_TIMING_ADVANCE                                  (uint16_t)0x0E
#define MODE1_TIMING_ADVANCE_LEN                              (uint8_t)0x1
#define MODE1_TIMING_ADVANCE_UNITS                            (uint16_t)PID_UNITS_DEGREES
#endif

/**
 * Intake air temperature expressed in PID_UNITS_CELCIUS
 */
#if defined(MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_INTAKE_AIR_TEMPERATURE                          (uint16_t)0x0F
#define MODE1_INTAKE_AIR_TEMPERATURE_LEN                      (uint8_t)0x1
#define MODE1_INTAKE_AIR_TEMPERATURE_UNITS                    (uint16_t)PID_UNITS_CELCIUS
#endif

/**
 * Absolute barometric pressure expressed in PID_UNITS_KPA
 */
#if defined(MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE                    (uint16_t)0x33
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_LEN                (uint8_t)0x1
#define MODE1_ABSOLUTE_BAROMETRIC_PRESSURE_UNITS              (uint16_t)PID_UNITS_KPA
#endif

/**
 * Relative accelerator pedal position expressed in PID_UNITS_PERCENT
 */
#if defined(MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION             (uint16_t)0x5A
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_LEN         (uint8_t)0x1
#define MODE1_RELATIVE_ACCELERATOR_PEDAL_POSITION_UNITS       (uint16_t)PID_UNITS_PERCENT
#endif

/**
 * Engine oil temperature expressed in PID_UNITS_CELCIUS
 */
#if defined(MODE1_ENGINE_OIL_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_ENGINE_OIL_TEMPERATURE                          (uint16_t)0x5C
#define MODE1_ENGINE_OIL_TEMPERATURE_LEN                      (uint8_t)0x1
#define MODE1_ENGINE_OIL_TEMPERATURE_UNITS                    (uint16_t)PID_UNITS_CELCIUS
#endif

/**
 * Turbocharger compressor inlet pressure expressed in PID_UNITS_KPA
 */
#if defined(MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE          (uint16_t)0x6F
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_LEN      (uint8_t)0x1
#define MODE1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE_UNITS    (uint16_t)PID_UNITS_KPA
#endif

/**
 * Intake air temperature expressed in PID_UNITS_CELCIUS
 */
#if defined(MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_INTAKE_AIR_TEMPERATURE                          (uint16_t)0xF40F
#define MODE22_INTAKE_AIR_TEMPERATURE_LEN                      (uint8_t)0x1
#define MODE22_INTAKE_AIR_TEMPERATURE_UNITS                    (uint16_t)PID_UNITS_CELCIUS
#endif

/**
 * Charge air temperature expressed in PID_UNITS_CELCIUS
 */
#if defined(MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_CHARGE_AIR_TEMPERATURE                          (uint16_t)0x0461
#define MODE22_CHARGE_AIR_TEMPERATURE_LEN                      (uint8_t)0x2
#define MODE22_CHARGE_AIR_TEMPERATURE_UNITS                    (uint16_t)PID_UNITS_CELCIUS
#endif

/**
 * Ambient air temperature expressed in PID_UNITS_CELCIUS
 */
#if defined(MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED) || !defined(LIMIT_PIDS)
#define MODE22_AMBIENT_AIR_TEMPERATURE                         (uint16_t)0x057D
#define MODE22_AMBIENT_AIR_TEMPERATURE_LEN                     (uint8_t)0x1
#define MODE22_AMBIENT_AIR_TEMPERATURE_UNITS                   (uint16_t)PID_UNITS_CELCIUS
#endif

/**
 * Gauge Brightness expressed in PID_UNITS_PERCENT
 */
#if defined(SNIFF_GAUGE_BRIGHTNESS_SUPPORTED) || !defined(LIMIT_PIDS)
#define SNIFF_GAUGE_BRIGHTNESS                                (uint16_t)0x01C8
#define SNIFF_GAUGE_BRIGHTNESS_LEN                            (uint8_t)0x0
#define SNIFF_GAUGE_BRIGHTNESS_UNITS                          (uint16_t)PID_UNITS_PERCENT
#endif

