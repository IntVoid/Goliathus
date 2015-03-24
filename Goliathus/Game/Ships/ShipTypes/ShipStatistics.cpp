#include "ShipStatistics.h"

using namespace ShipStats;

ShipStatistics::ShipStatistics() {
	hullStrength = 0.0;
	shieldStrength = 0.0;
	maxCrewCount = 0;
	availableTurretSlots = 0;
}

ShipStatistics::~ShipStatistics() {

}

void ShipStatistics::setFrigateStats() {
	hullStrength = 100.0;
	shieldStrength = 100.0;
	maxCrewCount = 50;
	availableTurretSlots = 4;

	return;
}

void ShipStatistics::setCruiserStats() {
	hullStrength = 150.0;
	shieldStrength = 200.0;
	maxCrewCount = 150;
	availableTurretSlots = 4;

	return;
}

void ShipStatistics::setDestroyerStats() {
	hullStrength = 100.0;
	shieldStrength = 150.0;
	maxCrewCount = 150;
	availableTurretSlots = 8;

	return;
}

void ShipStatistics::setDreadnaughtStats() {
	hullStrength = 1500.0;
	shieldStrength = 5000.0;
	maxCrewCount = 5000;
	availableTurretSlots = 20;

	return;
}

// Determines what type of ship is being created.
// Once ShipType is determined, sets the appropriate
// initial stats for the ship.
void ShipStatistics::setShipStats(Ship &_ship) {
	//switch (_ship.shipType) {
	//case ShipType::Frigate:
	//	setFrigateStats();
	//	break;
	//case ShipType::Cruiser:
	//	setCruiserStats();
	//	break;
	//case ShipType::Destroyer:
	//	setDestroyerStats();
	//	break;
	//case ShipType::Dreadnaught:
	//	setDreadnaughtStats();
	//	break;
	//}
	//
	//_ship.hullStrength = hullStrength;
	//_ship.maxHullStrength = hullStrength;
	//_ship.shieldStrength = shieldStrength;
	//_ship.maxShieldStrength = shieldStrength;
	//_ship.maxCrewCount = maxCrewCount;
	//_ship.availableTurretSlots = availableTurretSlots;

	return;
}