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
		int effectBonus;
	public:
	Green(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenText,int givenEfectBonus,int givenEffectCost);
	Green(const Green& Copy);
	~Green();
	int getEffectCost();
	void giveBonus();
};
#endif //GREEN
