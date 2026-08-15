#include "packet.hpp"
#include <iostream>

#define ARM 0x01
#define DISARM 0x02
#define ALTITUDE 0x03
#ifndef FLIGHT_CONTROL_H
#define FLIGHT_CONTROL_H

#pragma once


class FlightController {
    
    int altitude;

    public:

        FlightController(int alt);
        uint8_t decode(const std::vector<uint8_t>& bytes);
        std::vector<uint8_t>sendAlt(Packet& packet);
        void handleCommand(const uint8_t& command);
        void arm();
        void disarm();

};

class groundControl{
    public:
        groundControl();
        int groundDecode(const std::vector<uint8_t>& bytes);
        void groundHandle(int altitude);
        std::vector<uint8_t>requestAlt(Packet& packet);
    
};

#endif 
