#include "ShipBaseStats.h"

ShipBaseStats::ShipBaseStats() {
	turningSpeed = 0.0;
	accelerationRate = 0.0;
	maxHullStrength = 0.0;
	maxShieldStrength = 0.0;
	maxTurretSlots = 0;
	maxCrewCount = 0;
}


FrigateBaseStats::FrigateBaseStats() {
	turningSpeed = 100.0;
	accelerationRate = 100.0;
	maxHullStrength = 100.0;
	maxShieldStrength = 100.0;
	maxTurretSlots = 4;
	maxCrewCount = 150;
}

FrigateBaseStats::~FrigateBaseStats() {

}

CruiserBaseStats::CruiserBaseStats() {
	turningSpeed = 70.0;
	accelerationRate = 70.0;
	maxHullStrength = 150.0;
	maxShieldStrength = 300.0;
	maxTurretSlots = 6;
	maxCrewCount = 350;
}

CruiserBaseStats::~CruiserBaseStats() {

}

DestroyerBaseStats::DestroyerBaseStats() {
	turningSpeed = 56.0;
	accelerationRate = 75.0;
	maxHullStrength = 150.0;
	maxShieldStrength = 300.0;
	maxTurretSlots = 8;
	maxCrewCount = 275;
}

DestroyerBaseStats::~DestroyerBaseStats() {

}

DreadnaughtBaseStats::DreadnaughtBaseStats() {
	turningSpeed = 15.0;
	accelerationRate = 25.0;
	maxHullStrength = 1500.0;
	maxShieldStrength = 3000.0;
	maxTurretSlots = 20;
	maxCrewCount = 2750;
}

DreadnaughtBaseStats::~DreadnaughtBaseStats() {

}