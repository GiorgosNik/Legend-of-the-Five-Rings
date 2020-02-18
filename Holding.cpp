#include <iostream>
#include "Holding.hpp"
using namespace std;
Holding::Holding(int givenCost,string GivenName,int Harvest):Black(givenCost,GivenName),harvestValue(Harvest),upperHolding(NULL),lowerHolding(NULL){}
Holding::Holding(const Holding& Copy):Black(Copy),harvestValue(Copy.harvestValue){}
Holding::~Holding(){
	if(upperHolding!=NULL){
		delete upperHolding;		//POSIBLE DELETE PROBLEM
	}
	if(lowerHolding!=NULL){
		delete lowerHolding;
	}
}
int Holding::getType(){
	return HOLDING;
}
void Holding::giveUpper(Holding* givenHold){
	upperHolding=givenHold;
}
void Holding::giveLow(Holding* givenHold){
	lowerHolding=givenHold;
}
int Holding::getHarvestValue(){
	return harvestValue;
}
GiftsandFavour::GiftsandFavour(string GivenName):Holding(2,GivenName,2){}
Plain::Plain(string GivenName):Holding(2,GivenName,2){}
Farmland::Farmland(string GivenName):Holding(3,GivenName,4){}
Mine::Mine(string GivenName):Holding(5,GivenName,3){}
GoldMine::GoldMine(string GivenName):Holding(7,GivenName,5){}
CrystalMine::CrystalMine(string GivenName):Holding(12,GivenName,6){}
