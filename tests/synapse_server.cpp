
#include "synapse_server.h"

grpc::Status SynapseServerImpl::ListDevices(grpc::ServerContext* context, const proto_synapse::ListDevicesRequest* request, grpc::ServerWriter<proto_synapse::DeviceInfo>* writer) {
    // Mock data for example purposes
  proto_synapse::DeviceInfo device1;
    device1.set_name("Device 1");
    device1.set_serial(12345);
    device1.set_synapse_version(1);
    device1.set_firmware_version(101);

    proto_synapse::DeviceInfo device2;
    device2.set_name("Device 2");
    device2.set_serial(67890);
    device2.set_synapse_version(2);
    device2.set_firmware_version(202);

    // Stream the devices to the client
    writer->Write(device1);
    writer->Write(device2);

    return grpc::Status::OK;
}

