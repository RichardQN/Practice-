#include "packet.hpp"

//packet init and functional commmands 

std::vector<uint8_t> packetSerial::serialize(const Packet& packet){
    std::vector<uint8_t> res;
    res.push_back(packet.header);
    res.push_back(packet.deviceID);
    res.push_back(packet.cmd);
    res.push_back(packet.length);
    for (uint8_t data : packet.payload){
        res.push_back(data);
    }
    return res;
}

Packet packetSerial::deserialize(const std::vector<uint8_t>& serial){
    Packet res;
    res.header = serial[0];
    res.deviceID = serial[1];
    res.cmd = serial[2];
    res.length = serial[3];
    for (size_t i = 4; i < serial.size(); i++){
        res.payload.push_back(serial[i]);
    }
    return res;

}







