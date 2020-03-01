#include "Card.hpp"
#include <iostream>
using namespace std;

Card::Card(int givenCost, string givenName):Cost(givenCost), Name(givenName),isTapped(false){
}
Card::Card(const Card& Copy):Name(Copy.Name),Cost(Copy.Cost),isTapped(Copy.isTapped){
}
Card::~Card(){
}
int Card::getCost(){
	return Cost;
}
string Card::getName(){
	return Name;
}
void Card::print(){
	cout<<"Name: "<<Name<<" Cost: "<<Cost<<" Tapped: ";
	if(isTapped){
		cout<<"Yes ";
	}else{
		cout<<"No ";
	}
}
void Card::untap(){
	isTapped=false;
}
bool Card::getIsTapped(){
	return isTapped;
}
void Card::tapp(){
	isTapped=true;
}
void Card::printName(){
	cout<<Name;
}
