#include "card.hpp"
using namespace ariel;

Card :: Card(int v, string Suit){
    val = v;
    suit = Suit;
}

/*
this function compares the current card to another one.
it checks first if there are special conditions such as Ace over value greater then 2, 
and if not checks which one is greater than the other one.
if the current card 'wins', it returns 1, if the cards are equal by value returns 2,
and otherwise 0
*/

int Card :: compare(Card otro){
    if (val ==1 && otro.val>2){
        return 1;
    }
    if (otro.val ==1 && val >2){
        return -1;
    }    
    if (val == otro.val)
        return 0;
    return (val >= otro.val ? (val == otro.val ? 0 : 1) : -1);
}

