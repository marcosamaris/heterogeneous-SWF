# Install script for directory: /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/example/lapack_to_morse

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
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step1" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step1")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step1"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step1")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/lapack_to_morse/step1")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step1" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step1")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step1"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step1")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step2")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step2"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step2")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/lapack_to_morse/step2")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step2")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step2"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step2")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step3" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step3")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step3"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step3")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/lapack_to_morse/step3")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step3" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step3")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step3"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step3")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step4" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step4")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step4"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step4")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/lapack_to_morse/step4")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step4" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step4")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step4"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step4")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step5" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step5")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step5"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step5")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/lapack_to_morse/step5")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step5" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step5")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step5"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step5")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step6" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step6")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step6"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step6")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/lapack_to_morse/step6")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step6" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step6")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step6"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step6")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step0"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step0")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/lapack_to_morse/step0")
  if(EXISTS "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step0"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib/chameleon/example/lapack_to_morse/step0")
    endif()
  endif()
endif()

