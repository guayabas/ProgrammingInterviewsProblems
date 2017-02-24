#include "Problem01.h"
#include "Utilities.h"

/// Problem 01.
/// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order
std::queue<int> Problem01::spiralOrderMatrix(int ** matrix, int numberRows, int numberColumns)
{
	std::queue<int> spiralOrder;
	if (!matrix) return spiralOrder;

	int n = numberColumns;
	int m = numberRows;

	int matrixElementi = 0;
	int matrixElementj = 0;
	while (n > 0 && m > 0)
	{

		/// process single row / column
		if (m == 1) for (int i = 0; i < n; ++i) spiralOrder.push(matrix[matrixElementi][matrixElementj++]);
		else if (n == 1) for (int i = 0; i < m; ++i) spiralOrder.push(matrix[matrixElementi++][matrixElementj]);

		/// move right
		for (int i = 0; i < (n - 1); ++i) spiralOrder.push(matrix[matrixElementi][matrixElementj++]);

		/// move down
		for (int i = 0; i < (m - 1); ++i) spiralOrder.push(matrix[matrixElementi++][matrixElementj]);

		/// move left
		for (int i = 0; i < (n - 1); ++i) spiralOrder.push(matrix[matrixElementi][matrixElementj--]);

		/// move up
		for (int i = 0; i < (m - 1); ++i) spiralOrder.push(matrix[matrixElementi--][matrixElementj]);

		/// move to next circle
		matrixElementi++;
		matrixElementj++;
		m -= 2;
		n -= 2;
	}

	return spiralOrder;
}

void Problem01::unitTest()
{
	int numberRows = 3;
	int numberCols = 3;
	int ** matrixToObtainSpiralOrder = new int *[numberRows]
	{
		new int[numberCols] {1, 2, 3},
			new int[numberCols] {4, 5, 6},
			new int[numberCols] {7, 8, 9}
	};
	printMatrix(matrixToObtainSpiralOrder, numberRows, numberCols);
	auto spiralOrder = spiralOrderMatrix(matrixToObtainSpiralOrder, numberRows, numberCols);
	while (!spiralOrder.empty())
	{
		printf("%d ", spiralOrder.front());
		spiralOrder.pop();
	}
	printf("\n");

	for (int i = (numberRows - 1); i >= 0; i--) delete[] matrixToObtainSpiralOrder[i];
	delete[] matrixToObtainSpiralOrder;
}