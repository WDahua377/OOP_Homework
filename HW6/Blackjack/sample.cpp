#include <iostream>
#include <time.h>
#include <string>
#include <cstdlib>

class Card {
    public:
    Card():flag(false){}
    //set card suit to s, value to v
    void setcard(int s, int v){
        suit = static_cast<Suit>(s);
        value = v;  }
    //set card suit to s
    void setsuit(int s){
        suit = static_cast<Suit>(s);    }
    //set card rank to r
    void setrank(int r){
        rank = r;    }
    //set card value to v
    void setvalue(int v){
        value = v;    }
    //the card has been drawn
    void draw(){
        flag = true;
    }
    //return whether the card has been drawn(true) or not(false)
    bool getflag(){
        return flag;
    }

    private:
    int rank;
    enum Suit {spade, heart, diamond, club} suit;
    int value;
    bool flag;  //true if it's drawn, false if it's not
    };

typedef Card Deck[51];    //Deck[which deck][which card in a deck]

class Player {
    public:
    Player():hand(0), lose(false){};
    //strategy that decide whether to draw or not
    virtual void strategy(int decknumber, Deck Deck[]) = 0; //pure virtual function

    //how much does the Player want to bet with
    virtual void bets() = 0;

    //set bankroll to n
    void setbankroll(int n){
        bankroll = n;   }
    //set bet to n
    void setbet(int n){
        bet = n;    }
    //set hand to n
    void sethand(int n){
        hand = n;   }
    //set name to s
    void setname(std::string s){
        name = s;    }
    //set owncard to s
    void setowncard(std::string s){
        owncard = s;
    }
    //display all information of player
    void display(){
        std::cout << "name:" << name << " bankroll:" << bankroll << std::endl;
    }
    //get Player name
    std::string getname(){
        return name;    }
    //player draw a card
    void draw(int decknumber, Deck Deck[]){
        // std::cout << getname() << " chooses to draw." << std::endl;
        srand(time(NULL));
        int decknum = (int) (decknumber-1) * (double)rand()/RAND_MAX ;
        int index = (int) (50) * (double)rand()/RAND_MAX ;
        if(Deck[decknum][index].getflag() == false){
            //std::cout << "index:" << index << " flag:" << Deck[decknum][index].getflag() << std::endl;
            Deck[decknum][index].draw();

            int rank = (index+1) % 13; //The rank of the card being drawn
            if(rank == 0)  rank += 13;
            int suit = (index+1) / 13;  //The suit of the card being drawn
            computevalue(rank);
            display(rank,suit);
            bust(hand);
        }
    }
    //return hand
    int gethand(){
        return hand;
    }
    //return bet
    int getbet(){
        return bet;
    }

    //return bankroll
    int getbankroll(){
        return bankroll;
    }

    //compute hand value
    void computevalue(int rank){
        if(rank > 10){
            hand += 10;
            }
        else{
            hand += rank;
        }
    }

    //check if player is bust
    void bust(int value){
        if(value > 21){
            lose = true;
        }
    }
    //reutrn lose
    bool getlose(){
        return lose;
    }

    //return what cards Player has in hand
    std::string getowncard(){
        return owncard;
    }

    void display(int rank, int suit){
        std::string s;
        switch (suit){
            case 0:
                setowncard(getowncard()+std::to_string(rank)+"S ");
                break;
            case 1:
                setowncard(getowncard()+std::to_string(rank)+"H ");
                break;
            case 2:
                setowncard(getowncard()+std::to_string(rank)+"D ");
                break;
            case 3:
                setowncard(getowncard()+std::to_string(rank)+"C ");
                break;
            }
        std::cout << name << "'s current hand:" << owncard << std::endl;
    }
    //compute who lose money
    int computemoney(){
        if(lose == true){
            bankroll -= bet*2;
        }
        return bet*2;
    }

    //compute house money
    void computehouse(int n){
        bankroll += n;
    }

    private:
    std::string name;
    int bankroll;
    int bet;
    int hand;
    std::string owncard;
    bool lose;  //lose or not
    };

class Game{
    public:
    private:
};
class Human: public Player, public Game { 
    public:
    void strategy(int decknumber, Deck Deck[]){
        while(getlose() == false){
            std::cout << getname() << "'s turn.\n ------------" << std::endl;
            std::cout << "Would you like to draw another card?(Y or N): " << std::endl;
            std::string s;
            std::cin >> s;
            if(s.compare("Y") == 0){
                draw(decknumber,Deck);
                std::cout << getname() << " chooses to draw." << std::endl;
            }
            else{
                std::cout << getname() << " chooses to stay." << std::endl;
                break;
            }
        }
        if(getlose() == true){
            std::cout << getname() << " busted at " << gethand() << " !" << std::endl;
        }
    }
    void bets(){
        std::cout << getname() << ", how much would you like to bet?" << std::endl;
        int n;
        std::cin >> n;
        std::cout << getname() << " bets $" << n << std::endl;
        setbet(n);
    }
    private:
};

