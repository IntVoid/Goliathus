#pragma once

// Flyweight Implementation
// This Flyweight will hold a central point for all
// common data shared by all ship types.

class ShipBaseStats {
public:
	ShipBaseStats();
	float turningSpeed;
	float accelerationRate;
	float maxHullStrength;
	float maxShieldStrength;
	int maxTurretSlots;
	int maxCrewCount;
};

struct FrigateBaseStats : public ShipBaseStats {
	FrigateBaseStats();
	~FrigateBaseStats();
};

struct CruiserBaseStats : public ShipBaseStats {
	CruiserBaseStats();
	~CruiserBaseStats();
};

struct DestroyerBaseStats : public ShipBaseStats {
	DestroyerBaseStats();
	~DestroyerBaseStats();
};