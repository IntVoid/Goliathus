#include "System.h"

namespace SYSTEM {

	void Initialize() {
		// Initialize stuff here if needed
		gameState = GameState::TITLESCREEN;
		
		// THEN call Game loop
		return;
	}

	bool RunMainApplication() {

		system("CLS");
		
		switch (gameState) {
		case GameState::TITLESCREEN:
			MENU::TitleScreen();
			gameState = GameState::MAINMENU;
			return true;
		case GameState::MAINMENU:
			while (RunMainMenu());
			return true;
		case GameState::MAINGAME:
			while(GAME::RunGame());
			return true;
		case GameState::LOADGAME:
			// RunLoadingMenu();
			cout << "Currently Unavailable" << endl;
			gameState = GameState::MAINMENU;
			system("pause");
			return true;
		case GameState::ENDGAME:
			return true;
		case GameState::CREDITS:
			return true;
		case GameState::QUIT:
			return false;
		}

		return true;
	}

	bool RunMainMenu() {	
		int decision = MENU::MainMenu();
		switch (decision) {
		case 1:
			gameState = GameState::MAINGAME;
			return false;
		case 2:
			gameState = GameState::LOADGAME;
			return false;
		case 3: 
			gameState = GameState::QUIT;
			return false;
		}
	}

}