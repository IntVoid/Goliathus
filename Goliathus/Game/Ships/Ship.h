#pragma once

#include "./ShipSystems/CrewSystem.h"
#include "./ShipSystems/PowerSystem.h"
#include "./ShipSystems/TurretSystem.h"
#include "../Items/Turrets/Turret.h"

#include "ShipBaseStats.h"

#include <memory>
#include <map>

using namespace std;

// Possible States the Ship could be in.
enum class ShipState {
	SILENT, 
	NORMAL,
	LIGHTLY_DAMGED,
	MODERATELY_DAMAGED,
	CRITICALY_DAMAGED,
	EXPLODING,
	DESTROYED,
	CLOAKED,
	SHIELDED
};

// Possible Types the Ship could be.
enum class ShipType {
	Empty,
	Fighter, Interceptor, Bomber, Recon,
	LightFrigate, Frigate, SupportFrigate, HeavyFrigate,
	Destroyer, HeavyDestroyer, SupportDestroyer,
	LightCruiser, Cruiser, HeavyCruiser, SupportCruiser,
	Capital, HeavyCapital, SupportCapital,
	Dreadnaught, Carrier, Mothership
};

// Possible Roles the Ship could fill.
enum class ShipDesignation {
	Empty,
	Offense, Defense,
	Support, Recon
};

// Ship Class, this class is a composition design pattern.
// The ship is dependent on ShipPowerSystem, ShipTurretSystem,
// and ShipCrewSystem but those three classes are not.
class Ship {
protected:
	ShipType shipType;
	ShipDesignation shipDesignation;
	ShipState shipState;
	ShipBaseStats shipBaseStats;
public:
	Ship();
	~Ship();

	/* Set Functions */
	void SetShipType(ShipType _shipType) { shipType = _shipType; };
	void SetDesignation(ShipDesignation _shipDesignation) { shipDesignation = _shipDesignation; };
	void SetBaseStats(ShipBaseStats _shipBaseStats) { shipBaseStats = _shipBaseStats; };
	void SetShipPower() { shipPowerSystem->beginPowerDistribution(); };
	void SetShipMaxTurretCount(int _turretCount) { shipBaseStats.maxTurretSlots = _turretCount; };
	void SetShipCrewCount(int _crewCount) { shipBaseStats.maxCrewCount = _crewCount; };
	void SetShipState(ShipState _shipState) { shipState = _shipState; };
	void SetShipCurrentHull(float _currentHull) { currentHullStrength = _currentHull; };
	void SetShipCurrentShield(float _currentShield) { currentShieldStrength = _currentShield; };
	void ShipReadout();

	/* Adjust Functions */
	void AdjustCurrentHull(float _modifer) { currentHullStrength += _modifer; };
	void AdjustCurrentShield(float _modifier) { currentShieldStrength += _modifier; };

	/* Get Functions */
	void getShipTypeName();
	int& getShipMaxTurretCount() { return shipBaseStats.maxTurretSlots; };
	float& getShipMaxHullStrength() { return shipBaseStats.maxHullStrength; };
	float& getShipCurrentHull() { return currentHullStrength; };
	float& getShipMaxShieldStrength() { return shipBaseStats.maxShieldStrength; };
	float& getShipCurrentShield() { return currentShieldStrength; };
	int& getShipMaxCrewCount() { return shipBaseStats.maxCrewCount; };
	ShipType getShipType() { return shipType; };
	ShipDesignation getShipDesignation() { return shipDesignation; };
	ShipState getShipState() { return shipState; };
private:
	float currentHullStrength;
	float currentShieldStrength;
	float availableTurretSlots;
	unique_ptr<ShipPowerSystem> shipPowerSystem;
	unique_ptr<ShipTurretSystem> shipTurretSystem;
	unique_ptr<ShipCrewSystem> shipCrewSystem;
	void ShipCrewReadout();
	void ShipTurretReadout();
	void ShipPowerReadout();
	void ShipOnDeath();
	void Update();
};