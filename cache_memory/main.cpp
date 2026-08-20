#include "cache.hpp"
#include "memory.hpp"
#include <iostream>

int main(){
    Memory memory{};
    Cache cache{memory};

    uint16_t address = 0xABCC;

    cache.cacheWrite(address, 6);
    std::cout<< static_cast<int> (cache.cacheRead(address)) << "\n";
    std::cout<< static_cast<int> (memory.read(address));

    return 0;
}