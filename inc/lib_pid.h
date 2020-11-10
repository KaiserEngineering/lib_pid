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

typedef enum _pid_compare {
	PID_NO_MATCH,
	PID_MATCH,
} PID_COMPARE, *PTR_PID_COMPARE;

#define USE_LIB_OBDII          1
#define USE_LIB_CAN_BUS_DECODE 1

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

#define MODE1_CALCULATED_ENGINE_LOAD_VALUE              (uint16_t)0x04   // Calculated engine load value
#define MODE1_CALCULATED_ENGINE_LOAD_VALUE_LEN          (uint8_t)0x1     // Calculated engine load value
#define MODE1_CALCULATED_ENGINE_LOAD_UNITS              PID_UNITS_PERCENT

#define MODE1_ENGINE_COOLANT_TEMPERATURE                (uint16_t)0x05   // Engine coolant temperature
#define MODE1_ENGINE_COOLANT_TEMPERATURE_LEN            (uint8_t)0x1     // Engine coolant temperature
#define MODE1_ENGINE_COOLANT_TEMPERATURE_UNITS          PID_UNITS_CELCIUS

#define MODE1_FUEL_PRESSURE                             (uint16_t)0x0A   // Fuel pressure
#define MODE1_FUEL_PRESSURE_LEN                         (uint8_t)0x1     // Fuel pressure
#define MODE1_FUEL_PRESSURE_UNITS                       PID_UNITS_KPA

#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE         (uint16_t)0x0B   // Intake manifold absolute pressure
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LEN     (uint8_t)0x1     // Intake manifold absolute pressure
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_UNITS   PID_UNITS_KPA

#define MODE1_ENGINE_RPM                                (uint16_t)0x0C   // Engine RPM
#define MODE1_ENGINE_RPM_LEN                            (uint8_t)0x2     // Engine RPM
#define MODE1_ENGINE_RPM_UNITS                          PID_UNITS_RPM

#define MODE1_VEHICLE_SPEED                             (uint16_t)0x0D   // Vehicle speed
#define MODE1_VEHICLE_SPEED_LEN                         (uint8_t)0x1     // Vehicle speed
#define MODE1_VEHICLE_SPEED_UNITS                       PID_UNITS_KMH

#define MODE1_TIMING_ADVANCE                            (uint16_t)0x0E   // Timing advance
#define MODE1_TIMING_ADVANCE_LEN                        (uint8_t)0x1     // Timing advance
#define MODE1_TIMING_ADVANCE_UNITS                      PID_UNITS_DEGREES

#define MODE1_INTAKE_AIR_TEMPERATURE                    (uint16_t)0x0F   // Intake air temperature
#define MODE1_INTAKE_AIR_TEMPERATURE_LEN                (uint8_t)0x1     // Intake air temperature
#define MODE1_INTAKE_AIR_TEMPERATURE_UNITS              PID_UNITS_CELCIUS

#define MODE1_MAF_AIR_FLOW_RATE                         (uint16_t)0x10   // MAF air flow rate
#define MODE1_MAF_AIR_FLOW_RATE_LEN                     (uint8_t)0x2     // MAF air flow rate
#define MODE1_MAF_AIR_FLOW_RATE_UNITS                   PID_UNITS_GRAMSEC

#define MODE1_THROTTLE_POSITION                         (uint16_t)0x11   // Throttle position
#define MODE1_THROTTLE_POSITION_LEN                     (uint8_t)0x1     // Throttle position
#define MODE1_THROTTLE_POSITION_UNITS                   PID_UNITS_PERCENT

#define MODE1_BAROMETRIC_PRESSURE                       (uint16_t)0x33   // Barometric pressure
#define MODE1_BAROMETRIC_PRESSURE_LEN                   (uint8_t)0x1     // Barometric pressure
#define MODE1_BAROMETRIC_PRESSURE_UNITS                 PID_UNITS_KPA

#define MODE1_ABSOLUTE_LOAD_VALUE                       (uint16_t)0x43   // Absolute load value
#define MODE1_ABSOLUTE_LOAD_VALUE_LEN                   (uint8_t)0x2     // Absolute load value
#define MODE1_ABSOLUTE_LOAD_VALUE_UNITS                 PID_UNITS_PERCENT

#define MODE1_AMBIENT_AIR_TEMPERATURE                   (uint16_t)0x46   // Ambient air temperature
#define MODE1_AMBIENT_AIR_TEMPERATURE_LEN               (uint8_t)0x1     // Ambient air temperature
#define MODE1_AMBIENT_AIR_TEMPERATURE_UNITS             PID_UNITS_CELCIUS

#define MODE1_REL_ACCELERATOR_PEDAL_POS                 (uint16_t)0x5A   // Relative accelerator pedal position
#define MODE1_REL_ACCELERATOR_PEDAL_POS_LEN             (uint8_t)0x1     // Relative accelerator pedal position
#define MODE1_REL_ACCELERATOR_PEDAL_POS_UNITS           PID_UNITS_PERCENT

#define MODE1_ENGINE_OIL_TEMPERATURE                    (uint16_t)0x5C   // Engine oil temperature
#define MODE1_ENGINE_OIL_TEMPERATURE_LEN                (uint8_t)0x1     // Engine oil temperature
#define MODE1_ENGINE_OIL_TEMPERATURE_UNITS               PID_UNITS_CELCIUS

#define MODE1_TURBO_INLET_PRESSURE                      (uint16_t)0x6F   // Turbocharger compressor inlet pressure
#define MODE1_TURBO_INLET_PRESSURE_LEN                  (uint8_t)0x3     // Turbocharger compressor inlet pressure
#define MODE1_TURBO_INLET_PRESSURE_UNITS                PID_UNITS_KPA

#define MODE22_INTAKE_AIR_TEMPERATURE                   (uint16_t)0xF40F // Intake air temperature
#define MODE22_INTAKE_AIR_TEMPERATURE_LEN               (uint8_t)0x1     // Intake air temperature
#define MODE22_INTAKE_AIR_TEMPERATURE_UNITS             PID_UNITS_CELCIUS

#define MODE22_CHARGE_AIR_TEMPERATURE                   (uint16_t)0x0461 // Charge air temperature
#define MODE22_CHARGE_AIR_TEMPERATURE_LEN               (uint8_t)0x2     // Charge air temperature
#define MODE22_CHARGE_AIR_TEMPERATURE_UNITS             PID_UNITS_CELCIUS


#endif /* PID_H_ */
