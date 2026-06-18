import json
from datetime import date

def format_name(units):
    """Generate a C-style name based on units."""
    return "_".join(unit.lower() for unit in units) + "_list"

def format_enum(units):
    """Generate PID_UNITS enum list for C code."""
    return ", ".join(f"PID_UNITS_{unit.upper()}" for unit in units)

today = date.today()

code_header = open('header.h', 'r').read()
code_header = code_header.replace("<today>", today.strftime("%b-%d-%Y"))
code_header = code_header.replace("<year>", today.strftime("%Y"))

with open('digital-dash-firmware.json') as f:
  data = json.load(f)

# Extract the list for your key
pid_list = data["Ford_Focus_STRS_2013_2018"]

# Sort by PID (string), e.g., ascending order
pid_list.sort(key=lambda pid: pid["desc"])

header = open("..\src\pid.h", "w")

length = 0

def format_pid_desc(pid):
    return pid["desc"].replace(' ', '_').replace('-', '_').replace('(', '').replace(')', '').replace('/', '_').replace(']', '').replace('[', '').upper()

for pid in pid_list:
    if len(pid["desc"]) > length:
        length = len(pid["desc"])

length = length + 4 + len("FAHRENHEIT") #Add the longest unit string

############################################
#                pid.h                     #
############################################

print("[CREATE] pid.h")

header.write( code_header + "\n\n" )

# Iterate through all PIDs
for pid in pid_list:

    # Determine even spacing
    spacing = length - len(pid["desc"])
    id_extension     = "_HEADER (uint16_t)0x"
    pid_extension    = "_PID (uint16_t)0x"
    mode_extension    = "_MODE (uint8_t)"
    uuid_extension    = "_UUID (uint32_t)"
    len_extension    = "_LEN (uint8_t)0x"
    units_extension  = "_UNITS (uint16_t)PID_UNITS_"
    label_extension  = "_LABEL \""
    parameter_extension  = "_PARAM \""
    desc_extension  = "_DESC \""
    id_extension     = id_extension.replace(' ', ' '*(spacing+4))
    pid_extension    = pid_extension.replace(' ', ' '*(spacing+7))
    mode_extension    = mode_extension.replace(' ', ' '*(spacing+6))
    uuid_extension    = uuid_extension.replace(' ', ' '*(spacing+6))
    len_extension    = len_extension.replace(' ', ' '*(spacing+7))
    units_extension  = units_extension.replace(' ', ' '*(spacing+5))
    label_extension  = label_extension.replace(' ', ' '*(spacing+5))
    parameter_extension  = parameter_extension.replace(' ', ' '*(spacing+5))
    desc_extension  = desc_extension.replace(' ', ' '*(spacing+6))

    # Add commenting
    header.write("/**\n")
    header.write(" * " + pid["desc"] + " expressed in " + pid["units"][0] +"\n" )
    header.write(" */\n")

    define = pid["mode"] + "_" + format_pid_desc(pid)

    # Define the PID header
    header.write("#define " + define + id_extension + pid["id"] + "\n")

    # Define the PID header
    header.write("#define " + define + pid_extension + pid["pid"] + "\n")

    # Define the PID byte code
    header.write("#define " + define + mode_extension + pid["mode"] + "\n")

    # Define the PID UUID
    header.write("#define " + define + uuid_extension + "((" + define + "_MODE" + " << 16) | " + define + "_PID)\n")

    # Define the PID response length
    header.write("#define " + define + len_extension + str(pid["dataLen"]) + "\n")

    # Define the PID units returned
    header.write("#define " + define + units_extension + pid["units"][0] + "\n")

    # Define the PID label
    header.write("#define " + define + label_extension + pid["label"] + "\"\n")

    # Define the PID description
    header.write("#define " + define + desc_extension + pid["desc"] + "\"\n")

    # Loop through each unit while accessing corresponding min and max values
    for i, unit in enumerate(pid["units"]):
        upper_extension  = "_UPPER (float)"
        lower_extension  = "_LOWER (float)"
        precision_extension = "_PRECISION (uint8_t)"
        upper_extension  = upper_extension.replace(' ', ' '*((spacing+4)-len(unit)))
        lower_extension  = lower_extension.replace(' ', ' '*((spacing+4)-len(unit)))
        precision_extension  = precision_extension.replace(' ', ' '*((spacing)-len(unit)))

        # Define the PID lower limit
        header.write("#define " + define + "_" + unit + lower_extension + str(pid["min"][i]) + "\n")

        # Define the PID upper limit
        header.write("#define " + define + "_" + unit + upper_extension + str(pid["max"][i]) + "\n")

        # Define the PID label
        header.write("#define " + define + "_" + unit + precision_extension + str(pid["decimals"][i]) + "\n")

    header.write("\n")

    print("[ADDED] " + pid["desc"])

