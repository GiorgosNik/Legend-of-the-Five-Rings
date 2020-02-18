#include <iostream>
#include "Stronghold.hpp"
using namespace std;
Stronghold::Stronghold(string GivenName):Holding(5,GivenName,5),initDefence(5){}
Stronghold::Stronghold(const Stronghold& Copy):Holding(Copy),initDefence(Copy.initDefence){}
Stronghold::~Stronghold(){
}
int Stronghold::getDefence(){
	return initDefence;
}
void Stronghold::print(){
	cout<<"Type: Stronghold";
	Card::print();
	Black::print();
	Holding::print();
	cout<<endl;
}
