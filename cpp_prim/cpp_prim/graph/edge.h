#pragma once
#include <unordered_set>

class Edge {
public:
	int vertex1;
	int vertex2;
	int weight;
	
	/**
	 * @brief Construct a new Edge object
	 * 
	 * @param vertex1 Index of the first vertex
	 * @param vertex2 Index of the second vertex
	 * @param weight Edge weight
	 */
	Edge(int vertex1, int vertex2, int weight);

	/**
	 * @brief Compare edges based on their weight and vertex indices
	 * 
	 * @param rhs Edge to compare
	 * @return true Edges are equal
	 * @return false Edge aren't equal
	 */
	
	bool operator==(const Edge& rhs) const;


	/**
	 * @brief Check if given hash set of verticies contains one of the verticies of the object
	 * 
	 * @param vertices Set of verticies
	 * @return true Set has one of the edge verticies
	 * @return false Set doesn't contain verticies or it has them both
	 */
	bool hasExactlyOneVertexIn(const std::unordered_set<int>& vertices);
};