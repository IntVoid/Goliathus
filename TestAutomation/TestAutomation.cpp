// TestAutomation.cpp : Defines the entry point for the console application.
//
#pragma once

#include "stdafx.h"

#include "catch.h"
#include "Game\Ships\EnemyFactory.h"
#include "Game\Ships\ShipTypes\ShipTypes.h"
#include <memory>

TEST_CASE("Enemy Factory: Build enemy, Returns Offense Frigate", "[EnemyFactory][Frigate][Designation]")
{
	EnemyFactory* enemyFactory = new EnemyFactory;
	Ship* enemyShip = enemyFactory->NewEnemyShip(ShipType::Frigate, ShipDesignation::Offense);

	REQUIRE(enemyShip->getShipType() == ShipType::Frigate);
	REQUIRE(enemyShip->getShipDesignation() == ShipDesignation::Offense);

	delete enemyFactory;
	enemyFactory = nullptr;
	delete enemyShip;
	enemyShip = nullptr;
}

TEST_CASE("Enemy Factory: Build enemy, Returns Defense Cruiser", "[EnemyFactory][Cruiser][Designation]")
{
	EnemyFactory* enemyFactory = new EnemyFactory;
	Ship* enemyShip = enemyFactory->NewEnemyShip(ShipType::Cruiser, ShipDesignation::Defense);

	REQUIRE(enemyShip->getShipType() == ShipType::Cruiser);
	REQUIRE(enemyShip->getShipDesignation() == ShipDesignation::Defense);

	delete enemyFactory;
	enemyFactory = nullptr;
	delete enemyShip;
	enemyShip = nullptr;
}

TEST_CASE("Ship Builder: Build Ship, Returns Frigate", "[ShipBuilder][Frigate]")
{
	ShipCreator shipCreator;
	ShipBuilder* shipBuilder(new ShipBuilderType::FrigateBuilder);
	shipCreator.setShipBuilder(shipBuilder);
	shipCreator.createShip();
	Ship* ship = shipCreator.getShip();

	REQUIRE(ship->getShipType() == ShipType::Frigate);

	delete shipBuilder;
	shipBuilder = nullptr;
	delete ship;
	ship = nullptr;
}

TEST_CASE("Ship Builder: Build Ship, Returns Cruiser", "[ShipBuilder][Cruiser]")
{
	ShipCreator shipCreator;
	ShipBuilder* shipBuilder(new ShipBuilderType::CruiserBuilder);
	shipCreator.setShipBuilder(shipBuilder);
	shipCreator.createShip();
	Ship* ship = shipCreator.getShip();

	REQUIRE(ship->getShipType() == ShipType::Cruiser);

	delete shipBuilder;
	shipBuilder = nullptr;
	delete ship;
	ship = nullptr;
}

TEST_CASE("Ship Builder: Build Cruiser, State Should be Normal", "[ShipBuilder][Cruiser][State]")
{
	ShipCreator shipCreator;
	ShipBuilder* shipBuilder(new ShipBuilderType::CruiserBuilder);
	shipCreator.setShipBuilder(shipBuilder);
	shipCreator.createShip();
	Ship* ship = shipCreator.getShip();

	REQUIRE(ship->getShipState() == ShipState::NORMAL);

	delete shipBuilder;
	shipBuilder = nullptr;
	delete ship;
	ship = nullptr;
}

TEST_CASE("Ship Builder: Build Cruiser, Set State to Destroyed", "[ShipBuilder][Cruiser][State]")
{
	ShipCreator shipCreator;
	ShipBuilder* shipBuilder(new ShipBuilderType::CruiserBuilder);
	shipCreator.setShipBuilder(shipBuilder);
	shipCreator.createShip();
	Ship* ship = shipCreator.getShip();
	ship->SetShipState(ShipState::DESTROYED);

	REQUIRE(ship->getShipState() == ShipState::DESTROYED);

	delete shipBuilder;
	shipBuilder = nullptr;
	delete ship;
	ship = nullptr;
}

