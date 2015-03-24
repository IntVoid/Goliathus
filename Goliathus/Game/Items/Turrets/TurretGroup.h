#pragma once

#include "Turret.h"

typedef bool TB_Turret;

class AbstractTurretGroup : public Turret {
public:
private:
protected:
	virtual TB_Turret offense() = 0;
	virtual TB_Turret defense() = 0;
	virtual TB_Turret utility() = 0;
	virtual TB_Turret support() = 0;
};

class TurretGroup : public AbstractTurretGroup {
public:
	//virtual void fire();
	//virtual void reload();
	TB_Turret offense();
	TB_Turret defense();
	TB_Turret utility();
	TB_Turret support();
private:
	void getGroup();
};