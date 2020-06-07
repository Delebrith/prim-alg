#pragma once
#include "edge.h"

class EdgeHash
{
public:
	/**
	 * @brief Compute hash function over the Edge class based its weight and verticies index
	 * 
	 * @param edge Input edge
	 * @return std::size_t Hash function result
	 */
	std::size_t operator()(const Edge& edge) const;
};

