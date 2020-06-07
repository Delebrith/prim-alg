#pragma once
#include <vector>

/**
 * @brief Run Prim's algorithm
 * 
 * @param adjacencyMatrix Adjacency matrix with edge weights
 * @return std::vector<std::vector<int>> Adjacency matrix of resulting MST
 */
std::vector<std::vector<int>> run_algorithm(std::vector<std::vector<int>> graph);
