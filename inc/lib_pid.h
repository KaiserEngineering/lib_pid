/*
 * pid.h
 *
 *  Created on: Dec 18, 2019
 *      Author: mkaiser
 */

#ifndef PID_H_
#define PID_H_

#if TEST
#include <var.h>
#endif
#include <stdio.h>
#include <string.h>
#ifdef LIMIT_PIDS
#include <pids_supported.h>
#else
#define MODE1_CALCULATED_ENGINE_LOAD_VALUE_SUPPORTED
#define MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED
#define MODE1_FUEL_PRESSURE_SUPPORTED
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED
#define MODE1_ENGINE_RPM_SUPPORTED
#define MODE1_VEHICLE_SPEED_SUPPORTED
#define MODE1_TIMING_ADVANCE_SUPPORTED
#define MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED
#define MODE1_MAF_AIR_FLOW_RATE_SUPPORTED
#define MODE1_AMBIENT_AIR_TEMPERATURE_SUPPORTED
#define MODE1_BAROMETRIC_PRESSURE_SUPPORTED
#define MODE1_ABSOLUTE_LOAD_VALUE_SUPPORTED
#define MODE1_THROTTLE_POSITION_SUPPORTED
#define MODE1_REL_ACCELERATOR_PEDAL_POS_SUPPORTED
#define MODE1_ENGINE_OIL_TEMPERATURE_SUPPORTED
#define MODE1_TURBO_INLET_PRESSURE_SUPPORTED
#define MODE1_TRANS_ACTUAL_GEAR_SUPPORTED
#define MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED
#define MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED
#define MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED
#define DECODE_GAUGE_BRIGHTNESS_SUPPORTED
#define DECODE_CLUTCH_POSITION_SUPPORTED
#endif


typedef enum _pid_compare {
	PID_NO_MATCH,
	PID_MATCH,
} PID_COMPARE, *PTR_PID_COMPARE;

typedef float (*obdii_conversion)(uint8_t A, uint8_t B, uint8_t C, uint8_t D);

typedef enum _pid_units {
    PID_UNITS_NOT_APPLICABLE,
    PID_UNITS_PERCENT,
    PID_UNITS_CELCIUS,
    PID_UNITS_FAHRENHEIT,
    PID_UNITS_KPA,
    PID_UNITS_PSI,
    PID_UNITS_RPM,
    PID_UNITS_KMH,
    PID_UNITS_MPH,
    PID_UNITS_GRAMSEC,
    PID_UNITS_DEGREES,
    PID_UNITS_VOLTS,
    PID_UNITS_KM,
    PID_UNITS_MILES,
    PID_UNITS_SECONDS,
    PID_UNITS_RATIO,
    PID_UNITS_LPH,
} PID_UNITS, *PPID_UNITS;

#define PID_UNASSIGNED             0x00

/* Standard OBD-II request */
#ifdef USE_LIB_OBDII
#define PID_ASSIGNED_TO_OBDII      0x01
#endif

/* Decode CAN bus data stream */
#ifdef USE_LIB_CAN_BUS_DECODE
#define PID_ASSIGNED_TO_CAN_DECODE 0x02
#endif


typedef struct _pid_data {

	/* Mode of the PID being streamed */
	volatile uint8_t mode;

	/* PID being streamed */
	volatile uint16_t pid;

	/* Units of the PID @PID_UNITS */
	volatile uint8_t pid_unit;

	/* Units the PID was reported in @PID_UNITS */
	volatile uint8_t base_unit;

	/* Last captured value of the PID */
	volatile float pid_value;

	/* When the data was aquired */
	volatile uint32_t timestamp;

	/* How the data was acquired */
	volatile uint8_t acquisition_type;

	/* Number of attached devices */
	volatile uint8_t devices;

} PID_DATA, *PTR_PID_DATA;


typedef PTR_PID_DATA (*request_pid_data)( PTR_PID_DATA pid );


typedef struct _obdii_pid {

    uint16_t pid;
    uint8_t data_bytes;
    PID_UNITS units;
    obdii_conversion formula;

} OBDII_PID, *POBDII_PID;

PID_UNITS get_pid_base_unit( uint8_t mode, uint16_t PID );

#define A 0
#define B 1
#define C 2
#define D 3

#define MODE1                                           (uint8_t)0x01    // Show current data
#define MODE2                                           (uint8_t)0x02    // Show freeze frame data
#define MODE22                                          (uint8_t)0x22    // Enhanced data
#define DECODE                                          (uint8_t)0xDE    // Data extracted from sniffing the CAN bus

/**
 * Calculated engine load value expressed in Percent.
 */
#ifdef MODE1_CALCULATED_ENGINE_LOAD_VALUE_SUPPORTED
#define MODE1_CALCULATED_ENGINE_LOAD_VALUE              (uint16_t)0x04
#define MODE1_CALCULATED_ENGINE_LOAD_VALUE_LEN          (uint8_t)0x1
#define MODE1_CALCULATED_ENGINE_LOAD_UNITS              (uint8_t)PID_UNITS_PERCENT
#endif

