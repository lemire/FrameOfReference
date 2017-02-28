
cmake_minimum_required(VERSION 2.8.7)
if (NOT CMAKE_BUILD_TYPE)
                message(STATUS "No build type selected, default to Release")
                set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()
MESSAGE( STATUS "CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE} )

project(FrameOfReference CXX C)
set(PROJECT_URL "https://github.com/lemire/FrameOfReference")
set(PROJECT_DESCRIPTION "C++ library to pack and unpack vectors of integers having a small range of values using a technique called Frame of Reference")

### Next line would be ideal, but it does not work on all platforms:
###set(CMAKE_CXX_STANDARD 11)
####
set(CMAKE_CXX_FLAGS                "-Wall -std=c++11")


# library target
include_directories(include)
add_library(FrameOfReference STATIC ./src/bpacking.cpp
                                                                ${HEADERS}
                                                                )
enable_testing()


add_executable(unit src/test)
target_link_libraries(unit FrameOfReference)
add_test(unit unit ${PROJECT_SOURCE_DIR}/sampledata.txt )
