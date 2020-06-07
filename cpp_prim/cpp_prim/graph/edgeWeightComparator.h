#pragma once

#include "edge.h"

// This class is used to sort edges inside priority queue
class EdgeWeightComparator
{
public:
	/**
	 * @brief Compare Edges classes based on their weights and verticies index
	 * 
	 * @param lhs First edge
	 * @param rhs Second edge
	 * @return true Edges are same
	 * @return false Edges are different
	 */
	bool operator()(Edge& lhs, Edge& rhs);
};

