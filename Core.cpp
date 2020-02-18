#include "Deckbuilder.hpp"
#include <list>
#include "Black.hpp"
#include "Green.hpp"
#include <iostream>
using namespace std;
int main(){
	cout<<"TEST";
	DeckBuilder test;
	list<Green*>* first;
	first=test.createFateDeck();
	return 0;
}


