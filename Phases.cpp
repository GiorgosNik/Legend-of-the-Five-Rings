#include <iostream>
#include <vector>
using namespace std;
namespace phases{
	void startingPhase(Player& Given){
		Given.untapEverything();	//here
		Given.drawFateCard();
		Given.revealProvinces();		//here
		Given.printHand();
		Given.printProvinces();
		Given.resetCashPool();
	};
	void equipPhase(Player& Given){
		int handNum,armyNum,rez;
		string input;
		if(Given.isArmyEmpy()==false){
			do{
			Given.prinHandNumbered();
			cout<<"Select a Fate Card: "<<endl;
			cin>>handNum;
			while(handNum<1||handNum>Given.getHandSize()){	//Input Guard for handNum
				cout<<"Bad input, please try again"<<endl;
				cin>>handNum;
			}//USE THE MONEY
			cout<<"Do you want to upgrade? Y/N"<<endl;
			cin>>input;
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
			if(rez==0){
				cout<<"This personality does not have enough honour."<<endl;
			}else if(rez==1){
				cout<<"This personality has too many Items"<<endl;
			}else if(rez==2){
				cout<<"This personality has too many Followers"<<endl;
			}else{
				cout<<"Assigned succesfully"<<endl;
			}
			cout<<"Want to get anything else? Y/N"<<endl;
			cin>>input;
			}while(input!=N)
		}else{
			cout<<"No army to equip with Items and Followers."<<endl;
		}
	};
	void battlePhase(Player& Given,vector<Player*> Players){
		int selection;
		string input;
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
		//Print the players numbered
		cout<<"Who do you want to target?"<<endl;
		cint>>selection;
		while(*(Players.at(selection-1))=Given){
			cout<<"You cannot attack yourself, please select someone else:"<<endl;
			//Print the players numbered
			cin>>selection;
		}
		}
		
	};
	void economyPhase(Player& Given){
		
	};
	void finalPhase(Player& Given){
		
	}
}
