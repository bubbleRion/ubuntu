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
CMAKE_SOURCE_DIR = /home/ghfjdhdl/Desktop/ubuntu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ghfjdhdl/Desktop/ubuntu/build

# Include any dependencies generated for this target.
include part3/Carsignal/CMakeFiles/carSerial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include part3/Carsignal/CMakeFiles/carSerial.dir/compiler_depend.make

# Include the progress variables for this target.
include part3/Carsignal/CMakeFiles/carSerial.dir/progress.make

# Include the compile flags for this target's objects.
include part3/Carsignal/CMakeFiles/carSerial.dir/flags.make

part3/Carsignal/CMakeFiles/carSerial.dir/main.c.o: part3/Carsignal/CMakeFiles/carSerial.dir/flags.make
part3/Carsignal/CMakeFiles/carSerial.dir/main.c.o: ../part3/Carsignal/main.c
part3/Carsignal/CMakeFiles/carSerial.dir/main.c.o: part3/Carsignal/CMakeFiles/carSerial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object part3/Carsignal/CMakeFiles/carSerial.dir/main.c.o"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/part3/Carsignal && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT part3/Carsignal/CMakeFiles/carSerial.dir/main.c.o -MF CMakeFiles/carSerial.dir/main.c.o.d -o CMakeFiles/carSerial.dir/main.c.o -c /home/ghfjdhdl/Desktop/ubuntu/part3/Carsignal/main.c

part3/Carsignal/CMakeFiles/carSerial.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/carSerial.dir/main.c.i"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/part3/Carsignal && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ghfjdhdl/Desktop/ubuntu/part3/Carsignal/main.c > CMakeFiles/carSerial.dir/main.c.i

part3/Carsignal/CMakeFiles/carSerial.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/carSerial.dir/main.c.s"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/part3/Carsignal && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ghfjdhdl/Desktop/ubuntu/part3/Carsignal/main.c -o CMakeFiles/carSerial.dir/main.c.s

part3/Carsignal/CMakeFiles/carSerial.dir/serial.c.o: part3/Carsignal/CMakeFiles/carSerial.dir/flags.make
part3/Carsignal/CMakeFiles/carSerial.dir/serial.c.o: ../part3/Carsignal/serial.c
part3/Carsignal/CMakeFiles/carSerial.dir/serial.c.o: part3/Carsignal/CMakeFiles/carSerial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object part3/Carsignal/CMakeFiles/carSerial.dir/serial.c.o"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/part3/Carsignal && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT part3/Carsignal/CMakeFiles/carSerial.dir/serial.c.o -MF CMakeFiles/carSerial.dir/serial.c.o.d -o CMakeFiles/carSerial.dir/serial.c.o -c /home/ghfjdhdl/Desktop/ubuntu/part3/Carsignal/serial.c

part3/Carsignal/CMakeFiles/carSerial.dir/serial.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/carSerial.dir/serial.c.i"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/part3/Carsignal && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ghfjdhdl/Desktop/ubuntu/part3/Carsignal/serial.c > CMakeFiles/carSerial.dir/serial.c.i

part3/Carsignal/CMakeFiles/carSerial.dir/serial.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/carSerial.dir/serial.c.s"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/part3/Carsignal && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ghfjdhdl/Desktop/ubuntu/part3/Carsignal/serial.c -o CMakeFiles/carSerial.dir/serial.c.s

# Object files for target carSerial
carSerial_OBJECTS = \
"CMakeFiles/carSerial.dir/main.c.o" \
"CMakeFiles/carSerial.dir/serial.c.o"

# External object files for target carSerial
carSerial_EXTERNAL_OBJECTS =

part3/Carsignal/carSerial: part3/Carsignal/CMakeFiles/carSerial.dir/main.c.o
part3/Carsignal/carSerial: part3/Carsignal/CMakeFiles/carSerial.dir/serial.c.o
part3/Carsignal/carSerial: part3/Carsignal/CMakeFiles/carSerial.dir/build.make
part3/Carsignal/carSerial: part3/Carsignal/CMakeFiles/carSerial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable carSerial"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/part3/Carsignal && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/carSerial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
part3/Carsignal/CMakeFiles/carSerial.dir/build: part3/Carsignal/carSerial
.PHONY : part3/Carsignal/CMakeFiles/carSerial.dir/build

part3/Carsignal/CMakeFiles/carSerial.dir/clean:
	cd /home/ghfjdhdl/Desktop/ubuntu/build/part3/Carsignal && $(CMAKE_COMMAND) -P CMakeFiles/carSerial.dir/cmake_clean.cmake
.PHONY : part3/Carsignal/CMakeFiles/carSerial.dir/clean

part3/Carsignal/CMakeFiles/carSerial.dir/depend:
	cd /home/ghfjdhdl/Desktop/ubuntu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ghfjdhdl/Desktop/ubuntu /home/ghfjdhdl/Desktop/ubuntu/part3/Carsignal /home/ghfjdhdl/Desktop/ubuntu/build /home/ghfjdhdl/Desktop/ubuntu/build/part3/Carsignal /home/ghfjdhdl/Desktop/ubuntu/build/part3/Carsignal/CMakeFiles/carSerial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : part3/Carsignal/CMakeFiles/carSerial.dir/depend

