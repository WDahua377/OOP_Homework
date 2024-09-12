#include <iostream>
#include <time.h>
#include <string>
#include <cstdlib>

class Card {
private:
    int rank;
    enum Suit {spade, heart, diamond, club} suit;
    int value;
    bool flag;  //true if it's drawn, false if it's not

public:
    Card():flag(false){}
    void setcard(int s, int v); //set card suit to s, value to v
    void setsuit(int s);    //set card suit to s
    void setrank(int r);    //set card rank to r
    void setvalue(int v);   //set card value to v
    void draw();    //the card has been drawn
    bool getflag();     //return whether the card has been drawn(true) or not(false)
};

typedef Card Deck[51];    //Deck[which deck][which card in a deck]

class Player {
public:
    Player():hand(0), lose(false){}
    //strategy that decide whether to draw or not
    virtual void strategy(int decknumber, Deck Deck[]) = 0; //pure virtual function

    //how much does the Player want to bet with
    virtual void bets() = 0;    //pure virtual function

    void setbankroll(int n);    //set bankroll to n
    void setbet(int n);     //set bet to n
    void sethand(int n);    //set hand to n
    void setname(std::string s);    //set name to s
    void setowncard(std::string s);     //set owncard to s
    void display();     //display all information of player
    std::string getname();  //get Player name
    void draw(int decknumber, Deck Deck[]);     //player draw a card
    int gethand();  //return hand
    int getbet();   //return bet
    int getbankroll();  //return bankroll
    void computevalue(int rank);    //compute hand value
    void bust(int value);   //check if player is bust
    bool getlose(); //reutrn lose
    std::string getowncard();   //return what cards Player has in hand
    void display(int rank, int suit);
    int computemoney();     //compute who lose money
    void computehouse(int n);   //compute house money

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
    void strategy(int decknumber, Deck Deck[]) override;
    void bets() override;
private:
};

class Dealer: public Player{
    public:
    Dealer():Player(){}

    void strategy(int decknumber, Deck Deck[]) override;
    void bets() override;
};

class Meek: public Player{ 
public:
    Meek():wins(0), Player(){}
    void setwins(int n);    //set the number of wins to n
    int getwins();  //return wins
    void strategy(int decknumber, Deck Deck[]) override;
    void bets() override;

private:
    int wins;   //record how many times Meek has won
};

class Random: public Player{ 
public:
    Random():Player(){}
    void strategy(int decknumber, Deck Deck[]) override;
    void bets() override;
};