#include "Destroyer.h"

DestroyerBuilder::~DestroyerBuilder() {

}

void DestroyerBuilder::buildHull() {
	ship->SetShipType(ShipType::Destroyer);
}

void DestroyerBuilder::buildDesignation() {
	ship->SetDesignation(ShipDesignation::Defense);
}