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
include bowling/CMakeFiles/bowling.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bowling/CMakeFiles/bowling.dir/compiler_depend.make

# Include the progress variables for this target.
include bowling/CMakeFiles/bowling.dir/progress.make

# Include the compile flags for this target's objects.
include bowling/CMakeFiles/bowling.dir/flags.make

bowling/CMakeFiles/bowling.dir/src/bowling.c.o: bowling/CMakeFiles/bowling.dir/flags.make
bowling/CMakeFiles/bowling.dir/src/bowling.c.o: ../bowling/src/bowling.c
bowling/CMakeFiles/bowling.dir/src/bowling.c.o: bowling/CMakeFiles/bowling.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object bowling/CMakeFiles/bowling.dir/src/bowling.c.o"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/bowling && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT bowling/CMakeFiles/bowling.dir/src/bowling.c.o -MF CMakeFiles/bowling.dir/src/bowling.c.o.d -o CMakeFiles/bowling.dir/src/bowling.c.o -c /home/ghfjdhdl/Desktop/ubuntu/bowling/src/bowling.c

bowling/CMakeFiles/bowling.dir/src/bowling.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bowling.dir/src/bowling.c.i"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/bowling && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ghfjdhdl/Desktop/ubuntu/bowling/src/bowling.c > CMakeFiles/bowling.dir/src/bowling.c.i

bowling/CMakeFiles/bowling.dir/src/bowling.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bowling.dir/src/bowling.c.s"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/bowling && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ghfjdhdl/Desktop/ubuntu/bowling/src/bowling.c -o CMakeFiles/bowling.dir/src/bowling.c.s

bowling/CMakeFiles/bowling.dir/src/main.c.o: bowling/CMakeFiles/bowling.dir/flags.make
bowling/CMakeFiles/bowling.dir/src/main.c.o: ../bowling/src/main.c
bowling/CMakeFiles/bowling.dir/src/main.c.o: bowling/CMakeFiles/bowling.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object bowling/CMakeFiles/bowling.dir/src/main.c.o"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/bowling && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT bowling/CMakeFiles/bowling.dir/src/main.c.o -MF CMakeFiles/bowling.dir/src/main.c.o.d -o CMakeFiles/bowling.dir/src/main.c.o -c /home/ghfjdhdl/Desktop/ubuntu/bowling/src/main.c

bowling/CMakeFiles/bowling.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bowling.dir/src/main.c.i"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/bowling && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ghfjdhdl/Desktop/ubuntu/bowling/src/main.c > CMakeFiles/bowling.dir/src/main.c.i

bowling/CMakeFiles/bowling.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bowling.dir/src/main.c.s"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/bowling && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ghfjdhdl/Desktop/ubuntu/bowling/src/main.c -o CMakeFiles/bowling.dir/src/main.c.s

# Object files for target bowling
bowling_OBJECTS = \
"CMakeFiles/bowling.dir/src/bowling.c.o" \
"CMakeFiles/bowling.dir/src/main.c.o"

# External object files for target bowling
bowling_EXTERNAL_OBJECTS =

bowling/bowling: bowling/CMakeFiles/bowling.dir/src/bowling.c.o
bowling/bowling: bowling/CMakeFiles/bowling.dir/src/main.c.o
bowling/bowling: bowling/CMakeFiles/bowling.dir/build.make
bowling/bowling: bowling/CMakeFiles/bowling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable bowling"
	cd /home/ghfjdhdl/Desktop/ubuntu/build/bowling && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bowling.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bowling/CMakeFiles/bowling.dir/build: bowling/bowling
.PHONY : bowling/CMakeFiles/bowling.dir/build

bowling/CMakeFiles/bowling.dir/clean:
	cd /home/ghfjdhdl/Desktop/ubuntu/build/bowling && $(CMAKE_COMMAND) -P CMakeFiles/bowling.dir/cmake_clean.cmake
.PHONY : bowling/CMakeFiles/bowling.dir/clean

bowling/CMakeFiles/bowling.dir/depend:
	cd /home/ghfjdhdl/Desktop/ubuntu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ghfjdhdl/Desktop/ubuntu /home/ghfjdhdl/Desktop/ubuntu/bowling /home/ghfjdhdl/Desktop/ubuntu/build /home/ghfjdhdl/Desktop/ubuntu/build/bowling /home/ghfjdhdl/Desktop/ubuntu/build/bowling/CMakeFiles/bowling.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bowling/CMakeFiles/bowling.dir/depend

