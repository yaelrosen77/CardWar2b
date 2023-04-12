#include "player.hpp"

Player :: Player(string nombre){
    name = nombre;
    mazoCartas = new Stack(HALF_DECK);
    loot = new Stack(CAPACITY);
}

Player :: Player(){
    name = "";
    mazoCartas = NULL;
    loot = NULL;
}

Player ::~Player(){
    delete mazoCartas;
    delete loot;
}

unsigned int Player :: stacksize(){
    return mazoCartas->CurSize;
} 

/// @brief 
/// @return 
unsigned int Player:: cardesTaken(){
    return loot->CurSize;
}

Card Player :: play(){
    return mazoCartas->pop;
}