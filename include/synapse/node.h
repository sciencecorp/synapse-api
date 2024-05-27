#ifndef SYNAPSE_NODE_H_
#define SYNAPSE_NODE_H_

#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <variant>

#include "synapse/status.h"

// nodes
#include "synapse/nodes/stream_in.h"
#include "synapse/nodes/stream_out.h"
#include "synapse/nodes/electrical_broadband.h"
#include "synapse/nodes/electrical_stim.h"
#include "synapse/nodes/optical_broadband.h"
#include "synapse/nodes/optical_stim.h"
#include "synapse/nodes/spike_detect.h"
#include "synapse/nodes/spectral_filter.h"

namespace synapse {

enum class NodeType : uint8_t {
  kStreamIn = 0,
  kStreamOut = 1,
  kElectricalBroadband = 2,
  kElectricalStim = 3, 
  kOpticalBroadband = 4,
  kOpticalStim = 5,
  kSpikeDetect = 6,
  kInference = 7,
  kSpectralFilter = 8,
  kCamera = 9,
};

enum class DataType {
  kAny = 0,
  kBroadband = 1,
  kSpiketrain = 2,
  kTimestamps = 3,
  kImage = 4,
};

using NodeInfo = std::variant<StreamInInfo, StreamOutInfo, ElectricalBroadbandInfo, 
             ElectricalStimInfo, OpticalBroadbandInfo, OpticalStimInfo, 
             SpikeDetectInfo, SpectralFilterInfo>;

using NodeConfig = std::variant<StreamInConfig, StreamOutConfig, ElectricalBroadbandConfig,
             ElectricalStimConfig, OpticalBroadbandConfig, OpticalStimConfig,
             SpikeDetectConfig, SpectralFilterConfig>;

class Node {
 public:
  Node(NodeType node_type) : node_type_(node_type){};
  Node(NodeType node_type, NodeConfig node_config) : node_type_(node_type), node_config_(node_config){};

  [[nodiscard]] NodeType get_node_type() const { return node_type_; }

  virtual NodeInfo      get_valid_config() const = 0;
  virtual NodeConfig           get_config() const = 0;
  [[nodiscard]] virtual Status set_config(NodeConfig config) = 0;

  [[nodiscard]] virtual std::vector<DataType> get_input_dtype() const = 0;
  [[nodiscard]] virtual std::vector<DataType> get_output_dtype() const = 0;

 private:
  NodeType node_type_;
  NodeInfo node_config_options_;
  NodeConfig node_config_;

  std::vector<DataType> input_dtype_;
  std::vector<DataType> output_dtype_;

};
}  // namespace synapse

#endif  // SYNAPSE_NODE_H_
