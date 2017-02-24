#pragma once
#include "ProblemInterface.h"

class Problem01
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	void countingSort(int **, int, int);
};