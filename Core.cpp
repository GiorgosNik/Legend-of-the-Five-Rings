#include "Deckbuilder.hpp"
#include <list>
#include "BlackCard.hpp"
#include "GreenCard.hpp"
#include <iostream>
using namespace std;
int main(){
	cout<<"TEST";
	DeckBuilder test;
	list<GreenCard*>* first;
	first=test.createFateDeck();
	return 0;
}


