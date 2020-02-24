#include "GreenCard.hpp"
using namespace std;
GreenCard::GreenCard(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenText,int givenEffectBonus,int givenEffectCost)
:Card(givenCost,givenName),attackBonus(givenAttBonus),defenceBonus(givenDefBonus),minimumHonnor(givenMinHonnor),cardText(givenText),effectBonus(givenEffectBonus),effectCost(givenEffectCost){}
GreenCard::GreenCard(const GreenCard& Copy)
:Card(Copy),attackBonus(Copy.attackBonus),defenceBonus(Copy.defenceBonus),minimumHonnor(Copy.minimumHonnor),cardText(Copy.cardText),effectCost(Copy.effectCost)	{}
GreenCard::~GreenCard(){}
int GreenCard::getEffectCost(){
	return effectCost;
}
void GreenCard::giveBonus(){
	attackBonus=attackBonus+effectBonus;
	defenceBonus=defenceBonus+effectBonus;
	effectBonus=0;
	effectCost=0;
}
int GreenCard::getAttackBonus(){
	return attackBonus;
}
int GreenCard::getDefenceBonus(){
	return defenceBonus;
}
void GreenCard::print(){
	cout<<"Attack Bonus: "<<attackBonus<<" Defence Bonus: "<<defenceBonus<<" Minimum Honour: "<<minimumHonnor<<" Text:"<<cardText<<" Effect Cost: "<<effectCost<<" Effect Bonus"<<effectBonus<<endl;
}
int GreenCard::getminHonour(){
	return minimumHonnor;
}

