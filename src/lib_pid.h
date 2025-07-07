/*
 * pid.h
 *
 *  Created on: Dec 18, 2019
 *      Author: mkaiser
 */

#ifndef PID_H_
#define PID_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "cJSON.h"
#include <stdlib.h>
#include <math.h>
#ifdef LIMIT_PIDS
#include "pids_supported.h"
#endif

#include "pid.h"
#ifdef USE_KE_CONF
#include "../ke_conf.h"
#endif

typedef enum _pid_compare {
	PID_NO_MATCH,
	PID_MATCH,
} PID_COMPARE, *PTR_PID_COMPARE;

#define LIMIT_ERROR -5125.594 // Random number to indicate error
#define INIT_MIN 99999
#define INIT_MAX -99999

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

#define PID_UNITS_RESERVED_DESC "Reserved"
#define PID_UNITS_PERCENT_DESC "Percent"
#define PID_UNITS_CELSIUS_DESC "Celsius"
#define PID_UNITS_FAHRENHEIT_DESC "Fahrenheit"
#define PID_UNITS_KPA_DESC "kPa"
#define PID_UNITS_PSI_DESC "psi"
#define PID_UNITS_RPM_DESC "rpm"
#define PID_UNITS_KMH_DESC "km/h"
#define PID_UNITS_MPH_DESC "mph"
#define PID_UNITS_GRAMSEC_DESC "Grams/sec"
#define PID_UNITS_DEGREES_DESC "Degrees"
#define PID_UNITS_VOLTS_DESC "Volts"
#define PID_UNITS_KM_DESC "Kilometers"
#define PID_UNITS_MILES_DESC "Miles"
#define PID_UNITS_SECONDS_DESC "Seconds"
#define PID_UNITS_RATIO_DESC "Ratio"
#define PID_UNITS_LPM_DESC "Liters/min"
#define PID_UNITS_BAR_DESC "Bar"
#define PID_UNITS_G_FORCE_DESC "G-Force"
#define PID_UNITS_NONE_DESC "None"

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
#define DESC_MAX_CHAR 64


typedef struct _pid_data {

	/* Label for the PID */
	char label[LABEL_MAX_CHAR];

	/* Description for the PID */
	char desc[DESC_MAX_CHAR];

	/* Unit label for the PID */
	char unit_label[LABEL_MAX_CHAR];

	/* Number of decimal places to display */
	uint8_t precision;

	/* The lower limit of what will/could be displayed */
	float lower_limit;

	/* The upper limit of what will/could be displayed */
	float upper_limit;

    /* Header of the PID */
    uint16_t header;

	/* Mode of the PID UUID being streamed */
	uint32_t pid_uuid;

	/* Units of the PID that should be displayed */
	PID_UNITS pid_unit;

	/* Units the PID was reported in from the vehicle */
	PID_UNITS base_unit;

	/* List of Supported units for particular PID */
	const PID_UNITS *supported_units;

	/* Number of supported units @PID_UNITS */
	uint8_t num_supported_units;

	/* Most recent captured value of the PID */
	float pid_value;

	/* Min value of the PID for this session */
	float pid_min;

	/* Max value of the PID for this session */
	float pid_max;

	/* When the data was acquired */
	uint32_t timestamp;

	/* How the data was acquired */
	uint8_t acquisition_type;

	/* Number of attached devices */
	uint8_t devices;

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
float get_pid_value( uint32_t pid_uuid, uint8_t data[] );
uint8_t lookup_payload_length( uint32_t pid_uuid );
PID_UNITS get_pid_base_unit( uint32_t pid_uuid );
uint16_t get_pid_header( uint32_t pid_uuid );
uint8_t get_pid_label( uint32_t pid_uuid, char* label );
uint8_t get_pid_desc( uint32_t pid_uuid, char* desc );
uint32_t get_pid_by_string(const char *str);
uint8_t get_unit_label( PID_UNITS unit, char* label );
uint8_t get_unit_desc( PID_UNITS unit, char* label );
PID_UNITS get_unit_by_string(const char *str);
uint8_t get_mode_by_uuid( uint32_t pid_uuid );
uint16_t get_pid_by_uuid( uint32_t pid_uuid );
uint8_t load_pid_data( PTR_PID_DATA pid );
float get_pid_lower_limit( uint32_t pid_uuid, PID_UNITS unit );
float get_pid_upper_limit( uint32_t pid_uuid, PID_UNITS unit );
float get_pid_precision( uint32_t pid_uuid, PID_UNITS unit );
uint8_t get_pid_units( uint32_t pid_uuid, const PID_UNITS **units );
uint32_t get_pid_from_list(uint32_t idx);
uint32_t get_pid_list_size(void);
uint32_t pid_list_to_json(char *buffer, uint32_t buffer_size);

#define OBDII_BYTEA 0
#define OBDII_BYTEB 1
#define OBDII_BYTEC 2
#define OBDII_BYTED 3

#define MODE1                                           (uint8_t)0x01    // Show current data
#define MODE2                                           (uint8_t)0x02    // Show freeze frame data
#define MODE22                                          (uint8_t)0x22    // Enhanced data
#define SNIFF                                           (uint8_t)0xDE    // Data extracted from sniffing the CAN bus
#define CALC1                                           (uint8_t)0xC1    // Data calculated using other PIDs

#endif /* PID_H_ */
