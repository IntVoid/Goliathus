#pragma once

#include "../../ShipBuilder.h"

namespace ShipBuilderType {
	class FrigateBuilder : public ShipBuilder {
	public:
		virtual ~FrigateBuilder();
		virtual void buildHull();
		virtual void buildDesignation();
	};
}