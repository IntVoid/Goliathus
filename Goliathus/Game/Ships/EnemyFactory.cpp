#include "EnemyFactory.h"

using namespace ShipBuilderType;

// Here we see a Factory utilizing the same very ship builder.
Ship *EnemyFactory::NewEnemyShip(ShipType _shipType, ShipDesignation _shipDesignation) {

	ShipCreator shipCreator;

	if (_shipType == ShipType::Frigate) {
		ShipBuilder* frigateBuilder(new FrigateBuilder);
		shipCreator.setShipBuilder(frigateBuilder);
		shipCreator.createShip();
		Ship* frigateShip = shipCreator.getShip();
		frigateShip->SetDesignation(_shipDesignation);

		return frigateShip;
	}

	if (_shipType == ShipType::Cruiser) {
		ShipBuilder* cruiserBuilder(new CruiserBuilder);
		shipCreator.setShipBuilder(cruiserBuilder);
		shipCreator.createShip();
		Ship* cruiserShip = shipCreator.getShip();

		return cruiserShip;
	}

	return nullptr;

}