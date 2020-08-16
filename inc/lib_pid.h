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
    PID_UNITS_RESERVED,
    PID_UNITS_PERCENT,
    PID_UNITS_CELCIUS,
    PID_UNITS_KPA,
    PID_UNITS_RPM,
    PID_UNITS_KMH,
    PID_UNITS_GS
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


#define A 0
#define B 1
#define C 2
#define D 3

#define MODE01_OBDII                                    (uint8_t)01
#define MODE22_OBDII                                    (uint8_t)22

#define MODE1_CALCULATED_ENGINE_LOAD_VALUE              (uint16_t)0x04  // Calculated engine load value
#define MODE1_CALCULATED_ENGINE_LOAD_VALUE_LEN          (uint8_t)0x1    // Calculated engine load value

#define MODE1_ENGINE_COOLANT_TEMPERATURE                (uint16_t)0x05  // Engine coolant temperature
#define MODE1_ENGINE_COOLANT_TEMPERATURE_LEN            (uint8_t)0x1    // Engine coolant temperature

#define MODE1_FUEL_PRESSURE                             (uint16_t)0x0A  // Fuel pressure
#define MODE1_FUEL_PRESSURE_LEN                         (uint8_t)0x1    // Fuel pressure

#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE         (uint16_t)0x0B  // Intake manifold absolute pressure
#define MODE1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE_LEN     (uint8_t)0x1    // Intake manifold absolute pressure

#define MODE1_ENGINE_RPM                                (uint16_t)0x0C  // Engine RPM
#define MODE1_ENGINE_RPM_LEN                            (uint8_t)0x2    // Engine RPM

#define MODE1_VEHICLE_SPEED                             (uint16_t)0x0D  // Vehicle speed
#define MODE1_VEHICLE_SPEED_LEN                         (uint8_t)0x1    // Vehicle speed

#define MODE1_TIMING_ADVANCE                            (uint16_t)0x0E  // Timing advance
#define MODE1_TIMING_ADVANCE_LEN                        (uint8_t)0x1    // Timing advance

#define MODE1_INTAKE_AIR_TEMPERATURE                    (uint16_t)0x0F  // Intake air temperature
#define MODE1_INTAKE_AIR_TEMPERATURE_LEN                (uint8_t)0x1    // Intake air temperature

#define MODE1_MAF_AIR_FLOW_RATE                         (uint16_t)0x10  // MAF air flow rate
#define MODE1_MAF_AIR_FLOW_RATE_LEN                     (uint8_t)0x2    // MAF air flow rate

#define MODE1_THROTTLE_POSITION                         (uint16_t)0x11  // Throttle position
#define MODE1_THROTTLE_POSITION_LEN                     (uint8_t)0x1    // Throttle position

#define MODE1_BAROMETRIC_PRESSURE                       (uint16_t)0x33  // Barometric pressure
#define MODE1_BAROMETRIC_PRESSURE_LEN                   (uint8_t)0x1    // Barometric pressure

#define MODE1_ABSOLUTE_LOAD_VALUE                       (uint16_t)0x43  // Absolute load value
#define MODE1_ABSOLUTE_LOAD_VALUE_LEN                   (uint8_t)0x2    // Absolute load value

#define MODE1_AMBIENT_AIR_TEMPERATURE                   (uint16_t)0x46  // Ambient air temperature
#define MODE1_AMBIENT_AIR_TEMPERATURE_LEN               (uint8_t)0x1    // Ambient air temperature

#define MODE1_INTAKE_AIR_TEMPERATURE_SENSOR             (uint16_t)0x68  // Intake air temperature sensor
#define MODE1_INTAKE_AIR_TEMPERATURE_SENSOR_LEN         (uint8_t)0x7    // Intake air temperature sensor


#endif /* PID_H_ */
