#include <iostream>
#include <vector>
#include "Personality.hpp"
class Player;	//TEMP
using namespace std;
namespace phases{
	void startingPhase(Player& Given){
	//	Given.untapEverything();		//here
	//	Given.drawFateCard();
	//	Given.revealProvinces();		//here
	//	Given.printHand();
	//	Given.printProvinces();
	//	Given.resetCashPool();
	//	Given.undeploy();
	};
	void equipPhase(Player& Given){
		int handNum,armyNum,rez;
		string input;
		if(Given.isArmyEmpy()==false){
			Given.prinHandNumbered();
			cout<<"Select a Fate Card with the displayed number, select 0 to exit"<<endl;
			cin>>handNum;									//Select Green Card
			while(handNum<0||handNum>Given.getHandSize()){	//Input Guard for handNum
				cout<<"Bad input, please try again"<<endl;
				cin>>handNum;
			}
			if(handNum!=0){
			if(Given.payment(handCards.at(handNum)->getCost)){
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
		int selection,provinceSelection,armySelection;
		string input;
		Player* target;
		vector<Personality*> toAttack;
		Given.printArmyNumberedUntapped();
		cout<<"Select Personalities to tapp, select 0 to finish selection."<<endl;
		cin>>selection;
		while(selection!=0){
			Given.tapArmy(selection-1);
			cout<<endl<<endl<<endl<<endl<<endl;
			Given.printArmyNumberedUntapped();
		}
		cout<<"Army Sellection Complete"<<endl;
		cout<<"Do you want to attack? Y/N"<<endl;
		cin>>input;
		if(input=="Y"){
		for(int h=0;h<Players.size();h++){			//Loop to Print Players Numbered
			cout<<h+1<<": ";Players.at(h)->printName();cout<<endl;
		}
		cout<<"Who do you want to target?"<<endl;
		cint>>selection;
		while(*(Players.at(selection-1))=Given){	//Input Guard for selection
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
		do{
			cout<<"Select Personalities to attack with, Select 0 to commence the Attack:"<<endl;
			Given->printTappedArmyNumbered();
			cin>>armySelection;
			while(armySellection<0||armySellection>Given->getTappedNumber()){
				cout<<"Bad input, please try again"<<endl;
				cin>>armySellection;
			}
		}while(armySellection!=0);
		
		
		
		
		
		}
	};
	void economyPhase(Player& Given){
		
	};
	void finalPhase(Player& Given){
		
	}
}
