#!/bin/bash
set -e
# Check if protoc is installed
if ! command -v protoc &> /dev/null
then
    echo "protoc could not be found. Please install it to proceed."
    exit 1
fi

mkdir -p /tmp/proto_compiled

PROTO_FILES=$(find . -name "*.proto")
echo "Compiling proto files: $PROTO_FILES"

protoc --proto_path=. $PROTO_FILES --cpp_out=/tmp/proto_compiled --fatal_warnings

echo "Protobuf compilation completed."