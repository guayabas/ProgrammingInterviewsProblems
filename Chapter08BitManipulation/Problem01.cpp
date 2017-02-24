#include <unordered_map>
#include "Problem01.h"
#include "Utilities.h"
#include <cstdio>

/// Problem 01.
/// Given an array of integers, every elements appears twice except for one. Find that single one
int Problem01::singleNumber(int ** buffer, int size)
{
	int number = 0;
	for (int i = 0; i < size; ++i) number ^= (*buffer)[i];
	return number;
}

int Problem01::singleNumberHashMap(int ** buffer, int size)
{
	int number = 0;

	std::unordered_map<int, int> histogram;
	for (int i = 0; i < size; ++i)
	{
		int currentValue = (*buffer)[i];
		if (histogram.find(currentValue) == histogram.end()) histogram[currentValue]++;
		else histogram.erase(currentValue);
	}

	for (const auto & pairKeyValue : histogram) number = pairKeyValue.first;
	return number;
}

void Problem01::unitTest()
{
	int * arrayToFindSingleNumber = nullptr;
	int numberElements;
	
	numberElements = 5;
	arrayToFindSingleNumber = new int[numberElements]{ 1, 1, 2, 3, 3 };
	printArray(&arrayToFindSingleNumber, numberElements);
	printf("%d\n", singleNumber(&arrayToFindSingleNumber, numberElements));
	delete[] arrayToFindSingleNumber;

	numberElements = 5;
	arrayToFindSingleNumber = new int[numberElements] { 1, 3, 1, 4, 3 };
	printArray(&arrayToFindSingleNumber, numberElements);
	printf("%d\n", singleNumberHashMap(&arrayToFindSingleNumber, numberElements));
	delete[] arrayToFindSingleNumber;

	numberElements = 11;
	arrayToFindSingleNumber = new int[numberElements] { 1, 2, 6, 8, 7, 2, 1, 8, 6, 9, 9 };
	printArray(&arrayToFindSingleNumber, numberElements);
	printf("%d\n", singleNumberHashMap(&arrayToFindSingleNumber, numberElements));
	delete[] arrayToFindSingleNumber;
}