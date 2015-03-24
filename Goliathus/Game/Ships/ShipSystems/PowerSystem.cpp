#include "PowerSystem.h"

using namespace std;

ShipPowerSystem::ShipPowerSystem() {
	totalSubPower = 0;
	weaponSubsystem = 0;
	supportSubsystem = 0;
	engineSubsystem = 0;
	shiftDriveSubsystem = 0;
}

ShipPowerSystem::~ShipPowerSystem() {

}

void ShipPowerSystem::beginPowerDistribution() {
	string addRemoveS;
	string systemS;
	PowerSystems powerSystem;

	cout << "\tPower Distribution Panel" << endl;
	cout << "Add/Remove Power to what system or Balance Power? (Ex. Add Weapons)" << endl;
	cin >> addRemoveS >> systemS;

	if (systemS.compare("Weapons"))
		powerSystem = PowerSystems::Weapons;
	else if (systemS.compare("Support"))
		powerSystem = PowerSystems::Support;
	else if (systemS.compare("Engines"))
		powerSystem = PowerSystems::Engines;
	else if (systemS.compare("ShiftDrive"))
		powerSystem = PowerSystems::ShiftDrive;

	if (addRemoveS.compare("Add"))
		ShipPowerSystem::addPower(powerSystem);
	else if (addRemoveS.compare("Remove"))
		ShipPowerSystem::removePower(powerSystem);
	else if (addRemoveS.compare("Balance"))
		ShipPowerSystem::balancePower();
}

void ShipPowerSystem::balancePower() {

}

void ShipPowerSystem::addPower(PowerSystems _powerSystem) {
	int transferAmount = 1;

	if (totalSubPower > 0) {
			ShipPowerSystem::adjustPower(_powerSystem, transferAmount);
	}
	else {
		cout << "No power available to redirect to ";
		switch (_powerSystem) {
		case PowerSystems::Weapons:
			cout << "Weapons";
			break;
		case PowerSystems::Support:
			cout << "Support";
			break;
		case PowerSystems::Engines:
			cout << "Engines";
			break;
		case PowerSystems::ShiftDrive:
			cout << "ShiftDrive";
			break;
		}
		cout << "!" << endl;
	}
}

void ShipPowerSystem::removePower(PowerSystems _powerSystem) {

}

void ShipPowerSystem::adjustPower(PowerSystems _powerSystem, int _amount) {

}