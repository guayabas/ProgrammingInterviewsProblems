#include "Problem02.h"
#include "Utilities.h"

/// Problem 02.
/// Rotate an array of n elements to the right by k steps
void Problem02::rotateArray(int ** buffer, unsigned int size, unsigned int steps)
{
	if (!buffer) return;

	int * leftArray = new int[(size - steps)];
	for (unsigned int n = 0; n < (size - steps); ++n) leftArray[n] = (*buffer)[n];

	int * rightArray = new int[steps];
	for (unsigned int n = 0; n < steps; ++n) rightArray[n] = (*buffer)[(size - steps) + n];

	for (unsigned int n = 0; n < steps; ++n) (*buffer)[n] = rightArray[n];
	for (unsigned int n = 0; n < (size - steps); ++n) (*buffer)[n + steps] = leftArray[n];

	delete[] rightArray;
	delete[] leftArray;
}

void Problem02::unitTest()
{
	unsigned int numberElements = 7;
	unsigned int steps = 3;

	int * arrayToRotate = new int[numberElements] { 1, 2, 3, 4, 5, 6, 7 };
	printArray(&arrayToRotate, numberElements);
	rotateArray(&arrayToRotate, numberElements, steps);
	printArray(&arrayToRotate, numberElements);
	delete[] arrayToRotate;
}