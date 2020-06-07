#pragma once
#include <vector>

/**
 * @brief Uruchomienie algorytmu Prima
 * 
 * @param adjacencyMatrix Kwadratowa macierz sąsiedztwa grafu z wagami 
 * @return std::vector<std::vector<int>> Kwadratowa macierz sąsiedztwa wynikowego drzewa MST
 */
std::vector<std::vector<int>> run_algorithm(std::vector<std::vector<int>> graph);
