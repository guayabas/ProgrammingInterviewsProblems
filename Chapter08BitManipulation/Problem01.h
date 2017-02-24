#pragma once
#include "ProblemInterface.h"

class Problem01
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	int singleNumberHashMap(int **, int);
	int singleNumber(int **, int);
};