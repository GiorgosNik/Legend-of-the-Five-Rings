#include <iostream>
#include "Personality.hpp"
#include "Follower.hpp"
#include "Item.hpp"
using namespace std;
Personality::Personality(int GivenCost,string GivenName,int givenAttack,int givenDefence,int givenHonour):BlackCard(GivenCost,GivenName),attack(givenAttack),defence(givenDefence),honour(givenHonour),isAlive(true){}
Personality::Personality(const Personality& Copy):BlackCard(Copy),attack(Copy.attack),defence(Copy.defence),honour(Copy.honour),Retinue(Copy.Retinue),Arsenal(Copy.Arsenal){}
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
			Retinue.at(i)->print();
		}
	}
	if(Arsenal.empty()){
		cout<<"No items"<<endl;
	}else{
		for(int i=0;i<Arsenal.size();i++){
			Arsenal.at(i)->print();
		}
	}
	
}
void Personality::detach(Item* toRemove){
	int i=0;
	while(i<Arsenal.size()){
		if(Arsenal.at(i)==toRemove){
			Arsenal.erase(Arsenal.begin()+i);
			break;
		}
		i++;
	}
}
void Personality::killFollower(Follower* toRemove){
	int i=0;
	while(i<Retinue.size()){
		if(Retinue.at(i)==toRemove){
			Retinue.erase(Retinue.begin()+i);
			break;
		}
		i++;
	}
}
void Personality::defeat(){
	for(int i=0;i<Arsenal.size();i++){
		Arsenal.at(i)->damage();
		if(Arsenal.at(i)->getDurability()==0){
			detach(Arsenal.at(i));
		}
	}
	honour--;
	if(honour=0){
		performSepuku();
	}
	tapp();
}
int Personality::removeAtLeast(int points){
	int i=0;
	while(i<Retinue.size()&&points>0){
		points-=Retinue.at(i)->getAttackBonus();
		killFollower(Retinue.at(i));
	}
	i=0;
	while(i<Arsenal.size()&&points>0){
		points-=Arsenal.at(i)->getAttackBonus();
		detach(Arsenal.at(i));
	}
	return points;
}
void Personality::performSepuku(){
	cout<<"Your faithfull servant: "<<getName()<<" has performed Sepuku to cleanse his honour"<<endl;
	setDeath();
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
	Arsenal.push_back(&toGive);
}
void Personality::giveFollower(Follower& toGive){
	attack+=toGive.getAttackBonus();
	defence+=toGive.getDefenceBonus();
	Retinue.push_back(&toGive);
}
int Personality::getType(){
	return PERSONALITY;
}
bool Personality::getFollowerNumber(){
	return Retinue.size()<MAXFOLLOWERS;
}
bool Personality::getItemNumber(){
	return Arsenal.size()<MAXITEMS;
}
Attacker::Attacker(string GivenName):Personality(5,GivenName,3,2,2){}
Defender::Defender(string GivenName):Personality(5,GivenName,2,3,2){}
Shogun::Shogun(string GivenName):Personality(15,GivenName,10,5,8){}
Chancellor::Chancellor(string GivenName):Personality(15,GivenName,5,10,8){}
Champion::Champion(string GivenName):Personality(30,GivenName,20,20,12){}
void Attacker::print(){
	cout<<"Type: Attacker ";
	Card::print();
	BlackCard::print();
	Personality::print();
	cout<<endl;
}
void Defender::print(){
	cout<<"Type: Defender ";
	Card::print();
	BlackCard::print();
	Personality::print();
	cout<<endl;
}
void Shogun::print(){
	cout<<"Type: Shogun ";
	Card::print();
	BlackCard::print();
	Personality::print();
	cout<<endl;
}
void Chancellor::print(){
	cout<<"Type: Chancellor ";
	Card::print();
	BlackCard::print();
	Personality::print();
	cout<<endl;
}
void Champion::print(){
	cout<<"Type: Champion ";
	Card::print();
	BlackCard::print();
	Personality::print();
	cout<<endl;
}
