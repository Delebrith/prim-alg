#include "edge.h"

Edge::Edge(int vertex1, int vertex2, int weight)
{
	this->vertex1 = vertex1;
	this->vertex2 = vertex2;
	this->weight = weight;
}

bool Edge::operator==(const Edge& rhs) const
{
	return this->weight == rhs.weight && 
		((this->vertex1 == rhs.vertex1 && this->vertex2 == rhs.vertex2)
			|| (this->vertex1 == rhs.vertex2 && this->vertex2 == rhs.vertex1));
}

bool Edge::hasExactlyOneVertexIn(std::unordered_set<int> vertices)
{
	return (vertices.find(this->vertex1) != vertices.end() && vertices.find(this->vertex2) == vertices.end()) 
		|| (vertices.find(this->vertex1) == vertices.end() && vertices.find(this->vertex2) != vertices.end());
}
