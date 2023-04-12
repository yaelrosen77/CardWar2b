#ifndef GAME
#define GAME
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.hpp"
using namespace std;

class Game{
    public: 
        Player p1;
        Player p2;
        Stack *discard_pile;

        Game(Player player1, Player player2);
        
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

    private:
        void suffle(); 
        void generateCards();
        void dealCards(int Amount);
        int getNdx(int* ARR, int MaxNdx);
        void playAll();
        // void war();
};

#endif

