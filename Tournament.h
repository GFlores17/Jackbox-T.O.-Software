#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
#include <map>
#include <iterator>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>   

#include "Game.h"
#include "Match.h"
#include "Player.h"
#include "Round.h"
#include "getEntry.h"

class Tournament {
public:

	static int getEntry();

	std::string tournamentName;
	std::vector<std::shared_ptr<Player>> listOfAllPlayers;
	std::vector<std::shared_ptr<Round>> listOfRounds;

	Tournament();
	void printAllPlayers();
	void registerPlayers();
	void startRound();
	void continueRound();
	void exitProgram();
	void tournamentMenu();
	void menuSelect(int choice);

}; //end Tournament class

#endif //TOURNAMENT_H