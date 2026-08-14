#include <string>
#include <vector>
#include <cstdint>

#ifndef PACKET_H
#define PACKET_H

#pragma once


struct Packet {
    uint8_t header;
    uint8_t deviceID{}, cmd{}, length{};
    std::vector<uint8_t> payload;
};

class packetSerial {
    std::vector<uint8_t> serialize(const Packet& packet);
    Packet deserialize(const std::vector<uint8_t>& serial);
    //bool valid(Packet packet, uint8_t cmd);

};



#endif

