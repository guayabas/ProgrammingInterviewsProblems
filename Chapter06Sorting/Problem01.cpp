#include "Problem01.h"
#include "Utilities.h"
#include <vector>
#include <ctime>

/// Problem 01.
/// Given an array with n objects colored red, white or blue, sort them so that the
/// objects of the same color are adjacent, with the colors in the order red, white and blue
void Problem01::countingSort(int ** buffer, int size, int colors)
{
	int * sortedArray = new int[size] { 0 };

	int * countingArray = new int[colors]{ 0 };
	for (int i = 0; i < size; ++i) countingArray[(*buffer)[i]]++;
	for (int i = 0; i < (colors - 1); ++i) countingArray[i + 1] += countingArray[i];

	for (int i = (size - 1); i >= 0; --i)
	{
		int currentValue = (*buffer)[i];
		int index = countingArray[currentValue] - 1;
		sortedArray[index] = currentValue;
		countingArray[currentValue]--;
	}

	for (int i = 0; i < size; ++i) (*buffer)[i] = sortedArray[i];

	delete[] countingArray;
	delete[] sortedArray;
}

void Problem01::unitTest()
{
	srand((unsigned)time(0));

	int numberElements;

	numberElements = 10;
	int * arrayToSort = new int[numberElements] { 0, 0, 1, 1, 0, 0, 2, 1, 2, 0};
	printArray(&arrayToSort, numberElements);
	countingSort(&arrayToSort, numberElements, 3);
	printArray(&arrayToSort, numberElements);
	delete[] arrayToSort;

	numberElements = 20;
	std::vector<int> containerToSort;
	containerToSort.reserve(numberElements);
	for (int n = 0; n < numberElements; ++n) containerToSort.push_back(RandomNumbers::generate(0, 3));
	int * containerAsArray = &containerToSort[0];
	printArray(&containerAsArray, numberElements);
	countingSort(&containerAsArray, numberElements, 3);
	printArray(&containerAsArray, numberElements);
}