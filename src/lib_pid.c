#include "lib_pid.h"
#include "cjson_shared.h"

static PID_METADATA pid_metadata_table[PID_MAX_DEFINITIONS];
static uint32_t pid_metadata_count = 0;

static PPID_METADATA find_pid_metadata( uint32_t pid_uuid )
{
    for( uint32_t i = 0; i < pid_metadata_count; i++ )
    {
        if( pid_metadata_table[i].pid_uuid == pid_uuid )
            return &pid_metadata_table[i];
    }

    return NULL;
}

static int compare_pid_desc( uint32_t left_uuid, uint32_t right_uuid )
{
    PPID_METADATA left = find_pid_metadata(left_uuid);
    PPID_METADATA right = find_pid_metadata(right_uuid);
    int result = 0;

    if( (left == NULL) || (right == NULL) )
        return 0;

    result = strcmp(left->desc, right->desc);
    if( result != 0 )
        return result;

    result = strcmp(left->label, right->label);
    if( result != 0 )
        return result;

    if( left_uuid < right_uuid )
        return -1;
    if( left_uuid > right_uuid )
        return 1;

    return 0;
}

static void sort_pid_list_by_desc( uint32_t *pid_list, uint32_t pid_count )
{
    for( uint32_t i = 1; i < pid_count; i++ )
    {
        uint32_t current = pid_list[i];
        uint32_t j = i;

        while( (j > 0U) && (compare_pid_desc(current, pid_list[j - 1U]) < 0) )
        {
            pid_list[j] = pid_list[j - 1U];
            j--;
        }

        pid_list[j] = current;
    }
}

static bool parse_pid_u32_json( cJSON *item, uint32_t *value )
{
    char *end = NULL;

    if( (item == NULL) || (value == NULL) )
        return false;

    if( cJSON_IsNumber(item) )
    {
        *value = (uint32_t)item->valuedouble;
        return true;
    }

    if( cJSON_IsString(item) && (item->valuestring != NULL) )
    {
        *value = (uint32_t)strtoul(item->valuestring, &end, 16);
        return (end != item->valuestring) && ((end == NULL) || (*end == '\0'));
    }

    return false;
}

static bool parse_pid_mode_json( cJSON *item, uint8_t *mode )
{
    uint32_t value = 0;

    if( (item == NULL) || (mode == NULL) )
        return false;

    if( cJSON_IsString(item) && (item->valuestring != NULL) )
    {
        if( strcmp(item->valuestring, "MODE1") == 0 )
        {
            *mode = MODE1;
            return true;
        }
        if( strcmp(item->valuestring, "MODE2") == 0 )
        {
            *mode = MODE2;
            return true;
        }
        if( strcmp(item->valuestring, "MODE22") == 0 )
        {
            *mode = MODE22;
            return true;
        }
        if( strcmp(item->valuestring, "SNIFF") == 0 )
        {
            *mode = SNIFF;
            return true;
        }
        if( strcmp(item->valuestring, "CALC1") == 0 )
        {
            *mode = CALC1;
            return true;
        }
    }

    if( parse_pid_u32_json(item, &value) )
    {
        *mode = (uint8_t)value;
        return true;
    }

    return false;
}

static PID_UNITS parse_pid_unit_json( cJSON *item )
{
    const char *unit = NULL;

    if( !cJSON_IsString(item) || (item->valuestring == NULL) )
        return PID_UNITS_RESERVED;

    unit = item->valuestring;

    if( strcmp(unit, "RESERVED") == 0 ) return PID_UNITS_RESERVED;
    if( strcmp(unit, "PERCENT") == 0 ) return PID_UNITS_PERCENT;
    if( strcmp(unit, "CELSIUS") == 0 ) return PID_UNITS_CELSIUS;
    if( strcmp(unit, "FAHRENHEIT") == 0 ) return PID_UNITS_FAHRENHEIT;
    if( strcmp(unit, "KPA") == 0 ) return PID_UNITS_KPA;
    if( strcmp(unit, "PSI") == 0 ) return PID_UNITS_PSI;
    if( strcmp(unit, "RPM") == 0 ) return PID_UNITS_RPM;
    if( strcmp(unit, "KMH") == 0 ) return PID_UNITS_KMH;
    if( strcmp(unit, "MPH") == 0 ) return PID_UNITS_MPH;
    if( strcmp(unit, "GRAMSEC") == 0 ) return PID_UNITS_GRAMSEC;
    if( strcmp(unit, "DEGREES") == 0 ) return PID_UNITS_DEGREES;
    if( strcmp(unit, "VOLTS") == 0 ) return PID_UNITS_VOLTS;
    if( strcmp(unit, "KM") == 0 ) return PID_UNITS_KM;
    if( strcmp(unit, "MILES") == 0 ) return PID_UNITS_MILES;
    if( strcmp(unit, "SECONDS") == 0 ) return PID_UNITS_SECONDS;
    if( strcmp(unit, "RATIO") == 0 ) return PID_UNITS_RATIO;
    if( strcmp(unit, "LPM") == 0 ) return PID_UNITS_LPM;
    if( strcmp(unit, "BAR") == 0 ) return PID_UNITS_BAR;
    if( strcmp(unit, "G_FORCE") == 0 ) return PID_UNITS_G_FORCE;
    if( strcmp(unit, "G") == 0 ) return PID_UNITS_G_FORCE;
    if( strcmp(unit, "NONE") == 0 ) return PID_UNITS_NONE;
    if( strcmp(unit, "BOOLEAN") == 0 ) return PID_UNITS_NONE;

    return get_unit_by_string(unit);
}

