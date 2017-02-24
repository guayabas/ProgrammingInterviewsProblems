#include "Problem01.h"
#include "Utilities.h"
#include <iostream>
#include <cstdlib>
#include <vector>

/// Problem 01.
/// Find the contiguous subarray within an array (containing at least one number) which has
/// the largest sum
int Problem01::maximumSubarrayDynamic(int ** buffer, unsigned int size)
{
	int maxsum = (*buffer)[0];
	int * sums = new int[size - 1]{ 0 };
	sums[0] = maxsum;

	for (unsigned int i = 1; i < size; ++i)
	{
		sums[i] = (int)std::fmax((*buffer)[i], sums[i - 1] + (*buffer)[i]);
		maxsum = (int)std::fmax(maxsum, sums[i]);
	}

	//delete[] sums;

	return maxsum;
}

Triple Problem01::maximumSubarray(int ** buffer, unsigned int size)
{
	std::vector<Triple> sums;

	for (unsigned int i = 0; i < size; ++i)
	{
		unsigned int rightIndex = i;
		unsigned int leftIndex = i;

		int currentSum = (*buffer)[i];

		while (leftIndex != 0 || rightIndex != (size - 1))
		{
			rightIndex += (rightIndex == (size - 1)) ? 0 : 1;
			leftIndex -= (leftIndex == 0) ? 0 : 1;

			int nextSum = 0;
			for (unsigned int j = leftIndex; j < rightIndex; ++j)
			{
				nextSum += (*buffer)[j];
			}

			if (nextSum < currentSum) break;

			currentSum = nextSum;
		}

		Triple currentSumInformation(rightIndex, leftIndex, currentSum);
		sums.push_back(currentSumInformation);
	}

	Triple result(sums[0].right, sums[0].left, sums[0].sum);
	for (size_t i = 1; i < sums.size(); ++i)
	{
		if (sums[i].sum > result.sum)
		{
			result = sums[i];
		}
	}

	return result;
}

void Problem01::unitTest()
{
	unsigned int arraySize = 9;
	int * arrayToFindMaxSubarray = new int[arraySize]{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	//Triple subArrayInfo = maximumSubarray(&arrayToFindMaxSubarray, arraySize);
	//std::cout << "Subarray: ";
	//printArray(&arrayToFindMaxSubarray, subArrayInfo.left, subArrayInfo.right);

	std::cout << "Sum: " << maximumSubarrayDynamic(&arrayToFindMaxSubarray, arraySize) << std::endl;

	delete[] arrayToFindMaxSubarray;
}