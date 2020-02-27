#include <iostream>
#include <vector>
#include "GreenCard.hpp"
#include "BlackCard.hpp"
#include "Holding.hpp"
#include "Stronghold.hpp"
using namespace std;

class Player 
{
private:
	string Name; //my adition
	int honour;
    int numOfProvinces = 4;
    int balance = 0;
    list<GreenCard*> Fate;		
    list<BlackCard*> Dynasty;
    vector<GreenCard*> handCards;	//my change
    vector<BlackCard*> provinces;
    vector<Holding*>	Holdings;	//my change
    vector<Personality*> Army;
    //vector<Personality*> Deployed;		//Mine 
    Stronghold* Keep;		//my aadition
public:
    Player(int handCards)
	{
		
	}

    void loseProvince()
	{
	    //player loses a health point
        numOfprovinces--;
    }

    void untapEverything()
	{
        //change state of all player cards to untapped
    }

    void drawFateCard()
	{
		
    }

    void buyProvince()
	{
        for(int n : dynDeck)
		{
            if(dynDeck<n>.isProvince)
			{
                
                cout << "Buy province? (1 : Yes/0 : No)";
                int choice;
                cin >> choice;
                if (choice == 1 && dynDeck<n>.getPrice <= balance)
				{
                    provinces.pushback(dynDeck<n>);
                    //remove card from dyndeck?
                    //remove money from balance
                    //increment province counter

                }

            }

        }

    }
    //----------------------------------MINE------------------------------------
    bool isArmyEmpty(){
    	return Army.empty();
	}
	void resetCashPool(){
		balance=0;
	}
	void printHandNumbered(){
		for(i=0;i<handCards.size();i++){
			cout<<i+1<<": ";
			handCards.at(i)->print();
		}
	}
	int getHandSize(){
		return handCards.size();
	}
	void printArmyNumbered(){
		for(i=0;i<Army.size();i++){
			cout<<i+1<<": ";
			Army.at(i)->print();
		}
	}
	int getArmySize(){
		return handCards.size();
	}
	int assignToArmy(int handNum,int armyNum){
		if(handCard.at(handNum-1)->getminHonour>Army.at(armyNum-1)->getHonour){
			return 0;
		}
		if(getItem(handCards.at(handNum-1))!=NULL){
			if(Army.at(armyNum-1)->getItemNumber()==false){
				return 1;
			}
			Army.at(armyNum-1)->giveItem(*handCards.at(handNum-1));
		}else{
			if(Army.at(armyNum-1)->getFollowerNumber()==false){
				return 2;
			}
			Army.at(armyNum-1)->giveFollower(*handCards.at(handNum-1));
			return 3;
		}
		
	}
	void printTappedArmyNumbered(){
		j=1;
		for(i=0;i<Army.size();i++){
			if(Army.at(i)->getIsTapped()){
				cout<<j<<": ";
				j++;
				Army.at(i)->print();
			}
		}
	}
	void printUntappedArmyNumbered(){
		j=1;
		for(i=0;i<Army.size();i++){
			if(Army.at(i)->getIsTapped()!=true){
				cout<<j<<": ";
				j++;
				Army.at(i)->print();
			}
		}
	}
	void tapArmy(int toTap){
		Army.at(toTap)->tapp();
	}
	void printName(){
		cout<<name;
	}
	void printProvincesNumbered(){
		for(int i=0;i<provinces.size();i++){
			cout<<i+1<<": ";provinces.at(i)->printName();cout<<endl;
		}
	}
	bool payment(int cost){
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
					for(j=0;j<=i;j++){
						Holdings.at(j)->tapp();
					}
					return true;
				}
			}
		}
		return false;
	}
	bool upgradeHand(int handNum){
		if(payment(handCards.at(handNum-1)->getCost())){
			handCards.at(handNum-1)->
		}
	}
	void printProvincesNumbered(){
		for(int i=0;i<provinces.size();i++){
			cout<<i+1<<": ";
			provinces.at(i)->print();
		}
	}
	int getProvinceNumber{
		return numOfProvinces;
	}
	bool deploy(int sellection){
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
	void undeploy(){
		Deployed.clear();
	}
	int getUnTappedNumber(){
		int	num;
		for(int i=0;i<Army.size();i++){
			if(Army.at(i)->getIsUnTapped()){
				num++;
			}
		}
		return num;
	}
	int getDeployedAttack(){
		int sum=0;
		for(int i=0;i<Deployed.size();i++){
			sum+=Deployed.at(i)->getAttack();
		}
		return sum;
	}
	int getDeployedDefence(){
		int sum=0;
		for(int i=0;i<Deployed.size();i++){
			sum+=Deployed.at(i)->getDefence();
		}
		return sum;
	}
	int getKeepDefence(){
		return Keep.getDefence();
	}
	void killArmy(){
		for(int i=0;i<Deployed.size();i++){
			Deployed.at(i)->setDeath();
		}
	}
	void killProvince(int toKill){
		toKill--;
		//later
	}
	void killAtLeast(int points){
		//later
	}
	void loseAttack(){
		for(int i=0;i<Deployed.size();i++){
			Deployed.at(i)->defeat();
		}
	}
	void removeDead(){

	}
};

