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
    vector<BlackCard*> Army;
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
		for(int i=0;i<provinces.size();i++){
			if(provinces.at(i)->getIsTapped()==false){ //Adding Harvest of untapped provinces to cumulative
				cumulative+=provinces.at(i)->getHarvestValue();
				if(cumulative>=cost){	//If it becomes enough
					balance=cumulative-cost;
					Keep->tapp();
					for(j=0;j<=i;j++){
						provinces.at(j)->tapp();
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
};

