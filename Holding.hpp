#ifndef HOLDINGG
#define HOLDINGG
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
		virtual int getHarvestValue();
		Holding* getLowerHolding();
		Holding* getUpperHolding();
		int getType();
		virtual void print();
};
class GiftsandFavour:public Holding{
	public:
		GiftsandFavour(string GivenName);
		void print();
};
class Plain:public Holding{
	public:
		Plain(string GivenName);
		void print();
};
class Farmland:public Holding{
	public:
		Farmland(string GivenName);
		void print();
};
class Mine:public Holding{
	public:
		Mine(string GivenName);
		int getHarvestValue();
		void print();
};
class GoldMine:public Holding{
	public:
		GoldMine(string GivenName);
		int getHarvestValue();
		void print();
};
class CrystalMine:public Holding{
	public:
		CrystalMine(string GivenName);
		int getHarvestValue();
		void print();
};
#endif		//HOLDINGG
