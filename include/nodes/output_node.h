#pragma once
#include <synapse/utils.h>

#include <tl/expected.hpp>

#include "synapse/node.h"

namespace synapse {

class OutputNode : public Node {
 public:
  OutputNode(NodeType node_type) : Node(node_type){};

  virtual tl::expected<std::array<uint16_t, 1024>, synapse::status> read() = 0;
};

}  // namespace synapse