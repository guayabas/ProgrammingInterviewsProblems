#pragma once
#include "ProblemInterface.h"

template<typename T>
class LinkedList;

class Problem01
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	template<typename T>
	void addNumbers(LinkedList<T> *, LinkedList<T> *, LinkedList<T> *);
};