#ifndef BLACK
#define BLACK
#include <iostream>
#include "Card.hpp"
using namespace std;
class Black:public Card{
	bool isRevealed;
	public:
		Black(int givenCost,string givenName);
		Black(const Black& Copy);
		~Black();
		bool getIsRevealed();
};
#endif		//BLACK
