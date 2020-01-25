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
