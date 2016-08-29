#pragma once

#include "Interface/Menu/Menu.h"
#include "../../Game/Items/Turrets/TurretAdapter.h"
#include "../../Game/Ships/EnemyFactory.h"
#include "../../Game/Ships/ShipBaseStats.h"

namespace GAME {

	bool RunGame();

	namespace SETUP {

		namespace PLAYER {
			void InitializePlayer();
			void InitializeBeginnerShips();
			void CreatePlayerShip();
			void OutfitPlayerShip();
		}
		
		// stuff go here

	}

}