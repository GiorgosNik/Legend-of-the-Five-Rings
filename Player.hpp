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
    int numOfProvinces = 4;
    int balance;
    list<GreenCard*> fateDeck;		
    list<BlackCard*> dynastyDeck;
    vector<GreenCard*> handCards;
    vector<BlackCard*> provinces;
    vector<Holding*>	Holdings;
    vector<Personality*> Army;
    vector<Personality*> Deployed;
    vector<Personality*> Graveyard;
    Stronghold* Keep;
public:
    Player(int cardsAtHand,string name);
    int getBalance();
    void setBalance();
    void printName();
    int getHonour();
    void setHonour();
    void loseProvince();
    void untapEverything();
    void drawFateCard();
    void buyProvince();
     bool isArmyEmpty();
	void resetCashPool();
	void printHandNumbered();
	int getHandSize();
	void printArmyNumbered();
	int getArmySize();
	int assignToArmy(int handNum,int armyNum);
	void printTappedArmyNumbered();
	void printUntappedArmyNumbered();
	void tapArmy(int toTap);
	void printProvincesNumbered();
	bool payment(int cost);
	bool upgradeHand(int handNum);
	int getProvinceNumber();
	bool deploy(int sellection);
	void undeploy();
	int getUnTappedNumber();
	int getDeployedAttack();
	int getDeployedDefence();
	int getKeepDefence();
	void killArmy();
	void killProvince(int toKill);
	void killAtLeast(int points);
	void loseAttack();
	void removeDead();
	GreenCard* getCardAt(int index);
};
