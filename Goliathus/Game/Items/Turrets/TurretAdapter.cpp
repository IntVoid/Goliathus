#include "TurretAdapter.h"
#include <stdlib.h>;

TurretAdapter::TurretAdapter(AbstractTurretType* _TTurret) {
	_Turret = _TTurret;
}

TurretAdapter::~TurretAdapter() {
	delete _Turret;
	_Turret = NULL;
}

TB_Turret TurretAdapter::offense() { return 1; }
TB_Turret TurretAdapter::defense() { return 2; }
TB_Turret TurretAdapter::utility() { return 3; }
TB_Turret TurretAdapter::support() { return 4; }