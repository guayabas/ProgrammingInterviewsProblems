#pragma once
#include "ProblemInterface.h"
#include "Triple.h"

class Problem02
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	void maximizeMoneyLessFruit(int, const int, const int, const int);
};