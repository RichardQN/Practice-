#include <vector>
#include <cstdint>
#ifndef MEMORY_H
#define MEMORY_H

#pragma once

/* Simulated memory prototype */

class Memory {
    
    std::vector<uint8_t> data; 

    public:

        Memory();
        static uint8_t read(uint16_t address);
        static void write(uint16_t address, uint8_t value);

};

#endif