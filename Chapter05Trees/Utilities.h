#pragma once
#include "GraphNode.h"
#include <iostream>
#include "Graph.h"

template<typename T>
void printGraph(Graph<T> * graph)
{
	for (GraphNode<T> * node : graph->nodes)
	{
		std::cout << node->value << ": ";

		for (unsigned int i = 0; i < node->numberNeighbors; ++i) 
		{
			std::cout << node->neighbors[i].value << " ";
		}

		std::cout << std::endl;
	}
}