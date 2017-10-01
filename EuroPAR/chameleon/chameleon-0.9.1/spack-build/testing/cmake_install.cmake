# Install script for directory: /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/testing

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
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/stesting" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/stesting")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/stesting"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/stesting")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/testing/stesting")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/stesting" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/stesting")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/stesting"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/stesting")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/dtesting" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/dtesting")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/dtesting"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/dtesting")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/testing/dtesting")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/dtesting" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/dtesting")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/dtesting"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/dtesting")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ctesting" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ctesting")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ctesting"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ctesting")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/testing/ctesting")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ctesting" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ctesting")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ctesting"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ctesting")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ztesting" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ztesting")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ztesting"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ztesting")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/testing/ztesting")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ztesting" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ztesting")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ztesting"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/ztesting")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing/morse_testing_starpu.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/testing" TYPE FILE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/testing/morse_testing_starpu.py")
endif()

