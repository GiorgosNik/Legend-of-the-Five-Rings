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
			while(handNum<1||handNum>Given.getHandSize()){
				cout<<"Bad input, please try again"<<endl;
				cin>>handNum;
			}//USE THE MONEY
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
			Given.printArmyNumbered();
			cin>>armyNum;
			while(armyNum<1||handNum>Given.getArmySize()){
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
		}
	};
	void battlePhase(Player& Given){
		
	};
	void economyPhase(Player& Given){
		
	};
	void finalPhase(Player& Given){
		
	}
}
