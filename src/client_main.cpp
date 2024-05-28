#include "synapse_client.h"

int main(int argc, char** argv) {
    SynapseClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    client.ListDevices();

    return 0;
}

