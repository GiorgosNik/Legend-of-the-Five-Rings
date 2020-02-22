#include <iostream>
#include <vector>
using namespace std;
namespace phases{
	void startingPhase(Player& Given){
		Given.untapEverything();
		Given.drawFateCard();
		Given.revealProvinces();
		Given.printHand();
		Given.printProvinces();
		Given.resetCashPool();		//here
	};
	void equipPhase(Player& Given){
		int handNum,armyNum;
		string input;
		if(Given.isArmyEmpy()==false){
			do{
			Given.prinHandNumbered();	//here
			cout<<"Select a Fate Card: "<<endl;
			cin>>handNum;
			while(handNum<1||handNum>Given.getHandSize()){	//Here
				cout<<"Bad input, please try again"<<endl;
				cin>>handNum;
			}
			cout<<"Do you want to upgrade? Y/N"<<endl;
			cin>>input;
			while(input!="Y"&&input!="N"){
				cout<<"Wrong input, please use Y/N"<<endl;
				cin>>input;
			}
			if(input=="Y"){
				Given.upgradeHand(handNum);		//here
			}
			cout<<"Assign to whom?"<<endl;
			Given.printArmyNumbered();		//Here
			cin>>armyNum;
			while(armyNum<1||handNum>Given.getArmySize()){	//Here
				cout<<"Bad input, please try again"<<endl;
				cin>>armyNum;
			}
			Given.assignToArmy(handNum,armyNum);		//Here
			cout<<"Want to get anything else? Y/N"<<endl;
			cin>>input;
			}while(input!=N)
		}
	};
	void battlePhase(Player& Given){
		
	};
	void economyPhase(Player& Given){
		
	};
	void finalPhase(Player& Given){
		
	}
}
