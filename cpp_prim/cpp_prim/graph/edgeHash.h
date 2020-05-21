#pragma once
#include "edge.h"

class EdgeHash
{
public:
	std::size_t operator()(const Edge& edge) const;
};

