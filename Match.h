#ifndef MATCH_H
#define MATCH_H

#include "Player.h"
#include "Game.h"

class Match {
private:
	std::string matchName;
	std::vector<std::unique_ptr<Game>> listOfGames;
	std::vector<std::shared_ptr<Player>> matchPlayersVector;

public:
	static int getEntry();

	Match();
	Match(std::vector<Player> &vec);
	Match(std::string name, std::vector<std::shared_ptr<Player>> roundPlayerVector);

	void printResults();
	void printName();
	std::string getName();
	void setMatchName();
	std::vector<std::shared_ptr<Player>> getMatchPlayersVector();
	//void addGame();
	void addGame();
	void addGame(int num);
	void addPlayers(std::vector<std::shared_ptr<Player>> vec);

	void viewGamesResults();
	void startGame();
	void enterGameResults();
	void printGames();
	void menu();
	void menuSelect(int choice);
	void exitProgram();
};

#endif