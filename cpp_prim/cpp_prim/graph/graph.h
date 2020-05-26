#pragma once

#include <vector>
#include <unordered_set>
#include "edge.h"
#include "edgeHash.h"

class Graph {
	std::vector<std::vector<int>> adjacencyMatrix;

public:
	std::unordered_set<int> vertices;

	Graph(std::vector<std::vector<int>> adjacencyMatrix);
	std::unordered_set<Edge, EdgeHash> getAdjacentEdgesOf(int vertex);
};