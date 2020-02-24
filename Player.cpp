#include <iostream>
#include <vector>
#include <GreenCard>		
#include <BlackCard>		
using namespace std;

class Player 
{
private:
	int honour;
    int numOfProvinces = 4;
    int balance = 0;
    list<GreenCard*> Fate;		
    list<BlackCard*> Dynasty;
    vector<Card*> handCards;
    vector<BlackCard*> provinces;
    vector<BlackCard*> Army;
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
	int assignToArmy(int handNum,int armyNum){	//return error in int
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
};

