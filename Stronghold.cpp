#include <iostream>
#include "Stronghold.hpp"
using namespace std;
Stronghold::Stronghold(string GivenName):Holding(5,GivenName,5),initDefence(5){
honour=rand()%10+1;
}
Stronghold::Stronghold(const Stronghold& Copy):Holding(Copy),initDefence(Copy.initDefence){}
Stronghold::~Stronghold(){
}
int Stronghold::getDefence(){
	return initDefence;
}
void Stronghold::print(){
	cout<<"Type: Stronghold";
	Card::print();
	BlackCard::print();
	Holding::print();
	cout<<endl;
}
int Stronghold::getHonour(){
	return honour;
}
