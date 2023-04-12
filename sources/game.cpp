#include "game.hpp"



Game :: Game(Player player1, Player player2){
    p1 = player1;
    p2 = player2;
    discard_pile = new Stack(CAPACITY);
    generateCards();
    dealCards(CAPACITY);

} 

void Game:: generateCards(){
    Card tmp[CAPACITY];
    for (int i = 0; i < CAPACITY; i++){
        if (i<13){
            const Card c1(i%13,"Clubs");
            tmp[i] = c1;
        }
        else if (i<26)
        {
            const Card c2(i%13, "Hearts"); 
            tmp[i] = c2;
        }
        else if(i<39){
            const Card c3(i%13, "Spades");
            tmp[i] = c3;
        }
        else {
            const Card c4(i%13, "Diamonds");
            tmp[i] = c4;
        }
}
    int shuf[CAPACITY];
    for (int j=0; j<CAPACITY; j++)
        shuf[j]=j;

    int k=0;
    while (k<CAPACITY){
        int i = getNdx(shuf, CAPACITY-(k+1));
        discard_pile->push(tmp[i]);
        k++;
    }
    
}

int Game :: getNdx(int * ARR, int MaxNdx){
    srand(time(nullptr));
    int min = 0;
    int max = MaxNdx;
    int rando = rand() % (max - min + 1) + min;
    int result = ARR[rando]; 
    ARR[rando] = ARR[MaxNdx];

    return ARR[rando];
}

void Game:: dealCards(int Amount){
    while (int i =0 <Amount)
    {
        if (i%2==0)
            p1.mazoCartas->push(discard_pile.pop);
        
        else {
            p2.mazoCartas->push(discard_pile.pop);
        }
    i++;
    }
}


void Game :: playTurn(){
    Card pl1 = p1.play;
    Card pl2 = p2.play;
    int res = pl1.compare(pl2);
    // if (res == 0){
    //     // play war
    // }
    if (res==-1){
        p2.loot->push(pl1);
        p2.loot->push(pl2);
    }
    else{
        p1.loot->push(pl1);
        p1.loot->push(pl2);
    }
}

