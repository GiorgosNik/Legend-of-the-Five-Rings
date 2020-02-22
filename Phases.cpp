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
	};
	void equipPhase(Player& Given){
		//Only if army is not empty
		int handNum,armyNum;
		string upgrade;
		if(Given.isArmyEmpy()==false){
			Given.prinHandNumbered();
			cout<<"Select a card: "<<endl;
			cin>>handNum;
			cout<<"Do you want to upgrade? Y/N"<<endl;
			cin>>upgrade;
			while(upgrade!="Y"&&upgrade!="N"){
				cout<<"Wrong input, please use Y/N"<<endl;
				cin>>upgrade;
			}
			//remove it from the vector
			
		}
	};
	void battlePhase(Player& Given){
		
	};
	void economyPhase(Player& Given){
		
	};
	void finalPhase(Player& Given){
		
	}
}
