#include "ShipBuilder.h"

//TODO: Builder Structure / Body

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

void ShipBuilder::buildShip() {
	//auto ship = make_shared<Ship>();
	ship = new Ship();
}

//////////////////////////////////////////////////////////////////////////
// SHIP CREATOR
//////////////////////////////////////////////////////////////////////////

void ShipCreator::setShipBuilder(ShipBuilder* _shipBuilderType) {
	shipBuilder = _shipBuilderType;
}

Ship* ShipCreator::getShip() {
	return shipBuilder->getShip();
}

// This calls all necessary functions to build all the components of the object
void ShipCreator::createShip() {
	shipBuilder->buildShip();
	shipBuilder->buildShipType();
	shipBuilder->buildShipDesignation();
	shipBuilder->buildShipStats();
	shipBuilder->buildShipCrewSubSystem();
	shipBuilder->buildShipPowerSubSystem();
	shipBuilder->buildShipTurretSubSystem();
}