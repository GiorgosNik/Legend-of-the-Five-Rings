#include "Item.h"
using namespace std;
Item::Item(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenTextm,givenEffectCost,int givenDurability)
:Green(givenName,givenCost,givenAttBonus,givenDefBonus,givenMinHonnor,givenTextm,givenEffectCost,givenDurability),durability(givenDurability)
{
cout<<"Item created"<<endl;	
}
Item::Item(const Item& Copy)
:Green(Copy),durability(Copy.durability)
{
cout<<"Item created"<<endl;	
}
Green::~Green(){
	cout<<"Item deleted"<<endl;	
}
