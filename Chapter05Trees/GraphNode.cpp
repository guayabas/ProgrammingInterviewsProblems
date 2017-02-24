#include "GraphNode.h"

template<typename T>
GraphNode<T>::GraphNode()
	: numberNeighbors(0)
	, neighbors(nullptr)
	, visited(false)
	, value(T(0))
{

}

template<typename T>
GraphNode<T>::~GraphNode()
{
	//if (!neighbors) delete[] neighbors;
}

template class GraphNode<int>;