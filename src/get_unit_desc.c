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

uint8_t get_unit_desc( PID_UNITS unit, char* label )
{
	for( uint8_t i = 0; i < LABEL_MAX_CHAR; i++ )
		label[i] = '\0';

	switch(unit)
	{
		case PID_UNITS_PERCENT:
			memcpy(label, PID_UNITS_PERCENT_DESC, sizeof(PID_UNITS_PERCENT_DESC));
			break;

		case PID_UNITS_CELSIUS:
			memcpy(label, PID_UNITS_CELSIUS_DESC, sizeof(PID_UNITS_CELSIUS_DESC));
			break;

		case PID_UNITS_FAHRENHEIT:
			memcpy(label, PID_UNITS_FAHRENHEIT_DESC, sizeof(PID_UNITS_FAHRENHEIT_DESC));
		break;

		case PID_UNITS_KPA:
			memcpy(label, PID_UNITS_KPA_DESC, sizeof(PID_UNITS_KPA_DESC));
			break;

		case PID_UNITS_PSI:
			memcpy(label, PID_UNITS_PSI_DESC, sizeof(PID_UNITS_PSI_DESC));
			break;

		case PID_UNITS_RPM:
			memcpy(label, PID_UNITS_RPM_DESC, sizeof(PID_UNITS_RPM_DESC));
			break;

		case PID_UNITS_KMH:
			memcpy(label, PID_UNITS_KMH_DESC, sizeof(PID_UNITS_KMH_DESC));
			break;

		case PID_UNITS_MPH:
			memcpy(label, PID_UNITS_MPH_DESC, sizeof(PID_UNITS_MPH_DESC));
			break;

		case PID_UNITS_GRAMSEC:
			memcpy(label, PID_UNITS_GRAMSEC_DESC, sizeof(PID_UNITS_GRAMSEC_DESC));
			break;

		case PID_UNITS_DEGREES:
			memcpy(label, PID_UNITS_DEGREES_DESC, sizeof(PID_UNITS_DEGREES_DESC));
			break;

		case PID_UNITS_VOLTS:
			memcpy(label, PID_UNITS_VOLTS_DESC, sizeof(PID_UNITS_VOLTS_DESC));
			break;

		case PID_UNITS_KM:
			memcpy(label, PID_UNITS_KM_DESC, sizeof(PID_UNITS_KM_DESC));
			break;

		case PID_UNITS_MILES:
			memcpy(label, PID_UNITS_MILES_DESC, sizeof(PID_UNITS_MILES_DESC));
			break;

		case PID_UNITS_SECONDS:
			memcpy(label, PID_UNITS_SECONDS_DESC, sizeof(PID_UNITS_SECONDS_DESC));
			break;

		case PID_UNITS_RATIO:
			memcpy(label, PID_UNITS_RATIO_DESC, sizeof(PID_UNITS_RATIO_DESC));
			break;

		case PID_UNITS_LPM:
			memcpy(label, PID_UNITS_LPM_DESC, sizeof(PID_UNITS_LPM_DESC));
			break;

		case PID_UNITS_BAR:
			memcpy(label, PID_UNITS_BAR_DESC, sizeof(PID_UNITS_BAR_DESC));
			break;

		case PID_UNITS_G_FORCE:
			memcpy(label, PID_UNITS_G_FORCE_DESC, sizeof(PID_UNITS_G_FORCE_DESC));
			break;

		case PID_UNITS_RESERVED:
		case PID_UNITS_NONE:
		default:
			memcpy(label, PID_UNITS_NONE_DESC, sizeof(PID_UNITS_NONE_DESC));
			break;
	}
	return 1;
}
