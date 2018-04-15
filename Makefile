# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thiagofsr/Hacking/CPUSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thiagofsr/Hacking/CPUSimulator

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/local/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/thiagofsr/Hacking/CPUSimulator/CMakeFiles /home/thiagofsr/Hacking/CPUSimulator/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/thiagofsr/Hacking/CPUSimulator/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named CPUSimulator

# Build rule for target.
CPUSimulator: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 CPUSimulator
.PHONY : CPUSimulator

# fast build rule for target.
CPUSimulator/fast:
	$(MAKE) -f CMakeFiles/CPUSimulator.dir/build.make CMakeFiles/CPUSimulator.dir/build
.PHONY : CPUSimulator/fast

CPU.o: CPU.cpp.o

.PHONY : CPU.o

# target to build an object file
CPU.cpp.o:
	$(MAKE) -f CMakeFiles/CPUSimulator.dir/build.make CMakeFiles/CPUSimulator.dir/CPU.cpp.o
.PHONY : CPU.cpp.o

CPU.i: CPU.cpp.i

.PHONY : CPU.i

# target to preprocess a source file
CPU.cpp.i:
	$(MAKE) -f CMakeFiles/CPUSimulator.dir/build.make CMakeFiles/CPUSimulator.dir/CPU.cpp.i
.PHONY : CPU.cpp.i

CPU.s: CPU.cpp.s

.PHONY : CPU.s

# target to generate assembly for a file
CPU.cpp.s:
	$(MAKE) -f CMakeFiles/CPUSimulator.dir/build.make CMakeFiles/CPUSimulator.dir/CPU.cpp.s
.PHONY : CPU.cpp.s

Memory.o: Memory.cpp.o

.PHONY : Memory.o

# target to build an object file
Memory.cpp.o:
	$(MAKE) -f CMakeFiles/CPUSimulator.dir/build.make CMakeFiles/CPUSimulator.dir/Memory.cpp.o
.PHONY : Memory.cpp.o

Memory.i: Memory.cpp.i

.PHONY : Memory.i

# target to preprocess a source file
Memory.cpp.i:
	$(MAKE) -f CMakeFiles/CPUSimulator.dir/build.make CMakeFiles/CPUSimulator.dir/Memory.cpp.i
.PHONY : Memory.cpp.i

Memory.s: Memory.cpp.s

.PHONY : Memory.s

# target to generate assembly for a file
Memory.cpp.s:
	$(MAKE) -f CMakeFiles/CPUSimulator.dir/build.make CMakeFiles/CPUSimulator.dir/Memory.cpp.s
.PHONY : Memory.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/CPUSimulator.dir/build.make CMakeFiles/CPUSimulator.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/CPUSimulator.dir/build.make CMakeFiles/CPUSimulator.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/CPUSimulator.dir/build.make CMakeFiles/CPUSimulator.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... CPUSimulator"
	@echo "... CPU.o"
	@echo "... CPU.i"
	@echo "... CPU.s"
	@echo "... Memory.o"
	@echo "... Memory.i"
	@echo "... Memory.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

