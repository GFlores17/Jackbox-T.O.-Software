#ifndef GAME_H
#define GAME_H

#include <iterator>
#include <map>
#include <vector>

#include "Player.h"
//Player.h has <iostream>, <iomanip>, and <string>.

class Game {
private:
	std::map <std::string, int> gameResults;
	std::vector<std::shared_ptr<Player>> playersInGame;
	std::string gameName;

public:
	Game();
	Game(int num);
	void setName(const std::string& name);
	std::string getName();

	std::map <std::string, int> getMap();

	void addPlayersToGame(std::vector<std::shared_ptr<Player>> matchPlayerVector);
	void setGameResults();
	void printGameResults();
	void printPlayers();
	//void addPlayerToGame(std::vector<shared_ptr<Player>>& playersInTournament);

};

#endif //GAME_H