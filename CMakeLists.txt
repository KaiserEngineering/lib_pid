idf_component_register(SRCS "src/lib_pid.c" "src/pid_unit_conversion.c" "src/get_unit_by_string.c" "src/get_unit_desc.c" "src/get_unit_label.c"
                       INCLUDE_DIRS "src"
                       REQUIRES json)
