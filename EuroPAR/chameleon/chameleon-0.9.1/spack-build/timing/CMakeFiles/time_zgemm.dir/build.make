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
include timing/CMakeFiles/time_zgemm.dir/depend.make

# Include the progress variables for this target.
include timing/CMakeFiles/time_zgemm.dir/progress.make

# Include the compile flags for this target's objects.
include timing/CMakeFiles/time_zgemm.dir/flags.make

timing/time_zgemm.c: ../timing/time_zgemm.c
timing/time_zgemm.c: ../cmake_modules/morse/precision_generator/codegen.py
timing/time_zgemm.c: ../cmake_modules/morse/precision_generator/subs.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating time_zgemm.c"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/cmake-3.7.2-wxxosgus6wenpd7b6wowwmtx3dii66m7/bin/cmake -E remove -f time_zgemm.c && /usr/bin/python /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/cmake_modules/morse/precision_generator/codegen.py -f /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/timing/time_zgemm.c -p z -P ./ && chmod a-w time_zgemm.c

timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o: timing/CMakeFiles/time_zgemm.dir/flags.make
timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o: timing/time_zgemm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_z -o CMakeFiles/time_zgemm.dir/time_zgemm.c.o   -c /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/time_zgemm.c

timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/time_zgemm.dir/time_zgemm.c.i"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_z -E /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/time_zgemm.c > CMakeFiles/time_zgemm.dir/time_zgemm.c.i

timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/time_zgemm.dir/time_zgemm.c.s"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_z -S /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/time_zgemm.c -o CMakeFiles/time_zgemm.dir/time_zgemm.c.s

timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o.requires:

.PHONY : timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o.requires

timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o.provides: timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o.requires
	$(MAKE) -f timing/CMakeFiles/time_zgemm.dir/build.make timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o.provides.build
.PHONY : timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o.provides

timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o.provides.build: timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o


# Object files for target time_zgemm
time_zgemm_OBJECTS = \
"CMakeFiles/time_zgemm.dir/time_zgemm.c.o"

# External object files for target time_zgemm
time_zgemm_EXTERNAL_OBJECTS =

timing/time_zgemm: timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o
timing/time_zgemm: timing/CMakeFiles/time_zgemm.dir/build.make
timing/time_zgemm: compute/libchameleon.so
timing/time_zgemm: timing/libchameleon_timing.a
timing/time_zgemm: runtime/starpu/libchameleon_starpu.so
timing/time_zgemm: /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib/libstarpumpi-1.2.so
timing/time_zgemm: /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib/libstarpu-1.2.so
timing/time_zgemm: coreblas/compute/libcoreblas.so
timing/time_zgemm: /usr/lib64/libm.so
timing/time_zgemm: /usr/lib64/librt.so
timing/time_zgemm: /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib/libmpi.so
timing/time_zgemm: timing/CMakeFiles/time_zgemm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking Fortran executable time_zgemm"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/time_zgemm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
timing/CMakeFiles/time_zgemm.dir/build: timing/time_zgemm

.PHONY : timing/CMakeFiles/time_zgemm.dir/build

timing/CMakeFiles/time_zgemm.dir/requires: timing/CMakeFiles/time_zgemm.dir/time_zgemm.c.o.requires

.PHONY : timing/CMakeFiles/time_zgemm.dir/requires

timing/CMakeFiles/time_zgemm.dir/clean:
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && $(CMAKE_COMMAND) -P CMakeFiles/time_zgemm.dir/cmake_clean.cmake
.PHONY : timing/CMakeFiles/time_zgemm.dir/clean

timing/CMakeFiles/time_zgemm.dir/depend: timing/time_zgemm.c
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1 /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/timing /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/CMakeFiles/time_zgemm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : timing/CMakeFiles/time_zgemm.dir/depend

