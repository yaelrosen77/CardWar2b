#ifndef PLAYER
#define PLAYER
#include "stack.hpp"
#include <iostream>
#include <cstdlib>
#define HALF_DECK 26
#define CAPACITY 52

using namespace std;

class Player{
    Stack * mazoCartas;
    
    public: 
        string name;
        Stack * loot;

        Player(string nombre);
        ~Player();
        unsigned int stacksize();
        unsigned int cardesTaken();
};

#endif