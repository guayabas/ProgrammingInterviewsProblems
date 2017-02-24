#pragma once
#include "ProblemInterface.h"

class Problem02
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	void transformDecimalToBinary(unsigned int, unsigned int *, unsigned int);
	unsigned int transformBinaryToDecimal(unsigned int *, unsigned int);
	void reverseBits(unsigned int);
};