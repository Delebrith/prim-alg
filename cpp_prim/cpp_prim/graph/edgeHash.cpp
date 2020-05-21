#include "edgeHash.h"

// based on https://stackoverflow.com/a/17017281/11913932
std::size_t EdgeHash::operator()(const Edge& edge) const
{
	return std::hash<int>()(edge.vertex1) ^ std::hash<int>()(edge.vertex2) ^ std::hash<int>()(edge.weight);
}
