#include "BinarySearch.h"
#include "Problem02.h"
#include "Utilities.h"

/// Problem 02.
/// Write an efficient algorithm that searches for a value in an m x n matrix. The matrix has the following properties
/// 1. Integers in each row are sorted from left to right
/// 2. The first integer of each row is greater than the last integer of the previous row
bool Problem02::searchInMatrix(int ** matrix, int numberRows, int numberColumns, int valueToSearch)
{
	for (int i = 0; i < numberRows; ++i) if (binarySearch(valueToSearch, matrix[i], 0, numberColumns)) return true;
	return false;
}

void Problem02::unitTest()
{
	int numberRows = 3;
	int numberCols = 4;
	int ** matrixToSearch = new int *[numberRows]
	{
		new int[numberCols] {0x01, 0x03, 0x05, 0x07},
		new int[numberCols] {0x0A, 0x0B, 0x10, 0x14},
		new int[numberCols] {0x17, 0x1E, 0x22, 0x32}
	};
	printMatrix(matrixToSearch, numberRows, numberCols);
	printf("Searching value %d %s\n", 0x03, boolToString(searchInMatrix(matrixToSearch, numberRows, numberCols, 0x03)).c_str());
	printf("Searching value %d %s\n", 0x0F, boolToString(searchInMatrix(matrixToSearch, numberRows, numberCols, 0x0F)).c_str());
	printf("Searching value %d %s\n", 0x32, boolToString(searchInMatrix(matrixToSearch, numberRows, numberCols, 0x32)).c_str());

	for (int i = (numberRows - 1); i >= 0; i--) delete[] matrixToSearch[i];
	delete[] matrixToSearch;
}