#include "Green.hpp"
using namespace std;
Green::Greenstring givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenTextm,givenEffectCost)
:Card(givenName,givenCost),attackBonus(givenAttBonus),deffenceBonus(givenDefBonus),minimumHonnor(givenMinHonnor),cardText(givenText),effectCost(givenEffectCost){	
cout<<"Green Card just created"<<endl;
}
Green::Green(const Green& Copy)
:Card(Copy),attackBonus(Copy.attackBonus),deffenceBonus(Copy.defenceBonus),minimumHonnor(Copy.minimumHonnor),cardText(Copy.cardText),effectCost(Copy.effectCost){	
{
cout<<"Green Card just created"<<endl;
}
Green::~Green(){
	cout<<"Green Card just destroyed"<<endl;
}
int Green::getCost(){
	return effectCost;
}
void Green::effectBonus(){
	//What do we do?
}