static uint32_t pid_uuid_from_json( cJSON *entry )
{
    uint32_t pid_uuid = PID_UNASSIGNED;
    uint32_t pid = 0;
    uint8_t mode = 0;

    if( parse_pid_u32_json(cJSON_GetObjectItemCaseSensitive(entry, "pid_uuid"), &pid_uuid) )
        return pid_uuid;

    if( !parse_pid_mode_json(cJSON_GetObjectItemCaseSensitive(entry, "mode"), &mode) )
        return PID_UNASSIGNED;

    if( !parse_pid_u32_json(cJSON_GetObjectItemCaseSensitive(entry, "pid"), &pid) )
        return PID_UNASSIGNED;

    return PID_UUID(mode, pid);
}

static void copy_json_string( cJSON *item, char *dst, size_t dst_size )
{
    if( (dst == NULL) || (dst_size == 0U) )
        return;

    dst[0] = '\0';

    if( cJSON_IsString(item) && (item->valuestring != NULL) )
    {
        strncpy(dst, item->valuestring, dst_size - 1U);
        dst[dst_size - 1U] = '\0';
    }
}

void pid_metadata_clear_all(void)
{
    memset(pid_metadata_table, 0, sizeof(pid_metadata_table));
    pid_metadata_count = 0;
}

PID_METADATA_STATUS pid_metadata_register( const PID_METADATA *metadata )
{
    PPID_METADATA slot = NULL;

    if( (metadata == NULL) || (metadata->pid_uuid == PID_UNASSIGNED) || (metadata->num_supported_units == 0U) )
        return PID_METADATA_ERROR;

    slot = find_pid_metadata(metadata->pid_uuid);

    if( slot == NULL )
    {
        if( pid_metadata_count >= PID_MAX_DEFINITIONS )
            return PID_METADATA_ERROR;

        slot = &pid_metadata_table[pid_metadata_count++];
    }

    *slot = *metadata;
    return PID_METADATA_OK;
}

PID_METADATA_STATUS pid_metadata_register_json( cJSON *entry, uint16_t default_header )
{
    PID_METADATA metadata;
    cJSON *units = NULL;
    cJSON *min = NULL;
    cJSON *max = NULL;
    cJSON *decimals = NULL;
    cJSON *unit = NULL;
    uint32_t header = default_header;

    if( !cJSON_IsObject(entry) )
        return PID_METADATA_ERROR;

    memset(&metadata, 0, sizeof(metadata));
    metadata.pid_uuid = pid_uuid_from_json(entry);

    if( metadata.pid_uuid == PID_UNASSIGNED )
        return PID_METADATA_ERROR;

    if( parse_pid_u32_json(cJSON_GetObjectItemCaseSensitive(entry, "id"), &header) && (header > UINT16_MAX) )
        return PID_METADATA_ERROR;

    metadata.header = (uint16_t)header;
    copy_json_string(cJSON_GetObjectItemCaseSensitive(entry, "label"), metadata.label, sizeof(metadata.label));
    copy_json_string(cJSON_GetObjectItemCaseSensitive(entry, "desc"), metadata.desc, sizeof(metadata.desc));

    units = cJSON_GetObjectItemCaseSensitive(entry, "units");
    min = cJSON_GetObjectItemCaseSensitive(entry, "min");
    max = cJSON_GetObjectItemCaseSensitive(entry, "max");
    decimals = cJSON_GetObjectItemCaseSensitive(entry, "decimals");

    if( !cJSON_IsArray(units) )
        return PID_METADATA_ERROR;

    cJSON_ArrayForEach(unit, units)
    {
        uint8_t index = metadata.num_supported_units;

        if( index >= PID_MAX_SUPPORTED_UNITS )
            break;

        metadata.supported_units[index] = parse_pid_unit_json(unit);
        if( metadata.supported_units[index] == PID_UNITS_RESERVED )
            return PID_METADATA_ERROR;

        metadata.lower_limit[index] = cJSON_IsArray(min) && cJSON_IsNumber(cJSON_GetArrayItem(min, index)) ? (float)cJSON_GetArrayItem(min, index)->valuedouble : 0.0f;
        metadata.upper_limit[index] = cJSON_IsArray(max) && cJSON_IsNumber(cJSON_GetArrayItem(max, index)) ? (float)cJSON_GetArrayItem(max, index)->valuedouble : 0.0f;
        metadata.precision[index] = cJSON_IsArray(decimals) && cJSON_IsNumber(cJSON_GetArrayItem(decimals, index)) ? (uint8_t)cJSON_GetArrayItem(decimals, index)->valuedouble : 0U;
        metadata.num_supported_units++;
    }

    metadata.base_unit = metadata.supported_units[0];

    return pid_metadata_register(&metadata);
}

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

