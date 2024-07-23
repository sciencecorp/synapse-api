# Synapse API 1.0

Synapse uses gRPC for its control plane API and UDP for streaming data.

To build, install `grpcio-tools` and then:

```
python -m grpc_tools.protoc -I. --python_out=py --grpc_python_out=py ./api/**/*.proto
```
