# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/cmake-3.7.2-wxxosgus6wenpd7b6wowwmtx3dii66m7/bin/cmake

# The command to remove a file.
RM = /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/cmake-3.7.2-wxxosgus6wenpd7b6wowwmtx3dii66m7/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build

# Include any dependencies generated for this target.
include example/basic_zposv/CMakeFiles/cposv_users_functions.dir/depend.make

# Include the progress variables for this target.
include example/basic_zposv/CMakeFiles/cposv_users_functions.dir/progress.make

# Include the compile flags for this target's objects.
include example/basic_zposv/CMakeFiles/cposv_users_functions.dir/flags.make

example/basic_zposv/cposv_users_functions.c: ../example/basic_zposv/zposv_users_functions.c
example/basic_zposv/cposv_users_functions.c: ../cmake_modules/morse/precision_generator/codegen.py
example/basic_zposv/cposv_users_functions.c: ../cmake_modules/morse/precision_generator/subs.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating cposv_users_functions.c"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv && /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/cmake-3.7.2-wxxosgus6wenpd7b6wowwmtx3dii66m7/bin/cmake -E remove -f cposv_users_functions.c && /usr/bin/python /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/cmake_modules/morse/precision_generator/codegen.py -f /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/example/basic_zposv/zposv_users_functions.c -p c -P ./ && chmod a-w cposv_users_functions.c

example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o: example/basic_zposv/CMakeFiles/cposv_users_functions.dir/flags.make
example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o: example/basic_zposv/cposv_users_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_c -o CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o   -c /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/cposv_users_functions.c

example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.i"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_c -E /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/cposv_users_functions.c > CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.i

example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.s"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_c -S /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/cposv_users_functions.c -o CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.s

example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o.requires:

.PHONY : example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o.requires

example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o.provides: example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o.requires
	$(MAKE) -f example/basic_zposv/CMakeFiles/cposv_users_functions.dir/build.make example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o.provides.build
.PHONY : example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o.provides

example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o.provides.build: example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o


# Object files for target cposv_users_functions
cposv_users_functions_OBJECTS = \
"CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o"

# External object files for target cposv_users_functions
cposv_users_functions_EXTERNAL_OBJECTS =

example/basic_zposv/cposv_users_functions: example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o
example/basic_zposv/cposv_users_functions: example/basic_zposv/CMakeFiles/cposv_users_functions.dir/build.make
example/basic_zposv/cposv_users_functions: compute/libchameleon.so
example/basic_zposv/cposv_users_functions: runtime/starpu/libchameleon_starpu.so
example/basic_zposv/cposv_users_functions: /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib/libstarpumpi-1.2.so
example/basic_zposv/cposv_users_functions: /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib/libstarpu-1.2.so
example/basic_zposv/cposv_users_functions: coreblas/compute/libcoreblas.so
example/basic_zposv/cposv_users_functions: /usr/lib64/libm.so
example/basic_zposv/cposv_users_functions: /usr/lib64/librt.so
example/basic_zposv/cposv_users_functions: /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib/libmpi.so
example/basic_zposv/cposv_users_functions: example/basic_zposv/CMakeFiles/cposv_users_functions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking Fortran executable cposv_users_functions"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cposv_users_functions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/basic_zposv/CMakeFiles/cposv_users_functions.dir/build: example/basic_zposv/cposv_users_functions

.PHONY : example/basic_zposv/CMakeFiles/cposv_users_functions.dir/build

example/basic_zposv/CMakeFiles/cposv_users_functions.dir/requires: example/basic_zposv/CMakeFiles/cposv_users_functions.dir/cposv_users_functions.c.o.requires

.PHONY : example/basic_zposv/CMakeFiles/cposv_users_functions.dir/requires

example/basic_zposv/CMakeFiles/cposv_users_functions.dir/clean:
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv && $(CMAKE_COMMAND) -P CMakeFiles/cposv_users_functions.dir/cmake_clean.cmake
.PHONY : example/basic_zposv/CMakeFiles/cposv_users_functions.dir/clean

example/basic_zposv/CMakeFiles/cposv_users_functions.dir/depend: example/basic_zposv/cposv_users_functions.c
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1 /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/example/basic_zposv /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/CMakeFiles/cposv_users_functions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/basic_zposv/CMakeFiles/cposv_users_functions.dir/depend