TEST_CASE("Ship Builder: Build Cruiser, Default Max Turrets = Cruiser Default", "[ShipBuilder][Cruiser][TurretCount]")
{
	ShipCreator shipCreator;
	ShipBuilder* shipBuilder(new ShipBuilderType::CruiserBuilder);
	shipCreator.setShipBuilder(shipBuilder);
	shipCreator.createShip();
	Ship* ship = shipCreator.getShip();

	CruiserBaseStats defaultStats;

	REQUIRE(ship->getShipMaxTurretCount() == defaultStats.maxTurretSlots);

	delete shipBuilder;
	shipBuilder = nullptr;
	delete ship;
	ship = nullptr;
}

TEST_CASE("Ship Builder: Build Cruiser, Set Max Turret Count = 10", "[ShipBuilder][Cruiser][TurretCount]")
{
	ShipCreator shipCreator;
	ShipBuilder* shipBuilder(new ShipBuilderType::CruiserBuilder);
	shipCreator.setShipBuilder(shipBuilder);
	shipCreator.createShip();
	Ship* ship = shipCreator.getShip();

	ship->SetShipMaxTurretCount(10);

	REQUIRE(ship->getShipMaxTurretCount() == 10);

	delete shipBuilder;
	shipBuilder = nullptr;
	delete ship;
	ship = nullptr;
}

TEST_CASE("Initalize Player Ship Dreadnaught", "[PlayerShip]")
{
	ShipCreator shipCreator;
	ShipBuilder* shipBuilder(new ShipBuilderType::DreadnaughtBuilder);
	shipCreator.setShipBuilder(shipBuilder);
	shipCreator.createShip();
	Ship* ship = shipCreator.getShip();

	DreadnaughtBaseStats baseStats;
	
	SECTION("Player Ship = Dreadnaught")
	{
		REQUIRE(ship->getShipType() == ShipType::Dreadnaught);
	}
	SECTION("Confirm Base Stats Have Been Assigned")
	{
		CAPTURE(baseStats.maxCrewCount);
		CAPTURE(ship->getShipMaxCrewCount());
		CHECK(ship->getShipMaxCrewCount() == baseStats.maxCrewCount);
		CHECK(ship->getShipMaxHullStrength() == baseStats.maxHullStrength);
		CHECK(ship->getShipMaxShieldStrength() == baseStats.maxShieldStrength);
		CHECK(ship->getShipMaxTurretCount() == baseStats.maxTurretSlots);
	}

	delete shipBuilder;
	shipBuilder = nullptr;
	delete ship;
	ship = nullptr;
}

SCENARIO("Player has gotten into a space battle with their ship")
{
	GIVEN("The player is flying a Destroyer class ship")
	{
		ShipCreator shipCreator;
		ShipBuilder* shipBuilder(new ShipBuilderType::DestroyerBuilder);
		shipCreator.setShipBuilder(shipBuilder);
		shipCreator.createShip();
		Ship* ship = shipCreator.getShip();

		DestroyerBaseStats baseStats;

		WHEN("The players ship first enters the fight without damage")
		{
			CAPTURE(ship->getShipCurrentHull());
			CAPTURE(ship->getShipCurrentShield());
			THEN("Hull and Strength should be max") 
			{
				REQUIRE(ship->getShipMaxHullStrength() == baseStats.maxHullStrength);
				REQUIRE(ship->getShipMaxShieldStrength() == baseStats.maxShieldStrength);
			}

			WHEN("Hull lightly damaged in the fight and has no Shield")
			{
				ship->AdjustCurrentHull(-50);
				ship->SetShipCurrentShield(0);
				ship->SetShipState(ShipState::LIGHTLY_DAMGED);
				THEN("Return LIGHTLY_DAMAGED, Hull = 100, Shield = 0")
				{
					REQUIRE(ship->getShipState() == ShipState::LIGHTLY_DAMGED);
					CHECK(ship->getShipCurrentHull());
					REQUIRE(ship->getShipCurrentHull() == 100);
					REQUIRE(ship->getShipCurrentShield() == 0);
				}
			}
		}

		delete shipBuilder;
		shipBuilder = nullptr;
		delete ship;
		ship = nullptr;
	}
}