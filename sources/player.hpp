#ifndef PLAYER
#define PLAYER
#include <iostream>
#include "card.hpp"
#include <vector>
#include <cstdlib>
#define HALF_DECK 26
#define CAPACITY 52

using namespace std;

namespace ariel{
    
class Player{
    public: 
        string name;
        vector<Card> loot;
        vector<Card> mazoCartas;

        Player(string nombre);
        int stacksize();
        int cardesTaken();
        Card play();
};
}
#endif