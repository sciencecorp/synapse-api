#ifndef SYNAPSE_ELEC_STIM_H_
#define SYNAPSE_ELEC_STIM_H_

#include <vector>
#include <cstdint>

struct ElectricalStimInfo {
  uint32_t ch_count;
  std::vector<uint8_t> sample_rate;
  std::vector<uint8_t> bit_width;
  std::vector<uint8_t> lsb;
};

struct ElectricalStimConfig {
  uint32_t peripheral_id;
  std::vector<bool> ch_mask;
  uint8_t sample_rate;
  uint8_t bit_width;
  uint8_t lsb;
};

#endif  // SYNAPSE_ELEC_STIM_H_
