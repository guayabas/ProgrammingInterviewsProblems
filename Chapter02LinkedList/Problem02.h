#pragma once
#include "ProblemInterface.h"

template<typename T>
class LinkedList;

class Problem02
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	template<typename T>
	bool linkedListHasCycle(LinkedList<T> *);
};