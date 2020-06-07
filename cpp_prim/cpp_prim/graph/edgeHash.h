#pragma once
#include "edge.h"

// this class enables using Edge objects in sets
class EdgeHash
{
public:
	std::size_t operator()(const Edge& edge) const;
};

