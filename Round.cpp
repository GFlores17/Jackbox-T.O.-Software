#include "Round.h"
#include "Match.h"
#include "Player.h"
#include "getEntry.h"

int Round::getEntry() {
	int choice;
	std::cin >> choice;
	checkIfInt(choice);

	while (choice < 1 || choice > 3) {
		std::cout << "invalid option. retry now." << std::endl;
		std::cin >> choice;
		checkIfInt(choice);
	}
	std::cout << std::endl;
	return choice;
}

std::string roundName;
std::vector <std::unique_ptr<Match>> listOfMatches;
std::vector <std::shared_ptr<Player>> playersInRound;

Round::Round() {//Constructor
	std::cout << "Enter round name." << std::endl << std::endl;
	std::cin >> roundName;
	std::cout << "-------------------------------" << "[" << roundName << "]" << "-------------------------------" << std::endl;

	menu();
	menuSelect(getEntry());
}

Round::Round(std::vector <std::shared_ptr<Player>>& playersInTournament) {//Test function.
	std::cout << "Enter round name." << std::endl << std::endl;
	std::cin >> roundName;
	std::cout << "-------------------------------" << "[" << roundName << "]" << "-------------------------------" << std::endl;


	addPlayer(playersInTournament);
	menu();
	menuSelect(getEntry());
}

void Round::menu() {
	std::cout << std::endl;
	std::cout << "1. Start New Match." << std::endl;
	std::cout << "2. Continue Match." << std::endl;
	std::cout << "3. Main Menu." << std::endl;
}

void Round::addMatch() {
	std::cout << "How many matches would you like to add?" << std::endl;
	int rounds;
	std::cin >> rounds;

	for (int i = 0; i < rounds; i++) {
		std::cout << "Name of match " << i + 1 << "?\n";
		std::string name;
		std::cin >> name;

		std::unique_ptr<Match> m = std::make_unique<Match>(name);
		listOfMatches.push_back(move(m));
	}//end for loop
}//end of addMatch

void Round::addPlayer(std::vector<std::shared_ptr<Player>>& vec) {
	std::cout << "How many players to add?\n";
	int numOfPlayers;
	std::cin >> numOfPlayers;

	for (int i = 0; i < numOfPlayers; i++) {
		std::cout << "Name of player to add?\n";
		std::string player;
		std::cin >> player;

		int placement;
		std::cout << "searching for : " << player << std::endl;
		placement = binaryStringSearch(vec, player, vec.size());
		//validates player.

		std::cout << "PLACEMENT : " << placement << std::endl;

		if (placement < 0) {
			std::cout << "Invalid player.\n";
		}
		else {
			playersInRound.emplace_back(vec.at(placement));
		}

	}//end for loop

	printPlayers();
	//Confirming Players In Round.
}

void Round::printPlayers() {
	for (int i = 0; i < playersInRound.size(); i++) {
		playersInRound.at(i)->print();
	}
}

void Round::viewMatches() {
	std::cout << "-------------------------------" << "[" << roundName << "]" << "-------------------------------" << std::endl;
	std::cout << "-------------------------------" << "[DISPLAYING MATCHES]" << "-------------------------------" << std::endl;
	for (int i = 0; i < listOfMatches.size(); i++) {
		std::cout << i + 1 << ". | ";
		listOfMatches.at(i)->print();
	}
}

void Round::checkIfMatchInRange(int& choice) {
	while (choice < 1 || choice > listOfMatches.size()) {
		std::cout << "Match not in range. Try again.\n";
		std::cin >> choice;
		checkIfInt(choice);
	}
}

void Round::selectMatch() {
	if (listOfMatches.size() == 0) {
		std::cout << "There are no matches yet.\n";
	}

	else {
		viewMatches();
		std::cout << "Which match would you like to access?" << std::endl;
		int choice;
		std::cin >> choice;

		checkIfInt(choice);
		checkIfMatchInRange(choice);

		--choice;
		listOfMatches.at(choice)->menu();
		listOfMatches.at(choice)->menuSelect(getEntry());
	}
}

void Round::exitProgram() {
	std::cout << "-----------[MAIN MENU]-----------" << std::endl;
	//Switch statement does repeat after this.
}

void Round::menuSelect(int choice) {
	switch (choice) {
	case 1: //Start round, create players.
		addMatch();
		menu();
		menuSelect(getEntry());
		break;

	case 2:
		selectMatch();
		menu();
		menuSelect(getEntry());
		break;

	case 3: //Exit program.
		exitProgram();
		break;

	default:
		std::cout << "invalid option. retry now." << std::endl;
		menu();
		menuSelect(getEntry());
	}// end switch statement

}//end menuSelect

