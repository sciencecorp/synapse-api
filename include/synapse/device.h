#ifndef SYNAPSE_DEVICE_H_
#define SYNAPSE_DEVICE_H_

#include <atomic>
#include <vector>

#include "synapse/status.h"
#include "synapse/synapse.h"
#include "synapse/node.h"
#include "synapse/signal_chain.h"


namespace synapse {

struct SynapsePeripheral;

struct DeviceInfo {
  std::string name;
  uint64_t serial;
  uint32_t synapse_version;
  uint32_t firmware_version;
  // which node we are talking to is position dependent
  // and should be described in manual of the device
  std::vector<SynapsePeripheral> peripherals;
};

struct DeviceStatus {
  bool is_streaming;
  std::vector<NodeInfo> nodes;
};

class Device {
 public:
  Device(const DeviceInfo& info);
  Device(const Device& other) = default;  // Copy constructor
  Device(Device&& other) = default;       // Move constructor
  ~Device() = default;
    
  Status init();
  Status start();
  Status stop();

  // fill up to `buf_len` bytes into the memory starting at `buf`;
  // populates `read_len` with the actual number of bytes written
  // and data_lost with a number of bytes dropped from the output
  // node's circular buffer between reads, if any.
  // `data_lost` resets after every read call.
  // The format of the data is determined by the `data_type` parameter.
  Status read(uint32_t node_id,
              uint16_t *buf,
              uint32_t buf_len,
              DataType *data_type,
              uint32_t *read_len,
              uint32_t *data_lost);

  // write `data_len` bytes starting from `data` to `node_id`
  Status write(uint32_t node_id, int32_t *data, uint32_t data_len);

  Status get_info(DeviceInfo *device_info);
  Status get_status(DeviceStatus *device_status);

  Status set_config(SignalChain *signal_chain);
  Status get_config(SignalChain *signal_chain);

 private:
  DeviceInfo info_;

  std::atomic<bool> is_initialized_{false}; // set in init, else start will fail

  SignalChain signal_chain_;
  std::atomic<bool> is_streaming_{false};

};

}  // namespace synapse
#endif  // SYNAPSE_DEVICE_H_
