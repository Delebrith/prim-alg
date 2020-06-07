#pragma once
#include "edge.h"

class EdgeHash
{
public:
	/**
	 * @brief Obliczenie funkcji mieszającej klasy Edge na podstawie jej parametrów
	 * 
	 * @param edge Krawedż do obliczenie funkcji mieszającej
	 * @return std::size_t  Wynik funkcji mieszającej
	 */
	std::size_t operator()(const Edge& edge) const;
};

