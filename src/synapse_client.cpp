#include "synapse_client.h"
#include <iostream>

SynapseClient::SynapseClient(std::shared_ptr<grpc::Channel> channel)
    : stub_(SynapseServer::NewStub(channel)) {}

void SynapseClient::ListDevices() {
    ListDevicesRequest request;
    grpc::ClientContext context;
    std::unique_ptr<grpc::ClientReader<DeviceInfo>> reader(stub_->ListDevices(&context, request));

    DeviceInfo device;
    while (reader->Read(&device)) {
        std::cout << "Device Name: " << device.name() << std::endl;
        std::cout << "Serial: " << device.serial() << std::endl;
        std::cout << "Synapse Version: " << device.synapse_version() << std::endl;
        std::cout << "Firmware Version: " << device.firmware_version() << std::endl;
    }

    grpc::Status status = reader->Finish();
    if (!status.ok()) {
        std::cerr << "ListDevices RPC failed." << std::endl;
    }
}

