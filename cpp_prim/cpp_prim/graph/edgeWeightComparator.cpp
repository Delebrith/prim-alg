#include "edgeWeightComparator.h"

bool EdgeWeightComparator::operator()(Edge& lhs, Edge& rhs)
{
	return lhs.weight > rhs.weight;
}
