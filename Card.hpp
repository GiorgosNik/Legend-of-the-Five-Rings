#ifndef CARD
#define CARD
#include <iostream>
using namespace std;

class Card{
	private:
		int Cost;
		string Name;
		bool isTapped;
	public:	
		Card(int givenCost, string givenName);
		Card(const Card& Copy);
		virtual	~Card();	//To be used for debuging messages ONLY!!!
		int getCost();
};
#endif //CARD
