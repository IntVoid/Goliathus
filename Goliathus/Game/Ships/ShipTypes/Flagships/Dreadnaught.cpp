#include "Dreadnaught.h"

DreadnaughtBuilder::~DreadnaughtBuilder() {

}

void DreadnaughtBuilder::buildHull() {
	ship->SetShipType(ShipType::Dreadnaught);
}

void DreadnaughtBuilder::buildDesignation() {
	ship->SetDesignation(ShipDesignation::Offense);
}