#include "DeckBuilder.hpp"
#include <list>
#include "BlackCard.hpp"
#include "GreenCard.hpp"
#include <iostream>
#include "Player.hpp"
#include "Phases.hpp"
#include "GameBoard.hpp"
using namespace std;
int main(){
	GameBoard toPlay;
	toPlay.initializeGameBoard();
	toPlay.gameplay();
	return 0;
}
