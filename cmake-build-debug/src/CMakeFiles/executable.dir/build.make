# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /opt/JetBrains/apps/CLion/ch-0/181.4445.84/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/JetBrains/apps/CLion/ch-0/181.4445.84/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thekatze/CLionProjects/shvrdengine-test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/executable.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/executable.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/executable.dir/flags.make

src/CMakeFiles/executable.dir/main.cpp.o: src/CMakeFiles/executable.dir/flags.make
src/CMakeFiles/executable.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/executable.dir/main.cpp.o"
	cd /home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executable.dir/main.cpp.o -c /home/thekatze/CLionProjects/shvrdengine-test/src/main.cpp

src/CMakeFiles/executable.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executable.dir/main.cpp.i"
	cd /home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thekatze/CLionProjects/shvrdengine-test/src/main.cpp > CMakeFiles/executable.dir/main.cpp.i

src/CMakeFiles/executable.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executable.dir/main.cpp.s"
	cd /home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thekatze/CLionProjects/shvrdengine-test/src/main.cpp -o CMakeFiles/executable.dir/main.cpp.s

src/CMakeFiles/executable.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/executable.dir/main.cpp.o.requires

src/CMakeFiles/executable.dir/main.cpp.o.provides: src/CMakeFiles/executable.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/executable.dir/build.make src/CMakeFiles/executable.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/executable.dir/main.cpp.o.provides

src/CMakeFiles/executable.dir/main.cpp.o.provides.build: src/CMakeFiles/executable.dir/main.cpp.o


# Object files for target executable
executable_OBJECTS = \
"CMakeFiles/executable.dir/main.cpp.o"

# External object files for target executable
executable_EXTERNAL_OBJECTS =

src/executable: src/CMakeFiles/executable.dir/main.cpp.o
src/executable: src/CMakeFiles/executable.dir/build.make
src/executable: src/CMakeFiles/executable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable executable"
	cd /home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/executable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/executable.dir/build: src/executable

.PHONY : src/CMakeFiles/executable.dir/build

src/CMakeFiles/executable.dir/requires: src/CMakeFiles/executable.dir/main.cpp.o.requires

.PHONY : src/CMakeFiles/executable.dir/requires

src/CMakeFiles/executable.dir/clean:
	cd /home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/executable.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/executable.dir/clean

src/CMakeFiles/executable.dir/depend:
	cd /home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thekatze/CLionProjects/shvrdengine-test /home/thekatze/CLionProjects/shvrdengine-test/src /home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug /home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug/src /home/thekatze/CLionProjects/shvrdengine-test/cmake-build-debug/src/CMakeFiles/executable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/executable.dir/depend
