#pragma once
#include "ProblemInterface.h"
#include <string>

class Problem01
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	bool stringHasUniqueCharacters(const std::string &);
	std::string isUniqueConsolePrinting(bool);
};