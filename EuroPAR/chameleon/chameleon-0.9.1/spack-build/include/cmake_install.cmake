# Install script for directory: /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/chameleon" TYPE FILE FILES
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/include/morse_constants.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/include/morse_fortran.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/include/morse_kernels.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/include/morse_simulate.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/include/morse_struct.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/include/morse_types.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/include/runtime.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/morse_s.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/morse_c.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/morse_z.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/morse_d.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/morse_ds.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/morse_zc.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/runtime_s.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/runtime_c.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/runtime_z.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/runtime_d.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/runtime_ds.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/runtime_zc.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/morse.h"
    )
endif()

