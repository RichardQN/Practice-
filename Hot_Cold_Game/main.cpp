#include <iostream>
#include "guessgame.hpp"

using namespace std;


int main() {
    int n = randomNum();
    int guess{0};

    while (n != guess){
        cout<<"Enter a number: ";
        cin>>guess;
        check(n, guess);

    }
    cout<<"You got it!";
    return 0;
}



