
#ifndef SYNAPSE_SPECTRAL_FILTER_H_
#define SYNAPSE_SPECTRAL_FILTER_H_

#include "synapse/node.h"
#include <vector>
#include <cstdint>

enum class spectralFilterMethod : uint8_t {
  kLowPass = 0,
  kHighPass = 1,
  kBandPass = 2,
  kBandStop = 3,
}

struct SpectralFilterInfo {
};

struct SpectralFilterConfig {
  spectralFilterMethod method;
  uint32_t low_cutoff_mHz;
  uint32_t high_cutoff_mHz;
};

#endif  // SYNAPSE_SPECTRAL_FILTER_H_
