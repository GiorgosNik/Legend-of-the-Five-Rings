#ifndef PLAYER
#define PLAYER
#include <iostream>
#include <vector>
#include <string>
#include "TypeConverter.hpp"
#include "Card.hpp"
#include "GreenCard.hpp"
#include "BlackCard.hpp"
#include "DeckBuilder.hpp"
#include "Stronghold.hpp"
class Player{
private:
    string Name;
	int honour;
    int balance,maxAtHand;
    DeckBuilder* deck;
    list<GreenCard*>* fateDeck;
    list<BlackCard*>* dynastyDeck;
    vector<BlackCard*>* dynastyDeckVector;
    vector<GreenCard*>* fateDeckVector;
    vector<GreenCard*> handCards;
    vector<BlackCard*> provinces;
    vector<Holding*>	Holdings;
    vector<Personality*> Army;
    vector<Personality*> Arena;
    vector<Personality*> Graveyard;
    Stronghold* Keep;
    void setHonour();
public:
  Player(int cardsAtHand,string name);
  void printName();
  void revealProvinces();
  int getHonour();
  void discardSurplusFateCards();
  int getProvinceCost(int selection);
  void untapEverything();
  void drawFateCard();
  BlackCard* drawDynastyCard();
  void buyProvince(int selection);
  bool isArmyEmpty();
	void resetCashPool();
	bool isArenaEmpty();
	void printHandNumbered();
	int getHandSize();
	void printArmyNumbered();
	int getArmySize();
	int assignToArmy(int handNum,int armyNum);
	void printTappedArmyNumbered();
	void printUntappedArmyNumbered();
	void tapArmy(int toTap);
	void printProvinces();
	bool payment(int cost);
	bool upgradeHand(int handNum);
	int getProvinceNumber();
	bool arena(int sellection);
	void unarena();
	int getUnTappedNumber();
	int getArenaAttack();
	int getArenaDefence();
	int getKeepDefence();
	void killArmy();
	void killProvince(int toKill);
	void killAtLeast(int points);
	void loseAttack();
	void removeDead();
	bool provinceIsTapped(int selection);
	GreenCard* getCardAt(int index);
};
#endif		//PLAYER
