#pragma once
#include "ProblemInterface.h"

class Problem05
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	bool isNumberPalindrome(int);
};
