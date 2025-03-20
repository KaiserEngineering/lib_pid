/*
 * pid.h
 *
 *  Created on: Dec 18, 2019
 *      Author: mkaiser
 */

#ifndef PID_H_
#define PID_H_

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#ifdef LIMIT_PIDS
#include "pids_supported.h"
#endif

#include "pid.h"
#include "../ke_conf.h"

typedef enum _pid_compare {
	PID_NO_MATCH,
	PID_MATCH,
} PID_COMPARE, *PTR_PID_COMPARE;

typedef float (*obdii_conversion)(uint8_t A, uint8_t B, uint8_t C, uint8_t D);

#define PID_UNITS_PERCENT_LABEL "%"
#define PID_UNITS_CELSIUS_LABEL "°C"
#define PID_UNITS_FAHRENHEIT_LABEL "°F"
#define PID_UNITS_KPA_LABEL "kPa"
#define PID_UNITS_PSI_LABEL "psi"
#define PID_UNITS_RPM_LABEL ""
#define PID_UNITS_KMH_LABEL "kmh"
#define PID_UNITS_MPH_LABEL "mph"
#define PID_UNITS_GRAMSEC_LABEL "g/s"
#define PID_UNITS_DEGREES_LABEL "°"
#define PID_UNITS_VOLTS_LABEL "V"
#define PID_UNITS_KM_LABEL "km"
#define PID_UNITS_MILES_LABEL "mi"
#define PID_UNITS_SECONDS_LABEL "s"
#define PID_UNITS_RATIO_LABEL ":1"
#define PID_UNITS_LPM_LABEL "lpm"
#define PID_UNITS_BAR_LABEL "bar"
#define PID_UNITS_G_FORCE_LABEL "G"
#define PID_UNITS_NONE_LABEL ""

typedef enum _pid_units {
    PID_UNITS_RESERVED,
    PID_UNITS_PERCENT,
    PID_UNITS_CELSIUS,
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
    PID_UNITS_LPM,
    PID_UNITS_BAR,
    PID_UNITS_G_FORCE,
    PID_UNITS_NONE,
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

#define LABEL_MAX_CHAR 16


typedef struct _pid_data {

	/* Label for the PID */
	char label[LABEL_MAX_CHAR];

	/* Unit label for the PID */
	char unit_label[LABEL_MAX_CHAR];

	/* Number of decimal places */
	uint8_t precision;

	/* The lower limit of what will/could be displayed */
	volatile float lower_limit;

	/* The upper limit of what will/could be displayed */
	volatile float upper_limit;

    /* Header of the PID */
    volatile uint16_t header;

	/* Mode of the PID being streamed */
	volatile uint8_t mode;

	/* PID being streamed */
	volatile uint16_t pid;

	/* Units of the PID @PID_UNITS */
	volatile PID_UNITS pid_unit;

	/* Units the PID was reported in @PID_UNITS */
	volatile PID_UNITS base_unit;

	/* Last captured value of the PID */
	volatile float pid_value;

	/* min value of the PID for this session */
	volatile float pid_min;

	/* max value of the PID for this session */
	volatile float pid_max;

	/* When the data was acquired */
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
uint16_t get_pid_header( uint8_t mode, uint16_t pid );

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
