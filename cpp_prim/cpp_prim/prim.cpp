#include "prim.h"
#include "graph/edge.h"
#include "graph/graph.h"
#include "graph/edgeWeightComparator.h"

#include <iostream>
#include <unordered_set>
#include <queue>

std::vector<std::vector<int>> run_algorithm(std::vector<std::vector<int>> adjacencyMatrix) 
{
	std::vector<std::vector<int>> mst = std::vector<std::vector<int>>();
	std::unordered_set<int> verticesOfMst = std::unordered_set<int>();
	std::priority_queue<Edge, std::deque<Edge>, EdgeWeightComparator> edgeQueue = std::priority_queue<Edge, std::deque<Edge>, EdgeWeightComparator>();
	Graph graph = Graph(adjacencyMatrix);

	int randomVertex = 0;

	
	verticesOfMst.insert(randomVertex);
	std::unordered_set<Edge, EdgeHash> edges = graph.getAdjacentEdgesOf(randomVertex);
	for (Edge e : edges)
	{
		edgeQueue.push(e);
	}

	
	while (verticesOfMst != graph.vertices) 
	{
		Edge topEdge = edgeQueue.top();
		edgeQueue.pop();
		
		// check if only one vertex of edge is in MST to avoid cycles. If cycle is found, continue
		if (topEdge.hasExactlyOneVertexIn(verticesOfMst)) {
			mst.push_back(std::vector<int>({ topEdge.vertex1, topEdge.vertex2 }));

			// choose next vertex to be added to set
			int vertex = (verticesOfMst.find(topEdge.vertex1) == verticesOfMst.end()) ? topEdge.vertex1 : topEdge.vertex2;
			verticesOfMst.insert(vertex);

			// add adjacent edges to queue
			std::unordered_set<Edge, EdgeHash> adjacentEdges = graph.getAdjacentEdgesOf(vertex);
			for (Edge e : adjacentEdges)
			{
				edgeQueue.push(e);
			}
		}
	}

	return mst;
}