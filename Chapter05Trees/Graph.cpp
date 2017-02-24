#include "GraphNode.h"
#include "Graph.h"

template<typename T>
Graph<T>::~Graph()
{
	//for (size_t n = nodes.size(); n >= 0; --n) delete nodes[n];
}

template<typename T>
void Graph<T>::insertNode(int value, GraphNode<T> * neighbors, unsigned int numberNeighbors)
{
	GraphNode<T> * newNode = new GraphNode<T>;
	newNode->numberNeighbors = numberNeighbors;
	newNode->neighbors = neighbors;
	newNode->value = value;

	nodes.push_back(newNode);
}

template class Graph<int>;