cmake_minimum_required(VERSION 3.20.1)
project(libsynapse VERSION 0.1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Protobufs
# set(PROTO_FILES
    # ${CMAKE_SOURCE_DIR}/proto/device.proto
    # ${CMAKE_SOURCE_DIR}/proto/node.proto
    # ${CMAKE_SOURCE_DIR}/proto/signal_chain.proto
    # ${CMAKE_SOURCE_DIR}/proto/synapse.proto
# )

# find_package(Protobuf REQUIRED)
# protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

# Source files
# set(SOURCES
    # src/device.cpp
    # src/synapse.cpp
    # ${PROTO_SRCS}
# )

# Executable
add_executable(synapse_project ${SOURCES} tests/main.cpp)

# Link libraries
# target_link_libraries(synapse_project ${PROTOBUF_LIBRARIES})
