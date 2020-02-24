#ifndef GREEN
#define GREEN
#include "Card.hpp"
using namespace std;
class GreenCard: public Card{
	private:
		int attackBonus;
		int defenceBonus;
		int minimumHonnor;
		string cardText;
		int effectCost;
		int effectBonus;
	public:
	GreenCard(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenText,int givenEfectBonus,int givenEffectCost);
	GreenCard(const GreenCard& Copy);
	~GreenCard();
	int getEffectCost();
	void giveBonus();
	int getDefenceBonus();
	int getAttackBonus();
	int getminHonour();
	virtual void print();
	virtual int getType()=0;
};
#endif //GREEN
