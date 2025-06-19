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

#include "lib_pid.h"

PID_UNITS get_unit_by_string(const char *str)
{
    if (strcmp(str, PID_UNITS_RESERVED_DESC) == 0)   return PID_UNITS_RESERVED;
    if (strcmp(str, PID_UNITS_PERCENT_DESC) == 0)    return PID_UNITS_PERCENT;
    if (strcmp(str, PID_UNITS_CELSIUS_DESC) == 0)    return PID_UNITS_CELSIUS;
    if (strcmp(str, PID_UNITS_FAHRENHEIT_DESC) == 0) return PID_UNITS_FAHRENHEIT;
    if (strcmp(str, PID_UNITS_KPA_DESC) == 0)        return PID_UNITS_KPA;
    if (strcmp(str, PID_UNITS_PSI_DESC) == 0)        return PID_UNITS_PSI;
    if (strcmp(str, PID_UNITS_RPM_DESC) == 0)        return PID_UNITS_RPM;
    if (strcmp(str, PID_UNITS_KMH_DESC) == 0)        return PID_UNITS_KMH;
    if (strcmp(str, PID_UNITS_MPH_DESC) == 0)        return PID_UNITS_MPH;
    if (strcmp(str, PID_UNITS_GRAMSEC_DESC) == 0)    return PID_UNITS_GRAMSEC;
    if (strcmp(str, PID_UNITS_DEGREES_DESC) == 0)    return PID_UNITS_DEGREES;
    if (strcmp(str, PID_UNITS_VOLTS_DESC) == 0)      return PID_UNITS_VOLTS;
    if (strcmp(str, PID_UNITS_KM_DESC) == 0)         return PID_UNITS_KM;
    if (strcmp(str, PID_UNITS_MILES_DESC) == 0)      return PID_UNITS_MILES;
    if (strcmp(str, PID_UNITS_SECONDS_DESC) == 0)    return PID_UNITS_SECONDS;
    if (strcmp(str, PID_UNITS_RATIO_DESC) == 0)      return PID_UNITS_RATIO;
    if (strcmp(str, PID_UNITS_LPM_DESC) == 0)        return PID_UNITS_LPM;
    if (strcmp(str, PID_UNITS_BAR_DESC) == 0)        return PID_UNITS_BAR;
    if (strcmp(str, PID_UNITS_G_FORCE_DESC) == 0)    return PID_UNITS_G_FORCE;
    if (strcmp(str, PID_UNITS_NONE_DESC) == 0)       return PID_UNITS_NONE;
    return PID_UNITS_RESERVED; // Default fallback
}
