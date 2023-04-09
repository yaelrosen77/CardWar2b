#ifndef STACK
#define STACK

#include <iostream>
#include <cstdlib>
#include "card.hpp"

class Stack{
    public: 
        unsigned int CurSize;
        Card * deckCards;

        Stack(int capacity);
        ~Stack();
        void push(Card n);
        bool isEmpty();
        Card pop();
};

#endif