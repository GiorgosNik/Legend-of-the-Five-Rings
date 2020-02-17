#ifndef HOLDING
#define HOLDING
#include <iostream>
#include "Black.hpp"
using namespace std;
class Holding:public Black{
int harvestValue;
Holding* upperHolding;
Holding* lowerHolding;
public:
Holding(int givenCost,string GivenName,int Harvest);
Holding(const Holding& Copy);
~Holding();
void giveUpper(Holding* givenHold);
void giveLow(Holding* givenHold);
int getHarvestValue();
};
class GiftsandFavour:public Holding{
	public:
		GiftsandFavour(string GivenName);
};
class Plain:public Holding{
	public:
		Plain(string GivenName);
};
class Farmland:public Holding{
	public:
		Farmland(string GivenName);
};
class Mine:public Holding{
	public:
		Mine(string GivenName);
};
class GoldMine:public Holding{
	public:
		GoldMine(string GivenName);
};
class CrystalMine:public Holding{
	public:
		CrystalMine(string GivenName);
};
#endif		//HOLDING
