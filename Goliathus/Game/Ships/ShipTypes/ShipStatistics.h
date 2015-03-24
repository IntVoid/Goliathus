#pragma once

#include "../Ship.h"

// Chain of Responsibility Design Pattern.
// This class is being used as a utility to help
// clean up my code base by using the COR Design Pattern.
// This works by housing all required information needed
// for initializing a multitude of different ships stats.
// This class is called on by the Builder, which provides
// what shipType it is. ShipStatistics then takes the
// reference to the object, and sets its initial statistics.
namespace ShipStats {

	class ShipStatistics {
	public:
		ShipStatistics();
		~ShipStatistics();
		void setFrigateStats();
		void setCruiserStats();
		void setDestroyerStats();
		void setDreadnaughtStats();
		void setShipStats(Ship &_ship);
	private:
		float hullStrength;
		float shieldStrength;
		int maxCrewCount;
		int availableTurretSlots;
	};

}