/**
 * Engine coolant temperature expressed in Celcius.
 */
#ifdef MODE1_ENGINE_COOLANT_TEMPERATURE_SUPPORTED
#define MODE1_ENGINE_COOLANT_TEMPERATURE                (uint16_t)0x05
#define MODE1_ENGINE_COOLANT_TEMPERATURE_LEN            (uint8_t)0x1
#define MODE1_ENGINE_COOLANT_TEMPERATURE_UNITS          (uint8_t)PID_UNITS_CELCIUS
#endif

/**
 * Fuel pressure expressed in kPa.
 */
#ifdef MODE1_FUEL_PRESSURE_SUPPORTED
#define MODE1_FUEL_PRESSURE                             (uint16_t)0x0A
#define MODE1_FUEL_PRESSURE_LEN                         (uint8_t)0x1
#define MODE1_FUEL_PRESSURE_UNITS                       (uint8_t)PID_UNITS_KPA
#endif

/**
 * Intake manifold absolute pressure expressed in kPa.
 */
#ifdef MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_SUPPORTED
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE         (uint16_t)0x0B
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LEN     (uint8_t)0x1
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_UNITS   (uint8_t)PID_UNITS_KPA
#endif

/**
 * Engine Speed expressed in Rotations Per Minute (RPM).
 */
#ifdef MODE1_ENGINE_RPM_SUPPORTED
#define MODE1_ENGINE_RPM                                (uint16_t)0x0C
#define MODE1_ENGINE_RPM_LEN                            (uint8_t)0x2
#define MODE1_ENGINE_RPM_UNITS                          (uint8_t)PID_UNITS_RPM
#endif

/**
 * Vehicle speed expressed in Kilometers per Hour (KM/H).
 */
#ifdef MODE1_VEHICLE_SPEED_SUPPORTED
#define MODE1_VEHICLE_SPEED                             (uint16_t)0x0D
#define MODE1_VEHICLE_SPEED_LEN                         (uint8_t)0x1
#define MODE1_VEHICLE_SPEED_UNITS                       (uint8_t)PID_UNITS_KMH
#endif

/**
 * Timing advance expressed in Degrees.
 */
#ifdef MODE1_TIMING_ADVANCE_SUPPORTED
#define MODE1_TIMING_ADVANCE                            (uint16_t)0x0E
#define MODE1_TIMING_ADVANCE_LEN                        (uint8_t)0x1
#define MODE1_TIMING_ADVANCE_UNITS                      (uint8_t)PID_UNITS_DEGREES
#endif

/**
 * Intake air temperature expressed in Celcius.
 */
#ifdef MODE1_INTAKE_AIR_TEMPERATURE_SUPPORTED
#define MODE1_INTAKE_AIR_TEMPERATURE                    (uint16_t)0x0F
#define MODE1_INTAKE_AIR_TEMPERATURE_LEN                (uint8_t)0x1
#define MODE1_INTAKE_AIR_TEMPERATURE_UNITS              (uint8_t)PID_UNITS_CELCIUS
#endif

/**
 * Mass Air Flow (MAF) air flow rate expressed in Grams per Second (g/s).
 */
#ifdef MODE1_MAF_AIR_FLOW_RATE_SUPPORTED
#define MODE1_MAF_AIR_FLOW_RATE                         (uint16_t)0x10
#define MODE1_MAF_AIR_FLOW_RATE_LEN                     (uint8_t)0x2
#define MODE1_MAF_AIR_FLOW_RATE_UNITS                   (uint8_t)PID_UNITS_GRAMSEC
#endif

/**
 * Throttle position expressed in Percent.
 */
#ifdef MODE1_THROTTLE_POSITION_SUPPORTED
#define MODE1_THROTTLE_POSITION                         (uint16_t)0x11
#define MODE1_THROTTLE_POSITION_LEN                     (uint8_t)0x1
#define MODE1_THROTTLE_POSITION_UNITS                   (uint8_t)PID_UNITS_PERCENT
#endif

/**
 * Barometric pressure expressed in kPa.
 */
#ifdef MODE1_BAROMETRIC_PRESSURE_SUPPORTED
#define MODE1_BAROMETRIC_PRESSURE                       (uint16_t)0x33
#define MODE1_BAROMETRIC_PRESSURE_LEN                   (uint8_t)0x1
#define MODE1_BAROMETRIC_PRESSURE_UNITS                 (uint8_t)PID_UNITS_KPA
#endif

/**
 * Absolute load value expressed in Percent.
 */
#ifdef MODE1_ABSOLUTE_LOAD_VALUE_SUPPORTED
#define MODE1_ABSOLUTE_LOAD_VALUE                       (uint16_t)0x43
#define MODE1_ABSOLUTE_LOAD_VALUE_LEN                   (uint8_t)0x2
#define MODE1_ABSOLUTE_LOAD_VALUE_UNITS                 (uint8_t)PID_UNITS_PERCENT
#endif

/**
 * Ambient air temperature expressed in Celcius.
 */
