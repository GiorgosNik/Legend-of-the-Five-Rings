#include <iostream>
#include "Card.hpp"
using namespace std;
class Black:public Card{
	bool isRevealed;
	public:
		Black(string GivenName,int givenCost);
		Black(const Black& Copy);
		~Black();
		bool getIsRevealed();
};
