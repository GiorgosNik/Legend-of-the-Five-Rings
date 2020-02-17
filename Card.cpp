#include "Card.hpp"
#include <iostream>
using namespace std;

Card::Card(int givenCost, string givenName):Cost(givenCost), Name(givenName),isTapped(false){
	cout<<"Card: "<< Name<<" just created!"<<endl;	//Comment out
}
Card::Card(const Card& Copy):Name(Copy.Name),Cost(Copy.Cost),isTapped(Copy.isTapped){
	cout<<"Card: "<< Name<<" copied!"<<endl;	//Comment out
}
Card::~Card(){
	cout<<"Card: "<< Name<<" just deleted!"<<endl;	//Comment out
}
int Card::getCost(){
	return Cost;
}
