#pragma once

#include <iostream>
#include <string>
#include <cstdint>

class ShipPowerSystem {
private:
	int totalSubPower;
	int weaponSubsystem;
	int supportSubsystem;
	int engineSubsystem;
	int shiftDriveSubsystem;
	enum class PowerSystems {
		Weapons, Support,
		Engines, ShiftDrive
	};
	void adjustPower(PowerSystems _powerSystem, int _amount);
public:
	ShipPowerSystem();
	~ShipPowerSystem();
	void beginPowerDistribution();
	void balancePower();
	void addPower(PowerSystems _powerSystem);
	void removePower(PowerSystems _powerSystem);
};