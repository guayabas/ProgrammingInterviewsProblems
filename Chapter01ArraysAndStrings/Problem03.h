#pragma once
#include "ProblemInterface.h"
#include <string>

class Problem03
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	void reverseString(std::string &);
};