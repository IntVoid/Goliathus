#include "ShipTypes.h"

using namespace ShipBuilderType;

//////////////////////////////////////////////////////////////////////////
// SHIP BASE STATS
//////////////////////////////////////////////////////////////////////////
ShipBaseStats _shipBaseStats;
FrigateBaseStats _frigateBaseStats;
CruiserBaseStats _cruiserBaseStats;
DestroyerBaseStats _destroyerBaseStats;
DreadnaughtBaseStats _dreadnaughtBaseStats;

//////////////////////////////////////////////////////////////////////////
// FRIGATE BUILDER
//////////////////////////////////////////////////////////////////////////
FrigateBuilder::~FrigateBuilder() {

}

void FrigateBuilder::buildShipType() {
	ship->SetShipType(ShipType::Frigate);
}

void FrigateBuilder::buildShipDesignation() {
	ship->SetDesignation(ShipDesignation::Recon);
}

void FrigateBuilder::buildShipStats() {
	ship->SetBaseStats(_frigateBaseStats);
}

void FrigateBuilder::buildShipTurretSubSystem() {

}

void FrigateBuilder::buildShipPowerSubSystem() {
	
}

void FrigateBuilder::buildShipCrewSubSystem() {

}

//////////////////////////////////////////////////////////////////////////
// CRUISER BUILDER
//////////////////////////////////////////////////////////////////////////
CruiserBuilder::~CruiserBuilder() {

}

void CruiserBuilder::buildShipType() {
	ship->SetShipType(ShipType::Cruiser);
}

void CruiserBuilder::buildShipDesignation() {
	ship->SetDesignation(ShipDesignation::Support);
}

void CruiserBuilder::buildShipStats() {
	ship->SetBaseStats(_cruiserBaseStats);
}

void CruiserBuilder::buildShipTurretSubSystem() {

}

void CruiserBuilder::buildShipPowerSubSystem() {

}

void CruiserBuilder::buildShipCrewSubSystem() {

}

//////////////////////////////////////////////////////////////////////////
// DESTROYER BUILDER
//////////////////////////////////////////////////////////////////////////
DestroyerBuilder::~DestroyerBuilder() {

}

void DestroyerBuilder::buildShipType() {
	ship->SetShipType(ShipType::Destroyer);
}

void DestroyerBuilder::buildShipDesignation() {
	ship->SetDesignation(ShipDesignation::Defense);
}

void DestroyerBuilder::buildShipStats() {
	ship->SetBaseStats(_destroyerBaseStats);
}

void DestroyerBuilder::buildShipTurretSubSystem() {

}

void DestroyerBuilder::buildShipPowerSubSystem() {

}

void DestroyerBuilder::buildShipCrewSubSystem() {

}

//////////////////////////////////////////////////////////////////////////
// DREADNAUGHT BUILDER
//////////////////////////////////////////////////////////////////////////
DreadnaughtBuilder::~DreadnaughtBuilder() {

}

void DreadnaughtBuilder::buildShipType() {
	ship->SetShipType(ShipType::Dreadnaught);
}

void DreadnaughtBuilder::buildShipDesignation() {
	ship->SetDesignation(ShipDesignation::Offense);
}

void DreadnaughtBuilder::buildShipStats() {
	ship->SetBaseStats(_dreadnaughtBaseStats);
}

void DreadnaughtBuilder::buildShipTurretSubSystem() {

}

void DreadnaughtBuilder::buildShipPowerSubSystem() {

}

void DreadnaughtBuilder::buildShipCrewSubSystem() {

}