#ifdef MODE1_AMBIENT_AIR_TEMPERATURE_SUPPORTED
#define MODE1_AMBIENT_AIR_TEMPERATURE                   (uint16_t)0x46
#define MODE1_AMBIENT_AIR_TEMPERATURE_LEN               (uint8_t)0x1
#define MODE1_AMBIENT_AIR_TEMPERATURE_UNITS             (uint8_t)PID_UNITS_CELCIUS
#endif

/**
 * Relative accelerator pedal position expressed in Percent.
 */
#ifdef MODE1_REL_ACCELERATOR_PEDAL_POS_SUPPORTED
#define MODE1_REL_ACCELERATOR_PEDAL_POS                 (uint16_t)0x5A
#define MODE1_REL_ACCELERATOR_PEDAL_POS_LEN             (uint8_t)0x1
#define MODE1_REL_ACCELERATOR_PEDAL_POS_UNITS           (uint8_t)PID_UNITS_PERCENT
#endif

/**
 * Engine oil temperature expressed in Celcius, this can only be sniffed from
 * the CAN bus as of right now.
 */
#ifdef MODE1_ENGINE_OIL_TEMPERATURE_SUPPORTED
#define MODE1_ENGINE_OIL_TEMPERATURE                    (uint16_t)0x5C
#define MODE1_ENGINE_OIL_TEMPERATURE_LEN                (uint8_t)0x1
#define MODE1_ENGINE_OIL_TEMPERATURE_UNITS              (uint8_t)PID_UNITS_CELCIUS
#endif

/**
 * Turbocharger compressor inlet pressure expressed in kPa, this can only be
 * sniffed from the CAN bus as of right now.
 */
#ifdef MODE1_TURBO_INLET_PRESSURE_SUPPORTED
#define MODE1_TURBO_INLET_PRESSURE                      (uint16_t)0x6F
#define MODE1_TURBO_INLET_PRESSURE_LEN                  (uint8_t)0x3
#define MODE1_TURBO_INLET_PRESSURE_UNITS                (uint8_t)PID_UNITS_KPA
#endif

/**
 * Transmission Actual Gear , this can only be sniffed from the CAN bus as
 * of right now.
 */
#ifdef MODE1_TRANS_ACTUAL_GEAR_SUPPORTED
#define MODE1_TRANS_ACTUAL_GEAR                         (uint16_t)0x6F
#define MODE1_TRANS_ACTUAL_GEAR_LEN                     (uint8_t)0x4
#define MODE1_TRANS_ACTUAL_GEAR_UNITS                   (uint8_t)PID_UNITS_NOT_APPLICABLE
#endif

/**
 * Intake air temperature expressed in Celcius.
 */
#ifdef MODE22_INTAKE_AIR_TEMPERATURE_SUPPORTED
#define MODE22_INTAKE_AIR_TEMPERATURE                   (uint16_t)0xF40F
#define MODE22_INTAKE_AIR_TEMPERATURE_LEN               (uint8_t)0x1
#define MODE22_INTAKE_AIR_TEMPERATURE_UNITS             (uint8_t)PID_UNITS_CELCIUS
#endif

/**
 * Charge air temperature expressed in Celcius.
 */
#ifdef MODE22_CHARGE_AIR_TEMPERATURE_SUPPORTED
#define MODE22_CHARGE_AIR_TEMPERATURE                   (uint16_t)0x0461
#define MODE22_CHARGE_AIR_TEMPERATURE_LEN               (uint8_t)0x2
#define MODE22_CHARGE_AIR_TEMPERATURE_UNITS             (uint8_t)PID_UNITS_CELCIUS
#endif

/**
 * Ambient Air Temperature
 */
#ifdef MODE22_AMBIENT_AIR_TEMPERATURE_SUPPORTED
#define MODE22_AMBIENT_AIR_TEMPERATURE                  (uint16_t)0x057D
#define MODE22_AMBIENT_AIR_TEMPERATURE_LEN              (uint8_t)0x1
#define MODE22_AMBIENT_AIR_TEMPERATURE_UNITS            (uint8_t)PID_UNITS_CELCIUS
#endif

/**
 * Gauge Brightness expressed in percent, this can only be sniffed from the CAN bus
 * as of right now.
 */
#ifdef DECODE_GAUGE_BRIGHTNESS_SUPPORTED
#define DECODE_GAUGE_BRIGHTNESS                         (uint16_t)0x01C8
#define DECODE_GAUGE_BRIGHTNESS_LEN                     (uint8_t)0x0
#define DECODE_GAUGE_BRIGHTNESS_UNITS                   (uint8_t)PID_UNITS_PERCENT
#endif

/**
 * Clutch position expressed in percent, this can only be sniffed from the CAN bus
 * as of right now.
 */
#ifdef DECODE_CLUTCH_POSITION_SUPPORTED
#define DECODE_CLUTCH_POSITION                          (uint16_t)0x1138
#define DECODE_CLUTCH_POSITION_LEN                      (uint8_t)0x0
#define DECODE_CLUTCH_POSITION_UNITS                    (uint8_t)PID_UNITS_PERCENT
#endif




#endif /* PID_H_ */
