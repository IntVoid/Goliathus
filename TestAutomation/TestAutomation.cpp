// TestAutomation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "../Goliathus/Game/Ships/Ship.h"
#include "../Goliathus/Game/Ships/EnemyFactory.h"

TEST_CASE("Create Enemy Cruiser")
{
	EnemyFactory* enemyFactory = new EnemyFactory;
	Ship* enemyShip = new Ship;
	//Ship* enemyShip = enemyFactory->NewEnemyShip(ShipType::Cruiser, ShipDesignation::Offense);

	//REQUIRE(enemyShip->getShipType() == ShipType::Cruiser);
}