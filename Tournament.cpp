#include <iostream>
#include <vector>
#include <memory>
#include <string> 
#include <limits>

#include "Round.h"
#include "Match.h"
#include "Player.h"
#include "Tournament.h"
#include "getEntry.h"

	static void helloMessage() {
		std::cout << std::setfill(' ') << std::setw(45) << "***************************************************" << std::endl;
		std::cout << std::setfill(' ') << std::setw(33) << "Welcome to the" << std::endl << std::setfill(' ') << std::setw(39) << "JACKBOX TOURNAMENT MANAGER" << std::endl << std::setfill(' ') << std::setw(30) << "program." << std::endl;
		std::cout << std::setfill(' ') << std::setw(45) << "***************************************************" << std::endl << std::endl;

		std::cout << "This is a small scorekeeping software program written in C++\n";
		std::cout << "that allows the user to organize tournament play using 3 functions.\n\n";
		/*
		std::cout << "1. Create a round.\n";
		std::cout << "    1a. This is done by naming a round, then the total # of players, then assigning each player a name.\n\n";
		std::cout << "2. Updating scores.\n";
		std::cout << "    2a. After the end of a round, the user can go through the entire list of players in the round and\n";
		std::cout << "    add points to their score.\n";
		std::cout << "    NOTE: Option to add points individually at a given time instead of every player at once to be added later.\n\n";
		std::cout << "3. Display standings.\n";
		std::cout << "    3a. The system arranges all players in the current round from highest score to lowest score.\n";
		std::cout << "    NOTE: Ability to automatically detect top cut based on user input to be added later.\n\n";
		*/
	}

	int Tournament::getEntry() {
		int choice;
		std::cin >> choice;
		checkIfInt(choice);

		while (choice < 1 || choice > 5) {
			std::cout << "Invalid option. Try again." << std::endl;
			std::cin >> choice;
			checkIfInt(choice);
		}

		std::cout << std::endl;
		return choice;
	}

	std::string tournamentName;
	std::vector<std::shared_ptr<Player>> listOfAllPlayers;
	std::vector<std::shared_ptr<Round>> listOfRounds;

	Tournament::Tournament() {
		std::cout << "Please enter Tournament name.\n";
		std::getline(std::cin, tournamentName);
		std::cout << "--------------[" << tournamentName << "]--------------" << "\n";
		//Initialize name.

		tournamentMenu();
		menuSelect(getEntry());
		//Start tournament.
	}

	void Tournament::printAllPlayers() {
		if (listOfAllPlayers.size() == 0) {//If no people in tournament.
			std::cout << "ERROR : Empty Tournament. No players registered." << std::endl;
		}

		else {
			for (int i = 0; i < listOfAllPlayers.size(); i++) {//Print the names of all "Player" objects in the Tournament "arrayOfPlayers."
				listOfAllPlayers.at(i)->print();
			}

		}

		std::cout << std::endl;
	}

	void Tournament::registerPlayers() {

		std::cout << "Number of players to register?" << std::endl;
		int numOfPlayers;
		std::cin >> numOfPlayers;
		checkIfInt(numOfPlayers);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		for (int i = 0; i < numOfPlayers; i++) {
			std::shared_ptr<Player> p = std::make_shared<Player>();
			std::cout << "Enter player name.\n";
			std::string name;

			std::getline(std::cin, name);
			p->setName(name);
			p->setScore(i);

			listOfAllPlayers.push_back(p);
			std::cout << std::endl;
		}
		std::cout << "Players registed.\n";
		//printAllPlayers(); //Test to see if adding players works.
		//std::cout << std::endl;
	}

	void Tournament::startRound() {
		std::unique_ptr<Round> round = std::make_unique<Round>(listOfAllPlayers);
		listOfRounds.push_back(move(round));
	}

	void Tournament::continueRound() {
		if (listOfRounds.size() == 0) {
			std::cout << "No rounds created yet.\n";
		}
		else {
			for (int i = 0; i < listOfRounds.size(); i++) {
				std::cout << i + 1 << ". " << listOfRounds.at(i)->roundName << "\n";
			}
			std::cout << "Select round to continue." << std::endl;
			int choice;
			std::cin >> choice;
			--choice;

			//Goes to the round in listOfRounds vector and accesses it via menu() member function.
			std::cout << "----------------[" << listOfRounds.at(choice)->roundName << "]----------------\n";
			listOfRounds.at(choice)->menu();
			listOfRounds.at(choice)->menuSelect(getEntry());
		}//end else/if

	}

	void Tournament::exitProgram() {
		std::cout << "exiting" << std::endl;
	}

	void Tournament::tournamentMenu() {
		std::cout << "Select option.\n"
			<< "1. Register Players.\n"
			<< "2. Start Round.\n"
			<< "3. Continue Round.\n"
			<< "4. Print All Players.\n"
			<< "5. Exit.\n";
	}

	void Tournament::menuSelect(int choice) {
		switch (choice) {
		case 1: //Start round, create players.
			registerPlayers();

			//Remove these 2 eventually.
			nameSort(listOfAllPlayers);
			printAllPlayers();
			//^^

			tournamentMenu();
			menuSelect(getEntry());
			break;

		case 2: //Start next round.
			startRound();
			tournamentMenu();
			menuSelect(getEntry());
			break;

		case 3: //Continue Round
			continueRound();
			tournamentMenu();
			menuSelect(getEntry());
			break;

		case 4: //Print all registered players.
			scoreSort(listOfAllPlayers);
			printAllPlayers();
			tournamentMenu();
			menuSelect(getEntry());
			break;

		/*
		case 5: //Rearrange alphabetically
			nameSort(listOfAllPlayers);
			printAllPlayers();
			tournamentMenu();
			menuSelect(getEntry());
			break;
		*/

		case 5: //Exit program.
			exitProgram();

			break;

		default:
			std::cout << "invalid option. retry now." << std::endl;
			menuSelect(getEntry());
		}// end switch statement

	}//end menuSelect

	int main() {
		Tournament T = Tournament();
		std::string x;
		/*for (int i = 0; i < 10; i++) {
			std::getline(std::cin, x);
			std::cout << x << "\n";
		}*/
		//This is a test to make my sister think I'm smarter than I actually am.
	}