bool is_pid_supported( uint32_t pid_uuid )
{
    return find_pid_metadata(pid_uuid) != NULL;
}

PID_UNITS get_pid_base_unit( uint32_t pid_uuid )
{
    PPID_METADATA metadata = find_pid_metadata(pid_uuid);
    return (metadata != NULL) ? metadata->base_unit : PID_UNITS_RESERVED;
}

uint16_t get_pid_header( uint32_t pid_uuid )
{
    PPID_METADATA metadata = find_pid_metadata(pid_uuid);
    return (metadata != NULL) ? metadata->header : 0U;
}

uint8_t get_pid_label( uint32_t pid_uuid, char* label )
{
    PPID_METADATA metadata = find_pid_metadata(pid_uuid);

    if( label == NULL )
        return 0;

    label[0] = '\0';

    if( metadata == NULL )
        return 0;

    strncpy(label, metadata->label, LABEL_MAX_CHAR - 1U);
    label[LABEL_MAX_CHAR - 1U] = '\0';

    return 1;
}

uint8_t get_pid_desc( uint32_t pid_uuid, char* desc )
{
    PPID_METADATA metadata = find_pid_metadata(pid_uuid);

    if( desc == NULL )
        return 0;

    desc[0] = '\0';

    if( metadata == NULL )
        return 0;

    strncpy(desc, metadata->desc, DESC_MAX_CHAR - 1U);
    desc[DESC_MAX_CHAR - 1U] = '\0';

    return 1;
}

uint32_t get_pid_by_string(const char *str)
{
    if( str == NULL )
        return PID_UNASSIGNED;

    for( uint32_t i = 0; i < pid_metadata_count; i++ )
    {
        if( strcmp(str, pid_metadata_table[i].desc) == 0 )
            return pid_metadata_table[i].pid_uuid;
    }

    return PID_UNASSIGNED;
}

static uint8_t pid_unit_index( PPID_METADATA metadata, PID_UNITS unit )
{
    if( metadata == NULL )
        return UINT8_MAX;

    for( uint8_t i = 0; i < metadata->num_supported_units; i++ )
    {
        if( metadata->supported_units[i] == unit )
            return i;
    }

    return UINT8_MAX;
}

float get_pid_lower_limit( uint32_t pid_uuid, PID_UNITS unit )
{
    PPID_METADATA metadata = find_pid_metadata(pid_uuid);
    uint8_t index = pid_unit_index(metadata, unit);
    return (index != UINT8_MAX) ? metadata->lower_limit[index] : LIMIT_ERROR;
}

float get_pid_upper_limit( uint32_t pid_uuid, PID_UNITS unit )
{
    PPID_METADATA metadata = find_pid_metadata(pid_uuid);
    uint8_t index = pid_unit_index(metadata, unit);
    return (index != UINT8_MAX) ? metadata->upper_limit[index] : LIMIT_ERROR;
}

float get_pid_precision( uint32_t pid_uuid, PID_UNITS unit )
{
    PPID_METADATA metadata = find_pid_metadata(pid_uuid);
    uint8_t index = pid_unit_index(metadata, unit);
    return (index != UINT8_MAX) ? (float)metadata->precision[index] : 0.0f;
}

uint8_t get_pid_units( uint32_t pid_uuid, const PID_UNITS **units )
{
    PPID_METADATA metadata = find_pid_metadata(pid_uuid);

    if( units == NULL )
        return 0;

    *units = NULL;

    if( metadata == NULL )
        return 0;

    *units = metadata->supported_units;
    return metadata->num_supported_units;
}

uint32_t get_pid_from_list(uint32_t idx)
{
    return (idx < pid_metadata_count) ? pid_metadata_table[idx].pid_uuid : PID_UNASSIGNED;
}

uint32_t get_pid_list_size(void)
{
    return pid_metadata_count;
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
    if(pid->precision > 2) {
    	pid->precision = 2;
    }

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
    uint32_t sorted_pid_list[PID_MAX_DEFINITIONS];
    PID_DATA pid_json;

    if( pid_count > PID_MAX_DEFINITIONS )
        pid_count = PID_MAX_DEFINITIONS;

    for( uint32_t i = 0; i < pid_count; i++ )
        sorted_pid_list[i] = get_pid_from_list(i);

    sort_pid_list_by_desc(sorted_pid_list, pid_count);

    for (uint32_t i = 0; i < pid_count; i++) {
        // Load the base PID data
        memset(&pid_json, 0, sizeof(pid_json));
        pid_json.pid_uuid = sorted_pid_list[i];
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
