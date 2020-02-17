#ifndef PERSONALITY
#define PERSONALITY
#include <iostream>
#include <vector>
#include "Black.hpp"
#include "Follower.hpp"
#include "Item.hpp"
using namespace std;
class Personality:public Black{
	int attack;
	int defence;
	int honour;
	bool isAlive;
	vector <Follower> Retinue;
	vector <Item> Arsenal;	
	public:
		Personality(int GivenCost,string GivenName,int givenAttack,int givenDefence,int givenHonour);
		Personality(const Personality& Copy);
		~Personality();
		int getAttack();
		int getDefence();
		int getHonour();
		bool getIsAlive();
		void setDeath();
		void giveItem(Item& toGive);
		void giveFollower(Follower& toGive);
};
class Attacker:public Personality{
	public:
		Attacker(string GivenName);
};
class Defender:public Personality{
	public:
		Defender(string GivenName);
};
class Champion:public Personality{
	public:
		Champion(string GivenName);
};
class Chancellor:public Personality{
	public:
		Chancellor(string GivenName);
};
class Shogun:public Personality{
	public:
		Shogun(string GivenName);
};
#endif		//PERSONALITY
