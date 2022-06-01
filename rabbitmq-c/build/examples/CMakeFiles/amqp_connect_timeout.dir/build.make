# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/RAPID-LINUX/rabbitmq-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/RAPID-LINUX/rabbitmq-c/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/amqp_connect_timeout.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/amqp_connect_timeout.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/amqp_connect_timeout.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/amqp_connect_timeout.dir/flags.make

examples/CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.o: examples/CMakeFiles/amqp_connect_timeout.dir/flags.make
examples/CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.o: ../examples/amqp_connect_timeout.c
examples/CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.o: examples/CMakeFiles/amqp_connect_timeout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/RAPID-LINUX/rabbitmq-c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.o"
	cd /root/RAPID-LINUX/rabbitmq-c/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.o -MF CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.o.d -o CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.o -c /root/RAPID-LINUX/rabbitmq-c/examples/amqp_connect_timeout.c

examples/CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.i"
	cd /root/RAPID-LINUX/rabbitmq-c/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/RAPID-LINUX/rabbitmq-c/examples/amqp_connect_timeout.c > CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.i

examples/CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.s"
	cd /root/RAPID-LINUX/rabbitmq-c/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/RAPID-LINUX/rabbitmq-c/examples/amqp_connect_timeout.c -o CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.s

# Object files for target amqp_connect_timeout
amqp_connect_timeout_OBJECTS = \
"CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.o"

# External object files for target amqp_connect_timeout
amqp_connect_timeout_EXTERNAL_OBJECTS = \
"/root/RAPID-LINUX/rabbitmq-c/build/examples/CMakeFiles/examples-common.dir/utils.c.o" \
"/root/RAPID-LINUX/rabbitmq-c/build/examples/CMakeFiles/examples-common.dir/unix/platform_utils.c.o"

examples/amqp_connect_timeout: examples/CMakeFiles/amqp_connect_timeout.dir/amqp_connect_timeout.c.o
examples/amqp_connect_timeout: examples/CMakeFiles/examples-common.dir/utils.c.o
examples/amqp_connect_timeout: examples/CMakeFiles/examples-common.dir/unix/platform_utils.c.o
examples/amqp_connect_timeout: examples/CMakeFiles/amqp_connect_timeout.dir/build.make
examples/amqp_connect_timeout: librabbitmq/librabbitmq.so.0.12.0
examples/amqp_connect_timeout: examples/CMakeFiles/amqp_connect_timeout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/RAPID-LINUX/rabbitmq-c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable amqp_connect_timeout"
	cd /root/RAPID-LINUX/rabbitmq-c/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/amqp_connect_timeout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/amqp_connect_timeout.dir/build: examples/amqp_connect_timeout
.PHONY : examples/CMakeFiles/amqp_connect_timeout.dir/build

examples/CMakeFiles/amqp_connect_timeout.dir/clean:
	cd /root/RAPID-LINUX/rabbitmq-c/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/amqp_connect_timeout.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/amqp_connect_timeout.dir/clean

examples/CMakeFiles/amqp_connect_timeout.dir/depend:
	cd /root/RAPID-LINUX/rabbitmq-c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/RAPID-LINUX/rabbitmq-c /root/RAPID-LINUX/rabbitmq-c/examples /root/RAPID-LINUX/rabbitmq-c/build /root/RAPID-LINUX/rabbitmq-c/build/examples /root/RAPID-LINUX/rabbitmq-c/build/examples/CMakeFiles/amqp_connect_timeout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/amqp_connect_timeout.dir/depend

