#pragma once
#include "ProblemInterface.h"
#include <string>

class Problem04
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	bool stringsIsomorphic(const std::string &, const std::string &, int **);
};