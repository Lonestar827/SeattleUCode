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
CMAKE_SOURCE_DIR = /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPSC_3500_Pthreads.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CPSC_3500_Pthreads.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPSC_3500_Pthreads.dir/flags.make

CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.o: CMakeFiles/CPSC_3500_Pthreads.dir/flags.make
CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.o: ../pthread_test_1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.o -c /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthread_test_1.cpp

CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthread_test_1.cpp > CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.i

CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthread_test_1.cpp -o CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.s

CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.o: CMakeFiles/CPSC_3500_Pthreads.dir/flags.make
CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.o: ../pthread_test_2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.o -c /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthread_test_2.cpp

CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthread_test_2.cpp > CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.i

CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthread_test_2.cpp -o CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.s

CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.o: CMakeFiles/CPSC_3500_Pthreads.dir/flags.make
CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.o: ../pthread_test_3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.o -c /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthread_test_3.cpp

CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthread_test_3.cpp > CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.i

CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthread_test_3.cpp -o CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.s

CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.o: CMakeFiles/CPSC_3500_Pthreads.dir/flags.make
CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.o: ../pthreads_skeleton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.o -c /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthreads_skeleton.cpp

CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthreads_skeleton.cpp > CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.i

CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/pthreads_skeleton.cpp -o CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.s

# Object files for target CPSC_3500_Pthreads
CPSC_3500_Pthreads_OBJECTS = \
"CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.o" \
"CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.o" \
"CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.o" \
"CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.o"

# External object files for target CPSC_3500_Pthreads
CPSC_3500_Pthreads_EXTERNAL_OBJECTS =

CPSC_3500_Pthreads: CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_1.cpp.o
CPSC_3500_Pthreads: CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_2.cpp.o
CPSC_3500_Pthreads: CMakeFiles/CPSC_3500_Pthreads.dir/pthread_test_3.cpp.o
CPSC_3500_Pthreads: CMakeFiles/CPSC_3500_Pthreads.dir/pthreads_skeleton.cpp.o
CPSC_3500_Pthreads: CMakeFiles/CPSC_3500_Pthreads.dir/build.make
CPSC_3500_Pthreads: CMakeFiles/CPSC_3500_Pthreads.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable CPSC_3500_Pthreads"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPSC_3500_Pthreads.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPSC_3500_Pthreads.dir/build: CPSC_3500_Pthreads
.PHONY : CMakeFiles/CPSC_3500_Pthreads.dir/build

CMakeFiles/CPSC_3500_Pthreads.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPSC_3500_Pthreads.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPSC_3500_Pthreads.dir/clean

CMakeFiles/CPSC_3500_Pthreads.dir/depend:
	cd /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/cmake-build-debug /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/cmake-build-debug /Users/matthewthayer/CLionProjects/CPSC_3500_Pthreads/cmake-build-debug/CMakeFiles/CPSC_3500_Pthreads.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPSC_3500_Pthreads.dir/depend

