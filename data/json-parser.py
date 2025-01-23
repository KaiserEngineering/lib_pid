import json
from datetime import date

today = date.today()

code_header = open('header.h', 'r').read()
code_header = code_header.replace("<today>", today.strftime("%b-%d-%Y"))
code_header = code_header.replace("<year>", today.strftime("%Y"))

C_FORMULAS = {
    'UNDEFINED'                                 : '0',
    '100_TIMES_A_OVER_255'                      : '(((float)data[A]) * (float)100) / (float)255',
    'A_OVER_200'                                : '(float)data[A] / (float)255',
    'A_MINUS_40'                                : '((float)data[A] - (float)40)',
    '256_TIMES_A_PLUS_B_OVER_4'                 : '(((float)256 * (float)data[A] ) + (float)data[B] ) / (float)4',
    '256_TIMES_A_PLUS_B_OVER_100'               : '(((float)256 * (float)data[A] ) + (float)data[B] ) / (float)100',
    '256_TIMES_A_PLUS_B_OVER_10_MINUS_40'       : '((((float)256 * (float)data[A] ) + (float)data[B] ) / (float)10)-(float)40',
    'A'                                         : '(float)data[A]',
    '256_TIMES_A_SIGNED_PLUS_B_OVER_64'         : '(((float)256 * (float)(int8_t)data[A] ) + (float)data[B] ) / (float)64',
    'A_TIMES_3'                                 : '(float)data[A] * (float)3',
    'A_OVER_2_MINUS_64'                         : '((float)data[A] / (float)2) - (float)64',
    'A_OVER_2_MINUS_40'                         : '((float)data[A] / (float)2) - (float)40',
    'A_OVER_3_MINUS_40'                         : '((float)data[A] / (float)3) - (float)40',
    '256_TIMES_A_SIGNED_PLUS_B_OVER_NEG_512'    : '(((float)256 * (float)((int8_t)data[A]) ) + (float)data[B] ) / (float)-512',
    '256_TIMES_A_SIGNED_PLUS_B_OVER_1024'       : '(((float)256 * (float)((int8_t)data[A]) ) + (float)data[B] ) / (float)1024',
    '256_TIMES_A_SIGNED_PLUS_B_OVER_16384'      : '(((float)256 * (float)((int8_t)data[A]) ) + (float)data[B] ) / (float)16384',
    '256_TIMES_A_PLUS_B_OVER_327_DOT_68'        : '(((float)256 * (float)(data[A]) ) + (float)data[B] ) / (float)327.68',
    '256_TIMES_A_PLUS_B_OVER_32768'             : '(((float)256 * (float)(data[A]) ) + (float)data[B] ) / (float)32768',
    '100_OVER_128_TIMES_A_MINUS_100'            : '(((float)100 / (float)128) * (float)(data[A])) - (float)100',
    '256_TIMES_A_PLUS_B_TIMES_2_OVER_65536_TIMES': '(((((float)256 * (float)(data[A])) + (float)(data[B])) * (float)2) / (float)65536)',
    'ZERO_DOT_079_TIMES_256_TIMES_A_PLUS_B'      : '((float)0.079 * (((float)256 * (float)data[A]) + (float)data[B]))',
    '256_TIMES_A_SIGNED_PLUS_B_TIMES_0_DOT_002'  : '(((float)256 * (float)((int8_t)data[A]) ) + (float)data[B] ) * (float)0.002',
    '256_TIMES_A_PLUS_B_OVER_3_PLUS_22_OVER_3'   : '((((float)256 *(float)data[A]) + (float)data[B]) + ((float)22 / (float)3))',
    '29D4_OVER_65536_TIMES_256_A_PLUS_B'         : '((((float)256 *(float)data[A]) + (float)data[B]) * (float)29.4) / (float)65536'
}

with open('digital-dash-firmware.json') as f:
  data = json.load(f)

header = open("..\src\pid.h", "w")

length = 0

for pid in data["Ford_Focus_STRS_2013_2018"]:
    if len(pid["desc"]) > length:
        length = len(pid["desc"])

length = length + 4

############################################
#                pid.h                     #
############################################

print("[CREATE] pid.h")

header.write( code_header + "\n\n" )

