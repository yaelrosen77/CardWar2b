#ifndef CARD
#define CARD
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std; 

namespace ariel{
class Card{

    public: 
        int val;
        string suit;

        Card(int vali, string Suit);        //no need for an empty constructor hence card only exist with suit and value
        int compare(Card otro);
};
}
#endif