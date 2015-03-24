#pragma once

#include "../ShipBuilder.h"
#include "ShipStatistics.h"

namespace ShipBuilderType {

	class FrigateBuilder : public ShipBuilder {
	public:
		virtual ~FrigateBuilder();
		virtual void buildShipType();
		virtual void buildShipDesignation();
		virtual void buildShipStats();
		virtual void buildShipTurretSubSystem();
		virtual void buildShipPowerSubSystem();
		virtual void buildShipCrewSubSystem();
	};

	class CruiserBuilder : public ShipBuilder {
	public:
		virtual ~CruiserBuilder();
		virtual void buildShipType();
		virtual void buildShipDesignation();
		virtual void buildShipStats();
		virtual void buildShipTurretSubSystem();
		virtual void buildShipPowerSubSystem();
		virtual void buildShipCrewSubSystem();
	};

	class DestroyerBuilder : public ShipBuilder {
	public:
		virtual ~DestroyerBuilder();
		virtual void buildShipType();
		virtual void buildShipDesignation();
		virtual void buildShipStats();
		virtual void buildShipTurretSubSystem();
		virtual void buildShipPowerSubSystem();
		virtual void buildShipCrewSubSystem();
	};

	class DreadnaughtBuilder : public ShipBuilder {
	public:
		virtual ~DreadnaughtBuilder();
		virtual void buildShipType();
		virtual void buildShipDesignation();
		virtual void buildShipStats();
		virtual void buildShipTurretSubSystem();
		virtual void buildShipPowerSubSystem();
		virtual void buildShipCrewSubSystem();
	};

}