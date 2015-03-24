#pragma once

#include "ShipBuilderIncludes.h"

// Factory to build enemy ships. It utilizes the ShipBuilder to expedite
// the process
class EnemyFactory {
public:
	static Ship *NewEnemyShip(ShipType _shipType, ShipDesignation _shipDesignation);
};
