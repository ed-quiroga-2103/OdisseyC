# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/eduardo/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/eduardo/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/eduardo/Documents/Datos II/GenericServer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/eduardo/Documents/Datos II/GenericServer/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/OddServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OddServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OddServer.dir/flags.make

CMakeFiles/OddServer.dir/main.cpp.o: CMakeFiles/OddServer.dir/flags.make
CMakeFiles/OddServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/eduardo/Documents/Datos II/GenericServer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OddServer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OddServer.dir/main.cpp.o -c "/home/eduardo/Documents/Datos II/GenericServer/main.cpp"

CMakeFiles/OddServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OddServer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/eduardo/Documents/Datos II/GenericServer/main.cpp" > CMakeFiles/OddServer.dir/main.cpp.i

CMakeFiles/OddServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OddServer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/eduardo/Documents/Datos II/GenericServer/main.cpp" -o CMakeFiles/OddServer.dir/main.cpp.s

CMakeFiles/OddServer.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/OddServer.dir/main.cpp.o.requires

CMakeFiles/OddServer.dir/main.cpp.o.provides: CMakeFiles/OddServer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/OddServer.dir/build.make CMakeFiles/OddServer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/OddServer.dir/main.cpp.o.provides

CMakeFiles/OddServer.dir/main.cpp.o.provides.build: CMakeFiles/OddServer.dir/main.cpp.o


CMakeFiles/OddServer.dir/mainServer.cpp.o: CMakeFiles/OddServer.dir/flags.make
CMakeFiles/OddServer.dir/mainServer.cpp.o: ../mainServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/eduardo/Documents/Datos II/GenericServer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OddServer.dir/mainServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OddServer.dir/mainServer.cpp.o -c "/home/eduardo/Documents/Datos II/GenericServer/mainServer.cpp"

CMakeFiles/OddServer.dir/mainServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OddServer.dir/mainServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/eduardo/Documents/Datos II/GenericServer/mainServer.cpp" > CMakeFiles/OddServer.dir/mainServer.cpp.i

CMakeFiles/OddServer.dir/mainServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OddServer.dir/mainServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/eduardo/Documents/Datos II/GenericServer/mainServer.cpp" -o CMakeFiles/OddServer.dir/mainServer.cpp.s

CMakeFiles/OddServer.dir/mainServer.cpp.o.requires:

.PHONY : CMakeFiles/OddServer.dir/mainServer.cpp.o.requires

CMakeFiles/OddServer.dir/mainServer.cpp.o.provides: CMakeFiles/OddServer.dir/mainServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/OddServer.dir/build.make CMakeFiles/OddServer.dir/mainServer.cpp.o.provides.build
.PHONY : CMakeFiles/OddServer.dir/mainServer.cpp.o.provides

CMakeFiles/OddServer.dir/mainServer.cpp.o.provides.build: CMakeFiles/OddServer.dir/mainServer.cpp.o


# Object files for target OddServer
OddServer_OBJECTS = \
"CMakeFiles/OddServer.dir/main.cpp.o" \
"CMakeFiles/OddServer.dir/mainServer.cpp.o"

# External object files for target OddServer
OddServer_EXTERNAL_OBJECTS =

OddServer: CMakeFiles/OddServer.dir/main.cpp.o
OddServer: CMakeFiles/OddServer.dir/mainServer.cpp.o
OddServer: CMakeFiles/OddServer.dir/build.make
OddServer: CMakeFiles/OddServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/eduardo/Documents/Datos II/GenericServer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OddServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OddServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OddServer.dir/build: OddServer

.PHONY : CMakeFiles/OddServer.dir/build

CMakeFiles/OddServer.dir/requires: CMakeFiles/OddServer.dir/main.cpp.o.requires
CMakeFiles/OddServer.dir/requires: CMakeFiles/OddServer.dir/mainServer.cpp.o.requires

.PHONY : CMakeFiles/OddServer.dir/requires

CMakeFiles/OddServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OddServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OddServer.dir/clean

CMakeFiles/OddServer.dir/depend:
	cd "/home/eduardo/Documents/Datos II/GenericServer/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/eduardo/Documents/Datos II/GenericServer" "/home/eduardo/Documents/Datos II/GenericServer" "/home/eduardo/Documents/Datos II/GenericServer/cmake-build-debug" "/home/eduardo/Documents/Datos II/GenericServer/cmake-build-debug" "/home/eduardo/Documents/Datos II/GenericServer/cmake-build-debug/CMakeFiles/OddServer.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/OddServer.dir/depend

