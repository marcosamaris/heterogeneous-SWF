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
include timing/CMakeFiles/time_sgetrf_nopiv.dir/depend.make

# Include the progress variables for this target.
include timing/CMakeFiles/time_sgetrf_nopiv.dir/progress.make

# Include the compile flags for this target's objects.
include timing/CMakeFiles/time_sgetrf_nopiv.dir/flags.make

timing/time_sgetrf_nopiv.c: ../timing/time_zgetrf_nopiv.c
timing/time_sgetrf_nopiv.c: ../cmake_modules/morse/precision_generator/codegen.py
timing/time_sgetrf_nopiv.c: ../cmake_modules/morse/precision_generator/subs.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating time_sgetrf_nopiv.c"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/cmake-3.7.2-wxxosgus6wenpd7b6wowwmtx3dii66m7/bin/cmake -E remove -f time_sgetrf_nopiv.c && /usr/bin/python /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/cmake_modules/morse/precision_generator/codegen.py -f /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/timing/time_zgetrf_nopiv.c -p s -P ./ && chmod a-w time_sgetrf_nopiv.c

timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o: timing/CMakeFiles/time_sgetrf_nopiv.dir/flags.make
timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o: timing/time_sgetrf_nopiv.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_s -o CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o   -c /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/time_sgetrf_nopiv.c

timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.i"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_s -E /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/time_sgetrf_nopiv.c > CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.i

timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.s"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_s -S /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/time_sgetrf_nopiv.c -o CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.s

timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o.requires:

.PHONY : timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o.requires

timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o.provides: timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o.requires
	$(MAKE) -f timing/CMakeFiles/time_sgetrf_nopiv.dir/build.make timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o.provides.build
.PHONY : timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o.provides

timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o.provides.build: timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o


# Object files for target time_sgetrf_nopiv
time_sgetrf_nopiv_OBJECTS = \
"CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o"

# External object files for target time_sgetrf_nopiv
time_sgetrf_nopiv_EXTERNAL_OBJECTS =

timing/time_sgetrf_nopiv: timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o
timing/time_sgetrf_nopiv: timing/CMakeFiles/time_sgetrf_nopiv.dir/build.make
timing/time_sgetrf_nopiv: compute/libchameleon.so
timing/time_sgetrf_nopiv: timing/libchameleon_timing.a
timing/time_sgetrf_nopiv: runtime/starpu/libchameleon_starpu.so
timing/time_sgetrf_nopiv: /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib/libstarpumpi-1.2.so
timing/time_sgetrf_nopiv: /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib/libstarpu-1.2.so
timing/time_sgetrf_nopiv: coreblas/compute/libcoreblas.so
timing/time_sgetrf_nopiv: /usr/lib64/libm.so
timing/time_sgetrf_nopiv: /usr/lib64/librt.so
timing/time_sgetrf_nopiv: /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib/libmpi.so
timing/time_sgetrf_nopiv: timing/CMakeFiles/time_sgetrf_nopiv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking Fortran executable time_sgetrf_nopiv"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/time_sgetrf_nopiv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
timing/CMakeFiles/time_sgetrf_nopiv.dir/build: timing/time_sgetrf_nopiv

.PHONY : timing/CMakeFiles/time_sgetrf_nopiv.dir/build

timing/CMakeFiles/time_sgetrf_nopiv.dir/requires: timing/CMakeFiles/time_sgetrf_nopiv.dir/time_sgetrf_nopiv.c.o.requires

.PHONY : timing/CMakeFiles/time_sgetrf_nopiv.dir/requires

timing/CMakeFiles/time_sgetrf_nopiv.dir/clean:
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && $(CMAKE_COMMAND) -P CMakeFiles/time_sgetrf_nopiv.dir/cmake_clean.cmake
.PHONY : timing/CMakeFiles/time_sgetrf_nopiv.dir/clean

timing/CMakeFiles/time_sgetrf_nopiv.dir/depend: timing/time_sgetrf_nopiv.c
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1 /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/timing /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/CMakeFiles/time_sgetrf_nopiv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : timing/CMakeFiles/time_sgetrf_nopiv.dir/depend

