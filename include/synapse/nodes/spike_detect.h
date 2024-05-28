#ifndef SYNAPSE_SPIKE_DETECT_H_
#define SYNAPSE_SPIKE_DETECT_H_

#include <vector>
#include <cstdint>

enum class spikeDetectMode : uint8_t {
  kThreshold = 0,
  kTemplate = 1,
  kWavelet = 2,
};

struct SpikeDetectInfo {
  std::vector<spikeDetectMode> mode;
};

struct SpikeDetectConfig {
  spikeDetectMode mode;
  uint32_t threshold_uV;
  std::vector<uint32_t> template_uV;
  bool sort{false}; // incompatible with threshold
};

#endif  // SYNAPSE_SPIKE_DETECT_H_
