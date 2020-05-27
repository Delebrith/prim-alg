#include "prim.h"
#include "graph/edge.h"
#include "graph/graph.h"
#include "graph/edgeWeightComparator.h"

#include <iostream>
#include <unordered_set>
#include <queue>

std::vector<std::vector<int>> run_algorithm(std::vector<std::vector<int>> adjacencyMatrix) 
{
	//std::cout << "running prim's algorithm cpp implementation..." << std::endl;
	// std::cout << "input was..." << std::endl;
	//for (int i = 0; i < adjacencyMatrix.size(); i++) {
	//	for (int j = 0; j < adjacencyMatrix[i].size(); j++)
	//		std::cout << adjacencyMatrix[i][j] << " ";
	//	std::cout << std::endl;
	//}
	
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
		
		if (topEdge.hasExactlyOneVertexIn(verticesOfMst)) {
			mst.push_back(std::vector<int>({ topEdge.vertex1, topEdge.vertex2 }));

			int vertex = (verticesOfMst.find(topEdge.vertex1) == verticesOfMst.end()) ? topEdge.vertex1 : topEdge.vertex2;
			verticesOfMst.insert(vertex);


			std::unordered_set<Edge, EdgeHash> adjacentEdges = graph.getAdjacentEdgesOf(vertex);
			for (Edge e : adjacentEdges)
			{
				if (e.hasExactlyOneVertexIn(verticesOfMst))
				{
					edgeQueue.push(e);
				}
			}
		}
	}


	//std::cout << "finished prim's algorithm cpp implementation." << std::endl;
	// std::cout << "returning..." << std::endl;
	//for (int i = 0; i < mst.size(); i++) {
	//	for (int j = 0; j < mst[i].size(); j++)
	//		std::cout << mst[i][j] << " ";
	//	std::cout << std::endl;
	//}

	return mst;
}