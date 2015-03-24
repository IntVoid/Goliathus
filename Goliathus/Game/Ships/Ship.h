#pragma once

#include "./ShipSystems/CrewSystem.h"
#include "./ShipSystems/PowerSystem.h"
#include "./ShipSystems/TurretSystem.h"
#include "../Items/Turrets/Turret.h"

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
	Fighter, Interceptor, Bomber, Recon,
	LightFrigate, Frigate, SupportFrigate, HeavyFrigate,
	Destroyer, HeavyDestroyer, SupportDestroyer,
	LightCruiser, Cruiser, HeavyCruiser, SupportCruiser,
	Capital, HeavyCapital, SupportCapital,
	Dreadnaught, Carrier, Mothership
};

// Possible Roles the Ship could fill.
enum class ShipDesignation {
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
public:
	Ship();
	~Ship();
	void SetShipType(ShipType _shipType);
	void SetDesignation(ShipDesignation _shipDesignation);
	void SetShipPower();
	void SetShipTurretCount();
	void SetShipCrewCount();
	void ShipReadout();
	void getShipTypeName();
	ShipType getShipType();
	ShipDesignation getShipDesignation();
	ShipState getShipState();
private:
	float hullStrength;
	float shieldStrength;
	float turretSlotCount;
	float crewCount;
	unique_ptr<ShipPowerSystem> shipPowerSystem;
	unique_ptr<ShipTurretSystem> shipTurretSystem;
	unique_ptr<ShipCrewSystem> shipCrewSystem;
	void ShipCrewReadout();
	void ShipTurretReadout();
	void ShipPowerReadout();
	void ShipOnDeath();
	void Update();
};