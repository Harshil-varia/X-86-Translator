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
CMAKE_SOURCE_DIR = /tmp/tmp.7Pm4KfxYkL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.7Pm4KfxYkL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/xtra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xtra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xtra.dir/flags.make

CMakeFiles/xtra.dir/main.c.o: CMakeFiles/xtra.dir/flags.make
CMakeFiles/xtra.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.7Pm4KfxYkL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/xtra.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xtra.dir/main.c.o -c /tmp/tmp.7Pm4KfxYkL/main.c

CMakeFiles/xtra.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xtra.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.7Pm4KfxYkL/main.c > CMakeFiles/xtra.dir/main.c.i

CMakeFiles/xtra.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xtra.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.7Pm4KfxYkL/main.c -o CMakeFiles/xtra.dir/main.c.s

CMakeFiles/xtra.dir/xtra.c.o: CMakeFiles/xtra.dir/flags.make
CMakeFiles/xtra.dir/xtra.c.o: ../xtra.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.7Pm4KfxYkL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/xtra.dir/xtra.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xtra.dir/xtra.c.o -c /tmp/tmp.7Pm4KfxYkL/xtra.c

CMakeFiles/xtra.dir/xtra.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xtra.dir/xtra.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.7Pm4KfxYkL/xtra.c > CMakeFiles/xtra.dir/xtra.c.i

CMakeFiles/xtra.dir/xtra.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xtra.dir/xtra.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.7Pm4KfxYkL/xtra.c -o CMakeFiles/xtra.dir/xtra.c.s

# Object files for target xtra
xtra_OBJECTS = \
"CMakeFiles/xtra.dir/main.c.o" \
"CMakeFiles/xtra.dir/xtra.c.o"

# External object files for target xtra
xtra_EXTERNAL_OBJECTS =

xtra: CMakeFiles/xtra.dir/main.c.o
xtra: CMakeFiles/xtra.dir/xtra.c.o
xtra: CMakeFiles/xtra.dir/build.make
xtra: CMakeFiles/xtra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.7Pm4KfxYkL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable xtra"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xtra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xtra.dir/build: xtra

.PHONY : CMakeFiles/xtra.dir/build

CMakeFiles/xtra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xtra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xtra.dir/clean

CMakeFiles/xtra.dir/depend:
	cd /tmp/tmp.7Pm4KfxYkL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.7Pm4KfxYkL /tmp/tmp.7Pm4KfxYkL /tmp/tmp.7Pm4KfxYkL/cmake-build-debug /tmp/tmp.7Pm4KfxYkL/cmake-build-debug /tmp/tmp.7Pm4KfxYkL/cmake-build-debug/CMakeFiles/xtra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xtra.dir/depend

