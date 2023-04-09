#ifndef PLAYER
#define PLAYER
#include "stack.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

class Player{
    Stack mazoCartas;
    
    public: 
        string name;
        Stack loot;
};

#endif