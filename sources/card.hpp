#ifndef CARD
#define CARD
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std; 


enum CardVal {
    Ace = 1,
    Two, 
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};


class Card{

    public: 
        int val;
        string suit;

        Card();
        Card(int v, string Suit);
        int compare(Card otro);
};

#endif