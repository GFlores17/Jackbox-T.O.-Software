#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>
#include <string> 

class Player {
public:
	std::string pName;
	int score;

	Player();
	Player(const std::string& Name);

	void print();
	void promptForScore();
	void promptForPlacement();
	void manualScoreAdd(int points);
	void placementScoreAdd(int numOfPlayers, int placement);
	int getScore();
};

#endif // PLAYER_H