# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/maherme/Projects/cpp_buffer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maherme/Projects/cpp_buffer/build

# Include any dependencies generated for this target.
include modules/Data/CMakeFiles/DataLib.dir/depend.make

# Include the progress variables for this target.
include modules/Data/CMakeFiles/DataLib.dir/progress.make

# Include the compile flags for this target's objects.
include modules/Data/CMakeFiles/DataLib.dir/flags.make

modules/Data/CMakeFiles/DataLib.dir/Data.cpp.o: modules/Data/CMakeFiles/DataLib.dir/flags.make
modules/Data/CMakeFiles/DataLib.dir/Data.cpp.o: ../modules/Data/Data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maherme/Projects/cpp_buffer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/Data/CMakeFiles/DataLib.dir/Data.cpp.o"
	cd /home/maherme/Projects/cpp_buffer/build/modules/Data && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataLib.dir/Data.cpp.o -c /home/maherme/Projects/cpp_buffer/modules/Data/Data.cpp

modules/Data/CMakeFiles/DataLib.dir/Data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataLib.dir/Data.cpp.i"
	cd /home/maherme/Projects/cpp_buffer/build/modules/Data && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maherme/Projects/cpp_buffer/modules/Data/Data.cpp > CMakeFiles/DataLib.dir/Data.cpp.i

modules/Data/CMakeFiles/DataLib.dir/Data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataLib.dir/Data.cpp.s"
	cd /home/maherme/Projects/cpp_buffer/build/modules/Data && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maherme/Projects/cpp_buffer/modules/Data/Data.cpp -o CMakeFiles/DataLib.dir/Data.cpp.s

# Object files for target DataLib
DataLib_OBJECTS = \
"CMakeFiles/DataLib.dir/Data.cpp.o"

# External object files for target DataLib
DataLib_EXTERNAL_OBJECTS =

modules/Data/libDataLib.a: modules/Data/CMakeFiles/DataLib.dir/Data.cpp.o
modules/Data/libDataLib.a: modules/Data/CMakeFiles/DataLib.dir/build.make
modules/Data/libDataLib.a: modules/Data/CMakeFiles/DataLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maherme/Projects/cpp_buffer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDataLib.a"
	cd /home/maherme/Projects/cpp_buffer/build/modules/Data && $(CMAKE_COMMAND) -P CMakeFiles/DataLib.dir/cmake_clean_target.cmake
	cd /home/maherme/Projects/cpp_buffer/build/modules/Data && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/Data/CMakeFiles/DataLib.dir/build: modules/Data/libDataLib.a

.PHONY : modules/Data/CMakeFiles/DataLib.dir/build

modules/Data/CMakeFiles/DataLib.dir/clean:
	cd /home/maherme/Projects/cpp_buffer/build/modules/Data && $(CMAKE_COMMAND) -P CMakeFiles/DataLib.dir/cmake_clean.cmake
.PHONY : modules/Data/CMakeFiles/DataLib.dir/clean

modules/Data/CMakeFiles/DataLib.dir/depend:
	cd /home/maherme/Projects/cpp_buffer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maherme/Projects/cpp_buffer /home/maherme/Projects/cpp_buffer/modules/Data /home/maherme/Projects/cpp_buffer/build /home/maherme/Projects/cpp_buffer/build/modules/Data /home/maherme/Projects/cpp_buffer/build/modules/Data/CMakeFiles/DataLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/Data/CMakeFiles/DataLib.dir/depend

