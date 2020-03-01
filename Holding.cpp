#include <iostream>
#include "Holding.hpp"
using namespace std;
Holding::Holding(int givenCost,string GivenName,int Harvest):BlackCard(givenCost,GivenName),harvestValue(Harvest),upperHolding(NULL),lowerHolding(NULL){}
Holding::Holding(const Holding& Copy):BlackCard(Copy),harvestValue(Copy.harvestValue){}
Holding::~Holding(){
	if(upperHolding!=NULL){
		delete upperHolding;		//POSIBLE DELETE PROBLEM
	}
	if(lowerHolding!=NULL){
		delete lowerHolding;
	}
}
bool Holding::crystalLowerChain(){
	return false;
}
bool Holding::goldLowerChain(){
	return false;
}
bool Holding::goldUpperChain(){
	return false;
}
bool Holding::mineUpperChain(){
	return false;
}
Holding* Holding::getLowerHolding(){
	return lowerHolding;
}
Holding* Holding::getUpperHolding(){
	return upperHolding;
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
void Holding::print(){
	cout<<"Harvest Value: "<<harvestValue;
	if(upperHolding!=NULL){
		cout<<"Has Upper Holding: "<<upperHolding->getName();
	}
	if(lowerHolding!=NULL){
		cout<<"Has Lower Holding: "<<lowerHolding->getName();
	}
}
GiftsandFavour::GiftsandFavour(string GivenName):Holding(2,GivenName,2){}
Plain::Plain(string GivenName):Holding(2,GivenName,2){}
Farmland::Farmland(string GivenName):Holding(3,GivenName,4){}
Mine::Mine(string GivenName):Holding(5,GivenName,3){}
GoldMine::GoldMine(string GivenName):Holding(7,GivenName,5){}
CrystalMine::CrystalMine(string GivenName):Holding(12,GivenName,6){}
void GiftsandFavour::print(){
	cout<<"Type: Gifts and Favours ";
	Card::print();
	BlackCard::print();
	Holding::print();
	cout<<endl;
}
void Plain::print(){
	cout<<"Type: Plain ";
	Card::print();
	BlackCard::print();
	Holding::print();
	cout<<endl;
}
void Farmland::print(){
	cout<<"Type: Farmland ";
	Card::print();
	BlackCard::print();
	Holding::print();
	cout<<endl;
}
void Mine::print(){
	cout<<"Type: Mine ";
	Card::print();
	BlackCard::print();
	Holding::print();
	cout<<endl;
}
void GoldMine::print(){
	cout<<"Type: Gold Mine ";
	Card::print();
	BlackCard::print();
	Holding::print();
	cout<<endl;
}
void CrystalMine::print(){
	cout<<"Type: Crysta lMine ";
	Card::print();
	BlackCard::print();
	Holding::print();
	cout<<endl;
}
int Mine::getHarvestValue(){
	if(getUpperHolding()!=NULL){
		return (Holding::getHarvestValue()+2);
	}else{
		return Holding::getHarvestValue();
	}
}
int GoldMine::getHarvestValue(){
	int rez=Holding::getHarvestValue();
	if(getLowerHolding()!=NULL){
		rez+=4;
	}
	if(getUpperHolding()!=NULL){
		rez+=5;
	}
	if(getLowerHolding()!=NULL&&getUpperHolding()!=NULL){
		rez+=Holding::getHarvestValue()*2;
	}
	return rez;
}
int CrystalMine::getHarvestValue(){
	int rez=Holding::getHarvestValue();
	if(getLowerHolding()!=NULL){
		rez+=Holding::getHarvestValue();
		if(getLowerHolding()->getLowerHolding()!=NULL){
			rez+=Holding::getHarvestValue();
		}
	}
	return rez;
}
