#pragma once
#include <unordered_set>

class Edge {
public:
	int vertex1;
	int vertex2;
	int weight;

	Edge(int vertex1, int vertex2, int weight);
	bool operator==(const Edge& rhs) const;

	bool hasExactlyOneVertexIn(const std::unordered_set<int>& vertices);
};