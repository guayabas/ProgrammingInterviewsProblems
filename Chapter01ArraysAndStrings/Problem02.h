#pragma once
#include "ProblemInterface.h"

class Problem02
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	void rotateArray(int **, unsigned int, unsigned int);
};