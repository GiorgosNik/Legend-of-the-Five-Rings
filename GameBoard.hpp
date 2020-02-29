#ifndef	GAMEBOARD
#define GAMEBOARD
#include <iostream>
#include "Player.hpp"
using namespace std;

class GameBoard{
private:
	vector<Player*> players;
public:
    GameBoard();
    void initializeGameBoard();
    void gameplay();
    void playPhases(Player& toPlay);
};
#endif	//GAMEBOARD