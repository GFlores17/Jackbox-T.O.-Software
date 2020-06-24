#ifndef MATCH_H
#define MATCH_H

#include "Player.h"
#include "Game.h"

class Match {

public:
	
	static int getEntry();

	std::string matchName;
	std::vector<std::unique_ptr<Game>> listOfGames;

	Match();
	Match(std::vector<Player> &vec);
	Match(const std::string& name);

	void printResults();
	void print();
	//void addGame();
	void addGame();
	void viewGamesResults();
	void startGame();
	void enterGameResults();
	void printGames();
	void menu();
	void menuSelect(int choice);
	void exitProgram();
};

#endif