#pragma once
#include "ProblemInterface.h"
#include <queue>

class Problem01
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	std::queue<int> reverseInteger(int &);
};