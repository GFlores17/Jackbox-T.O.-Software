#ifndef ROUND_H
#define ROUND_H

#include "Match.h"
#include "Player.h"
#include "getEntry.h"

class Round {
public:
	static int getEntry();

	std::string roundName;
	std::vector <std::unique_ptr<Match>> listOfMatches;
	std::vector <std::shared_ptr<Player>> playersInRound;

	Round();
	Round(std::vector <std::shared_ptr<Player>>& vec);

	void menu();
	void addMatch();
	void addPlayer(std::vector<std::shared_ptr<Player>>& vec);
	void printPlayers();
	void viewMatches();
	void checkIfMatchInRange(int& choice);
	void selectMatch();
	void exitProgram();
	void menuSelect(int choice);

};

#endif

