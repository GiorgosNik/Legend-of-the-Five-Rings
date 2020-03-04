#include <iostream>
#include <vector>
#include "GreenCard.hpp"
#include "BlackCard.hpp"
#include "Item.hpp"
#include "Holding.hpp"
#include "Personality.hpp"
#include "Stronghold.hpp"
#include <list>
#include "Player.hpp"
#include "TypeConverter.hpp"
#include "DeckBuilder.hpp"
using namespace std;


Player::Player(int cardsAtHand,string name):Name(name),maxAtHand(cardsAtHand){
deck=new DeckBuilder;
fateDeck=deck->createFateDeck();
dynastyDeck=deck->createDynastyDeck();
deck->deckShuffler(fateDeck);
deck->deckShuffler(dynastyDeck);
Keep=new Stronghold("Demonic Castle");
for(int i=0;i<cardsAtHand;i++){
	drawFateCard();
}
for(int i=0;i<4;i++){
	provinces.push_back(drawDynastyCard());
}
}
Player::~Player(){
	delete deck;
}
void Player::discardSurplusFateCards(){
	while(handCards.size()>maxAtHand){
		handCards.erase(handCards.begin()+maxAtHand);
	}
}

int Player::getHonour(){
    return honour;
}

void Player::setHonour(){
    honour=Keep->getHonour();

}
void Player::drawFateCard(){
	if(fateDeck->empty()==false){
		handCards.push_back(fateDeck->back());
    	fateDeck->pop_back();
	}else{
		cout<<"You run out of cards..."<<endl;	//Model Later
	}
}
bool Player::provinceIsTapped(int selection){
	selection--;
	return provinces.at(selection)->getIsTapped();
}
BlackCard* Player::drawDynastyCard(){
	BlackCard* toReturn;
	toReturn=dynastyDeck->back();
	dynastyDeck->pop_back();
	toReturn->tapp();
	return toReturn;
}
void Player::revealProvinces(){
	for(int i=0;i<provinces.size();i++){
		provinces.at(i)->untap();
	}
}
void Player::untapEverything(){
	for(int i=0;i<Army.size();i++){
		Army.at(i)->untap();
	}
	for(int i=0;i<Holdings.size();i++){
		Holdings.at(i)->untap();
	}
	Keep->untap();
}

    bool Player::isArmyEmpty(){
    	return Army.empty();
	}
	void Player::resetCashPool(){
		balance=0;
	}
	void Player::printHand(){
		cout<<endl;
		for(int i=0;i<handCards.size();i++){
			cout<<i+1<<": ";
			handCards.at(i)->print();
			cout<<endl;
		}
	}
	int Player::getHandSize(){
		return handCards.size();
	}
	void Player::printArmyNumbered(){
		for(int i=0;i<Army.size();i++){
			cout<<i+1<<": ";
			Army.at(i)->print();
		}
	}
	int Player::getArmySize(){
		return handCards.size();
	}
	int Player::assignToArmy(int handNum,int armyNum){
		TypeConverter converter;
		if(handCards.at(handNum-1)->getminHonour()>Army.at(armyNum-1)->getHonour()){
			return 0;
		}
		if(converter.getItem(handCards.at(handNum-1))!=NULL){
			if(Army.at(armyNum-1)->getItemNumber()==false){
				return 1;
			}
			Army.at(armyNum-1)->giveItem(*converter.getItem(handCards.at(handNum-1)));
			handCards.erase(handCards.begin()+handNum-1);
			return 3;
		}else{
			if(Army.at(armyNum-1)->getFollowerNumber()==false){
				return 2;
			}
			Army.at(armyNum-1)->giveFollower(*converter.getFollower(handCards.at(handNum-1)));
			handCards.erase(handCards.begin()+handNum-1);
			return 3;
		}

	}
	void Player::printTappedArmyNumbered(){
		int j=1;
		for(int i=0;i<Army.size();i++){
			if(Army.at(i)->getIsTapped()){
				cout<<j<<": ";
				j++;
				Army.at(i)->print();
			}
		}
	}
	void Player::printUntappedArmyNumbered(){
		int j=1;
		for(int i=0;i<Army.size();i++){
			if(Army.at(i)->getIsTapped()!=true){
				cout<<j<<": ";
				j++;
				Army.at(i)->print();
			}
		}
	}
	void Player::tapArmy(int toTap){
		Army.at(toTap)->tapp();
	}
	void Player::printName(){
		cout<<Name;
	}
bool Player::isArenaEmpty(){
	return (Arena.size()==0);
}
	void Player::printProvinces(){
		cout<<"Provinces: "<<endl;
		for(int i=0;i<provinces.size();i++){
			if(provinces.at(i)->getIsTapped()==false){
			cout<<i+1<<": ";provinces.at(i)->printName();cout<<endl;
			}else{
				cout<<i+1<<": Province is hidden"<<endl;
			}
		}
	}
