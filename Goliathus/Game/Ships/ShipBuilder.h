#pragma once

#include "Ship.h"

// This is the ship builder, it concerns itself
// in building the different types of ships possible
// in the game with ease. The builder functionality is
// true virtual as it is inherited by the object that is
// being built. In this case, we define the virtual functions
// in the ship object.
class ShipBuilder : public Ship {
public:
	ShipBuilder();
	virtual ~ShipBuilder();		// Virtual constructor for overriding functionality
	Ship* getShip();			// Returns the object the builder has created
	void buildShip();			// Main Builder Loop.

	// Below are true virtual functions that will construct the many
	// pieces of the object.
	virtual void buildShipType() = 0;
	virtual void buildShipDesignation() = 0;
	virtual void buildShipStats() = 0;
	virtual void buildShipTurretSubSystem() = 0;
	virtual void buildShipPowerSubSystem() = 0;
	virtual void buildShipCrewSubSystem() = 0;
protected:
	Ship* ship;					// Object the builder will be creating
};

// This is a utility class for the ship builder. This utility
// is called to interact with the Builder. Think of this as the
// delivery system.
class ShipCreator {
public:
	void setShipBuilder(ShipBuilder* _shipBuilderType);	// Initializes the Builder
	Ship* getShip();									// Returns the object given to it by the Builder
	void createShip();									// Function that will call all underlying functions
private:
	ShipBuilder* shipBuilder;							// The Builder the Creator will be using
};