# Iterate through all PIDs
for pid in data["Ford_Focus_STRS_2013_2018"]:

    # Determine even spacing
    spacing = length - len(pid["desc"])
    id_extension     = "_HEADER (uint16_t)0x"
    pid_extension    = " (uint16_t)0x"
    len_extension    = "_LEN (uint8_t)0x"
    units_extension  = "_UNITS (uint16_t)"
    id_extension     = id_extension.replace(' ', ' '*(spacing))
    pid_extension    = pid_extension.replace(' ', ' '*(spacing+7))
    len_extension    = len_extension.replace(' ', ' '*(spacing+3))
    units_extension  = units_extension.replace(' ', ' '*(spacing+1))

    # Add commenting
    header.write("/**\n")
    header.write(" * " + pid["desc"] + " expressed in " + pid["units"][0] +"\n" )
    header.write(" */\n")

    # Add ifdef to check if PID is supported
    header.write("#if defined(" + pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + "_SUPPORTED) || !defined(LIMIT_PIDS)\n")

    # Define the PID header
    header.write("#define " + pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + id_extension + pid["id"] + "\n")

    # Define the PID byte code
    header.write("#define " + pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + pid_extension + pid["pid"] + "\n")

    # Define the PID response length
    header.write("#define " + pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + len_extension + str(pid["dataLen"]) + "\n")

    # Define the PID units returned
    header.write("#define " + pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + units_extension + pid["units"][0] + "\n")

    header.write("#endif\n\n")
    print("[ADDED] " + pid["desc"])

header.close()

############################################
#          get_pid_value.c                 #
############################################

get_pid_value = open("..\src\get_pid_value.c", "w")

print("[CREATE] get_pid_value.c")

get_pid_value.write( code_header + "\n\n" )

get_pid_value.write( "#include \"lib_pid.h\"\n\n" )

#Find the unique modes
unique_modes = []
for mode in data["Ford_Focus_STRS_2013_2018"]:
  if mode["mode"] not in unique_modes:
    unique_modes.append(mode["mode"])

# Create the C function
get_pid_value.write( "float get_pid_value( uint8_t mode, uint16_t pid, uint8_t data[] )\n" )
get_pid_value.write( "{\n" )
get_pid_value.write( "    switch( mode )\n" )
get_pid_value.write( "    {\n" )

# Parse through each mode and add the case statement
for mode in unique_modes:
  print("[ADDED] " + mode)
  get_pid_value.write( "        case " + mode + ":\n" )
  get_pid_value.write( "            switch( pid )\n" )
  get_pid_value.write( "            {\n" )

  # Get the formulas for the specific mode
  formulas = []
  for pid in data["Ford_Focus_STRS_2013_2018"]:
      if pid["formula"] not in formulas and pid["mode"] == mode:
        formulas.append(pid["formula"])

  for eq in formulas:
    for pid in data["Ford_Focus_STRS_2013_2018"]:
      if pid["mode"] == mode and pid["formula"] == eq:
        get_pid_value.write("                #if defined(")
        get_pid_value.write(pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + "_SUPPORTED) || !defined(LIMIT_PIDS)\n" )
        get_pid_value.write("                    #ifndef ")
        get_pid_value.write(pid["mode"] + "_" + pid["formula"] + "\n")
        get_pid_value.write("                    #define ")
        get_pid_value.write(pid["mode"] + "_" + pid["formula"] + "\n")
        get_pid_value.write("                    #endif\n")
        get_pid_value.write("                    case ")
        get_pid_value.write(pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + ":\n")
        get_pid_value.write("                #endif\n\n")
    get_pid_value.write("                #ifdef " + mode + "_" + eq + "\n")
    get_pid_value.write("                    return " + C_FORMULAS[eq] + ";\n")
    get_pid_value.write("                #endif\n\n")

  get_pid_value.write("                default:\n")
  get_pid_value.write("                    return 0;\n")
  get_pid_value.write( "            }\n" )
  get_pid_value.write( "        break;\n\n" )
get_pid_value.write( "        default:\n" )
get_pid_value.write( "            return 0;\n" )
get_pid_value.write( "    }\n" )
get_pid_value.write( "}" )

get_pid_value.close()

############################################
#        get_pid_base_unit.c               #
############################################

get_pid_base_unit = open("..\src\get_pid_base_unit.c", "w")

print("[CREATE] get_pid_base_unit.c")

