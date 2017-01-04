#include "TurretAdapter.h"
#include <stdlib.h>

TurretAdapter::TurretAdapter(AbstractTurretType* _TTurret) {
	_Turret = _TTurret;
}

TurretAdapter::~TurretAdapter() {
	delete _Turret;
	_Turret = NULL;
}

TB_Turret TurretAdapter::offense() { return NULL; }
TB_Turret TurretAdapter::defense() { return NULL; }
TB_Turret TurretAdapter::utility() { return NULL; }
TB_Turret TurretAdapter::support() { return NULL; }