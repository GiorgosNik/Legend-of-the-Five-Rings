#ifndef ITEMG
#define ITEMG
#include "GreenCard.hpp"
using namespace std;
class Item:public GreenCard{
	private:
		int durability;
	public:
		Item(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenTextm,int givenEffectBonus,int givenEffectCost,int givenDurability);
		Item(const Item& Copy);
		virtual	~Item();
		int getType();
		virtual void print();
};
class Katana:public Item{
	public:
		Katana(string givenName);
		void print();
};
class Spear:public Item{
	public:
		Spear(string givenName);
		void print();
};
class Bow:public Item{
	public:
		Bow(string givenName);
		void print();
};
class Ninjato:public Item{
	public:
		Ninjato(string givenName);
		void print();
};
class Wakizashi:public Item{
	public:
		Wakizashi(string givenName);
		void print();
};
#endif //ITEMG
