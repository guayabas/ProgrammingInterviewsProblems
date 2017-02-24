#pragma once

template<typename T>
class Node
{
public:
	Node(); ~Node();

	Node * next;
	T value;
};