#include "Utilities.h"
#include <cstdio>

void printMatrix(int ** matrix, int numberRows, int numberColumns)
{
	for (int i = 0; i < numberRows; ++i)
	{
		for (int j = 0; j < numberColumns; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

std::string boolToString(bool value)
{
	return (value) ? "true" : "false";
}