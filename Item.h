#include "Green.h"
using namespace std;
class Item:public Green{
	private:
		int durability;
	public:
		Item(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenTextm,int givenEffectCost,int givenDurability);
		Item(const Item& Copy);
		~Item();
};
class Katana:public Item{
	public:
		Katana(string givenName);
};
class Spear:public Item{
	public:
		Spear(string givenName);
};
class Bow:public Item{
	public:
		Bow(string givenName);
};
class Ninjato:public Item{
	public:
		Ninjato(string givenName);
};
class Wakizashi:public Item{
	public:
		Wakizashi(string givenName);
};
