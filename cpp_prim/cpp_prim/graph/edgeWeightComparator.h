#pragma once

#include "edge.h"

class EdgeWeightComparator
{
public:
	/**
	 * @brief Porównanie krawędzie według ich wag i indeksów wierzchołków
	 * 
	 * @param lhs Pierwsza krawędź do porównania
	 * @param rhs Druga krawędź do porównania
	 * @return true Krawędzie mają takie samie wagi i indeksy wierzchołków
	 * @return false Krawędzie nie są sobie równe
	 */
	bool operator()(Edge& lhs, Edge& rhs);
};

