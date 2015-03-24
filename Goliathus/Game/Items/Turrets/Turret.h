#pragma once

#include <iostream>
#include <cstdint>

class Turret {
public:
	Turret();
	~Turret();
	//virtual void fire();
	//virtual void reload();
private:

protected:
	uint8_t turretType;
	uint8_t turretGroup;
	float turnRate;
	float fireRate;
	float heatCapacity;
	float ammoCapacity;
	enum class turretSize { 
		VSmall, Small, 
		Medium, Large, 
		XLarge, Capital 
	};
};