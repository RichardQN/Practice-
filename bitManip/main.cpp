#include <iostream>
#include <cstdint>

int countSetBits(int val){
    int count = 0;
    for (int i = 0; i < 32; ++i){
        if ((val >> i) & 1){
            count += 1;
        }
    }
    return count;
}

int countOnes(uint32_t val){
    int count = 0;
    while(val != 0){
        val = val & (val - 1);
        count++;
    }
    return count;
}

int main(){
    int x = 255;
    std::cout << countSetBits(x) << "\n";
    std::cout<< countOnes(x);
    return 0;
}