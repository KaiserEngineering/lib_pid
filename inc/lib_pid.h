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
#endif

#include "pid.h"


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
    PID_UNITS_BAR,
} PID_UNITS, *PPID_UNITS;

#define PID_UNASSIGNED             0x00

/* Standard OBD-II request */
#ifdef USE_LIB_OBDII
#define PID_ASSIGNED_TO_OBDII      0x01
#endif

/* Decode CAN bus data stream */
#ifdef USE_LIB_CAN_BUS_SNIFFER
#define PID_ASSIGNED_TO_CAN_SNIFFER 0x02
#endif

#ifdef USE_LIB_VEHICLE_DATA
#define PID_ASSIGNED_TO_VEHICLE_DATA 0x03
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
typedef int (*clear_pid_request)( PTR_PID_DATA pid );


typedef struct _obdii_pid {

    uint16_t pid;
    uint8_t data_bytes;
    PID_UNITS units;
    obdii_conversion formula;

} OBDII_PID, *POBDII_PID;

void lib_pid_clear_PID( PTR_PID_DATA ptr_pid );
float get_pid_value( uint8_t mode, uint16_t pid, uint8_t data[] );
uint8_t lookup_payload_length( uint8_t mode, uint16_t PID );
PID_UNITS get_pid_base_unit( uint8_t mode, uint16_t PID );

#define A 0
#define B 1
#define C 2
#define D 3

#define MODE1                                           (uint8_t)0x01    // Show current data
#define MODE2                                           (uint8_t)0x02    // Show freeze frame data
#define MODE22                                          (uint8_t)0x22    // Enhanced data
#define SNIFF                                           (uint8_t)0xDE    // Data extracted from sniffing the CAN bus
#define CALC1                                           (uint8_t)0xC1    // Data calculated using other PIDs

#endif /* PID_H_ */
