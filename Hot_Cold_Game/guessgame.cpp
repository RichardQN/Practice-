#include <iostream> 
#include <random>
#include "guessgame.hpp"


using namespace std;

int randomNum(){
    srand(static_cast<unsigned int>(time(nullptr)));
    int n = (rand() % 100) + 1;

    return n;
}

void check(int n, int guess){
    if (guess > n-10 || guess < n+ 10 ){
        cout<<"Hot!" << "\n";
    } else {
        cout<<"Cold" << "\n";
    }
}