get_pid_base_unit.write( code_header + "\n\n" )

get_pid_base_unit.write( "#include \"lib_pid.h\"\n\n" )

#Find the unique modes
unique_modes = []
for mode in data["Ford_Focus_STRS_2013_2018"]:
  if mode["mode"] not in unique_modes:
    unique_modes.append(mode["mode"])

# Create the C function
get_pid_base_unit.write( "PID_UNITS get_pid_base_unit( uint8_t mode, uint16_t pid )\n" )
get_pid_base_unit.write( "{\n" )
get_pid_base_unit.write( "    switch( mode )\n" )
get_pid_base_unit.write( "    {\n" )

# Parse through each mode and add the case statement
for mode in unique_modes:
  print("[ADDED] " + mode)
  get_pid_base_unit.write( "        case " + mode + ":\n" )
  get_pid_base_unit.write( "            switch( pid )\n" )
  get_pid_base_unit.write( "            {\n" )

  for pid in data["Ford_Focus_STRS_2013_2018"]:
    if pid["mode"] == mode:
      get_pid_base_unit.write("                #if defined(")
      get_pid_base_unit.write(pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + "_SUPPORTED) || !defined(LIMIT_PIDS)\n" )
      get_pid_base_unit.write("                case ")
      get_pid_base_unit.write(pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + ":\n")
      get_pid_base_unit.write("                    return " + pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + "_UNITS;\n" )
      get_pid_base_unit.write("                #endif\n\n")

  get_pid_base_unit.write("                default:\n")
  get_pid_base_unit.write("                    return 0;\n")
  get_pid_base_unit.write( "            }\n" )
  get_pid_base_unit.write( "        break;\n\n" )
get_pid_base_unit.write( "        default:\n" )
get_pid_base_unit.write( "            return 0;\n" )
get_pid_base_unit.write( "    }\n" )
get_pid_base_unit.write( "}" )

get_pid_base_unit.close()

############################################
#      lookup_payload_length.c             #
############################################

lookup_payload_length = open("..\src\lookup_payload_length.c", "w")

print("[CREATE] lookup_payload_length.c")

lookup_payload_length.write( code_header + "\n\n" )

lookup_payload_length.write( "#include \"lib_pid.h\"\n\n" )

#Find the unique modes
unique_modes = []
for mode in data["Ford_Focus_STRS_2013_2018"]:
  if mode["mode"] not in unique_modes:
    unique_modes.append(mode["mode"])

# Create the C function
lookup_payload_length.write( "uint8_t lookup_payload_length( uint8_t mode, uint16_t pid )\n" )
lookup_payload_length.write( "{\n" )
lookup_payload_length.write( "    switch( mode )\n" )
lookup_payload_length.write( "    {\n" )

# Parse through each mode and add the case statement
for mode in unique_modes:
  print("[ADDED] " + mode)
  lookup_payload_length.write( "        case " + mode + ":\n" )
  lookup_payload_length.write( "            switch( pid )\n" )
  lookup_payload_length.write( "            {\n" )

  for pid in data["Ford_Focus_STRS_2013_2018"]:
    if pid["mode"] == mode:
      lookup_payload_length.write("                #if defined(")
      lookup_payload_length.write(pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + "_SUPPORTED) || !defined(LIMIT_PIDS)\n" )
      lookup_payload_length.write("                case ")
      lookup_payload_length.write(pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + ":\n")
      lookup_payload_length.write("                    return " + pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + "_LEN;\n" )
      lookup_payload_length.write("                #endif\n\n")

  lookup_payload_length.write("                default:\n")
  lookup_payload_length.write("                    return 0;\n")
  lookup_payload_length.write( "            }\n" )
  lookup_payload_length.write( "        break;\n\n" )
lookup_payload_length.write( "        default:\n" )
lookup_payload_length.write( "            return 0;\n" )
lookup_payload_length.write( "    }\n" )
lookup_payload_length.write( "}" )

lookup_payload_length.close()

############################################
#          get_pid_header.c                #
############################################

get_pid_header = open("..\src\get_pid_header.c", "w")

print("[CREATE] get_pid_header.c")

get_pid_header.write( code_header + "\n\n" )

get_pid_header.write( "#include \"lib_pid.h\"\n\n" )

