#ifndef PERSONALITYG
#define PERSONALITYG
#include <iostream>
#include <vector>
#include "BlackCard.hpp"
#include "Follower.hpp"
#include "Item.hpp"
#define MAXFOLLOWERS 5
#define MAXITEMS 5
using namespace std;
class Personality:public BlackCard{
	int attack;
	int defence;
	int honour;
	bool isAlive;
	vector <Follower*> Retinue;
	vector <Item*> Arsenal;
	public:
		Personality(int GivenCost,string GivenName,int givenAttack,int givenDefence,int givenHonour);
		Personality(const Personality& Copy);
		~Personality();
		int getAttack();
		void detach(Item* toRemove);
		void killFollower(Follower* toRemove);
		int getDefence();
		int getHonour();
		bool getIsAlive();
		void setDeath();
		void giveItem(Item& toGive);
		void giveFollower(Follower& toGive);
		int getType();
		bool getItemNumber();
		bool getFollowerNumber();
		void defeat();
		void performSepuku();
		int removeAtLeast(int points);
		virtual void print();
};
class Attacker:public Personality{
	public:
		Attacker(string GivenName);
		void print();
};
class Defender:public Personality{
	public:
		Defender(string GivenName);
		void print();
};
class Champion:public Personality{
	public:
		Champion(string GivenName);
		void print();
};
class Chancellor:public Personality{
	public:
		Chancellor(string GivenName);
		void print();
};
class Shogun:public Personality{
	public:
		Shogun(string GivenName);
		void print();
};
#endif		//PERSONALITYG
