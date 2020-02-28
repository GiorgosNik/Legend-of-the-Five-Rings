#include <iostream>
#include <vector>
#include <string>

#include "Card.hpp"
#include "Card.cpp"
#include "GreenCard.hpp"
#include "GreenCard.cpp"
#include "BlackCard.hpp"
#include "BlackCard.cpp"
#include "DeckBuilder.hpp"
#include "DeckBuilder.cpp"

class Player 
{
private:
    int honour;
    int balance = 0;
    list<GreenCard *> fateDeck;        
    list<BlackCard *> dynastyDeck;
    vector <Card> handCards;
    vector <dynastyCard> provinces;
    vector <Holdings> holdings;
    vector <Personalities> army;
public:
    Player(int handCards);

    int getBalance();
    void setBalance();
    int getHonour();
    void setHonour();

    void loseProvince();

    void untapEverything();

    void drawFateCard();

    void buyProvince();
}
