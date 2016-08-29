#include "ShipBuilder.h"

//////////////////////////////////////////////////////////////////////////
// SHIP BUILDER
//////////////////////////////////////////////////////////////////////////

ShipBuilder::ShipBuilder() {

}

ShipBuilder::~ShipBuilder() {

}

Ship* ShipBuilder::getShip() {
	return ship;
}

// Creates the empty object so the builder can then construct its parts
void ShipBuilder::buildShip() {
	ship = new Ship();
}

//////////////////////////////////////////////////////////////////////////
// SHIP CREATOR
//////////////////////////////////////////////////////////////////////////

// This sets up the Builder and insatiates it so the creator can give
// the builder the orders that came in
void ShipCreator::setShipBuilder(ShipBuilder* _shipBuilderType) {
	shipBuilder = _shipBuilderType;
}

// Returns the object that the Builder has created.
Ship* ShipCreator::getShip() {
	return shipBuilder->getShip();
}

// This calls all necessary functions to build all the components of the object
// This function calls all necessary steps in the builder.
void ShipCreator::createShip() {
	shipBuilder->buildShip();
	shipBuilder->buildShipType();
	shipBuilder->buildShipDesignation();
	shipBuilder->buildShipStats();
	shipBuilder->buildShipCrewSubSystem();
	shipBuilder->buildShipPowerSubSystem();
	shipBuilder->buildShipTurretSubSystem();
}