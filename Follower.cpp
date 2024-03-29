#include <iostream>
#include "Follower.hpp"
using namespace std;
Follower::Follower(string givenName, int givenCost, int givenAttBonus,int givenDefBonus,int givenMinHonnor, string givenText,int givenEffectBonus,int givenEffectCost):GreenCard(givenName,givenCost,givenAttBonus,givenDefBonus,givenMinHonnor,givenText,givenEffectBonus,givenEffectCost){}
Follower::Follower(const Follower& Copy):GreenCard(Copy){}
Follower::~Follower(){}
int Follower::getType(){
	return FOLLOWER;
}
Footsoldier::Footsoldier(string GivenName):Follower(GivenName,0,2,0,1,"SAMPLETEXT",1,2){}
Archer::Archer(string GivenName):Follower(GivenName,0,0,2,1,"SAMPLETEXT",1,2){}
Sieger::Sieger(string GivenName):Follower(GivenName,5,3,3,2,"SAMPLETEXT",2,3){}
Cavalry::Cavalry(string GivenName):Follower(GivenName,3,4,2,3,"SAMPLETEXT",3,4){}
Atakebune::Atakebune(string GivenName):Follower(GivenName,3,2,4,3,"SAMPLETEXT",3,4){}
Bushido::Bushido(string GivenName):Follower(GivenName,8,8,8,6,"SAMPLETEXT",3,8){}
void Footsoldier::print(){
	cout<<"Type: Footsoldier";
	Card::print();
	GreenCard::print();
	cout<<endl;
}
void Archer::print(){
	cout<<"Type: Archer";
	Card::print();
	GreenCard::print();
	cout<<endl<<endl;
}
void Sieger::print(){
	cout<<"Type: Sieger";
	Card::print();
	GreenCard::print();
	cout<<endl;
}
void Cavalry::print(){
	cout<<"Type: Cavalry";
	Card::print();
	GreenCard::print();
	cout<<endl;
}
void Atakebune::print(){
	cout<<"Type: Atakebune";
	Card::print();
	GreenCard::print();
	cout<<endl;
}
void Bushido::print(){
	cout<<"Type: Bushido";
	Card::print();
	GreenCard::print();
	cout<<endl;
}
