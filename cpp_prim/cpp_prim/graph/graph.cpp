#include "graph.h"

Graph::Graph(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	this->adjacencyMatrix = adjacencyMatrix;
	this->vertices = std::unordered_set<int>();
	this->vertices.reserve(adjacencyMatrix.size());
	for (int i = 0; i < adjacencyMatrix.size(); i++)
		this->vertices.insert(i);
}

std::unordered_set<Edge, EdgeHash> Graph::getAdjacentEdgesOf(int vertex)
{
	std::unordered_set<Edge, EdgeHash> adjacentEdges = std::unordered_set<Edge, EdgeHash>();
	for (int i = 0; i < vertex; i++) {
		int weight = adjacencyMatrix[i][vertex];
		if (weight != 0)
			adjacentEdges.insert(Edge(vertex, i, weight));
	}
	for (int i = vertex; i < adjacencyMatrix[vertex].size(); i++) {
		int weight = adjacencyMatrix[vertex][i];
		if (weight != 0)
			adjacentEdges.insert(Edge(vertex, i, weight));
	}
	return adjacentEdges;
}
