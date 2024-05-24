#ifndef SYNAPSE_STREAM_IN_H_
#define SYNAPSE_STREAM_IN_H_

#include "synapse/node.h"
#include <vector>
#include <cstdint>

namespace synapse {

struct StreamInInfo{
  std::vector<std::vector<uint32_t>> shape;
};

struct StreamInConfig {
  std::vector<uint32_t> shape;
};

}

#endif  // SYNAPSE_STREAM_IN_H_
