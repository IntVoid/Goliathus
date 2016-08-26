#include "Menu.h"

using namespace std;

namespace MENU {

	uint8_t input = 0;
	uint8_t choices = 0;

	void TitleScreen() {
		system("CLS");
		cout << "\t\tGoliathus: The Awakening\n\n"
			<< "Welcome to Goliathus: The Awakening, a tactical turn-based game\n"
			<< "where your skills at being a commander will be put to test.\n"
			<< endl;
		system("pause");
		system("CLS");

		return;
	}

	int MainMenu() {
		choices = 3;
		cout << "\t\tGoliathus" << endl;
		cout << "1. New Game" << endl;
		cout << "2. Load Game" << endl;
		cout << "3. Exit to Desktop" << endl;
		input = ReadNumericOption(choices);
		
		return input;
	}

	int ReadNumericOption(const int& amtChoices) {
		while (true) {
			int option = 0;
			cin >> option;
			cin.clear();
			fflush(stdin);
			if (option < 1 || option > amtChoices) {
				cout << "\nInvalid Choice, try again.\n\n" << endl;
				continue;
			}
			return option;
		}
	}

	namespace PLAYERCREATIONMENU {

		int ShipSelectionMenu() {
			system("CLS");
			choices = 3;
			cout << "Welcome Commander, we have several ships available to you..." << endl;
			cout << "Here is the available roster of ships..." << endl;
			cout << "1. Frigate" << endl;
			cout << "2. Cruiser" << endl;
			cout << "3. Destroyer\n" << endl;
			input = ReadNumericOption(choices);

			return input;
		}

		int CommanderCreationMenu() {
			system("CLS");
			choices = 1;
			cout << "Welcome Commander, before we can process your application the IFS requires full" << endl;
			cout << "disclosure of your personal information. Please fill out the following paperwork" << endl;
			cout << "and we can get going.\n" << endl;
		}

		int TurretSelectionMenu() {
			return input;
		}

		int CrewSelectionMenu() {
			return input;
		}

	}

}