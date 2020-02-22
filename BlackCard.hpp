#ifndef BLACK
#define BLACK
#include <iostream>
#include "Card.hpp"
using namespace std;
class BlackCard:public Card{
	bool isRevealed;
	public:
		BlackCard(int givenCost,string givenName);
		BlackCard(const BlackCard& Copy);
		~BlackCard();
		bool getIsRevealed();
		virtual void print();
		void reveal();
		virtual int getType()=0;
		
};
#endif		//BLACK