header.close()

############################################
#        get_pid_base_unit.c               #
############################################

get_pid_base_unit = open("..\src\get_pid_base_unit.c", "w")

print("[CREATE] get_pid_base_unit.c")

get_pid_base_unit.write( code_header + "\n\n" )

get_pid_base_unit.write( "#include \"lib_pid.h\"\n\n" )

# Create the C function
get_pid_base_unit.write( "PID_UNITS get_pid_base_unit( uint32_t pid_uuid )\n" )
get_pid_base_unit.write( "{\n" )

get_pid_base_unit.write( "    switch( pid_uuid )\n" )
get_pid_base_unit.write( "    {\n" )

for pid in pid_list:
  get_pid_base_unit.write("            case ")
  get_pid_base_unit.write(pid["mode"] + "_" + format_pid_desc(pid) + "_UUID:\n")
  get_pid_base_unit.write("                return " + pid["mode"] + "_" + format_pid_desc(pid) + "_UNITS;\n\n" )

get_pid_base_unit.write("            default:\n")
get_pid_base_unit.write("                return 0;\n")
get_pid_base_unit.write( "    }\n" )
get_pid_base_unit.write( "}" )

get_pid_base_unit.close()

############################################
#        get_pid_lower_limit.c             #
############################################

get_pid_lower_limit = open("..\src\get_pid_lower_limit.c", "w")

print("[CREATE] get_pid_lower_limit.c")

get_pid_lower_limit.write( code_header + "\n\n" )

get_pid_lower_limit.write( "#include \"lib_pid.h\"\n\n" )

# Create the C function
get_pid_lower_limit.write( "float get_pid_lower_limit( uint32_t pid_uuid, PID_UNITS unit )\n" )
get_pid_lower_limit.write( "{\n" )

get_pid_lower_limit.write( "    switch( pid_uuid )\n" )
get_pid_lower_limit.write( "    {\n" )

for pid in pid_list:
  get_pid_lower_limit.write("            case ")
  get_pid_lower_limit.write(pid["mode"] + "_" + format_pid_desc(pid) + "_UUID:\n")
  get_pid_lower_limit.write("                switch( unit )\n" )
  get_pid_lower_limit.write("                {\n" )
  for case in pid["units"]:
    get_pid_lower_limit.write("                    case PID_UNITS_" + str(case) + ":\n" )
    get_pid_lower_limit.write("                        return " + pid["mode"] + "_" + format_pid_desc(pid) + "_" + case + "_LOWER;\n\n" )
  get_pid_lower_limit.write("                    default:\n" )
  get_pid_lower_limit.write("                        return LIMIT_ERROR;\n\n" )
  get_pid_lower_limit.write("                }\n\n" )

get_pid_lower_limit.write("            default:\n")
get_pid_lower_limit.write("                return 0;\n")
get_pid_lower_limit.write( "    }\n" )
get_pid_lower_limit.write( "}" )

get_pid_lower_limit.close()

############################################
#        get_pid_upper_limit.c             #
############################################

get_pid_upper_limit = open("..\src\get_pid_upper_limit.c", "w")

print("[CREATE] get_pid_upper_limit.c")

get_pid_upper_limit.write( code_header + "\n\n" )

get_pid_upper_limit.write( "#include \"lib_pid.h\"\n\n" )

# Create the C function
get_pid_upper_limit.write( "float get_pid_upper_limit( uint32_t pid_uuid, PID_UNITS unit )\n" )
get_pid_upper_limit.write( "{\n" )

get_pid_upper_limit.write( "    switch( pid_uuid )\n" )
get_pid_upper_limit.write( "    {\n" )

for pid in pid_list:
  get_pid_upper_limit.write("            case ")
  get_pid_upper_limit.write(pid["mode"] + "_" + format_pid_desc(pid) + "_UUID:\n")
  get_pid_upper_limit.write("                switch( unit )\n" )
  get_pid_upper_limit.write("                {\n" )
  for case in pid["units"]:
    get_pid_upper_limit.write("                    case PID_UNITS_" + str(case) + ":\n" )
    get_pid_upper_limit.write("                        return " + pid["mode"] + "_" + format_pid_desc(pid) + "_" + case + "_UPPER;\n\n" )
  get_pid_upper_limit.write("                    default:\n" )
  get_pid_upper_limit.write("                        return LIMIT_ERROR;\n\n" )
  get_pid_upper_limit.write("                }\n" )

get_pid_upper_limit.write("            default:\n")
get_pid_upper_limit.write("                return 0;\n")
get_pid_upper_limit.write( "    }\n\n" )
get_pid_upper_limit.write( "}" )

get_pid_upper_limit.close()

############################################
#       get_pid_precision.c          #
############################################

get_pid_precision = open("..\src\get_pid_precision.c", "w")

