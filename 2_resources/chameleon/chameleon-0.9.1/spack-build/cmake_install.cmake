# Install script for directory: /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/chameleon.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/chameleon" TYPE FILE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/config.log")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/cmake_install.cmake")
  include("/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/include/cmake_install.cmake")
  include("/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/control/cmake_install.cmake")
  include("/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute/cmake_install.cmake")
  include("/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/cmake_install.cmake")
  include("/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/cmake_install.cmake")
  include("/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/testing/cmake_install.cmake")
  include("/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/timing/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
