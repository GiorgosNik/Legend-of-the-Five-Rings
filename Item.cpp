#include "Item.hpp"
using namespace std;
Item::Item(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenTextm,int givenEffectBonus,int givenEffectCost,int givenDurability)
:GreenCard(givenName,givenCost,givenAttBonus,givenDefBonus,givenMinHonnor,givenTextm,givenEffectBonus,givenEffectCost),durability(givenDurability){}
Item::Item(const Item& Copy)
:GreenCard(Copy),durability(Copy.durability){}
Item::~Item(){}
int Item::getType(){
	return ITEM;
}
void Item::print(){
	cout<<"Durability: "<<durability;
}

Katana::Katana(string GivenName):Item(GivenName,0,2,0,1,"SAMPLETEXT",1,2,3){}
Spear::Spear(string GivenName):Item(GivenName,0,0,2,1,"SAMPLETEXT",1,2,3){}
Bow::Bow(string GivenName):Item(GivenName,2,2,2,2,"SAMPLETEXT",3,4,5){}
Ninjato::Ninjato(string GivenName):Item(GivenName,4,3,3,3,"SAMPLETEXT",2,2,4){}
Wakizashi::Wakizashi(string GivenName):Item(GivenName,8,5,5,3,"SAMPLETEXT",3,3,8){}
void Katana::print(){
	cout<<"Type: Katana ";
	Card::print();
	GreenCard::print();
	Item::print();
	cout<<endl;
}
void Spear::print(){
	cout<<"Type: Spear ";
	Card::print();
	GreenCard::print();
	Item::print();
	cout<<endl;
}
void Bow::print(){
	cout<<"Type: Bow ";
	Card::print();
	GreenCard::print();
	Item::print();
	cout<<endl;
}
void Ninjato::print(){
	cout<<"Type: Ninjato ";
	Card::print();
	GreenCard::print();
	Item::print();
	cout<<endl;
}
void Wakizashi::print(){
	cout<<"Type: Wakizashi ";
	Card::print();
	GreenCard::print();
	Item::print();
	cout<<endl;
}
