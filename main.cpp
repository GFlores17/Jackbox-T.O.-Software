#define NOMINMAX
#include <iostream>
#include <vector>
#include <memory>
#include <string> 
#include <limits>
#include <windows.h>
//these two headers are already included in the <Windows.h> header

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
}

int main() {
	bool played = PlaySound(TEXT("C:\\Users\\hp\\Desktop\\Universe Sandbox Soundtrack - Track 6.wav"), NULL, SND_ASYNC);
	helloMessage();
	Tournament T = Tournament();

}