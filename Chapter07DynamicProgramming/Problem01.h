#pragma once
#include "ProblemInterface.h"
#include "Triple.h"

class Problem01
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	int maximumSubarrayDynamic(int **, unsigned int);
	Triple maximumSubarray(int **, unsigned int);
};