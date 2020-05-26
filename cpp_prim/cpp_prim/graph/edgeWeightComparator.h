#pragma once

#include "edge.h"

class EdgeWeightComparator
{
public:
	bool operator()(Edge& lhs, Edge& rhs);
};