void Player::buyProvince(int selection)	{
	selection--;
	TypeConverter converter;
	if(converter.getHolding(provinces.at(selection))!=NULL){
		Holdings.push_back(converter.getHolding(provinces.at(selection)));
		if(Holdings.back()->getMineType()==0){
			cout<<"Holding added successfully."<<endl;
		}else{
			cout<<"New Holding might be able to form a chain."<<endl<<"Atemtping Now..."<<endl;
			if(Holdings.back()->getMineType()==MINE){		//New Holding is of type MINE
			cout<<"Searching for Gold Mine"<<endl;
				for(int i =0;i<Holdings.size()-1;i++){
					if(Holdings.at(i)->getMineType()==GOLDMINE&&Holdings.at(i)->canChainLow()){
						Holdings.at(i)->giveLow(Holdings.back());
						Holdings.back()->giveUpper(Holdings.at(i));
						cout<<"Formed a Chain with a Gold Mine."<<endl;
						break;
					}
				}
			}else if(Holdings.back()->getMineType()==GOLDMINE){
				cout<<"Searching for Mine or Crystal Mine"<<endl;
				for(int i=0;i<Holdings.size()-1;i++){
					if(Holdings.at(i)->getMineType()==CRYSTALMINE&&Holdings.at(i)->canChainLow()){
						Holdings.at(i)->giveLow(Holdings.back());
						Holdings.back()->giveUpper(Holdings.at(i));
						cout<<"Formed Chain with a Crystal Mine."<<endl;
						break;
					}
				}
				for(int i =0;i<Holdings.size()-1;i++){
					if(Holdings.at(i)->getMineType()==MINE&&Holdings.at(i)->canChainUp()){
						Holdings.at(i)->giveUpper(Holdings.back());
						Holdings.back()->giveLow(Holdings.at(i));
						cout<<"Formed a Chain with a Mine."<<endl;
						break;
					}
				}
			}else{
				cout<<"Searching for Gold Mine"<<endl;
				for(int i =0;i<Holdings.size()-1;i++){
					if(Holdings.at(i)->getMineType()==GOLDMINE&&Holdings.at(i)->canChainUp()){
						Holdings.at(i)->giveUpper(Holdings.back());
						Holdings.back()->giveLow(Holdings.at(i));
						cout<<"Formed a Chain with a Gold Mine."<<endl;
						break;
					}
				}
			}
		}
	}else{
		Army.push_back(converter.getPersonality(provinces.at(selection)));
	}
	provinces.at(selection)=drawDynastyCard();

}
void Player::printArena(){
	for(int i=0;i<Arena.size();i++){
		Arena.at(i)->print();
	}
}
void Player::printHoldings(){
	for(int i=0;i<Holdings.size();i++){
		Holdings.at(i)->print();
	}
}
void Player::printGameStatistics(){
	cout<<"Has "<<getProvinceNumber()<<" provinces."<<endl;
	cout<<"Has "<<Holdings.size()<<" Holdings"<<endl;
	cout<<"Has "<<Army.size()<<" in his Army, of which "<<Arena.size()<<" are in the Arena"<<endl;
}
int Player::getProvinceCost(int selection){
	selection--;
	return provinces.at(selection)->getCost();
}
	bool Player::payment(int cost){
		int cumulative,startingCost;
		startingCost=cost;
		cumulative=balance;
		if(Keep->getIsTapped()==false){
			cumulative+=Keep->getHarvestValue();
		}
		if(cumulative>=cost){	//Cost covered by balance or Keep Harvest
			balance=cumulative-cost;
			Keep->tapp();
			return true;
		}
		for(int i=0;i<Holdings.size();i++){
			if(Holdings.at(i)->getIsTapped()==false){ //Adding Harvest of untapped provinces to cumulative
				cumulative+=Holdings.at(i)->getHarvestValue();
				if(cumulative>=cost){	//If it becomes enough
					balance=cumulative-cost;
					Keep->tapp();
					for(int j=0;j<=i;j++){
						Holdings.at(j)->tapp();
					}
					return true;
				}
			}
		}
		cout<<"Unable to pay cost: "<<startingCost<<endl;
		return false;
	}
	bool Player::upgradeHand(int handNum){
		handNum--;
		if(payment(handCards.at(handNum)->getEffectCost())){
			handCards.at(handNum)->giveBonus();
			return true;
		}else{
			return false;
		}
	}
	int Player::getProvinceNumber(){
		return provinces.size();
	}
	bool Player::arena(int selection){
		selection--;
		if(Army.at(selection)->getIsTapped()){
			cout<<"Cant add this, it is Taped"<<endl;
			return false;
		}
		for(int k=0;k<Arena.size();k++){
			if(Army.at(selection)==Arena.at(k)){
				cout<<"Personality Already Arena."<<endl;
				return false;
			}
		}
		Arena.push_back(Army.at(selection));
		return true;
	}
	void Player::unarena(){
		Arena.clear();
	}
	int Player::getUnTappedNumber(){
		int	num;
		for(int i=0;i<Army.size();i++){
			if(Army.at(i)->getIsTapped()==false){
				num++;
			}
		}
		return num;
	}
	int Player::getArenaAttack(){
		int sum=0;
		for(int i=0;i<Arena.size();i++){
			sum+=Arena.at(i)->getAttack();
		}
		return sum;
	}
	int Player::getArenaDefence(){
		int sum=0;
		for(int i=0;i<Arena.size();i++){
			sum+=Arena.at(i)->getDefence();
		}
		return sum;
	}
	int Player::getKeepDefence(){
		return Keep->getDefence();
	}
	void Player::killArmy(){
		for(int i=0;i<Arena.size();i++){
			Arena.at(i)->setDeath();
		}
	}
	void Player::killProvince(int toKill){
		toKill--;
		cout<<"Province destroyed"<<endl;
		provinces.erase(provinces.begin()+toKill);
	}
	void Player::killAtLeast(int points){
		int i=0;
		while(i<Arena.size()&&points>0){
			points=Arena.at(i)->removeAtLeast(points);
			if(points>0){
				Arena.at(i)->setDeath();
			}
			i++;
		}
	}
	void Player::loseAttack(){
		for(int i=0;i<Arena.size();i++){
			Arena.at(i)->defeat();
		}
	}
	void Player::removeDead(){
		for(int i=0;i<Army.size();i++){
			if(Army.at(i)->getIsAlive()==false){
				Graveyard.push_back(Army.at(i));
				Army.erase(Army.begin()+i);
			}
		}
	}
	GreenCard* Player::getCardAt(int index){
		return handCards.at(index-1);
	}
