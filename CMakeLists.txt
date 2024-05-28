cmake_minimum_required(VERSION 3.20.1)
project(libsynapse VERSION 0.1.0 LANGUAGES CXX)

# vcpkg dependencies
find_package(fmt CONFIG REQUIRED)
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Proto files
set(PROTO_FILES
    ${CMAKE_SOURCE_DIR}/proto/node.proto
    ${CMAKE_SOURCE_DIR}/proto/signal_chain.proto
    ${CMAKE_SOURCE_DIR}/proto/device.proto
    ${CMAKE_SOURCE_DIR}/proto/synapse.proto
)

# Ensure the protobuf and grpc plugins are found
if(NOT DEFINED Protobuf_PROTOC_EXECUTABLE)
    message(FATAL_ERROR "Protobuf compiler (protoc) not found.")
endif()

find_program(GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)  # Use find_program to locate the gRPC plugin
if(NOT GRPC_CPP_PLUGIN_EXECUTABLE)
    message(FATAL_ERROR "gRPC plugin for protoc not found.")
endif()

# Create the proto output directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/proto)

# Generate C++ source files from proto files
foreach(proto_file ${PROTO_FILES})
    get_filename_component(proto_name ${proto_file} NAME_WE)

    set(proto_src "${CMAKE_BINARY_DIR}/proto/${proto_name}.pb.cc")
    set(proto_hdr "${CMAKE_BINARY_DIR}/proto/${proto_name}.pb.h")
    set(grpc_src "${CMAKE_BINARY_DIR}/proto/${proto_name}.grpc.pb.cc")
    set(grpc_hdr "${CMAKE_BINARY_DIR}/proto/${proto_name}.grpc.pb.h")

    add_custom_command(
        OUTPUT ${proto_src} ${proto_hdr}
        COMMAND ${Protobuf_PROTOC_EXECUTABLE}
        ARGS --cpp_out=${CMAKE_BINARY_DIR}/proto
             -I${CMAKE_SOURCE_DIR}/proto
             ${proto_file}
        DEPENDS ${proto_file}
    )

    add_custom_command(
        OUTPUT ${grpc_src} ${grpc_hdr}
        COMMAND ${Protobuf_PROTOC_EXECUTABLE}
        ARGS --grpc_out=${CMAKE_BINARY_DIR}/proto
             --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN_EXECUTABLE}
             -I${CMAKE_SOURCE_DIR}/proto
             ${proto_file}
        DEPENDS ${proto_file}
    )

    list(APPEND PROTO_SRCS ${proto_src})
    list(APPEND PROTO_HDRS ${proto_hdr})
    list(APPEND GRPC_SRCS ${grpc_src})
    list(APPEND GRPC_HDRS ${grpc_hdr})
endforeach()

include_directories(${CMAKE_BINARY_DIR}/proto) # Generated proto files

# Source files
set(SOURCES
    src/synapse.cpp
    src/device.cpp
    tests/synapse_server.cpp
    ${PROTO_SRCS}
    ${GRPC_SRCS}
)

# Executable
add_executable(libsynapse ${SOURCES} tests/client_main.cpp)
add_executable(server ${SOURCES} tests/server_main.cpp)

# Link libraries
target_link_libraries(libsynapse 
                      PRIVATE 
                      fmt::fmt
                      gRPC::grpc++
                      protobuf::libprotobuf
                      )

                  
# Link libraries
target_link_libraries(server
                      PRIVATE 
                      fmt::fmt
                      gRPC::grpc++
                      protobuf::libprotobuf
                      )


