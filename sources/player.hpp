#ifndef PLAYER
#define PLAYER
#include "stack.hpp"
#include <iostream>
#include <cstdlib>
#define HALF_DECK 26
#define CAPACITY 52

using namespace std;

class Player{
    
    public: 
        string name;
        Stack * loot;
        Stack * mazoCartas;

        Player(string nombre);
        Player();
        
        ~Player();
        unsigned int stacksize();
        unsigned int cardesTaken();
        Card play();
};

#endif