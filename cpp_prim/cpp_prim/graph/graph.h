#pragma once

#include <vector>
#include <unordered_set>
#include "edge.h"
#include "edgeHash.h"

class Graph {
	std::vector<std::vector<int>> adjacencyMatrix;

public:
	std::unordered_set<int> vertices;

	/**
	 * @brief Construct a new Graph object
	 * 
	 * @param adjacencyMatrix Adjancecny matrix
	 */
	Graph(const std::vector<std::vector<int>>& adjacencyMatrix);

	/**
	 * @brief Get the Adjacent Edges Of object
	 * 
	 * @param vertex Vertex index
	 * @return std::unordered_set<Edge, EdgeHash> Resulting set of adjacent edges
	 */
	std::unordered_set<Edge, EdgeHash> getAdjacentEdgesOf(int vertex);
};