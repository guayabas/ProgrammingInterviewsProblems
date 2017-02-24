#pragma once
#include "ProblemInterface.h"

class Problem02
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	bool searchInMatrix(int **, int, int, int);
};