#ifndef FOLLOWERG
#define FOLLOWERG
#include "GreenCard.hpp"
class Follower:public GreenCard{
	public:
	Follower(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenText,int givenEffectBonus,int givenEffectCost);
	Follower(const Follower& Copy);
	virtual	~Follower();
	int getType();
	virtual	void print()=0;
};
class Footsoldier:public Follower{
	public:
		Footsoldier(string GivenName);
		void print();
};
class Archer:public Follower{
	public:
		Archer(string GivenName);
		void print();
};
class Sieger:public Follower{
	public:
		Sieger(string GivenName);
		void print();
};
class Cavalry:public Follower{
	public:
		Cavalry(string GivenName);
		void print();
};
class Atakebune:public Follower{
	public:
		Atakebune(string GivenName);
		void print();
};
class Bushido:public Follower{
	public:
		Bushido(string GivenName);
		void print();
};
#endif //FOLLOWERG
