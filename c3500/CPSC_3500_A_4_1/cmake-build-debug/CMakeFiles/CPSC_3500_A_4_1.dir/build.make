# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPSC_3500_A_4_1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CPSC_3500_A_4_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPSC_3500_A_4_1.dir/flags.make

CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.o: CMakeFiles/CPSC_3500_A_4_1.dir/flags.make
CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.o: ../producer_consumer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.o -c /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1/producer_consumer.cpp

CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1/producer_consumer.cpp > CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.i

CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1/producer_consumer.cpp -o CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.s

# Object files for target CPSC_3500_A_4_1
CPSC_3500_A_4_1_OBJECTS = \
"CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.o"

# External object files for target CPSC_3500_A_4_1
CPSC_3500_A_4_1_EXTERNAL_OBJECTS =

CPSC_3500_A_4_1: CMakeFiles/CPSC_3500_A_4_1.dir/producer_consumer.cpp.o
CPSC_3500_A_4_1: CMakeFiles/CPSC_3500_A_4_1.dir/build.make
CPSC_3500_A_4_1: CMakeFiles/CPSC_3500_A_4_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPSC_3500_A_4_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPSC_3500_A_4_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPSC_3500_A_4_1.dir/build: CPSC_3500_A_4_1
.PHONY : CMakeFiles/CPSC_3500_A_4_1.dir/build

CMakeFiles/CPSC_3500_A_4_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPSC_3500_A_4_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPSC_3500_A_4_1.dir/clean

CMakeFiles/CPSC_3500_A_4_1.dir/depend:
	cd /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1 /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1 /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1/cmake-build-debug /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1/cmake-build-debug /Users/matthewthayer/CLionProjects/CPSC_3500_A_4_1/cmake-build-debug/CMakeFiles/CPSC_3500_A_4_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPSC_3500_A_4_1.dir/depend

