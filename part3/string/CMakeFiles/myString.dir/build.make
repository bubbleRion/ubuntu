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
include string/CMakeFiles/myString.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include string/CMakeFiles/myString.dir/compiler_depend.make

# Include the progress variables for this target.
include string/CMakeFiles/myString.dir/progress.make

# Include the compile flags for this target's objects.
include string/CMakeFiles/myString.dir/flags.make

string/CMakeFiles/myString.dir/main.c.o: string/CMakeFiles/myString.dir/flags.make
string/CMakeFiles/myString.dir/main.c.o: string/main.c
string/CMakeFiles/myString.dir/main.c.o: string/CMakeFiles/myString.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/part3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object string/CMakeFiles/myString.dir/main.c.o"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/string && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT string/CMakeFiles/myString.dir/main.c.o -MF CMakeFiles/myString.dir/main.c.o.d -o CMakeFiles/myString.dir/main.c.o -c /home/ghfjdhdl/Desktop/ubuntu/part3/string/main.c

string/CMakeFiles/myString.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myString.dir/main.c.i"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/string && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ghfjdhdl/Desktop/ubuntu/part3/string/main.c > CMakeFiles/myString.dir/main.c.i

string/CMakeFiles/myString.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myString.dir/main.c.s"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/string && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ghfjdhdl/Desktop/ubuntu/part3/string/main.c -o CMakeFiles/myString.dir/main.c.s

string/CMakeFiles/myString.dir/myString.c.o: string/CMakeFiles/myString.dir/flags.make
string/CMakeFiles/myString.dir/myString.c.o: string/myString.c
string/CMakeFiles/myString.dir/myString.c.o: string/CMakeFiles/myString.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/part3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object string/CMakeFiles/myString.dir/myString.c.o"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/string && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT string/CMakeFiles/myString.dir/myString.c.o -MF CMakeFiles/myString.dir/myString.c.o.d -o CMakeFiles/myString.dir/myString.c.o -c /home/ghfjdhdl/Desktop/ubuntu/part3/string/myString.c

string/CMakeFiles/myString.dir/myString.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myString.dir/myString.c.i"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/string && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ghfjdhdl/Desktop/ubuntu/part3/string/myString.c > CMakeFiles/myString.dir/myString.c.i

string/CMakeFiles/myString.dir/myString.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myString.dir/myString.c.s"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/string && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ghfjdhdl/Desktop/ubuntu/part3/string/myString.c -o CMakeFiles/myString.dir/myString.c.s

# Object files for target myString
myString_OBJECTS = \
"CMakeFiles/myString.dir/main.c.o" \
"CMakeFiles/myString.dir/myString.c.o"

# External object files for target myString
myString_EXTERNAL_OBJECTS =

string/myString: string/CMakeFiles/myString.dir/main.c.o
string/myString: string/CMakeFiles/myString.dir/myString.c.o
string/myString: string/CMakeFiles/myString.dir/build.make
string/myString: string/CMakeFiles/myString.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ghfjdhdl/Desktop/ubuntu/part3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable myString"
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/string && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myString.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
string/CMakeFiles/myString.dir/build: string/myString
.PHONY : string/CMakeFiles/myString.dir/build

string/CMakeFiles/myString.dir/clean:
	cd /home/ghfjdhdl/Desktop/ubuntu/part3/string && $(CMAKE_COMMAND) -P CMakeFiles/myString.dir/cmake_clean.cmake
.PHONY : string/CMakeFiles/myString.dir/clean

string/CMakeFiles/myString.dir/depend:
	cd /home/ghfjdhdl/Desktop/ubuntu/part3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ghfjdhdl/Desktop/ubuntu/part3 /home/ghfjdhdl/Desktop/ubuntu/part3/string /home/ghfjdhdl/Desktop/ubuntu/part3 /home/ghfjdhdl/Desktop/ubuntu/part3/string /home/ghfjdhdl/Desktop/ubuntu/part3/string/CMakeFiles/myString.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : string/CMakeFiles/myString.dir/depend

