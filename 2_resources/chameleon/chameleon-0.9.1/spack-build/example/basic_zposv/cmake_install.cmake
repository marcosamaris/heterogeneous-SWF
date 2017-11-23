# Install script for directory: /tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/example/basic_zposv

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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_morse_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_morse_functions")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_morse_functions"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/cposv_morse_functions")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_morse_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_morse_functions")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_morse_functions"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_morse_functions")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_morse_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_morse_functions")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_morse_functions"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/sposv_morse_functions")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_morse_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_morse_functions")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_morse_functions"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_morse_functions")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_morse_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_morse_functions")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_morse_functions"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/zposv_morse_functions")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_morse_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_morse_functions")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_morse_functions"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_morse_functions")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_morse_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_morse_functions")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_morse_functions"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/dposv_morse_functions")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_morse_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_morse_functions")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_morse_functions"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_morse_functions")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_users_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_users_functions")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_users_functions"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/cposv_users_functions")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_users_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_users_functions")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_users_functions"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/cposv_users_functions")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_users_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_users_functions")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_users_functions"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/sposv_users_functions")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_users_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_users_functions")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_users_functions"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/sposv_users_functions")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_users_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_users_functions")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_users_functions"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/zposv_users_functions")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_users_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_users_functions")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_users_functions"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/zposv_users_functions")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_users_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_users_functions")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_users_functions"
         RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv" TYPE EXECUTABLE FILES "/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/example/basic_zposv/dposv_users_functions")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_users_functions" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_users_functions")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_users_functions"
         OLD_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/compute:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/runtime/starpu:/tmp/marcos/spack-stage/spack-stage-fPQgje/chameleon-0.9.1/spack-build/coreblas/compute:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openmpi-2.0.1-wmrycolmrlgieebzmb7vbndworuorggr/lib:"
         NEW_RPATH "/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/chameleon-trunk-jod3fdqodfjwcdh6xa26ln2eg7vankci/lib:-L/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/openblas-0.2.19-ucyililz2mufocy7t5245pozxecbyfc7:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/hwloc-1.11.6-4f6amaulmun4f2wg2rvyhinnfq7e4msj/lib:/home/marcos/chameleon/spack/opt/spack/linux-x86_64/gcc-4.8.5/starpu-1.2.1-b3ym3ekzbvawzmi5ft7u4wsoomckww6p/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/chameleon/example/basic_zposv/dposv_users_functions")
    endif()
  endif()
endif()

