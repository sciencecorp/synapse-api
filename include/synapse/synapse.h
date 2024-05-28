#ifndef SYNAPSE_H_
#define SYNAPSE_H_

#include <map>
#include <memory>
#include <vector>

#include "synapse/status.h"
#include "synapse/node.h"
#include "synapse/signal_chain.h"
#include "synapse/device.h"

#include <grpcpp/grpcpp.h>
#include "synapse.grpc.pb.h"


namespace synapse {

class Device;

struct SynapsePeripheral {
  NodeType peripheral_type;
  uint32_t peripheral_id;
  NodeInfo peripheral_info;
};

class Synapse {
public:
    Synapse(std::shared_ptr<grpc::Channel> channel);

    Status list_devices(std::vector<std::unique_ptr<Device>> *devices);

private:
    std::unique_ptr<proto_synapse::SynapseServer::Stub> stub_;
};

// TODO: helper to convert buf to *data_type

}  // namespace synapse

#endif  // SYNAPSE_H_
