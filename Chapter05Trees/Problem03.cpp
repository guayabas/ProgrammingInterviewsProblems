#include "Problem03.h"
#include "GraphNode.h"
#include "Utilities.h"
#include "Graph.h"
#include <queue>

/// Problem01.
/// Implement BFS without using external libraries
template<typename T>
void Problem03::breathFirstSearch(Graph<T> * graph)
{
	std::queue<GraphNode<T> *> listNodes;
	for (const auto & node : graph->nodes) listNodes.push(node);

	while (!listNodes.empty())
	{
		GraphNode<T> * node = listNodes.front();

		if (!node->visited)
		{
			node->visited = true;
			std::cout << node->value << " ";
		}

		for (unsigned int i = 0; i < node->numberNeighbors; ++i)
		{
			if (!node->neighbors[i].visited)
			{
				node->neighbors[i].visited = true;
				std::cout << node->neighbors[i].value << " ";
			}
		}

		listNodes.pop();
	}

	std::cout << std::endl;
}

void Problem03::unitTest()
{
	unsigned int numberNeighbors = 0;

	Graph<int> graphToTraverse;

	GraphNode<int> neighbors1[3];
	neighbors1[0].value = 3;
	neighbors1[1].value = 4;
	neighbors1[2].value = 2;
	graphToTraverse.insertNode(1, neighbors1, 3);

	GraphNode<int> neighbors2[3];
	neighbors2[0].value = 1;
	neighbors2[1].value = 4;
	neighbors2[2].value = 3;
	graphToTraverse.insertNode(2, neighbors2, 3);

	GraphNode<int> neighbors3[2];
	neighbors3[0].value = 1;
	neighbors3[1].value = 2;
	graphToTraverse.insertNode(3, neighbors3, 2);

	GraphNode<int> neighbors4[2];
	neighbors4[0].value = 1;
	neighbors4[1].value = 2;
	graphToTraverse.insertNode(4, neighbors4, 2);

	printGraph(&graphToTraverse);

	breathFirstSearch(&graphToTraverse);
}