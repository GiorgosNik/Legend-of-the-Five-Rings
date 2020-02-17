#include <iostream>
#include "Personality.hpp"
#include "Follower.hpp"
#include "Item.hpp"
using namespace std;
Personality::Personality(int GivenCost,string GivenName,int givenAttack,int givenDefence,int givenHonour):Black(GivenName,GivenCost),attack(givenAttack),defence(givenDefence),honour(givenHonour),isAlive(true){}
Personality::Personality(const Personality& Copy):Black(Copy),attack(Copy.attack),defence(Copy.defence),honour(Copy.honour),Retinue(Copy.Retinue),Arsenal(Copy.Arsenal){}
Personality::~Personality(){}
int Personality::getAttack(){
	return attack;
}
int Personality::getDefence(){
	return defence;
}
int Personality::getHonour(){
	return honour;
}
bool Personality::getIsAlive(){
	return isAlive;
}
void Personality::setDeath(){
	isAlive=false;
}
void Personality::giveItem(Item& toGive){
	Arsenal.push_back(toGive);
}
void Personality::giveFollower(Follower& toGive){
	Retinue.push_back(toGive);
}
class Attacker::Attacker(string GivenName):Personality(5,GivenName,3,2,2){}
class Defender::Defender(string GivenName):Personality(5,GivenName,2,3,2){}
class Shogun::Shogun(string GivenName):Personality(15,GivenName,10,5,8){}
class Chancellor::Chancellor(string GivenName):Personality(15,GivenName,5,10,8){}
class Champion::Champion(string GivenName):Personality(30,GivenName,20,20,12){}

