#include <cstdint>
#include <array>
#include <vector>
#include "memory.hpp"
#ifndef CACHE_H
#define CACHE_H 

#pragma once

struct CacheLine {
    bool valid;
    uint8_t tag;
    std::array<uint8_t, 16> data{};
};

class Cache {
    private:
        std::vector<CacheLine> cacheMemory;
        Memory& memory;
    public:
        Cache(Memory& memory);
        uint8_t cacheRead(const uint16_t address);
        void cacheWrite(const uint16_t address, uint8_t val);
        void loadBlock(const uint16_t address, CacheLine& line);

};

#endif