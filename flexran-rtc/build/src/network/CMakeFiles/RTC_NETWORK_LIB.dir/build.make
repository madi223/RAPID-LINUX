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
include src/network/CMakeFiles/RTC_NETWORK_LIB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/network/CMakeFiles/RTC_NETWORK_LIB.dir/compiler_depend.make

# Include the progress variables for this target.
include src/network/CMakeFiles/RTC_NETWORK_LIB.dir/progress.make

# Include the compile flags for this target's objects.
include src/network/CMakeFiles/RTC_NETWORK_LIB.dir/flags.make

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.o: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/flags.make
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.o: ../src/network/async_xface.cc
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.o: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/network/CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.o"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/network/CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.o -MF CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.o.d -o CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.o -c /root/flexran-rtc/src/network/async_xface.cc

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.i"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/network/async_xface.cc > CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.i

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.s"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/network/async_xface.cc -o CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.s

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.o: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/flags.make
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.o: ../src/network/connection_manager.cc
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.o: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/network/CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.o"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/network/CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.o -MF CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.o.d -o CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.o -c /root/flexran-rtc/src/network/connection_manager.cc

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.i"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/network/connection_manager.cc > CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.i

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.s"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/network/connection_manager.cc -o CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.s

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.o: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/flags.make
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.o: ../src/network/agent_session.cc
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.o: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/network/CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.o"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/network/CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.o -MF CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.o.d -o CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.o -c /root/flexran-rtc/src/network/agent_session.cc

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.i"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/network/agent_session.cc > CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.i

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.s"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/network/agent_session.cc -o CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.s

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.o: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/flags.make
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.o: ../src/network/protocol_message.cc
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.o: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/network/CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.o"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/network/CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.o -MF CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.o.d -o CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.o -c /root/flexran-rtc/src/network/protocol_message.cc

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.i"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/network/protocol_message.cc > CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.i

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.s"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/network/protocol_message.cc -o CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.s

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.o: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/flags.make
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.o: ../src/network/tagged_message.cc
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.o: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/network/CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.o"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/network/CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.o -MF CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.o.d -o CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.o -c /root/flexran-rtc/src/network/tagged_message.cc

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.i"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/flexran-rtc/src/network/tagged_message.cc > CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.i

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.s"
	cd /root/flexran-rtc/build/src/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/flexran-rtc/src/network/tagged_message.cc -o CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.s

# Object files for target RTC_NETWORK_LIB
RTC_NETWORK_LIB_OBJECTS = \
"CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.o" \
"CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.o" \
"CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.o" \
"CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.o" \
"CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.o"

# External object files for target RTC_NETWORK_LIB
RTC_NETWORK_LIB_EXTERNAL_OBJECTS =

src/network/libRTC_NETWORK_LIB.a: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/async_xface.cc.o
src/network/libRTC_NETWORK_LIB.a: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/connection_manager.cc.o
src/network/libRTC_NETWORK_LIB.a: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/agent_session.cc.o
src/network/libRTC_NETWORK_LIB.a: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/protocol_message.cc.o
src/network/libRTC_NETWORK_LIB.a: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/tagged_message.cc.o
src/network/libRTC_NETWORK_LIB.a: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/build.make
src/network/libRTC_NETWORK_LIB.a: src/network/CMakeFiles/RTC_NETWORK_LIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/flexran-rtc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libRTC_NETWORK_LIB.a"
	cd /root/flexran-rtc/build/src/network && $(CMAKE_COMMAND) -P CMakeFiles/RTC_NETWORK_LIB.dir/cmake_clean_target.cmake
	cd /root/flexran-rtc/build/src/network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RTC_NETWORK_LIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/network/CMakeFiles/RTC_NETWORK_LIB.dir/build: src/network/libRTC_NETWORK_LIB.a
.PHONY : src/network/CMakeFiles/RTC_NETWORK_LIB.dir/build

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/clean:
	cd /root/flexran-rtc/build/src/network && $(CMAKE_COMMAND) -P CMakeFiles/RTC_NETWORK_LIB.dir/cmake_clean.cmake
.PHONY : src/network/CMakeFiles/RTC_NETWORK_LIB.dir/clean

src/network/CMakeFiles/RTC_NETWORK_LIB.dir/depend:
	cd /root/flexran-rtc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/flexran-rtc /root/flexran-rtc/src/network /root/flexran-rtc/build /root/flexran-rtc/build/src/network /root/flexran-rtc/build/src/network/CMakeFiles/RTC_NETWORK_LIB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/network/CMakeFiles/RTC_NETWORK_LIB.dir/depend
