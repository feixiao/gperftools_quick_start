cmake_minimum_required(VERSION 2.8.0)
project(gperftools)
#
#enable_testing()

add_definitions(
        "-W"
        "-fPIC"
        "-DPIC"
        "-Wall"
        "-fpermissive"
        "-Werror"
        #            "-Wshadow"
        "-Wpointer-arith"
        "-Waggregate-return"
        "-Wno-long-long"
        "-Wuninitialized"
        "-D_POSIX_PTHREAD_SEMANTICS"
        "-DFLOATING_POINT"
        "-Wno-narrowing"
        "-std=c++11"
)

if (${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    message(FATAL_ERROR "Please into another dir to build!")
endif()

#string(TOUPPER ${CMAKE_SYSTEM_NAME} CMAKE_SYSTEM_NAME)
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "current platform: Linux")
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message(STATUS "current platform: Darwin")
    set(CMAKE_MACOSX_RPATH build)
    add_definitions("-Wno-invalid-source-encoding")
    add_definitions("-Os")
    set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk")
    set(CMAKE_CXX_FLAGS "--sysroot ${CMAKE_OSX_SYSROOT} ${CMAKE_CXX_FLAGS}")

    # https://stackoverflow.com/questions/69803659/what-is-the-proper-way-to-build-for-macos-x86-64-using-cmake-on-apple-m1-arm
    set(CMAKE_OSX_ARCHITECTURES "x86_64")
else()
    message(FATAL_ERROR "unknown CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}")
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_MACOSX_RPATH build)
endif()

#add_subdirectory(lib)
#add_subdirectory(exe)

add_subdirectory(memory)