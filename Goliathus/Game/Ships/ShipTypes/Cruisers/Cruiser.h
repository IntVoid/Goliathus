#pragma once

#include "../../ShipBuilder.h"

class CruiserBuilder : public ShipBuilder {
public:
	virtual ~CruiserBuilder();
	virtual void buildHull();
	virtual void buildDesignation();
};