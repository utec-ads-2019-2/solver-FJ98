# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/85/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/85/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/felix/2019-2/ADS-20192/solver-FJ98

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felix/2019-2/ADS-20192/solver-FJ98/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/solver_FJ98.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/solver_FJ98.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/solver_FJ98.dir/flags.make

CMakeFiles/solver_FJ98.dir/main.cpp.o: CMakeFiles/solver_FJ98.dir/flags.make
CMakeFiles/solver_FJ98.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felix/2019-2/ADS-20192/solver-FJ98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/solver_FJ98.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/solver_FJ98.dir/main.cpp.o -c /home/felix/2019-2/ADS-20192/solver-FJ98/main.cpp

CMakeFiles/solver_FJ98.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/solver_FJ98.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felix/2019-2/ADS-20192/solver-FJ98/main.cpp > CMakeFiles/solver_FJ98.dir/main.cpp.i

CMakeFiles/solver_FJ98.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/solver_FJ98.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felix/2019-2/ADS-20192/solver-FJ98/main.cpp -o CMakeFiles/solver_FJ98.dir/main.cpp.s

CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.o: CMakeFiles/solver_FJ98.dir/flags.make
CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.o: ../ExpressionSolver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felix/2019-2/ADS-20192/solver-FJ98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.o -c /home/felix/2019-2/ADS-20192/solver-FJ98/ExpressionSolver.cpp

CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felix/2019-2/ADS-20192/solver-FJ98/ExpressionSolver.cpp > CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.i

CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felix/2019-2/ADS-20192/solver-FJ98/ExpressionSolver.cpp -o CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.s

# Object files for target solver_FJ98
solver_FJ98_OBJECTS = \
"CMakeFiles/solver_FJ98.dir/main.cpp.o" \
"CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.o"

# External object files for target solver_FJ98
solver_FJ98_EXTERNAL_OBJECTS =

solver_FJ98: CMakeFiles/solver_FJ98.dir/main.cpp.o
solver_FJ98: CMakeFiles/solver_FJ98.dir/ExpressionSolver.cpp.o
solver_FJ98: CMakeFiles/solver_FJ98.dir/build.make
solver_FJ98: CMakeFiles/solver_FJ98.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/felix/2019-2/ADS-20192/solver-FJ98/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable solver_FJ98"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/solver_FJ98.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/solver_FJ98.dir/build: solver_FJ98

.PHONY : CMakeFiles/solver_FJ98.dir/build

CMakeFiles/solver_FJ98.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/solver_FJ98.dir/cmake_clean.cmake
.PHONY : CMakeFiles/solver_FJ98.dir/clean

CMakeFiles/solver_FJ98.dir/depend:
	cd /home/felix/2019-2/ADS-20192/solver-FJ98/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felix/2019-2/ADS-20192/solver-FJ98 /home/felix/2019-2/ADS-20192/solver-FJ98 /home/felix/2019-2/ADS-20192/solver-FJ98/cmake-build-debug /home/felix/2019-2/ADS-20192/solver-FJ98/cmake-build-debug /home/felix/2019-2/ADS-20192/solver-FJ98/cmake-build-debug/CMakeFiles/solver_FJ98.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/solver_FJ98.dir/depend

