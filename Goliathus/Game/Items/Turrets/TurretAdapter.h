#pragma once

#include "../../../Game/Items/Turrets/TurretType.h"

class TurretAdapter : public AbstractTurretGroup {
public:
	TurretAdapter(AbstractTurretType* _TTurret);
	~TurretAdapter();
	TB_Turret offense();
	TB_Turret defense();
	TB_Turret utility();
	TB_Turret support();
protected:
	AbstractTurretType* _Turret;
};