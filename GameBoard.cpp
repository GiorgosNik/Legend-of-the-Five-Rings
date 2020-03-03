#include <iostream>
#include "Player.hpp"
#include "GameBoard.hpp"
#include "Phases.hpp"
using namespace Phases;
using namespace std;
  GameBoard::GameBoard(){}
void GameBoard::initializeGameBoard(){
		cout<<"Seting up Game Board..."<<endl;
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
	bool result=false;
	cout<<"Press ENTER to start Game."<<endl;
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
	
	while(result==false){
		current=players.at(index);
		result=playPhases(*current);
		if(index+1<players.size()){
			index++;
		}else{
			index=0;
		}

	}
}
bool GameBoard::playPhases(Player& toPlay){
  if(toPlay.getProvinceNumber()>0){
	cout<<"Player: ";toPlay.printName();cout<<endl;
	startingPhase(toPlay);
	equipPhase(toPlay);
	battlePhase(toPlay,players);
	economyPhase(toPlay);
	finalPhase(toPlay);
  	return checkWinningCondition(toPlay);
}else{
  cout<<"Player ";toPlay.printName();cout<<" has run out of provinces, moving on to next player."<<endl;
}
}
bool GameBoard::checkWinningCondition(Player& toPlay){
	int j=0;
  if(toPlay.getProvinceNumber()>0){
	for(int i=0;i<players.size();i++){
		if(players.at(i)!=&toPlay&&players.at(i)->getProvinceNumber()==0){
			j++;
		}
	}
	if(j==players.size()-1){
		cout<<"PLAYER: ";toPlay.printName();cout<<" IS THE LAST RULER STANDING"<<endl<<"CONGRATULATIONS"<<endl;
		return true;
		}
  }
  return false;
}
