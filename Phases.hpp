#include <iostream>
#include <vector>
#include "Personality.hpp"
#include "Player.hpp"
using namespace std;
namespace Phases{
	void startingPhase(Player& Given);
	void equipPhase(Player& Given);
	void battlePhase(Player& Given,vector<Player*>& Players);
	void economyPhase(Player& Given);
	void finalPhase(Player& Given,vector<Player*>& Players);
};
