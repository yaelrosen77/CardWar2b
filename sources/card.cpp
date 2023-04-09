#include "card.hpp"

Card :: Card(){
    val = Nill;
    color ="";
    suit = "";
}

Card :: Card(CardVal v, string colr, string Suit){
    val = v;
    color = colr;
    suit = Suit;
}

int Card :: compare(Card otro){
    if (val == otro.val)
        return 0;
    return (val >= otro.val ? (val == otro.val ? 0 : 1) : -1);
}