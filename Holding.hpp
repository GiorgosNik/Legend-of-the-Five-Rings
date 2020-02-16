#include <iostream>
#include "Black.hpp"
using namespace std;
class Holding:public Black{
int harvestValue;
Holding* upperHolding;
Holding* subHolding;
public:
Holding(,int givenCost,string GivenName,int Harvest);
Holding(const Holding& Copy);
~Holding();
void giveUpper(Holding* givenHold);
void giveLow(Holding* givenHold);
int getHarvestValue();
};
class Giftsandfavour:public Holding{
	public:
		Giftsandfavour(int givenCost,string GivenName);
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
		GodlMine(string GivenName);
};
class CrystalMine:public Holding{
	public:
		CrystalMine(string GivenName);
};

