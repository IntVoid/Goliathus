#include "Cruiser.h"

CruiserBuilder::~CruiserBuilder() {

}

void CruiserBuilder::buildHull() {
	ship->SetShipType(ShipType::Cruiser);
}

void CruiserBuilder::buildDesignation() {
	ship->SetDesignation(ShipDesignation::Support);
}