#ifndef SYNAPSE_CLIENT_H
#define SYNAPSE_CLIENT_H

#include <grpcpp/grpcpp.h>
#include "synapse.grpc.pb.h"

class SynapseClient {
public:
    SynapseClient(std::shared_ptr<grpc::Channel> channel);
    void ListDevices();

private:
    std::unique_ptr<SynapseServer::Stub> stub_;
};

#endif // SYNAPSE_CLIENT_H
