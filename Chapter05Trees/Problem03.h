#pragma once
#include "ProblemInterface.h"

template<typename T>
class Graph;

class Problem03
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	template<typename T>
	void breathFirstSearch(Graph<T> *);
};