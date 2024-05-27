#ifndef SYNAPSE_H_
#define SYNAPSE_H_

#include <map>
#include <memory>
#include <vector>

#include "synapse/status.h"
#include "synapse/node.h"
#include "synapse/signal_chain.h"
#include "synapse/device.h"

namespace synapse {

struct SynapsePeripheral {
  NodeType peripheral_type;
  uint32_t peripheral_id;
  NodeInfo peripheral_info;
};


// Discover availible devices and enumerate the tree of each one
Status list_devices(std::vector<std::unique_ptr<Device>> *devices);

// TODO: helper to convert buf to *data_type

}  // namespace synapse

#endif  // SYNAPSE_H_
