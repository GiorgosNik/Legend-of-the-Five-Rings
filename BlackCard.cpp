#include <iostream>
#include "BlackCard.hpp"
using namespace std;
BlackCard::BlackCard(int givenCost,string GivenName):Card(givenCost,GivenName),isRevealed(false){}
BlackCard::BlackCard(const BlackCard& Copy):Card(Copy),isRevealed(Copy.isRevealed){}
BlackCard::~BlackCard(){}
bool BlackCard::getIsRevealed(){
	return isRevealed;
}
void BlackCard::print(){
	cout<<"Recealed: ";
	if(isRevealed){
		cout<<"Yes ";
	}else{
		cout<<"No ";
	}
}
void BlackCard::reveal(){
	isRevealed=true;
}
