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
CMAKE_SOURCE_DIR = /root/flexran-rtc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/flexran-rtc/build

# Include any dependencies generated for this target.
include src/core/CMakeFiles/parse-bd.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/core/CMakeFiles/parse-bd.dir/compiler_depend.make

# Include the progress variables for this target.
include src/core/CMakeFiles/parse-bd.dir/progress.make

# Include the compile flags for this target's objects.
include src/core/CMakeFiles/parse-bd.dir/flags.make

src/core/CMakeFiles/parse-bd.dir/parse-bd.cc.o: src/core/CMakeFiles/parse-bd.dir/flags.make
src/core/CMakeFiles/parse-bd.dir/parse-bd.cc.o: ../src/core/parse-bd.cc
src/core/CMakeFiles/parse-bd.dir/parse-bd.cc.o: src/core/CMakeFiles/parse-bd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/core/CMakeFiles/parse-bd.dir/parse-bd.cc.o"
	cd /root/flexran-rtc/build/src/core && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/core/CMakeFiles/parse-bd.dir/parse-bd.cc.o -MF CMakeFiles/parse-bd.dir/parse-bd.cc.o.d -o CMakeFiles/parse-bd.dir/parse-bd.cc.o -c /root/flexran-rtc/src/core/parse-bd.cc

src/core/CMakeFiles/parse-bd.dir/parse-bd.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parse-bd.dir/parse-bd.cc.i"
	cd /root/flexran-rtc/build/src/core && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/core/parse-bd.cc > CMakeFiles/parse-bd.dir/parse-bd.cc.i

src/core/CMakeFiles/parse-bd.dir/parse-bd.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parse-bd.dir/parse-bd.cc.s"
	cd /root/flexran-rtc/build/src/core && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/core/parse-bd.cc -o CMakeFiles/parse-bd.dir/parse-bd.cc.s

# Object files for target parse-bd
parse__bd_OBJECTS = \
"CMakeFiles/parse-bd.dir/parse-bd.cc.o"

# External object files for target parse-bd
parse__bd_EXTERNAL_OBJECTS =

src/core/parse-bd: src/core/CMakeFiles/parse-bd.dir/parse-bd.cc.o
src/core/parse-bd: src/core/CMakeFiles/parse-bd.dir/build.make
src/core/parse-bd: src/app/libRTC_APP_LIB.a
src/core/parse-bd: src/core/libRTC_CORE_LIB.a
src/core/parse-bd: src/rib/libRTC_RIB_LIB.a
src/core/parse-bd: src/network/libRTC_NETWORK_LIB.a
src/core/parse-bd: src/event/libRTC_EVENT_LIB.a
src/core/parse-bd: src/app/libRTC_APP_LIB.a
src/core/parse-bd: src/core/libRTC_CORE_LIB.a
src/core/parse-bd: src/rib/libRTC_RIB_LIB.a
src/core/parse-bd: src/network/libRTC_NETWORK_LIB.a
src/core/parse-bd: src/event/libRTC_EVENT_LIB.a
src/core/parse-bd: /usr/lib/x86_64-linux-gnu/libcurl.so
src/core/parse-bd: /usr/lib/x86_64-linux-gnu/libboost_system.so
src/core/parse-bd: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
src/core/parse-bd: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
src/core/parse-bd: src/MESSAGES/V2/libFLPT_MSG_LIB.a
src/core/parse-bd: /usr/local/lib/libprotobuf.so
src/core/parse-bd: src/core/CMakeFiles/parse-bd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable parse-bd"
	cd /root/flexran-rtc/build/src/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parse-bd.dir/link.txt --verbose=$(VERBOSE)
	cd /root/flexran-rtc/build/src/core && /usr/local/bin/cmake -E copy parse-bd /root/flexran-rtc/build/.

# Rule to build all files generated by this target.
src/core/CMakeFiles/parse-bd.dir/build: src/core/parse-bd
.PHONY : src/core/CMakeFiles/parse-bd.dir/build

src/core/CMakeFiles/parse-bd.dir/clean:
	cd /root/flexran-rtc/build/src/core && $(CMAKE_COMMAND) -P CMakeFiles/parse-bd.dir/cmake_clean.cmake
.PHONY : src/core/CMakeFiles/parse-bd.dir/clean

src/core/CMakeFiles/parse-bd.dir/depend:
	cd /root/flexran-rtc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/flexran-rtc /root/flexran-rtc/src/core /root/flexran-rtc/build /root/flexran-rtc/build/src/core /root/flexran-rtc/build/src/core/CMakeFiles/parse-bd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/core/CMakeFiles/parse-bd.dir/depend

