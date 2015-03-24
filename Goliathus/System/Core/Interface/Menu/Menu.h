#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cstdint>
#include <string>


// This entire MENU namespace is designed as an interface/proxy. It serves
// to provide the user a simple menu to interact with the multitude of parts
// within the game and provide a way of easy interaction for the user.
namespace MENU {

	void TitleScreen();
	int MainMenu();
	int ReadNumericOption(const int& amtChoices);

	namespace PLAYERCREATIONMENU {

		int ShipSelectionMenu();
		int TurretSelectionMenu();
		int CrewSelectionMenu();

	}
	
}