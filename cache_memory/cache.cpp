#include "cache.hpp"
#include <iostream>

Cache::Cache(Memory& mem) : memory(mem) {
    cacheMemory.resize(16);
}

uint8_t Cache::cacheRead(const uint16_t address){
    uint8_t offset = address & 0xF;
    uint8_t index = (address >> 4) & 0xF;
    uint8_t tag = (address >> 8) & 0xFF; 

    CacheLine& line = cacheMemory[index];

    if (line.valid && line.tag == tag){
        //cache hit
        return line.data[offset];
    } else {
        //cache miss
        return memory.read(address);
    }
}

void Cache::cacheWrite(const uint16_t address, uint8_t val){
    uint8_t offset = address & 0xF;
    uint8_t index = (address >> 4) & 0xF;
    uint8_t tag = (address >> 8) & 0xFF; 

    CacheLine& line = cacheMemory[index];

    if (line.valid && line.tag == tag){
        //cache hit
        line.data[offset] = val;
    } else {
        //cache miss
        std::cout<<"Invalid write location";
    }
}
