
#ifndef SYNAPSE_OPTICAL_STIM_H_
#define SYNAPSE_OPTICAL_STIM_H_

#include "synapse/node.h"
#include <vector>
#include <cstdint>

struct OpticalStimInfo {
  uint32_t pixel_count
  std::vector<uint8_t> bit_width;
  std::vector<uint8_t> sample_rate;
  std::vector<uint8_t> gain;
};

struct OpticalStimConfig {
  uint32_t peripheral_id;
  std::vector<bool> pixel_mask;
  uint8_t bit_width;
  uint8_t sample_rate; // frame rate
  uint8_t gain;
};

#endif  // SYNAPSE_OPTICAL_STIM_H_
