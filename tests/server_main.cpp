
#include <fmt/format.h>

#include "synapse/status.h"
#include "synapse/node.h"
#include "synapse/signal_chain.h"
#include "synapse/synapse.h"
#include "synapse/device.h"


#include <iostream>
#include <grpcpp/grpcpp.h>
#include "synapse_server.h"

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    SynapseServerImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}

