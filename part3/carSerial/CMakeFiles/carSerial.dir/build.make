# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ghfjdhdl/Desktop/ubuntu/part3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ghfjdhdl/Desktop/ubuntu/part3

# Include any dependencies generated for this target.
include carSerial/CMakeFiles/carSerial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include carSerial/CMakeFiles/carSerial.dir/compiler_depend.make

# Include the progress variables for this target.
include carSerial/CMakeFiles/carSerial.dir/progress.make

# Include the compile flags for this target's objects.
include carSerial/CMakeFiles/carSerial.dir/flags.make

carSerial/CMakeFiles/carSerial.dir/main.c.o: carSerial/CMakeFiles/carSerial.dir/flags.make
carSerial/CMakeFiles/carSerial.dir/main.c.o: carSerial/main.c
carSerial/CMakeFiles/carSerial.dir/main.c.o: carSerial/CMakeFiles/carSerial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/part3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object carSerial/CMakeFiles/carSerial.dir/main.c.o"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT carSerial/CMakeFiles/carSerial.dir/main.c.o -MF CMakeFiles/carSerial.dir/main.c.o.d -o CMakeFiles/carSerial.dir/main.c.o -c /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial/main.c

carSerial/CMakeFiles/carSerial.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/carSerial.dir/main.c.i"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial/main.c > CMakeFiles/carSerial.dir/main.c.i

carSerial/CMakeFiles/carSerial.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/carSerial.dir/main.c.s"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial/main.c -o CMakeFiles/carSerial.dir/main.c.s

carSerial/CMakeFiles/carSerial.dir/serial.c.o: carSerial/CMakeFiles/carSerial.dir/flags.make
carSerial/CMakeFiles/carSerial.dir/serial.c.o: carSerial/serial.c
carSerial/CMakeFiles/carSerial.dir/serial.c.o: carSerial/CMakeFiles/carSerial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/part3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object carSerial/CMakeFiles/carSerial.dir/serial.c.o"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT carSerial/CMakeFiles/carSerial.dir/serial.c.o -MF CMakeFiles/carSerial.dir/serial.c.o.d -o CMakeFiles/carSerial.dir/serial.c.o -c /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial/serial.c

carSerial/CMakeFiles/carSerial.dir/serial.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/carSerial.dir/serial.c.i"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial/serial.c > CMakeFiles/carSerial.dir/serial.c.i

carSerial/CMakeFiles/carSerial.dir/serial.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/carSerial.dir/serial.c.s"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial/serial.c -o CMakeFiles/carSerial.dir/serial.c.s

# Object files for target carSerial
carSerial_OBJECTS = \
"CMakeFiles/carSerial.dir/main.c.o" \
"CMakeFiles/carSerial.dir/serial.c.o"

# External object files for target carSerial
carSerial_EXTERNAL_OBJECTS =

carSerial/carSerial: carSerial/CMakeFiles/carSerial.dir/main.c.o
carSerial/carSerial: carSerial/CMakeFiles/carSerial.dir/serial.c.o
carSerial/carSerial: carSerial/CMakeFiles/carSerial.dir/build.make
carSerial/carSerial: carSerial/CMakeFiles/carSerial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/part3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable carSerial"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/carSerial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
carSerial/CMakeFiles/carSerial.dir/build: carSerial/carSerial
.PHONY : carSerial/CMakeFiles/carSerial.dir/build

carSerial/CMakeFiles/carSerial.dir/clean:
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial && $(CMAKE_COMMAND) -P CMakeFiles/carSerial.dir/cmake_clean.cmake
.PHONY : carSerial/CMakeFiles/carSerial.dir/clean

carSerial/CMakeFiles/carSerial.dir/depend:
	cd /home/ghfjdhdl/Desktop/ubuntu/part3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ghfjdhdl/Desktop/ubuntu/part3 /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial /home/ghfjdhdl/Desktop/ubuntu/part3 /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial /home/ghfjdhdl/Desktop/ubuntu/part3/carSerial/CMakeFiles/carSerial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : carSerial/CMakeFiles/carSerial.dir/depend

