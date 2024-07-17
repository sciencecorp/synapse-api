@0x80fe861389e8fb84;
struct BroadBandPacket {
    sequenceNumber @0 :UInt32;
    nixelOffset @1 :UInt32;
    samples @2 :List(UInt16);
}