#Find the unique modes
unique_modes = []
for mode in data["Ford_Focus_STRS_2013_2018"]:
  if mode["mode"] not in unique_modes:
    unique_modes.append(mode["mode"])

# Create the C function
get_pid_header.write( "uint16_t get_pid_header( uint8_t mode, uint16_t pid )\n" )
get_pid_header.write( "{\n" )
get_pid_header.write( "    switch( mode )\n" )
get_pid_header.write( "    {\n" )

# Parse through each mode and add the case statement
for mode in unique_modes:
  print("[ADDED] " + mode)
  get_pid_header.write( "        case " + mode + ":\n" )
  get_pid_header.write( "            switch( pid )\n" )
  get_pid_header.write( "            {\n" )

  for pid in data["Ford_Focus_STRS_2013_2018"]:
    if pid["mode"] == mode:
      get_pid_header.write("                #if defined(")
      get_pid_header.write(pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + "_SUPPORTED) || !defined(LIMIT_PIDS)\n" )
      get_pid_header.write("                case ")
      get_pid_header.write(pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + ":\n")
      get_pid_header.write("                    return " + pid["mode"] + "_" + pid["desc"].replace(' ', '_').replace('-', '').upper() + "_HEADER;\n" )
      get_pid_header.write("                #endif\n\n")

  get_pid_header.write("                default:\n")
  get_pid_header.write("                    return 0;\n")
  get_pid_header.write( "            }\n" )
  get_pid_header.write( "        break;\n\n" )
get_pid_header.write( "        default:\n" )
get_pid_header.write( "            return 0;\n" )
get_pid_header.write( "    }\n" )
get_pid_header.write( "}" )

get_pid_header.close()

############################################
#               readme.md                  #
############################################
# Open the readme file for writing
readme = open("../readme.md", "w")

# Write the table headers to the readme
readme.write("| Parameter | Type | Description |\n")
readme.write("| :-- | :--: | :-- |\n")

# Open the JSON file and load the data
with open('digital-dash-firmware.json') as f:
    data = json.load(f)

# Create a list to store PIDs
pid_list = []

# Iterate over the PIDs and process them
for pid in data["Ford_Focus_STRS_2013_2018"]:
    if pid["vehicles"][0] == "Ford_Focus_STRS_2013_2018":
        # Determine the mode description
        if pid["mode"] == "MODE1":
            mode = "Mode 1"
        elif pid["mode"] == "MODE22":
            mode = "Mode 22"
        elif pid["mode"] == "SNIFF":
            mode = "Sniff"
        elif pid["mode"] == "CALC1":
            mode = "Custom"

        # Add the PID data to the list
        pid_list.append({
            "shortDesc": pid["shortDesc"],
            "mode": mode,
            "desc": pid["desc"]
        })

# Sort the list by "shortDesc"
pid_list.sort(key=lambda x: x["shortDesc"])

# Write the sorted PIDs to the readme file
for pid in pid_list:
    readme.write("| " + pid["shortDesc"] + " | " + pid["mode"] + " | " + pid["desc"] + " |\n")

# Close the readme file
readme.close()

############################################
#      test_lookup_payload_length.c        #
############################################
test_lookup_payload_length = open("../test/test_lookup_payload_length.c", "w")


test_lookup_payload_length.write("\n#ifdef TEST\n\n")

test_lookup_payload_length.write("#include \"unity.h\"\n\n")

test_lookup_payload_length.write("#include \"lib_pid.h\"\n\n")

test_lookup_payload_length.write("void setUp(void)\n{\n}\n\n")

test_lookup_payload_length.write("void tearDown(void)\n{\n}\n\n")

# Iterate through all PIDs
for pid in data["Ford_Focus_STRS_2013_2018"]:

  test_lookup_payload_length.write("void test_lookup_payload_length_" + pid["mode"].lower() + "_" + pid["desc"].replace(' ', '_').replace('-', '').lower() + "(void)\n")
  test_lookup_payload_length.write("{\n")
  test_lookup_payload_length.write("    TEST_ASSERT_EQUAL_INT(" + str(pid["dataLen"]) + ", lookup_payload_length(" + pid["mode"] + ", 0x" + pid["pid"].upper() + "));\n")
  test_lookup_payload_length.write("}\n\n")

test_lookup_payload_length.write("#endif")

test_lookup_payload_length.close