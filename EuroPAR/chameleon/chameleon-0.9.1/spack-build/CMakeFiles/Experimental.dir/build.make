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

# Utility rule file for Experimental.

# Include the progress variables for this target.
include CMakeFiles/Experimental.dir/progress.make

CMakeFiles/Experimental:
	/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/cmake-3.7.2-wxxosgus6wenpd7b6wowwmtx3dii66m7/bin/ctest -D Experimental

Experimental: CMakeFiles/Experimental
Experimental: CMakeFiles/Experimental.dir/build.make

.PHONY : Experimental

# Rule to build all files generated by this target.
CMakeFiles/Experimental.dir/build: Experimental

.PHONY : CMakeFiles/Experimental.dir/build

CMakeFiles/Experimental.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Experimental.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Experimental.dir/clean

CMakeFiles/Experimental.dir/depend:
	cd /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1 /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1 /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/CMakeFiles/Experimental.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Experimental.dir/depend

