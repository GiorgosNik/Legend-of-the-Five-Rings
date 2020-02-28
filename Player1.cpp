#include "Player.hpp"

using namespace std;

Player::Player(int handCards)
{
	playerDeck = new DeckBuilder();
	 //nomizw xreiazetai mia function pou pernaei tis listes me tis kartes stis listes tou ekastote paikth (isws enan getter pou na epistrefei poia timh thes apo tis private lists tou deckBuilder)

	playerDeck.green.
}
	
int Player::getBalance()
{
    return balance;
}

void Player::setBalance(int bal)
{
    balance = bal;
    cout << "Balance set to: ", getBalance(), ".";
}

int Player::getHonour()
{
    return honour;
}

void Player::setHonour(int hon)
{
    honour = hon;
    cout << "Honour set to: ", getHonour(), ".";
}

void Player::loseProvince(string name)
{
    vector<dynastyCard>::iterator it_provinces; //dynDeck iterator
    for(it_provinces = provinces.begin(); it_provinces < it_provinces.end(); it_provinces ++)
    {
        if(*it_provinces.getName() == name)
        {
            cout << name, "Card found! Removing..";
            provinces.erase(it_dynastyDeck); //removes pointer to card from provinces vector
        }
    }
}

void Player::untapEverything() {
//thelei enan setter gia na allazei thn katastash isTapped stis kartes
/* ******************************************* */
//auta mporei kai na mhn xreiazetai na ginoun untapped
    vector<GreenCard *>::iterator it_fateDeck;
    vector<BlackCard *>::iterator it_dynastyDeck;
/* ******************************************* */
    vector<Card>::iterator it_handCards; //to untap handCards, mporei kai na mhn xreiazetai
    vector<dynastyCard>::iterator it_provinces; //to untap provinces
    vector<Holdings>::iterator it_holdings; //to untap holdings
    vector<Personalities>::iterator it_army; //to untap army cards
    cout << "Untapping Cards.. \n";

    for (it_handCards = handCards.begin(); it_handCards < handCards.end(); it_handCards++) 
	{
        *it_handCards.setTapped(false); //h setTapped() prepei na ftiaxtei sthn card.cpp
    }

    for (it_provinces = provinces.begin(); it_provinces < provinces.end(); it_provinces++) 
	{
        *it_provinces.setTapped(false); //h setTapped() prepei na ftiaxtei sthn card.cpp
    }

    for (it_holdings = holdings.begin(); it_holdings < holdings.end(); it_holdings++) 
	{
        *it_holdings.setTapped(false); //h setTapped() prepei na ftiaxtei sthn card.cpp
    }

    for (it_army = army.begin(); it_army < army.end(); it_army++) 
	{
        *it_army.setTapped(false); //h setTapped() prepei na ftiaxtei sthn card.cpp
    }
    cout << "Player Cards Untapped."
}

void Player::drawFateCard()
{
    handCards.push_back(fateDeck.front());      //puts first item of fate deck to hand
    fateDeck.pop_back(fateDeck.front());        //removes first card of fateDeck from list
}

void Player::buyProvince()
{
    for(int n : Dynasty)
    {
        if(Dynasty[n].isProvince)       //to Dynasty[n] einai ok gia access element? 
        {
            Dynasty[n].print();
            cout << "Buy province? (1 : Yes/0 : No)";
            int choice;
            cin >> choice;
            if (choice == 1 && Dynasty[n].getPrice <= balance)
        	{
            provinces.pushback(Dynasty[n]);
            dynastyDeck.erase(Dynasty[n]);
            balance = balance - Dynasty[n].getPrice()  //leipei h synarthsh getPrice
        	}

        }

    }

}

};
