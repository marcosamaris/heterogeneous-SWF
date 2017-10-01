# Install script for directory: /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/chameleon/control" TYPE FILE FILES
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/async.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/auxiliary.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/bulge.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/common.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/context.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/descriptor.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/gkkleader.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/global.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/morsewinthread.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/tile.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/control/workspace.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/control/compute_c.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/control/compute_s.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/control/compute_z.h"
    "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/control/compute_d.h"
    )
endif()

