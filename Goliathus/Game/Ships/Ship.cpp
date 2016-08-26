#include "Ship.h"

using namespace std;

// Translator Design Pattern used with a Hash Map implementation & Overriding
// to help print out the string values of enumerators. I override
// the ostream operator to search for the appropriate values needed.
ostream& operator<<(ostream& out, const ShipState value) {
#define BEGINSTRING 11
#define ENDSTRING 31
	static map<ShipState, string> shipStateMap;
	if (shipStateMap.size() == 0) {
#define INSERT_ELEMENT(p) shipStateMap[p] = #p
		INSERT_ELEMENT(ShipState::SILENT);
		INSERT_ELEMENT(ShipState::NORMAL);
		INSERT_ELEMENT(ShipState::LIGHTLY_DAMGED);
		INSERT_ELEMENT(ShipState::MODERATELY_DAMAGED);
		INSERT_ELEMENT(ShipState::CRITICALY_DAMAGED);
		INSERT_ELEMENT(ShipState::EXPLODING);
		INSERT_ELEMENT(ShipState::DESTROYED);
		INSERT_ELEMENT(ShipState::CLOAKED);
		INSERT_ELEMENT(ShipState::SHIELDED);
#undef INSERT_ELEMENT
	}
	return out << shipStateMap[value].substr(BEGINSTRING, ENDSTRING);
}

// As above, another Translator for ShipType Enumerator
ostream& operator<<(ostream& out, const ShipType value) {
#define BEGINSTRING 10
#define	ENDSTRING 30
	static map<ShipType, string> shipTypeMap;
	if (shipTypeMap.size() == 0) {
#define INSERT_ELEMENT(p) shipTypeMap[p] = #p
		INSERT_ELEMENT(ShipType::Empty);
		INSERT_ELEMENT(ShipType::Fighter);
		INSERT_ELEMENT(ShipType::Interceptor);
		INSERT_ELEMENT(ShipType::Bomber);
		INSERT_ELEMENT(ShipType::Recon);
		INSERT_ELEMENT(ShipType::LightFrigate);
		INSERT_ELEMENT(ShipType::Frigate);
		INSERT_ELEMENT(ShipType::SupportFrigate);
		INSERT_ELEMENT(ShipType::HeavyFrigate);
		INSERT_ELEMENT(ShipType::Destroyer);
		INSERT_ELEMENT(ShipType::HeavyDestroyer);
		INSERT_ELEMENT(ShipType::SupportDestroyer);
		INSERT_ELEMENT(ShipType::LightCruiser);
		INSERT_ELEMENT(ShipType::Cruiser);
		INSERT_ELEMENT(ShipType::HeavyCruiser);
		INSERT_ELEMENT(ShipType::SupportCruiser);
		INSERT_ELEMENT(ShipType::Capital);
		INSERT_ELEMENT(ShipType::HeavyCapital);
		INSERT_ELEMENT(ShipType::SupportCapital);
		INSERT_ELEMENT(ShipType::Dreadnaught);
		INSERT_ELEMENT(ShipType::Carrier);
		INSERT_ELEMENT(ShipType::Mothership);
#undef INSERT_ELEMENT
	}
	return out << shipTypeMap[value].substr(BEGINSTRING, ENDSTRING);
}

// As above, another Translator for ShipDesignation Enumerator
ostream& operator<<(ostream& out, const ShipDesignation value) {
#define BEGINSTRING 17
#define ENDSTRING 37
	static map<ShipDesignation, string> shipDesignationMap;
	if (shipDesignationMap.size() == 0) {
#define INSERT_ELEMENT(p) shipDesignationMap[p] = #p
		INSERT_ELEMENT(ShipDesignation::Empty);
		INSERT_ELEMENT(ShipDesignation::Offense);
		INSERT_ELEMENT(ShipDesignation::Defense);
		INSERT_ELEMENT(ShipDesignation::Support);
		INSERT_ELEMENT(ShipDesignation::Recon);
#undef INSERT_ELEMENT
	}
	return out << shipDesignationMap[value].substr(BEGINSTRING, ENDSTRING);
}

// Basic initialization of critical ship dependencies
Ship::Ship() {
	unique_ptr<ShipPowerSystem> shipPowerSystem;
	unique_ptr<ShipTurretSystem> shipTurretSystem;
	unique_ptr<ShipCrewSystem> shipCrewSystem;
	ShipBaseStats *shipBaseStats = nullptr;
	this->shipType = ShipType::Empty;
	this->shipDesignation = ShipDesignation::Empty;
	this->shipState = ShipState::NORMAL;
	this->currentHullStrength = 0.0;
	this->currentShieldStrength = 0.0;
	this->availableTurretSlots = 0;
}

Ship::~Ship() {

}

//TODO: Builder Object. This is the Object that is being created when the Builder is used.
void Ship::SetShipType(ShipType _shipType) {
	shipType = _shipType;
}

void Ship::SetDesignation(ShipDesignation _shipDesignation) {
	shipDesignation = _shipDesignation;
}

void Ship::SetBaseStats(ShipBaseStats &_shipBaseStats) {
	shipBaseStats = &_shipBaseStats;
}

void Ship::SetShipPower() {
	//shipPowerSystem->beginPowerDistribution();
}

void Ship::SetShipTurretCount() {

}

void Ship::SetShipCrewCount() {

}

// Give general feedback on ship status to user
void Ship::ShipReadout() {
	cout << "Ship Global Readout: " << endl;
	cout << "Ship State: " << shipState << endl;
	cout << "Ship Type: " << shipType << endl;
	cout << "Ship Designation: " << shipDesignation << endl;
	cout << "Total Available Turrets: " << shipBaseStats->maxTurretSlots << endl;
	cout << "Total Crew: " << shipBaseStats->maxCrewCount << endl;
	cout << "Max Hull: " << shipBaseStats->maxHullStrength << endl;
	cout << "Max Shield: " << shipBaseStats->maxShieldStrength << endl;
}

void Ship::getShipTypeName() {
	cout << shipType << endl;
}

ShipType Ship::getShipType() {
	return shipType;
}

ShipDesignation Ship::getShipDesignation() {
	return shipDesignation;
}

ShipState Ship::getShipState() {
	return shipState;
}

void Ship::ShipCrewReadout() {

}

void Ship::ShipTurretReadout() {

}

void Ship::ShipPowerReadout() {

}

// Ships personal state machine
void Ship::Update() {
	switch (shipState) {
	case ShipState::SILENT:
	case ShipState::NORMAL:
	case ShipState::LIGHTLY_DAMGED:
	case ShipState::MODERATELY_DAMAGED:
	case ShipState::CRITICALY_DAMAGED:
	case ShipState::EXPLODING:
	case ShipState::DESTROYED:
	case ShipState::CLOAKED:
	case ShipState::SHIELDED:
		break;
	}
}