print("[CREATE] get_pid_precision.c")

get_pid_precision.write( code_header + "\n\n" )

get_pid_precision.write( "#include \"lib_pid.h\"\n\n" )

# Create the C function
get_pid_precision.write( "float get_pid_precision( uint32_t pid_uuid, PID_UNITS unit )\n" )
get_pid_precision.write( "{\n" )

get_pid_precision.write( "    switch( pid_uuid )\n" )
get_pid_precision.write( "    {\n" )

for pid in pid_list:
  get_pid_precision.write("            case ")
  get_pid_precision.write(pid["mode"] + "_" + format_pid_desc(pid) + "_UUID:\n")
  get_pid_precision.write("                switch( unit )\n" )
  get_pid_precision.write("                {\n" )
  for case in pid["units"]:
    get_pid_precision.write("                    case PID_UNITS_" + str(case) + ":\n" )
    get_pid_precision.write("                        return " + pid["mode"] + "_" + format_pid_desc(pid) + "_" + case + "_PRECISION;\n\n" )
  get_pid_precision.write("                    default:\n" )
  get_pid_precision.write("                        return 0;\n\n" )
  get_pid_precision.write("                }\n\n" )
get_pid_precision.write("            default:\n")
get_pid_precision.write("                return 0;\n")
get_pid_precision.write( "    }\n" )
get_pid_precision.write( "}" )

get_pid_precision.close()

############################################
#          get_pid_label.c                 #
############################################

get_pid_label = open("..\src\get_pid_label.c", "w")

print("[CREATE] get_pid_label.c")

get_pid_label.write( code_header + "\n\n" )

get_pid_label.write( "#include \"lib_pid.h\"\n\n" )


# Create the C function
get_pid_label.write( "uint8_t get_pid_label( uint32_t pid_uuid, char* label )\n" )
get_pid_label.write( "{\n" )

get_pid_label.write( "    for( uint8_t i = 0; i < LABEL_MAX_CHAR; i++ )\n" )
get_pid_label.write( "        label[i] = '\\0';\n\n" )

get_pid_label.write( "    switch( pid_uuid )\n" )
get_pid_label.write( "    {\n" )

for pid in pid_list:
  get_pid_label.write("            case ")
  get_pid_label.write(pid["mode"] + "_" + format_pid_desc(pid) + "_UUID:\n")
  get_pid_label.write("                memcpy(label, " + pid["mode"] + "_" + format_pid_desc(pid) + "_LABEL, sizeof(" + pid["mode"] + "_" + format_pid_desc(pid) + "_LABEL));\n" )
  get_pid_label.write("                break;\n\n" )

get_pid_label.write("            default:\n")
get_pid_label.write("                return 0;\n")
get_pid_label.write("    }\n" )
get_pid_label.write("    return 1;\n")
get_pid_label.write( "}" )

get_pid_label.close()

############################################
#          get_pid_desc.c                 #
############################################

get_pid_desc = open("..\src\get_pid_desc.c", "w")

print("[CREATE] get_pid_desc.c")

get_pid_desc.write( code_header + "\n\n" )

get_pid_desc.write( "#include \"lib_pid.h\"\n\n" )


# Create the C function
get_pid_desc.write( "uint8_t get_pid_desc( uint32_t pid_uuid, char* desc )\n" )
get_pid_desc.write( "{\n" )

get_pid_desc.write( "    for( uint8_t i = 0; i < LABEL_MAX_CHAR; i++ )\n" )
get_pid_desc.write( "        desc[i] = '\\0';\n\n" )

get_pid_desc.write( "    switch( pid_uuid )\n" )
get_pid_desc.write( "    {\n" )

for pid in pid_list:
  get_pid_desc.write("            case ")
  get_pid_desc.write(pid["mode"] + "_" + format_pid_desc(pid) + "_UUID:\n")
  get_pid_desc.write("                memcpy(desc, " + pid["mode"] + "_" + format_pid_desc(pid) + "_DESC, sizeof(" + pid["mode"] + "_" + format_pid_desc(pid) + "_DESC));\n" )
  get_pid_desc.write("                break;\n\n" )

get_pid_desc.write("            default:\n")
get_pid_desc.write("                return 0;\n")
get_pid_desc.write("    }\n" )
get_pid_desc.write("    return 1;\n")
get_pid_desc.write( "}" )

get_pid_desc.close()

############################################
#          get_pid_by_string.c             #
############################################

get_pid_by_string = open("..\src\get_pid_by_string.c", "w")

print("[CREATE] get_pid_by_string.c")

get_pid_by_string.write( code_header + "\n\n" )

get_pid_by_string.write( "#include \"lib_pid.h\"\n\n" )


