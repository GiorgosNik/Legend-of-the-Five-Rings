#include "Green.hpp"
using namespace std;
Green::Green(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenText,int givenEffectBonus,int givenEffectCost)
:Card(givenCost,givenName),attackBonus(givenAttBonus),defenceBonus(givenDefBonus),minimumHonnor(givenMinHonnor),cardText(givenText),effectBonus(givenEffectBonus),effectCost(givenEffectCost){	
cout<<"Green Card just created"<<endl;
}
Green::Green(const Green& Copy)
:Card(Copy),attackBonus(Copy.attackBonus),defenceBonus(Copy.defenceBonus),minimumHonnor(Copy.minimumHonnor),cardText(Copy.cardText),effectCost(Copy.effectCost)	
{
cout<<"Green Card just created"<<endl;
}
Green::~Green(){
	cout<<"Green Card just destroyed"<<endl;
}
int Green::getEffectCost(){
	return effectCost;
}
void Green::giveBonus(){
	attackBonus=attackBonus+effectBonus;
	defenceBonus=defenceBonus+effectBonus;
	effectBonus=0;
	effectCost=0;
}
int Green::getAttackBonus(){
	return attackBonus;
}
int Green::getDefenceBonus(){
	return defenceBonus;
}
void Green::print(){
	cout<<"Attack Bonus: "<<attackBonus<<" Defence Bonus: "<<defenceBonus<<" Minimum Honour: "<<minimumHonnor<<" Text:"<<cardText<<" Effect Cost: "<<effectCost<<" Effect Bonus"<<effectBonus<<endl;
}

