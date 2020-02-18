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
	Black::print();
	Holding::print();
	cout<<endl;
}
void Plain::print(){
	cout<<"Type: Plain ";
	Card::print();
	Black::print();
	Holding::print();
	cout<<endl;
}
void Farmland::print(){
	cout<<"Type: Farmland ";
	Card::print();
	Black::print();
	Holding::print();
	cout<<endl;
}
void Mine::print(){
	cout<<"Type: Mine ";
	Card::print();
	Black::print();
	Holding::print();
	cout<<endl;
}
void GoldMine::print(){
	cout<<"Type: Gold Mine ";
	Card::print();
	Black::print();
	Holding::print();
	cout<<endl;
}
void CrystalMine::print(){
	cout<<"Type: Crysta lMine ";
	Card::print();
	Black::print();
	Holding::print();
	cout<<endl;
}
