idf_component_register(SRCS "src/lib_pid.c" "src/get_pid_base_unit.c" "src/get_pid_header.c" "src/get_pid_label.c" "src/get_pid_lower_limit.c" "src/get_pid_precision.c" "src/get_pid_upper_limit.c" "src/get_pid_value.c" "src/get_unit_label.c" "src/lib_pid.c" "src/lookup_payload_length.c"
                       INCLUDE_DIRS "src"
                       REQUIRES cJSON)