idf_component_register(SRCS "src/lib_pid.c" "src/get_pid_base_unit.c" "src/get_pid_header.c" "src/get_pid_label.c" "src/get_pid_lower_limit.c" "src/pid_unit_conversion.c"
                       INCLUDE_DIRS "src"
                       REQUIRES json)