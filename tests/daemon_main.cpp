
#include <fmt/format.h>

#include "synapse/status.h"
#include "synapse/node.h"
#include "synapse/signal_chain.h"
#include "synapse/synapse.h"
#include "synapse/device.h"


#include <iostream>
#include <grpcpp/grpcpp.h>
#include "synapse_daemon.h"

void RunServer() {
    std::string daemon_address("0.0.0.0:50052");
    SynapseServerImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(daemon_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> daemon(builder.BuildAndStart());
    std::cout << "Server listening on " << daemon_address << std::endl;

    daemon->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}

