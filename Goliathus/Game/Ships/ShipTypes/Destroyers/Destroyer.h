#pragma once

#include "../../ShipBuilder.h"

class DestroyerBuilder : public ShipBuilder {
public:
	virtual ~DestroyerBuilder();
	virtual void buildHull();
	virtual void buildDesignation();
};