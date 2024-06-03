#ifndef SYNAPSE_NODES_ELEC_BROADBAND_H_
#define SYNAPSE_NODES_ELEC_BROADBAND_H_

#include <vector>
#include <cstdint>

namespace synapse {

  struct ElectricalBroadbandInfo {
    uint32_t ch_count;
    std::vector<uint8_t> bit_width;
    std::vector<uint8_t> sample_rate;
    std::vector<uint8_t> gain;
  };

  struct ElectricalBroadbandConfig {
    uint32_t peripheral_id; // add to other pys nodes
    std::vector<bool> ch_mask;
    uint8_t bit_width;
    uint8_t sample_rate;
    uint8_t gain;
  };

}  // namespace synapse
#endif  // SYNAPSE_NODES_ELEC_BROADBAND_H_





