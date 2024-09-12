#include <iostream>
#include "Game.h"

// How many players? each kind? each name? each bankroll?
// Loop for each round

void main () {
    std::cout << "Welcome to BlackJack!\nPlease enter how many players want to join the game:" << std::endl;
    int humannum;
    std::cin >> humannum;   //number of players
    Human Human[humannum];
    std::cout << "And these are Computer players!" << std::endl;
    Dealer Dealer;
    Meek Meek;
    Random Random;
    int decknum = (humannum/3)+1;    //number of decks, plus one for Computers
    Deck deck[decknum];

    for(int i = 0; i < humannum; i++){    //User set Player name and bankroll
        //player name
        std::cout << "Please enter the name of Player " << i+1 << std::endl;
        std::string s;
        std::cin >> s;
        Human[i].setname(s);
        //bankroll
        std::cout << "Please enter how much money " << Human[i].getname()  << " have" << std::endl;
        int n;
        std::cin >> n;
        Human[i].setbankroll(n);
    }
    while(true){    // Loop for each round
        for(int i = 0; i < humannum; i++){
            Human[i].bets();
        }
        Dealer.bets();
        Meek.bets();
        Random.bets();

        Dealer.strategy(1,deck);

        for(int i = 0;i < humannum;i++){
            Human[i].strategy(decknum,deck);
        }

        Meek.strategy(decknum,deck);
        Random.strategy(decknum,deck);
        int k = Meek.computemoney();

        if(Meek.getlose() == true)
            Dealer.computehouse(k);
        
        k = Random.computemoney();
        
        if(Random.getlose() == true)
            Dealer.computehouse(k);
        
        for(int i = 0;i < humannum;i++){
            k = Human[i].computemoney();

            if(Human[i].getlose() == true)
                Dealer.computehouse(k);
        
        }

        std::cout << "Would you like to continue?(Y/N)" << std::endl;
        std::string s;
        std::cin >> s;

        if(s.compare("N") == 0){
            break;
        }
    }

    // Dealer.computemoney();
    std::cout << "These are final result!" << std::endl;
    Dealer.display();
    Meek.display();
    Random.display();

    for(int i = 0;i < humannum;i++){
        Human[i].display();
        }
        
    return 0;
}