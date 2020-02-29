#ifndef STRONGHOLD
#define STRONGHOLD
#include <iostream>
#include "Holding.hpp"
using namespace std;
class Stronghold:public Holding{
		int initDefence;
		int honour;
	public:
		Stronghold(string GivenName);
		Stronghold(const Stronghold& Copy);
		~Stronghold();
		int getDefence();
		int getHonour();
		void print();
};
#endif		//STRONGHOLD