# Create the C function
get_pid_by_string.write( "uint32_t get_pid_by_string(const char *str)\n" )
get_pid_by_string.write( "{\n" )
for pid in pid_list:
    get_pid_by_string.write("        if(strcmp(str, ")
    get_pid_by_string.write(pid["mode"] + "_" + format_pid_desc(pid) + "_DESC) == 0) ")
    get_pid_by_string.write("return " + pid["mode"] + "_" + format_pid_desc(pid) + "_UUID;\n\n" )
get_pid_by_string.write( "    return 0x00000000;\n" )
get_pid_by_string.write( "}\n" )
get_pid_by_string.close()

############################################
#          get_pid_header.c                #
############################################

get_pid_header = open("..\src\get_pid_header.c", "w")

print("[CREATE] get_pid_header.c")

get_pid_header.write( code_header + "\n\n" )

get_pid_header.write( "#include \"lib_pid.h\"\n\n" )

# Create the C function
get_pid_header.write( "uint16_t get_pid_header( uint32_t pid_uuid )\n" )
get_pid_header.write( "{\n" )

get_pid_header.write( "    switch( pid_uuid )\n" )
get_pid_header.write( "    {\n" )

for pid in pid_list:
    get_pid_header.write("            case ")
    get_pid_header.write(pid["mode"] + "_" + format_pid_desc(pid) + "_UUID:\n")
    get_pid_header.write("                return " + pid["mode"] + "_" + format_pid_desc(pid) + "_HEADER;\n\n" )

get_pid_header.write("            default:\n")
get_pid_header.write("                return 0;\n")
get_pid_header.write( "    }\n" )
get_pid_header.write( "}" )

get_pid_header.close()

############################################
#          get_pid_units.c                 #
############################################

get_pid_units = open("..\src\get_pid_units.c", "w")

print("[CREATE] get_pid_units.c")

# Collect unique unit combinations
unique_combinations = set()
for item in pid_list:
    units = item.get("units", [])
    if units:
        unique_combinations.add(tuple(units))

# Sort for consistent output
unique_combinations = sorted(unique_combinations)

get_pid_units.write( code_header + "\n\n" )

get_pid_units.write( "#include \"lib_pid.h\"\n\n" )

# Generate and print C-style definitions
for combo in unique_combinations:
    name = format_name(combo)
    enums = format_enum(combo)
    get_pid_units.write(f"static const PID_UNITS {name}[] = {{{enums}}};\n")

get_pid_units.write( "\n" )

# Create the C function
get_pid_units.write( "uint8_t get_pid_units( uint32_t pid_uuid, const PID_UNITS **units )\n" )
get_pid_units.write( "{\n" )

get_pid_units.write( "    switch( pid_uuid )\n" )
get_pid_units.write( "    {\n" )

for pid in pid_list:
    get_pid_units.write("            case ")
    get_pid_units.write(pid["mode"] + "_" + format_pid_desc(pid) + "_UUID:\n")
    get_pid_units.write("                *units = " + format_name(pid["units"]) + ";\n" )
    get_pid_units.write("                return sizeof(" + format_name(pid["units"]) + ") / sizeof(PID_UNITS);\n\n" )

get_pid_units.write("            default:\n")
get_pid_units.write("                return 0;\n")
get_pid_units.write( "    }\n" )
get_pid_units.write( "}" )

get_pid_units.close()

############################################
#             get_pid_list.c               #
############################################

get_pid_list = open("..\src\get_pid_list.c", "w")

print("[CREATE] get_pid_list.c")

get_pid_list.write( code_header + "\n\n" )

get_pid_list.write( "#include \"lib_pid.h\"\n\n" )
get_pid_list.write( "const uint32_t pid_list[] = {\n" )
for pid in pid_list:
  desc = format_pid_desc(pid)
  mode = pid["mode"].upper()
  get_pid_list.write(f'    {mode}_{desc}_UUID,\n')
get_pid_list.write( "};\n\n" )
get_pid_list.write( "uint32_t get_pid_from_list(uint32_t idx) { return pid_list[idx]; }\n" )
get_pid_list.write( "uint32_t get_pid_list_size(void) { return sizeof(pid_list) / sizeof(pid_list[0]); }\n" )

############################################
#               readme.md                  #
############################################W
readme = open("../readme.md", "w")

readme.write("| Type | Description |\n")
readme.write("| :--: | :-- |\n")

for pid in pid_list:

  if pid["vehicles"][0] == "Ford_Focus_STRS_2013_2018":
    if pid["mode"] == "MODE1":
      mode = "Mode 1"
    elif pid["mode"] == "MODE22":
      mode = "Mode 22"
    elif pid["mode"] == "SNIFF":
      mode = "Sniff"
    elif pid["mode"] == "CALC1":
      mode = "Custom"

    readme.write("| " + mode + " | " + pid["desc"] + " |\n")


readme.close()
