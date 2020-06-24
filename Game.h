#ifndef GAME_H
#define GAME_H

#include <iterator>
#include <map>
#include <vector>

#include "Player.h"
//Player.h has <iostream>, <iomanip>, and <string>.

class Game {
public:
	std::map <std::string, int> gameResults;
	std::vector<std::shared_ptr<Player>> playersInGame;
	std::string gameName;

	Game();
	void setName(const std::string& name);
	std::string getName();

	void addPlayerToGame();
	void setGameResults();
	void printGameResults();
	//void addPlayerToGame(std::vector<shared_ptr<Player>>& playersInTournament);

};

#endif //GAME_H