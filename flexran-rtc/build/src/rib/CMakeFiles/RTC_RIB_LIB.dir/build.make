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
include src/rib/CMakeFiles/RTC_RIB_LIB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/rib/CMakeFiles/RTC_RIB_LIB.dir/compiler_depend.make

# Include the progress variables for this target.
include src/rib/CMakeFiles/RTC_RIB_LIB.dir/progress.make

# Include the compile flags for this target's objects.
include src/rib/CMakeFiles/RTC_RIB_LIB.dir/flags.make

src/rib/CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/flags.make
src/rib/CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.o: ../src/rib/agent_info.cc
src/rib/CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/rib/CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.o"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/rib/CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.o -MF CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.o.d -o CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.o -c /root/flexran-rtc/src/rib/agent_info.cc

src/rib/CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.i"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/rib/agent_info.cc > CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.i

src/rib/CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.s"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/rib/agent_info.cc -o CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.s

src/rib/CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/flags.make
src/rib/CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.o: ../src/rib/cell_mac_rib_info.cc
src/rib/CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/rib/CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.o"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/rib/CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.o -MF CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.o.d -o CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.o -c /root/flexran-rtc/src/rib/cell_mac_rib_info.cc

src/rib/CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.i"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/rib/cell_mac_rib_info.cc > CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.i

src/rib/CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.s"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/rib/cell_mac_rib_info.cc -o CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.s

src/rib/CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/flags.make
src/rib/CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.o: ../src/rib/enb_rib_info.cc
src/rib/CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/rib/CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.o"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/rib/CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.o -MF CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.o.d -o CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.o -c /root/flexran-rtc/src/rib/enb_rib_info.cc

src/rib/CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.i"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/rib/enb_rib_info.cc > CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.i

src/rib/CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.s"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/rib/enb_rib_info.cc -o CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.s

src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/flags.make
src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib.cc.o: ../src/rib/rib.cc
src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib.cc.o"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib.cc.o -MF CMakeFiles/RTC_RIB_LIB.dir/rib.cc.o.d -o CMakeFiles/RTC_RIB_LIB.dir/rib.cc.o -c /root/flexran-rtc/src/rib/rib.cc

src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_RIB_LIB.dir/rib.cc.i"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/rib/rib.cc > CMakeFiles/RTC_RIB_LIB.dir/rib.cc.i

src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_RIB_LIB.dir/rib.cc.s"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/rib/rib.cc -o CMakeFiles/RTC_RIB_LIB.dir/rib.cc.s

src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/flags.make
src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.o: ../src/rib/rib_common.cc
src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.o"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.o -MF CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.o.d -o CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.o -c /root/flexran-rtc/src/rib/rib_common.cc

src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.i"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/rib/rib_common.cc > CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.i

src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.s"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/rib/rib_common.cc -o CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.s

src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/flags.make
src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.o: ../src/rib/rib_updater.cc
src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.o"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.o -MF CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.o.d -o CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.o -c /root/flexran-rtc/src/rib/rib_updater.cc

src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.i"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/rib/rib_updater.cc > CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.i

src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.s"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/rib/rib_updater.cc -o CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.s

src/rib/CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/flags.make
src/rib/CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.o: ../src/rib/ue_mac_rib_info.cc
src/rib/CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.o: src/rib/CMakeFiles/RTC_RIB_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/rib/CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.o"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/rib/CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.o -MF CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.o.d -o CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.o -c /root/flexran-rtc/src/rib/ue_mac_rib_info.cc

src/rib/CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.i"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/rib/ue_mac_rib_info.cc > CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.i

src/rib/CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.s"
	cd /root/flexran-rtc/build/src/rib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/rib/ue_mac_rib_info.cc -o CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.s

# Object files for target RTC_RIB_LIB
RTC_RIB_LIB_OBJECTS = \
"CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.o" \
"CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.o" \
"CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.o" \
"CMakeFiles/RTC_RIB_LIB.dir/rib.cc.o" \
"CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.o" \
"CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.o" \
"CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.o"

# External object files for target RTC_RIB_LIB
RTC_RIB_LIB_EXTERNAL_OBJECTS =

src/rib/libRTC_RIB_LIB.a: src/rib/CMakeFiles/RTC_RIB_LIB.dir/agent_info.cc.o
src/rib/libRTC_RIB_LIB.a: src/rib/CMakeFiles/RTC_RIB_LIB.dir/cell_mac_rib_info.cc.o
src/rib/libRTC_RIB_LIB.a: src/rib/CMakeFiles/RTC_RIB_LIB.dir/enb_rib_info.cc.o
src/rib/libRTC_RIB_LIB.a: src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib.cc.o
src/rib/libRTC_RIB_LIB.a: src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_common.cc.o
src/rib/libRTC_RIB_LIB.a: src/rib/CMakeFiles/RTC_RIB_LIB.dir/rib_updater.cc.o
src/rib/libRTC_RIB_LIB.a: src/rib/CMakeFiles/RTC_RIB_LIB.dir/ue_mac_rib_info.cc.o
src/rib/libRTC_RIB_LIB.a: src/rib/CMakeFiles/RTC_RIB_LIB.dir/build.make
src/rib/libRTC_RIB_LIB.a: src/rib/CMakeFiles/RTC_RIB_LIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libRTC_RIB_LIB.a"
	cd /root/flexran-rtc/build/src/rib && $(CMAKE_COMMAND) -P CMakeFiles/RTC_RIB_LIB.dir/cmake_clean_target.cmake
	cd /root/flexran-rtc/build/src/rib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RTC_RIB_LIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/rib/CMakeFiles/RTC_RIB_LIB.dir/build: src/rib/libRTC_RIB_LIB.a
.PHONY : src/rib/CMakeFiles/RTC_RIB_LIB.dir/build

src/rib/CMakeFiles/RTC_RIB_LIB.dir/clean:
	cd /root/flexran-rtc/build/src/rib && $(CMAKE_COMMAND) -P CMakeFiles/RTC_RIB_LIB.dir/cmake_clean.cmake
.PHONY : src/rib/CMakeFiles/RTC_RIB_LIB.dir/clean

src/rib/CMakeFiles/RTC_RIB_LIB.dir/depend:
	cd /root/flexran-rtc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/flexran-rtc /root/flexran-rtc/src/rib /root/flexran-rtc/build /root/flexran-rtc/build/src/rib /root/flexran-rtc/build/src/rib/CMakeFiles/RTC_RIB_LIB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/rib/CMakeFiles/RTC_RIB_LIB.dir/depend

