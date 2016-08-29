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
	ShipBaseStats *shipBaseStats;
public:
	Ship();
	~Ship();
	void SetShipType(ShipType _shipType);
	void SetDesignation(ShipDesignation _shipDesignation);
	void SetBaseStats(ShipBaseStats &_shipBaseStats);
	void SetShipPower(ShipPowerSystem &_shipPower);
	void SetShipTurrets(ShipTurretSystem &_shipTurrets);
	void SetShipTurretCount();
	void SetShipCrewCount();
	void ShipReadout();
	void getShipTypeName();
	ShipType getShipType();
	ShipDesignation getShipDesignation();
	ShipState getShipState();
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