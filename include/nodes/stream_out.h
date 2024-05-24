#ifndef SYNAPSE_STREAM_OUT_H_
#define SYNAPSE_STREAM_OUT_H_

#include "synapse/node.h"
#include <vector>
#include <cstdint>

namespace synapse {

struct StreamOutInfo{
  uint32_t ch_count;
};

struct StreamOutConfig {
  std::vector<bool> ch_mask;
};

}
#endif  // SYNAPSE_STREAM_OUT_H_


