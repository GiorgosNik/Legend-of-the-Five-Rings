#ifndef FOLLOWER
#define FOLLOWER
#include "Green.hpp"
class Follower:public Green{
	public:
	Follower(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenText,int givenEffectBonus,int givenEffectCost);
	Follower(const Follower& Copy);
virtual	~Follower();
};
class Footsoldier:public Follower{
	public:
		Footsoldier(string GivenName);
};
class Archer:public Follower{
	public:
		Archer(string GivenName);
};
class Sieger:public Follower{
	public:
		Sieger(string GivenName);
};
class Cavalry:public Follower{
	public:
		Cavalry(string GivenName);
};
class Atakebune:public Follower{
	public:
		Atakebune(string GivenName);
};
class Bushido:public Follower{
	public:
		Bushido(string GivenName);
};
#endif //FOLLOWER
