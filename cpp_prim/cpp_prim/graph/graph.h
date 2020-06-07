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
	 * @brief Graf w postaci macierzy sąsiedztwa
	 * 
	 * @param adjacencyMatrix Kwadratowa macierz sąsiedztwa grafu z wagami
	 */
	Graph(const std::vector<std::vector<int>>& adjacencyMatrix);

	/**
	 * @brief Krawędzie incydentne przekazanego indeksu wierzchołka grafu
	 * 
	 * @param vertex Indeks wierzchołka
	 * @return std::unordered_set<Edge, EdgeHash>  Zbiór incydentnych krawędzi
	 */
	std::unordered_set<Edge, EdgeHash> getAdjacentEdgesOf(int vertex);
};