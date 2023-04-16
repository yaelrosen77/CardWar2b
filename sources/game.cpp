#include "game.hpp"
using namespace ariel;

Game :: Game(Player& player1, Player& player2):p1(player1),p2(player2){
    generateCards();
    dealCards(CAPACITY);
    NumOfTurns =0;
} 

void Game:: generateCards(){
    for (int i = 0; i < CAPACITY; i++){
        if (i<13){
            const Card c1((i%13)+1,"Clubs");
            deck.push_back(c1);
        }
        else if (i<26)
        {
            const Card c2((i%13)+1, "Hearts"); 
            deck.push_back(c2);
        }
        else if(i<39){
            const Card c3((i%13)+1, "Spades");
            deck.push_back(c3);
        }
        else {
            const Card c4((i%13)+1, "Diamonds");
            deck.push_back(c4);
        }
}
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}

void Game:: dealCards(int mnt){
    int i=0;
    while (i < mnt)
    {
        if (i%2==0){
            p1.mazoCartas.push_back(deck.back());
            deck.pop_back();
        }
        
        else {
            p2.mazoCartas.push_back(deck.back());
            deck.pop_back();
        }
    i++;
    }
}
// Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.

void Game :: playTurn(){
    if (p1.mazoCartas.size()== 0 || p2.mazoCartas.size()==0){
        if (deck.size()==0){
            return;
        }
        else{
            dealCards(deck.size());
        }
    }    
    static string trick = "";
    Card pl1 = p1.play();
    trick.append(p1.name + " played " + getString(pl1.val) + " of " + pl1.suit);
    deck.push_back(pl1);

    Card pl2 = p2.play();
    trick.append(" " + p2.name + " played " + getString(pl2.val) + " of " + pl2.suit + ". ");
    deck.push_back(pl2);

    int res = pl1.compare(pl2);
    if (res == -1){
        while (deck.size()>0){
            p2.loot.push_back(deck.back());
            deck.pop_back();
        }
        trick.append(p2.name + " wins.");
        log.insert(log.begin()+NumOfTurns, trick);
        NumOfTurns++;
        trick = "";
    }

    else if (res ==1){
        while (deck.size()>0){
            p1.loot.push_back(deck.back());
            deck.pop_back();
        }
        trick.append(p1.name + " wins.");
        log.insert(log.begin()+NumOfTurns, trick);
        NumOfTurns++;
        trick = "";
    }

    else{
        trick.append("Draw. ");
        playTurn();
    }
}

void Game:: printLog(){
    return;
}

void Game:: printLastTurn(){
    cout<<log.back()<<endl;
}

void Game:: printStats(){
    return;
}

void Game:: playAll(){
    return;
}

string Game:: getString(int val){
    if (val >1 && val <11)
        return to_string(val);

    switch (val) {
        case 1:
            return "Ace";
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        default:
            return "Invalid value";
    }
}