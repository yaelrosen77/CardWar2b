#include "card.hpp"
using namespace ariel;

Card :: Card(int v, string Suit){
    val = v;
    suit = Suit;
}

int Card :: compare(Card otro){
    if (val == otro.val)
        return 0;
    return (val >= otro.val ? (val == otro.val ? 0 : 1) : -1);
}

