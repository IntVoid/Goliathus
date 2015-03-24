#pragma once

#include "Core/Game.h"

namespace SYSTEM {
	
	enum class GameState {
		TITLESCREEN,
		MAINMENU,
		MAINGAME,
		LOADGAME,
		ENDGAME,
		CREDITS,
		QUIT
	};

	static GameState gameState;

	void Initialize();
	bool RunMainApplication();
	bool RunMainMenu();
}