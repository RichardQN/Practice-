#include "devices.hpp"
#include "packet.hpp"
#include <iostream>

// Emulation for ground control to flight control devices and command handling

FlightController::FlightController(int alt){
    altitude = alt;
}

uint8_t FlightController::decode(const std::vector<uint8_t>& bytes){
    Packet res = packetSerial::deserialize(bytes);
    return res.cmd;
}

void FlightController::handleCommand(const uint8_t& command){

    switch (command){
        case ARM:
            arm();
            break;
        case DISARM:
            disarm();
            break;
        case ALTITUDE:
            std::cout<<"Altitude requested!\n";
            break;
        default:
            std::cout<<"Unknown command\n";
            break;
    }
}

void FlightController::arm(){
    std::cout<<"Device armed!\n";
}

void FlightController::disarm(){
    std::cout<<"Device disarmed!\n";
}

std::vector<uint8_t> FlightController::sendAlt(Packet& packet){
    std::vector<uint8_t> mixed;
    int alt = altitude;

    if (alt == 0){
        mixed.push_back(0);
    }
    while (alt != 0){
        uint8_t x = alt % 256;
        alt /= 256;
        mixed.push_back(x);
    }
    packet.payload = mixed;
    packet.length = mixed.size();
    std::vector<uint8_t> res = packetSerial::serialize(packet);

    return res;
    
}

groundControl::groundControl(){
}

std::vector<uint8_t> groundControl::requestAlt(Packet& packet){
    packet.header = 0xAA;
    packet.deviceID = 0x01;
    packet.cmd = ALTITUDE;
    packet.length = 0;
    packet.payload.clear();

    return packetSerial::serialize(packet);
}

int groundControl::groundDecode(const std::vector<uint8_t>& bytes){
    Packet packet = packetSerial::deserialize(bytes);
    int altitude = 0;
    int multiplier = 1;

    for (uint8_t data : packet.payload){
        altitude += data * multiplier;
        multiplier *= 256;
    }

    return altitude;
}

void groundControl::groundHandle(int altitude){
    std::cout<<"Ground Control opened altitude response: "<<altitude<<" meters\n";
}
