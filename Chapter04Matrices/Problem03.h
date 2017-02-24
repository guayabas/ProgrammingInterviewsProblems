#pragma once
#include "ProblemInterface.h"

class Problem03
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	bool allMovesDone(int **, int);
	bool gameTicTacToe(int);
};