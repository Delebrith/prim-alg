#pragma once

#include "edge.h"

// This class is used to sort edges inside priority queue
class EdgeWeightComparator
{
public:
	bool operator()(Edge& lhs, Edge& rhs);
};

