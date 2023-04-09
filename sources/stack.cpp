#include "stack.hpp"

Stack :: Stack(int capacity){
    CurSize = 0;
    Card deckCards[capacity];
}

Stack :: ~Stack(){
    delete deckCards;
}

void Stack :: push(Card n){
    deckCards[CurSize++] = n;
}

bool Stack :: isEmpty(){
    if (CurSize == 0)
        return true;
    return false;
} 

Card Stack :: pop(){
    if (isEmpty() == false)
        return deckCards[--CurSize];
}
