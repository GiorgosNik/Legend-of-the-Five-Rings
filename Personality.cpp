#include <iostream>
#include "Personality.hpp"
#include "Follower.hpp"
#include "Item.hpp"
using namespace std;
Personality::Personality(int GivenCost,string GivenName,int givenAttack,int givenDefence,int givenHonour):Black(GivenCost,GivenName),attack(givenAttack),defence(givenDefence),honour(givenHonour),isAlive(true){}
Personality::Personality(const Personality& Copy):Black(Copy),attack(Copy.attack),defence(Copy.defence),honour(Copy.honour),Retinue(Copy.Retinue),Arsenal(Copy.Arsenal){}
Personality::~Personality(){}
void Personality::print(){
	cout<<"Attack: "<<attack<<" Defence: "<<defence<<" Honour: "<<honour;
	if(isAlive){
		cout<<" Alive ";
	}else{
		cout<<" Dead ";
	}
	if(Retinue.empty()){
		cout<<"No Followers"<<endl;
	}else{
		cout<<"Has Followers: ";
		for(int i=0;i<Retinue.size();i++){
			Retinue.at(i).print();
		}
	}
	if(Arsenal.empty()){
		cout<<"No items"<<endl;
	}else{
		for(int i=0;i<Arsenal.size();i++){
			Arsenal.at(i).print();
		}
	}
	
}
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
	attack+=toGive.getAttackBonus();
	defence+=toGive.getDefenceBonus();
	Arsenal.push_back(toGive);
}
void Personality::giveFollower(Follower& toGive){
	attack+=toGive.getAttackBonus();
	defence+=toGive.getDefenceBonus();
	Retinue.push_back(toGive);
}
int Personality::getType(){
	return PERSONALITY;
}
Attacker::Attacker(string GivenName):Personality(5,GivenName,3,2,2){}
Defender::Defender(string GivenName):Personality(5,GivenName,2,3,2){}
Shogun::Shogun(string GivenName):Personality(15,GivenName,10,5,8){}
Chancellor::Chancellor(string GivenName):Personality(15,GivenName,5,10,8){}
Champion::Champion(string GivenName):Personality(30,GivenName,20,20,12){}
void Attacker::print(){
	cout<<"Type: Attacker ";
	Card::print();
	Black::print();
	Personality::print();
	cout<<endl;
}
void Defender::print(){
	cout<<"Type: Defender ";
	Card::print();
	Black::print();
	Personality::print();
	cout<<endl;
}
void Shogun::print(){
	cout<<"Type: Shogun ";
	Card::print();
	Black::print();
	Personality::print();
	cout<<endl;
}
void Chancellor::print(){
	cout<<"Type: Chancellor ";
	Card::print();
	Black::print();
	Personality::print();
	cout<<endl;
}
void Champion::print(){
	cout<<"Type: Champion ";
	Card::print();
	Black::print();
	Personality::print();
	cout<<endl;
}
