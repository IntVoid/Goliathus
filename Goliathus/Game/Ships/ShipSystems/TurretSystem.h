#pragma once

#include <unordered_map>
#include <vector>
#include <cstdint>
#include <iostream>

class ShipTurretSystem {
private:
	int totalTurretCount;
	int leftTurretCount;
	int rightTurretCount;
	int topTurretCount;
	int bottomTurretCount;
	enum class TurretSockets {
		Left, Right, Top, Down
	};
public:
	ShipTurretSystem();
	~ShipTurretSystem();
	void addTurret();
	void removeTurret();
	void changeTurret();
	void allocateTurret();
	void getTurret();
};