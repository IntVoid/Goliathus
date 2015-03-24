#pragma once

#include "TurretGroup.h"

class AbstractTurretType : public TurretGroup {
public:
	//virtual void fire();
	//virtual void reload();
private:
protected:
	virtual TB_Turret cannon() = 0;
	virtual TB_Turret multiCannon() = 0;
	virtual TB_Turret laser() = 0;
	virtual TB_Turret multiLaser() = 0;
	virtual TB_Turret plasmaAccelerator() = 0;
	virtual TB_Turret railgun() = 0;
};

class TurretType : public AbstractTurretType {
	TB_Turret cannon();
	TB_Turret multiCannon();
	TB_Turret laser();
	TB_Turret multiLaser();
	TB_Turret plasmaAccelerator();
	TB_Turret railgun();
};