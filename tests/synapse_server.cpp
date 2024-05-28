
#include "synapse_server.h"

grpc::Status SynapseServerImpl::ListDevices(grpc::ServerContext* context, const ListDevicesRequest* request, grpc::ServerWriter<DeviceInfo>* writer) {
    // Mock data for example purposes
    DeviceInfo device1;
    device1.set_name("Device 1");
    device1.set_serial(12345);
    device1.set_synapse_version(1);
    device1.set_firmware_version(101);

    DeviceInfo device2;
    device2.set_name("Device 2");
    device2.set_serial(67890);
    device2.set_synapse_version(2);
    device2.set_firmware_version(202);

    // Stream the devices to the client
    writer->Write(device1);
    writer->Write(device2);

    return grpc::Status::OK;
}

