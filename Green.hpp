#ifndef GREEN
#define GREEN
#include "Card.hpp"
using namespace std;
class Green: public Card{
	private:
		int attackBonus;
		int defenceBonus;
		int minimumHonnor;
		string cardText;
		int effectCost;
	public:
	Green(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenText,int givenEffectCost);
	Green(const Green& Copy);
	~Green();
	int geteffectCost();
	void effectBonus();
};
#endif //GREEN
