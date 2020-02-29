#include <iostream>
#include <vector>
#include "GreenCard.hpp"
#include "BlackCard.hpp"
#include "Holding.hpp"
#include "Personality.hpp"
#include "Stronghold.hpp"
#include <list>
#include "Player.hpp"
#include "TypeConverter.hpp"
#include "DeckBuilder.hpp"
using namespace std;


Player::Player(int cardsAtHand,string name):Name(name){
DeckBuilder builder;
fateDeck=builder.createFateDeck();
dynastyDeck=builder.createDynastyDeck();
builder.deckShuffler(fateDeck);
builder.deckShuffler(dynastyDeck);
Keep=new Stronghold("Demonic Castle");
for(int i=0;i<cardsAtHand;i++){
	drawFateCard();
}
for(int i=0;i<getProvinceNumber();i++){
	provinces.push_back(drawDynastyCard());
}
}

int Player::getHonour(){
    return honour;
}

void Player::setHonour(){
    honour=Keep->getHonour();

}

/*void Player::loseProvince(string name)
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
}*/

void Player::untapEverything() {
    
}

void Player::drawFateCard(){
    handCards.push_back(fateDeck->front());
    fateDeck->pop_back();        
}
BlackCard* Player::drawDynastyCard(){
	BlackCard* toReturn;
	toReturn=dynastyDeck->back();
	dynastyDeck->pop_back();
	return toReturn;
}


    bool Player::isArmyEmpty(){
    	return Army.empty();
	}
	void Player::resetCashPool(){
		balance=0;
	}
	void Player::printHandNumbered(){
		for(int i=0;i<handCards.size();i++){
			cout<<i+1<<": ";
			handCards.at(i)->print();
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
		}else{
			if(Army.at(armyNum-1)->getFollowerNumber()==false){
				return 2;
			}
			Army.at(armyNum-1)->giveFollower(*converter.getFollower(handCards.at(handNum-1)));
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
	void Player::printProvincesNumbered(){
		for(int i=0;i<provinces.size();i++){
			if(provinces.at(i)->getIsTapped()==false){
			cout<<i+1<<": ";provinces.at(i)->printName();cout<<endl;	
			}else{
				cout<<i+1<<"Province is hidden"<<endl;
			}
			
		}
	}
	bool Player::payment(int cost){
		int cumulative;
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
		return false;
	}
	bool Player::upgradeHand(int handNum){
		if(payment(handCards.at(handNum-1)->getCost())){
			handCards.at(handNum-1)->giveBonus();
			return true;
		}else{
			return false;
		}
	}
	int Player::getProvinceNumber(){
		return provinces.size();
	}
	bool Player::deploy(int selection){
		int i=0;
		int j=0;
		while(j<selection){
			if(Army.at(i)->getIsTapped()){
				j++;
			}
		}
		for(int k=0;k<Deployed.size();k++){
			if(Army.at(i)==Deployed.at(k)){
				return false;
			}
		}
		
		Deployed.push_back(Army.at(i));
		return true;
	}
	void Player::undeploy(){
		Deployed.clear();
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
	int Player::getDeployedAttack(){
		int sum=0;
		for(int i=0;i<Deployed.size();i++){
			sum+=Deployed.at(i)->getAttack();
		}
		return sum;
	}
	int Player::getDeployedDefence(){
		int sum=0;
		for(int i=0;i<Deployed.size();i++){
			sum+=Deployed.at(i)->getDefence();
		}
		return sum;
	}
	int Player::getKeepDefence(){
		return Keep->getDefence();
	}
	void Player::killArmy(){
		for(int i=0;i<Deployed.size();i++){
			Deployed.at(i)->setDeath();
		}
	}
	void Player::killProvince(int toKill){
		toKill--;
		//later
	}
	void Player::killAtLeast(int points){
		int i=0;
		while(i<Deployed.size()&&points>0){
			points=Deployed.at(i)->removeAtLeast(points);
			if(points>0){
				Deployed.at(i)->setDeath();
			}
			i++;
		}
	}
	void Player::loseAttack(){
		for(int i=0;i<Deployed.size();i++){
			Deployed.at(i)->defeat();
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
		return handCards.at(index);
	}


