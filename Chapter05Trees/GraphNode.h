#pragma once

template<typename T>
class GraphNode
{
public:
	GraphNode(); ~GraphNode();

	unsigned int numberNeighbors;
	GraphNode * neighbors;
	bool visited;
	T value;
};