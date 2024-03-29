#include <iostream>
#include <vector>
#include "Personality.hpp"
#include "Player.hpp"
#include "Phases.hpp"
using namespace std;

	void Phases::startingPhase(Player& Given){
		cout<<"###############################################################\n"<<endl;
		cout<<endl<<"STARTING  PHASE"<<endl;
		Given.untapEverything();
		Given.drawFateCard();
		Given.revealProvinces();
		Given.printProvinces();
		Given.printHand();
		Given.resetCashPool();
		Given.unarena();
	}
	void Phases::equipPhase(Player& Given){
		cout<<"###############################################################\n"<<endl;
		cout<<endl<<"EQUIP PHASE"<<endl;
		int handNum,armyNum,rez;
		string input;
		if(Given.isArmyEmpty()==false){
			Given.printHand();
			cout<<"Select a Fate Card with the displayed number, select 0 to exit"<<endl;
			cin>>handNum;									//Select Green Card
			while(handNum<0||handNum>Given.getHandSize()){	//Input Guard for handNum
				cout<<"Bad input, please try again"<<endl;
				cin>>handNum;
			}
			while(handNum!=0){
			if(Given.payment(Given.getCardAt(handNum)->getCost())){
				cout<<"Do you want to upgrade? Y/N"<<endl;
				cin>>input;										//Upgrade Green Card?
				while(input!="Y"&&input!="N"){					//Input Guard for input
					cout<<"Wrong input, please use Y/N"<<endl;
					cin>>input;
				}
				if(input=="Y"||input=="y"){
					Given.upgradeHand(handNum);
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
			Given.printHand();
			cout<<"Select a Fate Card with the displayed number, select 0 to exit"<<endl;
			cin>>handNum;									//Select Green Card
			while(handNum<0||handNum>Given.getHandSize()){	//Input Guard for handNum
				cout<<"Bad input, please try again"<<endl;
				cin>>handNum;
			}
		}
			cout<<"Exiting"<<endl;
		
		}else{
			cout<<"No army to equip with Items and Followers."<<endl;
		}
	}
	void Phases::battlePhase(Player& Given,vector<Player*>& Players){
		cout<<"###############################################################\n"<<endl;
		cout<<endl<<"BATTLE PHASE"<<endl;
		int selection,provinceSelection,armySelection,attackScore,defenceScore;
		string input;
		Player* target;
		vector<Personality*> toAttack;
		if(Given.isArmyEmpty()==false){
		do{	//Arena Sellection
			cout<<"Select Personalities to use in Battles, Select 0 to confirm:"<<endl;
			Given.printUntappedArmyNumbered();
			cin>>armySelection;
			while(armySelection<0||armySelection>Given.getUnTappedNumber()){	//Input Guard for armySelection
				cout<<"Bad input, please try again"<<endl;
				cin>>armySelection;
			}
			if(armySelection!=0){
				if(Given.arena(armySelection)){
				cout<<"Personality added to Battle Force"<<endl;
			}
			}
		}while(armySelection!=0);

		if(Given.isArenaEmpty()==false){
		cout<<"Do you want to attack? Y/N"<<endl;
		cin>>input;
		if(input=="Y"||input=="y"){
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
		target->printProvinces();
		cout<<"Select a province to Attack: "<<endl;
		cin>>provinceSelection;
		while(provinceSelection-1>target->getProvinceNumber()||provinceSelection<=0){	//Input Guard for provinceSelection
		cout<<"Bad input, please try again."<<endl;
		cin>>provinceSelection;
		}
		cout<<"Province Selected"<<endl;
		attackScore=Given.getArenaAttack();
		defenceScore=Players.at(selection-1)->getArenaDefence();
		defenceScore+=Players.at(selection-1)->getKeepDefence();
		cout<<"Attack Score"<<attackScore<<endl;
		cout<<"Defence Score"<<defenceScore<<endl;
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
			Players.at(selection-1)->killAtLeast(defenceScore+Players.at(selection-1)->getKeepDefence()-attackScore);
		}
		Given.removeDead();
		Players.at(selection-1)->removeDead();
		}
	}else{
		cout<<"You are unable to Attack because you did not select any Personalities."<<endl;
	}
	}else{
		cout<<"You have no Personalities to choose from"<<endl;
	}
	}
	void Phases::economyPhase(Player& Given){
		cout<<"###############################################################\n"<<endl;
		int selection;
		cout<<endl<<"ECONOMY PHASE"<<endl;
		do{
			Given.printProvinces();
			cout<<"Select a Province to buy (1-"<<Given.getProvinceNumber()<<"), select 0 to end Economy Phase"<<endl;
			cin>>selection;
			while(selection<0||selection>Given.getProvinceNumber()){
				cout<<"Bad Input. Please try again."<<endl;
				cin>>selection;
			}
			if(selection!=0){
			if(Given.provinceIsTapped(selection)==false){
			if(Given.payment(Given.getProvinceCost(selection))){
				Given.buyProvince(selection);
			}
		}
		}
		}while(selection!=0);
		cout<<"ENDING ECONOMY PHASE"<<endl;
	};
	void Phases::finalPhase(Player& Given,vector<Player*>& players){
		cout<<"###############################################################\n"<<endl;
		cout<<"FINAL PHASE"<<endl;
		Given.discardSurplusFateCards();
		for(int i=0;i<players.size();i++){
			cout<<"Stats for Player: ";players.at(i)->printName();cout<<endl;
			players.at(i)->printGameStatistics();
			cout<<"Provinces:"<<endl;
			players.at(i)->printProvinces();
			cout<<"Hand: "<<endl;
			players.at(i)->printHand();
			cout<<"Holdings:"<<endl;
			players.at(i)->printHoldings();
		}
		cout<<endl<<"Press ENTER to end your turn...\n"<<endl;
		cin.get();
	}