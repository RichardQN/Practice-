#include "cache.hpp"
#include <iostream>

/* cache implementation */

Cache::Cache(Memory& mem) : memory(mem) {
    cacheMemory.resize(16);
}

void Cache::loadBlock(const uint16_t address, CacheLine& line){
    uint16_t blockStart = address & 0xFFF0;
    for (int i = 0; i < 16; i++){
        line.data[i] = memory.read(blockStart + i);
    }
}

uint8_t Cache::cacheRead(const uint16_t address){
    uint8_t offset = address & 0xF;
    uint8_t index = (address >> 4) & 0xF;
    uint8_t tag = (address >> 8) & 0xFF; 

    CacheLine& line = cacheMemory[index];

    if (line.valid && line.tag == tag){
        //cache hit
        return line.data[offset];
    } 

    Cache::loadBlock(address, line);
    line.valid = true;
    line.tag = tag;
    return line.data[offset];
}

void Cache::cacheWrite(const uint16_t address, uint8_t val){
    uint8_t offset = address & 0xF;
    uint8_t index = (address >> 4) & 0xF;
    uint8_t tag = (address >> 8) & 0xFF; 

    CacheLine& line = cacheMemory[index];

    if (line.valid && line.tag == tag){
        //cache hit - currently write through 
        line.data[offset] = val;
        memory.write(address, val);
    } else {
        //cache miss and write-allocate
        Cache::loadBlock(address, line);
        line.valid = true;
        line.tag = tag;
        line.data[offset] = val;
        memory.write(address, val);
    }
}
