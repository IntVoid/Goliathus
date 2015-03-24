#pragma once

#include "../../ShipBuilder.h"

class DreadnaughtBuilder : public ShipBuilder {
public:
	virtual ~DreadnaughtBuilder();
	virtual void buildHull();
	virtual void buildDesignation();
};