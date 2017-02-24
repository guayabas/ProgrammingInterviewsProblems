#pragma once
#include <vector>

template<typename T>
class GraphNode;

template<typename T>
class Graph
{
public:
	~Graph();

	void insertNode(int, GraphNode<T> * = nullptr, unsigned int = 0);
	std::vector<GraphNode<T>*> nodes;
};