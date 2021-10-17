#ifndef	GAMEBOARD
#define GAMEBOARD
#include <iostream>
class Player;
using namespace std;

class GameBoard{
private:
	vector<Player*> players;
public:
    GameBoard();
    ~GameBoard();
    void initializeGameBoard();
    void gameplay();
    bool playPhases(Player& toPlay);
	bool checkWinningCondition(Player& toPlay);
    void enterToContinue();
};
#endif	//GAMEBOARD
