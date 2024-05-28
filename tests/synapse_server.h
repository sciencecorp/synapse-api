#ifndef SYNAPSE_SERVER_H
#define SYNAPSE_SERVER_H

#include <grpcpp/grpcpp.h>
#include "synapse.grpc.pb.h"

class SynapseServerImpl final : public SynapseServer::Service {
public:
    grpc::Status ListDevices(grpc::ServerContext* context, const ListDevicesRequest* request, grpc::ServerWriter<DeviceInfo>* writer) override;
};

#endif // SYNAPSE_SERVER_H


