#include <iostream>
#include "Stronghold.hpp"
using namespace std;
Stronghold::Stronghold(string GivenName):Holding(5,GivenName,5),initDefence(5){}
Stronghold::Stronghold(const Stronghold& Copy):Holding(Copy),initDefence(Copy.initDefence){}
~Stronghold::~Stronghold(){
	cout<<"DESTROYED STRONGHOLD"<<endl;
}
int Stronghold::getDefence(){
	return initDefence;
}
