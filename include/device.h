#ifndef SYNAPSE_DEVICE_H_
#define SYNAPSE_DEVICE_H_

namespace synapse {

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
  std::vector<NodeStatus> nodes;
};

class Device {
 public:
   Device(std::string path) : path_(path) {}

  status init();
  status start();
  status stop();

  // fill up to `buf_len` bytes into the memory starting at `buf`;
  // populates `read_len` with the actual number of bytes written
  // and data_lost with a number of bytes dropped from the output
  // node's circular buffer between reads, if any.
  // `data_lost` resets after every read call.
  // The format of the data is determined by the `data_type` parameter.
  status read(uint32_t node_id,
              uint16_t *buf,
              uint32_t buf_len,
              DataType *data_type,
              uint32_t *read_len,
              uint32_t *data_lost);

  // write `data_len` bytes starting from `data` to `node_id`
  status write(uint32_t node_id, int32_t *data, uint32_t data_len);

  std::optional<DeviceInfo> get_info();
  std::optional<DeviceStatus> get_status();

  status set_config(const SignalChain *signal_chain);
  std::optional<SignalChain> get_config();

 private:
  std::string path_;

  std::atomic<bool> is_initialized_{false}; // set in init, else start will fail

  SignalChain signal_chain_;
  std::atomic<bool> is_streaming_{false};

};

}  // namespace synapse
#endif  // SYNAPSE_DEVICE_H_
