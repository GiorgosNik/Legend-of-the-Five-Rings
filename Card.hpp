#ifndef CARD
#define CARD
#include <iostream>
using namespace std;
enum types{PERSONALITY = 1, HOLDING = 2, FOLLOWER = 3, ITEM = 4};
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
		string getName();
		bool getIsTapped();
		void untap();
		void tapp();
		void printName();
		virtual void print();
};
#endif //CARD
