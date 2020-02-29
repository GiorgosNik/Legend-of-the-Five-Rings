#include <iostream>
#include "Player.hpp"
#include "GameBoard.hpp"
#include "Phases.hpp"
using namespace Phases;
using namespace std;
  GameBoard::GameBoard(){}
void GameBoard::initializeGameBoard(){
    	int playerNum,handCards;
    	string givenName;
    	Player* tempPlayer;
		cout<<"How many Players will play?"<<endl;
		cin>>playerNum;
		cout<<"How many Cards can they have at hand?"<<endl;
		cin>>handCards;
		for(int i=0;i<playerNum;i++){
			cout<<"Give name for Player "<<i+1<<endl;
			cin>>givenName;
			tempPlayer=new Player(handCards,givenName);
			players.push_back(tempPlayer);
			tempPlayer=NULL;
		}
    }    
void GameBoard::gameplay(){
	Player* current,*temp;
	int index=0;
	for(int i=0;i<players.size();i++){
		for(int j=i+1;j<players.size();j++){
			if(players.at(j)->getHonour()>players.at(i)->getHonour()){
				temp=players.at(j);
				players.at(j)=players.at(i);
				players.at(i)=temp;
			}
		}
	}
	while(1==1){
		current=players.at(index);
		playPhases(*current);
		if(index+1<players.size()){
			index++;
		}else{
			index=0;
		}

	}
}
void GameBoard::playPhases(Player& toPlay){
	cout<<"Player: ";toPlay.printName();cout<<endl;
	startingPhase(toPlay);
	equipPhase(toPlay);
	battlePhase(toPlay,players);
	economyPhase(toPlay);
	finalPhase(toPlay);
}

