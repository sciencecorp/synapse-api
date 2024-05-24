#ifndef SYNAPSE_NODE_H_
#define SYNAPSE_NODE_H_

#include <synapse/utils.h>
#include "synapse/nodes/stream_in.h"
#include "synapse/nodes/stream_out.h"
#include "synapse/nodes/electrical_broadband.h"
#include "synapse/nodes/electrical_stim.h"
#include "synapse/nodes/optical_broadband.h"
#include "synapse/nodes/optical_stim.h"
#include "synapse/nodes/spike_detect.h"
#include "synapse/nodes/inference.h"
#include "synapse/nodes/spectral_filter.h"
#include "synapse/nodes/camera.h"

#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <variant>

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

std::variant<StreamInInfo, StreamOutInfo, ElectricalBroadbandInfo, 
             ElectricalStimInfo, OpticalBroadbandInfo, OpticalStimInfo, 
             SpikeDetectInfo, InferenceInfo, SpectralFilterInfo, 
             CameraInfo> NodeInfo;

std::variant<StreamInConfig, StreamOutConfig, ElectricalBroadbandConfig,
             ElectricalStimConfig, OpticalBroadbandConfig, OpticalStimConfig,
             SpikeDetectConfig, InferenceConfig, SpectralFilterConfig,
             CameraConfig> NodeConfig;

class Node {
 public:
  Node(NodeType node_type) : node_type_(node_type){};
  Node(NodeType node_type, NodeConfig node_config) : node_type_(node_type), node_config_(node_config){};

  [[nodiscard]] NodeType get_node_type() const { return node_type_; }

  virtual nodeInfo      get_valid_config() const = 0;
  virtual nodeConfig           get_config() const = 0;
  [[nodiscard]] virtual status set_config(NodeConfig config) = 0;

  [[nodiscard]] virtual std::vector<NodeConnectionType> get_input_type() const = 0;
  [[nodiscard]] virtual std::vector<NodeConnectionType> get_output_type() const = 0;

 private:
  nodeType node_type_;
  nodeInfo node_config_options_;
  nodeConfig node_config_;

  std::vector<NodeConnectionType> input_type_;
  std::vector<NodeConnectionType> output_type_;

};
}  // namespace synapse

#endif  // SYNAPSE_NODE_H_
