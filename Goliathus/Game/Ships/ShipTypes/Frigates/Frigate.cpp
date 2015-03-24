#include "Frigate.h"

using namespace ShipBuilderType;

FrigateBuilder::~FrigateBuilder() {

}

void FrigateBuilder::buildHull() {
	ship->SetShipType(ShipType::Frigate);
}

void FrigateBuilder::buildDesignation() {
	ship->SetDesignation(ShipDesignation::Recon);
}