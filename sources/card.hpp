#ifndef CARD
#define CARD
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std; 


enum CardVal {
    Nill = 0,
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
        CardVal val;
        string color;
        string suit;

        Card();
        Card(CardVal v, string colr, string Suit);
        int compare(Card otro);
};

#endif