class Dealer: public Player{
    public:
    Dealer():Player(){
        setbankroll(10000);  //start with 10,000 dollar
        setname("Dealer");
        display();
    };

    void strategy(int decknumber, Deck Deck[]){    //需要定義virtual function
        std::cout << getname() << "'s turn.\n ------------" << std::endl;
        while(getlose() == false){
        // 1. draw while hand is worth 16 or fewer points
            if(gethand() <= 16){
                // std::cout << getname() << " chooses to draw." << std::endl;
                draw(decknumber,Deck);
            }
            else{
                std::cout << getname() << " chooses to stay." << std::endl;
                break;
            }
        }
        if(getlose() == true){
            std::cout << getname() << " busted at " << gethand() << " !" << std::endl;
        }
        // 2. stop when reach 17 or more
    }
    void bets(){
        setbet(0);  //never bet any of house money
    }
};

class Meek: public Player{ 
    public:
    Meek():wins(0), Player(){
        setbankroll(100);  //start with 100 dollar
        setbet(2);  //start with bet 2
        setname("Meek");
        sethand(1);
        display();
    };
    //set the number of wins to n
    void setwins(int n){
        wins = n;
    }
    //return wins
    int getwins(){
        return wins;
    }
    void strategy(int decknumber, Deck Deck[]){    //需要定義virtual function
        std::cout << getname() << "'s turn.\n ------------" << std::endl;
        while(getlose() == false){
        //奇數 amount draw
            if(gethand() % 2 != 0){
                draw(decknumber, Deck);
                // std::cout << getname() << " chooses to draw." << std::endl;
            }
        //偶數 number stays 
            else{
                std::cout << getname() << " chooses to stay." << std::endl;    
                break;
            }
        }
        if(getlose() == true){
            std::cout << getname() << " busted at " << gethand() << " !" << std::endl;
            setwins(0);
        }
        
    };
    void bets(){
        //only bets just $2 every round
        //wins 3 rounds in a row, doubles current betting amount
        int w = getwins() / 3;
        if(w > 2){
            setbet(w*2);
        }
        std::cout << getname() << " bets $" << getbet() << std::endl;
    }
    private:
    int wins;   //record how many times Meek has won
};

class Random: public Player{ 
    public:
    Random():Player(){
        setbankroll(100);  //start with 100 dollar
        setname("Random");
        display();
    };
    void strategy(int decknumber, Deck Deck[]){    //需要定義virtual function
        std::cout << getname() << "'s turn.\n ------------" << std::endl;
        while(getlose() == false){
            int Hand = gethand();
            if(Hand <= 9){
                draw(decknumber, Deck);
                // std::cout << getname() << " chooses to draw." << std::endl;
            }
            //10-12 points, he draws with random probability 80%
            else if(Hand >= 10 && Hand <= 12){
                int n = (int) (4) * (double)rand()/RAND_MAX ;
                if(n != 1){
                    //1 is just a random number. This conditional has an 80% chance of happening.
                    draw(decknumber, Deck);
                    // std::cout << getname() << " chooses to draw." << std::endl;
                }
            }
            //13-15 points he draws 70%
            else if(Hand >= 13 && Hand <= 15){
                int n = (int) (8) * (double)rand()/RAND_MAX ;
                if(n != 1 && n != 2 && n != 3){
                    //This conditional has an 70% chance of happening.
                    draw(decknumber, Deck);
                    // std::cout << getname() << " chooses to draw." << std::endl;
                }
            }
            //16-18 points, he draws with 50%
            else if(Hand >= 16 && Hand <= 18){
                int n = (int) (1) * (double)rand()/RAND_MAX ;
                if(n != 1){
                    //This conditional has an 50% chance of happening.
                    draw(decknumber, Deck);
                    // std::cout << getname() << " chooses to draw." << std::endl;
                }
            }
            //19 points or over, he never draws
            else{
                std::cout << getname() << " chooses to stay." << std::endl;    
                break;
            }
        }
        if(getlose() == true){
            std::cout << getname() << " busted at " << gethand() << " !" << std::endl;
        }
    }
    void bets(){
        //randomly bets some amount between $1 and half of his bankroll
        int n = (int) ( (getbankroll()-1) * (double)rand()/RAND_MAX)+1 ;
        std::cout << getname() << " bets $" << getbet() << std::endl;
    }
};

int main () {
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

    for(int i = 0;i < humannum;i++){    //User set Player name and bankroll
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
        for(int i = 0;i < humannum;i++){
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