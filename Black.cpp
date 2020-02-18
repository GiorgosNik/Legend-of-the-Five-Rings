#include <iostream>
#include "Black.hpp"
using namespace std;
Black::Black(int givenCost,string GivenName):Card(givenCost,GivenName),isRevealed(false){}
Black::Black(const Black& Copy):Card(Copy),isRevealed(Copy.isRevealed){}
Black::~Black(){
	cout<<"BLACK DESTROYED"<<endl;
}
bool Black::getIsRevealed(){
	return isRevealed;
}
void Black::print(){
	cout<<"Recealed: ";
	if(isRevealed){
		cout<<"Yes ";
	}else{
		cout<<"No ";
	}
}
