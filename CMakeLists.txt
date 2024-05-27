cmake_minimum_required(VERSION 3.20.1)
project(libsynapse VERSION 0.1.0 LANGUAGES CXX)

# vcpkg dependencies
find_package(fmt CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Executable
add_executable(libsynapse ${SOURCES} tests/main.cpp)

# Link libraries
target_link_libraries(libsynapse PRIVATE fmt::fmt)

