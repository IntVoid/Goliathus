#include "ShipBuilder.h"

ShipBuilder::ShipBuilder() {

}

ShipBuilder::~ShipBuilder() {

}

Ship* ShipBuilder::getShip() {
	return ship;
}

void ShipBuilder::buildShip() {
	//auto ship = make_shared<Ship>();
	ship = new Ship();
}

void ShipCreator::setShipBuilder(ShipBuilder* _shipBuilderType) {
	shipBuilder = _shipBuilderType;
}

Ship* ShipCreator::getShip() {
	return shipBuilder->getShip();
}

void ShipCreator::createShip() {
	shipBuilder->buildShip();
	shipBuilder->buildHull();
	shipBuilder->buildDesignation();
}