#include "Problem03.h"
#include "Utilities.h"
#include <ctime>

/// Problem 03.
/// Design a tic-tac toe game that is played between two players on an n x n grid
bool Problem03::gameTicTacToe(int n)
{
	srand((unsigned)time(NULL));

	int ** grid = new int *[n];
	for (int i = 0; i < n; ++i) grid[i] = new int[n] { 0 };

	/// Make a move
	int currentPlayer = 1;
	do
	{
		int rowToPlay = RandomNumbers::generate(0, n);
		int colToPlay = RandomNumbers::generate(0, n);
		if (grid[rowToPlay][colToPlay] == 0)
		{
			grid[rowToPlay][colToPlay] = currentPlayer;

			if (currentPlayer == 1) { currentPlayer = 2; continue; }
			if (currentPlayer == 2) { currentPlayer = 1; continue; }
		}

	} while (!allMovesDone(grid, n));
	printMatrix(grid, n, n);

	/// Check rows for winner
	for (int i = 0; i < n; ++i)
	{
		unsigned int numberOnes = 0;
		unsigned int numberTwos = 0;

		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == 1) numberOnes++;
			if (grid[i][j] == 2) numberTwos++;
		}

		if (numberOnes == n || numberTwos == n) return true;
	}

	/// Check cols for winner
	for (int j = 0; j < n; ++j)
	{
		unsigned int numberOnes = 0;
		unsigned int numberTwos = 0;

		for (int i = 0; i < n; ++i)
		{
			if (grid[i][j] == 1) numberOnes++;
			if (grid[i][j] == 2) numberTwos++;
		}

		if (numberOnes == n || numberTwos == n) return true;
	}

	/// Check diagonal for winner
	{
		unsigned int numberOnes = 0;
		unsigned int numberTwos = 0;

		for (int i = 0; i < n; ++i)
		{
			if (grid[i][i] == 1) numberOnes++;
			if (grid[i][i] == 2) numberTwos++;
		}

		if (numberOnes == n || numberTwos == n) return true;
	}

	/// Check anti-diagonal for winner
	{
		unsigned int numberOnes = 0;
		unsigned int numberTwos = 0;

		for (int i = 0; i < n; ++i)
		{
			if (grid[n - 1 - i][i] == 1) numberOnes++;
			if (grid[n - 1 - i][i] == 2) numberTwos++;
		}

		if (numberOnes == n || numberTwos == n) return true;
	}

	return false;
}

bool Problem03::allMovesDone(int ** grid, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (grid[i][j] == 0) return false;
		}
	}
	return true;
}

void Problem03::unitTest()
{
	int gameSize = 5;
	printf("There is a winner : %s\n", boolToString(gameTicTacToe(gameSize)).c_str());
}