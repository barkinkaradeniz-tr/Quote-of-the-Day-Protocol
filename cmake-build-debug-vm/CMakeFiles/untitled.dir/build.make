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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tkn/Documents/RNVS/Block2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tkn/Documents/RNVS/Block2/cmake-build-debug-vm

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/client.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/client.c.o: ../client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tkn/Documents/RNVS/Block2/cmake-build-debug-vm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled.dir/client.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/client.c.o   -c /home/tkn/Documents/RNVS/Block2/client.c

CMakeFiles/untitled.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/client.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tkn/Documents/RNVS/Block2/client.c > CMakeFiles/untitled.dir/client.c.i

CMakeFiles/untitled.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/client.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tkn/Documents/RNVS/Block2/client.c -o CMakeFiles/untitled.dir/client.c.s

CMakeFiles/untitled.dir/client.c.o.requires:

.PHONY : CMakeFiles/untitled.dir/client.c.o.requires

CMakeFiles/untitled.dir/client.c.o.provides: CMakeFiles/untitled.dir/client.c.o.requires
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/client.c.o.provides.build
.PHONY : CMakeFiles/untitled.dir/client.c.o.provides

CMakeFiles/untitled.dir/client.c.o.provides.build: CMakeFiles/untitled.dir/client.c.o


# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/client.c.o"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled: CMakeFiles/untitled.dir/client.c.o
untitled: CMakeFiles/untitled.dir/build.make
untitled: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tkn/Documents/RNVS/Block2/cmake-build-debug-vm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable untitled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled

.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/requires: CMakeFiles/untitled.dir/client.c.o.requires

.PHONY : CMakeFiles/untitled.dir/requires

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	cd /home/tkn/Documents/RNVS/Block2/cmake-build-debug-vm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tkn/Documents/RNVS/Block2 /home/tkn/Documents/RNVS/Block2 /home/tkn/Documents/RNVS/Block2/cmake-build-debug-vm /home/tkn/Documents/RNVS/Block2/cmake-build-debug-vm /home/tkn/Documents/RNVS/Block2/cmake-build-debug-vm/CMakeFiles/untitled.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend

