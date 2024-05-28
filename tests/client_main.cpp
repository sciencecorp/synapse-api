
#include <fmt/core.h>

#include "synapse/synapse.h"
#include "synapse/device.h"

using namespace synapse;

int main() {
    Synapse synapse(grpc::CreateChannel("localhost:50052", grpc::InsecureChannelCredentials()));

    // List devices
    std::vector<std::unique_ptr<Device>> devices;
    Status s = synapse.list_devices(&devices);

    // Check what devices were returned
    if (s.ok()) {
        for (const std::unique_ptr<Device>& device : devices) {
          DeviceInfo info;
          Status s = device->get_info(&info);
          if (!s.ok()) {
            fmt::println("Error ({}): {}", __func__, s.message());
            return 1;
          }
          fmt::println("Device Name: {}", info.name);
          fmt::println("Serial: {}", info.serial);
          fmt::println("Synapse Version: {}", info.synapse_version);
          fmt::println("Firmware Version: {}", info.firmware_version);
        }
    } else {
      fmt::println("Error ({}): {}", __func__, s.message());
    }

    return 0;
}

