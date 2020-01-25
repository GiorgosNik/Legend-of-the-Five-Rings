#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(int givenConst, string givenName):Cost(givenCost), Name(givenCost),isTapped(false){
	cout<<"Card: "<< Name<<" just created!"<<endl;	//Comment out
}
Card::Card(const Card& Copy)Name(Copy.Name),Cost(Copy.Cost),isTapped(Copy.isTapped){
	cout<<"Card: "<< Name<<" copied!"<<endl;	//Comment out
}
Card::~Card(){
	cout<<"Card: "<< Name<<" just deleted!"<<endl;	//Comment out
}
int Card::getCost(){
	return Cost;
}
