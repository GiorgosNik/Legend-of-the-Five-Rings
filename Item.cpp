#include "Item.hpp"
using namespace std;
Item::Item(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenTextm,int givenEffectBonus,int givenEffectCost,int givenDurability,)
:Green(givenName,givenCost,givenAttBonus,givenDefBonus,givenMinHonnor,givenTextm,givenEffectBonus,givenEffectCost),durability(givenDurability)
{
cout<<"Item created"<<endl;	
}
Item::Item(const Item& Copy)
:Green(Copy),durability(Copy.durability)
{
cout<<"Item created"<<endl;	
}
Item::~Item(){
	cout<<"Item deleted"<<endl;	
}
Katana::Katana(string GivenName):Item(GivenName,0,2,0,1,"SAMPLETEXT",1,2,3){}
Spear::Spear(string GivenName):Item(GivenName,0,0,2,1,"SAMPLETEXT",1,2,3){}
Bow::Bow(string GivenName):Item(GivenName,2,2,2,2,"SAMPLETEXT",,3,4,5){}
Ninjato::Ninjato(string GivenName):Item(GivenName,4,3,3,3,"SAMPLETEXT",2,2,4){}
Wakizashi::Wakizashi(string GivenName):Item(GivenName,8,5,5,3,"SAMPLETEXT",3,3,8){}
