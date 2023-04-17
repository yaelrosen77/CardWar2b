#include "game.hpp"
using namespace ariel;

Game :: Game(Player& player1, Player& player2):p1(player1),p2(player2){
    generateCards();                 //creating first and then suffling
    dealCards(CAPACITY);             //dealing half deck to each player
    NumOfTurns =0;      
    p1.Numofwins =0;                //reset the data in case there was another game before this 
    p2.Numofwins =0;
    NumOfDraws =0;                  
} 

/*this function creates all of the cards and insert them to the deck*/
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
    random_device rd;                         //random_device is a uniformly-distributed integer random number generator that produces non-deterministic random numbers(from cppreference.com) 
    mt19937 g(rd());                          //seed function  
    shuffle(deck.begin(), deck.end(), g);     //Shuffle the elements of a sequence using a uniform random number generator.    
}

/*simmulates real dealing cards. i.e one for each player at a time*/
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

void Game :: playTurn(){
    if (&p1 == &p2){                                                    //based on test requirements
        throw invalid_argument("Player cannot play with himself! \n");
    }
    if (p1.stacksize()== 0 || p2.stacksize()==0){                   //no cards left to play
        random_device rd;
        mt19937 g(rd());
        if (deck.size()==0){                                
            throw runtime_error("Game over");
        }
        if (deck.size()==2){                        //there was a draw but there was no card to play, so there is no point of considering this turn
            p1.loot.push_back(deck.back());
            deck.pop_back();
            p2.loot.push_back(deck.back());         //taking these cards back to the loot
            deck.pop_back();
            return;
        }
        if (deck.size()==4){                        //there was a draw but enough cards for putting upside down cards
            if ((deck.at(0).compare(deck.at(2))==0) && (deck.at(3).compare(deck.at(2))==0)){            //a super rare situation that all four cards left are equal by value. in this case also we are not considering this turn
                p1.loot.push_back(deck.back());
                deck.pop_back();
                p2.loot.push_back(deck.back());
                deck.pop_back();
                p1.loot.push_back(deck.back());
                deck.pop_back();
                p2.loot.push_back(deck.back());
                deck.pop_back();
                return;
            }

            else{
                shuffle(deck.begin(), deck.end(), g);           //if there is at least one card different which is more likely to happen, deal and call the function again to handle the rest
                dealCards(4);
                playTurn();
                return;
            }
        }
        else{
            shuffle(deck.begin(), deck.end(), g);               //trivial
            dealCards(deck.size());
            playTurn();
            return;
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
        while (deck.size()>0){                      //player 2 won. taking all of the cards in the deck
            p2.loot.push_back(deck.back());
            deck.pop_back();
        }
        p2.Numofwins++;
        trick.append(p2.name + " wins.");
        log.insert(log.begin()+NumOfTurns, trick);              //saving the data 
        NumOfTurns++;
        trick = "";
    }

    else if (res ==1){
        while (deck.size()>0){
            p1.loot.push_back(deck.back());
            deck.pop_back();
        }
        p1.Numofwins++;
        trick.append(p1.name + " wins.");
        log.insert(log.begin()+NumOfTurns, trick);
        NumOfTurns++;
        trick = "";
    }

    else{
        trick.append("Draw. ");
        NumOfDraws++;
        if (p1.stacksize() >0 && p2.stacksize() > 0){       //if there are enough cards, put upside down cards
            pl1 = p1.play();
            deck.push_back(pl1);
            pl2 = p2.play();
            deck.push_back(pl2);
        }
        playTurn();                                          //calling recursively to determine final result.
    }
}

void Game:: printLog(){
    unsigned int i = 0;
    string res = "";
    while (i<NumOfTurns){
        res = log[i];
        cout<<res<<endl;
        i++;
    }
}

void Game :: printWiner(){
    if (p1.cardesTaken()>p2.cardesTaken())
        cout<<p1.name + " "<<endl;
    else if (p1.cardesTaken() < p2.cardesTaken())
        cout<<p2.name + " "<<endl; 
    else {
        cout<<"Draw! "<<endl;
    }
}

void Game:: printLastTurn(){
    cout<<log.back()<<endl;
}

/*printing name of each player, win rate, number of winnings and cards taken. also prints the number of draws and draw rate*/
void Game:: printStats(){
    cout<<"**************************STATS*****************************"<<endl;
    cout<<p1.name + " won " + to_string(p1.Numofwins) + " times with a win rate of " + to_string((double)p1.Numofwins/(double)NumOfTurns) + 
    " and has " + to_string(p1.cardesTaken()) + " cards taken."<<endl;
    cout<<p2.name + " won " + to_string(p2.Numofwins) + " times with a win rate of " + to_string((double)p2.Numofwins/(double)NumOfTurns) +
    " and has " + to_string(p2.cardesTaken()) + " cards taken."<<endl;
    cout<<"Total draws is " + to_string(NumOfDraws) + " and draw rate is " + to_string((double)NumOfDraws/(double)NumOfTurns)<<endl;
}

void Game:: playAll(){
    while (p1.stacksize()!=0 && p2.stacksize()!=0){
        playTurn();
    }
}

/*this function cast value of card to a string*/
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