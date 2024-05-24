#ifndef SYNAPSE_SIGNAL_CHAIN_H_
#define SYNAPSE_SIGNAL_CHAIN_H_

#include <vector>
#include <cstdint>
#include <atomic>
#include <map>
#include <synapse/node.h>
#include <synapse/nodes/output_node.h>

namespace synapse {

struct Connection {
  uint32_t from;
  uint32_t to;
};

class SignalChain {
 public:
  status add_node(NodeConfig node_config, uint32_t *node_id);
  status remove_node(uint32_t node_id);

  status connect(uint32_t from_id, uint32_t to_id);

  std::vector<Connection> get_connections(uint32_t node_id);

  std::map<uint32_t, NodeConfig> get_node_configs();

  status validate();

  bool empty();

 private:

  std::map<uint32_t, std::shared_ptr<Node>> nodes_;
  std::vector<Connection> connections_;
};

}  // namespace synapse

#endif // SYNAPSE_SIGNAL_CHAIN_H_
