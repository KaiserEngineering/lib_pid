#include "lib_pid.h"
#include "cjson_shared.h"

void lib_pid_clear_PID( PTR_PID_DATA ptr_pid )
{
    ptr_pid->pid_initialized = false;
    ptr_pid->pid_uuid = PID_UNASSIGNED;
    ptr_pid->pid_unit = PID_UNITS_RESERVED;
    ptr_pid->base_unit = PID_UNITS_RESERVED;
    ptr_pid->acquisition_type = PID_UNASSIGNED;
    ptr_pid->pid_value = 99999;
    ptr_pid->pid_min = INIT_MIN;
    ptr_pid->pid_max = INIT_MAX;
    ptr_pid->timestamp = 0;
    ptr_pid->devices = 0;
    ptr_pid->num_activated = 0;
}

static bool is_pid_initialized( PTR_PID_DATA pid )
{
    return (pid != NULL) && pid->pid_initialized;
}

uint8_t get_mode_by_uuid( uint32_t pid_uuid )
{
	return (pid_uuid >> 16) & 0xFF;
}

uint16_t get_pid_by_uuid( uint32_t pid_uuid )
{
	return pid_uuid & 0xFFFF;
}

bool load_pid_data(PTR_PID_DATA pid)
{
    // Verify the pid_uuid is valid
    if (pid->pid_uuid == PID_UNASSIGNED)
        return false;

    // Load the base unit first
    pid->base_unit = get_pid_base_unit(pid->pid_uuid);

    // Load the list of supported units
    pid->num_supported_units = get_pid_units(pid->pid_uuid, &pid->supported_units);

    // If the pid_unit is not valid or not supported, fall back to base_unit
    uint8_t unit_supported = 0;
    if (pid->pid_unit != PID_UNITS_RESERVED) {
        for (uint8_t i = 0; i < pid->num_supported_units; i++) {
            if (pid->pid_unit == pid->supported_units[i]) {
                unit_supported = 1;
                break;
            }
        }
    }

    if (!unit_supported) {
        pid->pid_unit = pid->base_unit;
    }

    // Load the labels
    get_pid_label(pid->pid_uuid, pid->label);
    get_unit_label(pid->pid_unit, pid->unit_label);

    // Load the description
    get_pid_desc(pid->pid_uuid, pid->desc);

    // Get the value limits
    pid->lower_limit = get_pid_lower_limit(pid->pid_uuid, pid->pid_unit);
    pid->upper_limit = get_pid_upper_limit(pid->pid_uuid, pid->pid_unit);
    pid->precision = get_pid_precision(pid->pid_uuid, pid->pid_unit);

    pid->pid_initialized = true;

    return true;
}

void update_pid_data( PTR_PID_DATA pid, float value, uint32_t timestamp )
{
    if (!is_pid_initialized(pid))
    {
        if (!load_pid_data(pid)) {
            // Failed to load PID data, mark as uninitialized and return
            pid->pid_initialized = false;
            return;
        }
    }

    pid->timestamp = timestamp;
    pid->pid_value = value;

    convert_units( pid->base_unit, pid->pid_unit, &pid->pid_value );

    // Log min/max if this is not the first data point
	if( pid->timestamp > 0 ) {
		if( pid->pid_value > pid->pid_max ) {
		    pid->pid_max = pid->pid_value;
		}
		if( pid->pid_value < pid->pid_min ) {
		    pid->pid_min = pid->pid_value;
		}
    }
}

uint32_t pid_list_to_json(char *buffer, uint32_t buffer_size) {
    if ((buffer == NULL) || (buffer_size == 0U) || !cjson_shared_acquire())
        return 0;

    cJSON *root = cJSON_CreateArray();  // Root is now an array

    if (!root) {
        cjson_shared_release();
        return 0;
    }

    uint32_t pid_count = get_pid_list_size();
    PID_DATA pid_json;

    for (uint32_t i = 0; i < pid_count; i++) {
        // Load the base PID data
        pid_json.pid_uuid = get_pid_from_list(i);
        pid_json.pid_unit = get_pid_base_unit(pid_json.pid_uuid);
        load_pid_data(&pid_json);

        // Create object for this PID
        cJSON *entry = cJSON_CreateObject();
        if (!entry) continue;

        cJSON_AddStringToObject(entry, "desc", pid_json.desc);
        cJSON_AddStringToObject(entry, "label", pid_json.label);

        // Arrays
        cJSON *units    = cJSON_CreateArray();
        cJSON *min      = cJSON_CreateArray();
        cJSON *max      = cJSON_CreateArray();
        cJSON *decimals = cJSON_CreateArray();

        // Get all supported units
        pid_json.num_supported_units = get_pid_units(pid_json.pid_uuid, &pid_json.supported_units);

        double rounded_nun = 0;
        char tmp_str[32] = {0};

        for (int u = 0; u < pid_json.num_supported_units; u++) {
            pid_json.pid_unit = pid_json.supported_units[u];
            load_pid_data(&pid_json);

            get_unit_desc(pid_json.pid_unit, tmp_str);
            cJSON_AddItemToArray(units, cJSON_CreateString(tmp_str));
            rounded_nun = round(pid_json.lower_limit * 1000.0) / 1000.0;
            cJSON_AddItemToArray(min, cJSON_CreateNumber(rounded_nun));
            rounded_nun = round(pid_json.upper_limit * 1000.0) / 1000.0;
            cJSON_AddItemToArray(max, cJSON_CreateNumber(rounded_nun));
            cJSON_AddItemToArray(decimals, cJSON_CreateNumber(pid_json.precision));
        }

        cJSON_AddItemToObject(entry, "units",    units);
        cJSON_AddItemToObject(entry, "min",      min);
        cJSON_AddItemToObject(entry, "max",      max);
        cJSON_AddItemToObject(entry, "decimals", decimals);

        cJSON_AddItemToArray(root, entry);
    }

    uint32_t actual_len = 0;

    if (cJSON_PrintPreallocated(root, buffer, (int)buffer_size, false)) {
        actual_len = (uint32_t)strlen(buffer);
    }

    cJSON_Delete(root);
    cjson_shared_release();
    return actual_len;  // 0 if failed
}
