#include <iterator>
#include <map>
#include <vector>

#include "Game.h"
#include "Player.h"

	std::map <std::string, int> gameResults;
	std::vector<std::shared_ptr<Player>> playersInGame;
	std::string gameName;

	Game::Game() {
		std::cout << "Enter name of created game.\n";
		std::string gameName;
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, gameName);
		this->gameName = gameName;
	}

	Game::Game(int num) {
		gameName = "Game " + std::to_string(num);
	}

	void Game::setName(const std::string& name) {
		gameName = name;
	}

	std::map <std::string, int> Game::getMap() {
		return gameResults;
	}

	std::string Game::getName() {
		return gameName;
	}

	void Game::addPlayersToGame(std::vector<std::shared_ptr<Player>> matchPlayerVector) {
		for (int i = 0; i < matchPlayerVector.size(); i++) {
			this->playersInGame.push_back(matchPlayerVector.at(i));
		}
	}

	void Game::setGameResults() {//Creates map according to 
		for (int i = 0; i < playersInGame.size(); i++) {
			playersInGame.at(i)->print();
			playersInGame.at(i)->promptForScore();

			int gameScore;
			std::cin >> gameScore;

			playersInGame.at(i)->manualScoreAdd(gameScore);
			gameResults.insert(std::pair<std::string, int>(playersInGame.at(i)->getName(), gameScore));
		}
	}

	void Game::printGameResults() {
		std::map<std::string, int>::iterator itr;
		std::cout << "\nThe game results are : \n";
		std::cout << "\tPLAYER\tSCORE\n";
		for (itr = gameResults.begin(); itr != gameResults.end(); ++itr) {
			std::cout << '\t' << itr->first
				<< '\t' << itr->second << '\n';
		}
	}

	void Game::printPlayers() {
		for (int i = 0; i < playersInGame.size(); i++) {
			std::cout << playersInGame.at(i)->getName() << "\n";
		}
	}

	/*void Game::addPlayerToGame(vector<shared_ptr<Player>>& playersInTournament) {
		std::string playerToAdd;
		std::cout << "Select player to add." << std::endl;
		std::cin >> playerToAdd;
		for (int i = 0; i < playersInTournament.size(); i++) {

			cout << "size : " << playersInTournament.size() << std::endl;
			cout << i << std::endl;

			if (playerToAdd == playersInTournament.at(i)->pName) {
				cout << "loop " << i << endl;
				playersInGame.push_back(playersInTournament.at(i));
				cout << "REFERENCES TO " << playersInTournament.at(i)->pName
					<< " : " << playersInTournament.at(i).use_count() << endl;
			}
		}
	}*/
