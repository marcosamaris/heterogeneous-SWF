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
include timing/CMakeFiles/chameleon_timing.dir/depend.make

# Include the progress variables for this target.
include timing/CMakeFiles/chameleon_timing.dir/progress.make

# Include the compile flags for this target's objects.
include timing/CMakeFiles/chameleon_timing.dir/flags.make

timing/timing_cauxiliary.c: ../timing/timing_zauxiliary.c
timing/timing_cauxiliary.c: ../cmake_modules/morse/precision_generator/codegen.py
timing/timing_cauxiliary.c: ../cmake_modules/morse/precision_generator/subs.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating timing_cauxiliary.c"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/cmake-3.7.2-wxxosgus6wenpd7b6wowwmtx3dii66m7/bin/cmake -E remove -f timing_cauxiliary.c && /usr/bin/python /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/cmake_modules/morse/precision_generator/codegen.py -f /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/timing/timing_zauxiliary.c -p c -P ./ && chmod a-w timing_cauxiliary.c

timing/timing_sauxiliary.c: ../timing/timing_zauxiliary.c
timing/timing_sauxiliary.c: ../cmake_modules/morse/precision_generator/codegen.py
timing/timing_sauxiliary.c: ../cmake_modules/morse/precision_generator/subs.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating timing_sauxiliary.c"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/cmake-3.7.2-wxxosgus6wenpd7b6wowwmtx3dii66m7/bin/cmake -E remove -f timing_sauxiliary.c && /usr/bin/python /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/cmake_modules/morse/precision_generator/codegen.py -f /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/timing/timing_zauxiliary.c -p s -P ./ && chmod a-w timing_sauxiliary.c

timing/timing_zauxiliary.c: ../timing/timing_zauxiliary.c
timing/timing_zauxiliary.c: ../cmake_modules/morse/precision_generator/codegen.py
timing/timing_zauxiliary.c: ../cmake_modules/morse/precision_generator/subs.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating timing_zauxiliary.c"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/cmake-3.7.2-wxxosgus6wenpd7b6wowwmtx3dii66m7/bin/cmake -E remove -f timing_zauxiliary.c && /usr/bin/python /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/cmake_modules/morse/precision_generator/codegen.py -f /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/timing/timing_zauxiliary.c -p z -P ./ && chmod a-w timing_zauxiliary.c

timing/timing_dauxiliary.c: ../timing/timing_zauxiliary.c
timing/timing_dauxiliary.c: ../cmake_modules/morse/precision_generator/codegen.py
timing/timing_dauxiliary.c: ../cmake_modules/morse/precision_generator/subs.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating timing_dauxiliary.c"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/cmake-3.7.2-wxxosgus6wenpd7b6wowwmtx3dii66m7/bin/cmake -E remove -f timing_dauxiliary.c && /usr/bin/python /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/cmake_modules/morse/precision_generator/codegen.py -f /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/timing/timing_zauxiliary.c -p d -P ./ && chmod a-w timing_dauxiliary.c

timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o: timing/CMakeFiles/chameleon_timing.dir/flags.make
timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o: timing/timing_cauxiliary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_c -o CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o   -c /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_cauxiliary.c

timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.i"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_c -E /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_cauxiliary.c > CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.i

timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.s"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_c -S /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_cauxiliary.c -o CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.s

timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o.requires:

.PHONY : timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o.requires

timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o.provides: timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o.requires
	$(MAKE) -f timing/CMakeFiles/chameleon_timing.dir/build.make timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o.provides.build
.PHONY : timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o.provides

timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o.provides.build: timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o


timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o: timing/CMakeFiles/chameleon_timing.dir/flags.make
timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o: timing/timing_sauxiliary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_s -o CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o   -c /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_sauxiliary.c

timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.i"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_s -E /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_sauxiliary.c > CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.i

timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.s"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_s -S /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_sauxiliary.c -o CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.s

timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o.requires:

.PHONY : timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o.requires

timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o.provides: timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o.requires
	$(MAKE) -f timing/CMakeFiles/chameleon_timing.dir/build.make timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o.provides.build
.PHONY : timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o.provides

timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o.provides.build: timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o


timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o: timing/CMakeFiles/chameleon_timing.dir/flags.make
timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o: timing/timing_zauxiliary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_z -o CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o   -c /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_zauxiliary.c

timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.i"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_z -E /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_zauxiliary.c > CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.i

timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.s"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_z -S /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_zauxiliary.c -o CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.s

timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o.requires:

.PHONY : timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o.requires

timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o.provides: timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o.requires
	$(MAKE) -f timing/CMakeFiles/chameleon_timing.dir/build.make timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o.provides.build
.PHONY : timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o.provides

timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o.provides.build: timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o


timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o: timing/CMakeFiles/chameleon_timing.dir/flags.make
timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o: timing/timing_dauxiliary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_d -o CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o   -c /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_dauxiliary.c

timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.i"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_d -E /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_dauxiliary.c > CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.i

timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.s"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && /home/marcos/chameleon/spack/lib/spack/env/gcc/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -DPRECISION_d -S /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/timing_dauxiliary.c -o CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.s

timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o.requires:

.PHONY : timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o.requires

timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o.provides: timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o.requires
	$(MAKE) -f timing/CMakeFiles/chameleon_timing.dir/build.make timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o.provides.build
.PHONY : timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o.provides

timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o.provides.build: timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o


# Object files for target chameleon_timing
chameleon_timing_OBJECTS = \
"CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o" \
"CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o" \
"CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o" \
"CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o"

# External object files for target chameleon_timing
chameleon_timing_EXTERNAL_OBJECTS =

timing/libchameleon_timing.a: timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o
timing/libchameleon_timing.a: timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o
timing/libchameleon_timing.a: timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o
timing/libchameleon_timing.a: timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o
timing/libchameleon_timing.a: timing/CMakeFiles/chameleon_timing.dir/build.make
timing/libchameleon_timing.a: timing/CMakeFiles/chameleon_timing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking Fortran static library libchameleon_timing.a"
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && $(CMAKE_COMMAND) -P CMakeFiles/chameleon_timing.dir/cmake_clean_target.cmake
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chameleon_timing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
timing/CMakeFiles/chameleon_timing.dir/build: timing/libchameleon_timing.a

.PHONY : timing/CMakeFiles/chameleon_timing.dir/build

timing/CMakeFiles/chameleon_timing.dir/requires: timing/CMakeFiles/chameleon_timing.dir/timing_cauxiliary.c.o.requires
timing/CMakeFiles/chameleon_timing.dir/requires: timing/CMakeFiles/chameleon_timing.dir/timing_sauxiliary.c.o.requires
timing/CMakeFiles/chameleon_timing.dir/requires: timing/CMakeFiles/chameleon_timing.dir/timing_zauxiliary.c.o.requires
timing/CMakeFiles/chameleon_timing.dir/requires: timing/CMakeFiles/chameleon_timing.dir/timing_dauxiliary.c.o.requires

.PHONY : timing/CMakeFiles/chameleon_timing.dir/requires

timing/CMakeFiles/chameleon_timing.dir/clean:
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing && $(CMAKE_COMMAND) -P CMakeFiles/chameleon_timing.dir/cmake_clean.cmake
.PHONY : timing/CMakeFiles/chameleon_timing.dir/clean

timing/CMakeFiles/chameleon_timing.dir/depend: timing/timing_cauxiliary.c
timing/CMakeFiles/chameleon_timing.dir/depend: timing/timing_sauxiliary.c
timing/CMakeFiles/chameleon_timing.dir/depend: timing/timing_zauxiliary.c
timing/CMakeFiles/chameleon_timing.dir/depend: timing/timing_dauxiliary.c
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1 /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/timing /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/CMakeFiles/chameleon_timing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : timing/CMakeFiles/chameleon_timing.dir/depend

