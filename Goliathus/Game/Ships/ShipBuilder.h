#pragma once

#include "Ship.h"

// This is the ship builder, it concerns itself
// in building the different types of ships possible
// in the game with ease.
class ShipBuilder : public Ship {
public:
	ShipBuilder();
	virtual ~ShipBuilder();
	Ship* getShip();
	void buildShip();
	virtual void buildShipType() = 0;
	virtual void buildShipDesignation() = 0;
	virtual void buildShipStats() = 0;
	virtual void buildShipTurretSubSystem() = 0;
	virtual void buildShipPowerSubSystem() = 0;
	virtual void buildShipCrewSubSystem() = 0;
protected:
	Ship* ship;
};

// This is a utility class for the ship builder.
class ShipCreator {
public:
	void setShipBuilder(ShipBuilder* _shipBuilderType);
	Ship* getShip();
	void createShip();
private:
	ShipBuilder* shipBuilder;
};