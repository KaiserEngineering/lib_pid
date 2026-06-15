/*
 * pid_unit_conversion.c
 *
 *  Created on: Dec 29, 2019
 *      Author: mkaiser
 */

#include "lib_pid.h"

#define MPH_TO_KPH_FACTOR (float)1.6093440
#define KPA_TO_PSI_FACTOR (float)0.1450377
#define KPA_TO_BAR_FACTOR (float)0.01

static float fahrenheit_to_celsuis( float fahrenheit )
{
    return (fahrenheit - (float)32.00) * ((float)5.00 / (float)9.00);
}

static float celsuis_to_fahrenheit( float celsuis )
{
    return (celsuis * ((float)9.00 / (float)5.00)) + (float)32.00;
}

static float kmh_to_mph( float kmh )
{
    return kmh / MPH_TO_KPH_FACTOR;
}

static float mph_to_kmh( float mph )
{
    return mph * MPH_TO_KPH_FACTOR;
}

static float kpa_to_psi( float kpa )
{
    return kpa * KPA_TO_PSI_FACTOR;
}

static float kpa_to_bar( float kpa )
{
    return kpa * KPA_TO_BAR_FACTOR;
}

static float psi_to_kpa( float psi )
{
    return psi / KPA_TO_PSI_FACTOR;
}


PID_UNITS convert_units( PID_UNITS unitsIn, PID_UNITS unitsOut, float *value )
{
    if( (unitsIn == PID_UNITS_FAHRENHEIT) && (unitsOut == PID_UNITS_CELSIUS) ) {
        *value = fahrenheit_to_celsuis( *value );
        return unitsOut;
    }

    else if( (unitsIn == PID_UNITS_CELSIUS) && (unitsOut == PID_UNITS_FAHRENHEIT) ) {
        *value = celsuis_to_fahrenheit( *value );
        return unitsOut;
    }

    else if( (unitsIn == PID_UNITS_KMH) && (unitsOut == PID_UNITS_MPH) ) {
        *value = kmh_to_mph( *value );
        return unitsOut;
    }

    else if( (unitsIn == PID_UNITS_MPH) && (unitsOut == PID_UNITS_KMH) ) {
        *value = mph_to_kmh( *value );
        return unitsOut;
    }

    else if( (unitsIn == PID_UNITS_KPA) && (unitsOut == PID_UNITS_PSI) ) {
        *value = kpa_to_psi( *value );
        return unitsOut;
    }

    else if( (unitsIn == PID_UNITS_KPA) && (unitsOut == PID_UNITS_BAR) ) {
        *value = kpa_to_bar( *value );
        return unitsOut;
    }

    else if( (unitsIn == PID_UNITS_PSI) && (unitsOut == PID_UNITS_KPA) ) {
        *value = psi_to_kpa( *value );
        return unitsOut;
    }

    else if( (unitsIn == PID_UNITS_PSI) && (unitsOut == PID_UNITS_BAR) ) {
        *value = psi_to_kpa( *value );
        *value = kpa_to_bar( *value );
        return unitsOut;
    }

    else {
        return unitsIn;
    }
}

