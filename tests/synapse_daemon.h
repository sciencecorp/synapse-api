#ifndef SYNAPSE_SERVER_H
#define SYNAPSE_SERVER_H

#include <grpcpp/grpcpp.h>
#include "synapse.grpc.pb.h"

class SynapseServerImpl final : public proto_synapse::SynapseServer::Service {
public:
    grpc::Status ListDevices(grpc::ServerContext* context, const proto_synapse::ListDevicesRequest* request, grpc::ServerWriter<proto_synapse::DeviceInfo>* writer) override;
};

#endif // SYNAPSE_SERVER_H


