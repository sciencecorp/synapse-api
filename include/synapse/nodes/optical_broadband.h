#ifndef SYNAPSE_OPTICAL_BROADBAND_H_
#define SYNAPSE_OPTICAL_BROADBAND_H_

#include <vector>
#include <cstdint>

struct OpticalBroadbandInfo {
  uint32_t pixel_count;
  std::vector<uint8_t> bit_width;
  std::vector<uint8_t> sample_rate;
  std::vector<uint8_t> gain;
};

struct OpticalBroadbandConfig {
  std::vector<bool> pixel_mask;
  uint8_t bit_width;
  uint8_t sample_rate;
  uint8_t gain;
};

#endif  // SYNAPSE_OPTICAL_BROADBAND_H_
