#include <iostream>
#include <vector>
#include "Personality.hpp"
#include "Player.hpp"
class Player;	//TEMP
using namespace std;
namespace phases{
	void startingPhase(Player& Given){
	//	Given.untapEverything();		//here
	//	Given.drawFateCard();
	//	Given.revealProvinces();		//here
		Given.printHandNumbered();
		Given.printProvincesNumbered();
		Given.resetCashPool();
		Given.undeploy();
	};


	void equipPhase(Player& Given){
		int handNum,armyNum,rez;
		string input;
		if(Given.isArmyEmpty()==false){
			Given.printHandNumbered();
			cout<<"Select a Fate Card with the displayed number, select 0 to exit"<<endl;
			cin>>handNum;									//Select Green Card
			while(handNum<0||handNum>Given.getHandSize()){	//Input Guard for handNum
				cout<<"Bad input, please try again"<<endl;
				cin>>handNum;
			}
			if(handNum!=0){
			if(Given.payment(Given.getCardAt(handNum)->getCost())){
				cout<<"Do you want to upgrade? Y/N"<<endl;
				cin>>input;										//Upgrade Green Card? 
				while(input!="Y"&&input!="N"){					//Input Guard for input
					cout<<"Wrong input, please use Y/N"<<endl;
					cin>>input;
				}
				if(input=="Y"){
					Given.upgradeHand(handNum);		//here
				}
				cout<<"Assign to whom?"<<endl;
				Given.printArmyNumbered();
				cin>>armyNum;
				while(armyNum<1||handNum>Given.getArmySize()){	//Input Guard for armyNum
					cout<<"Bad input, please try again"<<endl;
					cin>>armyNum;
				}
				rez=Given.assignToArmy(handNum,armyNum);
				if(rez==0){										//Posible Results
					cout<<"This personality does not have enough honour."<<endl;
				}else if(rez==1){
					cout<<"This personality has too many Items"<<endl;
				}else if(rez==2){
					cout<<"This personality has too many Followers"<<endl;
				}else{
					cout<<"Assigned succesfully"<<endl;
				}
			}else{
				cout<<"Not enought funds"<<endl;
			}	
		}else{
			cout<<"Exiting"<<endl;
		}
		}else{
			cout<<"No army to equip with Items and Followers."<<endl;
		}
	};
	void battlePhase(Player& Given,vector<Player*> Players){
		int selection,provinceSelection,armySelection,attackScore,defenceScore;
		string input;
		Player* target;
		vector<Personality*> toAttack;
		do{	//Deployment Sellection
			cout<<"Select Personalities to use in Battles, Select 0 to confirm:"<<endl;
			Given.printUntappedArmyNumbered();
			cin>>armySelection;
			while(armySelection<0||armySelection>Given.getUnTappedNumber()){	//Input Guard for armySelection
				cout<<"Bad input, please try again"<<endl;
				cin>>armySelection;
			}
			if(Given.deploy(armySelection)){
				cout<<"Personality added to Battle Force"<<endl;
			}else{
				cout<<"Personality already added"<<endl;
			}
		}while(armySelection!=0);
		
		cout<<"Do you want to attack? Y/N"<<endl;
		cin>>input;
		if(input=="Y"){
		for(int h=0;h<Players.size();h++){			//Loop to Print Players Numbered
			cout<<h+1<<": ";Players.at(h)->printName();cout<<endl;
		}
		cout<<"Who do you want to target?"<<endl;
		cin>>selection;
		while((Players.at(selection-1))==&Given){	//Input Guard for selection
			cout<<"You cannot attack yourself, please select someone else:"<<endl;
			for(int h=0;h<Players.size();h++){  //Loop to Print Players Numbered
				cout<<h+1<<": ";Players.at(h)->printName();cout<<endl;
			}
			cin>>selection;
		}
		target=Players.at(selection-1);
		target->printProvincesNumbered();
		cout<<"Select a province to Attack: "<<endl;
		Players.at(selection-1)->printProvincesNumbered();
		cin>>provinceSelection;
		while(provinceSelection>Players.at(selection)->getProvinceNumber()||provinceSelection<=0){	//Input Guard for provinceSelection
		cout<<"Bad input, please try again."<<endl;
		cin>>provinceSelection;
		}
		attackScore=Given.getDeployedAttack();
		defenceScore=Players.at(selection)->getDeployedDefence();
		if(attackScore>defenceScore){
			cout<<"Victory: Province Destroyed"<<endl;
			Players.at(selection-1)->killProvince(provinceSelection);
			Players.at(selection-1)->killArmy();
		}else if(attackScore>defenceScore-Players.at(selection-1)->getKeepDefence()){
			cout<<"Your army could not destroy the Province, but destroyed the enemy Army"<<endl;
			Players.at(selection-1)->killArmy();
			Given.killAtLeast(attackScore-defenceScore-Players.at(selection-1)->getKeepDefence());
			Given.loseAttack();
		}else if(attackScore==defenceScore-Players.at(selection-1)->getKeepDefence()){
			cout<<"Both Armies Destroyed"<<endl;
			Players.at(selection-1)->killArmy();
			Given.killArmy();
		}else{
			cout<<"Defeat: Your army was destroyed"<<endl;
			Given.killArmy();
			Players.at(selection)->killAtLeast(defenceScore+Players.at(selection-1)->getKeepDefence()-attackScore);
		}
		Given.removeDead();
		Players.at(selection)->removeDead();
		}
	};
	void economyPhase(Player& Given){
	};
	void finalPhase(Player& Given){
		
	};
};
