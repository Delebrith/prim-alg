#pragma once
#include <unordered_set>

class Edge {
public:
	int vertex1;
	int vertex2;
	int weight;

	/**
	 * @brief Construct a new Edge object Krawędź grafu
	 * 
	 * @param vertex1 Indeks pierwszego wierzchołka
	 * @param vertex2 Indeks drugiego wierzchołka
	 * @param weight Waga krawędzi
	 */
	Edge(int vertex1, int vertex2, int weight);

	/**
	 * @brief Porównanie krawędzi według ich wag i indeksów wierzchołków
	 * 
	 * @param rhs  Krawędź do porównania
	 * @return true Krawędzi mają te same wagi i indeksy wierzchołków
	 * @return false Krawędzi nie są sobie równe
	 */
	bool operator==(const Edge& rhs) const;

	/**
	 * @brief Sprawdza, czy dokładnie jeden wierzchołek krawędzi jest w przekazanym zbiorze wierzchołków
	 * 
	 * @param vertices Zbiór indeksów wierzchołków
	 * @return true Jeden z wierzchołków krawędzi znalazł się w przekazanym zbiorze
	 * @return false Zbiór nie zawiera wierzchołków krawędzi albo zawiera oba
	 */
	bool hasExactlyOneVertexIn(const std::unordered_set<int>& vertices);
};