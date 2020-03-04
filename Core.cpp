#include "DeckBuilder.hpp"
#include <list>
#include "BlackCard.hpp"
#include "GreenCard.hpp"
#include <iostream>
#include "Phases.hpp"
#include "GameBoard.hpp"
using namespace std;
int main(){
	GameBoard toPlay;
	toPlay.initializeGameBoard();
	toPlay.gameplay();
	cout<<"Game Over."<<endl;
	cout<<"Thanks for Playing!!!"<<endl;
	return 0;
}
